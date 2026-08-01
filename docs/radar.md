# Presence zones with an HLK-LD2450 (optional add-on)

*Deutsche Fassung weiter unten.*

This is an **optional extra** for LoHaTes. It has nothing to do with the Tesla side —
skip it entirely if you only want car control. Without `packages/radar.yml` the firmware
behaves exactly as before and the Radar page is hidden from the navigation.

## What it does

An HLK-LD2450 is a 24 GHz mmWave radar that tracks **people** (up to three at once) as
X/Y coordinates in front of the device. LoHaTes turns that into **three freely drawable
zones**. Stand in a zone for 3 s and it is reported to Loxone, so each zone can trigger
something different — open the garage door, switch on the outside light, whatever.

> It tracks **people, not cars**. A parked car is a static metal object and will not be
> detected reliably. Use the BLE presence signal for the car.

## Wiring
| LD2450 | ESP32-S3 |
|---|---|
| TX | GPIO18 (RX) |
| RX | GPIO17 (TX) |
| 5V / GND | 5V / GND |

Enable it by adding `radar: !include packages/radar.yml` to the `packages:` block of your
device YAML, then flash.

**Calibrating** — open `http://<esp>/radar` (works nicely on a phone). You get a live
top-down map with the detected targets and a fading trail. Pick zone 1, 2 or 3, then either
drag a rectangle on the map or walk to the spot and press *"I'm standing here"* — the zone
is placed around you and saved into the radar module itself (survives power loss).
Finally switch the zone mode to **Detection**, otherwise zones are ignored.

**What Loxone receives** — after someone stands in a zone for 3 s (configurable via
`radar_hold_time`), this goes out on UDP port 7101, repeated every 10 s so a lost packet
heals itself:

```
lohates:zone1=1;zone2=0;zone3=0
```

Add them as **analog** virtual inputs (min 0 / max 1) with `zone1=\v`, `zone2=\v`,
`zone3=\v`. Digital inputs are unreliable here — Loxone's range check clamps them to 0.

> **Tip:** combine the zone with "a known phone is on the WiFi" in Loxone. The radar knows
> *where* somebody stands but not *who* — the phone check adds the missing half.

---

# Anwesenheits-Zonen mit HLK-LD2450 (optionales Zubehör)

Das ist eine **optionale Erweiterung**. Mit der Tesla-Seite hat sie nichts zu tun — wer nur
das Auto steuern will, lässt sie einfach weg. Ohne `packages/radar.yml` verhält sich die
Firmware wie vorher und der Radar-Punkt verschwindet aus der Navigation.

## Wozu

Der HLK-LD2450 ist ein 24-GHz-mmWave-Radar, das **Personen** (bis zu drei gleichzeitig) als
X/Y-Koordinaten vor dem Gerät verfolgt. LoHaTes macht daraus **drei frei aufziehbare Zonen**.
Wer 3 s in einer Zone steht, wird an Loxone gemeldet — jede Zone kann also etwas anderes
auslösen: Garagentor auf, Außenlicht an, was auch immer.

> Erkannt werden **Menschen, nicht Autos**. Ein geparktes Auto ist ein statisches
> Metallteil und wird nicht zuverlässig erfasst. Fürs Auto ist das BLE-Signal zuständig.

## Verdrahtung
| LD2450 | ESP32-S3 |
|---|---|
| TX | GPIO18 (RX) |
| RX | GPIO17 (TX) |
| 5V / GND | 5V / GND |

Aktivieren: `radar: !include packages/radar.yml` im `packages:`-Block der Geräte-YAML
ergänzen und flashen.

**Kalibrieren** — `http://<esp>/radar` öffnen (funktioniert gut am Handy). Du siehst eine
Live-Draufsicht mit den erkannten Zielen und einer verblassenden Spur. Zone 1, 2 oder 3
wählen, dann entweder ein Rechteck auf die Karte ziehen oder sich an die Stelle stellen und
*„Ich stehe JETZT hier"* drücken — die Zone legt sich um dich und wird im Radar-Modul selbst
gespeichert (übersteht Stromausfall). Zum Schluss den Zonen-Modus auf **Detection** stellen,
sonst werden die Zonen ignoriert.

**Was Loxone bekommt** — steht jemand 3 s in einer Zone (einstellbar über
`radar_hold_time`), geht das per UDP auf Port 7101 raus, alle 10 s wiederholt, damit sich
ein verlorenes Paket selbst heilt:

```
lohates:zone1=1;zone2=0;zone3=0
```

Als **analoge** Virtuelle Eingänge anlegen (Min 0 / Max 1) mit `zone1=\v`, `zone2=\v`,
`zone3=\v`. Digitale Eingänge sind hier unzuverlässig — die Wertebereichsprüfung klemmt
sie auf 0.

> **Tipp:** In Loxone die Zone mit „bekanntes Handy ist im WLAN" verknüpfen. Das Radar weiß,
> *wo* jemand steht, aber nicht *wer* — der Handy-Check liefert die fehlende Hälfte.
