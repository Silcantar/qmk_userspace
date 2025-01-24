#define MOD_MASK_RALT	MOD_BIT(KC_RALT)
#define MOD_MASK_RAS	(MOD_MASK_RALT | MOD_MASK_SHIFT)

/* Templates for copying
const key_override_t OS_		= ko_make_basic(MOD_MASK_SHIFT, CK_,		CK_);
const key_override_t OA_		= ko_make_basic(MOD_MASK_RALT, KC_,		CK_);
const key_override_t OAS_		= ko_make_basic(MOD_MASK_RAS, CK_,		CK_);
*/

// Key Overrides
// Shift Overrides
// Functions
const key_override_t OS_COPY		= ko_make_basic(MOD_MASK_SHIFT, CK_COPY,		CK_CUT);
const key_override_t OS_PASTE		= ko_make_basic(MOD_MASK_SHIFT, CK_PASTE,		CK_PASTEP);

// Whitespace
const key_override_t OS_BSPC		= ko_make_basic(MOD_MASK_SHIFT, KC_BSPC,		KC_DEL);

// Colemak
	// Row 1
const key_override_t OS_DM_REC1		= ko_make_basic(MOD_MASK_SHIFT, DM_REC1,		DM_REC2);
const key_override_t OS_GRAVE		= ko_make_basic(MOD_MASK_SHIFT, KC_GRAVE,		CK_ACUTE);
const key_override_t OS_INTBANG		= ko_make_basic(MOD_MASK_SHIFT, CK_INTBANG,	CK_BULLET);
const key_override_t OS_EXCLAIM		= ko_make_basic(MOD_MASK_SHIFT, KC_EXCLAIM,	CK_INV_EXCLAIM);
const key_override_t OS_AT			= ko_make_basic(MOD_MASK_SHIFT, KC_AT,			CK_DDAGGER);
const key_override_t OS_LSQUOTE		= ko_make_basic(MOD_MASK_SHIFT, CK_LSQUOTE,	CK_RSQUOTE);
const key_override_t OS_LDQUOTE		= ko_make_basic(MOD_MASK_SHIFT, CK_LDQUOTE,	CK_RDQUOTE);
const key_override_t OS_AMPR		= ko_make_basic(MOD_MASK_SHIFT, KC_AMPR,		CK_DAGGER);
const key_override_t OS_QUES		= ko_make_basic(MOD_MASK_SHIFT, KC_QUES,		CK_INV_QUES);
const key_override_t OS_NDASH		= ko_make_basic(MOD_MASK_SHIFT, CK_NDASH,		CK_MDASH);
const key_override_t OS_MICRO		= ko_make_basic(MOD_MASK_SHIFT, CK_MICRO,		CK_EIGHTHNOTE);
const key_override_t OS_DM_PLY1		= ko_make_basic(MOD_MASK_SHIFT, DM_PLY1,		DM_PLY2);
	// Row 4
const key_override_t OS_COMMA		= ko_make_basic(MOD_MASK_SHIFT, KC_COMMA,		KC_SEMICOLON);
const key_override_t OS_DOT			= ko_make_basic(MOD_MASK_SHIFT, KC_DOT,		KC_COLON);

// Numeric
	// Row 1
const key_override_t OS_1_6			= ko_make_basic(MOD_MASK_SHIFT, CK_1_6,			CK_1_5);
const key_override_t OS_1_3			= ko_make_basic(MOD_MASK_SHIFT, CK_1_3,		CK_2_5);
const key_override_t OS_2_3			= ko_make_basic(MOD_MASK_SHIFT, CK_2_3,		CK_3_5);
const key_override_t OS_5_6			= ko_make_basic(MOD_MASK_SHIFT, CK_5_6,			CK_4_5);
const key_override_t OS_1_4			= ko_make_basic(MOD_MASK_SHIFT, CK_1_4,			CK_3_8);
const key_override_t OS_1_2			= ko_make_basic(MOD_MASK_SHIFT, CK_1_2,			CK_5_8);
const key_override_t OS_3_4			= ko_make_basic(MOD_MASK_SHIFT, CK_3_4,		CK_7_8);
	// Row 2
const key_override_t OS_PIPE		= ko_make_basic(MOD_MASK_SHIFT, KC_PIPE,		CK_EURO);
const key_override_t OS_TILDE		= ko_make_basic(MOD_MASK_SHIFT, KC_TILDE,		CK_ALMOST_EQ);
const key_override_t OS_CIRC		= ko_make_basic(MOD_MASK_SHIFT, KC_CIRC,		CK_DEGREE);
const key_override_t OS_PERCENT		= ko_make_basic(MOD_MASK_SHIFT, KC_PERCENT,		CK_PERMILLE);
const key_override_t OS_BSLS		= ko_make_basic(MOD_MASK_SHIFT, KC_BSLS,		CK_INTEGRAL);
const key_override_t OS_PAST		= ko_make_basic(MOD_MASK_SHIFT, KC_PAST,		CK_MULTSIGN);
const key_override_t OS_KP_7		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_7,		CK_RADICAL);
const key_override_t OS_KP_8		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_8,		CK_INFINITY);
const key_override_t OS_KP_9		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_9,		CK_PARTDIFF);
const key_override_t OS_PSLS		= ko_make_basic(MOD_MASK_SHIFT, KC_PSLS,		CK_FRACSLASH);
	//Row 3
