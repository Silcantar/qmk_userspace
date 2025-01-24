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

// Default Layers
#define DF_COLEMAK		DF(_COLEMAK)
#define DF_QWERTY		DF(_QWERTY)

// One-Shot Layers
#define OSL_NUMERIC		OSL(_NUMERIC)
#define OSL_FUNCTION	OSL(_FUNCTION)
#define OSL_MOUSE		OSL(_MOUSE)
#define OSL_WINMAN		OSL(_WINMAN)

// Mod-Taps
#define SH_SPACE		SH_T(KC_SPACE)
#define LALT_ENT		MT(MOD_LALT, KC_ENT)
#define RCTL_TAB		MT(MOD_RCTL, KC_TAB)
#define LSFT_SPACE		MT(MOD_LSFT, KC_SPACE)


// Bottom Row Mods
#define LALT_X			MT(MOD_LALT, KC_X)
#define LCTL_V			MT(MOD_LCTL, KC_V)
#define LSFT_C			MT(MOD_LSFT, KC_C)
#define LGUI_G			MT(MOD_LGUI, KC_G)
#define RGUI_M			MT(MOD_RGUI, KC_M)
#define RSFT_K			MT(MOD_RSFT, KC_K)
#define RCTL_COMMA		MT(MOD_RCTL, KC_COMMA)
#define RALT_DOT		MT(MOD_RALT, KC_DOT)

// One-Shot Mods
#define OSM_LALT		OSM(MOD_LALT)
#define OSM_RALT		OSM(MOD_RALT)
#define OSM_LCTL		OSM(MOD_LCTL)
#define OSM_RCTL		OSM(MOD_RCTL)
#define OSM_LGUI		OSM(MOD_LGUI)
#define OSM_RGUI		OSM(MOD_RGUI)
#define OSM_LSFT		OSM(MOD_LSFT)
#define OSM_RSFT		OSM(MOD_RSFT)

// Commands
// Function Layer
#define CMD_TOP			C(KC_HOME)
#define CMD_BOTTOM		C(KC_END)
#define CMD_UNDO		C(KC_Z)
#define CMD_CUT			C(KC_X)
//#define CMD_COPY		C(KC_C)
//#define CMD_PASTE		C(KC_V)
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
#define AS_TAB			LSG(KC_TAB)
#define A_TAB			LGUI(KC_TAB)
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