#pragma once
#include <string>
#include "esphome/core/component.h"
#include "esphome/core/preferences.h"
#include "esphome/components/web_server_base/web_server_base.h"

namespace esphome {
namespace loxone_docs {

class LogoHandler : public AsyncWebHandler {
 public:
  bool canHandle(AsyncWebServerRequest *request) const override;
  void handleRequest(AsyncWebServerRequest *request) override;
};

class LoxoneDocs : public Component, public AsyncWebHandler {
 public:
  void set_base(web_server_base::WebServerBase *base) { this->base_ = base; }
  void set_default_password(const std::string &pw) { this->default_password_ = pw; }
  void setup() override;
  float get_setup_priority() const override { return setup_priority::WIFI - 1.0f; }

  // Setzt das Web-Passwort auf den Wert aus secrets.yaml zurueck.
  // Aufruf per BOOT-Taster (10 s halten) oder Knopf auf /passwort.
  void reset_password();
  bool has_custom_password() const { return this->custom_active_; }

  bool canHandle(AsyncWebServerRequest *request) const override;
  void handleRequest(AsyncWebServerRequest *request) override;

 protected:
  bool store_password_(const std::string &pw);

  web_server_base::WebServerBase *base_{nullptr};
  LogoHandler logo_handler_;
  std::string default_password_;
  ESPPreferenceObject pref_;
  bool custom_active_{false};
};

}  // namespace loxone_docs
}  // namespace esphome
