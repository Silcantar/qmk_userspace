// Tap Dance
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enum
enum {
	_TD_SWAP,
	// Layers
	_TD_NUMERIC,
	_TD_FUNC,
	_TD_MOUSE,
	_TD_WINMAN,
	
	// Macros
	_EXCLAMS,
	_FSQUOTE,
	_FDQUOTE,
	_QUES,
	_QUOTES, 
	_USCORES,
	_PIPES,
	_ANGLES,
	_BRACES,
	_PARENS,
	_BRACKS,
	_PASCOMM,
	_STARS,
	_CCOMM,
};

//#define TD_SWAP		TD(_TD_SWAP)

#define TD_NUMERIC	TD(_TD_NUMERIC)
#define TD_FUNC		TD(_TD_FUNC)
#define TD_MOUSE	TD(_TD_MOUSE)
#define TD_WINMAN	TD(_TD_WINMAN)

#define TD_ANGLES	TD(_ANGLES)
#define TD_BRACKS	TD(_BRACKS)
#define TD_BRACES	TD(_BRACES)
#define TD_PARENS	TD(_PARENS)

#define TD_EXCLAMS	TD(_EXCLAMS)
#define TD_FSQUOTE	TD(_FSQUOTE)
#define TD_FDQUOTE	TD(_FDQUOTE)
#define TD_QUES		TD(_QUES)
#define TD_QUOTES	TD(_QUOTES)
#define TD_USCORES	TD(_USCORES)
#define TD_PIPES	TD(_PIPES)
#define TD_PASCOMM	TD(_PASCOMM)
#define TD_STARS	TD(_STARS)
#define TD_CCOMM	TD(_CCOMM)

// Layer Tapdance Setup
td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
//void td_swap_finished(tap_dance_state_t *state, void *user_data);
//void td_swap_reset(tap_dance_state_t *state, void *user_data);

void td_numeric_finished(tap_dance_state_t *state, void *user_data);
void td_numeric_reset(tap_dance_state_t *state, void *user_data);

void td_func_finished(tap_dance_state_t *state, void *user_data);
void td_func_reset(tap_dance_state_t *state, void *user_data);

void td_mouse_finished(tap_dance_state_t *state, void *user_data);
void td_mouse_reset(tap_dance_state_t *state, void *user_data);

void td_winman_finished(tap_dance_state_t *state, void *user_data);
void td_winman_reset(tap_dance_state_t *state, void *user_data);

void td_angles_finished(tap_dance_state_t *state, void *user_data);
void td_angles_reset(tap_dance_state_t *state, void *user_data);

void td_bracks_finished(tap_dance_state_t *state, void *user_data);
void td_bracks_reset(tap_dance_state_t *state, void *user_data);

void td_braces_finished(tap_dance_state_t *state, void *user_data);
void td_braces_reset(tap_dance_state_t *state, void *user_data);

void td_parens_finished(tap_dance_state_t *state, void *user_data);
void td_parens_reset(tap_dance_state_t *state, void *user_data);