#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
    _GRAISE,
};

enum keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAME,
};

#define ADJUST MO(_ADJUST)
#define GRAISE MO(_GRAISE)
#define SFT_ENT RSFT_T(KC_ENT)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_DEL RCTL_T(KC_DEL)
#define LWR_ESC LT(_LOWER, KC_ESC)
#define RSE_BCK LT(_RAISE, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
      KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_MINS, ADJUST,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
                                 CTL_TAB, LWR_ESC, KC_SPC,  SFT_ENT, RSE_BCK, CTL_DEL
  ),
  [_QWERTY] = LAYOUT_split_3x6_3(
      KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    ADJUST,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
                                 CTL_TAB, LWR_ESC, KC_SPC,  SFT_ENT, RSE_BCK, CTL_DEL
  ),
  [_LOWER] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, KC_MNXT, KC_VOLU, KC_VOLD, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
                                 _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_F11,
      _______, XXXXXXX, KC_LBRC, KC_RBRC, KC_EQL,  KC_BSLS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F12,
      _______, XXXXXXX, KC_LCBR, KC_RCBR, KC_PLUS, KC_PIPE, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
                                 KC_TAB,  KC_ESC,  KC_SPC,  _______, _______, _______
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
      RESET,   XXXXXXX, GAME,    QWERTY,  COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_GAME] = LAYOUT_split_3x6_3(
      KC_TAB,  KC_1,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_LCTL, KC_2,    KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,   KC_RSFT,
      KC_LSFT, KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M,    KC_COMM, KC_LEFT, KC_DOWN, KC_RGHT,
                                 KC_ESC,  GRAISE,  KC_SPC,  KC_ENT,  KC_LALT, KC_RGUI
  ),
  [_GRAISE] = LAYOUT_split_3x6_3(
      KC_TAB,  KC_3,    KC_4,    _______, KC_5,    KC_T,    _______, _______, _______, _______, _______, COLEMAK,
      KC_LCTL, KC_6,    _______, _______, _______, KC_G,    _______, _______, _______, _______, _______, _______,
      KC_LSFT, KC_7,    KC_8,    KC_9,    KC_0,    KC_B,    _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______
  ),
};

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
