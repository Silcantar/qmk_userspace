// Aliases for readability
// Layer Switches
#define COLEMAK			TO(_COLEMAK)
#define QWERTY			TO(_QWERTY)
#define GREEK			TO(_GREEK)
#define SYMBOL			TO(_SYMBOL)
#define TENGWAR			TO(_TENGWAR)
#define GAME			TO(_GAME)
#define NUMERIC			TO(_NUMERIC)
#define FUNCTION		TO(_FUNCTION)
#define MOUSE			TO(_MOUSE)
#define WINMAN			TO(_WINMAN)
#define LINE			TO(_LINE)

// Default Layers
#define DF_COLEMAK		DF(_COLEMAK)
#define DF_QWERTY		DF(_QWERTY)

// Layer Taps
#define LAYERDOWN		LT(_LAYER, KC_0)
#define LAYERUP			LT(_LAYER, KC_1)

// Thumb Mod-Taps
#define RALT_TABL		MT(MOD_RALT, KC_0)
#define LGUI_ESC		MT(MOD_LGUI, KC_ESC)
#define LSFT_ENT		MT(MOD_LSFT, KC_ENT)
#define RALT_TAB		MT(MOD_RALT, KC_TAB)
#define RCTL_DEL		MT(MOD_RCTL, KC_DEL)
#define SH_SPACE		SH_T(KC_SPACE)
#define KEYLOCK			MT(QK_LOCK, KC_CAPS)

// One-Shot Mods
#define OSM_LALT		OSM(MOD_LALT)
#define OSM_RALT		OSM(MOD_RALT)
#define OSM_LCTL		OSM(MOD_LCTL)
#define OSM_RCTL		OSM(MOD_RCTL)
#define OSM_LGUI		OSM(MOD_LGUI)
#define OSM_RGUI		OSM(MOD_RGUI)
#define OSM_LSFT		OSM(MOD_LSFT)
#define OSM_RSFT		OSM(MOD_RSFT)

// Mod Masks
#define GET_ALL_MODS	(get_mods() | get_weak_mods() | get_oneshot_mods())
#define MOD_MASK_RALT	MOD_BIT(KC_RALT)
#define MOD_MASK_RAS	(MOD_MASK_RALT | MOD_MASK_SHIFT)
#define SHIFT_ACTIVE	(GET_ALL_MODS & MOD_MASK_SHIFT)
#define RALT_ACTIVE		(GET_ALL_MODS & MOD_MASK_RALT)
#define RAS_ACTIVE		(GET_ALL_MODS & MOD_MASK_SHIFT & MOD_MASK_RALT)
#define CLEAR_SHIFT		del_weak_mods(MOD_MASK_SHIFT); del_oneshot_mods(MOD_MASK_SHIFT); unregister_mods(MOD_MASK_SHIFT)

// Commands
// Function Layer
#define KC_TABL			S(KC_TAB)
#define CMD_TOP			C(KC_HOME)
#define CMD_BOTTOM		C(KC_END)
#define CMD_UNDO		C(KC_Z)
#define CMD_CUT			C(KC_X)
#define CMD_COPY		C(KC_C)
#define CMD_PASTE		C(KC_V)
#define CMD_PASTE_SP	C(S(KC_V))
#define CMD_REDO		C(S(KC_Z))
#define CMD_HELP		KC_F1
#define CMD_REFRSH		KC_F5
#define CMD_PRINT		C(KC_P)
#define CMD_SAVEAS		KC_F12
#define CMD_SYMBOL		LGUI(KC_DOT)
#define CMD_NEW			C(KC_N)
#define CMD_EDIT		KC_F2
#define CMD_SAVE		C(KC_S)
#define CMD_OPEN		C(KC_O)
#define CMD_CLSTAB		C(KC_W)
#define CMD_CLSWIN		C(KC_Q)
#define CMD_FIND		C(KC_F)
#define CMD_REPL		C(KC_H)
#define CMD_SELALL		C(KC_A)

// Mouse & Media Layer
#define CMD_MUTE_MIC	C(S(KC_M))

// Window Management Layer
#define FILES			LGUI(KC_E)
#define MON_LEFT		LSG(KC_LEFT)
#define MON_RIGHT		LSG(KC_RIGHT)
#define SNAP_LEFT		LGUI(KC_LEFT)
#define SNAP_RIGHT		LGUI(KC_RIGHT)
#define MAXIMIZE		LGUI(KC_UP)
#define MINIMIZE		LGUI(KC_DOWN)
#define FULLSCREEN		KC_F11
#define RUN				LGUI(KC_R)
#define C_TAB			LCTL(KC_TAB)
#define CS_TAB			LCTL(LSFT(KC_TAB))
#define AS_TAB			LSA(KC_TAB)
#define A_TAB			LALT(KC_TAB)
#define SHOW_DTOP		LGUI(KC_D)
#define PEEK_DTOP		LGUI(KC_COMMA)
#define LOCK			LGUI(KC_L)
#define GUI1			LGUI(KC_1)
#define GUI2			LGUI(KC_2)
#define GUI3			LGUI(KC_3)
#define GUI4			LGUI(KC_4)
#define GUI5			LGUI(KC_5)
#define GUI6			LGUI(KC_6)
#define GUI7			LGUI(KC_7)
#define GUI8			LGUI(KC_8)
#define GUI9			LGUI(KC_9)
#define GUI0			LGUI(KC_0)

