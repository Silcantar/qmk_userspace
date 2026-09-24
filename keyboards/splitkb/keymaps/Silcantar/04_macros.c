#define LAYER_CYCLE_START	_COLEMAK
#define LAYER_CYCLE_END		_LINE

int8_t current_layer;
int8_t next_layer;

bool mod_lock_active;

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
// Select Word Macro
	if (!process_select_word(keycode, record, CK_SELWORD)) { return false; }

	switch (keycode) {
		case F22_SPACE:
			unregister_code16(KC_F22);
			if (record->event.pressed) {
				if (record->tap.count) {
					tap_code16(KC_SPACE);
					return false;
				} else {
					register_code16(KC_F22);
					return false;
				}
			} else {
				unregister_code16(KC_F22);
				return false;
			}
			break;
	}

	if (record->event.pressed) {
		switch (keycode) {

		// Tap Overrides
			case CK_COPY:
				if (SHIFT_ACTIVE) {
					tap_code16(CMD_CUT);
				} else {
					tap_code16(CMD_COPY);
				}
				return false;
				break;
			case CK_PASTE:
				if (SHIFT_ACTIVE) {
					tap_code16(CMD_PASTE_SP);
				} else {
					tap_code16(CMD_PASTE);
				}
				return false;
				break;
			case RALT_TABL:
				if (record->tap.count) {
					tap_code16(KC_TABL);
					return false;
				}
				break;
			case LGUI_UNDO:
				if (record->tap.count) {
					tap_code16(CMD_UNDO);
					return false;
				}
				break;
			case LALT_CUT:
				if (record->tap.count) {
					tap_code16(CMD_CUT);
					return false;
				}
				break;
			case LCTL_COPY:
				if (record->tap.count) {
					tap_code16(CMD_COPY);
					return false;
				}
				break;
			case LSFT_PASTE:
				if (record->tap.count) {
					tap_code16(CMD_PASTE);
					return false;
				}
				break;
			case RALT_REDO:
				if (record->tap.count) {
					tap_code16(CMD_REDO);
					return false;
				}
				break;

		// Hold Overrides
			case LYRCLR_ESC:
				if (!record->tap.count && record->event.pressed) {
					clear_keyboard();
					clear_mods();
					unregister_code16(KC_F22);
					layer_clear();
					return false;
				}
				break;
			case SAVE_W:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_SAVE);
					return false;
				}
				break;
			case FIND_F:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_FIND);
					return false;
				}
				break;
			case NEW_P:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_NEW);
					return false;
				}
				break;
			case SYM_B:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_SYMBOL);
					return false;
				}
				break;
			case UNDO_X:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_UNDO);
					return false;
				}
				break;
			case CUT_V:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_CUT);
					return false;
				}
				break;
			case COPY_C:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_COPY);
					return false;
				}
				break;
			case PASTE_D:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_PASTE);
					return false;
				}
				break;
			case REDO_Q:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_REDO);
					return false;
				}
				break;
			case REPL_H:
				if (!record->tap.count && record->event.pressed) {
					tap_code16(CMD_REPL);
					return false;
				}
				break;

		// Layer Cycle Keys
			case CK_LYRCLR:
				layer_clear();
				return false;
			case LAYERDOWN:
				if (record->tap.count) {
					current_layer = get_highest_layer(layer_state);

					// Check if we are within the range, if not quit
					if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
						return false;
					}

					next_layer = current_layer - 1;
					if (next_layer < LAYER_CYCLE_START) {
						next_layer = LAYER_CYCLE_END;
					}
					layer_move(next_layer);
					return false;
				}
				break;

			case LAYERUP:
				if (record->tap.count) {
					current_layer = get_highest_layer(layer_state);

					// Check if we are within the range, if not quit
					if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
						return false;
					}

					next_layer = current_layer + 1;
					if (next_layer > LAYER_CYCLE_END) {
						next_layer = LAYER_CYCLE_START;
					}
					layer_move(next_layer);
					return false;
				}
				break;

		// Modifier Lock
			case KC_CAPS:
				if (mod_lock_active) {
					unregister_code(KC_LALT);
					unregister_code(KC_RALT);
					unregister_code(KC_LCTL);
					unregister_code(KC_RCTL);
					unregister_code(KC_LGUI);
					unregister_code(KC_RGUI);
					mod_lock_active = false;
					return false;
				} else {
					return true;
				}
				break;
			case CK_LALTLOCK:
				mod_lock_active = true;
				register_code(KC_LALT);
				return false;
				break;
			case CK_RALTLOCK:
				mod_lock_active = true;
				register_code(KC_RALT);
				return false;
				break;
			case CK_LCTLLOCK:
				mod_lock_active = true;
				register_code(KC_LCTL);
				return false;
				break;
			case CK_RCTLLOCK:
				mod_lock_active = true;
				register_code(KC_RCTL);
				return false;
				break;
			case CK_LGUILOCK:
				mod_lock_active = true;
				register_code(KC_LGUI);
				return false;
				break;
			case CK_RGUILOCK:
				mod_lock_active = true;
				register_code(KC_RGUI);
				return false;
				break;