const key_override_t OS_LT			= ko_make_basic(MOD_MASK_SHIFT, KC_LT,			CK_LTEQUAL);
const key_override_t OS_LCBR		= ko_make_basic(MOD_MASK_SHIFT, KC_LCBR,		KC_RCBR);
const key_override_t OS_LPRN		= ko_make_basic(MOD_MASK_SHIFT, KC_LPRN,		KC_RPRN);
const key_override_t OS_LBRC		= ko_make_basic(MOD_MASK_SHIFT, KC_LBRC,		KC_RBRC);
const key_override_t OS_GT			= ko_make_basic(MOD_MASK_SHIFT, KC_GT,			CK_GTEQUAL);
const key_override_t OS_PPLS		= ko_make_basic(MOD_MASK_SHIFT, KC_PPLS,		CK_PLUSMINUS);
const key_override_t OS_KP_4		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_4,		S(KC_D));
const key_override_t OS_KP_5		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_5,		S(KC_E));
const key_override_t OS_KP_6		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_6,		S(KC_F));
const key_override_t OS_KP_0		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_0,		CK_TRIPLEZERO);
	// Row 4
const key_override_t OS_HASH		= ko_make_basic(MOD_MASK_SHIFT, KC_HASH,		CK_GBP);
const key_override_t OS_DOLLAR		= ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR,		CK_CENT);
const key_override_t OS_EQUAL		= ko_make_basic(MOD_MASK_SHIFT, KC_EQUAL,		CK_NOTEQUAL);
const key_override_t OS_KP_1		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_1,		S(KC_A));
const key_override_t OS_KP_2		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_2,		S(KC_B));
const key_override_t OS_KP_3		= ko_make_basic(MOD_MASK_SHIFT, KC_KP_3,		S(KC_C));

// Greek
const key_override_t OS_ALPHA		= ko_make_basic(MOD_MASK_SHIFT, CK_ALPHA,		CK_C_ALPHA);
const key_override_t OS_BETA		= ko_make_basic(MOD_MASK_SHIFT, CK_BETA,		CK_C_BETA);
const key_override_t OS_GAMMA		= ko_make_basic(MOD_MASK_SHIFT, CK_GAMMA,		CK_C_GAMMA);
const key_override_t OS_DELTA		= ko_make_basic(MOD_MASK_SHIFT, CK_DELTA,		CK_C_DELTA);
const key_override_t OS_EPSILON		= ko_make_basic(MOD_MASK_SHIFT, CK_EPSILON,	CK_C_EPSILON);
const key_override_t OS_ZETA		= ko_make_basic(MOD_MASK_SHIFT, CK_ZETA,		CK_C_ZETA);
const key_override_t OS_ETA			= ko_make_basic(MOD_MASK_SHIFT, CK_ETA,			CK_C_ETA);
const key_override_t OS_THETA		= ko_make_basic(MOD_MASK_SHIFT, CK_THETA,		CK_C_THETA);
const key_override_t OS_IOTA		= ko_make_basic(MOD_MASK_SHIFT, CK_IOTA,		CK_C_IOTA);
const key_override_t OS_KAPPA		= ko_make_basic(MOD_MASK_SHIFT, CK_KAPPA,		CK_C_KAPPA);
const key_override_t OS_LAMBDA		= ko_make_basic(MOD_MASK_SHIFT, CK_LAMBDA,		CK_C_LAMBDA);
const key_override_t OS_MU			= ko_make_basic(MOD_MASK_SHIFT, CK_MU,			CK_C_MU);
const key_override_t OS_NU			= ko_make_basic(MOD_MASK_SHIFT, CK_NU,			CK_C_NU);
const key_override_t OS_XI			= ko_make_basic(MOD_MASK_SHIFT, CK_XI,			CK_C_XI);
const key_override_t OS_OMICRON		= ko_make_basic(MOD_MASK_SHIFT, CK_OMICRON,	CK_C_OMICRON);
const key_override_t OS_PI			= ko_make_basic(MOD_MASK_SHIFT, CK_PI,			CK_C_PI);
const key_override_t OS_RHO			= ko_make_basic(MOD_MASK_SHIFT, CK_RHO,		CK_C_RHO);
const key_override_t OS_SIGMA		= ko_make_basic(MOD_MASK_SHIFT, CK_SIGMA,		CK_C_SIGMA);
const key_override_t OS_F_SIGMA		= ko_make_basic(MOD_MASK_SHIFT, CK_F_SIGMA,	CK_DTONOS);
const key_override_t OS_TAU			= ko_make_basic(MOD_MASK_SHIFT, CK_TAU,			CK_C_TAU);
const key_override_t OS_UPSILON		= ko_make_basic(MOD_MASK_SHIFT, CK_UPSILON,	CK_C_UPSILON);
const key_override_t OS_CHI			= ko_make_basic(MOD_MASK_SHIFT, CK_CHI,		CK_C_CHI);
const key_override_t OS_PHI			= ko_make_basic(MOD_MASK_SHIFT, CK_PHI,		CK_C_PHI);
const key_override_t OS_PSI			= ko_make_basic(MOD_MASK_SHIFT, CK_PSI,			CK_C_PSI);
const key_override_t OS_OMEGA		= ko_make_basic(MOD_MASK_SHIFT, CK_OMEGA,		CK_C_OMEGA);
const key_override_t OS_G_QUES		= ko_make_basic(MOD_MASK_SHIFT, CK_G_QUES,		KC_COLON);

