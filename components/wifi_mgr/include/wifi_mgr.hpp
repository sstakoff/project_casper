#ifndef _WIFI_MGR_H_
#define _WIFI_MGR_H_

extern "C" {
#include <esp_event.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>


#include <esp_log.h>
#include <esp_wifi.h>
#include <esp_event.h>
#include <nvs_flash.h>

#include <wifi_provisioning/manager.h>

#include <wifi_provisioning/scheme_ble.h>
};


class WifiMgr {
  public:
    WifiMgr(esp_event_loop_handle_t *event_loop);
    void provision(const char *pop, bool forceProvision = false);

    typedef enum {
      WIFI_CONNECTED,
      WIFI_DISCONNECTED
    } CasperWifiEvent_t;

    static esp_event_base_t CASPER_WIFI_EVENT;

  private:
    static void event_handler(void* arg, esp_event_base_t event_base,
                          int32_t event_id, void* event_data);

     bool _supporting_services_initialized;
     void setup_supporting_services();
     void wifi_init_sta(void);
     void get_device_service_name(char *service_name, size_t max);
     static void post_event(CasperWifiEvent_t event);
     static esp_event_loop_handle_t *event_loop;
};

#endif



