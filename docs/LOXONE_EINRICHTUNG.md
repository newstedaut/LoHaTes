# LoHaTes in Loxone & Home Assistant einrichten

Datenfluss: **Tesla ←BLE→ ESP (lohates.lan / 192.168.20.44) ←UDP:7091→ Miniserver (192.168.1.10)**
Zusätzlich ESP →ESPHome-API→ Home Assistant. Alles lokal, keine Cloud.

---

## 1. Virtueller UDP-Eingang (Status vom Tesla)

Loxone Config → Miniserver → **Virtuelle Eingänge → Virtueller UDP-Eingang** anlegen:

| Eigenschaft | Wert |
|---|---|
| Bezeichnung | LoHaTes |
| UDP-Empfangsport | **7091** |
| Senderadresse | 192.168.20.44 (optional, filtert fremde Pakete) |

Der ESP sendet alle 10 s eine Zeile:
```
lohates:soc=72;pwr=7.4;amps=11;volt=232;range=310;asleep=0;plugged=1;charging=1;rssi=-67;present=1
```
Bei Kommen/Gehen des Autos zusätzlich **sofort**: `lohates:present=1` bzw. `lohates:present=0`

Darunter je Wert einen **Virtuellen UDP-Eingang Befehl** anlegen:

| Bezeichnung | Befehlserkennung | Einheit/Anzeige | Bemerkung |
|---|---|---|---|
| Tesla SOC | `soc=\v` | % | -1 = unbekannt (Auto schläft) |
| Tesla Ladeleistung | `pwr=\v` | kW | |
| Tesla Ladestrom | `amps=\v` | A | Ist-Strom |
| Tesla Spannung | `volt=\v` | V | |
| Tesla Reichweite | `range=\v` | km | |
| Tesla schläft | `asleep=\v` | Digital | 1 = schläft |
| Tesla angesteckt | `plugged=\v` | Digital | 1 = Kabel drin |
| Tesla lädt | `charging=\v` | Digital | 1 = lädt gerade |
| Tesla BLE-Signal | `rssi=\v` | dBm | ca. -50 gut … -85 schwach |
| **Tesla anwesend** | `present=\v` | Digital | 1 = in BLE-Reichweite |

> Tipp: Im Loxone Config **UDP-Monitor** (Netzwerkmonitor) siehst du die ankommenden
> Pakete live – so prüfst du Port und Syntax in 30 Sekunden.

---

## 2. Virtueller Ausgang (Befehle an den Tesla)

**Virtuelle Ausgänge → Virtueller Ausgang** anlegen:

| Eigenschaft | Wert |
|---|---|
| Bezeichnung | LoHaTes Befehle |
| Adresse | `/dev/udp/192.168.20.44/7091` |

Darunter je Funktion einen **Virtuellen Ausgang Befehl**:

| Bezeichnung | Befehl bei EIN | Typ |
|---|---|---|
| Tesla wecken | `wake` | Digital (Impuls) |
| Laden Start | `charge=1` | Digital |
| Laden Stopp | `charge=0` | Digital |
| Ladestrom setzen | `amps=<v>` | **Analog** (1–16) |
| Ladelimit setzen | `limit=<v>` | **Analog** (50–100) |
| Verriegeln | `lock` | Digital |
| Entriegeln | `unlock` | Digital |
| Ladeport öffnen | `port_open` | Digital |

Bei den Analog-Befehlen „Als Digitalausgang verwenden" **abhaken** – gesendet wird
bei jeder Wertänderung. Befehle wirken auch am schlafenden Auto: die Firmware
weckt es bei Bedarf selbst (WAKE_IF_NEEDED).

---

## 3. Anwesenheit: „Tesla kommt" / „Tesla fährt weg"

So verhält sich `present`:
- **Auto kommt in BLE-Reichweite** (~5–10 m zur Garage): ESP verbindet → `present=1` (wenige Sekunden nach Ankunft)
- **Auto fährt weg**: Verbindung reißt ab → `present=0` (wenige Sekunden bis ~30 s)
- Kurze BLE-Abrisse bei stehendem Auto sind möglich → **immer entprellen!**

### Baustein-Kette in Loxone Config

**Schritt 1 – Entprellen:** VI „Tesla anwesend" → **Ausschaltverzögerung** 120 s
(Einschalten sofort, Ausschalten erst nach 2 min stabil weg) → Merker **„Tesla da"**.

