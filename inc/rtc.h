// rtc.h
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#ifndef RTC_H
#define RTC_H

#include "bitdoglab.h"
#include <stdint.h>
#include <stdbool.h>

// Internal Auxiliary Functions
static uint8_t dec_to_bcd(uint8_t dec);
static uint8_t bcd_to_dec(uint8_t val);

/**************************************
 * Real-Time Clock Handling Functions *
 **************************************/ 
// Configura o RTC com os valores passados (time: {hora, minuto, segundo} e
// date: {dia, mês, ano}). Os valores são convertidos para BCD e o byte de
// endereço (0x00) é enviado como primeiro byte.
bool rtc_write_datetime(uint8_t* time, uint8_t* date);

// Lê a data/hora do DS1307 e imprime no Serial USB
void rtc_read_datetime(char output[][20]);

#endif //RTC_H