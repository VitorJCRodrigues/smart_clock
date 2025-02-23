// pixel_leds.h
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#ifndef PIXEL_LEDS_H
#define PIXEL_LEDS_H

#include "imgs/rgb_img.h"
#include <stdint.h>

/*********************************
 * LED Matrix Handling Functions *
 *********************************/ 

// Function to send RGB data to the LED matrix with brightness control
void send_led_data(const Led_Image *led_image, float brightness);

void turn_off_leds();

#endif //PIXEL_LEDS_H