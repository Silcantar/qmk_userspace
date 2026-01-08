custom_modified_key_t custom_shift_keys[] = {
	{CK_COPY,		CK_CUT},
	{CK_PASTE,		CK_PASTEP},
	{KC_BSPC,		KC_DEL},
	{DM_REC1,		DM_REC2},
	{KC_GRAVE,		CK_ACUTE},
	{CK_INTBANG,	CK_BULLET}
	
	{KC_COMMA,		KC_SCLN},
	{KC_DOT,		KC_COLON},
};

uint8_t num_custom_shift_keys = sizeof(custom_shift_keys) / sizeof(custom_modified_key_t);

custom_modified_key_t custom_ralt_keys[] = {
	{0, 0},
};


const custom_shift_key_t custom_shift_keys[] = {
// Colemak
	{CK_COPY,		CK_CUT},
	{CK_PASTE,		CK_PASTEP},
	{KC_BSPC,		KC_DEL},
	{DM_REC1,		DM_REC2},
	{KC_GRAVE,		CK_ACUTE},
	{CK_INTBANG,	CK_BULLET},
	
	{KC_COMMA,		KC_SCLN},
	{KC_DOT,		KC_COLON},

// Numeric
	{KC_LCBR,		KC_RCBR},
	{KC_LPRN,		KC_RPRN},
	{KC_LBRC,		KC_RBRC},
	
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

/*custom_modified_key_t custom_ralt_keys[] = {
	{0, 0},
};*/