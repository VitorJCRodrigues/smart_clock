// smart_clock.c - main file
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <hardware/gpio.h>
#include <hardware/i2c.h>
#include <hardware/timer.h>
#include <hardware/uart.h>
#include <hardware/rtc.h>

#include <pico/stdlib.h>
#include <pico/binary_info.h>

#include "bitdoglab.h"
#include "clock.h"
#include "display.h"
#include "media_player.h"
#include "pixel_leds.h"
#include "rtc.h"

// #include "midis/alex_underwater.h"
// #include "midis/bohemian_rhapsody.h"
// #include "midis/never_gonna_give_you_up.h"
// #include "midis/cantode.h"
// #include "midis/creep.h"

#define HOLD_TIME_MS 3000 // Time to hold

typedef struct
{
    int index;
    int setting;
    bool isSet;
    bool trigger;
    char textLine[32];
    datetime_t datetime;
    Led_Image *img;
    Melody *tune;
} Alarm;

// Global Flags
bool isLedImgOn = false;
bool playAlarm = false;
bool isDispInverted = false;
bool freezeDisplay = false;
bool hasAlarmSet = false;

// Global Variables
int clock_setting = 0;
datetime_t current_datetime;

Alarm alarm1 = {
    .index = 1,
    .setting = 0,
    .isSet = false,
    .trigger = false,
    .textLine = "",
    .datetime = {
        .day = 1, .month = 1, .year = 1970, .hour = 0, .min = 0, .sec = 0, .dotw = 4},
    .img = NULL,
    .tune = NULL,
};

Alarm alarm2 = {
    .index = 2,
    .setting = 0,
    .isSet = false,
    .trigger = false,
    .textLine = "",
    .datetime = {
        .day = 1, .month = 1, .year = 1970, .hour = 0, .min = 0, .sec = 0, .dotw = 4},
    .img = NULL,
    .tune = NULL,
};

Button buttonA = {
    .state = IDLE,
    .press_time = 0,
    .isDone = false,
};

Button buttonB = {
    .state = IDLE,
    .press_time = 0,
    .isDone = false,
};

// Text Labels for the pixel arts (icons -> i_names) and songs (melodies -> m_names).
char i_names[ICONS_QTT + 1][16] = {"Cat", "Dog", "Water", "Heart", "Pill", "Hospital", "Sun", "Star", "Moon", ""};
char m_names[MELO_QTT + 1][16] = {"Pacman", "Nokia", "Tetris", ""};

// Function to handle changing the clock setting
void handle_datetime_setting()
{
    printf("Setting Clock...\n");
    freezeDisplay = true;
    int number = 0;
    bool joystick_left = false;
    bool joystick_right = false;
    absolute_time_t last_move_time = get_absolute_time();
    datetime_t new_datetime = current_datetime;
    Joystick joy_hdl;

    while (1)
    {
        if (!clock_read_joystick(&joy_hdl))
        {
            printf("Failed to read joystick data.\n");
        }

        // Check if button is pressed
        if (joy_hdl.sw_pressed)
        {
            printf("Button pressed\n");
            if (gpio_get(BITDOG_JOY_SW) == 0)
            {
                clock_setting++;
                if (clock_setting == IMG)
                {
                    printf("Setting datetime... [%s] --- > [%s]\n", datetime_to_string(current_datetime), datetime_to_string(new_datetime));
                    current_datetime = new_datetime;
                    rtc_write_datetime(new_datetime);
                    clock_setting = OFF;
                    freezeDisplay = false;
                    break;
                }
            }
            sleep_ms(200);
        }

        number = get_number_from_setting(clock_setting, new_datetime, 0, 0);

        // Handle left movement
        if (joy_hdl.vrx_percent < JOY_THRESHOLD_LOW && !joystick_left)
        {
            joystick_left = true;
            number--;
        }
        else if (joy_hdl.vrx_percent >= JOY_THRESHOLD_LOW)
        {
            joystick_left = false;
        }

        // Handle right movement
        if (joy_hdl.vrx_percent > JOY_THRESHOLD_HIGH && !joystick_right)
        {
            joystick_right = true;
            number++;
        }
        else if (joy_hdl.vrx_percent <= JOY_THRESHOLD_HIGH)
        {
            joystick_right = false;
        }

        switch (clock_setting)
        {
        case DAY:
            if (number > 31)
                number = 1;
            if (number < 1)
                number = 31;
            new_datetime.day = number;
            break;
        case MONTH:
            if (number > 12)
                number = 1;
            if (number < 1)
                number = 12;
            new_datetime.month = number;
            break;
        case YEAR:
            if (number > 9999)
                number = 1;
            if (number < 1)
                number = 9999;
            new_datetime.year = number;
            break;
        case HOUR:
            if (number > 23)
                number = 0;
            if (number < 0)
                number = 23;
            new_datetime.hour = number;
            break;
        case MIN:
            if (number > 59)
                number = 0;
            if (number < 0)
                number = 59;
            new_datetime.min = number;
            break;
        case SEC:
            if (number > 59)
                number = 0;
            if (number < 0)
                number = 59;
            new_datetime.sec = number;
            new_datetime.dotw = (int8_t)calculate_new_dotw(new_datetime);
            break;
        default:
            printf("Invalid clock setting: %d\n", clock_setting);
            break;
        }

        display_render_datetime(new_datetime, alarm2.textLine, alarm1.textLine);
        sleep_ms(50);
    }
}

