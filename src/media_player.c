// media_player.c
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#include "media_player.h"
#include <stdio.h>
#include <math.h>
#include <pico/stdlib.h>

void init_pwm(uint gpio_pin)
{
    gpio_set_function(gpio_pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin);
    pwm_set_wrap(slice_num, 255);                   // Set the PWM range
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 128); // Set duty cycle to 50%
    pwm_set_enabled(slice_num, true);
}

void play_tone(uint gpio_pin, uint frequency)
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

void stop_tone(uint gpio_pin)
{
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin);
    pwm_set_enabled(slice_num, false);
}

void play_melody(uint gpio_pin, Melody melody) 
{
    for (int i = 0; i < melody.length; i++) 
    {
        double duration = (1000 / melody.durations[i]); // Calculate the duration of the note in milliseconds

        play_tone(gpio_pin, melody.notes[i]);
        sleep_ms(duration*1.2); 
        stop_tone(gpio_pin);

        sleep_ms(50); // Short pause between notes
    }
}

void play_midi(uint gpio_pin, Midi midi) 
{
    for (int i = 0; i < midi.length; i++) 
    {
        double duration = (midi.durations[i]);

        play_tone(gpio_pin, midi.notes[i]);
        sleep_ms(duration); 
        stop_tone(gpio_pin);
        sleep_ms(50); // Short pause between notes
    }
}

double midiNoteToFrequency(int note)
{ 
    return 440.0 * pow(2.0, (note - 69) / 12.0);
}