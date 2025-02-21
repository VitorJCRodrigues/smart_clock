// bitdoglab.h
// Pinmap for the Smart Clock Project
// Contains definitions for the main resources used in the board
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#ifndef BITDOGLAB_H
#define BITDOGLAB_H

/*******************
 * Real-Time Clock *
 *******************/
#define BITDOG_RTC_PORT     i2c0
#define BITDOG_RTC_ADDR     _u(0x68)
#define BITDOG_RTC_SDA      0           // I²C - Internal Pull-Up
#define BITDOG_RTC_SCL      1           // I²C - Internal Pull-Up

/*******************
 * OLED Display    *
 *******************/
#define BITDOG_DISP_PORT    i2c1
#define BITDOG_DISP_ADDR    _u(0x3C)    // Default I2C address for SSD1306
#define BITDOG_DISP_SDA     14          // I²C - Internal Pull-Up
#define BITDOG_DISP_SCL     15          // I²C - Internal Pull-Up
#define BITDOG_DISP_HEIGHT  32
#define BITDOG_DISP_WIDTH   128

/*******************
 * SPI Pins        *
 *******************/
#define BITDOG_SPI_PORT     spi0
#define BITDOG_SPI_MISO     16
#define BITDOG_SPI_CSN      17
#define BITDOG_SPI_SCK      18
#define BITDOG_SPI_MOSI     19

/*******************
 * Joystick        *
 *******************/
#define BITDOG_JOY_VRY      26
#define BITDOG_JOY_VRX      27
#define BITDOG_JOY_SW       22          // Internal Pull-up

/*******************
 * RGB LEDs        *
 *******************/
#define BITDOG_LED_MTX      7
#define BITDOG_LED_GR       11
#define BITDOG_LED_BL       12
#define BITDOG_LED_RD       13

/*******************
 * Misc.           *
 *******************/
#define BITDOG_BTN_A        5           // Internal Pull-up
#define BITDOG_BTN_B        6           // Internal Pull-up
#define BITDOG_BZZ_A        21
#define BITDOG_BZZ_B        10
#define BITDOG_RESET        30

#endif //BITDOGLAB_H