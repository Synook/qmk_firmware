#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK,
    _NOHOLD,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAV,
    _MOUSE,
    _GAME,
    _GRAISE,
};

enum keycodes {
  COLEMAK = SAFE_RANGE,
  GAME,
};

#define SHIFT_T LSFT_T(KC_T)
#define SHIFT_N RSFT_T(KC_N)
#define CTRL_S LCTL_T(KC_S)
#define CTRL_E RCTL_T(KC_E)
#define ALT_R LALT_T(KC_R)
#define ALT_I LALT_T(KC_I)
#define AGR_Y RALT_T(KC_Y)
#define AGR_W RALT_T(KC_W)
#define GUI_A LGUI_T(KC_A)
#define GUI_O RGUI_T(KC_O)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)

#define GRAISE MO(_GRAISE)
#define LWR_BCK LT(_LOWER, KC_BSPC)
#define RSE_ENT LT(_RAISE, KC_ENT)
#define ADJ_DEL LT(_ADJUST, KC_DEL)
#define NAV_SPC LT(_NAV, KC_SPC)
#define NHD_TAB LT(_NOHOLD, KC_TAB)
#define MSE_ESC LT(_MOUSE, KC_ESC)
#define NDASH RALT(KC_MINS)
#define MDASH RSA(KC_MINS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
      KC_GRV,  KC_Q,    AGR_W,   KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    AGR_Y,   KC_MINS, KC_SCLN,
      KC_EQL,  GUI_A,   ALT_R,   CTRL_S,  SHIFT_T, KC_D,    KC_H,    SHIFT_N, CTRL_E,  ALT_I,   GUI_O,   KC_QUOT,
      KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
                                 NHD_TAB, MSE_ESC, NAV_SPC, RSE_ENT, LWR_BCK, ADJ_DEL
  ),
  [_NOHOLD] = LAYOUT_split_3x6_3(
      _______, _______, KC_W,    _______, _______, _______, _______, _______, _______, KC_Y,    _______, _______,
      _______, KC_A,    KC_R,    KC_S,    KC_T,    _______, _______, KC_N,    KC_E,    KC_I,    KC_O,    _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL
  ),
  [_NAV] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLU,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_RSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, KC_VOLD,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_MNXT,
                                 _______, _______, _______, KC_ENT,  KC_BSPC, KC_DEL
  ),
  [_MOUSE] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX, KC_ACL0,
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_RSFT, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_ACL1,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, KC_ACL2,
                                 _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3
  ),
  [_LOWER] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_GRV,  KC_BSLS, KC_SCLN, NDASH,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 KC_TAB,  KC_ESC,  KC_SPC,  _______, _______, _______
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_TILD, KC_PIPE, KC_COLN, MDASH,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 KC_TAB,  KC_ESC,  KC_SPC,  _______, _______, _______
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
      XXXXXXX, KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, GAME,    XXXXXXX, XXXXXXX, XXXXXXX, RESET,
                                 KC_TAB,  KC_ESC,  KC_SPC,  _______, _______, _______
  ),
  [_GAME] = LAYOUT_split_3x6_3(
      KC_TAB,  KC_1,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_LCTL, KC_2,    KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,   KC_RSFT,
      KC_LSFT, KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M,    KC_COMM, KC_LEFT, KC_DOWN, KC_RGHT,
                                 KC_ESC,  GRAISE,  KC_SPC,  KC_ENT,  KC_LALT, KC_RGUI
  ),
  [_GRAISE] = LAYOUT_split_3x6_3(
      KC_TAB,  KC_3,    KC_4,    _______, KC_5,    KC_T,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   COLEMAK,
      KC_LCTL, KC_6,    _______, _______, _______, KC_G,    KC_F5,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_SCLN,
      KC_LSFT, KC_7,    KC_8,    KC_9,    KC_0,    KC_B,    KC_F11,  KC_F12,  KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
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
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
  }
  return true;
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWR_BCK:
        case RSE_ENT:
        case ADJ_DEL:
        case NAV_SPC:
        case MSE_ESC:
        case NHD_TAB:
            return true;
        default:
            return false;
    }
}
