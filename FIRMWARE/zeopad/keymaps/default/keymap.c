#include QMK_KEYBOARD_H

#include "encoder.c"

enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

#define LAYOUT_via( \
    k00, k01, k02, k03, k04, k05, \
    k10, k11, k12, k13, k14, k15,\
    k20, k21, k22, k23, k24, k25,\
    k30, k31, k32, k33, k34, k35\
) \
{ \
    { k00, k01, k02, k03 , k04 , k05}, \
    { k10, k11, k12, k13 , k14 , k15}, \
    { k20, k21, k22, k23 , k24 , k25}, \
    { k30, k31, k32, k33 , k34 , k35} \
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ┌───┬───┬───┬───┐
 * │ 7 │ 8 │ 9 │ BS│
 * ├───┼───┬───┼───┤
 * │ 4 │ 5 │ 6 │ESC│
 * ├───┼───┬───┼───┤
 * │ 1 │ 2 │ 3 │TAB│
 * ├───┼───┬───┼───┤
 * │FN │ 0 │ . │RET│
 * └───┴───┴───┴───┘
 */
[_BASE] = LAYOUT_via(
    KC_P7,    KC_P8,  KC_P9,    KC_BSPC,        KC_A, KC_VOLU,
    KC_P4,    KC_P5,  KC_P6,    KC_ESC,         KC_A, KC_VOLD,
    KC_P1,    KC_P2,  KC_P3,    KC_TAB,         KC_A, KC_VOLU,
    TT(_FN1), KC_P0,  KC_PDOT,  KC_ENTER,       KC_A, KC_VOLD
),

/* FN
 * ┌───┬───┬───┬───┐
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * └───┴───┴───┴───┘
 */
[_FN1] = LAYOUT_via(
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLU,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLD,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLU,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLD
),

/* FN
 * ┌───┬───┬───┬───┐
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * └───┴───┴───┴───┘
 */
[_FN2] = LAYOUT_via(
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLU,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLD,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLU,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLD
),

/* FN
 * ┌───┬───┬───┬───┐
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * ├───┼───┬───┼───┤
 * │   │   │   │   │
 * └───┴───┴───┴───┘
 */
[_FN3] = LAYOUT_via(
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLU,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLD,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLU,
    KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_VOLD
),
};

//#if defined(ENCODER_MAP_ENABLE)
//const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//    [_BASE] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
//    [_FN1] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
//    [_FN2] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
//    [_FN3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)},
//};
//#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _FN1:
            
            rgblight_sethsv_noeeprom(180,255,20);
            break;
        case _FN2:
            
            rgblight_sethsv_noeeprom(35,255,20);
            break;
        case _FN3:
            
            rgblight_sethsv_noeeprom(100,255,20);
            break;
        case _BASE:
            
            rgblight_sethsv(255,255,20);
            break;
        default: // for any other layers, or the default layer
            
            rgblight_sethsv(255,255,20);
            break;
    }
  return state;
}