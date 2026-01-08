#include "send_unicode_set.h"
#include <string.h>

bool is_ascii(char string[], bool includeNonPrinting) {
	char firstAscii;
	char lastAscii;

	if (includeNonPrinting) {
		firstAscii = 0x01;
		lastAscii = 0xFF;
	} else {
		firstAscii = ' ';
		lastAscii = '~';
	}

	long i;
	for (i = 0; i < strlen(string); i++) {
		if (string[i] < firstAscii || string[i] > lastAscii) {
			return false;
		}
	}

	return true;
}

bool send_string_smart (char string[]) {
	if (string[0] == '\0') {
		return true;
	} else if (is_ascii(string, false)) {
		send_string(string);
		return false;
	} else {
		send_unicode_string(string);
		return false;
	}
}

bool send_unicode_set(
	char default_value[],
	char shift_value[],
	char ralt_value[],
	char ralt_shift_value[]) {
	
	char* value;

	uint8_t all_mods = (get_mods() | get_weak_mods() | get_oneshot_mods());
	
	if (all_mods == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RALT)) || all_mods == (MOD_BIT(KC_RSFT) | MOD_BIT(KC_RALT))) {
		value = ralt_shift_value;
	} else if (all_mods & MOD_MASK_SHIFT) {
		value = shift_value;
	} else if (all_mods & MOD_BIT(KC_RALT)) {
		value = ralt_value;
	} else {
		value = default_value;
	}
	
	return send_string_smart(value);
}