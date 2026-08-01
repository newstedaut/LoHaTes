window.addEventListener('load', function () {
  // Nicht anzeigen, wenn die Geraete-UI in /geraete als iframe eingebettet ist -
  // dort liefert die Rahmenseite Kopfzeile, Navigation und Legende bereits.
  try {
    if (window.self !== window.top) return;
  } catch (e) { return; }
  if (location.search.indexOf('embedded') !== -1) return;
  var d = document.createElement('div');
  d.style.cssText = 'text-align:center;padding:8px;background:#fff;border-bottom:3px solid #e82127;font-family:system-ui,sans-serif';
  d.innerHTML = '<a href="/loxone" style="color:#1c2531;font-weight:700;text-decoration:none;font-size:15px">' +
    '<span style="color:#69c350">Lo</span><span style="color:#41bdf5">Ha</span><span style="color:#e82127">Tes</span>' +
    ' &nbsp;Einrichtung &amp; Doku / Setup &amp; docs &rarr;</a>' +
    '<div style="margin-top:6px;display:flex;gap:6px;justify-content:center;flex-wrap:wrap">' +
    '<a href="/radar" style="background:#69c350;color:#fff;padding:4px 12px;border-radius:6px;' +
    'text-decoration:none;font-size:13px;font-weight:700">&#9678; Radar-Zonen</a>' +
    '<a href="/passwort" style="background:#1c2531;color:#fff;padding:4px 12px;border-radius:6px;' +
    'text-decoration:none;font-size:13px;font-weight:700">&#128273; Passwort</a>' +
    '<a href="/geraete" style="background:#f3f4f7;color:#5a6675;padding:4px 12px;border-radius:6px;' +
    'text-decoration:none;font-size:13px;font-weight:700">Ger&auml;te-UI</a></div>' +
    '<div style="font-size:12px;color:#6c7787;margin-top:4px">' +
    '&#9679; = AN/ON &nbsp;&middot;&nbsp; &#9675; = AUS/OFF &nbsp;&middot;&nbsp; ' +
    '&#9788; oben rechts = Hell/Dunkel &middot; top right = light/dark</div>';
  document.body.prepend(d);
});
