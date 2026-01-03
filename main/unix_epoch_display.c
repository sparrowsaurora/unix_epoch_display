#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

void app_main(void)
{
    int i=0;
    while (1) {
        printf("Unix epoch display alive: %d\n", i);
        i++;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
