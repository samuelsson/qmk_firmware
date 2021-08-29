#include QMK_KEYBOARD_H

#define MAC 0
#define MFN 1
#define WIN 2
#define WFN 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* 0: Mac layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ INS │ FN  │ DEL │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
   * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │   BSPC    │HOME │
   * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
   * │  TAB   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │ RETURN │PGUP │
   * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐       |─────┤
   * │  LCTRL  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │     │       │PGDN │
   * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴─┬─────┼─────┤
   * │LSHIFT│     │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  RSHFT   │ UP  │END  │
   * ├──────┼─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴────┬┴────┬┴────┬┴────┬─────┼─────┼─────┤
   * │LCTRL │ LALT  │ LCMD │                 SPC                 │RCMD │ FN  │RALT │LEFT │DOWN │RIGHT│
   * └──────┴───────┴──────┴─────────────────────────────────────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [MAC] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  MO(MFN),  KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    MO(MFN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RGUI,  MO(MFN),  KC_RALT,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  /* 1: Mac FN layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │     │     │     │     │     │     │     │     │     │     │     │     │     │     │ FN  │     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
   * │     │     │     │     │     │     │     │     │     │     │     │     │     │   RESET   │     │
   * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
   * │        │     │     │     │     │     │     │     │     │     │     │     │     │        │     │
   * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐       |─────┤
   * │         │     │     │     │     │     │     │     │     │     │     │     │     |       │     │
   * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴─┬─────┼─────┤
   * │      |     │     │     │     │     │     │     │     │     │     │     │          │     │     │
   * ├──────┼─────┴─┬───┴──┬──┴─────┴─────┴─────┴─────┴─────┴────┬┴────┬┴────┬┴────┬─────┼─────┼─────┤
   * │      │       │      │                                     │     │     │     │     │     │     │
   * └──────┴───────┴──────┴─────────────────────────────────────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */
  [MFN] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,    XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_UP,    KC_PGDN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_MOD,  RGB_TOG,  RGB_VAD,  RGB_VAI,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,  XXXXXXX,            TO(WIN),  XXXXXXX,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  KC_MRWD,  KC_MPLY,  KC_MFFD
  ),

  [WIN] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  MO(WFN),  KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    MO(WFN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RCTL,  MO(WFN),  KC_RALT,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [WFN] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,    XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_UP,    KC_PGDN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RGB_MOD,  RGB_TOG,  RGB_VAD,  RGB_VAI,  KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,  XXXXXXX,            TO(MAC),  XXXXXXX,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  KC_MRWD,  KC_MPLY,  KC_MFFD
  )
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case MAC:
        rgblight_setrgb_white();
        break;
    case MFN:
        rgblight_setrgb_white();
        break;
    case WIN:
        rgblight_setrgb_blue();
        break;
    case WFN:
        rgblight_setrgb_blue();
        break;
    default:
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
    return state;
}
