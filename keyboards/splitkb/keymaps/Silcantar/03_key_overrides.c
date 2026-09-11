// Key Overrides

/* Template for copying
const key_override_t OS_		= ko_make_basic(MOD_MASK_SHIFT, KC_,		KC_);
*/

const key_override_t OS_COMMA		= ko_make_basic(MOD_MASK_SHIFT, KC_COMMA,	KC_SEMICOLON);
const key_override_t OS_DOT			= ko_make_basic(MOD_MASK_SHIFT, KC_DOT,		KC_COLON);
const key_override_t OS_UNDS		= ko_make_basic(MOD_MASK_SHIFT, KC_UNDS,	KC_MINUS);

const key_override_t *key_overrides[] = {
	&OS_COMMA,
	&OS_DOT,
	&OS_UNDS,
};