// Symbol
const key_override_t OS_COPYRIGHT	= ko_make_basic(MOD_MASK_SHIFT, CK_COPYRIGHT,	CK_PATENT);
const key_override_t OS_ARRL_ARRR	= ko_make_basic(MOD_MASK_SHIFT, CK_ARRL_ARRR,	CK_ARRR_ARRL);
const key_override_t OS_ARRU_ARRD	= ko_make_basic(MOD_MASK_SHIFT, CK_ARRU_ARRD,	CK_ARRD_ARRU);
const key_override_t OS_ARRUD		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRUD,		CK_ARRUDF);
const key_override_t OS_ARRLR		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRLR,		CK_ARRLRF);
const key_override_t OS_TRADEMARK	= ko_make_basic(MOD_MASK_SHIFT, CK_TRADEMARK,	CK_REGTM);
const key_override_t OS_CIRCLE		= ko_make_basic(MOD_MASK_SHIFT, CK_CIRCLE,		CK_CIRCLE_F);
const key_override_t OS_ARRNW		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRNW,		CK_ARRNWF);
const key_override_t OS_ARRU		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRU,		CK_ARRUF);
const key_override_t OS_ARRNE		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRNE,		CK_ARRNEF);
const key_override_t OS_TRI_U		= ko_make_basic(MOD_MASK_SHIFT, CK_TRI_U,		CK_TRI_UF);
const key_override_t OS_TRI_L		= ko_make_basic(MOD_MASK_SHIFT, CK_TRI_L,		CK_TRI_LF);
const key_override_t OS_ARRL		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRL,		CK_ARRLF);
const key_override_t OS_ARRCW		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRCW,		CK_ARRCCW);
const key_override_t OS_ARRR		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRR,		CK_ARRRF);
const key_override_t OS_TRI_R		= ko_make_basic(MOD_MASK_SHIFT, CK_TRI_R,		CK_TRI_RF);
const key_override_t OS_SQUARE		= ko_make_basic(MOD_MASK_SHIFT, CK_SQUARE,		CK_SQUARE_F);
const key_override_t OS_ARRSW		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRSW,		CK_ARRSWF);
const key_override_t OS_ARRD		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRD,		CK_ARRDF);
const key_override_t OS_ARRSE		= ko_make_basic(MOD_MASK_SHIFT, CK_ARRSE,		CK_ARRSEF);
const key_override_t OS_TRI_D		= ko_make_basic(MOD_MASK_SHIFT, CK_TRI_D,		CK_TRI_DF);

// Emoji
const key_override_t OS_PENCIL		= ko_make_basic(MOD_MASK_SHIFT, CK_PENCIL,		CK_SCISSORS);
const key_override_t OS_APPLE		= ko_make_basic(MOD_MASK_SHIFT, CK_APPLE,		CK_AVOCADO);
const key_override_t OS_PIZZA		= ko_make_basic(MOD_MASK_SHIFT, CK_PIZZA,		CK_MEAT);
const key_override_t OS_SUN			= ko_make_basic(MOD_MASK_SHIFT, CK_SUN,			CK_RAIN);
const key_override_t OS_PEACH		= ko_make_basic(MOD_MASK_SHIFT, CK_PEACH,		CK_EGGPLANT);
const key_override_t OS_DOG			= ko_make_basic(MOD_MASK_SHIFT, CK_DOG,		CK_CAT);
const key_override_t OS_SHRUG		= ko_make_basic(MOD_MASK_SHIFT, CK_SHRUG,		CK_FACEPALM);
const key_override_t OS_THUMBU		= ko_make_basic(MOD_MASK_SHIFT, CK_THUMBU,		CK_THUMBD);
const key_override_t OS_POOP		= ko_make_basic(MOD_MASK_SHIFT, CK_POOP,		CK_SKULL);
const key_override_t OS_HEART		= ko_make_basic(MOD_MASK_SHIFT, CK_HEART,		CK_HEARTB);
const key_override_t OS_MINDBLOWN	= ko_make_basic(MOD_MASK_SHIFT, CK_MINDBLOWN,	CK_SCREAM);
const key_override_t OS_SILLY		= ko_make_basic(MOD_MASK_SHIFT, CK_SILLY,		CK_ZIPPED);
const key_override_t OS_SMILE		= ko_make_basic(MOD_MASK_SHIFT, CK_SMILE,		CK_GRIN);
const key_override_t OS_EYEROLL		= ko_make_basic(MOD_MASK_SHIFT, CK_EYEROLL,	CK_GRIMACE);
const key_override_t OS_CRYING		= ko_make_basic(MOD_MASK_SHIFT, CK_CRYING,		CK_NEUTRAL);
const key_override_t OS_TREX		= ko_make_basic(MOD_MASK_SHIFT, CK_TREX,		CK_SAUROPOD);
const key_override_t OS_SUS			= ko_make_basic(MOD_MASK_SHIFT, CK_SUS,			CK_MONOCLE);
const key_override_t OS_SHADES		= ko_make_basic(MOD_MASK_SHIFT, CK_SHADES,		CK_INLOVE);
const key_override_t OS_PARTY		= ko_make_basic(MOD_MASK_SHIFT, CK_PARTY,		CK_HALO);
const key_override_t OS_TIGER		= ko_make_basic(MOD_MASK_SHIFT, CK_TIGER,		CK_UNICORN);

// Tengwar
// Row 1
const key_override_t OS_T1			= ko_make_basic(MOD_MASK_SHIFT, CK_T1,			CK_T11);
const key_override_t OS_T2			= ko_make_basic(MOD_MASK_SHIFT, CK_T2,			CK_T12);
const key_override_t OS_T3			= ko_make_basic(MOD_MASK_SHIFT, CK_T3,			CK_T_LSD);
//const key_override_t OS_T4		= ko_make_basic(MOD_MASK_SHIFT, CK_T4,			CK_);
//const key_override_t OS_T5		= ko_make_basic(MOD_MASK_SHIFT, CK_T5,			CK_);
//const key_override_t OS_T6		= ko_make_basic(MOD_MASK_SHIFT, CK_T6,			CK_);
//const key_override_t OS_T7		= ko_make_basic(MOD_MASK_SHIFT, CK_T7,			CK_);
const key_override_t OS_T8			= ko_make_basic(MOD_MASK_SHIFT, CK_T8,			CK_T_PAREN);
//const key_override_t OS_T9		= ko_make_basic(MOD_MASK_SHIFT, CK_T9,			CK_);
const key_override_t OS_T0			= ko_make_basic(MOD_MASK_SHIFT, CK_T0,			CK_T10);
const key_override_t OS_T_SECTION	= ko_make_basic(MOD_MASK_SHIFT, CK_T_SECTION,	CK_T_DSECTION);

