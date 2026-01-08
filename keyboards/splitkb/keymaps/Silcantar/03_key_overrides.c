// Key Overrides

/* Template for copying
const key_override_t OS_		= ko_make_basic(MOD_MASK_SHIFT, KC_,		KC_);
*/

//const key_override_t OS_BSPC		= ko_make_basic(MOD_MASK_SHIFT, KC_BSPC,	KC_DEL);
const key_override_t OS_COMMA		= ko_make_basic(MOD_MASK_SHIFT, KC_COMMA,	KC_SEMICOLON);
const key_override_t OS_DOT			= ko_make_basic(MOD_MASK_SHIFT, KC_DOT,		KC_COLON);
const key_override_t OS_UNDS		= ko_make_basic(MOD_MASK_SHIFT, KC_UNDS,	KC_MINUS);
const key_override_t OS_1			= ko_make_basic(MOD_MASK_SHIFT, KC_1,		S(KC_A));
const key_override_t OS_2			= ko_make_basic(MOD_MASK_SHIFT, KC_2,		S(KC_B));
const key_override_t OS_3			= ko_make_basic(MOD_MASK_SHIFT, KC_3,		S(KC_C));
const key_override_t OS_4			= ko_make_basic(MOD_MASK_SHIFT, KC_4,		S(KC_D));
const key_override_t OS_5			= ko_make_basic(MOD_MASK_SHIFT, KC_5,		S(KC_E));
const key_override_t OS_6			= ko_make_basic(MOD_MASK_SHIFT, KC_6,		S(KC_F));

const key_override_t *key_overrides[] = {
//	&OS_BSPC,
	&OS_COMMA,
	&OS_DOT,
	&OS_UNDS,
	&OS_1,
	&OS_2,
	&OS_3,
	&OS_4,
	&OS_5,
	&OS_6,
};