// Function to handle setting an alarm time
void handle_alarm_setting()
{
    printf("Setting a new Alarm...\n");
    freezeDisplay = true;
    int number = 0;
    bool joystick_left = false;
    bool joystick_right = false;
    absolute_time_t last_move_time = get_absolute_time();
    datetime_t new_datetime = current_datetime;
    Joystick joy_hdl;
    int img_selector = ICONS_QTT;
    int melody_selector = MELO_QTT;
    char imgName[16] = "";
    char melodyName[16] = "";

    // Determine which alarm to set
    Alarm *current_alarm = (alarm1.isSet) ? &alarm2 : &alarm1;
    bool is_alarm1_busy = alarm1.isSet;

    while (1)
    {
        if (!clock_read_joystick(&joy_hdl))
        {
            printf("Failed to read joystick data.\n");
        }

        // Check if button is pressed
        if (joy_hdl.sw_pressed)
        {
            printf("Button pressed\n");
            if (gpio_get(BITDOG_JOY_SW) == 0)
            {
                current_alarm->setting++;

                if (current_alarm->setting == DONE)
                {
                    current_alarm->setting = DAY;
                    if (isAlarmValid(new_datetime, current_datetime))
                    {
                        current_alarm->setting = OFF;
                        current_alarm->datetime = new_datetime;
                        printf("New 1 alarm set: [%s]\n", datetime_to_string(new_datetime));
                        current_alarm->isSet = true;
                        hasAlarmSet = true;
                        snprintf(current_alarm->textLine, sizeof(current_alarm->textLine), "%d>>>  %02d:%02d:%02d", current_alarm->index, current_alarm->datetime.hour, current_alarm->datetime.min, current_alarm->datetime.sec);
                        display_render_datetime(new_datetime, alarm2.textLine, alarm1.textLine);
                        current_alarm->img = pixel_leds_art_select(img_selector);
                        current_alarm->tune = bazz_player_melody_select(melody_selector);
                        freezeDisplay = false;
                        bazz_player_beep(BITDOG_BZZ_B, NOTE_A5, 150);
                        break;
                    }
                    printf("Alarme Invalido! Insira uma data posterior!\n");
                    bazz_player_beep(BITDOG_BZZ_B, NOTE_A1, 100);
                }
            }
            sleep_ms(200);
        }

        number = get_number_from_setting(current_alarm->setting, new_datetime, img_selector, melody_selector);

        // Handle left movement
        if (joy_hdl.vrx_percent < JOY_THRESHOLD_LOW && !joystick_left)
        {
            joystick_left = true;
            number--;
        }
        else if (joy_hdl.vrx_percent >= JOY_THRESHOLD_LOW)
        {
            joystick_left = false;
        }

        // Handle right movement
        if (joy_hdl.vrx_percent > JOY_THRESHOLD_HIGH && !joystick_right)
        {
            joystick_right = true;
            number++;
        }
        else if (joy_hdl.vrx_percent <= JOY_THRESHOLD_HIGH)
        {
            joystick_right = false;
        }

        switch (current_alarm->setting)
        {
        case DAY:
            if (number > 31)
                number = 1;
            if (number < 1)
                number = 31;
            new_datetime.day = number;
            break;
        case MONTH:
            if (number > 12)
                number = 1;
            if (number < 1)
                number = 12;
            new_datetime.month = number;
            break;
        case YEAR:
            if (number > 9999)
                number = 1;
            if (number < 1)
                number = 9999;
            new_datetime.year = number;
            break;
        case HOUR:
            if (number > 23)
                number = 0;
            if (number < 0)
                number = 23;
            new_datetime.hour = number;
            break;
        case MIN:
            if (number > 59)
                number = 0;
            if (number < 0)
                number = 59;
            new_datetime.min = number;
            break;
        case SEC:
            if (number > 59)
                number = 0;
            if (number < 0)
                number = 59;
            new_datetime.sec = number;
            new_datetime.dotw = (int8_t)calculate_new_dotw(new_datetime);
            break;
        case IMG:
            if (number >= ICONS_QTT)
                number = 0;
            if (number < 0)
                number = ICONS_QTT - 1;
            img_selector = number;
            break;
        case MELO:
            if (number >= MELO_QTT)
                number = 0;
            if (number < 0)
                number = MELO_QTT - 1;
            melody_selector = number;
            break;
        default:
            printf("Invalid alarm setting: %d\n", current_alarm->setting);
            break;
        }

        sprintf(imgName, "%s", i_names[img_selector]);
        sprintf(melodyName, "%s", m_names[melody_selector]);

        display_render_datetime(new_datetime, imgName, melodyName);
        sleep_ms(50);
    }
}

