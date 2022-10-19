#include <stdio.h>
#include "wifi_mgr.hpp"


extern "C" void app_main(void)
{
  WifiMgr w;
  w.provision("abc", true);

}
