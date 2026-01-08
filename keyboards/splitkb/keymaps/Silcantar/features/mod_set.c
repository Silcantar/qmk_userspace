#define MOD_MASK_RALT	MOD_BIT(KC_RALT)
#define MOD_MASK_RAS	(MOD_MASK_RALT | MOD_MASK_SHIFT)

#include "mod_set.h"

bool send_mod_set(
	uint16_t keycode,
	keyrecord_t *record,
	mod_set_t mod_set) {
		
		const uint8_t mods = get_mods() | get_weak_mods() | get_oneshot_mods();
		
		switch (mods) {
			case MOD_MASK_SHIFT:
				send_unicode_string(mod_set.shift_value);
				break;
			case MOD_MASK_RALT:
				send_unicode_string(mod_set.ralt_value);
				break;
			case MOD_MASK_RAS:
				send_unicode_string(mod_set.ras_value);
				break;
			default:
				send_unicode_string(mod_set.base_value);
				break;
		}
	}