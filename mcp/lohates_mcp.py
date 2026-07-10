#!/usr/bin/env python3
"""LoHaTes MCP-Server - KI-Schnittstelle fuer die Tesla-BLE-Bridge.

Erlaubt KI-Assistenten (Claude u. a.) den Tesla ueber den LoHaTes-ESP32
zu inspizieren und - falls freigeschaltet - zu steuern (Laden, Wecken usw.).

Transport: Streamable HTTP auf Port 8809 -> http://<pi-ip>:8809/mcp
Schreiben: config.json {"enable_write": true} - Entriegeln zusaetzlich
{"enable_unlock": true} (Standard: aus).
"""
import asyncio
import json
import time

from mcp.server.fastmcp import FastMCP

CONFIG_PATH = "/home/admin/lohates-mcp/config.json"


def _config():
    try:
        return json.load(open(CONFIG_PATH, encoding="utf-8"))
    except Exception:
        return {}


cfg = _config()
HOST = cfg.get("esp_host", "192.168.20.44")
PORT = int(cfg.get("esp_port", 6053))
PSK = cfg.get("api_encryption_key", "")

mcp = FastMCP("LoHaTes", host="0.0.0.0", port=int(cfg.get("port", 8809)))


async def _connect():
    from aioesphomeapi import APIClient
    cli = APIClient(HOST, PORT, None, noise_psk=PSK or None)
    await cli.connect(login=True)
    return cli


async def _snapshot(wait_s: float = 2.0):
    """Verbindet, sammelt Entitaeten + aktuelle Zustaende, trennt wieder."""
    cli = await _connect()
    try:
        ents, _ = await cli.list_entities_services()
        keymap = {}
        for e in ents:
            keymap[e.key] = {
                "object_id": getattr(e, "object_id", ""),
                "name": getattr(e, "name", ""),
                "type": type(e).__name__,
            }
        states = {}

        def cb(state):
            states[state.key] = state

        cli.subscribe_states(cb)
        await asyncio.sleep(wait_s)
        out = {}
        for key, meta in keymap.items():
            s = states.get(key)
            val = None
            if s is not None:
                for attr in ("state", "position", "current_temperature"):
                    if hasattr(s, attr):
                        val = getattr(s, attr)
                        break
                if hasattr(s, "missing_state") and s.missing_state:
                    val = None
            out[meta["object_id"]] = {
                "name": meta["name"],
                "type": meta["type"],
                "value": val,
            }
        return out, keymap, cli
    except Exception:
        await cli.disconnect()
        raise


async def _snapshot_and_close(wait_s: float = 2.0):
    out, _, cli = await _snapshot(wait_s)
    await cli.disconnect()
    return out


def _find(keymap, want_type, needle):
    for key, meta in keymap.items():
        if want_type in meta["type"].lower() and needle in meta["object_id"].lower():
            return key
    return None


async def _do(action: str, value: float = 0):
    from aioesphomeapi import LockCommand
    out, keymap, cli = await _snapshot(1.0)
    try:
        def sw(needle):
            for oid, meta in out.items():
                if needle in oid:
                    return meta["value"]
            return None
        if sw("ki_steuern") is False:
            return ("KI-Steuerung am Geraet deaktiviert "
                    "(Schalter 'KI Steuern erlaubt' auf http://lohates.lan/geraete).")
        needles = {"wake": "erlaubt_wake", "charge_on": "erlaubt_charge",
                   "charge_off": "erlaubt_charge", "amps": "erlaubt_amps",
                   "limit": "erlaubt_limit", "lock": "erlaubt_lock",
                   "unlock": "erlaubt_unlock", "port_open": "erlaubt_port"}
        n = needles.get(action)
        if n and sw(n) is False:
            return (f"Befehl '{action}' am Geraet nicht freigegeben "
                    "(Haken auf http://lohates.lan/loxone#sicherheit setzen).")
        if action == "wake":
            key = _find(keymap, "button", "wake")
            await cli.button_command(key)
        elif action in ("charge_on", "charge_off"):
            key = _find(keymap, "switch", "charging")
            await cli.switch_command(key, action == "charge_on")
        elif action == "amps":
            key = _find(keymap, "number", "amps")
            await cli.number_command(key, float(value))
        elif action == "limit":
            key = _find(keymap, "number", "limit")
            await cli.number_command(key, float(value))
        elif action in ("lock", "unlock"):
            key = _find(keymap, "lock", "doors")
            await cli.lock_command(key, LockCommand.LOCK if action == "lock" else LockCommand.UNLOCK)
        elif action == "port_open":
            key = _find(keymap, "lock", "charge_port")
            await cli.lock_command(key, LockCommand.UNLOCK)
        else:
            return f"Unbekannte Aktion: {action}"
        return "OK"
    finally:
        await cli.disconnect()


