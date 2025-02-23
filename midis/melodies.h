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

Melody simpsons = {
    .notes = {
        NOTE_C4, NOTE_E4, NOTE_FS4, REST, NOTE_A4,
        NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A3,
        NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_G3, REST,
        NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_G3, NOTE_AS3,
        NOTE_B3, REST
    },
    .durations = {
        2, 4, 4, 32, 8,
        2, 4, 4, 8,
        8, 8, 8, 4, 2,
        8, 8, 8, 4, 2,
        2, 2
    },
    .length = 22,
    .tempo = 250000
};

Melody mario_bros = {
    .notes = {
        NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
        NOTE_G5, REST, NOTE_G4, REST, 
        NOTE_C5, NOTE_G4, REST, NOTE_E4,
        NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
        REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
        NOTE_C5, NOTE_G4, REST, NOTE_E4,
        NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
        REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
        
        REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
        REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
        REST, NOTE_DS5, REST, NOTE_D5,
        NOTE_C5, REST,
        
        REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
        REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
        REST, NOTE_DS5, REST, NOTE_D5,
        NOTE_C5, REST,
        
        NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
        NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
        
        NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
        REST, 
        NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
        NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
        NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
        NOTE_G5, REST, NOTE_G4, REST, 
        NOTE_C5, NOTE_G4, REST, NOTE_E4,
        
        NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
        REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
        
        NOTE_C5, NOTE_G4, REST, NOTE_E4,
        NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
        NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
        REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
        
        NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
        NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
        NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
        
        NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
        NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
        NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
        NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
        NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
        
        NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
        NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
        NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
        
        NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
        NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
        NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
        NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
        NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
        NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
        REST,
        
        NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
        NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
        NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
        NOTE_G5, REST, NOTE_G4, REST, 
        NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
        NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
        NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
        
        NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
        NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
        NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
        NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
        NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
        
        // Game over sound
        NOTE_C5, NOTE_G4, NOTE_E4,
        NOTE_A4, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_AS4, NOTE_GS4,
        NOTE_G4, NOTE_D4, NOTE_E4
    },
    .durations = {
        8, 8, 8, 8, 8, 8, 8,
        4, 4, 8, 4, 
        4, 8, 4, 4,
        4, 4, 8, 4,
        8, 8, 8, 4, 8, 8,
        8, 4,8, 8, 4,
        4, 8, 4, 4,
        4, 4, 8, 4,
        8, 8, 8, 4, 8, 8,
        8, 4,8, 8, 4,
        
        
        4, 8, 8, 8, 4, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        4, 4, 8, 4,
        2, 2,
        
        4, 8, 8, 8, 4, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        4, 4, 8, 4,
        2, 2,
        
        8, 4, 8, 8, 8, 4,
        8, 4, 8, 2,
        
        8, 4, 8, 8, 8, 8, 8,
        1, 
        8, 4, 8, 8, 8, 4,
        8, 4, 8, 2,
        8, 8, 8, 8, 8, 8, 4,
        4, 4, 4, 4, 
        4, 8, 4, 4,
        
        4, 4, 8, 4,
        8, 8, 8, 4, 8, 8,
        8, 4, 8, 8, 4,
        
        4, 8, 4, 4,
        4, 4, 8, 4,
        8, 8, 8, 4, 8, 8,
        8, 4, 8, 8, 4,
        
        8, 4, 8, 4, 4,
        8, 4, 8, 2,
        8, 8, 8, 8, 8, 8,
        
        8, 4, 8, 2,
        8, 4, 8, 4, 4,
        8, 4, 8, 2,
        8, 4, 8, 8, 8, 8,
        8, 4, 8, 2,
        
        8, 4, 8, 4, 4,
        8, 4, 8, 2,
        8, 8, 8, 8, 8, 8,
        
        8, 4, 8, 2,
        8, 4, 8, 4, 4,
        8, 4, 8, 2,
        8, 4, 8, 8, 8, 8,
        8, 4, 8, 2,
        8, 4, 8, 8, 8, 8, 8,
        1,
        
        8, 4, 8, 8, 8, 4,
        8, 4, 8, 2,
        8, 8, 8, 8, 8, 8, 4,
        4, 4, 4, 4, 
        8, 4, 8, 4, 4,
        8, 4, 8, 2,
        8, 8, 8, 8, 8, 8,
        
        8, 4, 8, 2,
        8, 4, 8, 4, 4,
        8, 4, 8, 2,
        8, 4, 8, 8, 8, 8,
        8, 4, 8, 2,
        
        //game over sound
        4, 4, 4,
        8, 8, 8, 8, 8, 8,
        8, 8, 2
    },
    .length = 382,
    .tempo = 250000
};

