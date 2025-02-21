// display.h
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#ifndef DISPLAY_H
#define DISPLAY_H

#include "ssd1306.h"
#include "bitdoglab.h"
#include <stdint.h>
#include <hardware/i2c.h>

extern uint8_t display_buffer[SSD1306_BUF_LEN];

// Initialize render area for entire frame (BITDOG_DISP_WIDTH pixels by SSD1306_NUM_PAGES pages)
extern render_area frame_area;

// render 3 cute little raspberries
extern render_area raspberries;

/***********************************
 * OLED Display Handling Functions *
 ***********************************/ 

// Intro sequence: flash the screen 3 times
void play_display_intro();

// Clear the entire display
void clear_display(uint8_t * handler, render_area *area);

void display_transition(uint8_t * buffer, render_area *area);

void render_text(char output[][20]);

#endif //DISPLAY_H