void is_button_a_held(uint32_t hold_time_ms)
{
    if (clock_check_button(BITDOG_BTN_A, hold_time_ms, &buttonA))
    {
        sleep_ms(DEBOUNCE_DELAY_MS); // Non-blocking debounce delay
        printf("Button held for %d seconds!\n", hold_time_ms / 1000);
        alarm1.setting = 1;
        handle_alarm_setting();
    }
}

void is_button_b_held(uint32_t hold_time_ms)
{
    if (clock_check_button(BITDOG_BTN_B, hold_time_ms, &buttonB))
    {
        sleep_ms(DEBOUNCE_DELAY_MS); // Non-blocking debounce delay
        printf("Button held for %d seconds!\n", hold_time_ms / 1000);
        clock_setting = 1;
        handle_datetime_setting();
    }
}

void config_i2c_port(i2c_inst_t *i2cport, int i2c_clock, uint8_t sdapin, uint8_t sclpin)
{
    i2c_init(i2cport, i2c_clock * 1000);
    gpio_set_function(sclpin, GPIO_FUNC_I2C);
    gpio_set_function(sdapin, GPIO_FUNC_I2C);
    gpio_pull_up(sdapin);
    gpio_pull_up(sclpin);
}

void display_init()
{
    calc_render_area_buflen(&frame_area);
    display_clear(&frame_area);
    display_play_transition(&frame_area);
    bazz_player_init(BITDOG_BZZ_B);
    bazz_player_play_tone(BITDOG_BZZ_B, NOTE_B2);
    sleep_ms(100);
    bazz_player_stop_tone(BITDOG_BZZ_B);
    sleep_ms(1000);
}

/*******************
 * Timer Callbacks *
 *******************/
bool led_timer_callback(struct repeating_timer *t)
{
    if (alarm1.trigger == true && isLedImgOn == false)
    {
        pixel_leds_send_data(alarm1.img, 0.1);
        isLedImgOn = true;
    }
    else if (alarm2.trigger == true && isLedImgOn == false)
    {
        pixel_leds_send_data(alarm2.img, 0.1);
        isLedImgOn = true;
    }
    else
    {
        pixel_leds_turn_off();
        isLedImgOn = false;
    }
    return true;
}

bool buzzer_timer_callback(struct repeating_timer *t)
{
    playAlarm = true;
    return true;
}

bool invert_display_timer_callback(struct repeating_timer *t)
{
    if (alarm1.trigger || alarm2.trigger)
    {
        if (isDispInverted)
        {
            SSD1306_send_cmd(SSD1306_SET_NORM_DISP);
        }
        else
        {
            SSD1306_send_cmd(SSD1306_SET_INV_DISP);
        }
        isDispInverted = !isDispInverted;
    }
}

bool update_display_timer_callback(struct repeating_timer *t)
{
    if (!freezeDisplay)
    {
        rtc_read_datetime(&current_datetime);
        display_render_datetime(current_datetime, alarm2.textLine, alarm1.textLine);
    }
}

bool check_alarm_timer_callback(struct repeating_timer *t)
{
    uint32_t seconds_remaining;

    if (hasAlarmSet)
    {
        if (alarm1.isSet)
        {
            printf("Detectei um alarme programado para %s\n", datetime_to_string(alarm1.datetime));
            seconds_remaining = (datetime_to_timestamp(&alarm1.datetime) - datetime_to_timestamp(&current_datetime));
            printf("Faltam %d segundos para o próximo alarme.\n", seconds_remaining);
            if (seconds_remaining < 1)
            {
                // printf("HORA DO ALARME!! HORA DO ALARME!! HORA DO ALARME!!\n");
                alarm1.isSet = false;
                alarm1.trigger = true;
                strcpy(alarm1.textLine, "");
                if (!alarm2.isSet)
                    hasAlarmSet = false;
            }
        }

        if (alarm2.isSet)
        {
            printf("Detectei um alarme programado para %s\n", datetime_to_string(alarm2.datetime));
            seconds_remaining = (datetime_to_timestamp(&alarm2.datetime) - datetime_to_timestamp(&current_datetime));
            printf("Faltam %d segundos para o próximo alarme.\n", seconds_remaining);
            if (seconds_remaining < 1)
            {
                // printf("HORA DO ALARME!! HORA DO ALARME!! HORA DO ALARME!!\n");
                alarm2.isSet = false;
                alarm2.trigger = true;
                strcpy(alarm2.textLine, "");
                if (!alarm1.isSet)
                    hasAlarmSet = false;
            }
        }
    }
}

