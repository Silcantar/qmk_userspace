bool encoder_update_user(uint8_t index, bool clockwise) {
//	if (!encoder_update_user(index, clockwise)) {
//		return false;
//	}

	switch (get_highest_layer(layer_state)) {
		case _MOUSE:
			if (index == 0 || index == 1 || index == 2) {
				// Left side
				// Left/Right Arrow keys
				if (clockwise) {
					tap_code16(KC_MFFD);
				} else {
					tap_code16(KC_MRWD);
				}
				return false;
			} else if (index == 4 || index == 5 || index == 6) {
				// Right side
				// Up/Down Arrow Keys
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
				// Left/Right Arrow keys
				if (clockwise) {
					tap_code16(LCTL(KC_TAB));
				} else {
					tap_code16(LCTL(LSFT(KC_TAB)));
				}
				return false;
			} else if (index == 4 || index == 5 || index == 6) {
				// Right side
				// Up/Down Arrow Keys
				if (clockwise) {
					tap_code16(LGUI(KC_TAB));
				} else {
					tap_code16(LSG(KC_TAB));
				}
				return false;
			}
			return true;
		default:
			if (index == 0 || index == 1 || index == 2) {
				// Left side
				// Left/Right Arrow keys
				if (clockwise) {
					tap_code16(KC_RIGHT);
				} else {
					tap_code16(KC_LEFT);
				}
				return false;
			} else if (index == 4 || index == 5 || index == 6) {
				// Right side
				// Up/Down Arrow Keys
				if (clockwise) {
					tap_code16(KC_DOWN);
				} else {
					tap_code16(KC_UP);
				}
				return false;
			}
			return true;
	}
};