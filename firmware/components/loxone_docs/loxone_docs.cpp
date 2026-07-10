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
<header><svg height="46" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 176 74" role="img" aria-label="LoHaTes">
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
<nav><a href="/geraete">Ger&auml;te-UI</a><a href="#live">Live</a><a href="#loxone">Loxone</a><a href="#ha">Home Assistant</a><a href="#ki">KI/MCP</a><a href="#sicherheit">Sicherheit</a><a href="#geraet">Ger&auml;t</a></nav><span style="margin-left:auto;display:flex;gap:4px"><a href="/loxone" style="background:#1c2531;color:#fff;padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700">DE</a><a href="/en" style="background:#f3f4f7;color:#5a6675;padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700">EN</a></span>
</header><main>

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
<tr><td><code>wake</code></td><td>Auto aufwecken</td><td><input type=checkbox data-sw="erlaubt_wake"></td></tr>
<tr><td><code>charge</code></td><td>Laden start/stopp</td><td><input type=checkbox data-sw="erlaubt_charge"></td></tr>
<tr><td><code>amps</code></td><td>Ladestrom setzen</td><td><input type=checkbox data-sw="erlaubt_amps"></td></tr>
<tr><td><code>limit</code></td><td>Ladelimit setzen</td><td><input type=checkbox data-sw="erlaubt_limit"></td></tr>
<tr><td><code>lock</code></td><td>Verriegeln</td><td><input type=checkbox data-sw="erlaubt_lock"></td></tr>
<tr><td><code>unlock</code></td><td><b>Entriegeln</b> (Standard: gesperrt!)</td><td><input type=checkbox data-sw="erlaubt_unlock"></td></tr>
<tr><td><code>port_open</code></td><td>Ladeport &ouml;ffnen</td><td><input type=checkbox data-sw="erlaubt_port_open"></td></tr>
</table>
<div class=sub>Passwort &auml;ndern</div>
<p>Das Login-Passwort steht in <code>secrets.yaml</code> (Zeile <code>web_password</code>) im Firmware-Ordner. &Auml;ndern und per OTA aufspielen:</p>
<pre>1. &lt;Projektordner&gt;\secrets.yaml &rarr; web_password anpassen
2. robocopy "...\TeslaBLE" C:\LoHaTesBuild /MIR /XD .esphome .git
3. cd C:\LoHaTesBuild
4. esphome run tesla-ble-esp32-s3.yml --device 192.168.20.44</pre>
<p>Dauert ca. 2 Minuten, das Ger&auml;t startet einmal neu. (Oder einfach Claude darum bitten.)</p>
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
<title>LoHaTes \u00b7 Ger\u00e4te-UI</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36;display:flex;flex-direction:column;height:100vh}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;
 display:flex;align-items:center;gap:1.3rem;flex-wrap:wrap;box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav{display:flex;gap:.3rem;flex-wrap:wrap}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
