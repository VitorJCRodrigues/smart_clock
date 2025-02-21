// rtc.h
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#ifndef RTC_H
#define RTC_H

#include "bitdoglab.h"
#include <stdint.h>
#include <stdbool.h>
#include <hardware/rtc.h>

// Internal Auxiliary Functions
static bool is_leap_year(int year);
static int days_in_month(int year, int month);
static uint8_t dec_to_bcd(uint8_t dec);
static uint8_t bcd_to_dec(uint8_t val);
static uint8_t calculate_new_dotw(datetime_t old_datetime, datetime_t new_datetime);
static uint8_t* datetime_to_uint(datetime_t datetime);
static datetime_t uint_to_datetime(uint8_t *buffer);

/**************************************
 * Real-Time Clock Handling Functions *
 **************************************/ 
// Configura o RTC com os valores passados utilizando o 
// formato datetime_t. Os valores são convertidos para BCD
// e o byte de endereço (0x00) é enviado como primeiro byte.
bool rtc_write_datetime(datetime_t datetime);

// Lê a data/hora do DS1307 e imprime no Serial USB
void rtc_read_datetime(datetime_t *datetime);


uint32_t datetime_to_timestamp(datetime_t *dt);

uint8_t calculate_new_dotw(datetime_t old_datetime, datetime_t new_datetime);

#endif //RTC_H