// Row 2
const key_override_t OS_HWESTAS		= ko_make_basic(MOD_MASK_SHIFT, CK_HWESTAS,	CK_BOMB_HW);
const key_override_t OS_VALA		= ko_make_basic(MOD_MASK_SHIFT, CK_VALA,		CK_VILYA);
const key_override_t OS_TELCO		= ko_make_basic(MOD_MASK_SHIFT, CK_TELCO,		CK_ARA);
const key_override_t OS_PARMA		= ko_make_basic(MOD_MASK_SHIFT, CK_PARMA,		CK_FORMEN);
const key_override_t OS_UMBAR		= ko_make_basic(MOD_MASK_SHIFT, CK_UMBAR,		CK_AMPA);
const key_override_t OS_ANGA		= ko_make_basic(MOD_MASK_SHIFT, CK_ANGA,		CK_ANCA);
const key_override_t OS_LAMBE		= ko_make_basic(MOD_MASK_SHIFT, CK_LAMBE,		CK_ALDA);
const key_override_t OS_REMPENUQ	= ko_make_basic(MOD_MASK_SHIFT, CK_REMPENUQ,	CK_URE);
const key_override_t OS_ANNA		= ko_make_basic(MOD_MASK_SHIFT, CK_ANNA,		CK_AMATIXE2);
const key_override_t OS_ESSE		= ko_make_basic(MOD_MASK_SHIFT, CK_ESSE,		CK_ESSENUQ);

// Row 3
const key_override_t OS_AMATIXE3	= ko_make_basic(MOD_MASK_SHIFT, CK_AMATIXE3,	CK_OSSE);
const key_override_t OS_ROMEN		= ko_make_basic(MOD_MASK_SHIFT, CK_ROMEN,		CK_ORE);
const key_override_t OS_SILME		= ko_make_basic(MOD_MASK_SHIFT, CK_SILME,		CK_SILMENUQ);
const key_override_t OS_TINCO		= ko_make_basic(MOD_MASK_SHIFT, CK_TINCO,		CK_THULE);
const key_override_t OS_UNGWE		= ko_make_basic(MOD_MASK_SHIFT, CK_UNGWE,		CK_UNQUE);
const key_override_t OS_MALTA		= ko_make_basic(MOD_MASK_SHIFT, CK_MALTA,		CK_MH);
const key_override_t OS_NUMEN		= ko_make_basic(MOD_MASK_SHIFT, CK_NUMEN,		CK_NGWALME);
const key_override_t OS_TECCO		= ko_make_basic(MOD_MASK_SHIFT, CK_TECCO,		CK_YANTA);
const key_override_t OS_AMATIXE1	= ko_make_basic(MOD_MASK_SHIFT, CK_AMATIXE1,	CK_UNUTIXE1);
const key_override_t OS_REMPE		= ko_make_basic(MOD_MASK_SHIFT, CK_REMPE,		CK_OSSENUQ);

// Row 4
const key_override_t OS_SARINCE		= ko_make_basic(MOD_MASK_SHIFT, CK_SARINCE,		CK_C_SARIN);
//const key_override_t OS_FORMEN	= ko_make_basic(MOD_MASK_SHIFT, CK_FORMEN,		CK_);
const key_override_t OS_CALMA		= ko_make_basic(MOD_MASK_SHIFT, CK_CALMA,		CK_HARMA);
const key_override_t OS_ANDO		= ko_make_basic(MOD_MASK_SHIFT, CK_ANDO,		CK_ANTO);
const key_override_t OS_T_LQUOTE	= ko_make_basic(MOD_MASK_SHIFT, CK_T_LQUOTE,	CK_T_RQUOTE);
const key_override_t OS_T_EXCLAIM	= ko_make_basic(MOD_MASK_SHIFT, CK_T_EXCLAIM,	CK_T_QUES);
const key_override_t OS_HYARMEN		= ko_make_basic(MOD_MASK_SHIFT, CK_HYARMEN,	CK_HALLA);
const key_override_t OS_QUESSE		= ko_make_basic(MOD_MASK_SHIFT, CK_QUESSE,		CK_HWESTA);
const key_override_t OS_T_COMMA		= ko_make_basic(MOD_MASK_SHIFT, CK_T_COMMA,	CK_T_SEMICOLON);
const key_override_t OS_T_DOT		= ko_make_basic(MOD_MASK_SHIFT, CK_T_DOT,		CK_T_COLON);

// AltGr Overrides
const key_override_t OA_SPACE		= ko_make_basic(MOD_MASK_RALT, KC_SPACE,		CK_NBSP);
const key_override_t OA_ENTER		= ko_make_basic(MOD_MASK_RALT, KC_ENTER,		CK_LF);
const key_override_t OA_TAB			= ko_make_basic(MOD_MASK_RALT, KC_TAB,			CK_SPCTAB);

