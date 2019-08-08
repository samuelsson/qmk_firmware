#include QMK_KEYBOARD_H

enum keymap_layout {
  MAC = 0,  // Mac (Default layer)
  MFN,      // Mac function layer
  WIN,
  WFN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap Mac (Base) Layer
   * ,---------------------------------------------------------------.
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | + | ´ |Backsp |Rst|
   * |---------------------------------------------------------------|
   * | Tab | Q | W | E | R | T | Y | U | I | O | P | Å | ¨ |     |PgU|
   * |------------------------------------------------------.    |---|
   * | Func | A | S | D | F | G | H | J | K | L | Ö | Ä | ' |Ret |PgD|
   * |---------------------------------------------------------------|
   * |Shft| < | Z | X | C | V | B | N | M | , | . | - |Shift |Up |Fn |
   * |---------------------------------------------------------------|
   * |Ctrl|Alt |Cmd |         Space          |Cmd |Alt | |Lft|Dwn|Rig|
   * `-------------------------------------------------' `-----------'
   */
  [MAC] = LAYOUT_65_iso(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_PGUP, \
    MO(MFN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGDN, \
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   MO(MFN), \
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RGUI, KC_RALT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Keymap Mac Fn Layer
   * ,---------------------------------------------------------------.
   * | § |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete |Rst|
   * |---------------------------------------------------------------|
   * |Caps |   |Up |   |   |   |   |PgU|Up |PgD|   |   |   |     |Hom|
   * |------------------------------------------------------.    |---|
   * |      |Lft|Dwn|Rig|   |   |Hom|Lft|Dwn|Rig|   |   |   |    |End|
   * |---------------------------------------------------------------|
   * |    |   |   |   |   |   |   |End|Mut|V- |V+ |   |      |   |   |
   * |---------------------------------------------------------------|
   * |    |    |    |                        |    |    | |   |   |   |
   * `-------------------------------------------------' `-----------'
   */
  [MFN] = LAYOUT_65_iso(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  RESET,   \
    KC_CAPS, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,          KC_HOME, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, _______, DF(WIN), _______, \
    _______, _______, _______,                   _______,                            _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  /* Keymap Windows Layer
   * ,---------------------------------------------------------------.
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | + | ´ |Backsp |Rst|
   * |---------------------------------------------------------------|
   * | Tab | Q | W | E | R | T | Y | U | I | O | P | Å | ¨ |     |PgU|
   * |------------------------------------------------------.    |---|
   * | Func | A | S | D | F | G | H | J | K | L | Ö | Ä | ' |Ent |PgD|
   * |---------------------------------------------------------------|
   * |Shft| < | Z | X | C | V | B | N | M | , | . | - |Shift |Up |Fn |
   * |---------------------------------------------------------------|
   * |Ctrl|Win |Alt |         Space          |Alt |Ctrl| |Lft|Dwn|Rig|
   * `-------------------------------------------------' `-----------'
   */
  [WIN] = LAYOUT_65_iso(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_PGUP, \
    MO(WFN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGDN, \
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   MO(WFN), \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, KC_RCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Keymap Windows Fn Layer
   * ,---------------------------------------------------------------.
   * | § |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete |Rst|
   * |---------------------------------------------------------------|
   * |Caps |   |Up |   |   |   |   |PgU|Up |PgD|   |   |   |     |Hom|
   * |------------------------------------------------------.    |---|
   * |      |Lft|Dwn|Rig|   |   |Hom|Lft|Dwn|Rig|   |   |   |    |End|
   * |---------------------------------------------------------------|
   * |    |   |   |   |   |   |   |End|Mut|V- |V+ |   |      |   |   |
   * |---------------------------------------------------------------|
   * |    |    |    |                        |    |    | |   |   |   |
   * `-------------------------------------------------' `-----------'
   */
  [WFN] = LAYOUT_65_iso(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  RESET,   \
    KC_CAPS, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,          KC_HOME, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, _______, DF(MAC), _______, \
    _______, _______, _______,                   _______,                            _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