**Schritt 2 – „Tesla kommt heim"** (Impuls):
```
„Tesla da" → Flankenerkennung steigend (z.B. Impuls bei Flanke ↑)
   UND „Tesla war lange weg" (siehe Schritt 4)
   UND Garagentor = zu
→ Impuls auf Torsteuerung AUF
```

**Schritt 3 – „Tesla ist weggefahren"** (Impuls):
```
„Tesla da" → Flankenerkennung fallend
   UND Garagentor = offen
→ Einschaltverzögerung 60–120 s → Impuls auf Torsteuerung ZU
```
Damit geht das Tor **erst zu, wenn das Auto wirklich weg ist** – nicht während es
davor steht. Steht der Tesla vor dem offenen Tor (`present=1`), passiert nichts;
zugemacht wird dann wie gewohnt manuell/per Loxone-Logik (z.B. Zeit, Taster, App).

**Schritt 4 – Fehltrigger-Schutz „war lange weg":**
„Tesla da" invertiert → **Einschaltverzögerung 10 min** → Merker „Tesla war lange weg".
So öffnet das Tor nur, wenn das Auto vorher ≥10 min weg war (verhindert Öffnen
durch kurzen BLE-Abriss beim parkenden Auto).

**Zusätzliche Bedingungen nach Geschmack:** Zeitfenster (nicht nachts), Alarmanlage
unscharf, oder Tor-zu nur wenn `asleep=0→weggefahren` plausibel.

---

## 4. PV-Überschussladen (Skizze)

1. Überschuss [W] aus deiner Energielogik → **Formel:** `Ampere = Überschuss / 690`
   (3-phasig: 3 × 230 V = 690 W pro Ampere; 1-phasig: /230)
2. Begrenzen mit Min/Max auf **6–16 A** (unter 6 A lädt der Tesla unsauber)
3. Ergebnis auf VQ „Ladestrom setzen" (`amps=<v>`)
4. Schwellwert: Überschuss > ~4,2 kW (3-ph) → `charge=1`, längere Zeit darunter → `charge=0`
5. Nur senden wenn `plugged=1`. Hysterese/Mindestlaufzeit (10–15 min) einbauen,
   damit nicht bei jeder Wolke gestartet/gestoppt wird.

---

## 5. Home Assistant

Der ESP ist zusätzlich ein normales ESPHome-Gerät:

1. HA → Einstellungen → Geräte & Dienste → **Integration hinzufügen → ESPHome**
2. Host: `192.168.20.44` (oder `lohates.lan`), Port `6053`
3. Encryption-Key: steht in `TeslaBLE\secrets.yaml` (`api_encryption_key`)

Danach erscheinen **alle** Entitäten automatisch: SOC, Ladeleistung, Klima (sogar
als Thermostat!), Frunk/Kofferraum, Reifendruck, Schlösser, Ladestrom-Regler,
Wake/Pair-Buttons usw. – deutlich mehr Detail als der UDP-Push.

- **Rollenteilung:** Garagentor & Laden = Loxone (lokal, entscheidend).
  HA = Anzeige, Statistik, Spielereien. TeslaMate bleibt für Langzeit-Statistik
  (liest Cloud, kann eh nur lesen).
- **Wichtig:** Der ESP läuft auch ohne HA komplett weiter (api reboot_timeout=0).
- Anwesenheit gibt's in HA über den Sensor „Asleep"/BLE Signal bzw. das
  Gerät online/offline – fürs Tor aber besser direkt `present` in Loxone nutzen.

---

## 6. Testen ohne Auto

Von jedem PC im Netz (PowerShell):
```powershell
$u = New-Object System.Net.Sockets.UdpClient
$b = [Text.Encoding]::ASCII.GetBytes("wake")
$u.Send($b, $b.Length, "192.168.20.44", 7091) | Out-Null; $u.Close()
```
→ Auto wacht auf (Beweis, dass VQ-Richtung stimmt). Eingangsrichtung: UDP-Monitor
in Loxone Config öffnen und auf das 10-s-Paket warten.

## Referenz
- Firmware/Änderungen: `..\TeslaBLE\packages\loxone.yml` (UDP-Logik), `client.yml` (Anwesenheit)
- Flashen: OTA `esphome run tesla-ble-esp32-s3.yml --device 192.168.20.44` aus `C:\Users\<name>\LoHaTesBuild`
- Web-UI: http://lohates.lan