// Colemak
// Row 1
const key_override_t OA_GRAVE		= ko_make_basic(MOD_MASK_RALT, KC_GRAVE,		CK_LSAQUOTE);
const key_override_t OA_EXCLAIM		= ko_make_basic(MOD_MASK_RALT, KC_EXCLAIM,		CK_C_CIRC);
const key_override_t OA_AT			= ko_make_basic(MOD_MASK_RALT, KC_AT,			CK_C_RING);
const key_override_t OA_C_GRAVE		= ko_make_basic(MOD_MASK_RALT, CK_LSQUOTE,		CK_C_GRAVE);
const key_override_t OA_DQUOTE_LO	= ko_make_basic(MOD_MASK_RALT, CK_LDQUOTE,		CK_DQUOTE_LO);
const key_override_t OA_AMPR		= ko_make_basic(MOD_MASK_RALT, KC_AMPR,			CK_C_BREVE);
const key_override_t OA_QUES		= ko_make_basic(MOD_MASK_RALT, KC_QUES,			CK_C_TILDE);
const key_override_t OA_NDASH		= ko_make_basic(MOD_MASK_RALT, CK_NDASH,		CK_C_BAR_O);
const key_override_t OA_MICRO		= ko_make_basic(MOD_MASK_RALT, CK_MICRO,		CK_LDAQUOTE);

// Row 2
const key_override_t OA_Q			= ko_make_basic(MOD_MASK_RALT, KC_Q,			CK_O_SLASH);
const key_override_t OA_W			= ko_make_basic(MOD_MASK_RALT, KC_W,			CK_STRUT);
const key_override_t OA_F			= ko_make_basic(MOD_MASK_RALT, KC_F,			CK_AE);
const key_override_t OA_P			= ko_make_basic(MOD_MASK_RALT, KC_P,			CK_OE);
const key_override_t OA_B			= ko_make_basic(MOD_MASK_RALT, KC_B,			CK_E_ROUND);
const key_override_t OA_J			= ko_make_basic(MOD_MASK_RALT, KC_J,			CK_DEZH);
const key_override_t OA_L			= ko_make_basic(MOD_MASK_RALT, KC_L,			CK_L_BAR);
const key_override_t OA_U			= ko_make_basic(MOD_MASK_RALT, KC_U,			CK_U_DIAER);
const key_override_t OA_Y			= ko_make_basic(MOD_MASK_RALT, KC_Y,			CK_SCHWA);
const key_override_t OA_Z			= ko_make_basic(MOD_MASK_RALT, KC_Z,			CK_EZH);

// Row 3
const key_override_t OA_A			= ko_make_basic(MOD_MASK_RALT, KC_A,			CK_A_DIAER);
const key_override_t OA_R			= ko_make_basic(MOD_MASK_RALT, KC_R,			CK_R_CARON);
const key_override_t OA_S			= ko_make_basic(MOD_MASK_RALT, KC_S,			CK_ESSZETT);
const key_override_t OA_T			= ko_make_basic(MOD_MASK_RALT, KC_T,			CK_THORN);
const key_override_t OA_G			= ko_make_basic(MOD_MASK_RALT, KC_G,			CK_G_BREVE);
const key_override_t OA_M			= ko_make_basic(MOD_MASK_RALT, KC_M,			CK_ENG);
const key_override_t OA_N			= ko_make_basic(MOD_MASK_RALT, KC_N,			CK_ENYE);
const key_override_t OA_E			= ko_make_basic(MOD_MASK_RALT, KC_E,			CK_E_ACUTE);
const key_override_t OA_I			= ko_make_basic(MOD_MASK_RALT, KC_I,			CK_I_DIAER);
const key_override_t OA_O			= ko_make_basic(MOD_MASK_RALT, KC_O,			CK_O_DIAER);

// Row 4
const key_override_t OA_X			= ko_make_basic(MOD_MASK_RALT, KC_X,			CK_ESH);
const key_override_t OA_V			= ko_make_basic(MOD_MASK_RALT, KC_V,			CK_U_CIRC);
const key_override_t OA_C			= ko_make_basic(MOD_MASK_RALT, KC_C,			CK_CEDILLE);
const key_override_t OA_D			= ko_make_basic(MOD_MASK_RALT, KC_D,			CK_ETH);
const key_override_t OA_QUOTE		= ko_make_basic(MOD_MASK_RALT, KC_QUOTE,		CK_C_ACUTE);
const key_override_t OA_MINUS		= ko_make_basic(MOD_MASK_RALT, KC_MINUS,		CK_C_MACRON);
const key_override_t OA_H			= ko_make_basic(MOD_MASK_RALT, KC_H,			CK_H_BAR);
const key_override_t OA_K			= ko_make_basic(MOD_MASK_RALT, KC_K,			CK_STOP);
const key_override_t OA_COMMA		= ko_make_basic(MOD_MASK_RALT, KC_COMMA,		CK_C_CEDILLA);
const key_override_t OA_DOT			= ko_make_basic(MOD_MASK_RALT, KC_DOT,			CK_C_DIAER);


// Tengwar
// Row 2
const key_override_t OA_HWESTAS		= ko_make_basic(MOD_MASK_RALT, CK_HWESTAS,		CK_BOMB_HW);
const key_override_t OA_VALA		= ko_make_basic(MOD_MASK_RALT, CK_VALA,			CK_BOMB_W);
const key_override_t OA_TELCO		= ko_make_basic(MOD_MASK_RALT, CK_TELCO,		CK_L_TELCO);
const key_override_t OA_PARMA		= ko_make_basic(MOD_MASK_RALT, CK_PARMA,		CK_X_PARMA);
const key_override_t OA_UMBAR		= ko_make_basic(MOD_MASK_RALT, CK_UMBAR,		CK_X_UMBAR);
const key_override_t OA_ANGA		= ko_make_basic(MOD_MASK_RALT, CK_ANGA,			CK_X_ANGA);
const key_override_t OA_LAMBE		= ko_make_basic(MOD_MASK_RALT, CK_LAMBE,		CK_UNUATWE);
const key_override_t OA_REMPENUQ	= ko_make_basic(MOD_MASK_RALT, CK_REMPENUQ,		CK_UNUREMPN);
const key_override_t OA_ANNA		= ko_make_basic(MOD_MASK_RALT, CK_ANNA,			CK_UNUTIXE2);
//const key_override_t OA_ESSE		= ko_make_basic(MOD_MASK_RALT, CK_ESSE,			CK_);

