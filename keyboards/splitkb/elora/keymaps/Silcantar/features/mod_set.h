#pragma once
#include QMK_KEYBOARD_H

typedef struct {
	char base_value[];
	char shift_value[];
	char ralt_value[];
	char ras_value[];
} mod_set_t;