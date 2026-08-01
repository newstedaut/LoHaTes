import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import web_server_base
from esphome.const import CONF_ID

AUTO_LOAD = ["web_server_base"]
DEPENDENCIES = ["web_server_base"]

loxone_docs_ns = cg.esphome_ns.namespace("loxone_docs")
LoxoneDocs = loxone_docs_ns.class_("LoxoneDocs", cg.Component)

CONF_WEB_SERVER_BASE_ID = "web_server_base_id"
CONF_DEFAULT_PASSWORD = "default_password"
CONF_SHOW_RADAR = "show_radar"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(LoxoneDocs),
        cv.GenerateID(CONF_WEB_SERVER_BASE_ID): cv.use_id(
            web_server_base.WebServerBase
        ),
        # Standard-Passwort aus secrets.yaml. Dient als Fallback, wenn der
        # Benutzer das selbst gesetzte Passwort zuruecksetzt (BOOT-Taster 10 s
        # oder Knopf auf /passwort). Wird das Standard-Passwort in secrets.yaml
        # geaendert und neu geflasht, verfaellt ein gesetztes Passwort ebenfalls
        # -> Neuflashen ist damit immer ein sicherer Rettungsweg.
        cv.Optional(CONF_DEFAULT_PASSWORD, default=""): cv.string,
        # Wird von packages/radar.yml auf true gesetzt. Nur dann taucht
        # "Radar" in der Navigation auf - ohne Radarmodul bleibt sie schlank.
        cv.Optional(CONF_SHOW_RADAR, default=False): cv.boolean,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    base = await cg.get_variable(config[CONF_WEB_SERVER_BASE_ID])
    cg.add(var.set_base(base))
    cg.add(var.set_default_password(config[CONF_DEFAULT_PASSWORD]))
    if config[CONF_SHOW_RADAR]:
        cg.add_define("LOHATES_HAS_RADAR")
