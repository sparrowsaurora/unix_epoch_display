/*******************************************************************
 * File Name: time_util.h
 *
 * Description: 
 * Header file for Unix time synchronization and build-time offsets.
 * Author: sparrowsaurora
 * Date: 3/1/26
 * *******************************************************************/

#ifndef TIME_UTIL_H
#define TIME_UTIL_H

#include <time.h>

/* * Manual delay adjustment for microcontroller flashing.
 * Note: Removed semicolon to allow use in arithmetic: now + FLASH_TIME
 */
#define FLASH_TIME 9 

/**
 * @brief Sets the system time based on the __DATE__ and __TIME__ 
 * macros provided by the compiler at build time.
 */
void set_time_from_build(void);

/**
 * @brief Synchronizes time and returns the current Unix epoch.
 * @return time_t current adjusted Unix time.
 */
time_t getUnixTime(void);

#endif /* TIME_UTIL_H */