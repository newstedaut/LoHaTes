<img src="logo.svg" alt="LoHaTes" width="300">

# LoHaTes — Tesla ↔ Loxone & Home Assistant Bridge

**🇬🇧 [English version](README.md)**

[![Buy Me a Coffee](https://img.shields.io/badge/☕-Buy%20me%20a%20coffee-ffdd00)](https://buymeacoffee.com/bernhardsu9) [![PayPal](https://img.shields.io/badge/PayPal-Spenden-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/donate/?hosted_button_id=HWBBHDSVD3MCC) [![License: AGPL v3](https://img.shields.io/badge/Lizenz-AGPL_v3-blue.svg)](LICENSE)

**Ein ESP32-S3 in der Garage spricht per Bluetooth mit deinem Tesla — und mit Loxone, Home Assistant und KI-Assistenten. Komplett lokal, keine Cloud, keine Tesla-API-Gebühren.**

LoHaTes (**Lo**xone + **H**ome **A**ssistant + **Tes**la, reimt sich auf Sokrates) baut auf dem
großartigen [yoziru/esphome-tesla-ble](https://github.com/yoziru/esphome-tesla-ble) auf und ergänzt
eine native **Loxone-UDP-Schnittstelle**, ein zweisprachiges (DE/EN) **Einrichtungs-Dashboard
direkt am ESP**, **Freigabe-Haken pro Befehl**, Anwesenheitserkennung für die
Garagentor-Automatik und einen **MCP-Server**, mit dem KI-Assistenten wie Claude das Auto
inspizieren und (falls erlaubt) steuern können.

> **Hinweis:** Unabhängiges Open-Source-Projekt, **nicht verbunden mit Tesla, Inc., Loxone
> Electronics GmbH oder Home Assistant / der Open Home Foundation**. Genannte Marken gehören
> ihren Eigentümern. Du steuerst dein eigenes Auto auf eigenes Risiko.

## Funktionen

- **Tesla per BLE** — Wecken, Laden start/stopp, Ampere (PV-Überschussladen!), Ladelimit,
  Ver-/Entriegeln, Ladeport, dazu Sensoren: SOC, Reichweite, Leistung, Klima, Reifendruck,
  Türen … Das Auto schläft ganz normal weiter (VCSEC-Polling weckt nicht)
- **Loxone nativ** — UDP-Status-Push alle 10 s + sofortige Anwesenheits-Events
  (`present=1/0` wenn das Auto kommt/fährt → Garagentor-Logik), Befehle zurück über
  Virtuellen Ausgang. Keine Plugins, kein Gateway, läuft auch ohne HA
- **Home Assistant** — normales ESPHome-Gerät, alle Entitäten automatisch erkannt inkl.
  Klima-Thermostat; läuft aber auch komplett ohne HA (`reboot_timeout: 0s`)
- **Einrichtungs-Dashboard am ESP** — `http://<esp>/loxone` (DE) / `http://<esp>/en` (EN):
  Live-Kacheln, Schritt-für-Schritt-Tabellen für Loxone, HA-Anleitung, Pairing-Anleitung
  für den BLE-Schlüssel, eingebettete Geräte-UI, Logo unter `/logo.svg` für Dashboards
- **Sicherheit** — Web-Login (Basic Auth), **Freigabe-Haken pro Befehl** im HoxPi-Stil
  (wake/charge/amps/limit/lock/unlock/port), gelten für Loxone-UDP *und* KI gleichermaßen;
  `unlock` ist ab Werk gesperrt
- **KI-Schnittstelle (MCP)** — kleiner [Model-Context-Protocol](https://modelcontextprotocol.io)-Server
  (läuft auf jedem Raspberry Pi / Always-on-Rechner, Port 8809): `get_status`, `diagnose`,
  `wake_vehicle`, `set_charging_amps` … Schreiben doppelt abgesichert über Config *und*
  die Haken am Gerät
- **Anwesenheits-Zonen (optional, mmWave-Radar)** — mit einem HLK-LD2450 bekommst du
  **3 frei aufziehbare Zonen**. Wer 3 s in einer Zone steht, wird an Loxone gemeldet
  (`zone1/zone2/zone3`) — z. B. Zone 1 öffnet das Garagentor, Zone 2 schaltet das Licht ein.
  Gezeichnet werden die Zonen mit Maus oder Finger auf einer Live-Karte unter `http://<esp>/radar`
- **Passwort, das man zurücksetzen kann** — Web-Login direkt am Gerät unter
  `http://<esp>/passwort` ändern; Notausgang über BOOT-Taster oder Neuflashen (siehe unten)

## Hardware

| Teil | Hinweis |
|---|---|
| ESP32-S3 (16 MB Flash, 8 MB PSRAM) | z. B. N16R8-Dev-Board; BLE + WLAN gleichzeitig |
| USB-Netzteil | Standort < 5 m zum Auto (Garage/Carport) |
| optional: Raspberry Pi | für den MCP-(KI-)Server — jeder Always-on-Linux-Rechner geht |
| optional: HLK-LD2450 | 24-GHz-mmWave-Radar für Anwesenheits-Zonen (siehe unten) |

## Installation (Firmware)

```bash
pip install esphome
cd firmware
cp secrets.yaml.example secrets.yaml   # WLAN, VIN, BLE-MAC, Loxone-IP, Schlüssel eintragen
esphome run tesla-ble-esp32-s3.yml     # erster Flash per USB, danach OTA
```

> **Windows-Hinweis:** ESP-IDF kann nicht in Pfaden mit Leerzeichen bauen — Projekt z. B.
> nach `C:\LoHaTesBuild` legen.

BLE-MAC des Autos finden und Schlüssel pairen: einfach `http://<esp-ip>/loxone` öffnen —
das Dashboard führt durch alles (DE/EN).

## Loxone / Home Assistant / KI

Die kompletten Schritt-für-Schritt-Anleitungen liefert **das Gerät selbst** unter
`http://<esp-ip>/loxone` (deutsch) und `http://<esp-ip>/en` (englisch) — Tabellen für
Virtuelle Ein-/Ausgänge (UDP-Port 7101), ESPHome-Integration für HA,
Garagentor-Anwesenheitslogik, PV-Überschuss-Formel und das Claude-Desktop-MCP-Snippet.
Eine Kopie liegt in [`docs/`](docs/).

### MCP-Server (optional, für KI-Assistenten)

```bash
# auf deinem Pi / Server:
mcp/lohates_mcp_setup.sh    # erstellt venv + systemd-Dienst auf Port 8809
```

Claude Desktop → `claude_desktop_config.json`:

```json
{ "mcpServers": { "lohates": {
    "command": "npx", "args": ["-y", "mcp-remote", "http://<pi-ip>:8809/mcp"] } } }
```

## Optional: Anwesenheits-Zonen (mmWave-Radar)

Mit einem HLK-LD2450 bekommt LoHaTes **drei frei aufziehbare Zonen** — wer ein paar
Sekunden in einer steht, wird an Loxone gemeldet (`zone1/zone2/zone3`). Gedacht für
„vors Garagentor stellen und es geht auf" oder Licht bei Annäherung.

Komplett optional: ohne das Radar-Paket ändert sich nichts, und der Radar-Punkt
verschwindet aus der Navigation. Ausführlich: **[docs/radar.md](docs/radar.md)**.

## Web-Passwort vergessen?

**Werkseinstellung: Benutzer `admin`, Passwort `12345678`** — bei jedem frisch gebauten Gerät
gleich, also nach der Inbetriebnahme einmal ändern.

Das Login-Passwort lässt sich am Gerät unter `http://<esp>/passwort` ändern und liegt im
Flash. Drei Wege zurück, falls es weg ist — einer geht immer:

| Weg | Wie |
|---|---|
| Noch eingeloggt | Knopf *„Auf Standard zurücksetzen"* auf `/passwort` |
| Zugriff aufs Gerät | **BOOT-Taster 10 Sekunden halten** → Standard aus `secrets.yaml` gilt wieder |
| Neu flashen | `web_password` in `secrets.yaml` ändern und flashen — ein selbst gesetztes Passwort wird dabei automatisch verworfen |

Der letzte Punkt ist Absicht: Ein eigenes Passwort liegt im NVS und würde ein Neuflashen
sonst überleben und dich dauerhaft aussperren. LoHaTes speichert deshalb einen Hash des
Standard-Passworts mit — ändert sich der Standard, gewinnt er.

Das **OTA-Passwort** zum Flashen ist ein anderes und steht ebenfalls in `secrets.yaml`
(`ota_password`).

## Änderungen gegenüber dem Original (AGPL-§5-Hinweis)

Dieses Repository enthält eine veränderte Kopie von
[yoziru/esphome-tesla-ble](https://github.com/yoziru/esphome-tesla-ble)
(in [`firmware/`](firmware/), Original-Lizenz unverändert enthalten). Details siehe
[englisches README](README.md#changes-vs-upstream-agpl-5-notice).

## Credits

- [yoziru/esphome-tesla-ble](https://github.com/yoziru/esphome-tesla-ble) — die
  Tesla-BLE-Protokoll-Implementierung, auf der dieses Projekt aufbaut (AGPL-3.0)
- [ESPHome](https://esphome.io) — Firmware-Framework
- Schwesterprojekt: [HoxPi](https://github.com/newstedaut/HoxPi) — dieselbe Idee für
  Hoval®-Wärmepumpen

## Lizenz

[AGPL-3.0](LICENSE) — wie das Upstream-Projekt, von dem es abstammt.