// One-Shot Layers
#define OSL_NUMERIC		OSL(_NUMERIC)
#define OSL_FUNCTION	OSL(_FUNCTION)
#define OSL_MOUSE		OSL(_MOUSE)
#define OSL_WINMAN		OSL(_WINMAN)
#define LALT_ENT		MT(MOD_LALT, KC_ENT)
#define LSFT_SPACE		MT(MOD_LSFT, KC_SPACE)

// Home Row Mods
	// Colemak
#define LGUI_A			MT(MOD_LGUI, KC_A)
#define LALT_R			MT(MOD_LALT, KC_R)
#define LCTL_S			MT(MOD_LCTL, KC_S)
#define LSFT_KC_T		MT(MOD_LSFT, KC_T)
#define RALT_G			MT(MOD_RALT, KC_G)
#define RALT_M			MT(MOD_RALT, KC_M)
#define RSFT_N			MT(MOD_RSFT, KC_N)
#define RCTL_E			MT(MOD_RCTL, KC_E)
#define LALT_I			MT(MOD_LALT, KC_I)
#define RGUI_O			MT(MOD_RGUI, KC_O)

	// Numeric
#define RALT_SLSH		MT(MOD_RALT, KC_SLSH)
#define RSFT_4			MT(MOD_RSFT, KC_4)
#define RSFT_0			MT(MOD_RSFT, KC_0)
#define RCTL_5			MT(MOD_RCTL, KC_5)
#define RCTL_1			MT(MOD_RCTL, KC_1)
#define LALT_6			MT(MOD_LALT, KC_6)
#define LALT_2			MT(MOD_LALT, KC_2)
#define RGUI_0			MT(MOD_RGUI, KC_0)
#define RGUI_3			MT(MOD_RGUI, KC_3)

	// Function
#define RALT_SYM		MT(MOD_RALT, KC_NO)
#define RSFT_NEW		MT(MOD_RSFT, KC_NO)
#define RCTL_EDIT		MT(MOD_RCTL, KC_F2)
#define LALT_SAVE		MT(MOD_LALT, KC_NO)
#define RGUI_OPEN		MT(MOD_RGUI, KC_NO)

// Bottom Row Mods
#define LALT_X			MT(MOD_LALT, KC_X)
#define LCTL_V			MT(MOD_LCTL, KC_V)
#define LSFT_C			MT(MOD_LSFT, KC_C)
#define LGUI_G			MT(MOD_LGUI, KC_G)
#define RGUI_M			MT(MOD_RGUI, KC_M)
#define RSFT_K			MT(MOD_RSFT, KC_K)
#define RCTL_COMMA		MT(MOD_RCTL, KC_COMMA)
#define RALT_DOT		MT(MOD_RALT, KC_DOT)

// Bottom Row Hold-Tap
#define UNDO_X		LT(0, KC_X)
#define CUT_V		LT(0, KC_V)
#define COPY_C		LT(0, KC_C)
#define PASTE_D		LT(0, KC_D)
#define REDO_Q		LT(0, KC_Q)
#define SAVE_W		LT(0, KC_W)
#define EDIT_F		LT(0, KC_F)
#define NEW_P		LT(0, KC_P)
#define SYM_B		LT(0, KC_B)

// Tapping Term Configuration
#define THUMB_TAP_TERM	TAPPING_TERM + 0
#define INSIDE_TAP_TERM	TAPPING_TERM + 0
#define INDEX_TAP_TERM	TAPPING_TERM - 50
#define MIDDLE_TAP_TERM	TAPPING_TERM + 0
#define RING_TAP_TERM	TAPPING_TERM + 50
#define PINKY_TAP_TERM	TAPPING_TERM + 50

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case RALT_G:
	case RALT_M:
	case RALT_SLSH:
	case RALT_SYM:
	case SYM_B:
	case REDO_Q:
		return INSIDE_TAP_TERM;
	case LSFT_KC_T:
	case RSFT_N:
	case RSFT_4:
	case RSFT_0:
	case RSFT_NEW:
	case NEW_P:
	case PASTE_D:
		return INDEX_TAP_TERM;
	case LCTL_S:
	case RCTL_E:
	case RCTL_5:
	case RCTL_1:
	case RCTL_EDIT:
	case EDIT_F:
	case COPY_C:
		return MIDDLE_TAP_TERM;
	case LALT_R:
	case LALT_I:
	case LALT_6:
	case LALT_2:
	case LALT_SAVE:
	case SAVE_W:
	case CUT_V:
		return RING_TAP_TERM;
	case LGUI_A:
	case RGUI_O:
	case RGUI_0:
	case RGUI_3:
	case RGUI_OPEN:
	case UNDO_X:
		return PINKY_TAP_TERM;
	default:
		return THUMB_TAP_TERM;
  }
}