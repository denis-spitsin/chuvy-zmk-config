/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

enum custom_keycodes {
    RUS_ENG = SAFE_RANGE,
    SELECTFROM,
    CMNTODATE,
};

#define K_LNG LSFT(LALT(KC_NO))             // alt+shift (to change lahguage)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------------|   |-----------------------------------------------------.
     KC_LNG1,    KC_Q,    KC_W,      KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+-----------------------|   |--------+--------+--------+--------+--------+--------|
     KC_LCTL, LCTL_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LGUI_T(KC_F), KC_G,   KC_H,    LGUI_T(KC_J),    RSFT_T(KC_K),    RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+-----------------------|   |--------+--------+--------+--------+--------+--------|
     KC_LSFT, LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M, KC_COMM,  KC_DOT, LSFT_T(KC_SLSH),  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------------|   |--------+--------+--------+--------+--------+--------|
                              LT(2,KC_ESC),   LT(1,KC_SPC),  LT(3,KC_TAB),    LT(3,KC_ENT),   LT(1,KC_BSPC), RGUI_T(KC_PGUP)
                              //--------`--------------------------------'   `----------------------------------------------'

  ),


    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_MINS,  KC_EQL, KC_QUOT, KC_LCBR, KC_RCBR,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_UNDS, KC_PLUS, KC_DQT,  KC_LBRC, KC_RBRC, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,KC_HOME,  KC_DEL,     KC_ENT, KC_END, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,  KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,                     KC_F5,   KC_F6,   KC_F7,   KC_F8,   LSFT(KC_INS), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),      LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_GRV, KC_TILD, XXXXXXX, KC_F9, KC_F10,                        KC_F11, KC_F12,    XXXXXXX, KC_PIPE, KC_BSLS, XXXXXXX,
                                          KC_LGUI, _______,  KC_SPC,     KC_RALT, KC_RSFT, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_NO, KC_LALT,    KC_RCTL,   KC_NO,  KC_RGUI
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RUS_ENG:
        if (record->event.pressed) {
          register_code(KC_LALT);
          register_code(KC_LSFT);
          unregister_code(KC_LALT);
          unregister_code(KC_LSFT);
            // when keycode RUS_ENG is pressed
        } /*else {
            // when keycode RUS_ENG is released
        }*/
        break;
    case SELECTFROM:
        if (record->event.pressed) {
          SEND_STRING("select "); 
          register_code(KC_LSFT);
          tap_code(KC_8);
          unregister_code(KC_LSFT);
          tap_code(KC_ENT);
          SEND_STRING("from "); 
        }
        break;
    case CMNTODATE:
        if (record->event.pressed) {
          SEND_STRING("CMN.ToDate"); 
          register_code(KC_LSFT);
          tap_code(KC_9);
          unregister_code(KC_LSFT);
          tap_code(KC_QUOT);
            
          SEND_STRING("01.06.2021"); 
          tap_code(KC_QUOT);
          register_code(KC_LSFT);
          tap_code(KC_0);
          unregister_code(KC_LSFT);
        }
        break;
    }
    return true;
};
