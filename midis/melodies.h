//melodies.h

#ifndef MELODIES_H
#define MELODIES_H

#include "notes.h"

// Melody Templates
Melody pacman = {
    .notes = {
        NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5,
        NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_C5,
        NOTE_C6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_G6, NOTE_E6,

        NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_B5,
        NOTE_FS5, NOTE_DS5, NOTE_DS5, NOTE_E5, NOTE_F5,
        NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_B5
    },
    .durations = {
        16, 16, 16, 16,
        32, 16, 8, 16,
        16, 16, 16, 32, 16, 8,

        16, 16, 16, 16, 32,
        16, 8, 32, 32, 32,
        32, 32, 32, 32, 32, 16, 8
    },
    .length = 31,
    .tempo = 250000
};

Melody nokia = {
    .notes = {
        NOTE_E5, NOTE_D5, NOTE_FS4, NOTE_GS4,
        NOTE_CS5, NOTE_B4, NOTE_D4, NOTE_E4,
        NOTE_B4, NOTE_A4, NOTE_CS4, NOTE_E4,
        NOTE_A4
    },
    .durations = {
        8, 8, 4, 4,
        8, 8, 4, 4,
        8, 8, 4, 4,
        2
    },
    .length = 13,
    .tempo = 250000
};

Melody tetris = {
    .notes = {
        NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
        NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
        NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
        NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,
        
        NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
        NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
        NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
        NOTE_C5, NOTE_A4, NOTE_A4, REST, 
        
        NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
        NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
        NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
        NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,
        
        NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
        NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
        NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
        NOTE_C5, NOTE_A4, NOTE_A4, REST, 
        
        NOTE_E5, NOTE_C5,
        NOTE_D5, NOTE_B4,
        NOTE_C5, NOTE_A4,
        NOTE_GS4, NOTE_B4, REST, 
        NOTE_E5, NOTE_C5,
        NOTE_D5, NOTE_B4,
        NOTE_C5, NOTE_E5, NOTE_A5,
        NOTE_GS5
    },
    .durations = {
        4, 8, 8, 4, 8, 8,
        4, 8, 8, 4, 8, 8,
        4, 8, 4, 4,
        4, 4, 8, 4, 8, 8,
        
        4, 8, 4, 8, 8,
        4, 8, 4, 8, 8,
        4, 8, 8, 4, 4,
        4, 4, 4, 4,
        
        4, 8, 8, 4, 8, 8,
        4, 8, 8, 4, 8, 8,
        4, 8, 4, 4,
        4, 4, 8, 4, 8, 8,
        
        4, 8, 4, 8, 8,
        4, 8, 4, 8, 8,
        4, 8, 8, 4, 4,
        4, 4, 4, 4,
        
        2, 2,
        2, 2,
        2, 2,
        2, 4, 8, 
        2, 2,
        2, 2,
        4, 4, 2,
        2
    },
    .length = 99,
    .tempo = 250000
};

#endif //MELODIES_H