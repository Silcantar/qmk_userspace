#define DEFAULT_SAT	192
#define DEFAULT_VAL	128

#define HUE_ORANGE	13
#define HUE_YELLOW	38
#define HUE_LIME	63
#define HUE_GREEN	88
#define HUE_CYAN	113
#define HUE_AZURE	138
#define HUE_BLUE	163
#define HUE_PURPLE	188
#define HUE_MAGENTA	213
#define HUE_RED		235

// Layer Indication Underglow
layer_state_t layer_state_set_user(layer_state_t state) {
	current_highest_layer = get_highest_layer(state);
	
	switch (get_highest_layer(state)) {
	case _COLEMAK:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_BLUE, DEFAULT_SAT, DEFAULT_VAL);	// Blue
		break;
	case _QWERTY:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (0, 0, DEFAULT_VAL);				// White
		break;
	case _NUMERIC:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_CYAN, DEFAULT_SAT, DEFAULT_VAL);	// Cyan
		break;
	case _FUNCTION:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_GREEN, DEFAULT_SAT, DEFAULT_VAL);		// Green
		break;
	case _MOUSE:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_ORANGE, DEFAULT_SAT, DEFAULT_VAL);		// Orange
		break;
	case _WINMAN:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_PURPLE, DEFAULT_SAT, DEFAULT_VAL);	// Purple
		break;
	case _GREEK:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_AZURE, DEFAULT_SAT, DEFAULT_VAL);	// Azure
		break;
	case _SYMBOL:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_YELLOW, DEFAULT_SAT, DEFAULT_VAL);		// Gold
		break;
	case _TENGWAR:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_LIME, DEFAULT_SAT, DEFAULT_VAL);		// Chartreuse
		break;
	case _GAME:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (HUE_MAGENTA, DEFAULT_SAT, DEFAULT_VAL);	// Magenta
		break;
	}
	return state;
}

// Caps Word Indication

#define CAPS_WORD_COLOR HUE_RED, 255, 192	// Red
#define LTHUMB_LED_INDEX 5
#define RTHUMB_LED_INDEX 11

void caps_word_set_user(bool active) {
    if (active) {
        rgblight_sethsv_at(CAPS_WORD_COLOR, LTHUMB_LED_INDEX);
        rgblight_sethsv_at(CAPS_WORD_COLOR, RTHUMB_LED_INDEX);
    } else {
        rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), LTHUMB_LED_INDEX);
        rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), RTHUMB_LED_INDEX);
    }
}