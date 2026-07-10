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

## Eingebaute Doku / Built-in docs

Jeder Befehl und jeder Wert bringt seine Beschreibung mit: Das Feld **Beschreibung**
(Comment) und der **Hinweis** (HintText) erklären direkt in Loxone Config, was die
Funktion tut, welche Wertebereiche gelten und worauf zu achten ist (z. B. PV-Formel
beim Ladestrom, Entprell-Empfehlung bei „Tesla anwesend", Warnung beim Entriegeln).
Einfach das Objekt anklicken und in die Eigenschaften schauen.

Every command/value ships with its documentation: the **Comment** and **HintText**
fields explain ranges, use cases and caveats right inside Loxone Config.

> Getestet mit Loxone Config 17. Falls der Import bei deiner Version meckert,
> bitte ein Issue aufmachen — das XML-Schema ändert sich gelegentlich.
> Vorlagen können laut Loxone auch in die offizielle [Loxone Library](https://library.loxone.com/)
> hochgeladen werden ([Guideline](https://library.loxone.com/guideline)) — geplant.
