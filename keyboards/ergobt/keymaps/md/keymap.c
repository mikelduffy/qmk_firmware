#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // Default Base Layer
#define SPMD 1 // Keypad and Arrow Keys
#define PGMD 2 // Programming

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Base Layer */
    [BASE] = LAYOUT( // layer 0 : default
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_PSCR,
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_LBRC,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
        KC_MEH, KC_HYPR, KC_LCTRL, KC_LGUI, KC_LALT,
                                             KC_MPRV, KC_MNXT,
                                                      KC_MPLY,
                  LT(SPMD, KC_SPC), LT(PGMD, KC_ENT), KC_MUTE,

        // right hand
        KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_GRAVE,
        KC_BSLS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RCTL_T(KC_QUOT),
                 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                       KC_RALT, KC_RGUI, KC_RCTRL, KC_HYPR, KC_MEH,
        KC_LEFT, KC_RGHT,
        KC_VOLU,
        KC_VOLD, LT(PGMD, KC_ENT), LT(SPMD, KC_SPC)),

    /* Keymap 1: Arrow and Mouse Keys */
    [SPMD] = LAYOUT(
        // left hand
        AG_NORM, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        _______, KC_SLSH, KC_7, KC_8, KC_9, LSFT(KC_8), _______,
        _______, KC_MINS, KC_4, KC_5, KC_6, LSFT(KC_EQL), _______,
        _______, KC_0, KC_1, KC_2, KC_3, KC_DOT,
        _______, _______, _______, _______, _______,
        KC_SPC, _______,
        _______,
        _______, _______, _______,

        // right hand
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, AG_SWAP,
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD, KC_VOLU,
        _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,
        _______, _______, _______, _______, _______,
        _______, KC_SPC,
        _______,
        _______, _______, _______),

    /* Keymap 2: Programming */
    [PGMD] = LAYOUT(
        // left hand
        _______, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18,
        _______, _______, LSFT(KC_QUOT), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_7), _______,
        _______, _______, KC_QUOT, LSFT(KC_9), LSFT(KC_0), LSFT(KC_BSLS), _______,
        _______, _______, KC_GRAVE, KC_LBRC, KC_RBRC, _______,
        _______, _______, _______, _______, _______,
                                                      KC_ENT, _______,
                                                              _______,
                                            _______, _______, _______,

        // right hand
        KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, _______,
        _______, KC_EQL, LSFT(KC_7), LSFT(KC_8), _______, _______, _______,
        _______, LSFT(KC_1), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_SCLN), LSFT(KC_QUOT),
                 _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_SLSH), _______,
                          _______, _______, _______, _______, _______,
        _______, KC_ENT,
        _______,
        _______, _______, _______),
};

const uint16_t PROGMEM fn_actions[] = {
    // [1] = ACTION_LAYER_TAP_TOGGLE(SPMD) // FN1 - Momentary Layer 1 (Symbols)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{
};

// uint32_t layer_state_set_user(uint32_t state) {
//   uint8_t layer = biton32(layer_state);
//   switch (layer) {
//     case 0:
//       ergodox_left_led_2_off();
//       ergodox_left_led_3_off();
//       ergodox_left_led_1_on();
//       break;
//     case 1:
//       ergodox_left_led_1_off();
//       ergodox_left_led_3_off();
//       ergodox_left_led_2_on();
//       break;
//     case 2:
//       ergodox_left_led_1_off();
//       ergodox_left_led_2_off();
//       ergodox_left_led_3_on();
//       break;
//     default:
//       break;
//   }
//   return state;
// };
