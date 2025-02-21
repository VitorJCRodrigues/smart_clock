// media_player.h
// Author: Vítor Rodrigues
// Repository: https://github.com/VitorJCRodrigues/smart_clock

#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include "notes.h"
#include <hardware/pwm.h>
#include <hardware/clocks.h>

// Internal Auxiliary Functions
static double midiNoteToFrequency(int note); // Convert MIDI values for notes in to frequencies in Hertz (Hz)

/***************************
 * MIDI Handling Functions *
 * *************************/ 

// Function to initialize PWM on a given GPIO pin
void bazz_player_init(uint gpio_pin);

// Play a tone
void bazz_player_play_tone(uint gpio_pin, uint frequency);

// Function to stop the tone on a given GPIO pin
void bazz_player_stop_tone(uint gpio_pin);

// Function to play a melody
void bazz_player_play_melody(uint gpio_pin, Melody melody);

// Play a converted MIDI file
void bazz_player_play_midi(uint gpio_pin, Midi midi);

#endif //MEDIA_PLAYER_H