def _run(coro):
    return asyncio.new_event_loop().run_until_complete(coro)


KERN = ["battery", "charging", "charger", "asleep", "range", "ble_signal",
        "tesla_anwesend", "user_present", "outside", "doors", "charge_port",
        "energy_added", "time_to_full", "charging_amps", "charging_limit",
        "charger_power", "charger_current", "charger_voltage", "iec"]


@mcp.tool()
def get_status() -> str:
    """Kern-Status des Tesla: SOC, Laden, anwesend, schlaeft, Reichweite usw."""
    out = _run(_snapshot_and_close())
    res = {}
    for oid, meta in sorted(out.items()):
        if any(k in oid for k in KERN):
            res[oid] = {"name": meta["name"], "value": meta["value"]}
    return json.dumps(res, ensure_ascii=False, default=str)


@mcp.tool()
def get_all_entities() -> str:
    """Alle Entitaeten des LoHaTes-ESP mit aktuellen Werten (vollstaendig)."""
    out = _run(_snapshot_and_close())
    return json.dumps(out, ensure_ascii=False, default=str)


@mcp.tool()
def diagnose() -> str:
    """Schnelldiagnose: ESP erreichbar? Auto in Reichweite? BLE-Signal? Laedt?"""
    t0 = time.time()
    try:
        out = _run(_snapshot_and_close())
    except Exception as e:
        return json.dumps({"esp_erreichbar": False, "fehler": str(e)})
    def val(sub):
        for oid, meta in out.items():
            if sub in oid:
                return meta["value"]
        return None
    return json.dumps({
        "esp_erreichbar": True,
        "antwortzeit_s": round(time.time() - t0, 1),
        "tesla_anwesend": val("tesla_anwesend"),
        "ble_signal_dbm": val("ble_signal"),
        "schlaeft": val("asleep"),
        "angesteckt": val("charger") if val("charger") is not None else None,
        "laedt": val("charging_state") or val("charging"),
        "soc": val("battery"),
    }, ensure_ascii=False, default=str)


def _write_guard():
    if not _config().get("enable_write", False):
        return "Schreiben deaktiviert (config.json: enable_write=true setzen)."
    return None


@mcp.tool()
def wake_vehicle() -> str:
    """Tesla aufwecken."""
    return _write_guard() or _run(_do("wake"))


@mcp.tool()
def set_charging(on: bool) -> str:
    """Laden starten (true) oder stoppen (false)."""
    return _write_guard() or _run(_do("charge_on" if on else "charge_off"))


@mcp.tool()
def set_charging_amps(amps: int) -> str:
    """Ladestrom setzen (1-16 A)."""
    if not 1 <= amps <= 16:
        return "Bereich 1-16 A."
    return _write_guard() or _run(_do("amps", amps))


@mcp.tool()
def set_charging_limit(percent: int) -> str:
    """Ladelimit setzen (50-100 %)."""
    if not 50 <= percent <= 100:
        return "Bereich 50-100 %."
    return _write_guard() or _run(_do("limit", percent))


@mcp.tool()
def open_charge_port() -> str:
    """Ladeport entriegeln/oeffnen."""
    return _write_guard() or _run(_do("port_open"))


@mcp.tool()
def lock_vehicle() -> str:
    """Tesla verriegeln."""
    return _write_guard() or _run(_do("lock"))


@mcp.tool()
def unlock_vehicle() -> str:
    """Tesla ENTRIEGELN - nur wenn enable_unlock=true in config.json."""
    if not _config().get("enable_unlock", False):
        return "Entriegeln deaktiviert (config.json: enable_unlock=true setzen)."
    return _write_guard() or _run(_do("unlock"))


@mcp.tool()
def about() -> str:
    """Was ist LoHaTes? Architektur und Endpunkte."""
    return json.dumps({
        "projekt": "LoHaTes - Loxone + Home Assistant + Tesla Bridge",
        "esp": f"{HOST} (lohates.lan), ESP32-S3, Basis yoziru/esphome-tesla-ble",
        "web_ui": "http://lohates.lan/ und http://lohates.lan/loxone",
        "loxone": "UDP Port 7091, Prefix 'lohates:'",
        "mcp": "dieser Server, Port 8809, auf dem HoxPi-Pi",
    }, ensure_ascii=False)


if __name__ == "__main__":
    mcp.run(transport="streamable-http")
