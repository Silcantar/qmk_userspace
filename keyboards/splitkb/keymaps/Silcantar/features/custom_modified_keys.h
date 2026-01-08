// Copyright 2021 Google LLC.
// SPDX-License-Identifier: Apache-2.0

#pragma once
#include QMK_KEYBOARD_H

typedef struct {
  uint16_t keycode;
  uint16_t shifted_keycode;
} custom_modified_key_t;

//extern const custom_modified_key_t custom_shift_keys[];
//extern uint8_t NUM_CUSTOM_SHIFT_KEYS;

bool process_custom_modified_keys(
	uint16_t keycode, keyrecord_t *record, 
	uint8_t MOD_MASK, 
	custom_modified_key_t custom_modified_keys[], 
	uint16_t num_custom_modified_keys
);