iframe{flex:1;border:0;width:100%}
</style></head><body>
<header><svg height="46" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 176 74" role="img" aria-label="LoHaTes">
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
<nav><a href="/geraete" style="background:#e82127;color:#fff">Ger&auml;te-UI</a><a href="/loxone#live">Live</a><a href="/loxone#loxone">Loxone</a><a href="/loxone#ha">Home Assistant</a><a href="/loxone#ki">KI/MCP</a><a href="/loxone#sicherheit">Sicherheit</a><a href="/loxone#geraet">Ger&auml;t</a></nav><span style="margin-left:auto;display:flex;gap:4px"><a href="/geraete" style="background:#1c2531;color:#fff;padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700">DE</a><a href="/geraete-en" style="background:#f3f4f7;color:#5a6675;padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700">EN</a></span>
</header>
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
<header><svg height="46" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 176 74" role="img" aria-label="LoHaTes">
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
</svg><span class=brand>Tesla &harr; Loxone &amp; Home Assistant bridge</span>
<nav><a href="/geraete-en">Device UI</a><a href="#live">Live</a><a href="#loxone">Loxone</a><a href="#ha">Home Assistant</a><a href="#ki">AI/MCP</a><a href="#sicherheit">Security</a><a href="#geraet">Device</a></nav><span style="margin-left:auto;display:flex;gap:4px"><a href="/loxone" style="background:#f3f4f7;color:#5a6675;padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700">DE</a><a href="/en" style="background:#1c2531;color:#fff;padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700">EN</a></span>
</header><main>

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
<tr><td><code>wake</code></td><td>wake the car</td><td><input type=checkbox data-sw="erlaubt_wake"></td></tr>
<tr><td><code>charge</code></td><td>charging start/stop</td><td><input type=checkbox data-sw="erlaubt_charge"></td></tr>
<tr><td><code>amps</code></td><td>set charging current</td><td><input type=checkbox data-sw="erlaubt_amps"></td></tr>
<tr><td><code>limit</code></td><td>set charge limit</td><td><input type=checkbox data-sw="erlaubt_limit"></td></tr>
<tr><td><code>lock</code></td><td>lock</td><td><input type=checkbox data-sw="erlaubt_lock"></td></tr>
<tr><td><code>unlock</code></td><td><b>unlock</b> (default: blocked!)</td><td><input type=checkbox data-sw="erlaubt_unlock"></td></tr>
<tr><td><code>port_open</code></td><td>open charge port</td><td><input type=checkbox data-sw="erlaubt_port_open"></td></tr>
</table>
<div class=sub>Change password</div>
<p>The login password lives in <code>secrets.yaml</code> (line <code>web_password</code>) in the firmware folder. Change it and flash via OTA (<code>esphome run tesla-ble-esp32-s3.yml --device 192.168.20.44</code>, ~2 minutes).</p>
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
<title>LoHaTes \u00b7 Device UI</title><style>
*{box-sizing:border-box}
body{font-family:'Segoe UI',system-ui,sans-serif;margin:0;background:#eceff3;color:#222b36;display:flex;flex-direction:column;height:100vh}
header{background:#fff;border-bottom:3px solid #e82127;padding:.6rem 1.3rem;
 display:flex;align-items:center;gap:1.3rem;flex-wrap:wrap;box-shadow:0 1px 6px rgba(0,0,0,.06)}
.brand{color:#6c7787;font-weight:500;font-size:.9rem}
nav{display:flex;gap:.3rem;flex-wrap:wrap}
nav a{color:#5a6675;text-decoration:none;padding:.4rem .8rem;border-radius:7px;font-size:.93rem;font-weight:500}
nav a:hover{background:#f3f4f7;color:#e82127}
iframe{flex:1;border:0;width:100%}
</style></head><body>
<header><svg height="46" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 176 74" role="img" aria-label="LoHaTes">
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
<nav><a href="/geraete" style="background:#e82127;color:#fff">Device UI</a><a href="/en#live">Live</a><a href="/en#loxone">Loxone</a><a href="/en#ha">Home Assistant</a><a href="/en#ki">AI/MCP</a><a href="/en#sicherheit">Security</a><a href="/en#geraet">Device</a></nav><span style="margin-left:auto;display:flex;gap:4px"><a href="/geraete" style="background:#f3f4f7;color:#5a6675;padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700">DE</a><a href="/geraete-en" style="background:#1c2531;color:#fff;padding:.3rem .6rem;border-radius:6px;text-decoration:none;font-size:.85rem;font-weight:700">EN</a></span>
</header>
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

void LoxoneDocs::setup() {
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
  return request->method() == HTTP_GET &&
         (request->url() == "/loxone" || request->url() == "/geraete" || request->url() == "/en" || request->url() == "/geraete-en");
}

void LoxoneDocs::handleRequest(AsyncWebServerRequest *request) {
  if (request->url() == "/geraete") {
    request->send(200, "text/html; charset=utf-8", GERAETE_HTML);
  } else if (request->url() == "/geraete-en") {
    request->send(200, "text/html; charset=utf-8", GERAETE_HTML_EN);
  } else if (request->url() == "/en") {
    request->send(200, "text/html; charset=utf-8", LOXONE_HTML_EN);
  } else {
    request->send(200, "text/html; charset=utf-8", LOXONE_HTML);
  }
}

}  // namespace loxone_docs
}  // namespace esphome
