#define LAYER_CYCLE_START	_COLEMAK
#define LAYER_CYCLE_END		_WINMAN

uint8_t current_layer;
uint8_t next_layer;

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	//process_custom_modified_keys(keycode, record, MOD_MASK_SHIFT, custom_shift_keys, num_custom_shift_keys);
	//if (!process_custom_modified_keys(keycode, record, MOD_MASK_SHIFT, custom_shift_keys, num_custom_shift_keys)) { return false; }
	// Select Word Macro
	if (!process_select_word(keycode, record, CK_SELWORD)) { return false; }

// Macros
	if (record->event.pressed) {
		switch (keycode) {
			case CK_CUT:
				tap_code16(C(KC_X));
				break;
			case CK_COPY:
				tap_code16(C(KC_C));
				break;
			case CK_PASTE:
				tap_code16(C(KC_V));
				break;
			case CK_PASTEP:
				tap_code16(C(S(KC_V)));
				break;
				
	// Layer Cycle Keys
			case CK_LYRCLR:
				layer_clear();
				return false;
				break;
				
			case CK_LAYERDOWN:
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
				break;

			case CK_LAYERUP:
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
				break;
				
	// Intercept Mod-Taps
			case LALT_X:
				switch (get_highest_layer(layer_state)) {
					case _COLEMAK:
						tap_code16(KC_X);		break;
					case _QWERTY:
						tap_code16(KC_Z);		break;
					case _NUMERIC:
						tap_code16(CK_BULLET);	break;
					case _FUNCTION:
						tap_code16(CMD_UNDO);	break;
					case _MOUSE:
						tap_code16(CMD_UNDO);	break;
					case _WINMAN:
						tap_code16(GUI1);		break;
					case _GREEK:
						tap_code16(CK_CHI);		break;
					case _SYMBOL:
						tap_code16(CK_SQUARE);	break;
					case _TENGWAR:
						tap_code16(CK_SARINCE);	break;
					//case _GAME:						Mod-Tap disabled on Game layer for performance.
					//	tap_code16(KC_6);		break;
				}
				return false;
				break;
				
			case LCTL_V:
				switch (get_highest_layer(layer_state)) {
					case _COLEMAK:
						tap_code16(KC_V);		break;
					case _QWERTY:
						tap_code16(KC_X);		break;
					case _NUMERIC:
						tap_code16(KC_HASH);	break;
					case _FUNCTION:
						tap_code16(CK_CUT);		break;
					case _MOUSE:
						tap_code16(CK_CUT);		break;
					case _WINMAN:
						tap_code16(GUI2);		break;
					case _GREEK:
						tap_code16(CK_OMEGA);	break;
					case _SYMBOL:
						tap_code16(CK_ARRSE);	break;
					case _TENGWAR:
						tap_code16(CK_FORMEN);	break;
					//case _GAME:
					//	tap_code16(KC_7);		break;
				}
				return false;
				break;
				
			case LSFT_C:
				switch (get_highest_layer(layer_state)) {
					case _COLEMAK:
						tap_code16(KC_C);		break;
					case _QWERTY:
						tap_code16(KC_C);		break;
					case _NUMERIC:
						tap_code16(KC_DOLLAR);	break;
					case _FUNCTION:
						tap_code16(CK_COPY);	break;
					case _MOUSE:
						tap_code16(CK_COPY);	break;
					case _WINMAN:
						tap_code16(GUI3);		break;
					case _GREEK:
						tap_code16(CK_PSI);		break;
					case _SYMBOL:
						tap_code16(CK_ARRD);	break;
					case _TENGWAR:
						tap_code16(CK_CALMA);	break;
					//case _GAME:
					//	tap_code16(KC_8);		break;
				}
				return false;
				break;
				
			case LGUI_G:
				switch (get_highest_layer(layer_state)) {
					case _COLEMAK:
						tap_code16(KC_G);		break;
					case _QWERTY:
						tap_code16(KC_G);		break;
					case _NUMERIC:
						tap_code16(KC_GT);		break;
					case _FUNCTION:
						tap_code16(KC_PGDN);	break;
					case _MOUSE:
						tap_code16(MS_WHLD);	break;
					case _WINMAN:
						tap_code16(MINIMIZE);	break;
					case _GREEK:
						tap_code16(CK_GAMMA);	break;
					case _SYMBOL:
						tap_code16(CK_TRI_R);	break;
					case _TENGWAR:
						tap_code16(CK_UNGWE);	break;
					//case _GAME:
					//	tap_code16(KC_F);		break;
				}
				return false;
				break;
				
			case RGUI_M:
				switch (get_highest_layer(layer_state)) {
					case _COLEMAK:
						tap_code16(KC_M);		break;
					case _QWERTY:
						tap_code16(KC_H);		break;
					case _NUMERIC:
						tap_code16(KC_PPLS);	break;
					case _FUNCTION:
						tap_code16(CMD_SYMBOL);	break;
					case _MOUSE:
						tap_code16(KC_VOLD);	break;
					case _WINMAN:
						tap_code16(KC_NO);		break;
					case _GREEK:
						tap_code16(CK_MU);		break;
					case _SYMBOL:
						tap_code16(CK_MINDBLOWN);	break;
					case _TENGWAR:
						tap_code16(CK_MALTA);	break;
					//case _GAME:
					//	tap_code16(KC_H);		break;
				}
				return false;
				break;
				
			case RSFT_K:
				switch (get_highest_layer(layer_state)) {
					case _COLEMAK:
						tap_code16(KC_K);		break;
					case _QWERTY:
						tap_code16(KC_COMMA);	break;
					case _NUMERIC:
						tap_code16(KC_2);		break;
					case _FUNCTION:
						tap_code16(CMD_REPL);	break;
					case _MOUSE:
						tap_code16(MS_BTN5);	break;
					case _WINMAN:
						tap_code16(GUI8);		break;
					case _GREEK:
						tap_code16(CK_KAPPA);	break;
					case _SYMBOL:
						tap_code16(CK_SHADES);	break;
					case _TENGWAR:
						tap_code16(CK_QUESSE);	break;
					//case _GAME:
					//	tap_code16(KC_8);		break;
				}
				return false;
				break;
				
			case RCTL_COMMA:
				switch (get_highest_layer(layer_state)) {
					case _COLEMAK:
						tap_code16(KC_COMMA);	break;
					case _QWERTY:
						tap_code16(KC_DOT);		break;
					case _NUMERIC:
						tap_code16(KC_3);		break;
					case _FUNCTION:
						tap_code16(CMD_SELALL);	break;
					case _MOUSE:
						tap_code16(MS_BTN6);	break;
					case _WINMAN:
						tap_code16(GUI9);		break;
					case _GREEK:
						tap_code16(KC_COMMA);	break;
					case _SYMBOL:
						tap_code16(CK_PARTY);	break;
					case _TENGWAR:
						tap_code16(CK_T_COMMA);	break;
					//case _GAME:
					//	tap_code16(KC_9);		break;
				}
				return false;
				break;
				
			case RALT_DOT:
				switch (get_highest_layer(layer_state)) {
					case _COLEMAK:
						tap_code16(KC_DOT);		break;
					case _QWERTY:
						tap_code16(KC_SLASH);	break;
					case _NUMERIC:
						tap_code16(KC_DOT);		break;
					case _FUNCTION:
						tap_code16(CK_SELWORD); break;
					case _MOUSE:
						tap_code16(MS_BTN7);	break;
					case _WINMAN:
						tap_code16(GUI0);		break;
					case _GREEK:
						tap_code16(KC_DOT);		break;
					case _SYMBOL:
						tap_code16(CK_TIGER);	break;
					case _TENGWAR:
						tap_code16(CK_T_DOT);	break;
					//case _GAME:
					//	tap_code16(KC_0);		break;
				}
				return false;
				break;
				

	/* Template for copying
			case CK_:		if (record->event.pressed) { send_unicode_string(""); } return false;		break;
	*/

	// Whitespace
			case CK_NBSP:			send_unicode_string(" ");return false;		break;
			case CK_LF:				SEND_STRING("\n");			return false;		break;
			case CK_SPCTAB:			SEND_STRING("    ");		return false;		break;

	// Colemak
	// Base / Shift
			case CK_ACUTE:			send_unicode_string("´");	return false;		break;
			case CK_INTBANG:		send_unicode_string("‽");	return false;		break; 
			case CK_BULLET:			send_unicode_string("•");	return false;		break; 
			case CK_INV_EXCLAIM:	send_unicode_string("¡");	return false;		break; 
			case CK_DDAGGER:		send_unicode_string("‡");	return false;		break; 
			case CK_LSQUOTE:		send_unicode_string("‘");	return false;		break; 
			case CK_RSQUOTE:		send_unicode_string("’");	return false;		break; 
			case CK_LDQUOTE:		send_unicode_string("“");	return false;		break; 
			case CK_RDQUOTE:		send_unicode_string("”");	return false;		break; 
			case CK_DAGGER:			send_unicode_string("†");	return false;		break; 
			case CK_INV_QUES:		send_unicode_string("¿");	return false;		break; 
			case CK_NDASH:			send_unicode_string("–");	return false;		break; 
			case CK_MDASH:			send_unicode_string("—");	return false;		break; 
			case CK_MICRO:			send_unicode_string("µ");	return false;		break; 
			case CK_EIGHTHNOTE:		send_unicode_string("♪");	return false;		break;

	// AltGr
			case CK_LSAQUOTE:		send_unicode_string("‹");	return false;		break;
			case CK_RSAQUOTE:		send_unicode_string("›");	return false;		break;
			case CK_C_CIRC:			send_unicode_string("̂");	return false; 		break;
			case CK_C_CARON:		send_unicode_string("̌");	return false; 		break;
			case CK_C_RING:			send_unicode_string("̊");	return false; 		break;
			case CK_C_RINGB:		send_unicode_string("̥");	return false; 		break;
			case CK_C_GRAVE:		send_unicode_string("̀");	return false; 		break;
			case CK_C_GRAVED:		send_unicode_string("̏");	return false; 		break;
			case CK_DQUOTE_LO:		send_unicode_string("„");	return false;		break;
			case CK_C_BREVE:		send_unicode_string("̆");	return false; 		break;
			case CK_C_BREVEI:		send_unicode_string("̑");	return false;		break; 
			case CK_C_TILDE:		send_unicode_string("̃");	return false; 		break;
			case CK_C_HORN:			send_unicode_string("̛");	return false; 		break;
			case CK_LDAQUOTE:		send_unicode_string("«");	return false;		break;
			case CK_RDAQUOTE:		send_unicode_string("»");	return false;		break;
			case CK_C_BAR_O:		send_unicode_string("̅");	return false; 		break;
			case CK_C_BAR_B:		send_unicode_string("̲");	return false; 		break;
			case CK_O_SLASH:		send_unicode_string("ø");	return false;		break;
			case CK_C_O_SLASH:		send_unicode_string("Ø");	return false;		break;
			case CK_STRUT:			send_unicode_string("ʌ");	return false;		break;
			case CK_C_STRUT:		send_unicode_string("Ʌ");	return false;		break;
			case CK_AE:				send_unicode_string("æ");	return false;		break;
			case CK_C_AE:			send_unicode_string("Æ");	return false;		break;
			case CK_OE:				send_unicode_string("œ");	return false;		break;
			case CK_C_OE:			send_unicode_string("Œ");	return false;		break;
			case CK_E_ROUND:		send_unicode_string("ɛ");	return false;		break;
			case CK_C_E_ROUND:		send_unicode_string("Ɛ");	return false;		break;
			case CK_DEZH:			send_unicode_string("ʤ");	return false;		break;
			case CK_L_BAR:			send_unicode_string("ł");	return false;		break;
			case CK_C_L_BAR:		send_unicode_string("Ł");	return false;		break;
			case CK_U_DIAER:		send_unicode_string("ü");	return false;		break;
			case CK_C_U_DIAER:		send_unicode_string("Ü");	return false;		break;
			case CK_SCHWA:			send_unicode_string("ə");	return false;		break;
			case CK_C_SCHWA:		send_unicode_string("Ə");	return false;		break;
			case CK_EZH:			send_unicode_string("ʒ");	return false;		break;
			case CK_C_EZH:			send_unicode_string("Ʒ");	return false;		break;
			case CK_A_DIAER:		send_unicode_string("ä");	return false;		break;
			case CK_C_A_DIAER:		send_unicode_string("Ä");	return false;		break;
			case CK_R_CARON:		send_unicode_string("ř");	return false;		break;
			case CK_C_R_CARON:		send_unicode_string("Ř");	return false;		break;
			case CK_ESSZETT:		send_unicode_string("ß");	return false;		break;
			case CK_C_ESSZETT:		send_unicode_string("ẞ");	return false;		break;
			case CK_THORN:			send_unicode_string("þ");	return false;		break;
			case CK_C_THORN:		send_unicode_string("Þ");	return false;		break;
			case CK_G_BREVE:		send_unicode_string("ğ");	return false;		break;
			case CK_C_G_BREVE:		send_unicode_string("Ğ");	return false;		break;
			case CK_ENG:			send_unicode_string("ŋ");	return false;		break;
			case CK_C_ENG:			send_unicode_string("Ŋ");	return false;		break;
			case CK_ENYE:			send_unicode_string("ñ");	return false;		break;
			case CK_C_ENYE:			send_unicode_string("Ñ");	return false;		break;
			case CK_E_ACUTE:		send_unicode_string("é");	return false;		break;
			case CK_C_E_ACUTE:		send_unicode_string("É");	return false;		break;
			case CK_I_DIAER:		send_unicode_string("ï");	return false;		break;
			case CK_C_I_DIAER:		send_unicode_string("Ï");	return false;		break;
			case CK_O_DIAER:		send_unicode_string("ö");	return false;		break;
			case CK_C_O_DIAER:		send_unicode_string("Ö");	return false;		break;
			case CK_ESH:			send_unicode_string("ʃ");	return false;		break;
			case CK_C_ESH:			send_unicode_string("Ʃ");	return false;		break;
			case CK_U_CIRC:			send_unicode_string("û");	return false;		break;
			case CK_C_U_CIRC:		send_unicode_string("Û");	return false;		break;
			case CK_CEDILLE:		send_unicode_string("ç");	return false;		break;
			case CK_C_CEDILLE:		send_unicode_string("Ç");	return false;		break;
			case CK_ETH:			send_unicode_string("ð");	return false;		break;
			case CK_C_ETH:			send_unicode_string("Ð");	return false;		break;
			case CK_C_ACUTE:		send_unicode_string("́");	return false; 		break;
			case CK_C_ACUTED:		send_unicode_string("̋");	return false; 		break;
			case CK_C_MACRON:		send_unicode_string("̄");	return false; 		break;
			case CK_C_MACRONB:		send_unicode_string("̱");	return false; 		break;
			case CK_H_BAR:			send_unicode_string("ħ");	return false;		break;
			case CK_C_H_BAR:		send_unicode_string("Ħ");	return false;		break;
			case CK_STOP:			send_unicode_string("ʔ");	return false;		break;
			case CK_C_CEDILLA:		send_unicode_string("̧");	return false; 		break;
			case CK_C_DIAER:		send_unicode_string("̈");	return false; 		break;
			case CK_C_DOT:			send_unicode_string("̇");	return false; 		break;

	// Numeric
			case CK_1_9:			send_unicode_string("⅑");	return false;		break;
			case CK_1_7:			send_unicode_string("⅐");	return false;		break;
			case CK_TRIPLEZERO:		send_string("000");			return false;		break;
			case CK_1_6:			send_unicode_string("⅙");	return false;		break;
			case CK_1_5:			send_unicode_string("⅕");	return false;		break;
			case CK_1_3:			send_unicode_string("⅓");	return false;		break;
			case CK_2_5	:			send_unicode_string("⅖");	return false;		break;
			case CK_2_3:			send_unicode_string("⅔");	return false;		break;
			case CK_3_5	:			send_unicode_string("⅗");	return false;		break;
			case CK_5_6:			send_unicode_string("⅚");	return false;		break;
			case CK_4_5	:			send_unicode_string("⅘");	return false;		break;
			case CK_1_8:			send_unicode_string("⅛");	return false;		break;
			case CK_1_4:			send_unicode_string("¼");	return false;		break;
			case CK_3_8	:			send_unicode_string("⅜");	return false;		break;
			case CK_1_2:			send_unicode_string("½");	return false;		break;
			case CK_5_8	:			send_unicode_string("⅝");	return false;		break;
			case CK_3_4:			send_unicode_string("¾");	return false;		break;
			case CK_7_8	:			send_unicode_string("⅞");	return false;		break;
			case CK_1_10:			send_unicode_string("⅒");	return false;		break;
			case CK_ONE_OVER:		send_unicode_string("⅟");	return false;		break;
			case CK_EURO:			send_unicode_string("€");	return false;		break;
			case CK_ALMOST_EQ:		send_unicode_string("≈");	return false;		break;
			case CK_DEGREE:			send_unicode_string("°");	return false;		break;
			case CK_PERMILLE:		send_unicode_string("‰");	return false;		break;
			case CK_INTEGRAL:		send_unicode_string("∫");	return false;		break;
			case CK_MULTSIGN:		send_unicode_string("×");	return false;		break;
			case CK_RADICAL:		send_unicode_string("√");	return false;		break;
			case CK_INFINITY:		send_unicode_string("∞");	return false;		break;
			case CK_PARTDIFF:		send_unicode_string("∂");	return false;		break;
			case CK_FRACSLASH:		send_unicode_string("∕");	return false;		break;
			case CK_LTEQUAL:		send_unicode_string("≤");	return false;		break;
			case CK_GTEQUAL:		send_unicode_string("≥");	return false;		break;
			case CK_PLUSMINUS:		send_unicode_string("±");	return false;		break;
			case CK_CHECK:			send_unicode_string("✓");	return false;		break;
			case CK_BALLOTX:		send_unicode_string("✗");	return false;		break;
			case CK_GBP:			send_unicode_string("£");	return false;		break;
			case CK_CENT:			send_unicode_string("¢");	return false;		break;
			case CK_NOTEQUAL:		send_unicode_string("≠");	return false;		break;
			case CK_DIVIDE:			send_unicode_string("÷");	return false;		break;
			case CK_MINUSSIGN:		send_unicode_string("−");	return false;		break;

	// Greek
			case CK_ALPHA:			send_unicode_string("α");	return false;		break;
			case CK_C_ALPHA:		send_unicode_string("Α");	return false;		break;
			case CK_BETA:			send_unicode_string("β");	return false;		break;
			case CK_C_BETA:			send_unicode_string("Β");	return false;		break;
			case CK_GAMMA:			send_unicode_string("γ");	return false;		break;
			case CK_C_GAMMA:		send_unicode_string("Γ");	return false;		break;
			case CK_DELTA:			send_unicode_string("δ");	return false;		break;
			case CK_C_DELTA:		send_unicode_string("Δ");	return false;		break;
			case CK_EPSILON:		send_unicode_string("ε");	return false;		break;
			case CK_C_EPSILON:		send_unicode_string("Ε");	return false;		break;
			case CK_ZETA:			send_unicode_string("ζ");	return false;		break;
			case CK_C_ZETA:			send_unicode_string("Ζ");	return false;		break;
			case CK_ETA:			send_unicode_string("η");	return false;		break;
			case CK_C_ETA:			send_unicode_string("Η");	return false;		break;
			case CK_THETA:			send_unicode_string("θ");	return false;		break;
			case CK_C_THETA:		send_unicode_string("Θ");	return false;		break;
			case CK_IOTA:			send_unicode_string("ι");	return false;		break;
			case CK_C_IOTA:			send_unicode_string("Ι");	return false;		break;
			case CK_KAPPA:			send_unicode_string("κ");	return false;		break;
			case CK_C_KAPPA:		send_unicode_string("Κ");	return false;		break;
			case CK_LAMBDA:			send_unicode_string("λ");	return false;		break;
			case CK_C_LAMBDA:		send_unicode_string("Λ");	return false;		break;
			case CK_MU:				send_unicode_string("μ");	return false;		break;
			case CK_C_MU:			send_unicode_string("Μ");	return false;		break;
			case CK_NU:				send_unicode_string("ν");	return false;		break;
			case CK_C_NU:			send_unicode_string("Ν");	return false;		break;
			case CK_XI:				send_unicode_string("ξ");	return false;		break;
			case CK_C_XI:			send_unicode_string("Ξ");	return false;		break;
			case CK_OMICRON:		send_unicode_string("ο");	return false;		break;
			case CK_C_OMICRON:		send_unicode_string("Ο");	return false;		break;
			case CK_PI:				send_unicode_string("π");	return false;		break;
			case CK_C_PI:			send_unicode_string("Π");	return false;		break;
			case CK_RHO:			send_unicode_string("ρ");	return false;		break;
			case CK_C_RHO:			send_unicode_string("Ρ");	return false;		break;
			case CK_SIGMA:			send_unicode_string("σ");	return false;		break;
			case CK_C_SIGMA:		send_unicode_string("Σ");	return false;		break;
			case CK_F_SIGMA:		send_unicode_string("ς");	return false;		break;
			case CK_TAU:			send_unicode_string("τ");	return false;		break;
			case CK_C_TAU:			send_unicode_string("Τ");	return false;		break;
			case CK_UPSILON:		send_unicode_string("υ");	return false;		break;
			case CK_C_UPSILON:		send_unicode_string("Υ");	return false;		break;
			case CK_PHI:			send_unicode_string("φ");	return false;		break;
			case CK_C_PHI:			send_unicode_string("Φ");	return false;		break;
			case CK_CHI:			send_unicode_string("χ");	return false;		break;
			case CK_C_CHI:			send_unicode_string("Χ");	return false;		break;
			case CK_PSI:			send_unicode_string("ψ");	return false;		break;
			case CK_C_PSI:			send_unicode_string("Ψ");	return false;		break;
			case CK_OMEGA:			send_unicode_string("ω");	return false;		break;
			case CK_C_OMEGA:		send_unicode_string("Ω");	return false;		break;
			case CK_G_QUES:			send_unicode_string(";");	return false;		break;
			case CK_DTONOS:			send_unicode_string("◌̈́");	return false;		break;

	// Geometric Symbols
			case CK_COPYRIGHT:		send_unicode_string("©");	return false;		break;
			case CK_PATENT:			send_unicode_string("℗");	return false;		break;
			case CK_ARRL_ARRR:		send_unicode_string("⇆");	return false;		break;
			case CK_ARRR_ARRL:		send_unicode_string("⇄");	return false;		break;
			case CK_ARRU_ARRD:		send_unicode_string("⇅");	return false;		break;
			case CK_ARRD_ARRU:		send_unicode_string("⇵");	return false;		break;
			case CK_ARRUD:			send_unicode_string("↕");	return false;		break;
			case CK_ARRUDF:			send_unicode_string("⇕");	return false;		break;
			case CK_ARRLR:			send_unicode_string("↔");	return false;		break;
			case CK_ARRLRF:			send_unicode_string("⇔");	return false;		break;
			case CK_TRADEMARK:		send_unicode_string("™");	return false;		break;
			case CK_REGTM:			send_unicode_string("®");	return false;		break;
			case CK_CIRCLE:			send_unicode_string("○");	return false;		break;
			case CK_CIRCLE_F:		send_unicode_string("●");	return false;		break;
			case CK_ARRNW:			send_unicode_string("↖");	return false;		break;
			case CK_ARRNWF:			send_unicode_string("⇖");	return false;		break;
			case CK_ARRU:			send_unicode_string("↑");	return false;		break;
			case CK_ARRUF:			send_unicode_string("⇑");	return false;		break;
			case CK_ARRNE:			send_unicode_string("↗");	return false;		break;
			case CK_ARRNEF:			send_unicode_string("⇗");	return false;		break;
			case CK_TRI_U:			send_unicode_string("△");	return false;		break;
			case CK_TRI_UF:			send_unicode_string("▲");	return false;		break;
			case CK_SQUARE:			send_unicode_string("□");	return false;		break;
			case CK_SQUARE_F:		send_unicode_string("■");	return false;		break;
			case CK_ARRL:			send_unicode_string("←");	return false;		break;
			case CK_ARRLF:			send_unicode_string("⇐");	return false;		break;
			case CK_ARRCW:			send_unicode_string("↻");	return false;		break;
			case CK_ARRCCW:			send_unicode_string("↺");	return false;		break;
			case CK_ARRR:			send_unicode_string("→");	return false;		break;
			case CK_ARRRF:			send_unicode_string("⇒");	return false;		break;
			case CK_TRI_R:			send_unicode_string("▷");	return false;		break;
			case CK_TRI_RF:			send_unicode_string("▶");	return false;		break;
			case CK_TRI_L:			send_unicode_string("◁");	return false;		break;
			case CK_TRI_LF:			send_unicode_string("◀");	return false;		break;
			case CK_ARRSW:			send_unicode_string("↙");	return false;		break;
			case CK_ARRSWF:			send_unicode_string("⇙");	return false;		break;
			case CK_ARRD:			send_unicode_string("↓");	return false;		break;
			case CK_ARRDF:			send_unicode_string("⇓");	return false;		break;
			case CK_ARRSE:			send_unicode_string("↘");	return false;		break;
			case CK_ARRSEF:			send_unicode_string("⇘");	return false;		break;
			case CK_TRI_D:			send_unicode_string("▽");	return false;		break;
			case CK_TRI_DF:			send_unicode_string("▼");	return false;		break;

	// Emoji
			case CK_PENCIL:			send_unicode_string("✏");	return false;		break;
			case CK_SCISSORS:		send_unicode_string("✂");	return false;		break;
			case CK_APPLE:			send_unicode_string("🍎");	return false;		break;
			case CK_AVOCADO:		send_unicode_string("🥑");	return false;		break;
			case CK_PIZZA:			send_unicode_string("🍕");	return false;		break;
			case CK_MEAT:			send_unicode_string("🥩");	return false;		break;
			case CK_SUN:			send_unicode_string("☀");	return false;		break;
			case CK_RAIN:			send_unicode_string("🌧");	return false;		break;
			case CK_PEACH:			send_unicode_string("🍑");	return false;		break;
			case CK_EGGPLANT:		send_unicode_string("🍆");	return false;		break;
			case CK_DOG:			send_unicode_string("🐕");	return false;		break;
			case CK_CAT:			send_unicode_string("🐈");	return false;		break;
			case CK_SHRUG:			send_unicode_string("🤷");	return false;		break;
			case CK_FACEPALM:		send_unicode_string("🤦");	return false;		break;
			case CK_THUMBU:			send_unicode_string("👍");	return false;		break;
			case CK_THUMBD:			send_unicode_string("👎");	return false;		break;
			case CK_POOP:			send_unicode_string("💩");	return false;		break;
			case CK_SKULL:			send_unicode_string("💀");	return false;		break;
			case CK_HEART:			send_unicode_string("❤");	return false;		break;
			case CK_HEARTB:			send_unicode_string("💔");	return false;		break;
			case CK_MINDBLOWN:		send_unicode_string("🤯");	return false;		break;
			case CK_SCREAM:			send_unicode_string("😱");	return false;		break;
			case CK_SILLY:			send_unicode_string("😜");	return false;		break;
			case CK_ZIPPED:			send_unicode_string("🤐");	return false;		break;
			case CK_SMILE:			send_unicode_string("😀");	return false;		break;
			case CK_GRIN:			send_unicode_string("😁");	return false;		break;
			case CK_EYEROLL:		send_unicode_string("🙄");	return false;		break;
			case CK_GRIMACE:		send_unicode_string("😬");	return false;		break;
			case CK_CRYING:			send_unicode_string("😢");	return false;		break;
			case CK_NEUTRAL:		send_unicode_string("😐");	return false;		break;
			case CK_TREX:			send_unicode_string("🦖");	return false;		break;
			case CK_SAUROPOD:		send_unicode_string("🦕");	return false;		break;
			case CK_SUS:			send_unicode_string("🤨");	return false;		break;
			case CK_MONOCLE:		send_unicode_string("🧐");	return false;		break;
			case CK_SHADES:			send_unicode_string("😎");	return false;		break;
			case CK_INLOVE:			send_unicode_string("😍");	return false;		break;
			case CK_PARTY:			send_unicode_string("🥳");	return false;		break;
			case CK_HALO:			send_unicode_string("😇");	return false;		break;
			case CK_TIGER:			send_unicode_string("🐯");	return false;		break;
			case CK_UNICORN:		send_unicode_string("🦄");	return false;		break;
			
	// Tengwar
			case CK_TINCO:			send_unicode_string("");	return false;		break;
			case CK_PARMA:			send_unicode_string("");	return false;		break;
			case CK_CALMA:			send_unicode_string("");	return false;		break;
			case CK_QUESSE:			send_unicode_string("");	return false;		break;
			case CK_ANDO:			send_unicode_string("");	return false;		break;
			case CK_UMBAR:			send_unicode_string("");	return false;		break;
			case CK_ANGA:			send_unicode_string("");	return false;		break;
			case CK_UNGWE:			send_unicode_string("");	return false;		break;
			case CK_THULE:			send_unicode_string("");	return false;		break;
			case CK_FORMEN:			send_unicode_string("");	return false;		break;
			case CK_HARMA:			send_unicode_string("");	return false;		break;
			case CK_HWESTA:			send_unicode_string("");	return false;		break;
			case CK_ANTO:			send_unicode_string("");	return false;		break;
			case CK_AMPA:			send_unicode_string("");	return false;		break;
			case CK_ANCA:			send_unicode_string("");	return false;		break;
			case CK_UNQUE:			send_unicode_string("");	return false;		break;
			case CK_NUMEN:			send_unicode_string("");	return false;		break;
			case CK_MALTA:			send_unicode_string("");	return false;		break;
			case CK_NGOLDO:			send_unicode_string("");	return false;		break;
			case CK_NGWALME:		send_unicode_string("");	return false;		break;
			case CK_ORE:			send_unicode_string("");	return false;		break;
			case CK_VALA:			send_unicode_string("");	return false;		break;
			case CK_ANNA:			send_unicode_string("");	return false;		break;
			case CK_VILYA:			send_unicode_string("");	return false;		break;
			case CK_X_TINCO:		send_unicode_string("");	return false;		break;
			case CK_X_PARMA:		send_unicode_string("");	return false;		break;
			case CK_X_CALMA:		send_unicode_string("");	return false;		break;
			case CK_X_QUESSE:		send_unicode_string("");	return false;		break;
			case CK_X_ANDO:			send_unicode_string("");	return false;		break;
			case CK_X_UMBAR:		send_unicode_string("");	return false;		break;
			case CK_X_ANGA:			send_unicode_string("");	return false;		break;
			case CK_X_UNGWE:		send_unicode_string("");	return false;		break;
			case CK_ROMEN:			send_unicode_string("");	return false;		break;
			case CK_ARDA:			send_unicode_string("");	return false;		break;
			case CK_LAMBE:			send_unicode_string("");	return false;		break;
			case CK_ALDA:			send_unicode_string("");	return false;		break;
			case CK_SILME:			send_unicode_string("");	return false;		break;
			case CK_SILMENUQ:		send_unicode_string("");	return false;		break;
			case CK_ESSE:			send_unicode_string("");	return false;		break;
			case CK_ESSENUQ:		send_unicode_string("");	return false;		break;
			case CK_HYARMEN:		send_unicode_string("");	return false;		break;
			case CK_HWESTAS:		send_unicode_string("");	return false;		break;
			case CK_YANTA:			send_unicode_string("");	return false;		break;
			case CK_URE:			send_unicode_string("");	return false;		break;
			case CK_ARA:			send_unicode_string("");	return false;		break;
			case CK_HALLA:			send_unicode_string("");	return false;		break;
			case CK_TELCO:			send_unicode_string("");	return false;		break;
			case CK_L_TELCO:		send_unicode_string("");	return false;		break;
			case CK_OSSE:			send_unicode_string("");	return false;		break;
			case CK_MH:				send_unicode_string("");	return false;		break;
			case CK_BEL_MH:			send_unicode_string("");	return false;		break;
			case CK_BOMB_W:			send_unicode_string("");	return false;		break;
			case CK_BOMB_HW:		send_unicode_string("");	return false;		break;
			case CK_O_ANNA:			send_unicode_string("");	return false;		break;
			case CK_C_QU:			send_unicode_string("");	return false;		break;
			case CK_L_HW:			send_unicode_string("");	return false;		break;
			case CK_VAIYA:			send_unicode_string("");	return false;		break;
			case CK_OSSENUQ:		send_unicode_string("");	return false;		break;
			case CK_AMATIXE3:		send_unicode_string("");	return false;		break;
			case CK_UNUTIXE3:		send_unicode_string("");	return false;		break;
			case CK_AMATIXE2:		send_unicode_string("");	return false;		break;
			case CK_UNUTIXE2:		send_unicode_string("");	return false;		break;
			case CK_AMATIXE1:		send_unicode_string("");	return false;		break;
			case CK_UNUTIXE1:		send_unicode_string("");	return false;		break;
			case CK_TECCO:			send_unicode_string("");	return false;		break;
			case CK_TECCONUQ:		send_unicode_string("");	return false;		break;
			case CK_UNUTECCO:		send_unicode_string("");	return false;		break;
			case CK_REMPE:			send_unicode_string("");	return false;		break;
			case CK_REMPENUQ:		send_unicode_string("");	return false;		break;
			case CK_UNUREMPE:		send_unicode_string("");	return false;		break;
			case CK_UNUREMPN:		send_unicode_string("");	return false;		break;
			case CK_DOT_IN:			send_unicode_string("");	return false;		break;
			case CK_AMATWE:			send_unicode_string("");	return false;		break;
			case CK_UNUATWE:		send_unicode_string("");	return false;		break;
			case CK_THINNAS:		send_unicode_string("");	return false;		break;
			case CK_SARINCE:		send_unicode_string("");	return false;		break;
			case CK_C_SARIN:		send_unicode_string("");	return false;		break;
			case CK_T_TILDE:		send_unicode_string("");	return false;		break;
			case CK_T_BREVE:		send_unicode_string("");	return false;		break;
			case CK_YANTA_A:		send_unicode_string("");	return false;		break;
			case CK_T0:				send_unicode_string("");	return false;		break;
			case CK_T1:				send_unicode_string("");	return false;		break;
			case CK_T2:				send_unicode_string("");	return false;		break;
			case CK_T3:				send_unicode_string("");	return false;		break;
			case CK_T4:				send_unicode_string("");	return false;		break;
			case CK_T5:				send_unicode_string("");	return false;		break;
			case CK_T6:				send_unicode_string("");	return false;		break;
			case CK_T7:				send_unicode_string("");	return false;		break;
			case CK_T8:				send_unicode_string("");	return false;		break;
			case CK_T9:				send_unicode_string("");	return false;		break;
			case CK_T10:			send_unicode_string("");	return false;		break;
			case CK_T11:			send_unicode_string("");	return false;		break;
			case CK_T12:			send_unicode_string("");	return false;		break;
			case CK_T_LSD:			send_unicode_string("");	return false;		break;
			case CK_T_COMMA:		send_unicode_string("⸱");	return false; 		break;
			case CK_T_SEMICOLON:	send_unicode_string(":");	return false;		break;
			case CK_T_COLON:		send_unicode_string("⁝");	return false;		break;
			case CK_T_DOT:			send_unicode_string("⁘");	return false;		break;
			case CK_T_DOT_ALT:		send_unicode_string("⸬");	return false;		break;
			case CK_T_EXCLAIM:		send_unicode_string("");	return false;		break;
			case CK_T_EXCL_TH:		send_unicode_string("");	return false;		break;
			case CK_T_QUES:			send_unicode_string("");	return false;		break;
			case CK_T_PAREN:		send_unicode_string("");	return false;		break;
			case CK_T_SECTION:		send_unicode_string("");	return false;		break;
			case CK_T_DSECTION:		send_unicode_string("");	return false;		break;
			case CK_T_LQUOTE:		send_unicode_string("");	return false;		break;
			case CK_T_RQUOTE:		send_unicode_string("");	return false;		break;
			case CK_ZWJ:			send_unicode_string("‍");	return false;		break;
		}
	}
	
	return true;
}