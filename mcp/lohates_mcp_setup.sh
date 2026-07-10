#!/bin/bash
# LoHaTes MCP-Server einrichten (laeuft als root via hoval_setup.py)
set -e
echo "== LoHaTes MCP Setup =="

mkdir -p /home/admin/lohates-mcp

# Config (Schreiben erlaubt, Entriegeln gesperrt)
if [ ! -f /home/admin/lohates-mcp/config.json ]; then
cat > /home/admin/lohates-mcp/config.json << 'EOF'
{
  "port": 8809,
  "esp_host": "192.168.20.44",
  "esp_port": 6053,
  "api_encryption_key": "<API-ENCRYPTION-KEY-AUS-SECRETS>",
  "enable_write": true,
  "enable_unlock": false
}
EOF
fi

# Hochgeladenes Skript an Ort und Stelle
if [ -f /home/admin/lohates_mcp.py ]; then
  mv /home/admin/lohates_mcp.py /home/admin/lohates-mcp/lohates_mcp.py
fi

# venv
if [ ! -d /home/admin/lohates-mcp-venv ]; then
  python3 -m venv /home/admin/lohates-mcp-venv
fi
/home/admin/lohates-mcp-venv/bin/pip install -q --upgrade "mcp[cli]" aioesphomeapi

# Erreichbarkeit ESP testen
echo "-- Ping ESP:"
ping -c1 -W2 192.168.20.44 >/dev/null && echo "ESP erreichbar" || echo "WARNUNG: ESP nicht erreichbar!"

# systemd
cat > /etc/systemd/system/lohates-mcp.service << 'EOF'
[Unit]
Description=LoHaTes MCP-Server (KI-Schnittstelle, Port 8809)
After=network-online.target
Wants=network-online.target

[Service]
User=admin
ExecStart=/home/admin/lohates-mcp-venv/bin/python /home/admin/lohates-mcp/lohates_mcp.py
Restart=on-failure
RestartSec=10

[Install]
WantedBy=multi-user.target
EOF

chown -R admin:admin /home/admin/lohates-mcp /home/admin/lohates-mcp-venv
systemctl daemon-reload
systemctl enable --now lohates-mcp
sleep 4
systemctl is-active lohates-mcp && echo "Dienst laeuft"
ss -tlnp | grep 8809 || echo "WARNUNG: Port 8809 lauscht nicht"
echo "== fertig =="
