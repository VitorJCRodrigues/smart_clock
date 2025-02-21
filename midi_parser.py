import mido
import sys
import os
import math

def midi_to_freq(note):
    return round(440.0 * (2 ** ((note - 69) / 12)))

def freqs_to_notes(freqs_list):
    new_list = []
    for f in freqs_list:
        if f == 0:
            new_list.append("REST")
        elif f == 31:
            new_list.append("NOTE_B0")
        elif f == 784:
            new_list.append("NOTE_G5")
        elif f == 33:
            new_list.append("NOTE_C1")
        elif f == 35:
            new_list.append("NOTE_CS1")
        elif f == 37:
            new_list.append("NOTE_D1")
        elif f == 39:
            new_list.append("NOTE_DS1")
        elif f == 41:
            new_list.append("NOTE_E1")
        elif f == 44:
            new_list.append("NOTE_F1")
        elif f == 46:
            new_list.append("NOTE_FS1")
        elif f == 49:
            new_list.append("NOTE_G1")
        elif f == 52:
            new_list.append("NOTE_GS1")
        elif f == 55:
            new_list.append("NOTE_A1")
        elif f == 58:
            new_list.append("NOTE_AS1")
        elif f == 62:
            new_list.append("NOTE_B1")
        elif f == 65:
            new_list.append("NOTE_C2")
        elif f == 69:
            new_list.append("NOTE_CS2")
        elif f == 73:
            new_list.append("NOTE_D2")
        elif f == 78:
            new_list.append("NOTE_DS2")
        elif f == 82:
            new_list.append("NOTE_E2")
        elif f == 87:
            new_list.append("NOTE_F2")
        elif f == 93:
            new_list.append("NOTE_FS2")
        elif f == 98:
            new_list.append("NOTE_G2")
        elif f == 104:
            new_list.append("NOTE_GS2")
        elif f == 110:
            new_list.append("NOTE_A2")
        elif f == 117:
            new_list.append("NOTE_AS2")
        elif f == 123:
            new_list.append("NOTE_B2")
        elif f == 131:
            new_list.append("NOTE_C3")
        elif f == 139:
            new_list.append("NOTE_CS3")
        elif f == 139:
            new_list.append("NOTE_DB3")
        elif f == 147:
            new_list.append("NOTE_D3")
        elif f == 156:
            new_list.append("NOTE_DS3")
        elif f == 156:
            new_list.append("NOTE_EB3")
        elif f == 165:
            new_list.append("NOTE_E3")
        elif f == 175:
            new_list.append("NOTE_F3")
        elif f == 185:
            new_list.append("NOTE_FS3")
        elif f == 196:
            new_list.append("NOTE_G3")
        elif f == 208:
            new_list.append("NOTE_GS3")
        elif f == 220:
            new_list.append("NOTE_A3")
        elif f == 233:
            new_list.append("NOTE_AS3")
        elif f == 247:
            new_list.append("NOTE_B3")
        elif f == 262:
            new_list.append("NOTE_C4")
        elif f == 277:
            new_list.append("NOTE_CS4")
        elif f == 294:
            new_list.append("NOTE_D4")
        elif f == 311:
            new_list.append("NOTE_DS4")
        elif f == 330:
            new_list.append("NOTE_E4")
        elif f == 349:
            new_list.append("NOTE_F4")
        elif f == 370:
            new_list.append("NOTE_FS4")
        elif f == 392:
            new_list.append("NOTE_G4")
        elif f == 415:
            new_list.append("NOTE_GS4")
        elif f == 440:
            new_list.append("NOTE_A4")
        elif f == 466:
            new_list.append("NOTE_AS4")
        elif f == 494:
            new_list.append("NOTE_B4")
        elif f == 523:
            new_list.append("NOTE_C5")
        elif f == 554:
            new_list.append("NOTE_CS5")
        elif f == 587:
            new_list.append("NOTE_D5")
        elif f == 622:
            new_list.append("NOTE_DS5")
        elif f == 659:
            new_list.append("NOTE_E5")
        elif f == 698:
            new_list.append("NOTE_F5")
        elif f == 740:
            new_list.append("NOTE_FS5")
        elif f == 831:
            new_list.append("NOTE_GS5")
        elif f == 880:
            new_list.append("NOTE_A5")
        elif f == 932:
            new_list.append("NOTE_AS5")
        elif f == 988:
            new_list.append("NOTE_B5")
        elif f == 1047:
            new_list.append("NOTE_C6")
        elif f == 1109:
            new_list.append("NOTE_CS6")
        elif f == 1175:
            new_list.append("NOTE_D6")
        elif f == 1245:
            new_list.append("NOTE_DS6")
        elif f == 1319:
            new_list.append("NOTE_E6")
        elif f == 1397:
            new_list.append("NOTE_F6")
        elif f == 1480:
            new_list.append("NOTE_FS6")
        elif f == 1568:
            new_list.append("NOTE_G6")
        elif f == 1661:
            new_list.append("NOTE_GS6")
        elif f == 1760:
            new_list.append("NOTE_A6")
        elif f == 1865:
            new_list.append("NOTE_AS6")
        elif f == 1976:
            new_list.append("NOTE_B6")
        elif f == 2093:
            new_list.append("NOTE_C7")
        elif f == 2217:
            new_list.append("NOTE_CS7")
        elif f == 2349:
            new_list.append("NOTE_D7")
        elif f == 2489:
            new_list.append("NOTE_DS7")
        elif f == 2637:
            new_list.append("NOTE_E7")
        elif f == 2794:
            new_list.append("NOTE_F7")
        elif f == 2960:
            new_list.append("NOTE_FS7")
        elif f == 3136:
            new_list.append("NOTE_G7")
        elif f == 3322:
            new_list.append("NOTE_GS7")
        elif f == 3520:
            new_list.append("NOTE_A7")
        elif f == 3729:
            new_list.append("NOTE_AS7")
        elif f == 3951:
            new_list.append("NOTE_B7")
        elif f == 4186:
            new_list.append("NOTE_C8")
        elif f == 4435:
            new_list.append("NOTE_CS8")
        elif f == 4699:
            new_list.append("NOTE_D8")
        elif f == 4978:
            new_list.append("NOTE_DS8")
        else:
            new_list.append(f)
    return new_list

