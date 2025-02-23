//smart_clock.c - main file
//Author: Vítor Rodrigues
//Repository: https://github.com/VitorJCRodrigues/smart_clock

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <hardware/gpio.h>
#include <hardware/pio.h>
#include <hardware/spi.h>
#include <hardware/i2c.h>
#include <hardware/timer.h>
#include <hardware/uart.h>
#include <hardware/adc.h>
#include <hardware/rtc.h>

#include <pico/stdlib.h>
#include <pico/binary_info.h>

#include "ws2812.pio.h"

#include "bitdoglab.h"
#include "display.h"
#include "media_player.h"
#include "rtc.h"

#include "imgs/icons.h"
#include "midis/melodies.h"
//#include "midis/alex_underwater.h"
//#include "midis/bohemian_rhapsody.h"
//#include "midis/never_gonna_give_you_up.h"
//#include "midis/cantode.h"
//#include "midis/creep.h"

#define HOLD_TIME_MS 2000      // Time to hold (2 seconds)

// Global Flags
bool isLedImgOn      = false;
bool isBuzzerPlaying = false;
bool triggerAlarm    = false;//true;
bool playAlarm       = false;
bool isDispInverted  = false;
bool freezeDisplay   = false;

int clock_setting = 0;
int alarm_setting = 0;

// Pin configuration
#define DEBOUNCE_DELAY_MS 10   // Debounce delay

bool hasAlarmSet = false;
char alarmLine[] = "";
datetime_t alarm_time = {
    .day=1, .month=1, .year=1970,
    .hour=0, .min=0, .sec=0, 
    .dotw=0
    };

// State machine states
typedef enum {
    IDLE,
    PRESSED,
    HELD
} ButtonState;

typedef struct {
    ButtonState state;
    uint32_t press_time;
    bool isDone;
} Button;

Button btn_a = {
    .state = IDLE, .press_time = 0, .isDone = false,
};

Button btn_b = {
    .state = IDLE, .press_time = 0, .isDone = false,
};

uint8_t scroll_state;
datetime_t current_datetime;

// Joystick thresholds for movement detection
#define JOY_THRESHOLD_LOW  30
#define JOY_THRESHOLD_HIGH 70

// Function to handle changing the clock setting
void handle_datetime_setting() {
    printf("Setting Clock...\n");
    freezeDisplay = true;
    int number = 0;
    bool joystick_left = false;
    bool joystick_right = false;
    bool button_pressed = false;
    absolute_time_t last_move_time = get_absolute_time();
    datetime_t new_datetime = current_datetime;
    
    while (1) {
        // Read joystick
        adc_select_input(1);  // ADC0 (Vrx)
        uint16_t vrx_value = adc_read();
        adc_select_input(0);  // ADC1 (Vry)
        uint16_t vry_value = adc_read();
        bool sw_pressed = gpio_get(BITDOG_JOY_SW) == 0;
        
        // Scale the values to 0 - 100
        int vrx_percent = (vrx_value * 100) / 4095;
        int vry_percent = (vry_value * 100) / 4095;

        // Check if button is pressed
        if (sw_pressed) {
            printf("Button pressed\n");
            if (gpio_get(BITDOG_JOY_SW) == 0) {
                clock_setting++;
                if(clock_setting>6){
                    printf("Setting datetime... [%s] --- > [%s]\n", datetime_to_string(current_datetime), datetime_to_string(new_datetime));
                    current_datetime = new_datetime;
                    rtc_write_datetime(new_datetime);
                    clock_setting = 0;
                    freezeDisplay = false;
                    break;
                }
            }
            sleep_ms(200);
        }

        if (clock_setting==1){
            number = new_datetime.day;
        } else if (clock_setting==2){
            number = new_datetime.month;
        } else if (clock_setting==3){
            number = new_datetime.year;
        } else if (clock_setting==4){
            number = new_datetime.hour;
        } else if (clock_setting==5){
            number = new_datetime.min;
        } else if (clock_setting==6){
            number = new_datetime.sec;
        }
        
        // Handle left movement
        if (vrx_percent < JOY_THRESHOLD_LOW && !joystick_left) {
            joystick_left = true;
            number--;
        } else if (vrx_percent >= JOY_THRESHOLD_LOW) {
            joystick_left = false;
        }

        // Handle right movement
        if (vrx_percent > JOY_THRESHOLD_HIGH && !joystick_right) {
            joystick_right = true;
            number++;
        } else if (vrx_percent <= JOY_THRESHOLD_HIGH) {
            joystick_right = false;
        }

        if (clock_setting==1){
            if (number > 31) number = 1;
            if (number < 1)  number = 31;
            new_datetime.day = number;
            new_datetime.dotw = (int8_t)calculate_new_dotw(new_datetime);
        } else if (clock_setting==2){
            if (number > 12) number = 1;
            if (number < 1)  number = 12;
            new_datetime.month = number;
        } else if (clock_setting==3){
            if (number > 9999) number = 1;
            if (number < 1)  number = 9999;
            new_datetime.year = number;
        } else if (clock_setting==4){
            if (number > 23) number = 0;
            if (number < 0)  number = 23;
            new_datetime.hour = number;
        } else if (clock_setting==5){
            if (number > 59) number = 0;
            if (number < 0)  number = 59;
            new_datetime.min = number;
        } else if (clock_setting==6){
            if (number > 59) number = 0;
            if (number < 0)  number = 59;
            new_datetime.sec = number;
        }

        display_render_datetime(new_datetime, alarmLine);
        sleep_ms(50);
    }
}

