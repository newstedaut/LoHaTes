#include "loxone_docs.h"

namespace esphome {
namespace loxone_docs {

static const char LOXONE_HTML[] = R"LHTS(<!doctype html><html lang=de><head><meta charset=utf-8>
<meta name=viewport content="width=device-width,initial-scale=1">
<title>LoHaTes · Einrichtung</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;
 display:flex;align-items:center;gap:1.3rem;flex-wrap:wrap;position:sticky;top:0;z-index:9;
 box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav{display:flex;gap:.3rem;flex-wrap:wrap}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
.jump{display:flex;align-items:center;gap:.25rem;flex-wrap:wrap;margin:.2rem 0 .9rem;
 font-size:.85rem;background:#fff;border:1px solid #e6e9ef;border-radius:10px;padding:.4rem .6rem}
.jump span{color:#8893a2;font-weight:700;margin-right:.3rem}
.jump a{color:#5a6675;text-decoration:none;padding:.25rem .6rem;border-radius:6px;font-weight:600}
.jump a:hover{background:#eef1f5;color:#e82127}
main{max-width:1040px;margin:0 auto;padding:1.3rem}
h1{font-size:1.5rem;margin:.3rem 0 1.1rem;color:#1c2531}
.domain{background:#fff;border-radius:15px;box-shadow:0 2px 10px rgba(20,30,50,.07);
 margin:1.3rem 0;border:1px solid #e6e9ef;overflow:hidden}
.dh{display:flex;align-items:center;gap:.7rem;padding:.9rem 1.2rem;color:#fff}
.dh.lox{background:linear-gradient(90deg,#4ea339,#69c350)}
.dh.ha{background:linear-gradient(90deg,#1e9ad6,#41bdf5)}
.dh.tes{background:linear-gradient(90deg,#c11a20,#e82127)}
.dh.ki{background:linear-gradient(90deg,#1c2531,#3a4a5e)}
.dh h2{margin:0;font-size:1.2rem;font-weight:700}
.dbody{padding:1rem 1.2rem 1.2rem}
.sub{font-size:.9rem;color:#8893a2;font-weight:700;text-transform:uppercase;letter-spacing:.4px;
 margin:1.1rem 0 .5rem;border-left:3px solid #41bdf5;padding-left:.5rem}
.cards{display:grid;grid-template-columns:repeat(auto-fill,minmax(150px,1fr));gap:.6rem;margin:.4rem 0}
.card{background:#f7f9fc;border:1px solid #e6ebf1;border-radius:11px;padding:.65rem .85rem}
.card .n{font-size:.8rem;color:#6c7787}
.card .v{font-size:1.32rem;font-weight:650;margin-top:.15rem;color:#1c2531}
.ok{color:#0a8f4f}.bad{color:#d6202f}.muted{color:#aab2bd}
table{border-collapse:collapse;width:100%;font-size:.9rem;margin-top:.4rem;background:#fff}
th,td{border-bottom:1px solid #eceff3;padding:.45rem .6rem;text-align:left}
th{color:#7a8694;font-weight:600;background:#f7f9fc}
td code,p code,li code{background:#f3f4f7;color:#c2185b;font-weight:600;padding:.05rem .35rem;border-radius:4px}
pre{background:#1c2531;color:#8fd97a;padding:.7rem .9rem;border-radius:9px;overflow-x:auto;font-size:.85rem}
.note{background:#eef6ff;border:1px solid #cfe2f7;border-radius:11px;padding:.8rem 1.1rem;color:#2b5378;font-size:.92rem;margin:.7rem 0}
.note.ok{background:#eafaf1;border-color:#bce7cd;color:#1c6b3f}
.note.warn{background:#fff3e6;border-color:#f3cf9e;color:#8a5a1e}
p{line-height:1.6;color:#3a4554}
a{color:#1e9ad6}
footer{color:#9aa3af;font-size:.8rem;text-align:center;padding:1.6rem}
</style></head><body>
<!--HEADER--><main>

<div class=jump><span>Springe zu:</span><a href="#live">Live</a><a href="#loxone">Loxone</a><a href="#ha">Home Assistant</a><a href="#ki">KI/MCP</a><a href="#sicherheit">Sicherheit</a><a href="#geraet">Ger&auml;t</a></div>
<h1 id=live>Live-Status</h1>
<div class=cards>
<div class=card><div class=n>Tesla anwesend</div><div class=v id=v_pres>&hellip;</div></div>
<div class=card><div class=n>Batterie</div><div class=v id=v_soc>&hellip;</div></div>
<div class=card><div class=n>Ladeleistung</div><div class=v id=v_pwr>&hellip;</div></div>
<div class=card><div class=n>Ladezustand</div><div class=v id=v_chg>&hellip;</div></div>
<div class=card><div class=n>Schl&auml;ft</div><div class=v id=v_slp>&hellip;</div></div>
<div class=card><div class=n>BLE-Signal</div><div class=v id=v_rssi>&hellip;</div></div>
</div>
<div class=note>Werte aktualisieren sich alle 10 s. &bdquo;-&ldquo; = Auto schl&auml;ft oder Wert noch unbekannt. Alle Entit&auml;ten und Buttons: <a href="/geraete">Ger&auml;te-UI</a>.</div>

<div class=domain id=loxone><div class="dh lox"><h2>Loxone einrichten</h2></div><div class=dbody>
<p>Kommunikation per <b>UDP, Port 7101</b>, in beide Richtungen. Miniserver: <code>192.168.1.10</code>, LoHaTes: <code>192.168.20.44</code> / <code>lohates.lan</code>. L&auml;uft komplett lokal &ndash; ohne Cloud, ohne Home Assistant.</p>
<div class=sub>1 &middot; Virtueller UDP-Eingang (Status empfangen)</div>
<p>Loxone Config &rarr; Virtuelle Eing&auml;nge &rarr; <b>Virtueller UDP-Eingang</b>: Empfangsport <code>7101</code>, Senderadresse <code>192.168.20.44</code>. LoHaTes sendet alle 10 s:</p>
<pre>lohates:soc=72;pwr=7.4;amps=11;volt=232;range=310;asleep=0;plugged=1;charging=1;rssi=-67;present=1</pre>
<p>Bei Ankunft/Wegfahrt zus&auml;tzlich <b>sofort</b>: <code>lohates:present=1</code> / <code>lohates:present=0</code>. Je Wert einen <b>UDP-Eingang-Befehl</b> anlegen:</p>
<table><tr><th>Bezeichnung</th><th>Befehlserkennung</th><th>Typ/Einheit</th><th>Bemerkung</th></tr>
<tr><td>Tesla SOC</td><td><code>soc=\v</code></td><td>Analog, %</td><td>-1 = unbekannt</td></tr>
<tr><td>Tesla Ladeleistung</td><td><code>pwr=\v</code></td><td>Analog, kW</td><td></td></tr>
<tr><td>Tesla Ladestrom</td><td><code>amps=\v</code></td><td>Analog, A</td><td>Ist-Strom</td></tr>
<tr><td>Tesla Spannung</td><td><code>volt=\v</code></td><td>Analog, V</td><td></td></tr>
<tr><td>Tesla Reichweite</td><td><code>range=\v</code></td><td>Analog, km</td><td></td></tr>
<tr><td>Tesla schl&auml;ft</td><td><code>asleep=\v</code></td><td>Digital</td><td>1 = schl&auml;ft</td></tr>
<tr><td>Tesla angesteckt</td><td><code>plugged=\v</code></td><td>Digital</td><td>1 = Kabel drin</td></tr>
<tr><td>Tesla l&auml;dt</td><td><code>charging=\v</code></td><td>Digital</td><td></td></tr>
<tr><td>Tesla BLE-Signal</td><td><code>rssi=\v</code></td><td>Analog, dBm</td><td>-50 gut &hellip; -85 schwach</td></tr>
<tr><td><b>Tesla anwesend</b></td><td><code>present=\v</code></td><td>Digital</td><td>1 = in BLE-Reichweite</td></tr></table>
<div class="note" style="margin-top:.8rem"><b>Mit Radarmodul (optional):</b> Zus&auml;tzlich kommt <code>lohates:zone1=1;zone2=0;zone3=0</code> &ndash; drei frei definierbare Zonen vor dem Ger&auml;t. Damit l&auml;sst sich z.&nbsp;B. das Tor &ouml;ffnen, wenn jemand davorsteht. Als <b>analoge</b> Eing&auml;nge anlegen (Min 0 / Max 1) mit <code>zone1=\v</code>, <code>zone2=\v</code>, <code>zone3=\v</code>. Einrichten und kalibrieren unter <a href="/radar">Radar</a>.</div>
<div class="note ok">Test: Loxone Config &rarr; UDP-Monitor &ouml;ffnen &rarr; alle 10 s kommt ein Paket.</div>
<div class=sub>2 &middot; Virtueller Ausgang (Befehle senden)</div>
<p>Virtuelle Ausg&auml;nge &rarr; <b>Virtueller Ausgang</b>, Adresse: <code>/dev/udp/192.168.20.44/7101</code></p>
<table><tr><th>Bezeichnung</th><th>Befehl bei EIN</th><th>Typ</th></tr>
<tr><td>Tesla wecken</td><td><code>wake</code></td><td>Digital (Impuls)</td></tr>
<tr><td>Laden Start / Stopp</td><td><code>charge=1</code> / <code>charge=0</code></td><td>Digital</td></tr>
<tr><td>Ladestrom setzen</td><td><code>amps=&lt;v&gt;</code></td><td>Analog 1&ndash;16 A</td></tr>
<tr><td>Ladelimit setzen</td><td><code>limit=&lt;v&gt;</code></td><td>Analog 50&ndash;100 %</td></tr>
<tr><td>Ver-/Entriegeln</td><td><code>lock</code> / <code>unlock</code></td><td>Digital &ndash; unlock nur mit Freigabe-Haken</td></tr>
<tr><td>Ladeport &ouml;ffnen</td><td><code>port_open</code></td><td>Digital</td></tr></table>
<div class=note>Befehle wecken das Auto bei Bedarf automatisch. Analog-Befehle senden bei jeder Wert&auml;nderung.</div>
<div class=sub>3 &middot; Garagentor-Logik (Anwesenheit)</div>
<table><tr><th>Schritt</th><th>Baustein-Kette</th></tr>
<tr><td>Entprellen</td><td>VI present &rarr; Ausschaltverz&ouml;gerung 120 s &rarr; Merker &bdquo;Tesla da&ldquo;</td></tr>
<tr><td>War lange weg</td><td>&bdquo;Tesla da&ldquo; invertiert &rarr; Einschaltverz&ouml;gerung 10 min</td></tr>
<tr><td>Tor AUF</td><td>Flanke &uarr; &bdquo;Tesla da&ldquo; UND &bdquo;war lange weg&ldquo; UND Tor zu &rarr; Impuls AUF</td></tr>
<tr><td>Tor ZU</td><td>Flanke &darr; &bdquo;Tesla da&ldquo; UND Tor offen &rarr; Verz&ouml;gerung 60&ndash;120 s &rarr; Impuls ZU</td></tr></table>
<p>Steht das Auto vor dem offenen Tor (present=1), schlie&szlig;t die Logik nicht &ndash; zugemacht wird manuell oder per Loxone.</p>
<div class=sub>4 &middot; PV-&Uuml;berschussladen</div>
<pre>Ampere = PV-&Uuml;berschuss [W] / 690     (3-phasig; 1-phasig: /230)
begrenzen auf 6..16 A &rarr; VQ "amps=&lt;v&gt;"
&Uuml;berschuss &gt; ~4,2 kW l&auml;nger anstehend &rarr; charge=1, sonst charge=0
nur wenn plugged=1; Hysterese/Mindestlaufzeit 10&ndash;15 min</pre>
</div></div>

<div class=domain id=ha><div class="dh ha"><h2>Home Assistant einrichten</h2></div><div class=dbody>
<p>LoHaTes ist ein normales ESPHome-Ger&auml;t &ndash; HA bekommt <b>alle</b> Entit&auml;ten automatisch (mehr Detail als der UDP-Push): SOC, Laden, Klima als Thermostat, Frunk/Kofferraum, Reifendruck, Schl&ouml;sser, Wake-Button u.v.m.</p>
<table><tr><th>Schritt</th><th>Aktion</th></tr>
<tr><td>1</td><td>HA &rarr; Einstellungen &rarr; Ger&auml;te &amp; Dienste &rarr; <b>Integration hinzuf&uuml;gen &rarr; ESPHome</b></td></tr>
<tr><td>2</td><td>Host: <code>192.168.20.44</code> &middot; Port: <code>6053</code></td></tr>
<tr><td>3</td><td>Encryption-Key eingeben (steht in <code>secrets.yaml</code> des Projekts)</td></tr></table>
<div class="note ok">LoHaTes l&auml;uft auch ohne HA vollst&auml;ndig weiter &ndash; HA ist Anzeige/Statistik, die Steuerung Richtung Loxone bleibt unabh&auml;ngig.</div>
<div class=sub>Dashboard-Karte mit Logo</div>
<pre>type: picture-elements
image: http://lohates.lan/logo.svg
elements: []   # eigene Badges/Werte nach Geschmack erg&auml;nzen</pre>
<p>Empfohlene Rollenteilung: <b>Loxone</b> = Tor &amp; Laden (entscheidend, lokal), <b>HA</b> = Anzeige, Statistik, Automationen nach Lust und Laune. TeslaMate darf f&uuml;r Langzeit-Statistik weiterlaufen (liest nur Cloud).</p>
</div></div>

<div class=domain id=ki><div class="dh ki"><h2>KI-Zugriff (MCP)</h2></div><div class=dbody>
<p>LoHaTes hat eine KI-Schnittstelle nach dem <a href="https://modelcontextprotocol.io">Model Context Protocol</a> &ndash; wie HoxPi. KI-Assistenten wie Claude k&ouml;nnen damit live den Tesla-Status abfragen, Probleme diagnostizieren und (falls freigegeben) das Laden steuern.</p>
<table>
<tr><td>Server</td><td>l&auml;uft auf dem HoxPi-Pi: <code>http://hoval-pi.local:8809/mcp</code> (Dienst <code>lohates-mcp</code>)</td></tr>
<tr><td>Werkzeuge</td><td><code>get_status</code>, <code>diagnose</code>, <code>get_all_entities</code>, <code>wake_vehicle</code>, <code>set_charging</code>, <code>set_charging_amps</code>, <code>set_charging_limit</code>, <code>open_charge_port</code>, <code>lock_vehicle</code>, <code>about</code></td></tr>
<tr><td>Sicherheit</td><td>Steuern nur mit <code>enable_write=true</code>; <b>Entriegeln</b> extra gesperrt (<code>enable_unlock</code>, Standard aus). Config: <code>/home/admin/lohates-mcp/config.json</code> am Pi.</td></tr>
</table>
<div class=sub>In Claude Desktop einbinden</div>
<p>Claude Desktop &rarr; Einstellungen &rarr; Entwickler &rarr; <code>claude_desktop_config.json</code> bearbeiten (Node.js n&ouml;tig):</p>
<pre>{
  "mcpServers": {
    "lohates": {
      "command": "npx",
      "args": ["-y", "mcp-remote", "http://hoval-pi.local:8809/mcp"]
    }
  }
}</pre>
<p>Danach Claude neu starten &ndash; und fragen: <i>&bdquo;Wie geht&rsquo;s meinem Tesla?&ldquo;</i></p>
<div class=note>Dienst-Verwaltung am Pi: <code>systemctl status/restart lohates-mcp</code> &middot; Logs: <code>journalctl -u lohates-mcp -f</code></div>
</div></div>

<div class=domain id=sicherheit><div class="dh ki"><h2>Sicherheit &amp; Freigaben</h2></div><div class=dbody>
<p>Wie bei HoxPi: <b>Haken = Befehl beschreibbar</b>. Gilt f&uuml;r Loxone-UDP <b>und</b> KI/MCP gleichzeitig. &Auml;nderungen wirken sofort und &uuml;berleben Neustarts. Web-UI und diese Seite sind per Login gesch&uuml;tzt (Benutzer <code>admin</code>, Passwort in <code>secrets.yaml</code>).</p>
<table id=sectbl>
<tr><th>Freigabe</th><th>Wirkung</th><th>Erlaubt</th></tr>
<tr><td>Loxone Status-Push</td><td>UDP-Daten an den Miniserver senden</td><td><input type=checkbox data-sw="loxone_status_push"></td></tr>
<tr><td>Loxone Befehle</td><td>UDP-Befehle vom Miniserver annehmen (Hauptschalter)</td><td><input type=checkbox data-sw="loxone_befehle"></td></tr>
<tr><td>KI Steuern</td><td>MCP-Server darf steuern (Hauptschalter)</td><td><input type=checkbox data-sw="ki_steuern_erlaubt"></td></tr>
<tr><td>Radar Zone-Push</td><td>Zonen-Meldungen des Radars an Loxone senden (nur mit LD2450)</td><td><input type=checkbox data-sw="radar_zone_push"></td></tr>
<tr><td><code>wake</code></td><td>Auto aufwecken</td><td><input type=checkbox data-sw="erlaubt_wake"></td></tr>
<tr><td><code>charge</code></td><td>Laden start/stopp</td><td><input type=checkbox data-sw="erlaubt_charge"></td></tr>
<tr><td><code>amps</code></td><td>Ladestrom setzen</td><td><input type=checkbox data-sw="erlaubt_amps"></td></tr>
<tr><td><code>limit</code></td><td>Ladelimit setzen</td><td><input type=checkbox data-sw="erlaubt_limit"></td></tr>
<tr><td><code>lock</code></td><td>Verriegeln</td><td><input type=checkbox data-sw="erlaubt_lock"></td></tr>
<tr><td><code>unlock</code></td><td><b>Entriegeln</b> (Standard: gesperrt!)</td><td><input type=checkbox data-sw="erlaubt_unlock"></td></tr>
<tr><td><code>port_open</code></td><td>Ladeport &ouml;ffnen</td><td><input type=checkbox data-sw="erlaubt_port_open"></td></tr>
</table>
<div class=sub>Passwort &auml;ndern oder vergessen</div>
<p>Am einfachsten direkt am Ger&auml;t: <a href="/passwort"><b>Seite &bdquo;Passwort&ldquo; &ouml;ffnen</b></a>.
Dort l&auml;sst sich das Login-Passwort setzen &ndash; es wird dauerhaft im Ger&auml;t gespeichert
und &uuml;berlebt Neustarts. Benutzername bleibt <code>admin</code>.</p>
<p><b>Passwort vergessen?</b> Drei Wege f&uuml;hren zur&uuml;ck &ndash; einer geht immer:</p>
<table>
<tr><th>Weg</th><th>Wie</th></tr>
<tr><td>Eingeloggt</td><td>Auf <a href="/passwort">/passwort</a> den Knopf &bdquo;Auf Standard zur&uuml;cksetzen&ldquo;</td></tr>
<tr><td>Am Ger&auml;t</td><td><b>BOOT-Taster 10 Sekunden halten</b> &rarr; Standard aus <code>secrets.yaml</code> gilt wieder</td></tr>
<tr><td>Neu flashen</td><td><code>web_password</code> in <code>secrets.yaml</code> &auml;ndern und flashen &ndash; ein selbst gesetztes Passwort wird dabei automatisch verworfen</td></tr>
</table>
<p>Das <b>OTA-Passwort</b> zum Flashen ist ein anderes und steht ebenfalls in
<code>secrets.yaml</code> (<code>ota_password</code>).</p>
<div class="note warn">Entriegeln nur freigeben, wenn du es wirklich brauchst &ndash; jeder im LAN mit Passwort bzw. Loxone-Zugriff kann es dann ausl&ouml;sen.</div>
</div></div>

<div class=domain id=geraet><div class="dh tes"><h2>Tesla &amp; Ger&auml;t</h2></div><div class=dbody>
<table>
<tr><td>Ger&auml;t</td><td>ESP32-S3 N16R8 &bdquo;LoHaTes&ldquo; &ndash; Tesla-BLE-Bridge (Basis: yoziru/esphome-tesla-ble)</td></tr>
<tr><td>IP / Domain</td><td><code>192.168.20.44</code> (fix) &middot; <code>lohates.lan</code></td></tr>
<tr><td>Ger&auml;te-UI</td><td><a href="/geraete">http://lohates.lan/geraete</a> (alle Entit&auml;ten, Buttons, Pairing)</td></tr>
<tr><td>Logo</td><td><a href="/logo.svg">/logo.svg</a> (f&uuml;r HA-Dashboards)</td></tr>
<tr><td>Schl&auml;ft das Auto?</td><td>VCSEC-Polling weckt nicht; Detail-Polling nur im Wachfenster. Wecken nur auf Befehl.</td></tr>
<tr><td>BLE-Key</td><td>Gepairt als Fahrzeugschl&uuml;ssel (Rolle DRIVER). Neu pairen: Ger&auml;te-UI &rarr; &bdquo;Pair BLE key&ldquo; + NFC-Karte.</td></tr>
<tr><td>OTA-Update</td><td><code>esphome run tesla-ble-esp32-s3.yml --device 192.168.20.44</code></td></tr>
</table>
<div class=sub>BLE-Key mit dem Tesla pairen (Schritt f&uuml;r Schritt)</div>
<p>N&ouml;tig einmalig bei Neuinstallation, Fahrzeugwechsel oder wenn der Schl&uuml;ssel im Auto gel&ouml;scht wurde. Dauer: ca. 2 Minuten.</p>
<table><tr><th></th><th>Schritt</th><th>Details</th></tr>
<tr><td>1</td><td><b>ESP platzieren</b></td><td>LoHaTes in BLE-Reichweite des Autos (&lt; 5 m, z. B. Garage) mit USB-Netzteil versorgen. Warten bis er im WLAN ist (diese Seite erreichbar).</td></tr>
<tr><td>2</td><td><b>Ins Auto setzen</b></td><td>NFC-Keycard mitnehmen. Am Handy diese Seite &ouml;ffnen &rarr; <a href="/geraete">Ger&auml;te-UI</a>.</td></tr>
<tr><td>3</td><td><b>&bdquo;Pair BLE key&ldquo; dr&uuml;cken</b></td><td>In der Ger&auml;te-UI den Button <b>Pair BLE key</b> dr&uuml;cken (unter Diagnose/Buttons).</td></tr>
<tr><td>4</td><td><b>Keycard auflegen</b></td><td>Sofort danach die NFC-Karte auf die Mittelkonsole legen (wo man sie zum Entriegeln hinh&auml;lt).</td></tr>
<tr><td>5</td><td><b>Best&auml;tigen</b></td><td>Popup am Auto-Bildschirm &bdquo;Handyschl&uuml;ssel-Kopplung angefordert&ldquo; &rarr; <b>Best&auml;tigen</b>. Kommt kein Popup: Schritt 3+4 wiederholen.</td></tr>
<tr><td>6</td><td><b>Pr&uuml;fen &amp; benennen</b></td><td>Auto: Steuerung &rarr; Schl&ouml;sser &rarr; neuer Schl&uuml;ssel &bdquo;Unknown device&ldquo; erscheint &rarr; in &bdquo;LoHaTes&ldquo; umbenennen.</td></tr>
<tr><td>7</td><td><b>Testen</b></td><td>Oben unter <a href="#live">Live</a> erscheinen Werte (SOC, anwesend=JA). Popup kommt sp&auml;ter nochmal? Einfach abbrechen &ndash; das ist eine alte, doppelte Anfrage.</td></tr></table>
<div class=note>Der Schl&uuml;ssel hat Rolle <b>DRIVER</b> &ndash; volle Kontrolle. Wer nur Laden steuern will, kann in der Firmware stattdessen <code>role: CHARGING_MANAGER</code> setzen (sicherer, aber kein Lock/Unlock).</div>
<div class="note warn">Unabh&auml;ngiges Open-Source-Projekt. Nicht verbunden mit Tesla, Inc., Loxone Electronics GmbH oder der Home Assistant / Open Home Foundation. Genannte Marken geh&ouml;ren ihren Eigent&uuml;mern.</div>
</div></div>

<footer>LoHaTes &middot; l&auml;uft lokal auf deinem ESP32 &middot; ohne Cloud</footer>
</main>
<script>
function g(id){return document.getElementById(id)}
function fmt(v,u,d){if(v===null||isNaN(v)||v<0&&u!=='dBm')return '\u2013';return v.toFixed(d)+' '+u}
async function upd(){
 try{
  const [soc,pwr,rssi,pres,slp,chg] = await Promise.all([
   fetch('/sensor/battery').then(r=>r.json()).catch(()=>null),
   fetch('/sensor/charger_power').then(r=>r.json()).catch(()=>null),
   fetch('/sensor/ble_signal').then(r=>r.json()).catch(()=>null),
   fetch('/binary_sensor/tesla_anwesend__ble_').then(r=>r.json()).catch(()=>null),
   fetch('/binary_sensor/asleep').then(r=>r.json()).catch(()=>null),
   fetch('/text_sensor/charging').then(r=>r.json()).catch(()=>null)
  ]);
  g('v_pres').innerHTML = pres&&pres.value?'<span class=ok>JA</span>':'<span class=muted>nein</span>';
  g('v_soc').textContent = soc?fmt(soc.value,'%',0):'\u2013';
  g('v_pwr').textContent = pwr?fmt(pwr.value,'kW',1):'\u2013';
  g('v_chg').textContent = chg&&chg.value?chg.value:'\u2013';
  g('v_slp').innerHTML = slp&&slp.value?'<span class=muted>schl\u00e4ft</span>':'<span class=ok>wach</span>';
  g('v_rssi').textContent = rssi&&rssi.value?Math.round(rssi.value)+' dBm':'\u2013';
 }catch(e){}
}
upd();setInterval(upd,10000);
document.querySelectorAll('#sectbl input[data-sw]').forEach(function(cb){
 var sw = cb.getAttribute('data-sw');
 fetch('/switch/'+sw).then(function(r){return r.json()}).then(function(j){cb.checked = !!j.value}).catch(function(){cb.disabled=true});
 cb.addEventListener('change', function(){
  fetch('/switch/'+sw+'/turn_'+(cb.checked?'on':'off'), {method:'POST'}).catch(function(){});
 });
});

</script>
</body></html>)LHTS";

static const char GERAETE_HTML[] = R"LHTS(<!doctype html><html lang=de><head><meta charset=utf-8>
<meta name=viewport content="width=device-width,initial-scale=1">
<title>LoHaTes &middot; Ger&auml;te-UI</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36;display:flex;flex-direction:column;height:100vh}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;
 display:flex;align-items:center;gap:1.3rem;flex-wrap:wrap;box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav{display:flex;gap:.3rem;flex-wrap:wrap}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
.jump{display:flex;align-items:center;gap:.25rem;flex-wrap:wrap;margin:.2rem 0 .9rem;
 font-size:.85rem;background:#fff;border:1px solid #e6e9ef;border-radius:10px;padding:.4rem .6rem}
.jump span{color:#8893a2;font-weight:700;margin-right:.3rem}
.jump a{color:#5a6675;text-decoration:none;padding:.25rem .6rem;border-radius:6px;font-weight:600}
.jump a:hover{background:#eef1f5;color:#e82127}
iframe{flex:1;border:0;width:100%}
</style></head><body>
<!--HEADER-->
<div style="background:#fff;border-bottom:1px solid #e6e9ef;padding:.45rem 1.3rem;font-size:.85rem;color:#6c7787">
Legende: <b style="color:#1c2531">&#9679;</b> gef&uuml;llter Kreis = AN / JA &nbsp;&middot;&nbsp; <b style="color:#aab2bd">&#9675;</b> leerer Kreis = AUS / NEIN &nbsp;&middot;&nbsp; &#9788; oben rechts = Hell-/Dunkel-Modus &nbsp;&middot;&nbsp; Werte in Meilen/&deg;F kommen direkt vom Auto</div>
<iframe src="/?embedded"></iframe>
</body></html>)LHTS";

static const char LOXONE_HTML_EN[] = R"LHTS(<!doctype html><html lang=en><head><meta charset=utf-8>
<meta name=viewport content="width=device-width,initial-scale=1">
<title>LoHaTes &middot; Setup</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;
 display:flex;align-items:center;gap:1.3rem;flex-wrap:wrap;position:sticky;top:0;z-index:9;
 box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav{display:flex;gap:.3rem;flex-wrap:wrap}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
.jump{display:flex;align-items:center;gap:.25rem;flex-wrap:wrap;margin:.2rem 0 .9rem;
 font-size:.85rem;background:#fff;border:1px solid #e6e9ef;border-radius:10px;padding:.4rem .6rem}
.jump span{color:#8893a2;font-weight:700;margin-right:.3rem}
.jump a{color:#5a6675;text-decoration:none;padding:.25rem .6rem;border-radius:6px;font-weight:600}
.jump a:hover{background:#eef1f5;color:#e82127}
main{max-width:1040px;margin:0 auto;padding:1.3rem}
h1{font-size:1.5rem;margin:.3rem 0 1.1rem;color:#1c2531}
.domain{background:#fff;border-radius:15px;box-shadow:0 2px 10px rgba(20,30,50,.07);
 margin:1.3rem 0;border:1px solid #e6e9ef;overflow:hidden}
.dh{display:flex;align-items:center;gap:.7rem;padding:.9rem 1.2rem;color:#fff}
.dh.lox{background:linear-gradient(90deg,#4ea339,#69c350)}
.dh.ha{background:linear-gradient(90deg,#1e9ad6,#41bdf5)}
.dh.tes{background:linear-gradient(90deg,#c11a20,#e82127)}
.dh.ki{background:linear-gradient(90deg,#1c2531,#3a4a5e)}
.dh h2{margin:0;font-size:1.2rem;font-weight:700}
.dbody{padding:1rem 1.2rem 1.2rem}
.sub{font-size:.9rem;color:#8893a2;font-weight:700;text-transform:uppercase;letter-spacing:.4px;
 margin:1.1rem 0 .5rem;border-left:3px solid #41bdf5;padding-left:.5rem}
.cards{display:grid;grid-template-columns:repeat(auto-fill,minmax(150px,1fr));gap:.6rem;margin:.4rem 0}
.card{background:#f7f9fc;border:1px solid #e6ebf1;border-radius:11px;padding:.65rem .85rem}
.card .n{font-size:.8rem;color:#6c7787}
.card .v{font-size:1.32rem;font-weight:650;margin-top:.15rem;color:#1c2531}
.ok{color:#0a8f4f}.bad{color:#d6202f}.muted{color:#aab2bd}
table{border-collapse:collapse;width:100%;font-size:.9rem;margin-top:.4rem;background:#fff}
th,td{border-bottom:1px solid #eceff3;padding:.45rem .6rem;text-align:left}
th{color:#7a8694;font-weight:600;background:#f7f9fc}
td code,p code,li code{background:#f3f4f7;color:#c2185b;font-weight:600;padding:.05rem .35rem;border-radius:4px}
pre{background:#1c2531;color:#8fd97a;padding:.7rem .9rem;border-radius:9px;overflow-x:auto;font-size:.85rem}
.note{background:#eef6ff;border:1px solid #cfe2f7;border-radius:11px;padding:.8rem 1.1rem;color:#2b5378;font-size:.92rem;margin:.7rem 0}
.note.ok{background:#eafaf1;border-color:#bce7cd;color:#1c6b3f}
.note.warn{background:#fff3e6;border-color:#f3cf9e;color:#8a5a1e}
p{line-height:1.6;color:#3a4554}
a{color:#1e9ad6}
footer{color:#9aa3af;font-size:.8rem;text-align:center;padding:1.6rem}
</style></head><body>
<!--HEADER--><main>

<div class=jump><span>Jump to:</span><a href="#live">Live</a><a href="#loxone">Loxone</a><a href="#ha">Home Assistant</a><a href="#ki">AI/MCP</a><a href="#sicherheit">Security</a><a href="#geraet">Device</a></div>
<h1 id=live>Live status</h1>
<div class=cards>
<div class=card><div class=n>Tesla present</div><div class=v id=v_pres>&hellip;</div></div>
<div class=card><div class=n>Battery</div><div class=v id=v_soc>&hellip;</div></div>
<div class=card><div class=n>Charging power</div><div class=v id=v_pwr>&hellip;</div></div>
<div class=card><div class=n>Charge state</div><div class=v id=v_chg>&hellip;</div></div>
<div class=card><div class=n>Asleep</div><div class=v id=v_slp>&hellip;</div></div>
<div class=card><div class=n>BLE signal</div><div class=v id=v_rssi>&hellip;</div></div>
</div>
<div class=note>Values refresh every 10 s. &ldquo;&ndash;&rdquo; = car asleep or value unknown yet. All entities and buttons: <a href="/geraete-en">Device UI</a>.</div>

<div class=domain id=loxone><div class="dh lox"><h2>Loxone setup</h2></div><div class=dbody>
<p>Communication via <b>UDP, port 7101</b>, both directions. Miniserver: <code>192.168.1.10</code>, LoHaTes: <code>192.168.20.44</code> / <code>lohates.lan</code>. Runs fully local &ndash; no cloud, no Home Assistant required.</p>
<div class=sub>1 &middot; Virtual UDP input (receive status)</div>
<p>Loxone Config &rarr; Virtual inputs &rarr; <b>Virtual UDP input</b>: receive port <code>7101</code>, sender address <code>192.168.20.44</code>. LoHaTes sends every 10 s:</p>
<pre>lohates:soc=72;pwr=7.4;amps=11;volt=232;range=310;asleep=0;plugged=1;charging=1;rssi=-67;present=1</pre>
<p>On arrival/departure additionally <b>immediately</b>: <code>lohates:present=1</code> / <code>lohates:present=0</code>. Create one <b>UDP input command</b> per value:</p>
<table><tr><th>Name</th><th>Command recognition</th><th>Type/unit</th><th>Note</th></tr>
<tr><td>Tesla SOC</td><td><code>soc=\v</code></td><td>Analog, %</td><td>-1 = unknown</td></tr>
<tr><td>Tesla charging power</td><td><code>pwr=\v</code></td><td>Analog, kW</td><td></td></tr>
<tr><td>Tesla charging current</td><td><code>amps=\v</code></td><td>Analog, A</td><td>actual current</td></tr>
<tr><td>Tesla voltage</td><td><code>volt=\v</code></td><td>Analog, V</td><td></td></tr>
<tr><td>Tesla range</td><td><code>range=\v</code></td><td>Analog, km</td><td></td></tr>
<tr><td>Tesla asleep</td><td><code>asleep=\v</code></td><td>Digital</td><td>1 = asleep</td></tr>
<tr><td>Tesla plugged in</td><td><code>plugged=\v</code></td><td>Digital</td><td>1 = cable connected</td></tr>
<tr><td>Tesla charging</td><td><code>charging=\v</code></td><td>Digital</td><td></td></tr>
<tr><td>Tesla BLE signal</td><td><code>rssi=\v</code></td><td>Analog, dBm</td><td>-50 good &hellip; -85 weak</td></tr>
<tr><td><b>Tesla present</b></td><td><code>present=\v</code></td><td>Digital</td><td>1 = in BLE range</td></tr></table>
<div class="note" style="margin-top:.8rem"><b>With radar module (optional):</b> additionally <code>lohates:zone1=1;zone2=0;zone3=0</code> arrives &ndash; three freely defined zones in front of the device, e.g. to open the door when somebody stands there. Create them as <b>analog</b> inputs (min 0 / max 1) using <code>zone1=\v</code>, <code>zone2=\v</code>, <code>zone3=\v</code>. Set up and calibrate under <a href="/radar">Radar</a>.</div>
<div class="note ok">Test: Loxone Config &rarr; open the UDP monitor &rarr; a packet arrives every 10 s.</div>
<div class=sub>2 &middot; Virtual output (send commands)</div>
<p>Virtual outputs &rarr; <b>Virtual output</b>, address: <code>/dev/udp/192.168.20.44/7101</code></p>
<table><tr><th>Name</th><th>Command on ON</th><th>Type</th></tr>
<tr><td>Wake Tesla</td><td><code>wake</code></td><td>Digital (pulse)</td></tr>
<tr><td>Charging start / stop</td><td><code>charge=1</code> / <code>charge=0</code></td><td>Digital</td></tr>
<tr><td>Set charging current</td><td><code>amps=&lt;v&gt;</code></td><td>Analog 1&ndash;16 A</td></tr>
<tr><td>Set charge limit</td><td><code>limit=&lt;v&gt;</code></td><td>Analog 50&ndash;100 %</td></tr>
<tr><td>Lock / unlock</td><td><code>lock</code> / <code>unlock</code></td><td>Digital &ndash; unlock requires permission checkbox</td></tr>
<tr><td>Open charge port</td><td><code>port_open</code></td><td>Digital</td></tr></table>
<div class=note>Commands wake the car automatically if needed. Analog commands are sent on every value change.</div>
<div class=sub>3 &middot; Garage door logic (presence)</div>
<table><tr><th>Step</th><th>Block chain</th></tr>
<tr><td>Debounce</td><td>VI present &rarr; switch-off delay 120 s &rarr; flag &ldquo;Tesla here&rdquo;</td></tr>
<tr><td>Was away long</td><td>&ldquo;Tesla here&rdquo; inverted &rarr; switch-on delay 10 min</td></tr>
<tr><td>Door OPEN</td><td>Edge &uarr; &ldquo;Tesla here&rdquo; AND &ldquo;was away long&rdquo; AND door closed &rarr; pulse OPEN</td></tr>
<tr><td>Door CLOSE</td><td>Edge &darr; &ldquo;Tesla here&rdquo; AND door open &rarr; delay 60&ndash;120 s &rarr; pulse CLOSE</td></tr></table>
<p>If the car sits in front of the open door (present=1), the logic never closes it &ndash; closing stays manual or via your own Loxone logic.</p>
<div class=sub>4 &middot; PV surplus charging</div>
<pre>Amps = PV surplus [W] / 690     (3-phase; single-phase: /230)
clamp to 6..16 A &rarr; VQ "amps=&lt;v&gt;"
surplus &gt; ~4.2 kW for a while &rarr; charge=1, otherwise charge=0
only if plugged=1; add hysteresis / minimum runtime 10&ndash;15 min</pre>
</div></div>

<div class=domain id=ha><div class="dh ha"><h2>Home Assistant setup</h2></div><div class=dbody>
<p>LoHaTes is a regular ESPHome device &ndash; HA discovers <b>all</b> entities automatically (more detail than the UDP push): SOC, charging, climate as thermostat, frunk/trunk, tire pressure, locks, wake button and more.</p>
<table><tr><th>Step</th><th>Action</th></tr>
<tr><td>1</td><td>HA &rarr; Settings &rarr; Devices &amp; services &rarr; <b>Add integration &rarr; ESPHome</b></td></tr>
<tr><td>2</td><td>Host: <code>192.168.20.44</code> &middot; Port: <code>6053</code></td></tr>
<tr><td>3</td><td>Enter the encryption key (see <code>secrets.yaml</code> of the project)</td></tr></table>
<div class="note ok">LoHaTes keeps running fine without HA &ndash; HA is display/statistics, control towards Loxone stays independent.</div>
<div class=sub>Dashboard card with logo</div>
<pre>type: picture-elements
image: http://lohates.lan/logo.svg
elements: []   # add your own badges/values</pre>
<p>Recommended split: <b>Loxone</b> = door &amp; charging (critical, local), <b>HA</b> = display, statistics, fun automations. TeslaMate may keep running for long-term stats (cloud, read-only anyway).</p>
</div></div>

<div class=domain id=ki><div class="dh ki"><h2>AI access (MCP)</h2></div><div class=dbody>
<p>LoHaTes has an AI interface based on the <a href="https://modelcontextprotocol.io">Model Context Protocol</a> &ndash; like HoxPi. AI assistants such as Claude can query the live Tesla status, diagnose issues and (if permitted) control charging.</p>
<table>
<tr><td>Server</td><td>runs on the HoxPi Pi: <code>http://hoval-pi.local:8809/mcp</code> (service <code>lohates-mcp</code>)</td></tr>
<tr><td>Tools</td><td><code>get_status</code>, <code>diagnose</code>, <code>get_all_entities</code>, <code>wake_vehicle</code>, <code>set_charging</code>, <code>set_charging_amps</code>, <code>set_charging_limit</code>, <code>open_charge_port</code>, <code>lock_vehicle</code>, <code>about</code></td></tr>
<tr><td>Safety</td><td>Writing only with <code>enable_write=true</code>; <b>unlocking</b> gated separately (<code>enable_unlock</code>, default off) plus the permission checkboxes below. Config: <code>/home/admin/lohates-mcp/config.json</code> on the Pi.</td></tr>
</table>
<div class=sub>Add to Claude Desktop</div>
<p>Claude Desktop &rarr; Settings &rarr; Developer &rarr; edit <code>claude_desktop_config.json</code> (requires Node.js):</p>
<pre>{
  "mcpServers": {
    "lohates": {
      "command": "npx",
      "args": ["-y", "mcp-remote", "http://hoval-pi.local:8809/mcp"]
    }
  }
}</pre>
<p>Restart Claude &ndash; then ask: <i>&ldquo;How is my Tesla doing?&rdquo;</i></p>
<div class=note>Service management on the Pi: <code>systemctl status/restart lohates-mcp</code> &middot; logs: <code>journalctl -u lohates-mcp -f</code></div>
</div></div>

<div class=domain id=sicherheit><div class="dh ki"><h2>Security &amp; permissions</h2></div><div class=dbody>
<p>Like HoxPi: <b>checkbox = command writable</b>. Applies to Loxone UDP <b>and</b> AI/MCP at the same time. Changes take effect immediately and survive reboots. Web UI and this page are login-protected (user <code>admin</code>, password in <code>secrets.yaml</code>).</p>
<table id=sectbl>
<tr><th>Permission</th><th>Effect</th><th>Allowed</th></tr>
<tr><td>Loxone status push</td><td>send UDP data to the Miniserver</td><td><input type=checkbox data-sw="loxone_status_push"></td></tr>
<tr><td>Loxone commands</td><td>accept UDP commands from the Miniserver (master switch)</td><td><input type=checkbox data-sw="loxone_befehle"></td></tr>
<tr><td>AI control</td><td>MCP server may control (master switch)</td><td><input type=checkbox data-sw="ki_steuern_erlaubt"></td></tr>
<tr><td>Radar zone push</td><td>send radar zone events to Loxone (only with LD2450)</td><td><input type=checkbox data-sw="radar_zone_push"></td></tr>
<tr><td><code>wake</code></td><td>wake the car</td><td><input type=checkbox data-sw="erlaubt_wake"></td></tr>
<tr><td><code>charge</code></td><td>charging start/stop</td><td><input type=checkbox data-sw="erlaubt_charge"></td></tr>
<tr><td><code>amps</code></td><td>set charging current</td><td><input type=checkbox data-sw="erlaubt_amps"></td></tr>
<tr><td><code>limit</code></td><td>set charge limit</td><td><input type=checkbox data-sw="erlaubt_limit"></td></tr>
<tr><td><code>lock</code></td><td>lock</td><td><input type=checkbox data-sw="erlaubt_lock"></td></tr>
<tr><td><code>unlock</code></td><td><b>unlock</b> (default: blocked!)</td><td><input type=checkbox data-sw="erlaubt_unlock"></td></tr>
<tr><td><code>port_open</code></td><td>open charge port</td><td><input type=checkbox data-sw="erlaubt_port_open"></td></tr>
</table>
<div class=sub>Change or recover the password</div>
<p>Easiest on the device itself: <a href="/passwort"><b>open the password page</b></a>.
The login password set there is stored permanently on the device and survives reboots.
Username stays <code>admin</code>.</p>
<p><b>Forgot it?</b> Three ways back &ndash; one always works:</p>
<table>
<tr><th>Way</th><th>How</th></tr>
<tr><td>Still logged in</td><td>Button &ldquo;reset to default&rdquo; on <a href="/passwort">/passwort</a></td></tr>
<tr><td>Physical</td><td><b>Hold the BOOT button for 10 seconds</b> &rarr; default from <code>secrets.yaml</code> applies again</td></tr>
<tr><td>Re-flash</td><td>Change <code>web_password</code> in <code>secrets.yaml</code> and flash &ndash; any custom password is discarded automatically</td></tr>
</table>
<p>The <b>OTA password</b> used for flashing is separate and also lives in
<code>secrets.yaml</code> (<code>ota_password</code>).</p>
<div class="note warn">Only enable unlocking if you really need it &ndash; anyone on the LAN with the password or Loxone access could trigger it.</div>
</div></div>

<div class=domain id=geraet><div class="dh tes"><h2>Tesla &amp; device</h2></div><div class=dbody>
<table>
<tr><td>Device</td><td>ESP32-S3 N16R8 &ldquo;LoHaTes&rdquo; &ndash; Tesla BLE bridge (based on yoziru/esphome-tesla-ble)</td></tr>
<tr><td>IP / domain</td><td><code>192.168.20.44</code> (static) &middot; <code>lohates.lan</code></td></tr>
<tr><td>Device UI</td><td><a href="/geraete-en">http://lohates.lan/geraete-en</a> (all entities, buttons, pairing)</td></tr>
<tr><td>Logo</td><td><a href="/logo.svg">/logo.svg</a> (for HA dashboards)</td></tr>
<tr><td>Does the car sleep?</td><td>VCSEC polling never wakes it; detailed polling only inside the wake window. Waking only on command.</td></tr>
<tr><td>BLE key</td><td>Paired as vehicle key (role DRIVER). Re-pair: Device UI &rarr; &ldquo;Pair BLE key&rdquo; + NFC card.</td></tr>
<tr><td>OTA update</td><td><code>esphome run tesla-ble-esp32-s3.yml --device 192.168.20.44</code></td></tr>
</table>
<div class=sub>Pair the BLE key with your Tesla (step by step)</div>
<p>Needed once for a new install, a different car, or if the key was removed in the car. Takes about 2 minutes.</p>
<table><tr><th></th><th>Step</th><th>Details</th></tr>
<tr><td>1</td><td><b>Place the ESP</b></td><td>LoHaTes within BLE range of the car (&lt; 5 m, e.g. garage) on a USB power supply. Wait until it joins WiFi (this page reachable).</td></tr>
<tr><td>2</td><td><b>Get into the car</b></td><td>Bring the NFC key card. Open this page on your phone &rarr; <a href="/geraete-en">Device UI</a>.</td></tr>
<tr><td>3</td><td><b>Press &ldquo;Pair BLE key&rdquo;</b></td><td>In the device UI press the <b>Pair BLE key</b> button.</td></tr>
<tr><td>4</td><td><b>Tap the key card</b></td><td>Immediately place the NFC card on the center console (where you unlock).</td></tr>
<tr><td>5</td><td><b>Confirm</b></td><td>Popup on the car screen &ldquo;phone key pairing requested&rdquo; &rarr; <b>Confirm</b>. No popup? Repeat steps 3+4.</td></tr>
<tr><td>6</td><td><b>Verify &amp; rename</b></td><td>Car: Controls &rarr; Locks &rarr; new key &ldquo;Unknown device&rdquo; appears &rarr; rename to &ldquo;LoHaTes&rdquo;.</td></tr>
<tr><td>7</td><td><b>Test</b></td><td>Values appear under <a href="#live">Live</a> (SOC, present=YES). Popup shows again later? Just cancel &ndash; it is an old duplicate request.</td></tr></table>
<div class=note>The key has role <b>DRIVER</b> &ndash; full control. If you only want charging control, set <code>role: CHARGING_MANAGER</code> in the firmware instead (safer, but no lock/unlock).</div>
<div class="note warn">Independent open-source project. Not affiliated with Tesla, Inc., Loxone Electronics GmbH or Home Assistant / the Open Home Foundation. Trademarks belong to their owners.</div>
</div></div>

<footer>LoHaTes &middot; runs locally on your ESP32 &middot; no cloud</footer>
</main>
<script>
function g(id){return document.getElementById(id)}
function fmt(v,u,d){if(v===null||isNaN(v)||v<0&&u!=='dBm')return '\u2013';return v.toFixed(d)+' '+u}
async function upd(){
 try{
  const [soc,pwr,rssi,pres,slp,chg] = await Promise.all([
   fetch('/sensor/battery').then(r=>r.json()).catch(()=>null),
   fetch('/sensor/charger_power').then(r=>r.json()).catch(()=>null),
   fetch('/sensor/ble_signal').then(r=>r.json()).catch(()=>null),
   fetch('/binary_sensor/tesla_anwesend__ble_').then(r=>r.json()).catch(()=>null),
   fetch('/binary_sensor/asleep').then(r=>r.json()).catch(()=>null),
   fetch('/text_sensor/charging').then(r=>r.json()).catch(()=>null)
  ]);
  g('v_pres').innerHTML = pres&&pres.value?'<span class=ok>YES</span>':'<span class=muted>no</span>';
  g('v_soc').textContent = soc?fmt(soc.value,'%',0):'\u2013';
  g('v_pwr').textContent = pwr?fmt(pwr.value,'kW',1):'\u2013';
  g('v_chg').textContent = chg&&chg.value?chg.value:'\u2013';
  g('v_slp').innerHTML = slp&&slp.value?'<span class=muted>asleep</span>':'<span class=ok>awake</span>';
  g('v_rssi').textContent = rssi&&rssi.value?Math.round(rssi.value)+' dBm':'\u2013';
 }catch(e){}
}
upd();setInterval(upd,10000);
document.querySelectorAll('#sectbl input[data-sw]').forEach(function(cb){
 var sw = cb.getAttribute('data-sw');
 fetch('/switch/'+sw).then(function(r){return r.json()}).then(function(j){cb.checked = !!j.value}).catch(function(){cb.disabled=true});
 cb.addEventListener('change', function(){
  fetch('/switch/'+sw+'/turn_'+(cb.checked?'on':'off'), {method:'POST'}).catch(function(){});
 });
});
</script>
</body></html>)LHTS";

static const char GERAETE_HTML_EN[] = R"LHTS(<!doctype html><html lang=en><head><meta charset=utf-8>
<meta name=viewport content="width=device-width,initial-scale=1">
<title>LoHaTes &middot; Device UI</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36;display:flex;flex-direction:column;height:100vh}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;
 display:flex;align-items:center;gap:1.3rem;flex-wrap:wrap;box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav{display:flex;gap:.3rem;flex-wrap:wrap}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
.jump{display:flex;align-items:center;gap:.25rem;flex-wrap:wrap;margin:.2rem 0 .9rem;
 font-size:.85rem;background:#fff;border:1px solid #e6e9ef;border-radius:10px;padding:.4rem .6rem}
.jump span{color:#8893a2;font-weight:700;margin-right:.3rem}
.jump a{color:#5a6675;text-decoration:none;padding:.25rem .6rem;border-radius:6px;font-weight:600}
.jump a:hover{background:#eef1f5;color:#e82127}
iframe{flex:1;border:0;width:100%}
</style></head><body>
<!--HEADER-->
<div style="background:#fff;border-bottom:1px solid #e6e9ef;padding:.45rem 1.3rem;font-size:.85rem;color:#6c7787">
Legend: <b style="color:#1c2531">&#9679;</b> filled circle = ON / YES &nbsp;&middot;&nbsp; <b style="color:#aab2bd">&#9675;</b> empty circle = OFF / NO &nbsp;&middot;&nbsp; &#9788; top right = light/dark mode &nbsp;&middot;&nbsp; miles/&deg;F values come straight from the car</div>
<iframe src="/?embedded"></iframe>
</body></html>)LHTS";

static const char LOGO_SVG[] = R"LHTS(<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 176 74" role="img" aria-label="LoHaTes">
  <path d="M14.75390625 24.1298828125H20.3935546875V41.7373046875H30.2958984375V46.0H14.75390625Z M41.943359375 32.9482421875Q40.2001953125 32.9482421875 39.28466796875 34.20068359375Q38.369140625 35.453125 38.369140625 37.8115234375Q38.369140625 40.169921875 39.28466796875 41.42236328125Q40.2001953125 42.6748046875 41.943359375 42.6748046875Q43.6572265625 42.6748046875 44.5654296875 41.42236328125Q45.4736328125 40.169921875 45.4736328125 37.8115234375Q45.4736328125 35.453125 44.5654296875 34.20068359375Q43.6572265625 32.9482421875 41.943359375 32.9482421875ZM41.943359375 29.1982421875Q46.1767578125 29.1982421875 48.55712890625 31.4833984375Q50.9375 33.7685546875 50.9375 37.8115234375Q50.9375 41.8544921875 48.55712890625 44.1396484375Q46.1767578125 46.4248046875 41.943359375 46.4248046875Q37.6953125 46.4248046875 35.30029296875 44.1396484375Q32.9052734375 41.8544921875 32.9052734375 37.8115234375Q32.9052734375 33.7685546875 35.30029296875 31.4833984375Q37.6953125 29.1982421875 41.943359375 29.1982421875Z" fill="#69c350"/>
  <path d="M55.48046875 24.1298828125H61.1201171875V32.46484375H69.4404296875V24.1298828125H75.080078125V46.0H69.4404296875V36.7275390625H61.1201171875V46.0H55.48046875Z M88.20703125 38.6171875Q86.56640625 38.6171875 85.73876953125 39.173828125Q84.9111328125 39.73046875 84.9111328125 40.814453125Q84.9111328125 41.810546875 85.57763671875 42.37451171875Q86.244140625 42.9384765625 87.4306640625 42.9384765625Q88.91015625 42.9384765625 89.9208984375 41.87646484375Q90.931640625 40.814453125 90.931640625 39.2177734375V38.6171875ZM96.2197265625 36.6396484375V46.0H90.931640625V43.568359375Q89.876953125 45.0625 88.55859375 45.74365234375Q87.240234375 46.4248046875 85.3505859375 46.4248046875Q82.8017578125 46.4248046875 81.21240234375 44.93798828125Q79.623046875 43.451171875 79.623046875 41.078125Q79.623046875 38.1923828125 81.60791015625 36.8447265625Q83.5927734375 35.4970703125 87.8408203125 35.4970703125H90.931640625V35.0869140625Q90.931640625 33.841796875 89.9501953125 33.26318359375Q88.96875 32.6845703125 86.888671875 32.6845703125Q85.2041015625 32.6845703125 83.75390625 33.021484375Q82.3037109375 33.3583984375 81.05859375 34.0322265625V30.033203125Q82.7431640625 29.623046875 84.4423828125 29.41064453125Q86.1416015625 29.1982421875 87.8408203125 29.1982421875Q92.279296875 29.1982421875 94.24951171875 30.94873046875Q96.2197265625 32.69921875 96.2197265625 36.6396484375Z" fill="#41bdf5"/>
  <g transform="translate(101.6,16)">
    <path d="M0,4 Q14,-3 28,4 L26.2,9.5 Q14,3.5 1.8,9.5 Z" fill="#e82127"/>
    <path d="M9.5,11 L18.5,11 L16,24 L14,34 L12,24 Z" fill="#e82127"/>
  </g>
  <path d="M141.974609375 37.7529296875V39.2470703125H129.7138671875Q129.904296875 41.0927734375 131.046875 42.015625Q132.189453125 42.9384765625 134.240234375 42.9384765625Q135.8955078125 42.9384765625 137.63134765625 42.44775390625Q139.3671875 41.95703125 141.1982421875 40.9609375V45.00390625Q139.337890625 45.70703125 137.4775390625 46.06591796875Q135.6171875 46.4248046875 133.7568359375 46.4248046875Q129.3037109375 46.4248046875 126.83544921875 44.16162109375Q124.3671875 41.8984375 124.3671875 37.8115234375Q124.3671875 33.7978515625 126.79150390625 31.498046875Q129.2158203125 29.1982421875 133.4638671875 29.1982421875Q137.3310546875 29.1982421875 139.65283203125 31.52734375Q141.974609375 33.8564453125 141.974609375 37.7529296875ZM136.583984375 36.009765625Q136.583984375 34.515625 135.71240234375 33.60009765625Q134.8408203125 32.6845703125 133.4345703125 32.6845703125Q131.9111328125 32.6845703125 130.958984375 33.54150390625Q130.0068359375 34.3984375 129.7724609375 36.009765625Z M159.26171875 30.1064453125V34.0908203125Q157.5771484375 33.3876953125 156.009765625 33.0361328125Q154.4423828125 32.6845703125 153.05078125 32.6845703125Q151.556640625 32.6845703125 150.83154296875 33.05810546875Q150.1064453125 33.431640625 150.1064453125 34.2080078125Q150.1064453125 34.837890625 150.65576171875 35.1748046875Q151.205078125 35.51171875 152.6259765625 35.6728515625L153.548828125 35.8046875Q157.5771484375 36.3173828125 158.96875 37.4892578125Q160.3603515625 38.6611328125 160.3603515625 41.166015625Q160.3603515625 43.7880859375 158.4267578125 45.1064453125Q156.4931640625 46.4248046875 152.6552734375 46.4248046875Q151.029296875 46.4248046875 149.29345703125 46.16845703125Q147.5576171875 45.912109375 145.7265625 45.3994140625V41.4150390625Q147.2939453125 42.1767578125 148.94189453125 42.5576171875Q150.58984375 42.9384765625 152.2890625 42.9384765625Q153.8271484375 42.9384765625 154.603515625 42.513671875Q155.3798828125 42.0888671875 155.3798828125 41.25390625Q155.3798828125 40.55078125 154.84521484375 40.20654296875Q154.310546875 39.8623046875 152.7138671875 39.671875L151.791015625 39.5546875Q148.2900390625 39.115234375 146.8837890625 37.9287109375Q145.4775390625 36.7421875 145.4775390625 34.3251953125Q145.4775390625 31.7177734375 147.2646484375 30.4580078125Q149.0517578125 29.1982421875 152.7431640625 29.1982421875Q154.193359375 29.1982421875 155.7900390625 29.41796875Q157.38671875 29.6376953125 159.26171875 30.1064453125Z" fill="#e82127"/>
  <rect x="12.0" y="56" width="40.2" height="4" rx="2" fill="#69c350"/>
  <rect x="52.7" y="56" width="45.9" height="4" rx="2" fill="#41bdf5"/>
  <rect x="101.6" y="56" width="56.2" height="4" rx="2" fill="#e82127"/>
</svg>)LHTS";

static const char RADAR_HTML[] = R"RAD(<!doctype html><html lang=de><head><meta charset=utf-8>
<meta name=viewport content="width=device-width,initial-scale=1">
<title>LoHaTes &middot; Radar-Zonen</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;display:flex;
 align-items:center;gap:1.3rem;flex-wrap:wrap;position:sticky;top:0;z-index:9;box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav{display:flex;gap:.3rem;flex-wrap:wrap}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
.jump{display:flex;align-items:center;gap:.25rem;flex-wrap:wrap;margin:.2rem 0 .9rem;
 font-size:.85rem;background:#fff;border:1px solid #e6e9ef;border-radius:10px;padding:.4rem .6rem}
.jump span{color:#8893a2;font-weight:700;margin-right:.3rem}
.jump a{color:#5a6675;text-decoration:none;padding:.25rem .6rem;border-radius:6px;font-weight:600}
.jump a:hover{background:#eef1f5;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
main{max-width:1040px;margin:0 auto;padding:1.1rem}
h1{font-size:1.35rem;margin:.2rem 0 1rem;color:#1c2531}
.card{background:#fff;border-radius:15px;box-shadow:0 2px 10px rgba(20,30,50,.07);margin:1rem 0;border:1px solid #e6e9ef;overflow:hidden}
.ch{padding:.8rem 1.1rem;color:#fff;background:linear-gradient(90deg,#4ea339,#69c350)}
.ch h2{margin:0;font-size:1.1rem}
.cb{padding:1rem 1.1rem 1.2rem}
canvas{width:100%;height:auto;display:block;border-radius:10px;background:#f7f9fb;border:1px solid #e2e6ec;touch-action:none;cursor:crosshair}
.badges{display:flex;gap:.5rem;flex-wrap:wrap;margin:.8rem 0 0}
.bg{background:#f3f4f7;border-radius:20px;padding:.3rem .8rem;font-size:.85rem;font-weight:600;color:#4a5563}
.bg b{color:#1c2531}
.bg.ok{background:#e6f7ea;color:#1c6b3f}.bg.no{background:#fdeceb;color:#a02020}
.tabs{display:flex;gap:.4rem;flex-wrap:wrap;margin-bottom:.9rem}
.tab{padding:.5rem 1rem;border-radius:9px;font-weight:700;font-size:.92rem;cursor:pointer;border:2px solid transparent;background:#f3f4f7;color:#5a6675}
.tab.on{color:#fff}
.tab.on.z1{background:#69c350;border-color:#4ea339}
.tab.on.z2{background:#41bdf5;border-color:#1e9ad6}
.tab.on.z3{background:#f0930b;border-color:#c97907}
.row{display:flex;gap:.6rem;flex-wrap:wrap;align-items:flex-end;margin:.7rem 0}
label{display:block;font-size:.78rem;color:#7a8694;font-weight:600;margin-bottom:.2rem}
input[type=number],input[type=text],select{padding:.45rem .6rem;border:1px solid #cfd6de;border-radius:8px;font-size:.95rem;width:110px;font-family:inherit}
button{padding:.55rem 1rem;border:0;border-radius:9px;font-size:.92rem;font-weight:700;cursor:pointer;font-family:inherit}
.p{background:#69c350;color:#fff}.p:hover{background:#5bb043}
.s{background:#1c2531;color:#fff}.s:hover{background:#2c3a4d}
.d{background:#f3f4f7;color:#5a6675}.d:hover{background:#e6e9ef}
.big{background:#e82127;color:#fff;font-size:1rem;padding:.8rem 1.3rem;width:100%}
.big:hover{background:#c8161c}
.note{background:#fff8e6;border:1px solid #e0c886;border-radius:10px;padding:.7rem .9rem;font-size:.87rem;color:#7a5b13;margin:.8rem 0}
.note.i{background:#eef4ff;border-color:#c9d8f0;color:#2b4470}
ol{margin:.4rem 0 0;padding-left:1.2rem;font-size:.9rem;line-height:1.6}
table{border-collapse:collapse;width:100%;font-size:.87rem;margin-top:.5rem}
th,td{border:1px solid #e2e5ea;padding:.4rem .55rem;text-align:left}
th{background:#1c2531;color:#fff;font-size:.8rem}
code{background:#f3f4f7;color:#c2185b;padding:.05rem .35rem;border-radius:4px;font-weight:600}
#toast{position:fixed;left:50%;transform:translateX(-50%);bottom:22px;background:#1c2531;color:#fff;
 padding:.6rem 1.1rem;border-radius:9px;font-size:.9rem;opacity:0;transition:.25s;pointer-events:none;z-index:20}
#toast.show{opacity:1}
</style></head><body>
<!--HEADER-->
<main>
<h1>Radar-Zonen einrichten</h1>

<div class=card><div class=ch><h2>Live-Ansicht (Draufsicht von oben)</h2></div><div class=cb>
<canvas id=cv width=1400 height=1000></canvas>
<div class=badges>
 <span class=bg id=bMode>Modus: &ndash;</span>
 <span class=bg id=bTot>Ziele: <b>0</b></span>
 <span class=bg id=bZ1>Zone 1: &ndash;</span>
 <span class=bg id=bZ2>Zone 2: &ndash;</span>
 <span class=bg id=bZ3>Zone 3: &ndash;</span>
 <span class=bg id=bT1>T1: &ndash;</span>
</div>
<div class=row>
 <div><label>Sichtbare Tiefe</label>
 <select id=depth><option value=3000>3 m</option><option value=4500 selected>4,5 m</option><option value=6000>6 m</option><option value=7560>7,5 m</option></select></div>
 <button class=d id=btnTrail>Spur l&ouml;schen</button>
 <button class=s id=btnDet>Zonen-Modus: Detection</button>
</div>
<div class="note i">Der Sensor sitzt oben in der Mitte (rot), nach unten geht es von der Wand weg.
W&auml;hle unten eine Zone und zieh mit Maus oder Finger ein Rechteck auf die Karte.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#1e9ad6,#41bdf5)"><h2>Zone bearbeiten</h2></div><div class=cb>
<div class=tabs>
 <div class="tab z1 on" data-z=0>Zone 1</div>
 <div class="tab z2" data-z=1>Zone 2</div>
 <div class="tab z3" data-z=2>Zone 3</div>
</div>
<button class=big id=btnHere>Ich stehe JETZT hier &rarr; Zone drumherum legen</button>
<div class=row>
 <div><label>Radius um mich (mm)</label><input type=number id=margin value=500 step=50 min=100 max=3000></div>
</div>
<div class=row>
 <div><label>X1 (links, mm)</label><input type=number id=x1 step=10></div>
 <div><label>Y1 (nah, mm)</label><input type=number id=y1 step=10></div>
 <div><label>X2 (rechts, mm)</label><input type=number id=x2 step=10></div>
 <div><label>Y2 (fern, mm)</label><input type=number id=y2 step=10></div>
</div>
<div class=row>
 <button class=p id=btnSave>Zone speichern</button>
 <button class=d id=btnClear>Diese Zone l&ouml;schen</button>
</div>
<div class=note><b>Wichtig:</b> Zonen wirken erst, wenn der Zonen-Modus auf <b>Detection</b> steht (Knopf oben).
Gespeichert wird im Radar-Modul selbst &ndash; bleibt also auch nach Stromausfall erhalten.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#c11a20,#e82127)"><h2>Was Loxone bekommt</h2></div><div class=cb>
<p style="margin:.2rem 0;font-size:.93rem">Steht jemand <b>3 Sekunden</b> in einer Zone, geht per UDP
(Port 7101) an den Miniserver:</p>
<p style="margin:.5rem 0"><code>lohates:zone1=1;zone2=0;zone3=0</code></p>
<table>
<tr><th>Zone</th><th>Befehlserkennung im Virtuellen Eingang</th><th>Idee</th></tr>
<tr><td>Zone 1</td><td><code>zone1=\v</code></td><td>Garagentor auf</td></tr>
<tr><td>Zone 2</td><td><code>zone2=\v</code></td><td>Aussenlicht an</td></tr>
<tr><td>Zone 3</td><td><code>zone3=\v</code></td><td>frei</td></tr>
</table>
<div class="note i" style="margin-top:.8rem">Als <b>Analog</b>-Eingang anlegen (Min 0 / Max 1), nicht digital &ndash;
sonst klemmt die Wertebereichspr&uuml;fung alles auf 0. Der Status wird zus&auml;tzlich alle 10 s
wiederholt, damit sich ein verlorenes Paket selbst heilt.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#1c2531,#3a4a5e)"><h2>So kalibrierst du</h2></div><div class=cb>
<ol>
<li>Diese Seite am <b>Handy</b> &ouml;ffnen und nach drau&szlig;en gehen.</li>
<li>Zone ausw&auml;hlen, an die gew&uuml;nschte Stelle stellen, kurz <b>ruhig stehen bleiben</b>.</li>
<li><b>&bdquo;Ich stehe JETZT hier&ldquo;</b> dr&uuml;cken &ndash; die Zone legt sich um dich.</li>
<li><b>Detection</b> aktivieren.</li>
<li>Test: <b>vorbeigehen</b> darf nicht ausl&ouml;sen, <b>3 s stehen</b> soll ausl&ouml;sen (Anzeige wird gr&uuml;n).</li>
</ol>
<div class="note i" style="margin-top:.9rem">Zu gro&szlig;e Zone &rarr; l&ouml;st beim Vorbeigehen aus.
Zu klein &rarr; man muss zu genau treffen. <b>50&ndash;70 cm Radius</b> ist ein guter Start.
Zonen sollten sich <b>nicht &uuml;berlappen</b>.</div>
</div></div>
</main>
<div id=toast></div>
<script>
var cv=document.getElementById('cv'),ctx=cv.getContext('2d'),W=1400,H=1000;
var XR=4860,YR=7560;
var view={xMin:-3000,xMax:3000,yMin:0,yMax:4500};
var COL=['#69c350','#41bdf5','#f0930b'],COLD=['#3d7f2c','#1a7fb0','#a86505'];
var T=[{x:null,y:null},{x:null,y:null},{x:null,y:null}];
var Z=[{x1:0,y1:0,x2:0,y2:0},{x1:0,y1:0,x2:0,y2:0},{x1:0,y1:0,x2:0,y2:0}];
var S={tot:0,cnt:[0,0,0],occ:[false,false,false],mode:'-'};
var act=0,trail=[],drag=null,editing=false;
var I={x1:document.getElementById('x1'),y1:document.getElementById('y1'),x2:document.getElementById('x2'),y2:document.getElementById('y2')};

function toast(m){var t=document.getElementById('toast');t.textContent=m;t.className='show';setTimeout(function(){t.className=''},2200)}
function sx(x){return (x-view.xMin)/(view.xMax-view.xMin)*W}
function sy(y){return (y-view.yMin)/(view.yMax-view.yMin)*H}
function wx(px){return view.xMin+px/W*(view.xMax-view.xMin)}
function wy(py){return view.yMin+py/H*(view.yMax-view.yMin)}
function cl(v,a,b){return Math.max(a,Math.min(b,v))}
function norm(z){return{x1:Math.min(z.x1,z.x2),x2:Math.max(z.x1,z.x2),y1:Math.min(z.y1,z.y2),y2:Math.max(z.y1,z.y2)}}
function valid(z){var n=norm(z);return (n.x2-n.x1)>1&&(n.y2-n.y1)>1}

function draw(){
 ctx.clearRect(0,0,W,H);ctx.fillStyle='#f7f9fb';ctx.fillRect(0,0,W,H);
 ctx.lineWidth=1;ctx.font='22px Segoe UI';
 for(var gx=Math.ceil(view.xMin/500)*500;gx<=view.xMax;gx+=500){
  var m=(gx%1000===0);ctx.strokeStyle=m?'#d2dae3':'#e9edf2';
  ctx.beginPath();ctx.moveTo(sx(gx),0);ctx.lineTo(sx(gx),H);ctx.stroke();
  if(m&&gx!==0){ctx.fillStyle='#9aa5b1';ctx.fillText((gx/1000)+'m',sx(gx)+5,H-10)}}
 for(var gy=0;gy<=view.yMax;gy+=500){
  var m2=(gy%1000===0);ctx.strokeStyle=m2?'#d2dae3':'#e9edf2';
  ctx.beginPath();ctx.moveTo(0,sy(gy));ctx.lineTo(W,sy(gy));ctx.stroke();
  if(m2&&gy>0){ctx.fillStyle='#9aa5b1';ctx.fillText((gy/1000)+'m',8,sy(gy)-8)}}
 ctx.strokeStyle='#c9d3dd';ctx.setLineDash([10,10]);ctx.lineWidth=2;
 [-60,60].forEach(function(a){var r=a*Math.PI/180;
  ctx.beginPath();ctx.moveTo(sx(0),sy(0));ctx.lineTo(sx(Math.sin(r)*YR),sy(Math.cos(r)*YR));ctx.stroke()});
 ctx.setLineDash([]);
 Z.forEach(function(z,i){if(!valid(z))return;var n=norm(z);
  ctx.fillStyle=COL[i]+'2e';ctx.strokeStyle=COL[i];ctx.lineWidth=(i===act)?6:3;
  ctx.fillRect(sx(n.x1),sy(n.y1),sx(n.x2)-sx(n.x1),sy(n.y2)-sy(n.y1));
  ctx.strokeRect(sx(n.x1),sy(n.y1),sx(n.x2)-sx(n.x1),sy(n.y2)-sy(n.y1));
  ctx.fillStyle=COLD[i];ctx.font='bold 24px Segoe UI';
  ctx.fillText('ZONE '+(i+1)+(S.occ[i]?'  *':''),sx(n.x1)+10,sy(n.y1)+30)});
 if(drag){ctx.strokeStyle=COL[act];ctx.lineWidth=5;ctx.setLineDash([12,8]);
  ctx.strokeRect(drag.px1,drag.py1,drag.px2-drag.px1,drag.py2-drag.py1);ctx.setLineDash([])}
 var now=Date.now();
 trail.forEach(function(p){var a=1-(now-p.t)/12000;if(a<=0)return;
  ctx.fillStyle='rgba(120,132,148,'+(a*0.45)+')';
  ctx.beginPath();ctx.arc(sx(p.x),sy(p.y),7,0,6.284);ctx.fill()});
 T.forEach(function(t,i){if(t.x===null||t.y===null||(t.x===0&&t.y===0))return;
  var inz=-1;Z.forEach(function(z,k){if(!valid(z))return;var n=norm(z);
   if(t.x>=n.x1&&t.x<=n.x2&&t.y>=n.y1&&t.y<=n.y2)inz=k});
  ctx.fillStyle=inz>=0?COL[inz]:'#5a6675';ctx.strokeStyle='#fff';ctx.lineWidth=4;
  ctx.beginPath();ctx.arc(sx(t.x),sy(t.y),18,0,6.284);ctx.fill();ctx.stroke();
  ctx.fillStyle='#1c2531';ctx.font='bold 24px Segoe UI';
  ctx.fillText('T'+(i+1)+'  '+Math.round(t.x)+' / '+Math.round(t.y),sx(t.x)+26,sy(t.y)-14)});
 ctx.fillStyle='#e82127';ctx.beginPath();
 ctx.moveTo(sx(0),sy(0)-4);ctx.lineTo(sx(0)-22,sy(0)-40);ctx.lineTo(sx(0)+22,sy(0)-40);ctx.closePath();ctx.fill();
 ctx.fillRect(sx(0)-60,sy(0)-52,120,14);
 ctx.fillStyle='#8a3033';ctx.font='bold 22px Segoe UI';ctx.fillText('LoHaTes',sx(0)-48,sy(0)-58);
}
function tick(){draw();requestAnimationFrame(tick)}
requestAnimationFrame(tick);

function pos(e){var r=cv.getBoundingClientRect();
 var cx=(e.touches?e.touches[0].clientX:e.clientX)-r.left;
 var cy=(e.touches?e.touches[0].clientY:e.clientY)-r.top;
 return{px:cx/r.width*W,py:cy/r.height*H}}
function dStart(e){e.preventDefault();var p=pos(e);drag={px1:p.px,py1:p.py,px2:p.px,py2:p.py}}
function dMove(e){if(!drag)return;e.preventDefault();var p=pos(e);drag.px2=p.px;drag.py2=p.py}
function dEnd(e){if(!drag)return;e.preventDefault();
 var a=wx(Math.min(drag.px1,drag.px2)),b=wx(Math.max(drag.px1,drag.px2));
 var c=wy(Math.min(drag.py1,drag.py2)),d=wy(Math.max(drag.py1,drag.py2));
 drag=null;
 if(Math.abs(b-a)<150||Math.abs(d-c)<150){toast('Rechteck zu klein');return}
 Z[act]={x1:Math.round(cl(a,-XR,XR)),x2:Math.round(cl(b,-XR,XR)),
         y1:Math.round(cl(c,0,YR)),y2:Math.round(cl(d,0,YR))};
 fill();toast('Zone '+(act+1)+' gezeichnet - noch speichern!')}
cv.addEventListener('mousedown',dStart);cv.addEventListener('mousemove',dMove);
window.addEventListener('mouseup',dEnd);
cv.addEventListener('touchstart',dStart,{passive:false});cv.addEventListener('touchmove',dMove,{passive:false});
cv.addEventListener('touchend',dEnd,{passive:false});

function fill(){var z=Z[act];I.x1.value=z.x1;I.y1.value=z.y1;I.x2.value=z.x2;I.y2.value=z.y2}
['x1','y1','x2','y2'].forEach(function(k){
 I[k].addEventListener('focus',function(){editing=true});
 I[k].addEventListener('change',function(){Z[act][k]=+I[k].value||0;editing=false})});
Array.prototype.forEach.call(document.querySelectorAll('.tab'),function(t){
 t.onclick=function(){act=+t.getAttribute('data-z');
  Array.prototype.forEach.call(document.querySelectorAll('.tab'),function(o){o.classList.remove('on')});
  t.classList.add('on');fill()}});

function setNum(o,v){return fetch('/number/'+o+'/set?value='+Math.round(v),{method:'POST'})}
function saveActive(){var n=norm(Z[act]),p='zone_'+(act+1)+'_';
 return Promise.all([setNum(p+'x1',n.x1),setNum(p+'y1',n.y1),setNum(p+'x2',n.x2),setNum(p+'y2',n.y2)])}
document.getElementById('btnSave').onclick=function(){
 Z[act]={x1:+I.x1.value||0,y1:+I.y1.value||0,x2:+I.x2.value||0,y2:+I.y2.value||0};
 saveActive().then(function(){toast('Zone '+(act+1)+' gespeichert')}).catch(function(){toast('Fehler beim Speichern')})};
document.getElementById('btnDet').onclick=function(){
 fetch('/select/radar_zonen-modus/set?option=Detection',{method:'POST'}).then(function(){toast('Detection aktiv')})};
document.getElementById('btnClear').onclick=function(){
 Z[act]={x1:0,y1:0,x2:0,y2:0};fill();
 saveActive().then(function(){toast('Zone '+(act+1)+' geloescht')})};
document.getElementById('btnHere').onclick=function(){
 if(T[0].x===null||(T[0].x===0&&T[0].y===0)){toast('Kein Ziel erkannt - kurz bewegen');return}
 var m=+document.getElementById('margin').value||500;
 Z[act]={x1:Math.round(cl(T[0].x-m,-XR,XR)),x2:Math.round(cl(T[0].x+m,-XR,XR)),
         y1:Math.round(cl(T[0].y-m,0,YR)),y2:Math.round(cl(T[0].y+m,0,YR))};
 fill();saveActive().then(function(){toast('Zone '+(act+1)+' um dich gesetzt und gespeichert')})};
document.getElementById('btnTrail').onclick=function(){trail=[]};
document.getElementById('depth').onchange=function(){view.yMax=+this.value;
 var half=+this.value*0.75;view.xMin=-half;view.xMax=half};

function badge(){
 document.getElementById('bTot').innerHTML='Ziele: <b>'+S.tot+'</b>';
 for(var i=0;i<3;i++){var e=document.getElementById('bZ'+(i+1));
  e.textContent='Zone '+(i+1)+': '+(S.occ[i]?'BESETZT':S.cnt[i]+' Ziele');
  e.className='bg '+(S.occ[i]?'ok':'')}
 var m=document.getElementById('bMode');
 m.textContent='Modus: '+S.mode;m.className='bg '+(S.mode==='Detection'?'ok':'no');
 document.getElementById('bT1').textContent='T1: '+(T[0].x===null?'-':Math.round(T[0].x)+' / '+Math.round(T[0].y)+' mm');
}
function push(){if(T[0].x===null||T[0].y===null)return;if(T[0].x===0&&T[0].y===0)return;
 trail.push({x:T[0].x,y:T[0].y,t:Date.now()});if(trail.length>150)trail.shift()}

var NM={};
[1,2,3].forEach(function(z){['x1','y1','x2','y2'].forEach(function(k){
 NM['number-zone_'+z+'_'+k]={z:z-1,k:k}})});

var es=new EventSource('/events');
es.addEventListener('state',function(e){var d;try{d=JSON.parse(e.data)}catch(_){return}
 var id=d.id||'';
 if(id==='sensor-radar_ziel_1_x'){T[0].x=d.value}
 else if(id==='sensor-radar_ziel_1_y'){T[0].y=d.value;push()}
 else if(id==='sensor-radar_ziel_2_x'){T[1].x=d.value}
 else if(id==='sensor-radar_ziel_2_y'){T[1].y=d.value}
 else if(id==='sensor-radar_ziel_3_x'){T[2].x=d.value}
 else if(id==='sensor-radar_ziel_3_y'){T[2].y=d.value}
 else if(id==='sensor-radar_ziele_gesamt'){S.tot=d.value}
 else if(id==='sensor-radar_zone_1_ziele'){S.cnt[0]=d.value}
 else if(id==='sensor-radar_zone_2_ziele'){S.cnt[1]=d.value}
 else if(id==='sensor-radar_zone_3_ziele'){S.cnt[2]=d.value}
 else if(id==='binary_sensor-radar__zone_1_besetzt'){S.occ[0]=!!d.value}
 else if(id==='binary_sensor-radar__zone_2_besetzt'){S.occ[1]=!!d.value}
 else if(id==='binary_sensor-radar__zone_3_besetzt'){S.occ[2]=!!d.value}
 else if(id==='select-radar_zonen-modus'){S.mode=d.value}
 else if(NM[id]){var t=NM[id];Z[t.z][t.k]=+d.value;
  if(!editing&&t.z===act)fill()}
 else return;
 badge()});
badge();
</script></body></html>)RAD";

static const char PW_HTML[] = R"PWD(<!doctype html><html lang=de><head><meta charset=utf-8>
<meta name=viewport content="width=device-width,initial-scale=1">
<title>LoHaTes &middot; Passwort</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;display:flex;
 align-items:center;gap:1.3rem;flex-wrap:wrap;box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
.jump{display:flex;align-items:center;gap:.25rem;flex-wrap:wrap;margin:.2rem 0 .9rem;
 font-size:.85rem;background:#fff;border:1px solid #e6e9ef;border-radius:10px;padding:.4rem .6rem}
.jump span{color:#8893a2;font-weight:700;margin-right:.3rem}
.jump a{color:#5a6675;text-decoration:none;padding:.25rem .6rem;border-radius:6px;font-weight:600}
.jump a:hover{background:#eef1f5;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
main{max-width:720px;margin:0 auto;padding:1.1rem}
h1{font-size:1.35rem;margin:.2rem 0 1rem;color:#1c2531}
.card{background:#fff;border-radius:15px;box-shadow:0 2px 10px rgba(20,30,50,.07);margin:1rem 0;border:1px solid #e6e9ef;overflow:hidden}
.ch{padding:.8rem 1.1rem;color:#fff;background:linear-gradient(90deg,#1c2531,#3a4a5e)}
.ch h2{margin:0;font-size:1.1rem}
.cb{padding:1rem 1.1rem 1.2rem}
label{display:block;font-size:.8rem;color:#7a8694;font-weight:600;margin:.7rem 0 .2rem}
input{padding:.55rem .7rem;border:1px solid #cfd6de;border-radius:8px;font-size:1rem;width:100%;font-family:inherit}
button{padding:.65rem 1.1rem;border:0;border-radius:9px;font-size:.95rem;font-weight:700;cursor:pointer;font-family:inherit;margin-top:.9rem}
.p{background:#69c350;color:#fff}.p:hover{background:#5bb043}
.w{background:#e8a020;color:#fff}.w:hover{background:#cf8c15}
.note{background:#fff8e6;border:1px solid #e0c886;border-radius:10px;padding:.7rem .9rem;font-size:.88rem;color:#7a5b13;margin:.9rem 0}
.note.i{background:#eef4ff;border-color:#c9d8f0;color:#2b4470}
.note.g{background:#eafaf1;border-color:#bce7cd;color:#1c6b3f}
ol{margin:.4rem 0 0;padding-left:1.2rem;font-size:.9rem;line-height:1.7}
code{background:#f3f4f7;color:#c2185b;padding:.05rem .35rem;border-radius:4px;font-weight:600}
#msg{margin-top:.8rem;font-size:.92rem;font-weight:600}
</style></head><body>
<!--HEADER-->
<main>
<h1>Web-Passwort</h1>

<div class="note" style="margin:0 0 1rem"><b>Werkseinstellung:</b> Benutzer <code>admin</code>,
Passwort <code>12345678</code>. Das ist bei jedem neuen Ger&auml;t gleich und steht so auch in der
Anleitung &ndash; also bitte gleich hier unten &auml;ndern.</div>

<div class=card><div class=ch><h2>Passwort &auml;ndern</h2></div><div class=cb>
<label for=pw1>Neues Passwort (8&ndash;32 Zeichen)</label>
<input type=password id=pw1 autocomplete=new-password>
<label for=pw2>Zur Sicherheit nochmal</label>
<input type=password id=pw2 autocomplete=new-password>
<button class=p id=btnSave>Passwort speichern</button>
<div id=msg></div>
<div class="note i">Benutzername bleibt <code>admin</code>. Nach dem Speichern fragt der Browser
gleich wieder nach dem Login &ndash; dann das <b>neue</b> Passwort eingeben.
Es wird dauerhaft im Ger&auml;t gespeichert und &uuml;berlebt Neustarts.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#c98a12,#e8a020)"><h2>Passwort vergessen?</h2></div><div class=cb>
<p style="margin:.2rem 0 .6rem;font-size:.95rem">Es gibt <b>drei</b> Wege zur&uuml;ck &ndash; einer davon geht immer:</p>
<ol>
<li><b>Hier zur&uuml;cksetzen</b> (nur wenn du gerade eingeloggt bist):<br>
<button class=w id=btnReset>Auf Standard-Passwort zur&uuml;cksetzen</button></li>
<li><b>Den BOOT-Knopf am Ger&auml;t 10 Sekunden lang gedr&uuml;ckt halten.</b> Das ist der
kleine Taster direkt auf der Platine. Danach gilt wieder das Standard-Passwort (siehe unten).
Man muss dazu also ans Ger&auml;t herankommen &ndash; von aussen geht das niemand.</li>
<li><b>Die Firmware neu aufspielen.</b> Wer die Firmware selbst baut, tr&auml;gt dabei ein
neues Standard-Passwort ein. Ein zuvor selbst gesetztes Passwort wird dann automatisch
verworfen. Dauerhaft aussperren kann man sich also nicht.</li>
</ol>
<div class="note">Nicht verwechseln: Das <b>OTA-Passwort</b> ist ein zweites, davon unabh&auml;ngiges Passwort.
Damit wird die Firmware &uuml;ber WLAN aufgespielt &ndash; f&uuml;r die Anmeldung hier spielt
es keine Rolle und es wird hier auch nicht ge&auml;ndert.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#4ea339,#69c350)"><h2>Wo liegt das Standard-Passwort?</h2></div><div class=cb>
<p style="margin:.2rem 0 .6rem;font-size:.95rem">Damit sich das Ger&auml;t &uuml;berhaupt
sch&uuml;tzen kann, wird schon beim Bau der Firmware ein Passwort fest hinterlegt &ndash; das ist
das <b>Standard-Passwort</b>, ab Werk <code>12345678</code>. Es steht in einer kleinen Textdatei namens <code>secrets.yaml</code>,
die zum Firmware-Projekt auf dem Computer geh&ouml;rt (Zeile <code>web_password</code>).</p>
<p style="margin:.2rem 0;font-size:.95rem">In dieser Datei stehen alle vertraulichen Angaben,
etwa das WLAN-Passwort. Sie bleibt deshalb auf dem eigenen Rechner und sollte nicht
weitergegeben werden.</p>
<div class="note g"><b>Du hast das Ger&auml;t nicht selbst eingerichtet?</b> Dann kennt die
Person das Passwort, die die Firmware aufgespielt hat &ndash; einfach dort nachfragen.
Und wenn du es selbst gesetzt hast: ab damit in den Passwortmanager, dann f&auml;ngt die
Sucherei gar nicht erst an.</div>
</div></div>
</main>
<script>
function msg(t,ok){var m=document.getElementById('msg');m.textContent=t;m.style.color=ok?'#1c6b3f':'#a02020'}
document.getElementById('btnSave').onclick=function(){
 var a=document.getElementById('pw1').value,b=document.getElementById('pw2').value;
 if(a!==b){msg('Die beiden Eingaben sind nicht gleich.',false);return}
 if(a.length<8||a.length>32){msg('Bitte 8 bis 32 Zeichen verwenden.',false);return}
 fetch('/passwort/set?pw='+encodeURIComponent(a),{method:'POST'}).then(function(r){
  if(r.ok){msg('Gespeichert. Beim naechsten Aufruf bitte mit dem neuen Passwort anmelden.',true)}
  else{r.text().then(function(t){msg('Fehler: '+t,false)})}
 }).catch(function(){msg('Verbindungsfehler.',false)})};
document.getElementById('btnReset').onclick=function(){
 if(!confirm('Web-Passwort wirklich auf den Standard aus secrets.yaml zuruecksetzen?'))return;
 fetch('/passwort/set?pw=__reset__',{method:'POST'}).then(function(r){
  if(r.ok){msg('Zurueckgesetzt. Es gilt wieder das Standard-Passwort.',true)}
  else{msg('Fehler beim Zuruecksetzen.',false)}})};
</script></body></html>)PWD";

static const char RADAR_HTML_EN[] = R"RADEN(<!doctype html><html lang=de><head><meta charset=utf-8>
<meta name=viewport content="width=device-width,initial-scale=1">
<title>LoHaTes &middot; Radar zones</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;display:flex;
 align-items:center;gap:1.3rem;flex-wrap:wrap;position:sticky;top:0;z-index:9;box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav{display:flex;gap:.3rem;flex-wrap:wrap}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
.jump{display:flex;align-items:center;gap:.25rem;flex-wrap:wrap;margin:.2rem 0 .9rem;
 font-size:.85rem;background:#fff;border:1px solid #e6e9ef;border-radius:10px;padding:.4rem .6rem}
.jump span{color:#8893a2;font-weight:700;margin-right:.3rem}
.jump a{color:#5a6675;text-decoration:none;padding:.25rem .6rem;border-radius:6px;font-weight:600}
.jump a:hover{background:#eef1f5;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
main{max-width:1040px;margin:0 auto;padding:1.1rem}
h1{font-size:1.35rem;margin:.2rem 0 1rem;color:#1c2531}
.card{background:#fff;border-radius:15px;box-shadow:0 2px 10px rgba(20,30,50,.07);margin:1rem 0;border:1px solid #e6e9ef;overflow:hidden}
.ch{padding:.8rem 1.1rem;color:#fff;background:linear-gradient(90deg,#4ea339,#69c350)}
.ch h2{margin:0;font-size:1.1rem}
.cb{padding:1rem 1.1rem 1.2rem}
canvas{width:100%;height:auto;display:block;border-radius:10px;background:#f7f9fb;border:1px solid #e2e6ec;touch-action:none;cursor:crosshair}
.badges{display:flex;gap:.5rem;flex-wrap:wrap;margin:.8rem 0 0}
.bg{background:#f3f4f7;border-radius:20px;padding:.3rem .8rem;font-size:.85rem;font-weight:600;color:#4a5563}
.bg b{color:#1c2531}
.bg.ok{background:#e6f7ea;color:#1c6b3f}.bg.no{background:#fdeceb;color:#a02020}
.tabs{display:flex;gap:.4rem;flex-wrap:wrap;margin-bottom:.9rem}
.tab{padding:.5rem 1rem;border-radius:9px;font-weight:700;font-size:.92rem;cursor:pointer;border:2px solid transparent;background:#f3f4f7;color:#5a6675}
.tab.on{color:#fff}
.tab.on.z1{background:#69c350;border-color:#4ea339}
.tab.on.z2{background:#41bdf5;border-color:#1e9ad6}
.tab.on.z3{background:#f0930b;border-color:#c97907}
.row{display:flex;gap:.6rem;flex-wrap:wrap;align-items:flex-end;margin:.7rem 0}
label{display:block;font-size:.78rem;color:#7a8694;font-weight:600;margin-bottom:.2rem}
input[type=number],input[type=text],select{padding:.45rem .6rem;border:1px solid #cfd6de;border-radius:8px;font-size:.95rem;width:110px;font-family:inherit}
button{padding:.55rem 1rem;border:0;border-radius:9px;font-size:.92rem;font-weight:700;cursor:pointer;font-family:inherit}
.p{background:#69c350;color:#fff}.p:hover{background:#5bb043}
.s{background:#1c2531;color:#fff}.s:hover{background:#2c3a4d}
.d{background:#f3f4f7;color:#5a6675}.d:hover{background:#e6e9ef}
.big{background:#e82127;color:#fff;font-size:1rem;padding:.8rem 1.3rem;width:100%}
.big:hover{background:#c8161c}
.note{background:#fff8e6;border:1px solid #e0c886;border-radius:10px;padding:.7rem .9rem;font-size:.87rem;color:#7a5b13;margin:.8rem 0}
.note.i{background:#eef4ff;border-color:#c9d8f0;color:#2b4470}
ol{margin:.4rem 0 0;padding-left:1.2rem;font-size:.9rem;line-height:1.6}
table{border-collapse:collapse;width:100%;font-size:.87rem;margin-top:.5rem}
th,td{border:1px solid #e2e5ea;padding:.4rem .55rem;text-align:left}
th{background:#1c2531;color:#fff;font-size:.8rem}
code{background:#f3f4f7;color:#c2185b;padding:.05rem .35rem;border-radius:4px;font-weight:600}
#toast{position:fixed;left:50%;transform:translateX(-50%);bottom:22px;background:#1c2531;color:#fff;
 padding:.6rem 1.1rem;border-radius:9px;font-size:.9rem;opacity:0;transition:.25s;pointer-events:none;z-index:20}
#toast.show{opacity:1}
</style></head><body>
<!--HEADER-->
<main>
<h1>Set up radar zones</h1>

<div class=card><div class=ch><h2>Live view (top-down)</h2></div><div class=cb>
<canvas id=cv width=1400 height=1000></canvas>
<div class=badges>
 <span class=bg id=bMode>Mode: &ndash;</span>
 <span class=bg id=bTot>Targets: <b>0</b></span>
 <span class=bg id=bZ1>Zone 1: &ndash;</span>
 <span class=bg id=bZ2>Zone 2: &ndash;</span>
 <span class=bg id=bZ3>Zone 3: &ndash;</span>
 <span class=bg id=bT1>T1: &ndash;</span>
</div>
<div class=row>
 <div><label>Visible depth</label>
 <select id=depth><option value=3000>3 m</option><option value=4500 selected>4,5 m</option><option value=6000>6 m</option><option value=7560>7,5 m</option></select></div>
 <button class=d id=btnTrail>Clear trail</button>
 <button class=s id=btnDet>Zone mode: Detection</button>
</div>
<div class="note i">The sensor sits top centre (red); downwards means away from the wall.
Pick a zone below and drag a rectangle onto the map with the mouse or your finger.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#1e9ad6,#41bdf5)"><h2>Edit zone</h2></div><div class=cb>
<div class=tabs>
 <div class="tab z1 on" data-z=0>Zone 1</div>
 <div class="tab z2" data-z=1>Zone 2</div>
 <div class="tab z3" data-z=2>Zone 3</div>
</div>
<button class=big id=btnHere>I am standing here NOW &rarr; put a zone around me</button>
<div class=row>
 <div><label>Radius around me (mm)</label><input type=number id=margin value=500 step=50 min=100 max=3000></div>
</div>
<div class=row>
 <div><label>X1 (left, mm)</label><input type=number id=x1 step=10></div>
 <div><label>Y1 (near, mm)</label><input type=number id=y1 step=10></div>
 <div><label>X2 (right, mm)</label><input type=number id=x2 step=10></div>
 <div><label>Y2 (far, mm)</label><input type=number id=y2 step=10></div>
</div>
<div class=row>
 <button class=p id=btnSave>Save zone</button>
 <button class=d id=btnClear>Delete this zone</button>
</div>
<div class=note><b>Important:</b> zones only take effect once the zone mode is set to <b>Detection</b> (button above).
They are stored inside the radar module itself, so they survive a power cut.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#c11a20,#e82127)"><h2>What Loxone receives</h2></div><div class=cb>
<p style="margin:.2rem 0;font-size:.93rem">Once somebody stands in a zone for <b>3 seconds</b>, this goes out via UDP
(port 7101) to the Miniserver:</p>
<p style="margin:.5rem 0"><code>lohates:zone1=1;zone2=0;zone3=0</code></p>
<table>
<tr><th>Zone</th><th>Command recognition in the virtual input</th><th>Idea</th></tr>
<tr><td>Zone 1</td><td><code>zone1=\v</code></td><td>Open garage door</td></tr>
<tr><td>Zone 2</td><td><code>zone2=\v</code></td><td>Outside light on</td></tr>
<tr><td>Zone 3</td><td><code>zone3=\v</code></td><td>unused</td></tr>
</table>
<div class="note i" style="margin-top:.8rem">Create them as <b>analog</b> inputs (min 0 / max 1), not digital &ndash; otherwise Loxone's
range check clamps everything to 0. The status is repeated every 10 s so a lost packet
heals itself.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#1c2531,#3a4a5e)"><h2>How to calibrate</h2></div><div class=cb>
<ol>
<li>Open this page on your <b>phone</b> and step outside.</li>
<li>Pick a zone, walk to the spot you want and <b>stand still</b> for a moment.</li>
<li>Press <b>&ldquo;I am standing here NOW&rdquo;</b> &ndash; the zone is placed around you.</li>
<li>Switch on <b>Detection</b>.</li>
<li>Test: <b>walking past</b> must not trigger, <b>standing for 3 s</b> must (the badge turns green).</li>
</ol>
<div class="note i" style="margin-top:.9rem">Too large &rarr; it fires when someone just walks past. Too small &rarr; you have to hit the
exact spot. <b>50&ndash;70 cm radius</b> is a good start. Zones should <b>not overlap</b>.</div>
</div></div>
</main>
<div id=toast></div>
<script>
var cv=document.getElementById('cv'),ctx=cv.getContext('2d'),W=1400,H=1000;
var XR=4860,YR=7560;
var view={xMin:-3000,xMax:3000,yMin:0,yMax:4500};
var COL=['#69c350','#41bdf5','#f0930b'],COLD=['#3d7f2c','#1a7fb0','#a86505'];
var T=[{x:null,y:null},{x:null,y:null},{x:null,y:null}];
var Z=[{x1:0,y1:0,x2:0,y2:0},{x1:0,y1:0,x2:0,y2:0},{x1:0,y1:0,x2:0,y2:0}];
var S={tot:0,cnt:[0,0,0],occ:[false,false,false],mode:'-'};
var act=0,trail=[],drag=null,editing=false;
var I={x1:document.getElementById('x1'),y1:document.getElementById('y1'),x2:document.getElementById('x2'),y2:document.getElementById('y2')};

function toast(m){var t=document.getElementById('toast');t.textContent=m;t.className='show';setTimeout(function(){t.className=''},2200)}
function sx(x){return (x-view.xMin)/(view.xMax-view.xMin)*W}
function sy(y){return (y-view.yMin)/(view.yMax-view.yMin)*H}
function wx(px){return view.xMin+px/W*(view.xMax-view.xMin)}
function wy(py){return view.yMin+py/H*(view.yMax-view.yMin)}
function cl(v,a,b){return Math.max(a,Math.min(b,v))}
function norm(z){return{x1:Math.min(z.x1,z.x2),x2:Math.max(z.x1,z.x2),y1:Math.min(z.y1,z.y2),y2:Math.max(z.y1,z.y2)}}
function valid(z){var n=norm(z);return (n.x2-n.x1)>1&&(n.y2-n.y1)>1}

function draw(){
 ctx.clearRect(0,0,W,H);ctx.fillStyle='#f7f9fb';ctx.fillRect(0,0,W,H);
 ctx.lineWidth=1;ctx.font='22px Segoe UI';
 for(var gx=Math.ceil(view.xMin/500)*500;gx<=view.xMax;gx+=500){
  var m=(gx%1000===0);ctx.strokeStyle=m?'#d2dae3':'#e9edf2';
  ctx.beginPath();ctx.moveTo(sx(gx),0);ctx.lineTo(sx(gx),H);ctx.stroke();
  if(m&&gx!==0){ctx.fillStyle='#9aa5b1';ctx.fillText((gx/1000)+'m',sx(gx)+5,H-10)}}
 for(var gy=0;gy<=view.yMax;gy+=500){
  var m2=(gy%1000===0);ctx.strokeStyle=m2?'#d2dae3':'#e9edf2';
  ctx.beginPath();ctx.moveTo(0,sy(gy));ctx.lineTo(W,sy(gy));ctx.stroke();
  if(m2&&gy>0){ctx.fillStyle='#9aa5b1';ctx.fillText((gy/1000)+'m',8,sy(gy)-8)}}
 ctx.strokeStyle='#c9d3dd';ctx.setLineDash([10,10]);ctx.lineWidth=2;
 [-60,60].forEach(function(a){var r=a*Math.PI/180;
  ctx.beginPath();ctx.moveTo(sx(0),sy(0));ctx.lineTo(sx(Math.sin(r)*YR),sy(Math.cos(r)*YR));ctx.stroke()});
 ctx.setLineDash([]);
 Z.forEach(function(z,i){if(!valid(z))return;var n=norm(z);
  ctx.fillStyle=COL[i]+'2e';ctx.strokeStyle=COL[i];ctx.lineWidth=(i===act)?6:3;
  ctx.fillRect(sx(n.x1),sy(n.y1),sx(n.x2)-sx(n.x1),sy(n.y2)-sy(n.y1));
  ctx.strokeRect(sx(n.x1),sy(n.y1),sx(n.x2)-sx(n.x1),sy(n.y2)-sy(n.y1));
  ctx.fillStyle=COLD[i];ctx.font='bold 24px Segoe UI';
  ctx.fillText('ZONE '+(i+1)+(S.occ[i]?'  *':''),sx(n.x1)+10,sy(n.y1)+30)});
 if(drag){ctx.strokeStyle=COL[act];ctx.lineWidth=5;ctx.setLineDash([12,8]);
  ctx.strokeRect(drag.px1,drag.py1,drag.px2-drag.px1,drag.py2-drag.py1);ctx.setLineDash([])}
 var now=Date.now();
 trail.forEach(function(p){var a=1-(now-p.t)/12000;if(a<=0)return;
  ctx.fillStyle='rgba(120,132,148,'+(a*0.45)+')';
  ctx.beginPath();ctx.arc(sx(p.x),sy(p.y),7,0,6.284);ctx.fill()});
 T.forEach(function(t,i){if(t.x===null||t.y===null||(t.x===0&&t.y===0))return;
  var inz=-1;Z.forEach(function(z,k){if(!valid(z))return;var n=norm(z);
   if(t.x>=n.x1&&t.x<=n.x2&&t.y>=n.y1&&t.y<=n.y2)inz=k});
  ctx.fillStyle=inz>=0?COL[inz]:'#5a6675';ctx.strokeStyle='#fff';ctx.lineWidth=4;
  ctx.beginPath();ctx.arc(sx(t.x),sy(t.y),18,0,6.284);ctx.fill();ctx.stroke();
  ctx.fillStyle='#1c2531';ctx.font='bold 24px Segoe UI';
  ctx.fillText('T'+(i+1)+'  '+Math.round(t.x)+' / '+Math.round(t.y),sx(t.x)+26,sy(t.y)-14)});
 ctx.fillStyle='#e82127';ctx.beginPath();
 ctx.moveTo(sx(0),sy(0)-4);ctx.lineTo(sx(0)-22,sy(0)-40);ctx.lineTo(sx(0)+22,sy(0)-40);ctx.closePath();ctx.fill();
 ctx.fillRect(sx(0)-60,sy(0)-52,120,14);
 ctx.fillStyle='#8a3033';ctx.font='bold 22px Segoe UI';ctx.fillText('LoHaTes',sx(0)-48,sy(0)-58);
}
function tick(){draw();requestAnimationFrame(tick)}
requestAnimationFrame(tick);

function pos(e){var r=cv.getBoundingClientRect();
 var cx=(e.touches?e.touches[0].clientX:e.clientX)-r.left;
 var cy=(e.touches?e.touches[0].clientY:e.clientY)-r.top;
 return{px:cx/r.width*W,py:cy/r.height*H}}
function dStart(e){e.preventDefault();var p=pos(e);drag={px1:p.px,py1:p.py,px2:p.px,py2:p.py}}
function dMove(e){if(!drag)return;e.preventDefault();var p=pos(e);drag.px2=p.px;drag.py2=p.py}
function dEnd(e){if(!drag)return;e.preventDefault();
 var a=wx(Math.min(drag.px1,drag.px2)),b=wx(Math.max(drag.px1,drag.px2));
 var c=wy(Math.min(drag.py1,drag.py2)),d=wy(Math.max(drag.py1,drag.py2));
 drag=null;
 if(Math.abs(b-a)<150||Math.abs(d-c)<150){toast('Rectangle too small');return}
 Z[act]={x1:Math.round(cl(a,-XR,XR)),x2:Math.round(cl(b,-XR,XR)),
         y1:Math.round(cl(c,0,YR)),y2:Math.round(cl(d,0,YR))};
 fill();toast('Zone '+(act+1)+' drawn - not saved yet!')}
cv.addEventListener('mousedown',dStart);cv.addEventListener('mousemove',dMove);
window.addEventListener('mouseup',dEnd);
cv.addEventListener('touchstart',dStart,{passive:false});cv.addEventListener('touchmove',dMove,{passive:false});
cv.addEventListener('touchend',dEnd,{passive:false});

function fill(){var z=Z[act];I.x1.value=z.x1;I.y1.value=z.y1;I.x2.value=z.x2;I.y2.value=z.y2}
['x1','y1','x2','y2'].forEach(function(k){
 I[k].addEventListener('focus',function(){editing=true});
 I[k].addEventListener('change',function(){Z[act][k]=+I[k].value||0;editing=false})});
Array.prototype.forEach.call(document.querySelectorAll('.tab'),function(t){
 t.onclick=function(){act=+t.getAttribute('data-z');
  Array.prototype.forEach.call(document.querySelectorAll('.tab'),function(o){o.classList.remove('on')});
  t.classList.add('on');fill()}});

function setNum(o,v){return fetch('/number/'+o+'/set?value='+Math.round(v),{method:'POST'})}
function saveActive(){var n=norm(Z[act]),p='zone_'+(act+1)+'_';
 return Promise.all([setNum(p+'x1',n.x1),setNum(p+'y1',n.y1),setNum(p+'x2',n.x2),setNum(p+'y2',n.y2)])}
document.getElementById('btnSave').onclick=function(){
 Z[act]={x1:+I.x1.value||0,y1:+I.y1.value||0,x2:+I.x2.value||0,y2:+I.y2.value||0};
 saveActive().then(function(){toast('Zone '+(act+1)+' saved')}).catch(function(){toast('Error while saving')})};
document.getElementById('btnDet').onclick=function(){
 fetch('/select/radar_zonen-modus/set?option=Detection',{method:'POST'}).then(function(){toast('Detection active')})};
document.getElementById('btnClear').onclick=function(){
 Z[act]={x1:0,y1:0,x2:0,y2:0};fill();
 saveActive().then(function(){toast('Zone '+(act+1)+' deleted')})};
document.getElementById('btnHere').onclick=function(){
 if(T[0].x===null||(T[0].x===0&&T[0].y===0)){toast('No target detected - move a little');return}
 var m=+document.getElementById('margin').value||500;
 Z[act]={x1:Math.round(cl(T[0].x-m,-XR,XR)),x2:Math.round(cl(T[0].x+m,-XR,XR)),
         y1:Math.round(cl(T[0].y-m,0,YR)),y2:Math.round(cl(T[0].y+m,0,YR))};
 fill();saveActive().then(function(){toast('Zone '+(act+1)+' placed around you and saved')})};
document.getElementById('btnTrail').onclick=function(){trail=[]};
document.getElementById('depth').onchange=function(){view.yMax=+this.value;
 var half=+this.value*0.75;view.xMin=-half;view.xMax=half};

function badge(){
 document.getElementById('bTot').innerHTML='Targets: <b>'+S.tot+'</b>';
 for(var i=0;i<3;i++){var e=document.getElementById('bZ'+(i+1));
  e.textContent='Zone '+(i+1)+': '+(S.occ[i]?'OCCUPIED':S.cnt[i]+' targets');
  e.className='bg '+(S.occ[i]?'ok':'')}
 var m=document.getElementById('bMode');
 m.textContent='Mode: '+S.mode;m.className='bg '+(S.mode==='Detection'?'ok':'no');
 document.getElementById('bT1').textContent='T1: '+(T[0].x===null?'-':Math.round(T[0].x)+' / '+Math.round(T[0].y)+' mm');
}
function push(){if(T[0].x===null||T[0].y===null)return;if(T[0].x===0&&T[0].y===0)return;
 trail.push({x:T[0].x,y:T[0].y,t:Date.now()});if(trail.length>150)trail.shift()}

var NM={};
[1,2,3].forEach(function(z){['x1','y1','x2','y2'].forEach(function(k){
 NM['number-zone_'+z+'_'+k]={z:z-1,k:k}})});

var es=new EventSource('/events');
es.addEventListener('state',function(e){var d;try{d=JSON.parse(e.data)}catch(_){return}
 var id=d.id||'';
 if(id==='sensor-radar_ziel_1_x'){T[0].x=d.value}
 else if(id==='sensor-radar_ziel_1_y'){T[0].y=d.value;push()}
 else if(id==='sensor-radar_ziel_2_x'){T[1].x=d.value}
 else if(id==='sensor-radar_ziel_2_y'){T[1].y=d.value}
 else if(id==='sensor-radar_ziel_3_x'){T[2].x=d.value}
 else if(id==='sensor-radar_ziel_3_y'){T[2].y=d.value}
 else if(id==='sensor-radar_ziele_gesamt'){S.tot=d.value}
 else if(id==='sensor-radar_zone_1_ziele'){S.cnt[0]=d.value}
 else if(id==='sensor-radar_zone_2_ziele'){S.cnt[1]=d.value}
 else if(id==='sensor-radar_zone_3_ziele'){S.cnt[2]=d.value}
 else if(id==='binary_sensor-radar__zone_1_besetzt'){S.occ[0]=!!d.value}
 else if(id==='binary_sensor-radar__zone_2_besetzt'){S.occ[1]=!!d.value}
 else if(id==='binary_sensor-radar__zone_3_besetzt'){S.occ[2]=!!d.value}
 else if(id==='select-radar_zonen-modus'){S.mode=d.value}
 else if(NM[id]){var t=NM[id];Z[t.z][t.k]=+d.value;
  if(!editing&&t.z===act)fill()}
 else return;
 badge()});
badge();
</script></body></html>)RADEN";

static const char PW_HTML_EN[] = R"PWDEN(<!doctype html><html lang=de><head><meta charset=utf-8>
<meta name=viewport content="width=device-width,initial-scale=1">
<title>LoHaTes &middot; Password</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;display:flex;
 align-items:center;gap:1.3rem;flex-wrap:wrap;box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
.jump{display:flex;align-items:center;gap:.25rem;flex-wrap:wrap;margin:.2rem 0 .9rem;
 font-size:.85rem;background:#fff;border:1px solid #e6e9ef;border-radius:10px;padding:.4rem .6rem}
.jump span{color:#8893a2;font-weight:700;margin-right:.3rem}
.jump a{color:#5a6675;text-decoration:none;padding:.25rem .6rem;border-radius:6px;font-weight:600}
.jump a:hover{background:#eef1f5;color:#e82127}
nav a.on{background:#1c2531;color:#fff}
main{max-width:720px;margin:0 auto;padding:1.1rem}
h1{font-size:1.35rem;margin:.2rem 0 1rem;color:#1c2531}
.card{background:#fff;border-radius:15px;box-shadow:0 2px 10px rgba(20,30,50,.07);margin:1rem 0;border:1px solid #e6e9ef;overflow:hidden}
.ch{padding:.8rem 1.1rem;color:#fff;background:linear-gradient(90deg,#1c2531,#3a4a5e)}
.ch h2{margin:0;font-size:1.1rem}
.cb{padding:1rem 1.1rem 1.2rem}
label{display:block;font-size:.8rem;color:#7a8694;font-weight:600;margin:.7rem 0 .2rem}
input{padding:.55rem .7rem;border:1px solid #cfd6de;border-radius:8px;font-size:1rem;width:100%;font-family:inherit}
button{padding:.65rem 1.1rem;border:0;border-radius:9px;font-size:.95rem;font-weight:700;cursor:pointer;font-family:inherit;margin-top:.9rem}
.p{background:#69c350;color:#fff}.p:hover{background:#5bb043}
.w{background:#e8a020;color:#fff}.w:hover{background:#cf8c15}
.note{background:#fff8e6;border:1px solid #e0c886;border-radius:10px;padding:.7rem .9rem;font-size:.88rem;color:#7a5b13;margin:.9rem 0}
.note.i{background:#eef4ff;border-color:#c9d8f0;color:#2b4470}
.note.g{background:#eafaf1;border-color:#bce7cd;color:#1c6b3f}
ol{margin:.4rem 0 0;padding-left:1.2rem;font-size:.9rem;line-height:1.7}
code{background:#f3f4f7;color:#c2185b;padding:.05rem .35rem;border-radius:4px;font-weight:600}
#msg{margin-top:.8rem;font-size:.92rem;font-weight:600}
</style></head><body>
<!--HEADER-->
<main>
<h1>Web password</h1>

<div class="note" style="margin:0 0 1rem"><b>Factory setting:</b> user <code>admin</code>,
password <code>12345678</code>. It is the same on every new device and printed in the manual
&ndash; so please change it right below.</div>

<div class=card><div class=ch><h2>Change password</h2></div><div class=cb>
<label for=pw1>New password (8&ndash;32 characters)</label>
<input type=password id=pw1 autocomplete=new-password>
<label for=pw2>Repeat to be safe</label>
<input type=password id=pw2 autocomplete=new-password>
<button class=p id=btnSave>Save password</button>
<div id=msg></div>
<div class="note i">The username stays <code>admin</code>. After saving, the browser asks for the login again
&ndash; enter the <b>new</b> password there. It is stored permanently on the device and
survives reboots.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#c98a12,#e8a020)"><h2>Forgot your password?</h2></div><div class=cb>
<p style="margin:.2rem 0 .6rem;font-size:.95rem">There are <b>three</b> ways back &ndash; one of them always works:</p>
<ol>
<li><b>Reset right here</b> (only while you are still logged in):<br>
<button class=w id=btnReset>Reset to the default password</button></li>
<li><b>Hold the BOOT button on the device for 10 seconds.</b> That is the small push button
on the board itself. The default password (see below) applies again afterwards. So you have to
be able to reach the device &ndash; nobody can do this remotely.</li>
<li><b>Install the firmware again.</b> Whoever builds the firmware sets a new default
password while doing so. A previously chosen password is then discarded automatically. So you
can never lock yourself out permanently.</li>
</ol>
<div class="note">Do not mix them up: the <b>OTA password</b> is a second, separate password. It is used to
install firmware over WiFi &ndash; it plays no role in signing in here and is not changed on
this page.</div>
</div></div>

<div class=card><div class=ch style="background:linear-gradient(90deg,#4ea339,#69c350)"><h2>Where does the default password live?</h2></div><div class=cb>
<p style="margin:.2rem 0 .6rem;font-size:.95rem">So the device can protect itself at all, a
password is built into the firmware right from the start &ndash; that is the <b>default
password</b>, <code>12345678</code> as shipped. It lives in a small text file called <code>secrets.yaml</code> that belongs to the
firmware project on the computer (line <code>web_password</code>).</p>
<p style="margin:.2rem 0;font-size:.95rem">That file holds every confidential detail, the WiFi
password among them. It stays on your own machine and should not be shared.</p>
<div class="note g"><b>Did somebody else set up the device?</b> Then the person who installed the
firmware knows the password &ndash; just ask them. And if you picked it yourself: put it in your
password manager, then the hunt never starts.</div>
</div></div>
</main>
<script>
function msg(t,ok){var m=document.getElementById('msg');m.textContent=t;m.style.color=ok?'#1c6b3f':'#a02020'}
document.getElementById('btnSave').onclick=function(){
 var a=document.getElementById('pw1').value,b=document.getElementById('pw2').value;
 if(a!==b){msg('The two entries do not match.',false);return}
 if(a.length<8||a.length>32){msg('Please use 8 to 32 characters.',false);return}
 fetch('/passwort/set?pw='+encodeURIComponent(a),{method:'POST'}).then(function(r){
  if(r.ok){msg('Saved. Please sign in with the new password next time.',true)}
  else{r.text().then(function(t){msg('Error: '+t,false)})}
 }).catch(function(){msg('Connection error.',false)})};
document.getElementById('btnReset').onclick=function(){
 if(!confirm('Really reset the web password to the default from secrets.yaml?'))return;
 fetch('/passwort/set?pw=__reset__',{method:'POST'}).then(function(r){
  if(r.ok){msg('Reset done. The default password applies again.',true)}
  else{msg('Error while resetting.',false)}})};
</script></body></html>)PWDEN";

static const char HEADER_HTML[] = R"HDR(<header><svg height="46" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 176 74" role="img" aria-label="LoHaTes">
  <path d="M14.75390625 24.1298828125H20.3935546875V41.7373046875H30.2958984375V46.0H14.75390625Z M41.943359375 32.9482421875Q40.2001953125 32.9482421875 39.28466796875 34.20068359375Q38.369140625 35.453125 38.369140625 37.8115234375Q38.369140625 40.169921875 39.28466796875 41.42236328125Q40.2001953125 42.6748046875 41.943359375 42.6748046875Q43.6572265625 42.6748046875 44.5654296875 41.42236328125Q45.4736328125 40.169921875 45.4736328125 37.8115234375Q45.4736328125 35.453125 44.5654296875 34.20068359375Q43.6572265625 32.9482421875 41.943359375 32.9482421875ZM41.943359375 29.1982421875Q46.1767578125 29.1982421875 48.55712890625 31.4833984375Q50.9375 33.7685546875 50.9375 37.8115234375Q50.9375 41.8544921875 48.55712890625 44.1396484375Q46.1767578125 46.4248046875 41.943359375 46.4248046875Q37.6953125 46.4248046875 35.30029296875 44.1396484375Q32.9052734375 41.8544921875 32.9052734375 37.8115234375Q32.9052734375 33.7685546875 35.30029296875 31.4833984375Q37.6953125 29.1982421875 41.943359375 29.1982421875Z" fill="#69c350"/>
  <path d="M55.48046875 24.1298828125H61.1201171875V32.46484375H69.4404296875V24.1298828125H75.080078125V46.0H69.4404296875V36.7275390625H61.1201171875V46.0H55.48046875Z M88.20703125 38.6171875Q86.56640625 38.6171875 85.73876953125 39.173828125Q84.9111328125 39.73046875 84.9111328125 40.814453125Q84.9111328125 41.810546875 85.57763671875 42.37451171875Q86.244140625 42.9384765625 87.4306640625 42.9384765625Q88.91015625 42.9384765625 89.9208984375 41.87646484375Q90.931640625 40.814453125 90.931640625 39.2177734375V38.6171875ZM96.2197265625 36.6396484375V46.0H90.931640625V43.568359375Q89.876953125 45.0625 88.55859375 45.74365234375Q87.240234375 46.4248046875 85.3505859375 46.4248046875Q82.8017578125 46.4248046875 81.21240234375 44.93798828125Q79.623046875 43.451171875 79.623046875 41.078125Q79.623046875 38.1923828125 81.60791015625 36.8447265625Q83.5927734375 35.4970703125 87.8408203125 35.4970703125H90.931640625V35.0869140625Q90.931640625 33.841796875 89.9501953125 33.26318359375Q88.96875 32.6845703125 86.888671875 32.6845703125Q85.2041015625 32.6845703125 83.75390625 33.021484375Q82.3037109375 33.3583984375 81.05859375 34.0322265625V30.033203125Q82.7431640625 29.623046875 84.4423828125 29.41064453125Q86.1416015625 29.1982421875 87.8408203125 29.1982421875Q92.279296875 29.1982421875 94.24951171875 30.94873046875Q96.2197265625 32.69921875 96.2197265625 36.6396484375Z" fill="#41bdf5"/>
  <g transform="translate(101.6,16)">
    <path d="M0,4 Q14,-3 28,4 L26.2,9.5 Q14,3.5 1.8,9.5 Z" fill="#e82127"/>
    <path d="M9.5,11 L18.5,11 L16,24 L14,34 L12,24 Z" fill="#e82127"/>
  </g>
  <path d="M141.974609375 37.7529296875V39.2470703125H129.7138671875Q129.904296875 41.0927734375 131.046875 42.015625Q132.189453125 42.9384765625 134.240234375 42.9384765625Q135.8955078125 42.9384765625 137.63134765625 42.44775390625Q139.3671875 41.95703125 141.1982421875 40.9609375V45.00390625Q139.337890625 45.70703125 137.4775390625 46.06591796875Q135.6171875 46.4248046875 133.7568359375 46.4248046875Q129.3037109375 46.4248046875 126.83544921875 44.16162109375Q124.3671875 41.8984375 124.3671875 37.8115234375Q124.3671875 33.7978515625 126.79150390625 31.498046875Q129.2158203125 29.1982421875 133.4638671875 29.1982421875Q137.3310546875 29.1982421875 139.65283203125 31.52734375Q141.974609375 33.8564453125 141.974609375 37.7529296875ZM136.583984375 36.009765625Q136.583984375 34.515625 135.71240234375 33.60009765625Q134.8408203125 32.6845703125 133.4345703125 32.6845703125Q131.9111328125 32.6845703125 130.958984375 33.54150390625Q130.0068359375 34.3984375 129.7724609375 36.009765625Z M159.26171875 30.1064453125V34.0908203125Q157.5771484375 33.3876953125 156.009765625 33.0361328125Q154.4423828125 32.6845703125 153.05078125 32.6845703125Q151.556640625 32.6845703125 150.83154296875 33.05810546875Q150.1064453125 33.431640625 150.1064453125 34.2080078125Q150.1064453125 34.837890625 150.65576171875 35.1748046875Q151.205078125 35.51171875 152.6259765625 35.6728515625L153.548828125 35.8046875Q157.5771484375 36.3173828125 158.96875 37.4892578125Q160.3603515625 38.6611328125 160.3603515625 41.166015625Q160.3603515625 43.7880859375 158.4267578125 45.1064453125Q156.4931640625 46.4248046875 152.6552734375 46.4248046875Q151.029296875 46.4248046875 149.29345703125 46.16845703125Q147.5576171875 45.912109375 145.7265625 45.3994140625V41.4150390625Q147.2939453125 42.1767578125 148.94189453125 42.5576171875Q150.58984375 42.9384765625 152.2890625 42.9384765625Q153.8271484375 42.9384765625 154.603515625 42.513671875Q155.3798828125 42.0888671875 155.3798828125 41.25390625Q155.3798828125 40.55078125 154.84521484375 40.20654296875Q154.310546875 39.8623046875 152.7138671875 39.671875L151.791015625 39.5546875Q148.2900390625 39.115234375 146.8837890625 37.9287109375Q145.4775390625 36.7421875 145.4775390625 34.3251953125Q145.4775390625 31.7177734375 147.2646484375 30.4580078125Q149.0517578125 29.1982421875 152.7431640625 29.1982421875Q154.193359375 29.1982421875 155.7900390625 29.41796875Q157.38671875 29.6376953125 159.26171875 30.1064453125Z" fill="#e82127"/>
  <rect x="12.0" y="56" width="40.2" height="4" rx="2" fill="#69c350"/>
  <rect x="52.7" y="56" width="45.9" height="4" rx="2" fill="#41bdf5"/>
  <rect x="101.6" y="56" width="56.2" height="4" rx="2" fill="#e82127"/>
</svg><span class=brand>Tesla &harr; Loxone &amp; Home Assistant Bridge</span>
<!--NAV-->
</header>)HDR";

// ---- Einheitliche Navigation ---------------------------------------------
// Alle Seiten tragen den Platzhalter <!--NAV--> und bekommen dieselbe
// Hauptnavigation. Der Punkt "Radar" erscheint nur, wenn packages/radar.yml
// eingebunden ist (setzt LOHATES_HAS_RADAR) - ohne Radarmodul bleibt die
// Navigation also aufgeraeumt.

enum class NavPage { SETUP, GERAETE, RADAR, PASSWORT };

static void nav_item(std::string &n, const char *href, const char *label, bool active) {
  n += "<a href=\"";
  n += href;
  n += active ? "\" class=on>" : "\">";
  n += label;
  n += "</a>";
}

static void nav_lang(std::string &n, const char *de_url, const char *en_url, bool en) {
  static const char *ON = "background:#1c2531;color:#fff";
  static const char *OFF = "background:#f3f4f7;color:#5a6675";
  static const char *BOX = ";padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700\">";
  n += "<span style=\"margin-left:auto;display:flex;gap:4px\">";
  n += std::string("<a href=\"") + de_url + "\" style=\"" + (en ? OFF : ON) + BOX + "DE</a>";
  n += std::string("<a href=\"") + en_url + "\" style=\"" + (en ? ON : OFF) + BOX + "EN</a>";
  n += "</span>";
}

static std::string build_nav(NavPage page, bool en) {
  std::string n = "<nav>";
  nav_item(n, en ? "/en" : "/loxone", en ? "Setup" : "Einrichtung", page == NavPage::SETUP);
#ifdef LOHATES_HAS_RADAR
  nav_item(n, en ? "/radar-en" : "/radar", "Radar", page == NavPage::RADAR);
#endif
  nav_item(n, en ? "/passwort-en" : "/passwort", en ? "Password" : "Passwort",
           page == NavPage::PASSWORT);
  nav_item(n, en ? "/geraete-en" : "/geraete", en ? "Device UI" : "Ger&auml;te-UI",
           page == NavPage::GERAETE);
  n += "</nav>";
  // Sprachumschalter: jede Seite gibt es in beiden Fassungen
  switch (page) {
    case NavPage::SETUP:    nav_lang(n, "/loxone",   "/en",           en); break;
    case NavPage::GERAETE:  nav_lang(n, "/geraete",  "/geraete-en",   en); break;
    case NavPage::RADAR:    nav_lang(n, "/radar",    "/radar-en",     en); break;
    case NavPage::PASSWORT: nav_lang(n, "/passwort", "/passwort-en",  en); break;
  }
  return n;
}

static void send_page(AsyncWebServerRequest *request, const char *html, NavPage page, bool en) {
  std::string s(html);
  // Kopfzeile ist auf allen Seiten dieselbe (Logo, Untertitel, Navigation)
  size_t pos = s.find("<!--HEADER-->");
  if (pos != std::string::npos)
    s.replace(pos, 13, HEADER_HTML);
  pos = s.find("<!--NAV-->");
  if (pos != std::string::npos)
    s.replace(pos, 10, build_nav(page, en));
  request->send(200, "text/html; charset=utf-8", s.c_str());
}

// ---- Passwortspeicher im Flash (NVS) -------------------------------------
static const uint32_t PW_MAGIC = 0x4C485057;  // "LHPW"

struct PwStore {
  uint32_t magic;
  uint32_t default_hash;  // Hash des Standard-Passworts beim Setzen
  char pw[33];
} PACKED;

static uint32_t fnv1a_hash(const std::string &s) {
  uint32_t h = 2166136261UL;
  for (char c : s) {
    h ^= static_cast<uint8_t>(c);
    h *= 16777619UL;
  }
  return h;
}

bool LoxoneDocs::store_password_(const std::string &pw) {
  PwStore s{};
  s.magic = PW_MAGIC;
  s.default_hash = fnv1a_hash(this->default_password_);
  size_t n = pw.size() < sizeof(s.pw) - 1 ? pw.size() : sizeof(s.pw) - 1;
  memcpy(s.pw, pw.c_str(), n);
  s.pw[n] = '\0';
  bool ok = this->pref_.save(&s);
  global_preferences->sync();
  if (ok && this->base_ != nullptr) {
    this->base_->set_auth_password(pw);
    this->custom_active_ = true;
    ESP_LOGI("lohates", "Web-Passwort geaendert");
  }
  return ok;
}

void LoxoneDocs::reset_password() {
  PwStore empty{};
  this->pref_.save(&empty);
  global_preferences->sync();
  if (this->base_ != nullptr && !this->default_password_.empty()) {
    this->base_->set_auth_password(this->default_password_);
  }
  this->custom_active_ = false;
  ESP_LOGW("lohates", "Web-Passwort auf Standard aus secrets.yaml zurueckgesetzt");
}

void LoxoneDocs::setup() {
  this->pref_ = global_preferences->make_preference<PwStore>(PW_MAGIC);

  PwStore s{};
  const uint32_t dh = fnv1a_hash(this->default_password_);
  if (this->pref_.load(&s) && s.magic == PW_MAGIC) {
    if (s.default_hash != dh) {
      // Standard-Passwort wurde in secrets.yaml geaendert und neu geflasht
      // -> selbst gesetztes Passwort verwerfen (Rettungsweg gegen Aussperren)
      PwStore empty{};
      this->pref_.save(&empty);
      global_preferences->sync();
      ESP_LOGW("lohates", "Neues Standard-Passwort geflasht -> eigenes Passwort verworfen");
    } else if (s.pw[0] != '\0') {
      s.pw[sizeof(s.pw) - 1] = '\0';
      if (this->base_ != nullptr) {
        this->base_->set_auth_password(std::string(s.pw));
        this->custom_active_ = true;
        ESP_LOGI("lohates", "Eigenes Web-Passwort aktiv (aendern/zuruecksetzen: /passwort)");
      }
    }
  }

  if (this->base_ != nullptr) {
    this->base_->add_handler(this);
    this->base_->add_handler_without_auth(&this->logo_handler_);
  }
}

bool LogoHandler::canHandle(AsyncWebServerRequest *request) const {
  return request->method() == HTTP_GET && request->url() == "/logo.svg";
}

void LogoHandler::handleRequest(AsyncWebServerRequest *request) {
  request->send(200, "image/svg+xml", LOGO_SVG);
}

bool LoxoneDocs::canHandle(AsyncWebServerRequest *request) const {
  if (request->method() == HTTP_POST && request->url() == "/passwort/set")
    return true;
  if (request->method() != HTTP_GET)
    return false;
  const std::string u = request->url();
  return u == "/loxone" || u == "/en" || u == "/geraete" || u == "/geraete-en" || u == "/radar" ||
         u == "/radar-en" || u == "/passwort" || u == "/passwort-en";
}

void LoxoneDocs::handleRequest(AsyncWebServerRequest *request) {
  if (request->url() == "/passwort/set") {
    auto *p = request->getParam("pw");
    if (p == nullptr) {
      request->send(400, "text/plain; charset=utf-8", "Parameter pw fehlt");
      return;
    }
    std::string pw = p->value();
    if (pw == "__reset__") {
      this->reset_password();
      request->send(200, "text/plain; charset=utf-8", "zurueckgesetzt");
      return;
    }
    if (pw.size() < 8 || pw.size() > 32) {
      request->send(400, "text/plain; charset=utf-8", "8 bis 32 Zeichen noetig");
      return;
    }
    if (!this->store_password_(pw)) {
      request->send(500, "text/plain; charset=utf-8", "Speichern fehlgeschlagen");
      return;
    }
    request->send(200, "text/plain; charset=utf-8", "ok");
    return;
  }
  if (request->url() == "/passwort") {
    send_page(request, PW_HTML, NavPage::PASSWORT, false);
  } else if (request->url() == "/passwort-en") {
    send_page(request, PW_HTML_EN, NavPage::PASSWORT, true);
  } else if (request->url() == "/radar-en") {
    send_page(request, RADAR_HTML_EN, NavPage::RADAR, true);
  } else if (request->url() == "/radar") {
    send_page(request, RADAR_HTML, NavPage::RADAR, false);
  } else if (request->url() == "/geraete") {
    send_page(request, GERAETE_HTML, NavPage::GERAETE, false);
  } else if (request->url() == "/geraete-en") {
    send_page(request, GERAETE_HTML_EN, NavPage::GERAETE, true);
  } else if (request->url() == "/en") {
    send_page(request, LOXONE_HTML_EN, NavPage::SETUP, true);
  } else {
    send_page(request, LOXONE_HTML, NavPage::SETUP, false);
  }
}

}  // namespace loxone_docs
}  // namespace esphome
