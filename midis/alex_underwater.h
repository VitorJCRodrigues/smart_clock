#include "notes.h"
#include "pitches.h"

Midi alex_underwater = {
  .notes = {NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_F5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_DS5, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_AS3, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_AS3, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_AS3, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_AS3, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_DS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_DS6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_D6, NOTE_F6, NOTE_DS6, NOTE_D6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_G6, NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_D6, NOTE_F6, NOTE_DS6, NOTE_D6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_G6, NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_AS4, NOTE_AS4, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_DS6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_D6, NOTE_F6, NOTE_DS6, NOTE_D6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_G6, NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_DS6, NOTE_D6, NOTE_F6, NOTE_DS6, NOTE_D6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_AS5, NOTE_C6, NOTE_D6, NOTE_G6, NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_D2, NOTE_D2, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_D2, NOTE_D2, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_D2, NOTE_D2, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_D2, NOTE_D2, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_D2, NOTE_D2, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_D2, NOTE_D2, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_D2, NOTE_D2, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_B1, NOTE_D2, NOTE_B1, NOTE_D2, NOTE_D2, NOTE_D2},
  .durations = {222, 222, 222, 222, 222, 267, 267, 533, 267, 800, 2400, 222, 222, 222, 222, 222, 267, 267, 533, 267, 3200, 222, 222, 222, 222, 222, 267, 267, 533, 267, 800, 2400, 222, 222, 222, 222, 222, 267, 267, 533, 267, 3200, 267, 267, 267, 800, 267, 800, 267, 800, 267, 267, 533, 267, 800, 2400, 800, 267, 800, 267, 533, 267, 533, 267, 3200, 267, 267, 267, 800, 267, 800, 267, 800, 267, 267, 533, 267, 800, 2400, 800, 267, 800, 267, 533, 267, 533, 267, 3200, 222, 222, 222, 222, 222, 267, 267, 533, 267, 800, 2400, 222, 222, 222, 222, 222, 267, 267, 533, 267, 3200, 222, 222, 222, 222, 222, 267, 267, 533, 267, 800, 2400, 222, 222, 222, 222, 222, 267, 267, 533, 267, 3200, 267, 267, 267, 800, 267, 800, 267, 800, 267, 267, 533, 267, 800, 2400, 800, 267, 800, 267, 533, 267, 533, 267, 3200, 267, 267, 267, 800, 267, 800, 267, 800, 267, 267, 533, 267, 800, 2400, 800, 267, 800, 267, 533, 267, 533, 267, 3200, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 533, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 533, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 533, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 533, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 222, 222, 222, 222, 222, 267, 267, 533, 267, 800, 2400, 222, 222, 222, 222, 222, 267, 267, 533, 267, 3200, 222, 222, 222, 222, 222, 267, 267, 533, 267, 800, 2400, 222, 222, 222, 222, 222, 267, 267, 533, 267, 3200, 800, 267, 800, 267, 800, 267, 267, 533, 267, 800, 2400, 800, 267, 800, 267, 533, 267, 533, 267, 3200, 267, 267, 267, 800, 267, 800, 267, 800, 267, 267, 533, 267, 800, 2400, 800, 267, 800, 267, 533, 267, 533, 267, 3200, 222, 222, 222, 222, 222, 267, 267, 533, 267, 800, 2400, 222, 222, 222, 222, 222, 267, 267, 533, 267, 3200, 222, 222, 222, 222, 222, 267, 267, 533, 267, 800, 2400, 222, 222, 222, 222, 222, 267, 267, 533, 267, 3200, 800, 267, 800, 267, 800, 267, 267, 533, 267, 800, 2400, 800, 267, 800, 267, 533, 267, 533, 267, 3200, 267, 267, 267, 800, 267, 800, 267, 800, 267, 267, 533, 267, 800, 2400, 800, 267, 800, 267, 533, 267, 533, 267, 3200, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 267, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 267},
  .length = 1242,
  .tempo = 533333
};
