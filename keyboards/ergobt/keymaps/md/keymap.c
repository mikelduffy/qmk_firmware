#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // Default Base Layer
#define NAVI 1 // Arrow Keys
// #define NUMB 2 // Numbers and Functions
#define SYMB 2 // Symbols

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Base Layer */
    [BASE] = LAYOUT( // layer 0 : default
        // left hand
        KC_ESC,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_PSCR,
        LCTL_T(KC_ESC), KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       XXXXXXX,
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,
        XXXXXXX,        XXXXXXX,    XXXXXXX,    KC_LGUI,    KC_LALT,
                                                                                    KC_MPRV,    KC_MNXT,
                                                                                                KC_MPLY,
                                                            LT(NAVI, KC_SPC), LT(SYMB, KC_ENT), KC_MUTE,

        // right hand
        KC_7,           KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_GRAVE,
        XXXXXXX,        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        XXXXXXX,        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    RCTL_T(KC_QUOT),
                        KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                    KC_RALT,    KC_RGUI,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        KC_LEFT, KC_RGHT,
        KC_VOLU,
        KC_VOLD, LT(SYMB, KC_ENT), LT(NAVI, KC_SPC)),

    [NAVI] = LAYOUT(
        // left hand
        RESET,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
        AG_NORM,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        AG_SWAP,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BTN1,    KC_BTN2,    _______,
        _______,    XXXXXXX,    XXXXXXX,    KC_ACL0,    KC_ACL1,    KC_ACL2,
        _______,    _______,    _______,    _______,    _______,
                                                                                _______,    _______,
                                                                                            _______,
                                                                    _______,    _______,    _______,

        // right hand
        KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     _______,
        _______,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_MPRV,    KC_MNXT,
        _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_VOLD,    KC_VOLU,
                    KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_MUTE,    KC_MPLY,
                                _______,    _______,    _______,    _______,    _______,
        _______,    _______,
        _______,
        _______,    _______,        _______),

    /* Keymap 2: Programming */
    [SYMB] = LAYOUT(
        // left hand
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    XXXXXXX,
        _______,    KC_PIPE,    KC_PLUS,    KC_UNDS,    KC_LCBR,    KC_LPRN,    XXXXXXX,
        _______,    KC_BSLS,    KC_TILD,    KC_GRAVE,   KC_LBRC,    KC_LT,
        _______,    _______,    _______,    _______,    _______,
                                                                                _______,    _______,
                                                                                            _______,
                                                                    _______,    _______,    _______,

        // right hand
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
        _______,    KC_CIRC,    KC_AMPR,    KC_ASTR,    XXXXXXX,    XXXXXXX,    _______,
        _______,    KC_RPRN,    KC_RCBR,    KC_MINS,    KC_EQL,     XXXXXXX,    _______,
                    KC_GT,      KC_RBRC,    KC_COMM,    KC_DOT,     KC_SLSH,    _______,
                                _______,    _______,    _______,    _______,    _______,
        _______,    _______,
        _______,
        _______,    _______,    _______),
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
