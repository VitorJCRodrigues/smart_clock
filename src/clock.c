// clock.c
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#include "clock.h"
#include "bitdoglab.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <hardware/adc.h>
#include <hardware/gpio.h>
#include <pico/stdlib.h>

bool clock_read_joystick(Joystick *handler)
{
    if(handler == NULL) return false;
    
    adc_select_input(1);  // ADC0 (Vrx)
    uint16_t vrx_value = adc_read();
    adc_select_input(0);  // ADC1 (Vry)
    uint16_t vry_value = adc_read();
    handler->sw_pressed = gpio_get(BITDOG_JOY_SW) == 0;
        
    // Scale the values to 0 - 100
    handler->vrx_percent = (vrx_value * 100) / 4095;
    handler->vry_percent = (vry_value * 100) / 4095;

    return true;
}

void clock_init_button(uint BUTTON_PIN)
{
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // Enable internal pull-up resistor
    gpio_set_input_hysteresis_enabled(BUTTON_PIN, true);
}

void clock_init_joystick(uint JOY_X_PIN, uint JOY_Y_PIN, uint JOY_SW_PIN)
{
    adc_init();
    adc_gpio_init(JOY_X_PIN);
    adc_gpio_init(JOY_Y_PIN);
    gpio_init(JOY_SW_PIN);
    gpio_set_dir(JOY_SW_PIN, GPIO_IN);
    gpio_pull_up(JOY_SW_PIN);
}
