#include QMK_KEYBOARD_H
#include "muse.h"

#ifdef AUDIO_ENABLE
    float error_song[][2] = SONG(GUITAR_SOUND);
#endif

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAME,
  _GAMERAISE,
  _36,
  _36NOHOLD,
  _36NUM,
  _36SYM,
  _36NAV,
  _36WIN,
  _36FUN,
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAME,
  THRTYSX,
  X______,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GRAISE MO(_GAMERAISE)
#define SHIFT_T LSFT_T(KC_T)
#define SHIFT_N RSFT_T(KC_N)
#define CTRL_S LCTL_T(KC_S)
#define CTRL_E RCTL_T(KC_E)
#define ALT_R LALT_T(KC_R)
#define ALT_I LALT_T(KC_I)
#define GUI_A LGUI_T(KC_A)
#define GUI_O RGUI_T(KC_O)
#define NOH_SPC LT(_36NOHOLD, KC_SPC)
#define NAV_TAB LT(_36NAV, KC_TAB)
#define WIN_ESC LT(_36WIN, KC_ESC)
#define NUM_BCK LT(_36NUM, KC_BSPC)
#define SYM_ENT LT(_36SYM, KC_ENT)
#define FUN_DEL LT(_36FUN, KC_DEL)


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
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, THRTYSX, COLEMAK, QWERTY,  GAME,    _______,
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
[_36] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    X______, X______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    GUI_A,   ALT_R,   CTRL_S,  SHIFT_T, KC_D,    X______, X______, KC_H,    SHIFT_N, CTRL_E,  ALT_I,   GUI_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    X______, X______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    X______, X______, WIN_ESC, NAV_TAB, NOH_SPC, X______, X______, SYM_ENT, NUM_BCK, FUN_DEL, X______, X______
),
[_36NOHOLD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_A,    KC_R,    KC_S,    KC_T,    _______, _______, _______, _______, KC_N,    KC_E,    KC_I,    KC_O,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL,  _______, _______
),
[_36NUM] = LAYOUT_planck_grid(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, _______, _______, X______, X______, X______, KC_RALT, X______,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______, _______, X______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, _______, _______, X______, X______, X______, X______, X______,
    _______, _______, KC_DOT,  KC_0,    KC_MINS, _______, _______, X______, X______, X______, _______, _______
),
[_36SYM] = LAYOUT_planck_grid(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______, _______, X______, X______, X______, KC_RALT, X______,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, _______, _______, X______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______, _______, X______, X______, X______, X______, X______,
    _______, _______, KC_LPRN, KC_RPRN, KC_UNDS, _______, _______, X______, X______, X______, _______, _______
),
[_36FUN] = LAYOUT_planck_grid(
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______, _______, X______, X______, X______, KC_RALT, X______,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, _______, _______, X______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, _______, X______, X______, X______, COLEMAK, RESET,
    _______, _______, KC_MENU, KC_TAB,  KC_SPC,  _______, _______, X______, X______, X______, _______, _______
),
[_36NAV] = LAYOUT_planck_grid(
    X______, KC_RALT, X______, X______, X______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, X______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS,
    X______, X______, X______, X______, X______, _______, _______, X______, KC_PSTE, KC_COPY, KC_CUT,  X______,
    _______, _______, X______, X______, X______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL,  _______, _______
),
[_36WIN] = LAYOUT_planck_grid(
    MEH(KC_Q), MEH(KC_W), MEH(KC_F), MEH(KC_P), MEH(KC_B), _______, _______, MEH(KC_J), MEH(KC_L), MEH(KC_U), MEH(KC_Y), MEH(KC_1),
    MEH(KC_A), MEH(KC_R), MEH(KC_S), MEH(KC_T), MEH(KC_G), _______, _______, MEH(KC_M), MEH(KC_N), MEH(KC_E), MEH(KC_I), MEH(KC_O),
    MEH(KC_Z), MEH(KC_X), MEH(KC_C), MEH(KC_D), MEH(KC_V), _______, _______, MEH(KC_K), MEH(KC_H), MEH(KC_2), MEH(KC_3), MEH(KC_4),
    _______,   _______,   X______,   X______,   X______,   _______, _______, MEH(KC_5), KC_LGUI,   MEH(KC_6), _______,   _______
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
    case THRTYSX:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_36);
      }
      return false;
      break;
    case X______:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
            PLAY_SONG(error_song);
        #endif
      }
      return false;
      break;
  }
  return true;
}
