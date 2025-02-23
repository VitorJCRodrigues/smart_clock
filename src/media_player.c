// media_player.c
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#include <stdio.h>
#include <math.h>
#include <pico/stdlib.h>
#include <hardware/timer.h>
#include "media_player.h"
#include "midis/melodies.h"

static Melody current_melody;
static int current_note_index = 0;
static uint current_gpio_pin;
static bool is_playing = false;
static alarm_id_t melody_alarm = -1;

static double midiNoteToFrequency(int note)
{
    return 440.0 * pow(2.0, (note - 69) / 12.0);
}

void bazz_player_init(uint gpio_pin)
{
    gpio_set_function(gpio_pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin);
    pwm_set_wrap(slice_num, 255);                   // Set the PWM range
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 128); // Set duty cycle to 50%
    pwm_set_enabled(slice_num, true);
}

void bazz_player_play_tone(uint gpio_pin, uint frequency)
{
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin);
    uint32_t clock = clock_get_hz(clk_sys); // System clock frequency
    uint16_t wrap = 65535;                  // Maximum wrap value for 16-bit PWM
    uint16_t level = wrap / 128;

    float divisor = (float)clock / (frequency * (wrap + 1));

    pwm_set_clkdiv(slice_num, divisor);
    pwm_set_wrap(slice_num, wrap);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, level); // 50% duty cycle
    pwm_set_enabled(slice_num, true);
}

void bazz_player_stop_tone(uint gpio_pin)
{
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin);
    pwm_set_enabled(slice_num, false);
}

void bazz_player_play_melody(uint gpio_pin, Melody melody)
{
    if (is_playing)
    {
        printf("Melody already playing!\n");
        return;
    }

    // Cancel any existing alarms
    if (melody_alarm != -1)
    {
        cancel_alarm(melody_alarm);
        melody_alarm = -1;
    }

    // Initialize playback state
    current_melody = melody;
    current_gpio_pin = gpio_pin;
    current_note_index = 0;
    is_playing = true;

    // Start PWM on the buzzer pin
    bazz_player_init(gpio_pin);

    // Schedule the first note
    melody_alarm = add_alarm_in_ms(
        0, // Start immediately
        (alarm_callback_t)bazz_player_play_next_note,
        NULL,
        true);

    if (melody_alarm == -1)
    {
        printf("Failed to schedule the first note!\n");
        is_playing = false;
        bazz_player_stop_tone(gpio_pin);
    }
}

void bazz_player_play_midi(uint gpio_pin, Midi midi)
{
    for (int i = 0; i < midi.length; i++)
    {
        double duration = (midi.durations[i]);

        bazz_player_play_tone(gpio_pin, midi.notes[i]);
        sleep_ms(duration);
        bazz_player_stop_tone(gpio_pin);
        sleep_ms(50); // Short pause between notes
    }
}

void bazz_player_beep(uint gpio_pin, uint frequency, uint time_ms)
{
    bazz_player_init(gpio_pin);
    bazz_player_play_tone(gpio_pin, frequency);
    sleep_ms(time_ms);
    bazz_player_stop_tone(gpio_pin);
}

void bazz_player_stop_melody()
{
    if (melody_alarm != -1)
    {
        cancel_alarm(melody_alarm);
        melody_alarm = -1;
    }
    is_playing = false;
    bazz_player_stop_tone(current_gpio_pin);
    current_note_index = 0; // Reset note index
}

int64_t bazz_player_play_next_note(alarm_id_t id, void *user_data)
{
    if (!is_playing || current_note_index >= current_melody.length)
    {
        printf("Melody finished or stopped.\n");
        is_playing = false;
        bazz_player_stop_tone(current_gpio_pin);
        if (melody_alarm != -1)
        {
            cancel_alarm(melody_alarm); // Cancel any pending alarm
            melody_alarm = -1;
        }
        return 0; // Return 0 to indicate no further alarms
    }

    // Stop previous note
    bazz_player_stop_tone(current_gpio_pin);

    // Play current note
    double duration = (1000.0 / current_melody.durations[current_note_index]) * 1.2;
    if (duration < 10)
    { // Ensure a minimum delay of 10ms
        duration = 10;
    }
    // printf("Note %d/%d: Frequency = %d, Duration = %.2f ms\n", current_note_index, current_melody.length, current_melody.notes[current_note_index], duration);
    bazz_player_play_tone(current_gpio_pin, current_melody.notes[current_note_index]);
    current_note_index++;

    // Schedule next note with explicit time calculation
    if (duration > 0 && current_note_index <= current_melody.length)
    {
        melody_alarm = add_alarm_in_ms(
            duration + 50,
            (alarm_callback_t)bazz_player_play_next_note,
            NULL,
            true);
        if (melody_alarm == -1)
        {
            printf("Failed to schedule next note!\n");
            is_playing = false;
            bazz_player_stop_tone(current_gpio_pin);
            return 0;
        }
    }
    else
    {
        printf("Melody finished.\n");
        is_playing = false;
        bazz_player_stop_tone(current_gpio_pin);
    }

    return 0; // Return 0 to indicate no further alarms
}

bool bazz_player_is_melody_playing()
{
    return is_playing;
}

Melody *bazz_player_melody_select(melos selector)
{
    switch (selector)
    {
    case PACMAN:
        return &pacman;
    case NOKIA:
        return &nokia;
    case TETRIS:
        return &tetris;
    default:
        return NULL; // Return NULL for invalid selections
    }
}

Melody *melody_init()
{
    return &nokia;
}