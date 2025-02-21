// display.c
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#include "display.h"
#include <stdint.h>

uint8_t display_buffer[SSD1306_BUF_LEN];

render_area frame_area = {
    start_col: 0,
    end_col : BITDOG_DISP_WIDTH - 1,
    start_page : 0,
    end_page : SSD1306_NUM_PAGES - 1
};

render_area raspberries = {
    start_page : 0,
    end_page : (IMG_HEIGHT / SSD1306_PAGE_HEIGHT)  - 1
};

void display_play_intro(){
    for (int i = 0; i < 3; i++) {
        SSD1306_send_cmd(SSD1306_SET_ALL_ON);    // Set all pixels on
        sleep_ms(500);
        SSD1306_send_cmd(SSD1306_SET_ENTIRE_ON); // go back to following RAM for pixel state
        sleep_ms(500);
    }
}

void display_clear(render_area *area)
{
    memset(display_buffer, 0, SSD1306_BUF_LEN);
    render(display_buffer, area);
}

void display_play_transition(render_area *area) {
    bool pix = true;
    for (int i = 0; i < 2;i++) {
        for (int x = 0;x < BITDOG_DISP_WIDTH;x++) {
            DrawLine(display_buffer, x, 0,  BITDOG_DISP_WIDTH - 1 - x, BITDOG_DISP_HEIGHT - 1, pix);
            render(display_buffer, area);
        }

        /*for (int y = BITDOG_DISP_HEIGHT-1; y >= 0 ;y--) {
            DrawLine(display_buffer, 0, y, BITDOG_DISP_WIDTH - 1, BITDOG_DISP_HEIGHT - 1 - y, pix);
            render(display_buffer, area);
        }*/
        pix = false;
    }
}

void display_render_text(char output[][20])
{
    int y = 0;
    for (uint i = 0 ;i < 4; i++) {
        WriteString(display_buffer, 5, y, output[i]);
        y+=8;
    }
    render(display_buffer, &frame_area);
}

/*raspberries.start_col = 0;
    raspberries.end_col = IMG_WIDTH - 1;
    
    calc_render_area_buflen(&raspberries);

    uint8_t offset = 5 + IMG_WIDTH; // 5px padding

    for (int i = 0; i < 3; i++) {
        render(raspberry26x32, &raspberries);
        raspberries.start_col += offset;
        raspberries.end_col += offset;
}*/