// Row 3
const key_override_t OA_AMATIXE3	= ko_make_basic(MOD_MASK_RALT, CK_AMATIXE3,	CK_UNUTIXE3);
const key_override_t OA_ROMEN		= ko_make_basic(MOD_MASK_RALT, CK_ROMEN,		CK_ARDA);
const key_override_t OA_SILME		= ko_make_basic(MOD_MASK_RALT, CK_SILME,		CK_ZWJ);
const key_override_t OA_TINCO		= ko_make_basic(MOD_MASK_RALT, CK_TINCO,		CK_X_TINCO);
const key_override_t OA_UNGWE		= ko_make_basic(MOD_MASK_RALT, CK_UNGWE,		CK_X_UNGWE);
const key_override_t OA_MALTA		= ko_make_basic(MOD_MASK_RALT, CK_MALTA,		CK_UNUATWE);
const key_override_t OA_NUMEN		= ko_make_basic(MOD_MASK_RALT, CK_NUMEN,		CK_NGOLDO);
const key_override_t OA_TECCO		= ko_make_basic(MOD_MASK_RALT, CK_TECCO,		CK_UNUTECCO);
const key_override_t OA_AMATIXE1	= ko_make_basic(MOD_MASK_RALT, CK_AMATIXE1,		CK_UNUTIXE1);
const key_override_t OA_REMPE		= ko_make_basic(MOD_MASK_RALT, CK_REMPE,		CK_UNUREMPE);

// Row 4
//const key_override_t OA_SARINCE	= ko_make_basic(MOD_MASK_RALT, CK_SARINCE,		CK_);
const key_override_t OA_FORMEN		= ko_make_basic(MOD_MASK_RALT, CK_FORMEN,		CK_X_PARMA);
const key_override_t OA_CALMA		= ko_make_basic(MOD_MASK_RALT, CK_CALMA,		CK_X_CALMA);
const key_override_t OA_ANDO		= ko_make_basic(MOD_MASK_RALT, CK_ANDO,			CK_X_ANDO);
//const key_override_t OA_T_QUOTE	= ko_make_basic(MOD_MASK_RALT, CK_T_QUOTE,		CK_);
const key_override_t OA_T_EXCLAIM	= ko_make_basic(MOD_MASK_RALT, CK_T_EXCLAIM,	CK_T_EXCL_TH);
const key_override_t OA_HYARMEN		= ko_make_basic(MOD_MASK_RALT, CK_HYARMEN,		CK_THINNAS);
const key_override_t OA_QUESSE		= ko_make_basic(MOD_MASK_RALT, CK_QUESSE,		CK_X_QUESSE);
//const key_override_t OA_T_COMMA		= ko_make_basic(MOD_MASK_RALT, CK_T_COMMA,		CK_);
const key_override_t OA_T_DOT		= ko_make_basic(MOD_MASK_RALT, CK_T_DOT,		CK_T_DOT_ALT);

// Shift+AltGr Overrides
// Colemak
// Row 1
const key_override_t OAS_GRAVE		= ko_make_basic(MOD_MASK_RAS, KC_GRAVE,			CK_RSAQUOTE);
const key_override_t OAS_EXCLAIM	= ko_make_basic(MOD_MASK_RAS, KC_EXCLAIM,		CK_C_CARON);
const key_override_t OAS_AT			= ko_make_basic(MOD_MASK_RAS, KC_AT,			CK_C_RINGB);
const key_override_t OAS_C_GRAVE	= ko_make_basic(MOD_MASK_RAS, CK_LSQUOTE,		CK_C_GRAVED);
const key_override_t OAS_AMPR		= ko_make_basic(MOD_MASK_RAS, KC_AMPR,			CK_C_BREVEI);
const key_override_t OAS_QUES		= ko_make_basic(MOD_MASK_RAS, KC_QUES,			CK_C_HORN);
const key_override_t OAS_NDASH		= ko_make_basic(MOD_MASK_RAS, CK_NDASH,			CK_C_BAR_B);
const key_override_t OAS_MICRO		= ko_make_basic(MOD_MASK_RAS, CK_MICRO,		CK_RDAQUOTE);

// Row 2
const key_override_t OAS_Q			= ko_make_basic(MOD_MASK_RAS, KC_Q,			CK_C_O_SLASH);
const key_override_t OAS_W			= ko_make_basic(MOD_MASK_RAS, KC_W,			CK_C_STRUT);
const key_override_t OAS_F			= ko_make_basic(MOD_MASK_RAS, KC_F,			CK_C_AE);
const key_override_t OAS_P			= ko_make_basic(MOD_MASK_RAS, KC_P,			CK_C_OE);
const key_override_t OAS_B			= ko_make_basic(MOD_MASK_RAS, KC_B,			CK_C_E_ROUND);
//const key_override_t OAS_J			= ko_make_basic(MOD_MASK_RAS, KC_J,			CK_C_DZ);
const key_override_t OAS_L			= ko_make_basic(MOD_MASK_RAS, KC_L,			CK_C_L_BAR);
const key_override_t OAS_U			= ko_make_basic(MOD_MASK_RAS, KC_U,			CK_C_U_DIAER);
const key_override_t OAS_Y			= ko_make_basic(MOD_MASK_RAS, KC_Y,			CK_C_SCHWA);
const key_override_t OAS_Z			= ko_make_basic(MOD_MASK_RAS, KC_Z,			CK_C_EZH);

