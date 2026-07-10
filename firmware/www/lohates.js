window.addEventListener('load', function () {
  var d = document.createElement('div');
  d.style.cssText = 'text-align:center;padding:8px;background:#fff;border-bottom:3px solid #e82127;font-family:system-ui,sans-serif';
  d.innerHTML = '<a href="/loxone" style="color:#1c2531;font-weight:700;text-decoration:none;font-size:15px">' +
    '<span style="color:#69c350">Lo</span><span style="color:#41bdf5">Ha</span><span style="color:#e82127">Tes</span>' +
    ' &nbsp;Einrichtung &amp; Doku / Setup &amp; docs &rarr;</a>' +
    '<div style="font-size:12px;color:#6c7787;margin-top:4px">' +
    '&#9679; = AN/ON &nbsp;&middot;&nbsp; &#9675; = AUS/OFF &nbsp;&middot;&nbsp; ' +
    '&#9788; oben rechts = Hell/Dunkel &middot; top right = light/dark</div>';
  document.body.prepend(d);
});
