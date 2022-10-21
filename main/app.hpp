#ifndef _APP_H_
#define _APP_H_

extern "C" {
#include "esp_event.h"
};


class App {
  public:
    App();
  private:
    static void event_handler(void *arg, esp_event_base_t event_base, int32_t
                              event_id, void *event_data);

};

#endif