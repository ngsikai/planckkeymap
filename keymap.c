/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _NAV,
  _SYMNUM,
  _FN
};

enum planck_keycodes {
  VS_CODE,
  CHROME,
  SLACK,
  SPOTIFY
};

#define SYMNUM MO(_SYMNUM)
#define SYMSPC LT(_SYMNUM,KC_SPC)
#define NAV_V LT(_NAV,KC_V)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case VS_CODE:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(" "));
                    wait_ms(70);
                    SEND_STRING("code");
                    wait_ms(20);
                    SEND_STRING(SS_TAP(X_ENTER));
                    // wait_ms(10);
                }
                return false;
                break;
            case CHROME:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(" "));
                    wait_ms(70);
                    SEND_STRING("chrome");
                    wait_ms(20);
                    SEND_STRING(SS_TAP(X_ENTER));
                    // wait_ms(10);
                }
                return false;
                break;
            case SLACK:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(" "));
                    wait_ms(70);
                    SEND_STRING("slack");
                    wait_ms(20);
                    SEND_STRING(SS_TAP(X_ENTER));
                    // wait_ms(10);
                }
                return false;
                break;
            case SPOTIFY:
                if (record->event.pressed) {
                    SEND_STRING(SS_LGUI(" "));
                    wait_ms(70);
                    SEND_STRING("spotify");
                    wait_ms(20);
                    SEND_STRING(SS_TAP(X_ENTER));
                    // wait_ms(10);
                }
                return false;
                break;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  | Ctrl |      | Alt  | GUI  |SymNum|Space | GUI  | Alt  | Caps | Ctrl |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    NAV_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
    MO(_FN), KC_LCTL, _______, KC_LALT, KC_LGUI, SYMNUM,  SYMSPC,  KC_RGUI, KC_RALT, KC_CAPS, KC_RCTL, _______
),

/* Symbol + Numbers
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ~  |      |      |      |      |   &  |   _  |   (  |   )  |   -  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   `  |   {  |   }  |      |      |   :  |   +  |   [  |   ]  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMNUM] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_UNDS, KC_LPRN, KC_RPRN, KC_MINS, KC_BSLS,
    _______, KC_GRV,  KC_LCBR, KC_RCBR, _______, _______, KC_COLN, KC_PPLS, KC_LBRC, KC_RBRC, KC_EQL,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |SPOTIF|SLACK |      |      | Prev | Next | Alt<-| Alt->|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |VSCODE|CHROME|      |      |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Home | PDN  |  PUP |  End |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, SPOTIFY,   SLACK, _______, _______, LGUI(KC_LCBR), LGUI(KC_RCBR), LALT(KC_LEFT), LALT(KC_RIGHT), _______,
    _______, VS_CODE,  CHROME, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY 
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |BL_OFF|BL_DEC|BL_INC|BL_ON |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
    _______, _______, _______, _______, _______, _______, _______, RGB_TOG, BL_OFF,  BL_DEC,  BL_INC,  BL_ON
)

};
