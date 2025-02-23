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
    if (handler == NULL)
        return false;

    adc_select_input(1); // ADC0 (Vrx)
    uint16_t vrx_value = adc_read();
    adc_select_input(0); // ADC1 (Vry)
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

bool clock_check_button(uint button_pin, uint hold_time, Button *btn_hdl)
{
    bool is_pressed = (gpio_get(button_pin) == 0);
    bool ret = false;

    switch (btn_hdl->state)
    {
    case IDLE:
        if (is_pressed)
        {
            sleep_ms(DEBOUNCE_DELAY_MS); // Add debounce delay here
            if (gpio_get(button_pin) == 0)
            { // Confirm button is still pressed
                btn_hdl->press_time = to_ms_since_boot(get_absolute_time());
                btn_hdl->state = PRESSED;
                btn_hdl->isDone = false;
            }
        }
        break;

    case PRESSED:
        if (is_pressed)
        {
            // Button still held, check duration
            uint32_t elapsed_time = to_ms_since_boot(get_absolute_time()) - btn_hdl->press_time;
            if (elapsed_time >= hold_time && !(btn_hdl->isDone))
            {
                btn_hdl->isDone = true; // Mark task as done
                btn_hdl->state = HELD;  // Immediately go to HELD state
                ret = true;
            }
        }
        else
        {
            // Button released before hold time
            btn_hdl->state = IDLE;
        }
        break;

    case HELD:
        if (!is_pressed)
        {
            // Button released, go back to IDLE
            btn_hdl->state = IDLE;
            btn_hdl->isDone = false; // Reset the task flag
        }
        break;
    }

    return ret;
}

int get_number_from_setting(int alarm_setting, datetime_t new_datetime, int img_selector, int melody_selector)
{
    int number = 0;

    switch (alarm_setting)
    {
    case DAY:
        number = new_datetime.day;
        break;
    case MONTH:
        number = new_datetime.month;
        break;
    case YEAR:
        number = new_datetime.year;
        break;
    case HOUR:
        number = new_datetime.hour;
        break;
    case MIN:
        number = new_datetime.min;
        break;
    case SEC:
        number = new_datetime.sec;
        break;
    case IMG:
        number = img_selector;
        break;
    case MELO:
        number = melody_selector;
        break;
    default:
        break;
    }

    return number;
}