#include <stdio.h>
#include "wifi_mgr.hpp"


extern "C" void app_main(void)
{
  WifiMgr w;
  w.provision("abc", true);
  w.waitForConnection();
  ESP_LOGI("app", "Connected!!!");

  vTaskDelay(5000 / portTICK_PERIOD_MS);
  ESP_LOGI("app","Starting reprovision");
  w.provision("abc", true);
  w.waitForConnection();
  ESP_LOGI("app", "Connected!!!");

}
