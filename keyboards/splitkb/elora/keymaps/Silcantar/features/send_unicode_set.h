#pragma once
#include QMK_KEYBOARD_H

bool send_unicode_set(
	char default_value[],
	char shift_value[],
	char ralt_value[],
	char ralt_shift_value[]);