// Function to handle setting an alarm time
void handle_alarm_setting() {
    printf("Setting a new Alarm...\n");
    freezeDisplay = true;
    int number = 0;
    bool joystick_left = false;
    bool joystick_right = false;
    bool button_pressed = false;
    absolute_time_t last_move_time = get_absolute_time();
    datetime_t new_datetime = current_datetime;
    
    while (1) {
        adc_select_input(1);  // ADC0 (Vrx)
        uint16_t vrx_value = adc_read();
        adc_select_input(0);  // ADC1 (Vry)
        uint16_t vry_value = adc_read();
        bool sw_pressed = gpio_get(BITDOG_JOY_SW) == 0;
        
        // Scale the values to 0 - 100
        int vrx_percent = (vrx_value * 100) / 4095;
        int vry_percent = (vry_value * 100) / 4095;

        // Check if button is pressed
        if (sw_pressed) {
            printf("Button pressed\n");
            if (gpio_get(BITDOG_JOY_SW) == 0) {
                alarm_setting++;
                if(alarm_setting>6){
                    alarm_setting = 0;
                    if(isAlarmValid(new_datetime, current_datetime))
                    {
                        alarm_time = new_datetime;
                        printf("New alarm set: [%s]\n", datetime_to_string(new_datetime));
                        hasAlarmSet = true;
                        sprintf(alarmLine, " >>>  %02d:%02d:%02d", alarm_time.hour, alarm_time.min, alarm_time.sec);
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

        if (alarm_setting==1){
            number = new_datetime.day;
        } else if (alarm_setting==2){
            number = new_datetime.month;
        } else if (alarm_setting==3){
            number = new_datetime.year;
        } else if (alarm_setting==4){
            number = new_datetime.hour;
        } else if (alarm_setting==5){
            number = new_datetime.min;
        } else if (alarm_setting==6){
            number = new_datetime.sec;
        }
        
        // Handle left movement
        if (vrx_percent < JOY_THRESHOLD_LOW && !joystick_left) {
            joystick_left = true;
            number--;
        } else if (vrx_percent >= JOY_THRESHOLD_LOW) {
            joystick_left = false;
        }

        // Handle right movement
        if (vrx_percent > JOY_THRESHOLD_HIGH && !joystick_right) {
            joystick_right = true;
            number++;
        } else if (vrx_percent <= JOY_THRESHOLD_HIGH) {
            joystick_right = false;
        }

        if (alarm_setting==1){
            if (number > 31) number = 1;
            if (number < 1)  number = 31;
            new_datetime.day = number;
            new_datetime.dotw = (int8_t)calculate_new_dotw(new_datetime);
        } else if (alarm_setting==2){
            if (number > 12) number = 1;
            if (number < 1)  number = 12;
            new_datetime.month = number;
        } else if (alarm_setting==3){
            if (number > 9999) number = 1;
            if (number < 1)  number = 9999;
            new_datetime.year = number;
        } else if (alarm_setting==4){
            if (number > 23) number = 0;
            if (number < 0)  number = 23;
            new_datetime.hour = number;
        } else if (alarm_setting==5){
            if (number > 59) number = 0;
            if (number < 0)  number = 59;
            new_datetime.min = number;
        } else if (alarm_setting==6){
            if (number > 59) number = 0;
            if (number < 0)  number = 59;
            new_datetime.sec = number;
        }

        display_render_datetime(new_datetime, alarmLine);
        sleep_ms(50);
    }
}

// Function to handle button press
bool check_button(uint button_pin, uint hold_time, Button *btn_hdl) {
    bool is_pressed = (gpio_get(button_pin) == 0);
    bool ret = false;

    switch (btn_hdl->state) {
        case IDLE:
            if (is_pressed) {
                sleep_ms(DEBOUNCE_DELAY_MS);  // Add debounce delay here
                if (gpio_get(button_pin) == 0) { // Confirm button is still pressed
                    btn_hdl->press_time = to_ms_since_boot(get_absolute_time());
                    btn_hdl->state = PRESSED;
                    btn_hdl->isDone = false;
                }
            }
            break;

        case PRESSED:
            if (is_pressed) {
                // Button still held, check duration
                uint32_t elapsed_time = to_ms_since_boot(get_absolute_time()) - btn_hdl->press_time;
                if (elapsed_time >= hold_time && !(btn_hdl->isDone)) {
                    btn_hdl->isDone = true; // Mark task as done
                    btn_hdl->state = HELD; // Immediately go to HELD state
                    ret = true;
                }
            } else {
                // Button released before hold time
                btn_hdl->state = IDLE;
            }
            break;

        case HELD:
            if (!is_pressed) {
                // Button released, go back to IDLE
                btn_hdl->state = IDLE;
                btn_hdl->isDone = false; // Reset the task flag
            }
            break;
    }

    return ret;
}

void is_button_a_held()
{
    if(check_button(BITDOG_BTN_A, HOLD_TIME_MS, &btn_a)){
        sleep_ms(DEBOUNCE_DELAY_MS);  // Non-blocking debounce delay
        printf("Button held for %d seconds!\n", HOLD_TIME_MS/1000);
        alarm_setting = 1;
        handle_alarm_setting();
    }
}

void is_button_b_held()
{
    if(check_button(BITDOG_BTN_B, HOLD_TIME_MS, &btn_b)){
        sleep_ms(DEBOUNCE_DELAY_MS);  // Non-blocking debounce delay
        printf("Button held for %d seconds!\n", HOLD_TIME_MS/1000);
        clock_setting = 1;
        handle_datetime_setting();
    }
}

void config_i2c_port(i2c_inst_t * i2cport, int i2c_clock, uint8_t sdapin, uint8_t sclpin)
{
    i2c_init(i2cport, i2c_clock * 1000);
    gpio_set_function(sclpin, GPIO_FUNC_I2C);
    gpio_set_function(sdapin, GPIO_FUNC_I2C);
    gpio_pull_up(sdapin);
    gpio_pull_up(sclpin);
}

char text[4][20] = {
    "",
    "",
    "",
    ""
};

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

/*********************************
 * LED Matrix Handling Functions *
 *********************************/ 

// Function to send RGB data to the LED matrix with brightness control
void send_led_data(const Led_Image *led_image, float brightness) {
    // Clamp brightness to the range [0, 1]
    if (brightness < 0) brightness = 0;
    if (brightness > 1) brightness = 1;

    // Initialize the PIO and WS2812 program
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    // Initialize the WS2812 program
    ws2812_program_init(pio, sm, offset, BITDOG_LED_MTX, 800000, false);

    // Send RGB data for each LED, scaled by brightness
    for (int i = 0; i < NUM_LEDS; i++) {
        uint8_t r = (uint8_t)(led_image->red[i] * brightness);
        uint8_t g = (uint8_t)(led_image->green[i] * brightness);
        uint8_t b = (uint8_t)(led_image->blue[i] * brightness);

        // GRB is the correct order as per indicated in the WS2812 datasheet
        uint32_t pixel_grb = ((uint32_t)r << 8) | ((uint32_t)g << 16) | (uint32_t)b;
        pio_sm_put_blocking(pio, sm, pixel_grb << 8u);
    }
}

void turn_off_leds() {
    // Initialize the PIO and WS2812 program
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    // Initialize the WS2812 program
    ws2812_program_init(pio, sm, offset, BITDOG_LED_MTX, 800000, false);

    // Send 0x000000 (off) to all LEDs
    for (int i = 0; i < NUM_LEDS; i++) {
        pio_sm_put_blocking(pio, sm, 0x000000);
    }
}

/*******************************
 * Joystick Handling Functions *
 * *************************/ 
// Function to read and print joystick values
void read_joystick() {
    // Read ADC values for Vrx and Vry
    adc_select_input(0);  // ADC0 (GPIO 26 for Vrx)
    uint16_t vrx_value = adc_read();
    adc_select_input(1);  // ADC1 (GPIO 27 for Vry)
    uint16_t vry_value = adc_read();

    // Scale the values to 0 - 100
    int vrx_percent = (vrx_value * 100) / 4095;
    int vry_percent = (vry_value * 100) / 4095;

    // Read button state (active low)
    bool sw_pressed = gpio_get(BITDOG_JOY_SW) == 0;

    // Print values
    printf("Vrx: %d%%, Vry: %d%%, SW: %s\n", 
            vrx_percent, 
            vry_percent, 
            sw_pressed ? "Pressed" : "Released");
}

/*******************
 * Timer Callbacks *
 *******************/ 
bool led_timer_callback(struct repeating_timer *t) {
    Led_Image *img;
    if (t->user_data == NULL)
    {
        if(led_images_counter == ICONS_QTT) led_images_counter = 0;
        switch (led_images_counter)
        {
        case CAT:
            img = &cat;
            break;
        case DOG2:
            img = &dog2;
            break;
        case DROP:
            img = &drop;
            break;
        case HEART:
            img = &heart;
            break;
        case PILL:
            img = &pill;
            break;
        case CROSS:
            img = &cross;
            break;
        case SUN:
            img = &sun;
            break;
        case STAR:
            img = &star;
            break;
        case MOON:
            img = &moon;
            break;
        default:
            break;
        }
        printf("led_images_counter: %d\n", led_images_counter);
        if(!isLedImgOn) led_images_counter++;
    }
    else
    {
        img = (Led_Image *)t->user_data; 
    }

    if(triggerAlarm == true && isLedImgOn == false){
        send_led_data(img, 0.1);
        isLedImgOn = true;
    } else {
        turn_off_leds();
        isLedImgOn = false;
    }
    return true;
}

bool buzzer_timer_callback(struct repeating_timer *t) {
    playAlarm = true;
    return true;
}

bool invert_display_timer_callback(struct repeating_timer *t) {
    if(!freezeDisplay)
    {
        if(isDispInverted){
            SSD1306_send_cmd(SSD1306_SET_NORM_DISP);
        } else {
            SSD1306_send_cmd(SSD1306_SET_INV_DISP);
        }
        isDispInverted = !isDispInverted;
    }
}

bool update_display_timer_callback(struct repeating_timer *t) {
    if(!freezeDisplay)
    {
        rtc_read_datetime(&current_datetime);
        display_render_datetime(current_datetime, alarmLine);
    }
}

bool scroll_display_timer_callback(struct repeating_timer *t) {
    if(!freezeDisplay)
    {
        if(scroll_state == 1){
            SSD1306_scroll(true);
        } else if(scroll_state == 2){
            SSD1306_scroll(false);
        } else{
            scroll_state = 0;
        }

        scroll_state++;
    }
}

bool check_alarm_timer_callback(struct repeating_timer *t) {
    uint32_t seconds_remaining;

    if(hasAlarmSet)
    {
        printf("Detectei um alarme programado para %s\n", datetime_to_string(alarm_time));

        seconds_remaining = (datetime_to_timestamp(&alarm_time) - datetime_to_timestamp(&current_datetime));
        printf("Faltam %d segundos para o próximo alarme.\n", seconds_remaining);    
        if(seconds_remaining < 1)
        {
            printf("HORA DO ALARME!! HORA DO ALARME!! HORA DO ALARME!!\n");
            hasAlarmSet = false;
            triggerAlarm = true;
            strcpy(alarmLine, "");
        }
    }
}

/*******************/ 

int main() 
{
    stdio_init_all();

    //Setup Uart0 for debugging printouts
    uart_init(uart1, 115200);
    gpio_set_function(8, GPIO_FUNC_UART);
    gpio_set_function(9, GPIO_FUNC_UART);
    
    struct repeating_timer timer_leds, timer_buzzers, 
                            timer_disp_inv, timer_disp_update, timer_disp_scroll,
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

    // Initialize GPIO for buzzer
    gpio_init(BITDOG_BZZ_A);
    gpio_init(BITDOG_BZZ_B);
    gpio_set_dir(BITDOG_BZZ_A, GPIO_OUT);
    gpio_set_dir(BITDOG_BZZ_B, GPIO_OUT);

    // Initialize GPIO for buttons
    gpio_init(BITDOG_BTN_A);
    gpio_init(BITDOG_BTN_B);
    gpio_set_dir(BITDOG_BTN_A, GPIO_IN);
    gpio_set_dir(BITDOG_BTN_B, GPIO_IN);
    gpio_pull_up(BITDOG_BTN_A); // Enable internal pull-up resistor
    gpio_pull_up(BITDOG_BTN_B); // Enable internal pull-up resistor

    // Initializes Joystick
    adc_init();
    adc_gpio_init(BITDOG_JOY_VRX);
    adc_gpio_init(BITDOG_JOY_VRY);
    gpio_init(BITDOG_JOY_SW);
    gpio_set_dir(BITDOG_JOY_SW, GPIO_IN);
    gpio_pull_up(BITDOG_JOY_SW);

    uint8_t test_byte = 0;
    if (!i2c_write_blocking(BITDOG_RTC_PORT, BITDOG_RTC_ADDR, &test_byte, 1, false)) {
        printf("RTC Not Working");
        return 1;
    }

    Led_Image img = dog2;
    Melody alarmTune = nokia;
    //Midi alarmTune = never_gonna_give_you_up;
    
    uint32_t wait = 10000;
    for (int i = 0; i < alarmTune.length; i++)
        wait += (alarmTune.tempo * 0.004) / alarmTune.durations[i];

    display_init();

    add_repeating_timer_ms(1000, led_timer_callback, NULL, &timer_leds);
    add_repeating_timer_ms(wait, buzzer_timer_callback, NULL, &timer_buzzers);
    add_repeating_timer_ms(2000, invert_display_timer_callback, NULL, &timer_disp_inv);
    add_repeating_timer_ms(1000, update_display_timer_callback, NULL, &timer_disp_update);
    //add_repeating_timer_ms(1500, scroll_display_timer_callback, NULL, &timer_disp_scroll);
    add_repeating_timer_ms(1000, check_alarm_timer_callback, NULL, &timer_check_alarm);

    if(triggerAlarm) playAlarm = true; // Immediatly triggers the melody the first time if alarm is already triggering.

    scroll_state = 0;

    uint8_t start_addr = 0x00;
    while(!i2c_write_blocking(BITDOG_RTC_PORT, BITDOG_RTC_ADDR, &start_addr, 1, true))
    {
        printf("Erro ao indicar registrador inicial.\n");
        sleep_ms(50);
    }

    bool date_set = true;//false;
    while(!date_set)
    {
        if(!rtc_write_datetime(hora, data)){
            printf("ERRO: Nao foi possivel definir datetime!\n");
        } else {
            date_set = true;
        } 
    }

    while(true)
    {
        // Handle detection for Command A (Hold button A) and Command B (Hold Button B)
        if(!triggerAlarm) // Ignore command detection when Alarm event is running
        {
            is_button_a_held();
            is_button_b_held();
        }
        
        // Handle alarm logic
        if(isBuzzerPlaying == false && triggerAlarm == true && playAlarm == true){
            isBuzzerPlaying = true;
            playAlarm = false;
            bazz_player_init(BITDOG_BZZ_B);
            bazz_player_play_melody(BITDOG_BZZ_B, alarmTune);
            //play_midi(BITDOG_BZZ_B, alarmTune);
            bazz_player_stop_tone(BITDOG_BZZ_B);
            gpio_set_function(BITDOG_BZZ_B, GPIO_FUNC_NULL);
            isBuzzerPlaying = false;
            char alarmText[4][20] = {"ALARM!", " ALARM!", "  ALARM!", "ALARM!"};
            display_render_text(alarmText);
        }

        // Check if both buttons are pressed simultaneously
        if (gpio_get(BITDOG_BTN_A) == 0 && gpio_get(BITDOG_BTN_B) == 0 && triggerAlarm == true) {
            sleep_ms(50); // Small delay to debounce buttons
            triggerAlarm = false; // Disable the alarm
            printf("Buttons pressed: Alarm disabled.\n");
        }
    }

    return 0;
}