/*******************/

int main()
{
    stdio_init_all();

    // Setup Uart0 for debugging printouts
    uart_init(uart1, 115200);
    gpio_set_function(8, GPIO_FUNC_UART);
    gpio_set_function(9, GPIO_FUNC_UART);

    struct repeating_timer timer_leds, timer_buzzers,
        timer_disp_inv, timer_disp_update,
        timer_check_alarm;

    // useful information for picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
    bi_decl(bi_program_description("SSD1306 OLED driver I2C example for the Raspberry Pi Pico"));

    // I2C is "open drain", pull ups to keep signal high when no data is being
    // I2C Initialisation. Using it at 400Khz (Default).
    config_i2c_port(BITDOG_DISP_PORT, SSD1306_I2C_CLK, BITDOG_DISP_SDA, BITDOG_DISP_SCL);
    config_i2c_port(BITDOG_RTC_PORT, 400, BITDOG_RTC_SDA, BITDOG_RTC_SCL);

    // Run through the complete SSD1306 initialization process
    SSD1306_init();

    // Initialize RTC
    rtc_connect();

    // Initialize GPIO for buzzer
    gpio_init(BITDOG_BZZ_A);
    gpio_init(BITDOG_BZZ_B);
    gpio_set_dir(BITDOG_BZZ_A, GPIO_OUT);
    gpio_set_dir(BITDOG_BZZ_B, GPIO_OUT);

    // Initialize GPIO for buttons
    clock_init_button(BITDOG_BTN_A);
    clock_init_button(BITDOG_BTN_B);

    // Initialize Joystick
    clock_init_joystick(BITDOG_JOY_VRX, BITDOG_JOY_VRY, BITDOG_JOY_SW);

    alarm1.tune = melody_init();
    alarm2.tune = melody_init();
    // Midi alarm1.tune = alex_underwater;

    uint32_t wait = 5000;
    for (int i = 0; i < alarm1.tune->length; i++)
        wait += (alarm1.tune->tempo * 0.004) / alarm1.tune->durations[i];

    display_init();

    add_repeating_timer_ms(1000, led_timer_callback, NULL, &timer_leds);
    add_repeating_timer_ms(wait, buzzer_timer_callback, NULL, &timer_buzzers);
    add_repeating_timer_ms(2000, invert_display_timer_callback, NULL, &timer_disp_inv);
    add_repeating_timer_ms(1000, update_display_timer_callback, NULL, &timer_disp_update);
    add_repeating_timer_ms(1000, check_alarm_timer_callback, NULL, &timer_check_alarm);

    if (alarm1.trigger || alarm2.trigger)
        playAlarm = true; // Immediatly triggers the melody the first time if alarm is already triggering.

    while (true)
    {
        // Handle alarm logic
        if (!bazz_player_is_melody_playing() && alarm1.trigger && playAlarm)
        {
            playAlarm = false;
            printf("Starting alarm melody\n");
            bazz_player_play_melody(BITDOG_BZZ_B, *alarm1.tune);
            // play_midi(BITDOG_BZZ_B, alarm1.tune);
            freezeDisplay = true;
            char alarmText[4][20] = {"      ALARM!", "         ALARM!", "    ALARM!", "ALARM!"};
            display_render_text(alarmText);
        }
        else if (!bazz_player_is_melody_playing() && alarm2.trigger && playAlarm)
        {
            playAlarm = false;
            printf("Starting alarm melody\n");
            bazz_player_play_melody(BITDOG_BZZ_B, *alarm2.tune);
            // play_midi(BITDOG_BZZ_B, alarm2.tune);
            freezeDisplay = true;
            char alarmText[4][20] = {"      ALARM!", "         ALARM!", "    ALARM!", "ALARM!"};
            display_render_text(alarmText);
        }

        // Handle detection for Command A (Hold button A) and Command B (Hold Button B)
        is_button_a_held(HOLD_TIME_MS);
        is_button_b_held(HOLD_TIME_MS);

        // Check if both buttons are pressed simultaneously
        if (gpio_get(BITDOG_BTN_A) == 0 && gpio_get(BITDOG_BTN_B) == 0 && (alarm1.trigger || alarm2.trigger))
        {
            if (alarm1.trigger)
                alarm1.trigger = false; // Disable the alarm
            if (alarm2.trigger)
                alarm2.trigger = false; // Disable the alarm
            freezeDisplay = false;
            printf("Buttons pressed: Alarm disabled.\n");
            bazz_player_stop_melody();
            SSD1306_send_cmd(SSD1306_SET_NORM_DISP);
        }
    }

    return 0;
}
