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
void display_play_intro();

// Clear the entire display
void display_clear(render_area *area);

// Plays a small transition that swirls the display
void display_play_transition(render_area *area);

// Renders a 4x20 textbox on display
void display_render_text(char output[][20]);

// Renders a datetime info on a texbox
void display_render_datetime(datetime_t datetime, const char* extraLine1, const char* extraLine2);

#endif //DISPLAY_H