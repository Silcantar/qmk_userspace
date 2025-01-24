/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicative that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currently not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustrating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'numeric' tap dance.
/*static td_tap_t td_swap_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};*/

// Create an instance of 'td_tap_t' for the 'numeric' tap dance.
static td_tap_t td_numeric_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create an instance of 'td_tap_t' for the 'numeric' tap dance.
static td_tap_t td_function_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create an instance of 'td_tap_t' for the 'numeric' tap dance.
static td_tap_t td_mouse_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create an instance of 'td_tap_t' for the 'numeric' tap dance.
static td_tap_t td_winman_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

/*void td_swap_finished(tap_dance_state_t *state, void *user_data) {
    td_swap_tap_state.state = cur_dance(state);
    switch (td_swap_tap_state.state) {
        case TD_SINGLE_TAP: layer_clear(); break;
        case TD_SINGLE_HOLD: swap_hands_on(); break;
        case TD_DOUBLE_TAP: swap_hands_toggle(); break;
        default: break;
    }
}

void td_swap_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_swap_tap_state.state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: swap_hands_off(); break;
        case TD_DOUBLE_TAP: break;
        default: break;
    }
    td_numeric_tap_state.state = TD_NONE;
}*/

void td_numeric_finished(tap_dance_state_t *state, void *user_data) {
    td_numeric_tap_state.state = cur_dance(state);
    switch (td_numeric_tap_state.state) {
        case TD_SINGLE_TAP: set_oneshot_layer(_NUMERIC, ONESHOT_START); break;
        case TD_SINGLE_HOLD: layer_on(_NUMERIC); break;
        case TD_DOUBLE_TAP: layer_invert(_NUMERIC); break;
        default: break;
    }
}

void td_numeric_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_numeric_tap_state.state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_SINGLE_HOLD: layer_off(_NUMERIC); break;
        case TD_DOUBLE_TAP: break;
        default: break;
    }
    td_numeric_tap_state.state = TD_NONE;
}

void td_func_finished(tap_dance_state_t *state, void *user_data) {
    td_function_tap_state.state = cur_dance(state);
    switch (td_function_tap_state.state) {
        case TD_SINGLE_TAP: set_oneshot_layer(_FUNCTION, ONESHOT_START); break;
        case TD_SINGLE_HOLD: layer_on(_FUNCTION); break;
        case TD_DOUBLE_TAP: layer_invert(_FUNCTION); break;
        default: break;
    }
}

void td_func_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_function_tap_state.state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_SINGLE_HOLD: layer_off(_FUNCTION); break;
        case TD_DOUBLE_TAP: break;
        default: break;
    }
    td_function_tap_state.state = TD_NONE;
}

void td_mouse_finished(tap_dance_state_t *state, void *user_data) {
    td_mouse_tap_state.state = cur_dance(state);
    switch (td_mouse_tap_state.state) {
        case TD_SINGLE_TAP: set_oneshot_layer(_MOUSE, ONESHOT_START); break;
        case TD_SINGLE_HOLD: layer_on(_MOUSE); break;
        case TD_DOUBLE_TAP: layer_invert(_MOUSE); break;
        default: break;
    }
}

void td_mouse_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_mouse_tap_state.state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_SINGLE_HOLD: layer_off(_MOUSE); break;
        case TD_DOUBLE_TAP: break;
        default: break;
    }
    td_mouse_tap_state.state = TD_NONE;
}

void td_winman_finished(tap_dance_state_t *state, void *user_data) {
    td_winman_tap_state.state = cur_dance(state);
    switch (td_winman_tap_state.state) {
        case TD_SINGLE_TAP: set_oneshot_layer(_WINMAN, ONESHOT_START); break;
        case TD_SINGLE_HOLD: layer_on(_WINMAN); break;
        case TD_DOUBLE_TAP: layer_invert(_WINMAN); break;
        default: break;
    }
}

void td_winman_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_winman_tap_state.state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_SINGLE_HOLD: layer_off(_WINMAN); break;
        case TD_DOUBLE_TAP: break;
        default: break;
    }
    td_winman_tap_state.state = TD_NONE;
}

// Macros
void td_exclams(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("¡!");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_EXCLAIM);
	}
}

void td_fsquote(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("‘’");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(CK_LSQUOTE);
	}
}

void td_fdquote(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("“”");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(CK_LDQUOTE);
	}
}

void td_ques(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("¿?");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_QUES);
	}
}

void td_dquotes(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("\"\"");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_QUOTE);
	}
}

void td_squotes(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("''");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_Q);
	}
}

void td_uscores(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("__");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_MINUS);
	}
}

void td_pipes(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("||");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_PIPE);
	}
}

void td_angles(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("<>");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_LT);
	}
}

void td_braces(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("{}");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_LCBR);
	}
}

void td_parens(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("()");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_LPRN);
	}
}

void td_bracks(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("[]");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_LBRC);
	}
}

void td_pascomm(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("(**)");
		tap_code16(KC_LEFT);
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_GT);
	}
}

void td_stars(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("**");
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_PAST);
	}
}

void td_ccomm(tap_dance_state_t *state, void *user_data) {
	if (state->count >= 2) {
		send_unicode_string("/**/");
		tap_code16(KC_LEFT);
		tap_code16(KC_LEFT);
	} else {
		tap_code16(KC_CIRC);
	}
}


tap_dance_action_t tap_dance_actions[] = {
	//[_TD_SWAP]		= ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_swap_finished, td_swap_reset),
	// Layers
	[_TD_NUMERIC]	= ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_numeric_finished, td_numeric_reset),
	[_TD_FUNC]		= ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_func_finished, td_func_reset),
	[_TD_MOUSE]		= ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mouse_finished, td_mouse_reset),
	[_TD_WINMAN]	= ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_winman_finished, td_winman_reset),
	
	// Macros
	[_EXCLAMS]		= ACTION_TAP_DANCE_FN(td_exclams),
	[_FSQUOTE]		= ACTION_TAP_DANCE_FN(td_fsquote),
	[_FDQUOTE]		= ACTION_TAP_DANCE_FN(td_fdquote),
	[_QUES]			= ACTION_TAP_DANCE_FN(td_ques),
	[_DQUOTES]		= ACTION_TAP_DANCE_FN(td_dquotes),
	[_SQUOTES]		= ACTION_TAP_DANCE_FN(td_squotes),
	[_USCORES]		= ACTION_TAP_DANCE_FN(td_uscores),
	[_PIPES]		= ACTION_TAP_DANCE_FN(td_pipes),
	[_ANGLES]		= ACTION_TAP_DANCE_FN(td_angles),
	[_BRACES]		= ACTION_TAP_DANCE_FN(td_braces),
	[_PARENS]		= ACTION_TAP_DANCE_FN(td_parens),
	[_BRACKS]		= ACTION_TAP_DANCE_FN(td_bracks),
	[_PASCOMM]		= ACTION_TAP_DANCE_FN(td_pascomm),
	[_STARS]		= ACTION_TAP_DANCE_FN(td_stars),
	[_CCOMM]		= ACTION_TAP_DANCE_FN(td_ccomm),
};