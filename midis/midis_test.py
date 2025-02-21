import mido
import pretty_midi
import re

# File paths (update these with the correct locations)
midi_file_path = "cantode.mid"  # Update with your MIDI file path
header_file_path = "cantode.h"  # Update with your cantode.h file path

# Function to extract note data from MIDI file
def extract_midi_data(midi_path):
    midi_data = pretty_midi.PrettyMIDI(midi_path)
    notes = []
    
    for instrument in midi_data.instruments:
        for note in instrument.notes:
            pitch = note.pitch
            duration = note.end - note.start
            notes.append((pitch, duration))
    
    return notes

# Function to extract note data from cantode.h
def extract_header_data(header_path):
    with open(header_path, "r") as file:
        content = file.read()

    # Extract notes and durations from the C array
    note_pattern = re.findall(r"0x90,(\d+)", content)  # Extract note values
    duration_pattern = re.findall(r"(\d+),\s*0x80", content)  # Extract durations
    
    # Convert extracted data to integers
    notes = [int(n) for n in note_pattern]
    durations = [int(d) for d in duration_pattern]
    
    return list(zip(notes, durations))

# Extract data
midi_notes = extract_midi_data(midi_file_path)
header_notes = extract_header_data(header_file_path)

# Compare extracted values
#print("\nFirst 10 Notes from MIDI File:")
#for note, duration in midi_notes[:10]:
#    print(f"Note: {note}, Duration: {duration:.3f} sec")

print("\nFirst 10 Notes from cantode.h:")
for note, duration in header_notes[:10]:
    print(f"Note: {note}, Duration: {duration}")

# Check for mismatches
mismatches = []
for i in range(min(len(midi_notes), len(header_notes))):
    midi_note, midi_dur = midi_notes[i]
    header_note, header_dur = header_notes[i]

    # Convert MIDI duration to a comparable value
    midi_dur_scaled = round(midi_dur * 1000)  # Convert to milliseconds

    if midi_note != header_note or abs(midi_dur_scaled - header_dur) > 10:
        mismatches.append((i, midi_note, midi_dur_scaled, header_note, header_dur))

# Show mismatches
if mismatches:
    print("\nMismatches Found:")
    for idx, midi_n, midi_d, head_n, head_d in mismatches[:10]:
        print(f"Index {idx}: MIDI (Note {midi_n}, Duration {midi_d} ms) != Header (Note {head_n}, Duration {head_d} ms)")
else:
    print("\nNo mismatches found! The extraction seems correct.")

