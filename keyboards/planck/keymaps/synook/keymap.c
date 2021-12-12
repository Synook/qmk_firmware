#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAME,
  _GAMERAISE,
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAME
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GRAISE MO(_GAMERAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_RALT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_RALT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_MHEN, KC_HENK, KC_KANA, KC_MINS, KC_EQL,  KC_GRV,  KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_INS,  KC_PSCR, KC_CAPS, KC_UNDS, KC_PLUS, KC_TILD, KC_DQUO, KC_LCBR, KC_RCBR, KC_PIPE, _______,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, COLEMAK, QWERTY,  GAME,    _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_GAME] = LAYOUT_planck_grid(
    KC_TAB,  KC_1,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LCTL, KC_2,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
    KC_LSFT, KC_3,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_H,    KC_J,    KC_K,    KC_UP,   KC_L,
    KC_ESC,  KC_4,    KC_LALT, KC_LGUI, GRAISE,  KC_SPC,  KC_SPC,  KC_N,    KC_M,    KC_LEFT, KC_DOWN, KC_RGHT
),
[_GAMERAISE] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    _______, KC_GRV,  KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, KC_ENT,
    _______, KC_P,    KC_COMM, KC_DOT,  KC_SLSH, KC_F11,  KC_F12,  KC_HOME, KC_PGUP, _______, _______, COLEMAK,
    _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, _______, _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
  }
  return true;
}