// Special Characters

	/* Template for copying
			case :			return send_unicode_set("", "", "", "");		break;
	*/

	// Whitespace
			case KC_SPACE:		return send_unicode_set("", "", " ", " ");	break;
			//case LSFT_ENT:		if (RALT_ACTIVE) { SEND_STRING(SS_DOWN(X_RALT) "u000a\n" SS_UP(X_RALT)); return false; } else { return true; } break;
			case RALT_TAB:		return send_unicode_set("", "", "    ", "    ");	break;

	// Colemak
		// Row 1
			case CK_INTBANG:	return send_unicode_set("‽", "•", "«", "»");	break;
			case KC_AT:			return send_unicode_set("", "‡", "̊", "̥");		break;
			case CK_NDASH:		return send_unicode_set("–", "—", "̅", "̲");		break;
			case CK_CHECK:		return send_unicode_set("✓", "✗", "☑", "⮽");	break;
		// Row 2
			case KC_Q:			return send_unicode_set("", "", "ø", "Ø");		break;
			case KC_W:			return send_unicode_set("", "", "ƿ", "Ƿ");		break;
			case KC_F:			return send_unicode_set("", "", "æ", "Æ");		break;
			case KC_P:			return send_unicode_set("", "", "œ", "Œ");		break;
			case KC_B:			return send_unicode_set("", "", "ɛ", "Ɛ");		break;
			case KC_J:			return send_unicode_set("", "", "ʤ", "ʝ");		break;
			case KC_L:			return send_unicode_set("", "", "ł", "Ł");		break;
			case KC_U:			return send_unicode_set("", "", "ü", "Ü");		break;
			case KC_Y:			return send_unicode_set("", "", "ə", "Ə");		break;
			case KC_Z:			return send_unicode_set("", "", "ʒ", "Ʒ");		break;
		// Row 3
			case KC_A:			return send_unicode_set("", "", "ä", "Ä");		break;
			case KC_R:			return send_unicode_set("", "", "ř", "Ř");		break;
			case KC_S:			return send_unicode_set("", "", "ß", "ẞ");		break;
			case KC_T:			return send_unicode_set("", "", "þ", "Þ");		break;
			case KC_G:			return send_unicode_set("", "", "ğ", "Ğ");		break;
			case KC_M:			return send_unicode_set("", "", "ŋ", "Ŋ");		break;
			case KC_N:			return send_unicode_set("", "", "ñ", "Ñ");		break;
			case KC_E:			return send_unicode_set("", "", "é", "É");		break;
			case KC_I:			return send_unicode_set("", "", "ï", "Ï");		break;
			case KC_O:			return send_unicode_set("", "", "ö", "Ö");		break;
		// Row 4
			case KC_X:			return send_unicode_set("", "", "ʃ", "Ʃ");		break;
			case KC_V:			return send_unicode_set("", "", "ʌ", "Ʌ");		break;
			case KC_C:			return send_unicode_set("", "", "ç", "Ç");		break;
			case KC_D:			return send_unicode_set("", "", "ð", "Ð");		break;
			case KC_MINUS:		return send_unicode_set("", "", "̄", "̱");		break;
			case KC_H:			return send_unicode_set("", "", "ħ", "Ħ");		break;
			case KC_K:			return send_unicode_set("", "", "ʔ", "ʕ");		break;
			case KC_COMMA:		return send_unicode_set("", "", "̧", "̨");		break;
			case KC_DOT:		return send_unicode_set("", "", "̈", "̇");		break;

	// Numeric
		// Row 1
			case CK_1_9:		return send_unicode_set("⅑", "⅑", "⅑", "⅑");	break;
			case CK_1_7:		return send_unicode_set("⅐", "⅐", "¹", "₁");	break;
			case CK_1_6:		return send_unicode_set("⅙", "⅕", "²", "₂");	break;
			case CK_1_3:		return send_unicode_set("⅓", "⅖", "³", "₃");	break;
			case CK_2_3:		return send_unicode_set("⅔", "⅗", "⁴", "₄");	break;
			case CK_5_6:		return send_unicode_set("⅚", "⅘", "⁵", "₅");	break;
			case CK_1_8:		return send_unicode_set("⅛", "⅛", "⁶", "₆");	break;
			case CK_1_4:		return send_unicode_set("¼", "⅜", "⁷", "₇");	break;
			case CK_1_2:		return send_unicode_set("½", "⅝", "⁸", "₈");	break;
			case CK_3_4:		return send_unicode_set("¾", "⅞", "⁹", "₉");	break;
			case CK_1_10:		return send_unicode_set("⅒", "⅒", "⁰", "₀");	break;
			case CK_ONE_OVER:	return send_unicode_set("⅟", "⅟", "ⁿ", "⅟");	break;
		// Row 2
			case KC_EQUAL:		return send_unicode_set("", "≠", "≡", "≔");		break;
			case KC_LBRC:		return send_unicode_set("", "", "⌈", "⌉");		break;
			case KC_LCBR:		return send_unicode_set("", "", "〈", "〉");		break;
			case KC_LPRN:		return send_unicode_set("", "", "⌊", "⌋");		break;
			case KC_LT:			return send_unicode_set("", "≤", "≪", "∈");		break;
			case KC_GT:			return send_unicode_set("", "≥", "≫", "∋");		break;
			case KC_EXLM:		return send_unicode_set("", "¡", "", "");		break;
			case KC_AMPR:		return send_unicode_set("", "‽", "", "");		break;
			// case KC_PIPE:		return send_unicode_set("", "€", "¥", "₹");		break;
			// case KC_TILDE:		return send_unicode_set("", "≈", "≅", "≉");		break;
			// case KC_CIRC:		return send_unicode_set("", "°", "", "°");		break;
		// Row 3
			case LGUI_7:		return send_unicode_set("", "√", "∛", "∜");		break;
			case LALT_5:		return send_unicode_set("", "€", "∧", "");		break;
			case LCTL_3:		return send_unicode_set("", "µ", "", "");		break;
			case LSFT_1:		return send_unicode_set("", "–", "", "");		break;
			case RALT_BSLS:		return send_unicode_set("", "", "∬", "∭");		break;
			case RALT_SLSH:		return send_unicode_set("", "÷", "", "∠");		break;
			case RSFT_0:		return send_unicode_set("", "@", "∪", "∩");	break;
			case RCTL_2:		return send_unicode_set("", "~", "", "");		break;
			case LALT_4:		return send_unicode_set("", "°", "∆", "");		break;
			case RGUI_6:		return send_unicode_set("", "", "∨", "");		break;
		// Row 4
			case KC_GRAVE:		return send_unicode_set("", "´", "‹", "›");		break;
			case KC_HASH:		return send_unicode_set("", "£", "⊂", "⊃");		break;
			case KC_ASTR:		return send_unicode_set("", "×", "∏", "∗");		break;
			case KC_9:			return send_unicode_set("", "—", "∇", "");		break;
			case KC_PERCENT:	return send_unicode_set("", "‰", "‱", "⁒");		break;
			case KC_DOLLAR:		return send_unicode_set("", "¢", "₿", "₪");		break;
			case KC_8:			return send_unicode_set("", "∞", "∝", "א");		break;
			case KC_PLUS:		return send_unicode_set("", "±", "∑", "∓");		break;
			// case CK_MICRO:		return send_unicode_set("µ", "♩", "∴", "♫");	break;
			// case CK_DIVIDE:		return send_unicode_set("÷", "−", "¬", "∡");	break;

	// Greek
			case CK_ALPHA:		return send_unicode_set("α", "Α", "ά", "");		break;
			case CK_BETA:		return send_unicode_set("β", "Β", "", "");		break;
			case CK_GAMMA:		return send_unicode_set("γ", "Γ", "", "");		break;
			case CK_DELTA:		return send_unicode_set("δ", "Δ", "", "");		break;
			case CK_EPSILON:	return send_unicode_set("ε", "Ε", "έ", "");		break;
			case CK_ZETA:		return send_unicode_set("ζ", "Ζ", "", "");		break;
			case CK_ETA:		return send_unicode_set("η", "Η", "ή", "");		break;
			case CK_THETA:		return send_unicode_set("θ", "Θ", "", "");		break;
			case CK_IOTA:		return send_unicode_set("ι", "Ι", "ί", "");		break;
			case CK_KAPPA:		return send_unicode_set("κ", "Κ", "", "");		break;
			case CK_LAMBDA:		return send_unicode_set("λ", "Λ", "", "");		break;
			case CK_MU:			return send_unicode_set("μ", "Μ", "", "");		break;
			case CK_NU:			return send_unicode_set("ν", "Ν", "", "");		break;
			case CK_XI:			return send_unicode_set("ξ", "Ξ", "", "");		break;
			case CK_OMICRON:	return send_unicode_set("ο", "Ο", "ό", "");		break;
			case CK_PI:			return send_unicode_set("π", "Π", "", "");		break;
			case CK_RHO:		return send_unicode_set("ρ", "Ρ", "", "");		break;
			case CK_SIGMA:		return send_unicode_set("σ", "Σ", "", "");		break;
			case CK_F_SIGMA:	return send_unicode_set("ς", "̈́", "", "");		break;
			case CK_TAU:		return send_unicode_set("τ", "Τ", "", "");		break;
			case CK_UPSILON:	return send_unicode_set("υ", "Υ", "ύ", "");		break;
			case CK_PHI:		return send_unicode_set("φ", "Φ", "", "");		break;
			case CK_CHI:		return send_unicode_set("χ", "Χ", "", "");		break;
			case CK_PSI:		return send_unicode_set("ψ", "Ψ", "", "");		break;
			case CK_OMEGA:		return send_unicode_set("ω", "Ω", "", "");		break;
			case CK_G_QUES:		return send_unicode_set(";", ":", "", "");		break;

	// Geometric Symbols
			case CK_COPYRIGHT:	return send_unicode_set("©", "℗", "☠", "☢");		break;
			case CK_ARRL_ARRR:	return send_unicode_set("⇆", "⇄", "⚒", "⚖");		break;
			case CK_ARRU_ARRD:	return send_unicode_set("⇅", "⇵", "⚓︎", "⚗");		break;
			case CK_ARRUD:		return send_unicode_set("↕", "⇕", "⚔", "⚘");		break;
			case CK_ARRLR:		return send_unicode_set("↔", "⇔", "⚕", "⚙");		break;
			case CK_TRADEMARK:	return send_unicode_set("™", "®", "☣", "☤");		break;
			case CK_CIRCLE:		return send_unicode_set("○", "●", "☆", "★");		break;
			case CK_ARRNW:		return send_unicode_set("↖", "⇖", "⚛", "⚠");		break;
			case CK_ARRU:		return send_unicode_set("↑", "⇑", "⚡︎", "⛏");		break;
			case CK_ARRNE:		return send_unicode_set("↗", "⇗", "", "");		break;
			case CK_TRI_U:		return send_unicode_set("△", "▲", "♂", "");		break;
			case CK_SQUARE:		return send_unicode_set("□", "■", "", "");		break;
			case CK_ARRL:		return send_unicode_set("←", "⇐", "", "");		break;
			case CK_ARRCW:		return send_unicode_set("↻", "↺", "☮", "☯");		break;
			case CK_ARRR:		return send_unicode_set("→", "⇒", "☸", "");		break;
			case CK_TRI_R:		return send_unicode_set("▷", "▶", "♀", "");		break;
			case CK_TRI_L:		return send_unicode_set("◁", "◀", "⛤", "⛧");		break;
			case CK_ARRSW:		return send_unicode_set("↙", "⇙", "⛵︎", "");		break;
			case CK_ARRD:		return send_unicode_set("↓", "⇓", "", "");		break;
			case CK_ARRSE:		return send_unicode_set("↘", "⇘", "", "");		break;
			case CK_TRI_D:		return send_unicode_set("▽", "▼", "", "");		break;

	// Emoji
			case CK_PENCIL:		return send_unicode_set("✏", "✂", "", "");		break;
			case CK_APPLE:		return send_unicode_set("🍎", "🥑", "⛆", "⛈");	break;
			case CK_PIZZA:		return send_unicode_set("🍕", "🥩", "⛅︎", "");	break;
			case CK_SUN:		return send_unicode_set("☀", "🌧", "☁", "☃");		break;
			case CK_PEACH:		return send_unicode_set("🍑", "🍆", "", "");	break;
			case CK_DOG:		return send_unicode_set("🐕", "🐈", "", "");	break;
			case CK_SHRUG:		return send_unicode_set("🤷", "🤦", "", "");	break;
			case CK_THUMBU:		return send_unicode_set("👍", "👎", "", "");	break;
			case CK_POOP:		return send_unicode_set("💩", "💀", "", "");	break;
			case CK_HEART:		return send_unicode_set("❤", "💔", "", "");	break;
			case CK_MINDBLOWN:	return send_unicode_set("🤯", "😱", "", "");	break;
			case CK_SILLY:		return send_unicode_set("😜", "🤐", "", "");	break;
			case CK_SMILE:		return send_unicode_set("😀", "😁", "", "");	break;
			case CK_EYEROLL:	return send_unicode_set("🙄", "😬", "", "");	break;
			case CK_CRYING:		return send_unicode_set("😢", "😐", "", "");	break;
			case CK_TREX:		return send_unicode_set("🦖", "🦕", "", "");	break;
			case CK_SUS:		return send_unicode_set("🤨", "🧐", "", "");	break;
			case CK_SHADES:		return send_unicode_set("😎", "😍", "", "");	break;
			case CK_PARTY:		return send_unicode_set("🥳", "😇", "", "");	break;
			case CK_TIGER:		return send_unicode_set("🐯", "🦄", "", "");	break;

	// Tengwar
		// Row 1
			case CK_TECCONUQ:	return send_unicode_set("", "", "", "");		break;
			case CK_T1:			return send_unicode_set("", "", "", "");		break;
			case CK_T2:			return send_unicode_set("", "", "", "");		break;
			case CK_T3:			return send_unicode_set("", "", "", "");		break;
			case CK_T4:			return send_unicode_set("", "", "", "");		break;
			case CK_T5:			return send_unicode_set("", "", "", "");		break;
			case CK_T6:			return send_unicode_set("", "", "", "");		break;
			case CK_T7:			return send_unicode_set("", "", "", "");		break;
			case CK_T8:			return send_unicode_set("", "", "", "");		break;
			case CK_T9:			return send_unicode_set("", "", "", "");		break;
			case CK_T0:			return send_unicode_set("", "", "", "");		break;
			case CK_T_SECTION:	return send_unicode_set("", "", "", "");		break;
		// Row 2
			case CK_HWESTAS:	return send_unicode_set("", "", "", "");	break;
			case CK_VALA:		return send_unicode_set("", "", "", "");	break;
			case CK_TELCO:		return send_unicode_set("", "", "", "");		break;
			case CK_PARMA:		return send_unicode_set("", "", "", "");		break;
			case CK_UMBAR:		return send_unicode_set("", "", "", "");		break;
			case CK_ANGA:		return send_unicode_set("", "", "", "");		break;
			case CK_LAMBE:		return send_unicode_set("", "", "", "");		break;
			case CK_REMPENUQ:	return send_unicode_set("", "", "", "");		break;
			case CK_ANNA:		return send_unicode_set("", "", "", "");		break;
			case CK_ESSE:		return send_unicode_set("", "", "‍", "");	break;
		// Row 3
			case CK_AMATIXE3:	return send_unicode_set("", "", "", "");		break;
			case CK_ROMEN:		return send_unicode_set("", "", "", "");		break;
			case CK_SILME:		return send_unicode_set("", "", "", "");		break;
			case CK_TINCO:		return send_unicode_set("", "", "", "");		break;
			case CK_UNGWE:		return send_unicode_set("", "", "", "");		break;
			case CK_MALTA:		return send_unicode_set("", "", "", "");		break;
			case CK_NUMEN:		return send_unicode_set("", "", "", "");		break;
			case CK_TECCO:		return send_unicode_set("", "", "", "");		break;
			case CK_AMATIXE1:	return send_unicode_set("", "", "", "");		break;
			case CK_REMPE:		return send_unicode_set("", "", "", "");		break;
		// Row 4
			case CK_SARINCE:	return send_unicode_set("", "", "", "");		break;
			case CK_FORMEN:		return send_unicode_set("", "", "", "");		break;
			case CK_CALMA:		return send_unicode_set("", "", "", "");		break;
			case CK_ANDO:		return send_unicode_set("", "", "", "");		break;
			case CK_T_LQUOTE:	return send_unicode_set("", "", "", "");		break;
			case CK_T_EXCLAIM:	return send_unicode_set("", "", "", "");		break;
			case CK_HYARMEN:	return send_unicode_set("", "", "", "");		break;
			case CK_QUESSE:		return send_unicode_set("", "", "", "");		break;
			case CK_T_COMMA:	return send_unicode_set("⸱", ":", "", "");		break;
			case CK_T_DOT:		return send_unicode_set("⁘", "⁝", "⸬", "");		break;

	// Box Drawing
		// Row 1
			case BD_LS:			return send_unicode_set("░", "▀", "", "");		break;
			case BD_BQB:		return send_unicode_set("▂", "▁", "", "");		break;
			case BD_BHB:		return send_unicode_set("▄", "▃", "", "");		break;
			case BD_BTB:		return send_unicode_set("▆", "▅", "", "");		break;
			case BD_FB:			return send_unicode_set("█", "▇", "", "");		break;
			case BD_DS:			return send_unicode_set("▓", "▉", "", "");		break;
			case BD_LTB:		return send_unicode_set("▊", "▋", "", "");		break;
			case BD_LHB:		return send_unicode_set("▌", "▍", "", "");		break;
			case BD_LQB:		return send_unicode_set("▎", "▏", "", "");		break;
			case BD_MS:			return send_unicode_set("▒", "▐", "", "");		break;
		// Row 2
			case BD_SDTW:		return send_unicode_set("╭", "╵", "", "");		break;
			case BD_SCNW:		return send_unicode_set("┌", "╓", "", "");		break;
			case BD_STN:		return send_unicode_set("┬", "╥", "", "");		break;
			case BD_SCNE:		return send_unicode_set("┐", "╖", "", "");		break;
			case BD_SDTN:		return send_unicode_set("╮", "╴", "", "");		break;
			case BD_DSTN:		return send_unicode_set("╱", "╳", "", "");		break;
			case BD_DCNW:		return send_unicode_set("╔", "╒", "", "");		break;
			case BD_DTN:		return send_unicode_set("╦", "╤", "", "");		break;
			case BD_DCNE:		return send_unicode_set("╗", "╕", "", "");		break;
			case BD_DSTE:		return send_unicode_set("╲", "╳", "", "");		break;

		// Row 3
			case BD_STW:		return send_unicode_set("├", "╟", "", "");		break;
			case BD_SX:			return send_unicode_set("┼", "╫", "", "");		break;
			case BD_SV:			return send_unicode_set("│", "┆", "", "");		break;
			case BD_SH:			return send_unicode_set("─", "┄", "", "");		break;
			case BD_STE:		return send_unicode_set("┤", "╢", "", "");		break;
			case BD_DTW:		return send_unicode_set("╠", "╞", "", "");		break;
			case BD_DH:			return send_unicode_set("═", "┈", "", "");		break;
			case BD_DV:			return send_unicode_set("║", "┊", "", "");		break;
			case BD_DX:			return send_unicode_set("╬", "╪", "", "");		break;
			case BD_DTE:		return send_unicode_set("╣", "╡", "", "");		break;

		// Row 4
			case BD_SDTS:		return send_unicode_set("╰", "╶", "", "");		break;
			case BD_SCSW:		return send_unicode_set("└", "╙", "", "");		break;
			case BD_STS:		return send_unicode_set("┴", "╨", "", "");		break;
			case BD_SCSE:		return send_unicode_set("┘", "╜", "", "");		break;
			case BD_SDTE:		return send_unicode_set("╯", "╷", "", "");		break;
			case BD_DSTW:		return send_unicode_set("▖", "▘", "", "");		break;
			case BD_DCSW:		return send_unicode_set("╚", "╘", "", "");		break;
			case BD_DTS:		return send_unicode_set("╩", "╧", "", "");		break;
			case BD_DCSE:		return send_unicode_set("╝", "╛", "", "");		break;
			case BD_DSTS:		return send_unicode_set("▗", "▝", "", "");		break;
		}
	} else {
		unregister_code16(keycode);
	}

	return true;
}