Melody doom = {
    .notes = {
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_FS3, NOTE_D3, NOTE_B2, NOTE_A3, NOTE_FS3, NOTE_B2, NOTE_D3, NOTE_FS3, NOTE_A3, NOTE_FS3, NOTE_D3, NOTE_B2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_B3, NOTE_G3, NOTE_E3, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_B3, NOTE_G4, NOTE_B4,
        
        NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2, 
        NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_F3,
        NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
        NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3,
        
        NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2, 
        NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_F3,
        NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
        NOTE_A3, NOTE_F3, NOTE_D3, NOTE_A3, NOTE_F3, NOTE_D3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_A3, NOTE_F3, NOTE_D3,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_CS3, NOTE_CS3, NOTE_CS4, NOTE_CS3, NOTE_CS3, NOTE_B3, NOTE_CS3, NOTE_CS3, 
        NOTE_A3, NOTE_CS3, NOTE_CS3, NOTE_G3, NOTE_CS3, NOTE_CS3, NOTE_GS3, NOTE_A3,
        NOTE_B2, NOTE_B2, NOTE_B3, NOTE_B2, NOTE_B2, NOTE_A3, NOTE_B2, NOTE_B2,
        NOTE_G3, NOTE_B2, NOTE_B2, NOTE_F3,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_B3, NOTE_G3, NOTE_E3, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_B3, NOTE_G4, NOTE_B4,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_FS3, NOTE_DS3, NOTE_B2, NOTE_FS3, NOTE_DS3, NOTE_B2, NOTE_G3, NOTE_D3, NOTE_B2, NOTE_DS4, NOTE_DS3, NOTE_B2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_E4, NOTE_B3, NOTE_G3, NOTE_G4, NOTE_E4, NOTE_G3, NOTE_B3, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G3,  
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2, 
        NOTE_F3, NOTE_A2, NOTE_A2, NOTE_DS3, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_F3,
        NOTE_A2, NOTE_A2, NOTE_A3, NOTE_A2, NOTE_A2, NOTE_G3, NOTE_A2, NOTE_A2,
        NOTE_A3, NOTE_F3, NOTE_D3, NOTE_A3, NOTE_F3, NOTE_D3, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_A3, NOTE_F3, NOTE_D3,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2,
        
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2, 
        NOTE_C3, NOTE_E2, NOTE_E2, NOTE_AS2, NOTE_E2, NOTE_E2, NOTE_B2, NOTE_C3,
        NOTE_E2, NOTE_E2, NOTE_E3, NOTE_E2, NOTE_E2, NOTE_D3, NOTE_E2, NOTE_E2,
        NOTE_B3, NOTE_G3, NOTE_E3, NOTE_B2, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_G3, NOTE_B3, NOTE_G3, NOTE_E3
    },
    .durations = {
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,  
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 2,
        
        8, 8, 8, 8, 8, 8, 8, 8, 
        8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16
        },
        .length = 744,
        .tempo = 250000
};

Melody pink_panther = {
    .notes = {
        REST, REST, REST, NOTE_DS4, 
        NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
        NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
        NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
        NOTE_E4, REST, REST, NOTE_DS4,
        
        NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
        NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_E5,
        NOTE_DS5,   
        NOTE_D5, REST, REST, NOTE_DS4, 
        NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
        NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
        
        NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
        NOTE_E4, REST,
        REST, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
        NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4,   
        NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4
        },
    .durations = {
        2, 4, 8, 8, 
        4, 8, 8, 4, 8, 8,
        8, 8,  8, 8, 8, 8, 8, 8,   
        2, 16, 16, 16, 16, 
        2, 4, 8, 4,
        
        4, 8, 8, 4, 8, 8,
        8, 8,  8, 8, 8, 8, 8, 8,
        1,   
        2, 4, 8, 8, 
        4, 8, 8, 4, 8, 8,
        8, 8,  8, 8, 8, 8, 8, 8,   
        
        2, 16, 16, 16, 16, 
        4, 4,
        4, 8, 8, 8, 8, 8, 8,
        16, 8, 16, 8, 16, 8, 16, 8,   
        16, 16, 16, 16, 16, 2
        },
        .length = 88,
        .tempo = 250000
};

#endif //MELODIES_H