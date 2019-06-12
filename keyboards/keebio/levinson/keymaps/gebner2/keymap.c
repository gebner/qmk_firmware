#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum {
  _BASE = 0,
  _MOVM,
  _FKEYS,
};


#define KC_ KC_TRNS
#define KC_RESET RESET

#define KC_X_LALT MT(MOD_LALT, KC_X)
#define KC_C_LCTL MT(MOD_LCTL, KC_C)
#define KC_A_LCTL MT(MOD_LCTL, KC_A)
#define KC_B_LGUI MT(MOD_LGUI, KC_B)
#define KC_N_RALT MT(MOD_RALT, KC_N)
#define KC_M_RCTL MT(MOD_RCTL, KC_M)
#define KC_ESC_LCTL MT(MOD_LCTL, KC_ESC)
#define KC_ENT_RCTL MT(MOD_RCTL, KC_ENT)
#define KC_SCLN_MOVM LT(_MOVM, KC_SCLN)
#define KC_SPC_LSFT MT(MOD_LSFT, KC_SPC)
#define KC_COMM_MOVM LT(_MOVM, KC_COMM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_kc(
MINS, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, EQL,
LBRC, Q, W, E, R, T, Y, U, I, O, P, RBRC,
QUOT, A_LCTL, S, D, F, G, H, J, K, L, SCLN_MOVM, BSLS,
COMM_MOVM, Z, X_LALT, C_LCTL, V, B_LGUI,
  SPC_LSFT, N_RALT, M_RCTL, BSPC, ENT, DOT
),

[_MOVM] = LAYOUT_kc(
F11, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F12,
PSCR, TAB, WH_L, WH_U, WH_D, WH_R, HOME, PGDN, PGUP, END, , INS,
, ESC, MS_L, MS_U, MS_D, MS_R, LEFT, DOWN, UP, RIGHT, , ,
TILD, , , BTN2, BTN1, BTN3, , VOLD, VOLU, MPLY, , SLSH
),

};
