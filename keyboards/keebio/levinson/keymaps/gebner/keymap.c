#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _SYMB 1
#define _NUMER 2
#define _KEEB 3
#define _MOVM 4

#define KC_SYMB MO(_SYMB)
#define KC_NUMER MO(_NUMER)
#define KC_KEEB MO(_KEEB)
#define KC_MOVM MO(_MOVM)

#define KC_ KC_TRNS
#define KC_RESET RESET

#define KC_ESC_LCTL MT(MOD_LCTL, KC_ESC)
#define KC_ENT_RCTL MT(MOD_RCTL, KC_ENT)
#define KC_SCLN_MOVM LT(_MOVM, KC_SCLN)
#define KC_SPC_LSFT MT(MOD_LSFT, KC_SPC)
#define KC_SPC_RSFT MT(MOD_RSFT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE]    =       LAYOUT_kc(  \
TAB,       Q,      W,          E,     R,      T,         Y,         U,     I,     O,      P,          BSPC,      \
ESC_LCTL,  A,      S,          D,     F,      G,         H,         J,     K,     L,      SCLN_MOVM,  ENT_RCTL,  \
LSFT,      Z,      X,          C,     V,      B,         N,         M,     COMM,  DOT,    SLSH,       RSFT,      \
MOVM,      LCTL,   LALT,       LGUI,  NUMER,  SPC_LSFT,  SPC_RSFT,  SYMB,  RALT,  ,       ,           MOVM       \
),

[_SYMB]    =       LAYOUT_kc(  \
TILD,      EXLM,   AT,         HASH,  DLR,    PERC,      CIRC,      AMPR,  ASTR,  LPRN,   RPRN,       BSLS,      \
DEL,       F1,     F2,         F3,    F4,     F5,        F6,        UNDS,  PLUS,  LCBR,   RCBR,       DQUO,      \
,          F7,     F8,         F9,    F10,    F11,       F12,       MINS,  EQL,   LBRC,   RBRC,       ,          \
,          ,       ,           ,      KEEB,   ,          DEL,       ,      ,      ,       ,           \
),

[_NUMER]   =       LAYOUT_kc(  \
GRV,       1,      2,          3,     4,      5,         6,         7,     8,     9,      0,          BSLS,      \
DEL,       F1,     F2,         F3,    F4,     F5,        F6,        4,     5,     6,      ,           QUOT,      \
,          F7,     F8,         F9,    F10,    F11,       F12,       1,     2,     3,      ,           ,          \
,          ,       ,           ,      ,       BSPC,      ,          KEEB,  ,      ,       ,           \
),

[_MOVM]    =       LAYOUT_kc(  \
,          ,       WH_L,       WH_U,  WH_D,   WH_R,      HOME,      PGDN,  PGUP,  END,    PSCR,       INS,       \
,          ,       MS_L,       MS_U,  MS_D,   MS_R,      LEFT,      DOWN,  UP,    RIGHT,  ,           ,          \
,          ,       ,           BTN2,  BTN1,   BTN3,      MUTE,      VOLD,  VOLU,  MPLY,   ,           ,          \
,          ,       ,           ,      KEEB,   ,          ,          ,      ,      ,       ,           \
),

[_KEEB]    =       LAYOUT_kc(  \
,          RESET,  ,           ,      ,       ,          ,          ,      ,      ,       ,           ,          \
,          ,       ,           ,      ,       ,          ,          ,      ,      ,       ,           ,          \
,          ,       ,           ,      ,       ,          ,          ,      ,      ,       ,           ,          \
,          ,       ,           ,      ,       ,          ,          ,      ,      ,       ,           \
),

};
