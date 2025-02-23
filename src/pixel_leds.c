// pixel_leds.c
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#include "pixel_leds.h"
#include "bitdoglab.h"
#include <stdint.h>
#include "ws2812.pio.h"

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