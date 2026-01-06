/*******************************************************************
 * 
 * File Name: time.C
 *
 * Description: 
 *   Returns the current unix time for startup and adjustments
 *   [possible: log desync ammounts.]
 * 
 * Author: sparrowsaurora
 * Date: 3/1/26
 * 
 * Limitations:
 *   We have to manualally account for the delay due to flashing the microcontroller
 *   Hence `#define FLASH_TIME 9;' 
 *
 *******************************************************************/

#include <time.h>
#include <sys/time.h>
#include <inttypes.h>
#include <stdlib.h>

#define FLASH_TIME 9; // seconds to flash microcontroller

void set_time_from_build(void)
{
    setenv("TZ", "UTC-8", 1);
    tzset();
    struct tm tm = {0};

    // Build time macros provided by compiler
    strptime(__DATE__ " " __TIME__, "%b %d %Y %H:%M:%S", &tm);

    time_t t = mktime(&tm);

    struct timeval tv = {
        .tv_sec = t,
        .tv_usec = 0
    };

    settimeofday(&tv, NULL);
}

time_t getUnixTime(void) {
    set_time_from_build();

    time_t now;
    time(&now);

    // adjust to account for flashing time (6s - 15s)
    now += FLASH_TIME; 

    // printf("from build: %lld\n", now);
    return now;
}