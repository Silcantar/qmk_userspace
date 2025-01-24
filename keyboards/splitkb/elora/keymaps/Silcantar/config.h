// Copyright 2024 Joshua Lucas (joshdlucas@gmail.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Myriad boilerplate
#define MYRIAD_ENABLE

#define FORCE_NKRO

// Tap Dance Config
#define PERMISSIVE_HOLD
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

// Unicode Config
#define UNICODE_KEY_WINC KC_RIGHT_ALT
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#define UNICODE_KEY_MAC KC_LEFT_ALT
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE //, UNICODE_MODE_LINUX, UNICODE_MODE_MACOS
#define UNICODE_CYCLE_PERSIST true
#define UNICODE_TYPE_DELAY 10

// LED Config
#define SPLIT_MODS_ENABLE
#define RGBLIGHT_SLEEP

// Caps Word
//#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 2000

// Select Word
#define SELECT_WORD_TIMEOUT 2000

// Combos
#define COMBO_MUST_PRESS_IN_ORDER