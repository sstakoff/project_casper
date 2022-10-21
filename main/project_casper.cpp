#include <stdio.h>
#include "wifi_mgr.hpp"
#include "app.hpp"

extern "C" void app_main(void)
{

  App a;
  
  WifiMgr w(NULL);
  // w.provision("abc", true);
  // ESP_LOGI("app", "Connected!!!");

  // vTaskDelay(5000 / portTICK_PERIOD_MS);
  // ESP_LOGI("app","Starting reprovision");
  w.provision("abc", true);


  for (;;) {
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }

}