def parse_midi(midi_path, output_path):
    mid = mido.MidiFile(midi_path)
    ticks_per_beat = mid.ticks_per_beat
    tempo = 250000  # Default tempo (240 BPM)
    current_time = 0.0
    active_notes = []  # Track {note, channel, start_time}
    notes = []
    durations = []

    # Process all tracks/messages
    for track in mid.tracks:
        for msg in track:
            # Update current time (delta in seconds)
            delta_time = mido.tick2second(msg.time, ticks_per_beat, tempo)
            current_time += delta_time

            # Handle events
            if msg.type == 'set_tempo':
                tempo = msg.tempo
            elif msg.type == 'note_on' and msg.velocity > 0:
                active_notes.append({
                    'note': msg.note,
                    'channel': msg.channel,
                    'start_time': current_time
                })
            elif msg.type == 'note_off' or (msg.type == 'note_on' and msg.velocity == 0):
                # Find matching note-on
                for note_data in reversed(active_notes):
                    if (note_data['note'] == msg.note and 
                        note_data['channel'] == msg.channel):
                        duration = current_time - note_data['start_time']
                        if duration > -1:
                            notes.append(midi_to_freq(msg.note))
                            # Convert duration in seconds to note value (assuming 1 whole note = 1 second at 60 BPM)
                            quarter_note_duration = 60.0 / (tempo / 1000000.0)  # Quarter note duration in seconds
                            
                            note_length = round(4000 * (duration / quarter_note_duration))  # Scale to whole, half, quarter, etc.

                            # Ensure it matches standard note values (1, 2, 4, 8, 16, etc.)
                            #valid_note_lengths = [1, 2, 4, 8, 16, 32, 64]
                            #note_length = min(valid_note_lengths, key=lambda x: abs(x - note_length))

                            durations.append(note_length)
                            #durations.append(round(duration*500))

                            #durations.append(round(1 / duration))  # Parts of a second
                        active_notes.remove(note_data)
                        break

    max_length = min(len(notes), 4096)
    notes = freqs_to_notes(notes[:max_length] + [0] * max_length)[:max_length]
    durations = (durations[:max_length] + [0] * max_length)[:max_length]
    length = max_length

    # Generate output
    struct_name = os.path.splitext(os.path.basename(midi_path))[0]
    with open(output_path, 'w') as f:
        f.write(f"#include \"notes.h\"\n"
                f"#include \"pitches.h\"\n"
                f"\n"
                f"Midi {struct_name} = {{\n"
                f"  .notes = {{{', '.join(map(str, notes))}}},\n"
                f"  .durations = {{{', '.join(map(str, durations))}}},\n"
                f"  .length = {length},\n"
                f"  .tempo = {tempo}\n"
                f"}};\n")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python midi_parser.py <input.mid> [output.h]")
        sys.exit(1)

    input_file = sys.argv[1]

    # If no output file is provided, default to the input file name with .h extension
    if len(sys.argv) == 2:
        output_file = os.path.splitext(input_file)[0] + ".h"
    else:
        output_file = sys.argv[2]
    
    parse_midi(input_file, output_file)