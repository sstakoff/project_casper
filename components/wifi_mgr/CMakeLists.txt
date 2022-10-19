idf_component_register(SRCS "wifi_mgr.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES nvs_flash protocomm wifi_provisioning)
