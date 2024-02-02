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
       S(KC_GRAVE), MEH(KC_1), MEH(KC_2), MEH(KC_3), MEH(KC_4), MEH(KC_5),   MEH(KC_6), MEH(KC_7), MEH(KC_8), MEH(KC_9),  KC_DEL,   KC_GRAVE,
  // ╰────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────╯
                                              _______,  _______,  _______,     _______,  _______
  //                                         ╰────────────────────────────╯ ╰───────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    _______, _______, DRG_TOG, SNIPING, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, KC_BTN2, DRGSCRL, KC_BTN1, _______,    _______, KC_BTN1, DRGSCRL, KC_BTN2, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_ARROW] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────────╮
       RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,       KC_HOME,    KC_PGDN,  KC_PGUP,     KC_END, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────┤
       _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,       KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────┤
       _______, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,    A(KC_LEFT), A(KC_DOWN), A(KC_UP), A(KC_RGHT), _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────────╯
                                  EE_CLR, XXXXXXX,  QK_BOOT,       _______,    _______
  //                            ╰───────────────────────────╯ ╰───────────────────────╯
  ),
};
// clang-format on
//
#ifdef POINTING_DEVICE_ENABLE

void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_POINTER);
    set_auto_mouse_enable(true);
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case SNIPING:
        case DRGSCRL:
        case DRG_TOG:
            return true;
        default:
            return false;
    }
}

static void set_dragscroll(bool enable) {
    charybdis_set_pointer_dragscroll_enabled(enable);

    auto_mouse_layer_off();
    set_auto_mouse_enable(!enable);

    enable ? layer_on(LAYER_POINTER) : layer_off(LAYER_POINTER);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    bool dragscroll_enabled = charybdis_get_pointer_dragscroll_enabled();

    if (dragscroll_enabled && record->event.pressed) {
        set_dragscroll(false);
        return false;
    }

    switch (keycode) {
        case DRG_TOG:
            if (record->event.pressed) {
                bool next = !dragscroll_enabled;
                set_dragscroll(next);
            }
            return false;
        default:
            return true;
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