// Row 3
const key_override_t OAS_A			= ko_make_basic(MOD_MASK_RAS, KC_A,			CK_C_A_DIAER);
const key_override_t OAS_R			= ko_make_basic(MOD_MASK_RAS, KC_R,			CK_C_R_CARON);
const key_override_t OAS_S			= ko_make_basic(MOD_MASK_RAS, KC_S,			CK_C_ESSZETT);
const key_override_t OAS_T			= ko_make_basic(MOD_MASK_RAS, KC_T,			CK_C_THORN);
const key_override_t OAS_G			= ko_make_basic(MOD_MASK_RAS, KC_G,			CK_C_G_BREVE);
const key_override_t OAS_M			= ko_make_basic(MOD_MASK_RAS, KC_M,			CK_C_ENG);
const key_override_t OAS_N			= ko_make_basic(MOD_MASK_RAS, KC_N,			CK_C_ENYE);
const key_override_t OAS_E			= ko_make_basic(MOD_MASK_RAS, KC_E,			CK_C_E_ACUTE);
const key_override_t OAS_I			= ko_make_basic(MOD_MASK_RAS, KC_I,			CK_C_I_DIAER);
const key_override_t OAS_O			= ko_make_basic(MOD_MASK_RAS, KC_O,			CK_C_O_DIAER);

// Row 4
const key_override_t OAS_X			= ko_make_basic(MOD_MASK_RAS, KC_X,			CK_C_ESH);
const key_override_t OAS_V			= ko_make_basic(MOD_MASK_RAS, KC_V,			CK_C_U_CIRC);
const key_override_t OAS_C			= ko_make_basic(MOD_MASK_RAS, KC_C,			CK_C_CEDILLE);
const key_override_t OAS_D			= ko_make_basic(MOD_MASK_RAS, KC_D,			CK_C_ETH);
const key_override_t OAS_QUOTE		= ko_make_basic(MOD_MASK_RAS, KC_QUOTE,		CK_C_ACUTED);
const key_override_t OAS_MINUS		= ko_make_basic(MOD_MASK_RAS, KC_MINUS,		CK_C_MACRONB);
const key_override_t OAS_H			= ko_make_basic(MOD_MASK_RAS, KC_H,			CK_C_H_BAR);
//const key_override_t OAS_K			= ko_make_basic(MOD_MASK_RAS, KC_K,			CK_STOP);
//const key_override_t OAS_COMMA		= ko_make_basic(MOD_MASK_RAS, KC_COMMA,		CK_C_CEDILLA);
const key_override_t OAS_DOT		= ko_make_basic(MOD_MASK_RAS, KC_DOT,			CK_C_DOT);


// Tengwar
const key_override_t OAS_HWESTAS	= ko_make_basic(MOD_MASK_RAS, CK_HWESTAS,		CK_C_QU);
const key_override_t OAS_VALA		= ko_make_basic(MOD_MASK_RAS, CK_VALA,			CK_VAIYA);
const key_override_t OAS_ANNA		= ko_make_basic(MOD_MASK_RAS, CK_ANNA,			CK_T_BREVE);
const key_override_t OAS_AMATIXE3	= ko_make_basic(MOD_MASK_RAS, CK_AMATIXE3,		CK_AMATIX3N);
const key_override_t OAS_TECCO		= ko_make_basic(MOD_MASK_RAS, CK_TECCO,			CK_YANTA_A);


