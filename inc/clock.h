// clock.h
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>
#include <stdint.h>
#include <hardware/rtc.h>

typedef struct {
    int vrx_percent;
    int vry_percent;
    bool sw_pressed;
} Joystick;

typedef enum {
    OFF,
    DAY,
    MONTH,
    YEAR,
    HOUR,
    MIN,
    SEC,
    IMG,
    MELO,
    DONE
} CLOCK_ST;

// State machine states for the Buttons
typedef enum {
    IDLE,
    PRESSED,
    HELD
} ButtonState;

/// Data Handler for the Buttons
typedef struct {
    ButtonState state;
    uint32_t press_time;
    bool isDone;
} Button;


// Joystick thresholds for movement detection
#define JOY_THRESHOLD_LOW  30
#define JOY_THRESHOLD_HIGH 70

// Button debounce delay
#define DEBOUNCE_DELAY_MS 200   

bool clock_read_joystick(Joystick *handler);

void clock_init_button(uint BUTTON_PIN);

void clock_init_joystick(uint JOY_X_PIN, uint JOY_Y_PIN, uint JOY_SW_PIN);

// Function to handle button press
bool clock_check_button(uint button_pin, uint hold_time, Button *btn_hdl);

int get_number_from_setting(int alarm_setting, datetime_t new_datetime, int img_selector, int melody_selector);

#endif //CLOCK_H