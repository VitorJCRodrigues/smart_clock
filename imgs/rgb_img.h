// This is a header to define the format for led array images
// rgb_img.h
#ifndef RGB_IMG_H
#define RGB_IMG_H

#include <stdint.h>

#define NUM_LEDS 25

typedef struct {
    uint8_t red[NUM_LEDS];
    uint8_t green[NUM_LEDS];
    uint8_t blue[NUM_LEDS];
} Led_Image;

#endif // RGB_IMG_H
