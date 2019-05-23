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
#define KC_B_LGUI MT(MOD_LGUI, KC_B)
#define KC_N_RALT MT(MOD_RALT, KC_N)
#define KC_M_RCTL MT(MOD_RCTL, KC_M)
#define KC_ESC_LCTL MT(MOD_LCTL, KC_ESC)
#define KC_ENT_RCTL MT(MOD_RCTL, KC_ENT)
#define KC_SCLN_MOVM LT(_MOVM, KC_SCLN)
#define KC_SPC_LSFT MT(MOD_LSFT, KC_SPC)
#define KC_COMM_MOVM LT(_MOVM, COMM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_kc(
1, 2, 3, 4, 5, MINS, EQL, 6, 7, 8, 9, 0,
Q, W, E, R, T, LBRC, RBRC, Y, U, I, O, P,
A, S, D, F, G, QUOT, BSLS, H, J, K, L, SCLN_MOVM,
Z, X_LALT, C_LCTL, V, B_LGUI, COMM_MOVM,
  DOT, SPC_LSFT, N_RALT, M_RCTL, BSPC, ENT
),

[_MOVM] = LAYOUT_kc(
F1, F2, F3, F4, F5, F11, F12, F6, F7, F8, F9, F10,
TAB, WH_L, WH_U, WH_D, WH_R, PSCR, INS, HOME, PGDN, PGUP, END, ,
ESC, MS_L, MS_U, MS_D, MS_R, , , LEFT, DOWN, UP, RIGHT, ,
, , BTN2, BTN1, BTN3, TILD, SLSH, , VOLD, VOLU, MPLY,
),

};
