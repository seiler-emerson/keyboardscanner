## GeneralMusic pRP8 – Key Mapping and Definition

This model uses the **GeneralMusic pRP8** 88‑key dynamic keyboard, based on the page‑8 schematic and the wiring diagram `generalmusic_prp8_wiring.svg`.

- **Keyboard range**: A0 → C8 (88 notes)
- **Left contacts board**: part `810552`, PCB `310531`  
  - **39 notes**, **octaves 0–3**  
  - Range: A0 → D#4 (MIDI 21–63)  
  - Connector: **CN4 (20‑pin)**
- **Right contacts board**: part `810551`, PCB `310530`  
  - **49 notes**, **octaves 4–7 + C8**  
  - Range: E4 → C8 (MIDI 64–108)  
  - Connector: **CN1 (20‑pin)**

The keyboard matrix is velocity‑sensitive and uses **two contact levels per key**:

- **MAKE (MK0–MK10)**: first contact that closes when a key is pressed (velocity start)
- **BREAK (BR0–BR10)**: second contact that opens when the key finishes its travel (velocity stop)

Each key is represented by a pair of MAKE/BREAK contacts connected to one **KD column** and one **MK/BR row**, as shown in the SVG.

## Arduino Mega 2560 Pin Assignment (from the SVG)

On the Arduino side, the schematic defines:

- **KD outputs (columns – driven LOW to scan)**  
  - KD0 → pin 2  
  - KD1 → pin 3  
  - KD2 → pin 4  
  - KD3 → pin 5  
  - KD4 → pin 6  
  - KD5 → pin 7  
  - KD6 → pin 8  
  - KD7 → pin 9  
  - KD8 → pin 10  

- **MK inputs (MAKE contacts)** – grouped per note range, labeled MK0..MK10 in the drawing
- **BR inputs (BREAK contacts)** – grouped BR0..BR10, always paired with the corresponding MKx group

In this project’s `model.h`, these logical signals are mapped to Arduino Mega ports in an optimized way (similar to the `maudio_keystation88ii` model), avoiding analog inputs **A0–A8** so they can be used by `potentiometers.cpp`.

Refer to:

- `model.h` for the final **KD/MK/BR → Arduino pin** mapping
- `pins.h` for the **PINS(output_pin, input_pin)** sequence that enumerates all 88 keys (A0 → C8) in scanning order, following the MK/BR grouping from the SVG.

\
**Pedro Tomaz Alves**  
2026-03-10  
Cuiabá-MT, Brazil  


