/*
Copyright 2018 Sekigon
Copyright (C) 2019 Gabriel Ebner <gebner@gebner.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "app_ble_func.h"

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
};


extern keymap_config_t keymap_config;

// Fillers to make layering more clear
#define _______ KC_TRNS
#define FN1_Q LT(1, KC_Q)

enum {
  _BASE = 0,
  _FN,
  _MOVM,
  _NUM,
  _FKEYS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_3x10(
    FN1_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(_MOVM, KC_SCLN),
    MT(MOD_LALT, KC_Z), MT(MOD_LCTL, KC_X), LT(_FKEYS, KC_C), LT(_NUM, KC_V), MT(MOD_LGUI, KC_B),
      MT(MOD_LSFT, KC_SPC), MT(MOD_RALT, KC_N), MT(MOD_RCTL, KC_M), KC_BSPC, KC_ENT
  ),

  [_MOVM] = LAYOUT_ortho_3x10(
		KC_TAB,  KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,    KC_INS,
		_______, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,  _______,
		_______, _______, KC_BTN2, KC_BTN1, KC_BTN3,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY,   _______
  ),

  [_NUM] = LAYOUT_ortho_3x10(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_GRV, KC_NO, KC_MINS, KC_EQL, KC_BSLS, KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT, KC_SLSH, KC_ESC
  ),

  [_FKEYS] = LAYOUT_ortho_3x10(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN] = LAYOUT_ortho_3x10(
    _______, DEL_ID0, DEL_ID1, DEL_ID2, DEL_ID3, DEL_ID4, _______, _______, ENT_SLP, BATT_LV,
    AD_WO_L, ADV_ID0, ADV_ID1, ADV_ID2, ADV_ID3, ADV_ID4, _______, _______, USB_EN, USB_DIS,
    _______, _______, _______, _______, _______, _______, ENT_DFU, _______, BLE_EN, BLE_DIS
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  }
  return true;
}
