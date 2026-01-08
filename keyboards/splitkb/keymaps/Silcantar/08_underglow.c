#define DEFAULT_SAT	192
#define DEFAULT_VAL	128

#define HUE_ORANGE	15
#define HUE_GOLD	45
#define HUE_YELLOW	75
#define HUE_LIME	105
#define HUE_GREEN	135
#define HUE_CYAN	165
#define HUE_AZURE	195
#define HUE_BLUE	225
#define HUE_VIOLET	255
#define HUE_PURPLE	285
#define HUE_MAGENTA	315
#define HUE_RED		345

// Caps Word Indication

#define INDICATOR_SAT		255
#define INDICATOR_VAL		192
#define PTHUMB_LED_INDEX	5
#define STHUMB_LED_INDEX	6

bool caps_word_active;
int8_t dyn_macro_record_direction;

int8_t hue_angle_to_byte(int32_t angle) {
	return (int8_t)(angle * 256 / 360);
}

void rgblight_sethsv_angle(int16_t hue, int8_t saturation, int8_t value){
	rgblight_sethsv(hue_angle_to_byte(hue), saturation, value);
}

void set_indicator_led (int16_t color) {
	rgblight_sethsv_at(hue_angle_to_byte(color), INDICATOR_SAT, INDICATOR_VAL, PTHUMB_LED_INDEX);
	rgblight_sethsv_at(hue_angle_to_byte(color), INDICATOR_SAT, INDICATOR_VAL, STHUMB_LED_INDEX);
}

void reset_indicator_led (void) {
	rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), PTHUMB_LED_INDEX);
	rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), STHUMB_LED_INDEX);
}

void caps_word_set_user(bool active) {
	caps_word_active = active;
}

bool dynamic_macro_record_start_user(int8_t direction) {
	dyn_macro_record_direction = direction;
	return false;
}

bool dynamic_macro_record_end_user(int8_t direction) {
	dyn_macro_record_direction = 0;
	return false;
}

void update_indicator_led(void){
	if (dyn_macro_record_direction == -1) {
		set_indicator_led(HUE_ORANGE);
	} else if (dyn_macro_record_direction == 1) {
		set_indicator_led(HUE_YELLOW);
	} else if (caps_word_active) {
		set_indicator_led(HUE_GREEN);
	} else if (host_keyboard_led_state().caps_lock) {
		set_indicator_led(HUE_RED);
	} else {
		reset_indicator_led();
	}
}

bool led_update_user(led_t led_state) {
	update_indicator_led();
	return false;
}

// Layer Indication Underglow
layer_state_t layer_state_set_user(layer_state_t state) {
	current_highest_layer = get_highest_layer(state);
	
	switch (get_highest_layer(state)) {
	case _COLEMAK:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_BLUE, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _QWERTY:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (0, 0, DEFAULT_VAL);				// White
		break;
	case _GREEK:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_AZURE, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _SYMBOL:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_GOLD, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _TENGWAR:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_LIME, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _GAME:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_MAGENTA, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _NUMERIC:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_CYAN, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _FUNCTION:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_GREEN, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _MOUSE:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_ORANGE, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _WINMAN:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_PURPLE, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _LINE:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv_angle (HUE_VIOLET, DEFAULT_SAT, DEFAULT_VAL);
		break;
	case _LAYER:
		rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
		rgblight_sethsv (0, 0, 0);
		break;
	}
	
	update_indicator_led();
	return state;
}