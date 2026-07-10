<img src="logo.svg" alt="LoHaTes" width="300">

# LoHaTes — Tesla ↔ Loxone & Home Assistant bridge

**🇩🇪 [Deutsche Version](README.de.md)**

[![Buy Me a Coffee](https://img.shields.io/badge/☕-Buy%20me%20a%20coffee-ffdd00)](https://buymeacoffee.com/bernhardsu9) [![PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/donate/?hosted_button_id=HWBBHDSVD3MCC) [![License: AGPL v3](https://img.shields.io/badge/License-AGPL_v3-blue.svg)](LICENSE)

**One ESP32-S3 in your garage talks to your Tesla over Bluetooth — and to Loxone, Home Assistant and AI assistants. Entirely local, no cloud, no Tesla API fees.**

LoHaTes (**Lo**xone + **H**ome **A**ssistant + **Tes**la, rhymes with Socrates) builds on the excellent
[yoziru/esphome-tesla-ble](https://github.com/yoziru/esphome-tesla-ble) and adds a native
**Loxone UDP interface**, a bilingual (DE/EN) **setup dashboard served by the ESP itself**,
**per-command permission checkboxes**, presence detection for garage-door automation, and an
**MCP server** so AI assistants like Claude can inspect and (if allowed) control the car.

> **Disclaimer:** Independent open-source project, **not affiliated with Tesla, Inc., Loxone
> Electronics GmbH or Home Assistant / the Open Home Foundation**. Mentioned trademarks belong
> to their owners. You interface with your own car at your own risk.

## Features

- **Tesla over BLE** — wake, charging start/stop, amps (PV surplus charging!), charge limit,
  lock/unlock, charge port, plus sensors: SOC, range, power, climate, tire pressure, doors …
  The car keeps sleeping normally (VCSEC polling never wakes it)
- **Loxone native** — UDP status push every 10 s + instant presence events
  (`present=1/0` when the car arrives/leaves → garage door logic), commands back via
  virtual output. No plugins, no gateway, works without HA
- **Home Assistant** — regular ESPHome device, all entities auto-discovered incl. climate
  thermostat; runs fine without HA too (`reboot_timeout: 0s`)
- **Setup dashboard on the ESP** — `http://<esp>/loxone` (DE) / `http://<esp>/en` (EN):
  live tiles, step-by-step Loxone tables, HA guide, BLE-key pairing walkthrough,
  embedded device UI, logo at `/logo.svg` for dashboards
- **Security** — web login (basic auth), HoxPi-style **permission checkboxes per command**
  (wake/charge/amps/limit/lock/unlock/port) enforced for Loxone UDP *and* AI alike;
  `unlock` ships disabled
- **AI interface (MCP)** — small [Model Context Protocol](https://modelcontextprotocol.io)
  server (runs on any Raspberry Pi / always-on box, port 8809): `get_status`, `diagnose`,
  `wake_vehicle`, `set_charging_amps` … Writing gated by config *and* the on-device checkboxes

## Hardware

| Part | Note |
|---|---|
| ESP32-S3 (16 MB flash, 8 MB PSRAM) | e.g. N16R8 dev board; BLE + WiFi concurrently |
| USB power supply | placed < 5 m from the car (garage/carport) |
| optional: Raspberry Pi | for the MCP (AI) server — any always-on Linux box works |

## Install (firmware)

```bash
pip install esphome
cd firmware
cp secrets.yaml.example secrets.yaml   # fill in WiFi, VIN, BLE MAC, Loxone IP, keys
esphome run tesla-ble-esp32-s3.yml     # first flash via USB, afterwards OTA
```

> **Windows note:** ESP-IDF cannot build in paths containing spaces — keep the project in
> e.g. `C:\LoHaTesBuild`.

Finding your car's BLE MAC and pairing the key: open `http://<esp-ip>/loxone` — the
dashboard walks you through everything (DE/EN).

## Loxone / Home Assistant / AI

Full step-by-step guides are **served by the device itself** at `http://<esp-ip>/loxone`
(German) and `http://<esp-ip>/en` (English) — virtual input/output tables for Loxone
(UDP port 7091), ESPHome integration for HA, garage-door presence logic, PV surplus
formula, and the Claude Desktop MCP snippet. A copy lives in [`docs/`](docs/).

**Ready-made Loxone templates** (virtual UDP input + virtual output as importable XML):
see [`loxone-templates/`](loxone-templates/).

### MCP server (optional, for AI assistants)

```bash
# on your Pi / server:
mcp/lohates_mcp_setup.sh    # creates venv + systemd service on port 8809
```

Claude Desktop → `claude_desktop_config.json`:

```json
{ "mcpServers": { "lohates": {
    "command": "npx", "args": ["-y", "mcp-remote", "http://<pi-ip>:8809/mcp"] } } }
```

## Changes vs. upstream (AGPL §5 notice)

This repository contains a modified copy of
[yoziru/esphome-tesla-ble](https://github.com/yoziru/esphome-tesla-ble)
(in [`firmware/`](firmware/), original license preserved). Modifications and additions:

- `firmware/packages/loxone.yml` — Loxone UDP interface (status push, presence events,
  command receiver) and feature/permission switches
- `firmware/components/loxone_docs/` — new component: bilingual setup dashboard
  (`/loxone`, `/en`, `/geraete`, `/geraete-en`), permission checkboxes, `/logo.svg`
- `firmware/packages/client.yml` — BLE connect/disconnect presence hooks
- `firmware/packages/base.yml` — web server with auth + injected banner (`www/lohates.js`),
  `api.reboot_timeout: 0s` (runs without Home Assistant)
- `firmware/boards/esp32-s3.yml`, `tesla-ble-esp32-s3.yml` — ESP32-S3 N16R8 board config
- `mcp/` — new: MCP server for AI assistants (not part of upstream)

## Credits

- [yoziru/esphome-tesla-ble](https://github.com/yoziru/esphome-tesla-ble) — the Tesla BLE
  protocol implementation this project builds on (AGPL-3.0)
- [ESPHome](https://esphome.io) — firmware framework
- Sibling project: [HoxPi](https://github.com/newstedaut/HoxPi) — same idea for
  Hoval® heat pumps

## License

[AGPL-3.0](LICENSE) — same as the upstream project it derives from.
