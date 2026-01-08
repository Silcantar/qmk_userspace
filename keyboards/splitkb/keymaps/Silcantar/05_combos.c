enum combos {
	//CAPS_WORD,
	
	LD_COLEMAK,
	LD_QWERTY,
	LD_GREEK,
	LD_SYMBOL,
	LD_TENGWAR,
	LD_GAME,
	LD_NUMERIC,
	LD_FUNC,
	LD_MOUSE,
	LD_WINMAN,
	
	LU_COLEMAK,
	LU_QWERTY,
	LU_GREEK,
	LU_SYMBOL,
	LU_TENGWAR,
	LU_GAME,
	LU_NUMERIC,
	LU_FUNC,
	LU_MOUSE,
	LU_WINMAN,

	LALT_LOCK,
	RALT_LOCK,
	LCTL_LOCK,
	RCTL_LOCK,
	LGUI_LOCK,
	RGUI_LOCK,
};

//const uint16_t PROGMEM combo_caps_word[] = {

const uint16_t PROGMEM combo_layerdown_a[] = {CK_LAYERDOWN, KC_A, COMBO_END};
const uint16_t PROGMEM combo_layerdown_r[] = {CK_LAYERDOWN, KC_R, COMBO_END};
const uint16_t PROGMEM combo_layerdown_s[] = {CK_LAYERDOWN, KC_S, COMBO_END};
const uint16_t PROGMEM combo_layerdown_t[] = {CK_LAYERDOWN, KC_T, COMBO_END};
const uint16_t PROGMEM combo_layerdown_g[] = {CK_LAYERDOWN, LGUI_G, COMBO_END};
const uint16_t PROGMEM combo_layerdown_m[] = {CK_LAYERDOWN, RGUI_M, COMBO_END};
const uint16_t PROGMEM combo_layerdown_n[] = {CK_LAYERDOWN, KC_N, COMBO_END};
const uint16_t PROGMEM combo_layerdown_e[] = {CK_LAYERDOWN, KC_E, COMBO_END};
const uint16_t PROGMEM combo_layerdown_i[] = {CK_LAYERDOWN, KC_I, COMBO_END};
const uint16_t PROGMEM combo_layerdown_o[] = {CK_LAYERDOWN, KC_O, COMBO_END};

const uint16_t PROGMEM combo_layerup_a[] = {CK_LAYERUP, KC_A, COMBO_END};
const uint16_t PROGMEM combo_layerup_r[] = {CK_LAYERUP, KC_R, COMBO_END};
const uint16_t PROGMEM combo_layerup_s[] = {CK_LAYERUP, KC_S, COMBO_END};
const uint16_t PROGMEM combo_layerup_t[] = {CK_LAYERUP, KC_T, COMBO_END};
const uint16_t PROGMEM combo_layerup_g[] = {CK_LAYERUP, LGUI_G, COMBO_END};
const uint16_t PROGMEM combo_layerup_m[] = {CK_LAYERUP, RGUI_M, COMBO_END};
const uint16_t PROGMEM combo_layerup_n[] = {CK_LAYERUP, KC_N, COMBO_END};
const uint16_t PROGMEM combo_layerup_e[] = {CK_LAYERUP, KC_E, COMBO_END};
const uint16_t PROGMEM combo_layerup_i[] = {CK_LAYERUP, KC_I, COMBO_END};
const uint16_t PROGMEM combo_layerup_o[] = {CK_LAYERUP, KC_O, COMBO_END};

const uint16_t PROGMEM lalt_lock[] = {KC_CAPS, RALT_TABL, COMBO_END};
const uint16_t PROGMEM ralt_lock[] = {KC_CAPS, RALT_TAB, COMBO_END};
const uint16_t PROGMEM lctl_lock[] = {KC_CAPS, OSM_LCTL, COMBO_END};
const uint16_t PROGMEM rctl_lock[] = {KC_CAPS, OSM_RCTL, COMBO_END};
const uint16_t PROGMEM lgui_lock[] = {KC_CAPS, LGUI_ESC, COMBO_END};
const uint16_t PROGMEM rgui_lock[] = {KC_CAPS, OSM_RGUI, COMBO_END};

combo_t key_combos[] = {
	[LD_COLEMAK]	= COMBO(combo_layerdown_a, COLEMAK),
	[LD_QWERTY]		= COMBO(combo_layerdown_r, QWERTY),
	[LD_GREEK]		= COMBO(combo_layerdown_s, GREEK),
	[LD_SYMBOL]		= COMBO(combo_layerdown_t, SYMBOL),
	[LD_TENGWAR]	= COMBO(combo_layerdown_g, TENGWAR),
	[LD_GAME]		= COMBO(combo_layerdown_m, GAME),
	[LD_NUMERIC]	= COMBO(combo_layerdown_n, NUMERIC),
	[LD_FUNC]		= COMBO(combo_layerdown_e, FUNCTION),
	[LD_MOUSE]		= COMBO(combo_layerdown_i, MOUSE),
	[LD_WINMAN]		= COMBO(combo_layerdown_o, WINMAN),
	
	[LU_COLEMAK]	= COMBO(combo_layerup_a, COLEMAK),
	[LU_QWERTY]		= COMBO(combo_layerup_r, QWERTY),
	[LU_GREEK]		= COMBO(combo_layerup_s, GREEK),
	[LU_SYMBOL]		= COMBO(combo_layerup_t, SYMBOL),
	[LU_TENGWAR]	= COMBO(combo_layerup_g, TENGWAR),
	[LU_GAME]		= COMBO(combo_layerup_m, GAME),
	[LU_NUMERIC]	= COMBO(combo_layerup_n, NUMERIC),
	[LU_FUNC]		= COMBO(combo_layerup_e, FUNCTION),
	[LU_MOUSE]		= COMBO(combo_layerup_i, MOUSE),
	[LU_WINMAN]		= COMBO(combo_layerup_o, WINMAN),

	[LALT_LOCK]		= COMBO(lalt_lock, CK_LALTLOCK),
	[RALT_LOCK]		= COMBO(ralt_lock, CK_RALTLOCK),
	[LCTL_LOCK]		= COMBO(lctl_lock, CK_LCTLLOCK),
	[RCTL_LOCK]		= COMBO(rctl_lock, CK_RCTLLOCK),
	[LGUI_LOCK]		= COMBO(lgui_lock, CK_LGUILOCK),
	[RGUI_LOCK]		= COMBO(rgui_lock, CK_RGUILOCK),
};