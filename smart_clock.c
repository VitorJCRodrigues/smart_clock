//smart_clock.c - main file
//Author: Vítor Rodrigues
//Repository: https://github.com/VitorJCRodrigues/smart_clock

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include <hardware/gpio.h>
#include <hardware/pio.h>
#include <hardware/spi.h>
#include <hardware/i2c.h>
#include <hardware/timer.h>
#include <hardware/uart.h>
#include <hardware/adc.h>

#include <pico/stdlib.h>
#include "ws2812.pio.h"

#include "bitdoglab.h"
// Midis included
#include "display.h"
#include "media_player.h"
#include "rtc.h"
#include "midis/melodies.h"
//#include "midis/alex_underwater.h"
//#include "midis/bohemian_rhapsody.h"
//#include "midis/never_gonna_give_you_up.h"
//#include "midis/cantode.h"
//#include "midis/creep.h"

// Imgs included
#include "imgs/icons.h"

#include "pico/binary_info.h"

#define HOLD_TIME_MS 3000      // Time to hold (5 seconds)

// Global Flags
bool isLedImgOn      = false;
bool isBuzzerPlaying = false;
bool triggerAlarm    = false;//true;
bool playAlarm       = false;
bool isDispInverted  = false;

#include "pico/stdlib.h"

// Pin configuration
#define DEBOUNCE_DELAY_MS 10   // Debounce delay

// State machine states
typedef enum {
    IDLE,
    PRESSED,
    HELD
} ButtonState;

ButtonState button_state = IDLE;
uint32_t press_start_time = 0;
uint8_t scroll_state;

