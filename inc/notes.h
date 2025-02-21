// This is a map for notes containing all notes frequencies
// notes.h
#ifndef NOTES_H
#define NOTES_H

#include "pitches.h"
#include <stdint.h>

#define MAX_NUM_NOTES 4096

typedef struct {
    uint16_t notes[MAX_NUM_NOTES];
    uint16_t durations[MAX_NUM_NOTES];
    int length;
    uint32_t tempo;
} Melody;

typedef struct {
    uint16_t notes[MAX_NUM_NOTES];
    double durations[MAX_NUM_NOTES];
    int length;
    uint32_t tempo;
} Midi;

#endif // NOTES_H
