#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

// components
#include "../components/time.c"
#include "../components/display.c"
#include "../components/rtc.c"

void app_main(void)
{
    time_t time = getUnixTime();
    // int i=0;
    while (1) {
        printf("Unix time: %lld\n", time); //time display reqs lld as it is a long long int
        time++;
        vTaskDelay(pdMS_TO_TICKS(1000)); // delay 1 second
    }
}
