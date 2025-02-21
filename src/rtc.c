// rtc.c
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#include "rtc.h"
#include "bitdoglab.h"

#include <stdio.h>
#include <string.h>
#include <hardware/i2c.h>

static uint8_t dec_to_bcd(uint8_t dec) {
    return ((dec / 10) << 4) | (dec % 10);
}

static uint8_t bcd_to_dec(uint8_t val) {
    return ((val / 16 * 10) + (val % 16));
}

bool rtc_write_datetime(uint8_t* time, uint8_t* date) {
    printf("SETTING DATE TIME\n");
    uint8_t datetime[] = {
        0x00,                       // Byte de endereço: registrador 0x00
        dec_to_bcd(time[2]) & 0x7F, // Segundos (& bit CH = 0)
        dec_to_bcd(time[1]),        // Minutos
        dec_to_bcd(time[0]),        // Horas (formato 24h)
        0x00,                       // Dia da semana
        dec_to_bcd(date[2]),        // Dia
        dec_to_bcd(date[1]),        // Mês
        dec_to_bcd(date[0])         // Ano (últimos dois dígitos)
    };

    int result = i2c_write_blocking(BITDOG_RTC_PORT, BITDOG_RTC_ADDR, datetime,
                                    sizeof(datetime), false);
    printf("result: %d\n", result);
    if (result == sizeof(datetime)) {
        printf("RTC configurado para %02d/%02d/20%02d - %02d:%02d:%02d\n",
               date[0], date[1], date[2],
               time[0], time[1], time[2]);
        return true;
    } else {
        printf("Erro ao configurar o RTC!\n");
        return false;
    }
}

void rtc_read_datetime(char output[][20]) {
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

    sprintf(data, "%02d/%02d/%02d", 
        bcd_to_dec(buffer[4]),  // Day
        bcd_to_dec(buffer[5]),  // Month
        bcd_to_dec(buffer[6]) + 2000); // Year + 2000

    sprintf(hora, "%02d:%02d:%02d", 
            bcd_to_dec(buffer[2]),  // Hour
            bcd_to_dec(buffer[1]),  // Minute
            bcd_to_dec(buffer[0])); // Second

    int wday_ = bcd_to_dec(buffer[3]);

    if (wday_ == 0){
        strcpy(wday, "Sunday");
    } else if (wday_ == 1){
        strcpy(wday, "Monday");
    } else if (wday_ == 2){
        strcpy(wday, "Tuesday");
    } else if (wday_ == 3){
        strcpy(wday, "Wednesday");
    } else if (wday_ == 4){
        strcpy(wday, "Thursday");
    } else if (wday_ == 5){
        strcpy(wday, "Friday");
    } else if (wday_ == 6){
        strcpy(wday, "Saturday");
    } else if (wday_ == 7){
        strcpy(wday, "Octofeira");
    }

    strcpy(output[0], data);
    strcpy(output[1], hora);
    strcpy(output[2], wday);
}