const key_override_t *key_overrides[] = {
// Shift Overrides
// Functions
	&OS_COPY,
	&OS_PASTE,
// Whitespace
	&OS_BSPC,

// Colemak
	// Row 1
	&OS_DM_REC1,
	&OS_GRAVE,
	&OS_INTBANG,
	&OS_EXCLAIM,
	&OS_AT,
	&OS_LSQUOTE,
	&OS_LDQUOTE,
	&OS_AMPR,
	&OS_QUES,
	&OS_NDASH,
	&OS_MICRO,
	&OS_DM_PLY1,
	// Row 4
	&OS_COMMA,
	&OS_DOT,

// Numeric
// Row 1
	&OS_1_6,
	&OS_1_3,
	&OS_2_3,
	&OS_5_6,
	&OS_1_4,
	&OS_1_2,
	&OS_3_4,
// Row 2
	&OS_PIPE,
	&OS_TILDE,
	&OS_CIRC,
	&OS_PERCENT,
	&OS_BSLS,
	&OS_PAST,
	&OS_KP_7,
	&OS_KP_8,
	&OS_KP_9,
	&OS_PSLS,
// Row 3
	&OS_LT,
	&OS_LCBR,
	&OS_LPRN,
	&OS_LBRC,
	&OS_GT,
	&OS_PPLS,
	&OS_KP_4,
	&OS_KP_5,
	&OS_KP_6,
	&OS_KP_0,
// Row 4
	&OS_HASH,
	&OS_DOLLAR,
	&OS_EQUAL,
	&OS_KP_1,
	&OS_KP_2,
	&OS_KP_3,

// Greek
	&OS_ALPHA,
	&OS_BETA,
	&OS_GAMMA,
	&OS_DELTA,
	&OS_EPSILON,
	&OS_ZETA,
	&OS_ETA,
	&OS_THETA,
	&OS_IOTA,
	&OS_KAPPA,
	&OS_LAMBDA,
	&OS_MU,
	&OS_NU,
	&OS_XI,
	&OS_OMICRON,
	&OS_PI,
	&OS_RHO,
	&OS_SIGMA,
	&OS_F_SIGMA,
	&OS_TAU,
	&OS_UPSILON,
	&OS_CHI,
	&OS_PHI,
	&OS_PSI,
	&OS_OMEGA,
	&OS_G_QUES,

// Symbol
	&OS_COPYRIGHT,
	&OS_ARRL_ARRR,
	&OS_ARRU_ARRD,
	&OS_ARRUD,
	&OS_ARRLR,
	&OS_TRADEMARK,
	&OS_CIRCLE,
	&OS_ARRNW,
	&OS_ARRU,
	&OS_ARRNE,
	&OS_TRI_U,
	&OS_TRI_L,
	&OS_ARRL,
	&OS_ARRCW,
	&OS_ARRR,
	&OS_TRI_R,
	&OS_SQUARE,
	&OS_ARRSW,
	&OS_ARRD,
	&OS_ARRSE,
	&OS_TRI_D,

// Emoji
	&OS_PENCIL,
	&OS_APPLE,
	&OS_PIZZA,
	&OS_SUN,
	&OS_PEACH,
	&OS_DOG,
	&OS_SHRUG,
	&OS_THUMBU,
	&OS_POOP,
	&OS_HEART,
	&OS_MINDBLOWN,
	&OS_SILLY,
	&OS_SMILE,
	&OS_EYEROLL,
	&OS_CRYING,
	&OS_TREX,
	&OS_SUS,
	&OS_SHADES,
	&OS_PARTY,
	&OS_TIGER,

// Tengwar
// Row 1
	&OS_T1,
	&OS_T2,
	&OS_T3,
	//&OS_T4,
	//&OS_T5,
	//&OS_T6,
	//&OS_T7,
	&OS_T8,
	//&OS_T9,
	&OS_T0,
	&OS_T_SECTION,

// Row 2
	&OS_HWESTAS,
	&OS_VALA,
	&OS_TELCO,
	&OS_PARMA,
	&OS_UMBAR,
	&OS_ANGA,
	&OS_LAMBE,
	&OS_REMPENUQ,
	&OS_ANNA,
	&OS_ESSE,

// Row 3
	&OS_AMATIXE3,
	&OS_ROMEN,
	&OS_SILME,
	&OS_TINCO,
	&OS_UNGWE,
	&OS_MALTA,
	&OS_NUMEN,
	&OS_TECCO,
	&OS_AMATIXE1,
	&OS_REMPE,

// Row 4
	&OS_SARINCE,
	//&OS_FORMEN,
	&OS_CALMA,
	&OS_ANDO,
	&OS_T_LQUOTE,
	&OS_T_EXCLAIM,
	&OS_HYARMEN,
	&OS_QUESSE,
	&OS_T_COMMA,
	&OS_T_DOT,

// AltGr Overrides
// Whitespace
	&OA_SPACE,
	&OA_ENTER,
	&OA_TAB,

// Colemak
// Row 1

	&OA_EXCLAIM,
	&OA_AT,
	&OA_C_GRAVE,
	&OA_AMPR,
	&OA_QUES,
	&OA_NDASH,
// Row 2
	&OA_Q,
	&OA_W,
	&OA_F,
	&OA_P,
	&OA_B,
	&OA_J,
	&OA_L,
	&OA_U,
	&OA_Y,
	&OA_Z,
// Row 3
	&OA_A,
	&OA_R,
	&OA_S,
	&OA_T,
	&OA_G,
	&OA_M,
	&OA_N,
	&OA_E,
	&OA_I,
	&OA_O,
// Row 4
	&OA_X,
	&OA_V,
	&OA_C,
	&OA_D,
	&OA_QUOTE,
	&OA_MINUS,
	&OA_H,
	&OA_K,
	&OA_COMMA,
	&OA_DOT,

// Tengwar
// Row 2
	&OA_HWESTAS,
	&OA_VALA,
	&OA_TELCO,
	&OA_PARMA,
	&OA_UMBAR,
	&OA_ANGA,
	&OA_LAMBE,
	&OA_REMPENUQ,
	&OA_ANNA,
	//&OA_ESSE,
// Row 3
	&OA_AMATIXE3,
	&OA_ROMEN,
	&OA_SILME,
	&OA_TINCO,
	&OA_UNGWE,
	&OA_MALTA,
	&OA_NUMEN,
	&OA_TECCO,
	&OA_AMATIXE1,
	&OA_REMPE,
// Row 4
	//&OA_SARINCE,
	&OA_FORMEN,
	&OA_CALMA,
	&OA_ANDO,
	//&OA_T_QUOTE,
	&OA_T_EXCLAIM,
	&OA_HYARMEN,
	&OA_QUESSE,
	//&OA_T_COMMA,
	&OA_T_DOT,

// Shift+AltGr Overrides
// Colemak
// Row 1
	&OAS_EXCLAIM,
	&OAS_AT,
	&OAS_C_GRAVE,
	&OAS_AMPR,
	&OAS_QUES,
	&OAS_NDASH,
// Row 2
	&OAS_Q,
	&OAS_W,
	&OAS_F,
	&OAS_P,
	&OAS_B,
	//OAS_J,
	&OAS_L,
	&OAS_U,
	&OAS_Y,
	&OAS_Z,
// Row 3
	&OAS_A,
	&OAS_R,
	&OAS_S,
	&OAS_T,
	&OAS_G,
	&OAS_M,
	&OAS_N,
	&OAS_E,
	&OAS_I,
	&OAS_O,
// Row 4
	&OAS_X,
	&OAS_V,
	&OAS_C,
	&OAS_D,
	&OAS_QUOTE,
	&OAS_MINUS,
	&OAS_H,
	//&OAS_K,
	//&OAS_COMMA,
	&OAS_DOT,

// Tengwar
	&OAS_HWESTAS,
	&OAS_VALA,
	&OAS_ANNA,
	&OAS_AMATIXE3,
	&OAS_TECCO,
};