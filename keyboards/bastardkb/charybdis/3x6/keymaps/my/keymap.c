/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include <stdint.h>
#include "action_layer.h"
#include "color.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include "../../config.h"
#include "info_config.h"
#include "default_keyboard.h"
#include "charybdis.h"
#include "pointing_device/pointing_device.h"
#include "pointing_device/pointing_device_auto_mouse.h"
#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUM,
    LAYER_POINTER,
    LAYER_ARROW,
};

#define LA_ESC LT(LAYER_ARROW, KC_ESC)
#define LA_LBRC LT(LAYER_ARROW, KC_LBRC)
#define LN_ENT LT(LAYER_NUM, KC_ENT)
#define GT_BTN1 LGUI_T(KC_BTN1)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────╮
       LA_ESC,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,            KC_P,         KC_LBRC,
  // ├──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────┤
       LCTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, RCTL_T(KC_SCLN),  C_S_T(KC_RBRC),
  // ├──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────┤
       LSFT_T(KC_MINS),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, RSFT_T(KC_SLSH), RALT_T(KC_BSLS),
  // ╰──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────╯
                                     KC_BSPC,  KC_SPC,  KC_LGUI,       KC_RGUI, LN_ENT
  //                                ╰───────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────╮
       KC_EQL,      S(KC_1),   S(KC_2),   S(KC_3),   S(KC_4),   S(KC_5),       S(KC_6),   S(KC_7),   S(KC_8),   S(KC_9), S(KC_0),    KC_QUOT,
  // ├────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────┤
       S(KC_EQL),   KC_1 ,     KC_2,      KC_3,      KC_4,      KC_5,             KC_6,      KC_7,      KC_8,      KC_9,    KC_0, S(KC_QUOT),
  // ├────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────┤
       S(KC_GRAVE), RCS(KC_1), RCS(KC_2), RCS(KC_3), RCS(KC_4), RCS(KC_5),   RCS(KC_6), RCS(KC_7), RCS(KC_8), RCS(KC_9),  KC_DEL,   KC_GRAVE,
  // ╰────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────╯
                                              _______,  _______,  _______,       KC_RGUI, LN_ENT
  //                                         ╰────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, KC_BTN2, DRGSCRL, KC_BTN1, _______,    _______, KC_BTN1, DRGSCRL, KC_BTN2, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, SNIPING, _______, _______,    _______, _______, SNIPING, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_ARROW] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────╮
       RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_HOME,    KC_PGDN,  KC_PGUP,     KC_END, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────┤
       RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, DPI_MOD,       KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────┤
       RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, S_D_MOD,    A(KC_LEFT), A(KC_DOWN), A(KC_UP), A(KC_RGHT), XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────╯
                                  EE_CLR, XXXXXXX,  QK_BOOT,       _______,    _______
  //                            ╰───────────────────────────╯ ╰───────────────────────╯
  ),
};
// clang-format on
//
#ifdef POINTING_DEVICE_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    int current_layer = get_highest_layer(state);
    // Enable drag-scroll for arrow layer
    charybdis_set_pointer_dragscroll_enabled(current_layer == LAYER_ARROW);
    return state;
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_POINTER);
    set_auto_mouse_enable(true);
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case SNIPING:
        case DRGSCRL:
            return true;
        default:
            return false;
    }
}
#endif

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);

#    define LAYER_POINTER_HSV 180, 120, 50

bool rgb_matrix_indicators_user() {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case LAYER_POINTER: {
            HSV hsv = (HSV){LAYER_POINTER_HSV};
            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
            return false;
        }
        default:
            return true;
    }
}

#endif

void shutdown_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}
