# Loxone-Vorlagen / Loxone templates

Fertige Gerätevorlagen für Loxone Config — statt alle Befehle von Hand anzulegen.

| Datei | Inhalt |
|---|---|
| `VIU_LoHaTes.xml` | Virtueller UDP-Eingang (Port 7101) mit allen 10 Status-Werten |
| `VQ_LoHaTes.xml` | Virtueller Ausgang mit allen 7 Befehlen |

## Import (DE)

1. Datei herunterladen
2. Loxone Config öffnen → Miniserver in der Peripherie anklicken
3. **Virtuelle Eingänge** markieren → im Menüband **Vorlage importieren** (bzw.
   Gerätevorlagen → Importieren) → `VIU_LoHaTes.xml` wählen
4. Dasselbe bei **Virtuelle Ausgänge** mit `VQ_LoHaTes.xml`
5. **Anpassen:** Beim Virtuellen Ausgang die Adresse auf die IP deines LoHaTes-ESP
   ändern (`/dev/udp/<esp-ip>/7101`); beim UDP-Eingang optional die Senderadresse setzen
6. Alternativ: XML-Dateien in den Templates-Ordner von Loxone Config legen
   (`C:\ProgramData\Loxone\Loxone Config <Version>\Templates\VirtualIn` bzw. `...\VirtualOut`)
   und Config neu starten

## Import (EN)

Download the XML, open Loxone Config, select **Virtual inputs** → **Import template**
→ `VIU_LoHaTes.xml`; same for **Virtual outputs** with `VQ_LoHaTes.xml`. Then adjust the
output address to your ESP's IP (`/dev/udp/<esp-ip>/7101`).

> Getestet mit Loxone Config 15/16. Falls der Import bei deiner Version meckert,
> bitte ein Issue aufmachen — das XML-Schema ändert sich gelegentlich.