// Function to handle button press
void check_button() {
    // Check if button is pressed (active low)
    bool is_pressed = (gpio_get(BITDOG_BTN_B) == 0);

    switch (button_state) {
        case IDLE:
            if (is_pressed) {
                // Button just pressed, start timing
                press_start_time = to_ms_since_boot(get_absolute_time());
                button_state = PRESSED;
            }
            break;

        case PRESSED:
            if (is_pressed) {
                // Button still held, check duration
                uint32_t elapsed_time = to_ms_since_boot(get_absolute_time()) - press_start_time;
                if (elapsed_time >= HOLD_TIME_MS) {
                    // Button held long enough
                    printf("Button held for 5 seconds!\n");
                    button_state = HELD;
                }
            } else {
                // Button released before hold time
                button_state = IDLE;
            }
            break;

        case HELD:
            if (!is_pressed) {
                // Button released, go back to IDLE
                button_state = IDLE;
            }
            break;
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

        uint32_t rgb = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
        pio_sm_put_blocking(pio, sm, rgb);
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
    Led_Image *img = (Led_Image *)t->user_data; 
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
    if(isDispInverted){
        SSD1306_send_cmd(SSD1306_SET_NORM_DISP);
    } else {
        SSD1306_send_cmd(SSD1306_SET_INV_DISP);
    }
    isDispInverted = !isDispInverted;
}

bool update_display_timer_callback(struct repeating_timer *t) {
    read_rtc_datetime(text);
    render_text(text);
}

bool scroll_display_timer_callback(struct repeating_timer *t) {
    if(scroll_state == 1){
        SSD1306_scroll(true);
    } else if(scroll_state == 2){
        SSD1306_scroll(false);
    } else{
        scroll_state = 0;
    }

    scroll_state++;
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
                            timer_disp_inv, timer_disp_update, timer_disp_scroll;

    //float brightness = 0.1;
    Melody alarmTune = nokia;
    //Midi alarmTune = never_gonna_give_you_up;
    
    // useful information for picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));
    bi_decl(bi_program_description("SSD1306 OLED driver I2C example for the Raspberry Pi Pico"));

    // I2C is "open drain", pull ups to keep signal high when no data is being
    // I2C Initialisation. Using it at 400Khz (Default).
    config_i2c_port(BITDOG_DISP_PORT, SSD1306_I2C_CLK, BITDOG_DISP_SDA, BITDOG_DISP_SCL);
    config_i2c_port(BITDOG_RTC_PORT, 400, BITDOG_RTC_SDA, BITDOG_RTC_SCL);

    // run through the complete initialization process
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

    // Initialize ADC for Vrx and Vry
    adc_init();
    adc_gpio_init(BITDOG_JOY_VRX);
    adc_gpio_init(BITDOG_JOY_VRY);

    // Initialize button
    gpio_init(BITDOG_JOY_SW);
    gpio_set_dir(BITDOG_JOY_SW, GPIO_IN);
    gpio_pull_up(BITDOG_JOY_SW);

    uint8_t test_byte = 0;
    if (!i2c_write_blocking(BITDOG_RTC_PORT, BITDOG_RTC_ADDR, &test_byte, 1, false)) {
        printf("RTC Not Working");
        return 1;
    }
    
    uint32_t wait = 10000;
    for (int i = 0; i < alarmTune.length; i++)
        wait += (alarmTune.tempo * 0.004) / alarmTune.durations[i];

    add_repeating_timer_ms(1000, led_timer_callback, &moon, &timer_leds);
    add_repeating_timer_ms(wait, buzzer_timer_callback, NULL, &timer_buzzers);
    add_repeating_timer_ms(2000, invert_display_timer_callback, NULL, &timer_disp_inv);
    add_repeating_timer_ms(1000, update_display_timer_callback, NULL, &timer_disp_update);
    //add_repeating_timer_ms(1500, scroll_display_timer_callback, NULL, &timer_disp_scroll);

    //if(triggerAlarm) playAlarm = true; // Immediatly triggers the melody the first time if alarm is already triggering.

    calc_render_area_buflen(&frame_area);

    clear_display(display_buffer, &frame_area);

    //play_display_intro();

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
        if(!set_rtc_datetime(hora, data)){
            printf("ERRO: Nao foi possivel definir datetime!\n");
        } else {
            date_set = true;
        } 
    }

    uint32_t press_start_time = 0;
    bool is_pressed = false;
    
    while(true)
    {
        sleep_ms(DEBOUNCE_DELAY_MS);  // Non-blocking debounce delay

        // Handle alarm logic
        if(isBuzzerPlaying == false && triggerAlarm == true && playAlarm == true){
            isBuzzerPlaying = true;
            playAlarm = false;
            init_pwm(BITDOG_BZZ_B);
            play_melody(BITDOG_BZZ_B, alarmTune);
            //play_midi(BITDOG_BZZ_B, alarmTune);
            stop_tone(BITDOG_BZZ_B);
            gpio_set_function(BITDOG_BZZ_B, GPIO_FUNC_NULL);
            isBuzzerPlaying = false;
        }

        //display_transition(display_buffer, &frame_area);
    
        // Check if both buttons are pressed simultaneously
        if (gpio_get(BITDOG_BTN_A) == 0 && gpio_get(BITDOG_BTN_B) == 0) {
            sleep_ms(50); // Small delay to debounce buttons
            triggerAlarm = false; // Disable the alarm
            printf("Buttons pressed: Alarm disabled.\n");
        }

        // Check if button B is held (active low)
        if (gpio_get(BITDOG_BTN_B) == 0) {
            if (!is_pressed) {
                press_start_time = to_ms_since_boot(get_absolute_time());
                is_pressed = true;
            } else {
                uint32_t elapsed_time = to_ms_since_boot(get_absolute_time()) - press_start_time;
                if (elapsed_time >= HOLD_TIME_MS) {
                    printf("Cadastrar Alarme!\n");
                    // Add any action to be performed here
                    is_pressed = false;  // Reset state after detection
                }
            }
        } else {
            // Button is released
            is_pressed = false;
        }

        // Check if button A is held (active low)
        if (gpio_get(BITDOG_BTN_A) == 0) {
            if (!is_pressed) {
                press_start_time = to_ms_since_boot(get_absolute_time());
                is_pressed = true;
            } else {
                uint32_t elapsed_time = to_ms_since_boot(get_absolute_time()) - press_start_time;
                if (elapsed_time >= HOLD_TIME_MS) {
                    printf("Setar Relógio!\n");
                    // Add any action to be performed here
                    is_pressed = false;  // Reset state after detection
                }
            }
        } else {
            // Button is released
            is_pressed = false;
        }

        //read_joystick();
    }

    return 0;
}

