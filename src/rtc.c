// rtc.c
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#include "rtc.h"
#include "bitdoglab.h"

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <hardware/i2c.h>
#include <hardware/rtc.h>

#define DATETIME_BUFFER_SIZE 9

static bool is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

static int days_in_month(int year, int month) {
    static const int days_per_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days_per_month[month - 1];
}

static uint8_t dec_to_bcd(uint8_t dec) {
    return ((dec / 10) << 4) | (dec % 10);
}

static uint8_t bcd_to_dec(uint8_t val) {
    return ((val / 16 * 10) + (val % 16));
}

static uint8_t* datetime_to_uint(datetime_t datetime)
{
    static uint8_t buffer[DATETIME_BUFFER_SIZE];

    buffer[0] = 0x00;                            // Byte de endereço: registrador 0x00
    buffer[1] = dec_to_bcd(datetime.sec) & 0x7F;  // Segundos (& bit CH = 0)
    buffer[2] = dec_to_bcd(datetime.min);         // Minutos
    buffer[3] = dec_to_bcd(datetime.hour);        // Horas (formato 24h)
    buffer[4] = dec_to_bcd(datetime.dotw);        // Dia da semana
    buffer[5] = dec_to_bcd(datetime.day);         // Dia
    buffer[6] = dec_to_bcd(datetime.month);       // Mês
    buffer[7] = dec_to_bcd(datetime.year-2000);   // Ano (últimos dois dígitos)

    return buffer;
}

// Calculate absolute difference in seconds
static int calculate_day_difference(uint32_t timestamp1, uint32_t timestamp2) {

    uint32_t diff_seconds = (timestamp1 > timestamp2) ? 
                             (timestamp1 - timestamp2) : 
                             (timestamp2 - timestamp1);
    
    // Convert seconds to days (1 day = 86400 seconds)
    return diff_seconds / 86400;
}

static datetime_t uint_to_datetime(uint8_t *buffer)
{
    datetime_t datetime = {
        .day   = bcd_to_dec(buffer[4]),             // Day
        .month = bcd_to_dec(buffer[5]),             // Month
        .year  = (bcd_to_dec(buffer[6]) + 2000),    // Year + 2000
        .hour  = bcd_to_dec(buffer[2]),             // Hour
        .min   = bcd_to_dec(buffer[1]),             // Minute
        .sec   = bcd_to_dec(buffer[0]),             // Second
        .dotw  = bcd_to_dec(buffer[3])
    };

    return datetime;
}

bool rtc_write_datetime(datetime_t dt) {
    printf("SETTING DATE TIME: %s\n", datetime_to_string(dt));
    uint8_t* buf = datetime_to_uint(dt);
    
    int result = i2c_write_blocking(BITDOG_RTC_PORT, BITDOG_RTC_ADDR, buf,
                                    DATETIME_BUFFER_SIZE, false);
    if (result == DATETIME_BUFFER_SIZE) {
        printf("RTC configurado para %02d/%02d/%04d - %02d:%02d:%02d\n",
               dt.day,  dt.month, dt.year,
               dt.hour, dt.min,   dt.sec);
        return true;
    } else {
        printf("Erro ao configurar o RTC!\n");
        return false;
    }
}

void rtc_read_datetime(datetime_t *datetime) {
    uint8_t buffer[7];
    uint8_t start_addr = 0x00;
    char data[20], hora[20], wday[20];
    
    if(!i2c_write_blocking(BITDOG_RTC_PORT, BITDOG_RTC_ADDR, &start_addr, 1, true))
    {
        printf("Erro ao indicar registrador inicial.\n");
        return;
    }

    if (i2c_read_blocking(BITDOG_RTC_PORT, BITDOG_RTC_ADDR, buffer, 7, false) != 7) 
    {
        printf("Erro na leitura do RTC!\n");
        return;
    }

    datetime_t current_datetime = uint_to_datetime(buffer);
    
    // Print time
    //    printf("Date: %04d-%02d-%02d Time: %02d:%02d:%02d\n",
    //           current_datetime.year, current_datetime.month, current_datetime.day,
    //           current_datetime.hour, current_datetime.min, current_datetime.sec);

    *datetime = current_datetime;
}

uint32_t datetime_to_timestamp(datetime_t *dt) {
    uint32_t timestamp = 0;
    int year, month;
    
    // Add seconds for complete years
    for (year = 1970; year < dt->year; year++) {
        timestamp += (is_leap_year(year) ? 366 : 365) * 86400;
    }
    
    // Add seconds for complete months
    for (month = 1; month < dt->month; month++) {
        timestamp += days_in_month(dt->year, month) * 86400;
    }
    
    // Add seconds for complete days
    timestamp += (dt->day - 1) * 86400;
    
    // Add seconds for complete hours, minutes, and seconds
    timestamp += dt->hour * 3600;
    timestamp += dt->min * 60;
    timestamp += dt->sec;
    
    return timestamp;
}

// Function to convert a timestamp to datetime_t
datetime_t timestamp_to_datetime(uint32_t timestamp) {
    datetime_t dt;

    // Constants for time calculations
    const int seconds_per_minute = 60;
    const int seconds_per_hour = 3600;
    const int seconds_per_day = 86400;

    // Calculate the number of days since the Unix epoch (January 1, 1970)
    uint32_t days_since_epoch = timestamp / seconds_per_day;
    dt.sec = timestamp % seconds_per_minute;
    dt.min = (timestamp % seconds_per_hour) / seconds_per_minute;
    dt.hour = (timestamp % seconds_per_day) / seconds_per_hour;

    // Calculate the day of the week (0 = Sunday, 6 = Saturday)
    dt.dotw = (days_since_epoch + 4) % 7; // January 1, 1970, was a Thursday (4)

    // Calculate the year and day of the year
    int year = 1970;
    while (days_since_epoch >= 365 + is_leap_year(year)) {
        days_since_epoch -= 365 + is_leap_year(year);
        year++;
    }
    dt.year = year;

    // Calculate the month and day of the month
    int month = 1;
    while (days_since_epoch >= days_in_month(month, year)) {
        days_since_epoch -= days_in_month(month, year);
        month++;
    }
    dt.month = month;
    dt.day = days_since_epoch + 1; // Days are 1-based

    return dt;
}

uint8_t calculate_new_dotw(datetime_t new_dt)
{
    uint32_t new_timestamp = datetime_to_timestamp(&new_dt);
    uint8_t new_day_of_week = (new_timestamp % (7 * 86400)) + DOTW_TIMESTAMP_REF - 1;
    if (new_day_of_week <= 0) new_day_of_week += 7;

    return new_day_of_week;
}

bool isAlarmValid(datetime_t alarm_datetime, datetime_t current_datetime)
{
    uint32_t alarm_ts = datetime_to_timestamp(&alarm_datetime);
    uint32_t cur_ts   = datetime_to_timestamp(&current_datetime);

    return (alarm_ts > cur_ts);
}

char* datetime_to_string(datetime_t dt)
{
    static char output[20];
    sprintf(output, "%02d-%02d-%04d %02d:%02d:%02d", dt.day, dt.month, dt.year, 
                                                    dt.hour, dt.min, dt.sec);
    return output;
}

void rtc_connect()
{
    uint8_t start_addr = 0x00;
    while(!i2c_write_blocking(BITDOG_RTC_PORT, BITDOG_RTC_ADDR, &start_addr, 1, true))
    {
        printf("Erro ao indicar registrador inicial.\n");
        sleep_ms(50);
    }
}