/*
Moura's Keyboard Scanner: turn you broken (or unused) keyboard in a MIDI controller
Copyright (C) 2017 Daniel Moura <oxesoft@gmail.com>

This code is originally hosted at https://github.com/oxesoft/keyboardscanner

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


Pedro Tomaz Alves
2026-03-10
Cuiabá-MT, Brazil
*/

// GeneralMusic pRP8 model definition
// Based on the structure of the other models in models/

// Number of keys and first MIDI note.
// GeneralMusic pRP8 is an 88‑key piano starting at A0 (MIDI 21).
#define KEYS_NUMBER       88
#define FIRST_KEY         21

// Sustain pedal pin (PORTB, keeping A0–A8 free)
#define SUSTAIN_PEDAL_PIN 50 // PB3

// Time range in microseconds used for velocity calculation
// Tweak these if you need to refine the velocity response
#define MIN_TIME_US       3000
#define MAX_TIME_US       25000

// ============================================================
// GeneralMusic pRP8 matrix mapping
// ============================================================
//
// KD0–KD8  → outputs (columns), driven LOW to scan
// MK0–MK10 → MAKE inputs (first contact that closes)
// BR0–BR10 → BREAK inputs (contact that opens later)
//
// Refactored to use ATmega2560 PORT groups in a similar way
// to the maudio_keystation88ii model, avoiding analog inputs
// A0–A8 (reserved for potentiometers in potentiometers.cpp).
//
// KD (outputs)  —  “drive LOW to scan”
// We use PORTA (22–29) + one line in PORTD
#define PIN_KD0 22 // PA0
#define PIN_KD1 23 // PA1
#define PIN_KD2 24 // PA2
#define PIN_KD3 25 // PA3
#define PIN_KD4 26 // PA4
#define PIN_KD5 27 // PA5
#define PIN_KD6 28 // PA6
#define PIN_KD7 29 // PA7
#define PIN_KD8 21 // PD0

// MK (make contacts inputs)
// First we use PORTC (30–37), then complete in PORTD
#define PIN_MK0 37 // PC0
#define PIN_MK1 36 // PC1
#define PIN_MK2 35 // PC2
#define PIN_MK3 34 // PC3
#define PIN_MK4 33 // PC4
#define PIN_MK5 32 // PC5
#define PIN_MK6 31 // PC6
#define PIN_MK7 30 // PC7
#define PIN_MK8 20 // PD1
#define PIN_MK9 19 // PD2
#define PIN_MK10 18 // PD3

// BR (break contacts inputs)
// We use PORTL (42–49) and PORTB (50–53)
#define PIN_BR0  42 // PL7
#define PIN_BR1  43 // PL6
#define PIN_BR2  44 // PL5
#define PIN_BR3  45 // PL4
#define PIN_BR4  46 // PL3
#define PIN_BR5  47 // PL2
#define PIN_BR6  48 // PL1
#define PIN_BR7  49 // PL0
#define PIN_BR8  53 // PB0
#define PIN_BR9  52 // PB1
#define PIN_BR10 51 // PB2

