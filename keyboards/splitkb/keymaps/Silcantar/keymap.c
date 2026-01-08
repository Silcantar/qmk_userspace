// Copyright 2024 Joshua Lucas (joshdlucas@gmail.com)
// SPDX-License-Identifier: GPL-2.0-or-later

// Everson Mono font is recommended to support all characters in this keymap.

// Dependencies
#include QMK_KEYBOARD_H
#include "features/select_word.h"
#include "features/send_unicode_set.h"

int current_highest_layer;

enum layers {
  _COLEMAK = 0,
  _QWERTY,
  _GREEK,
  _SYMBOL,
  _TENGWAR,
  _GAME,
  _NUMERIC,
  _FUNCTION,
  _MOUSE,
  _WINMAN,
  _LINE,
  _LAYER,
};

// Sections
#include "01_alias.c"

#include "02_custom_keycodes.c"

#include "03_key_overrides.c"

#include "04_macros.c"

#include "05_combos.c"

#include "06_tapdance_setup.c"

#include "07_layers.c"

#include "08_underglow.c"

#include "09_encoder.c"

#include "10_tapdance.c"

//#include "11_hand_swap.c"

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}