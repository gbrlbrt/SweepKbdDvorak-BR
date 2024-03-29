#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
//-----------------------------------------------------------------------------------------------------------------------
	MT(KC_ESC, KC_SLASH), KC_COMMA, KC_DOT, KC_P, KC_Y,     KC_F, KC_G, KC_C, KC_R, KC_L, 
//-----------------------------------------------------------------------------------------------------------------------
 	KC_A, KC_O, KC_E, LGUI(KC_U), KC_I,     KC_D, RGUI(KC_H), KC_T, KC_N, KC_S, 
//-----------------------------------------------------------------------------------------------------------------------
	LALT_T(KC_SEMICOLON), KC_Q, KC_J, KC_K, KC_X,     KC_B, KC_M, KC_W, KC_V, KC_Z, 
//-----------------------------------------------------------------------------------------------------------------------
	MT(MOD_LCTL, OSL(1)), MT(MOD_LSFT, KC_SPACE),     RALT_T(KC_ENTER), MT(TO(1), KC_BSPC) 
  ),

  [1] = LAYOUT(
//-----------------------------------------------------------------------------------------------------------------------
	KC_1, KC_2, KC_3, KC_4, KC_5,     KC_6, KC_7, KC_8, KC_9, KC_0, 
//-----------------------------------------------------------------------------------------------------------------------
	KC_GRAVE, KC_CIRCUMFLEX, KC_TILD, LGUI(KC_QUOTE), KC_EXLM,     KC_MINUS, RGUI(KC_LEFT), KC_DOWN, KC_UP, KC_RIGHT, 
//-----------------------------------------------------------------------------------------------------------------------
	LALT_T(KC_NUBS), KC_EQUAL, KC_MINUS, KC_LBRC, KC_LPRN,     KC_RPRN, KC_RBRC, KC_PGDOWN, KC_PGUP, MT(KC_CAPS, KC_DEL),
//-----------------------------------------------------------------------------------------------------------------------
	MT(MOD_LALT, TO(1)),  MT(MOD_LSFT, KC_TAB),     RALT_T(KC_ENTER), TO(2) 
  ),

  [2] = LAYOUT(
//-----------------------------------------------------------------------------------------------------------------------
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
//---------------------------------------------------------------------------------------------------------------------
	KC_F11, KC_F12, KC_F13, KC_PSCREEN, KC_MEDIA_STOP,   KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,
//---------------------------------------------------------------------------------------------------------------------
	KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
//-----------------------------------------------------------------------------------------------------------------------
	TO(1), MT(MOD_LSFT, KC_SPACE),        LCTL(KC_ENTER), TO(0) 
  )
};


//  [3] = LAYOUT(
//-----------------------------------------------------------------------------------------------------------------------
//	MT(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P, 
//-----------------------------------------------------------------------------------------------------------------------
// 	KC_A, KC_S, KC_D, MT(MOD_LGUI, KC_F), KC_G,     KC_H, MT(MOD_RGUI, KC_J), KC_K, KC_L, KC_, 
//-----------------------------------------------------------------------------------------------------------------------
//	KC_SEMICOLON, KC_Z, KC_X, KC_C, KC_V,     KC_B, KC_N, KC_M, KC_, KC_, 
//-----------------------------------------------------------------------------------------------------------------------
//	MT(MOD_LCTL, TO(1)), MT(MOD_LSFT, KC_SPACE),     RALT_T(KC_ENTER), MT(TO(2), KC_BSPC) 
//  ),

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

