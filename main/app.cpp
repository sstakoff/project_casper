#include "app.hpp"
#include "wifi_mgr.hpp"

extern "C" {
#include "esp_log.h"
};

static const char *TAG="App";

App::App() {
  esp_event_handler_register(WifiMgr::CASPER_WIFI_EVENT, ESP_EVENT_ANY_ID, App::event_handler, NULL);
}

void App::event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
  WifiMgr::CasperWifiEvent_t id = (WifiMgr::CasperWifiEvent_t)event_id;
  switch (id) {
    case WifiMgr::WIFI_CONNECTED:
      ESP_LOGI(TAG, "App has connected to WiFi");
      break;
    case WifiMgr::WIFI_DISCONNECTED:
      ESP_LOGI(TAG, "App has disconnected from WiFi");
      break;
  }
}