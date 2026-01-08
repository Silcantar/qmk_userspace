bool encoder_update_user(uint8_t index, bool clockwise) {
//	if (!encoder_update_user(index, clockwise)) {
//		return false;
//	}

	switch (get_highest_layer(layer_state)) {
		case _MOUSE:
			if (index == 0 || index == 1 || index == 2) {
				// Left side
				// Media Scrub
				if (clockwise) {
					tap_code16(KC_MFFD);
				} else {
					tap_code16(KC_MRWD);
				}
				return false;
			} else if (index == 4 || index == 5 || index == 6) {
				// Right side
				// Volume
				if (clockwise) {
					tap_code16(KC_VOLU);
				} else {
					tap_code16(KC_VOLD);
				}
				return false;
			}
			return true;
		case _WINMAN:
			if (index == 0 || index == 1 || index == 2) {
				// Left side
				// Cycle Tabs
				if (clockwise) {
					tap_code16(LCTL(KC_TAB));
				} else {
					tap_code16(LCTL(LSFT(KC_TAB)));
				}
				return false;
			} else if (index == 4 || index == 5 || index == 6) {
				// Right side
				// Cycle Windows
				if (clockwise) {
					tap_code16(LGUI(KC_TAB));
				} else {
					tap_code16(LSG(KC_TAB));
				}
				return false;
			}
			return true;
		case _FUNCTION:
			if (index == 0 || index == 1 || index == 2) {
				// Left side
				// Mouse Wheel Left/Right
				if (clockwise) {
					tap_code16(MS_WHLR);
				} else {
					tap_code16(MS_WHLL);
				}
				return false;
			} else if (index == 4 || index == 5 || index == 6) {
				// Right side
				// Mouse Wheel Up/Down
				if (clockwise) {
					tap_code16(MS_WHLD);
				} else {
					tap_code16(MS_WHLU);
				}
				return false;
			}
			return true;
		default:
			if (index == 0 || index == 1 || index == 2) {
				// Left side
				// Left/Right Arrow keys
				if (clockwise) {
					tap_code16(MS_WHLR);
				} else {
					tap_code16(MS_WHLL);
				}
				return false;
			} else if (index == 4 || index == 5 || index == 6) {
				// Right side
				// Up/Down Arrow Keys
				if (clockwise) {
					tap_code16(MS_WHLD);
				} else {
					tap_code16(MS_WHLU);
				}
				return false;
			}
			return true;
	}
};