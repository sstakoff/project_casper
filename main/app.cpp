#include "app.hpp"
#include "wifi_mgr.hpp"

extern "C" {
#include "esp_log.h"
};

static const char *TAG="App";

App::App() {
    /* Initialize the default event loop */
    // If default event loop already exists, ret will be ESP_ERR_INVALID_STATE.
    // In that case, we just ignore

    esp_err_t ret = esp_event_loop_create_default();
    if (ret != ESP_ERR_INVALID_STATE) {
      ESP_ERROR_CHECK(ret);
    }

  ESP_ERROR_CHECK(esp_event_handler_register(WifiMgr::CASPER_WIFI_EVENT, ESP_EVENT_ANY_ID, App::event_handler, NULL));
  ESP_LOGI(TAG, "Registered handler");
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