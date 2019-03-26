#include QMK_KEYBOARD_H

// readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum keymap_layout {
    MAC = 0,      // matches MF68 layout
    MFUN,         // 0x02
    SETTINGS,     // 0x04
    WIN,
    WFUN,
};

// Colors of the layer indicator LED
// This list needs to define layer 0xFFFFFFFF, it is the end of the list, and the unknown layer
const Layer_Info layer_info[] = {
  // Layer     Mask           Red     Green   Blue
  {0x00000000, 0xFFFFFFFF, {0x0000, 0x0FFF, 0x0000}}, // base layer - green
  {0x00000002, 0xFFFFFFFE, {0x0000, 0x0000, 0x0FFF}}, // function layer - blue
  {0x00000004, 0xFFFFFFFC, {0x0FFF, 0x0000, 0x0FFF}}, // settings layer - magenta
  {0xFFFFFFFF, 0xFFFFFFFF, {0x0FFF, 0x0FFF, 0x0FFF}}, // unknown layer - REQUIRED - white
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap MAC: (Base Layer) Default Layer for MacOS
   * ,---------.  ,-------------------------------------------------------------. ,---------.
   * | F1 | F2 |  |Esc~| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backspa | |Ins |PgUp|
   * |---------|  |-------------------------------------------------------------| |---------|
   * | F3 | F4 |  |Tab  | Q | W | E | R | T | Y | U | I | O | P | Å | ¨ |  Ret  | |Del |PgDn|
   * |---------|  |-------------------------------------------------------.     | `---------'
   * | F5 | F6 |  |FUNC  | A | S | D | F | G | H | J | K | L | Ö | Ä | '  |     |
   * |---------|  |-------------------------------------------------------------| ,----.
   * | F7 | F8 |  |Shft| \ | Z | X | C | V | B | N | M | , | . | - |Shift       | | Up |
   * |---------|  |--------------------------------------------------------------------------.
   * | F9 | F10|  |Ctrl|Alt |Cmd |      Space            |Cmd |Alt |Ctrl |   |Left|Dwn |Rig |
   * `---------'  `------------------------------------------------------'   `--------------'
   */
  [MAC] = LAYOUT_iso(
    KC_F1,  KC_F2,    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,          KC_INS,  KC_PGUP, \
    KC_F3,  KC_F4,    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_ENT,           KC_DEL,  KC_PGDN, \
    KC_F5,  KC_F6,    MO(MFUN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,                                      \
    KC_F7,  KC_F8,    KC_LSFT,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,          KC_UP,            \
    KC_F9,  KC_F10,   KC_LCTL,  KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Keymap FUNCTION: Function Layer for MAC Layer
   * ,---------.  ,-------------------------------------------------------------. ,---------.
   * |    |    |  | §  |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete  | |    |Home|
   * |---------|  |-------------------------------------------------------------| |---------|
   * |    |    |  |     |   |Up |   |   |   |   |PgU|Up |PgD|   |   |   |       | |    |End |
   * |---------|  |-------------------------------------------------------.     | `---------'
   * |    |    |  |      |Lft|Dwn|Rig|   |   |Hom|Lft|Dwn|Rig|   |   |    |     |
   * |---------|  |-------------------------------------------------------------| ,----.
   * |    |    |  |    |   |   |   |   |   |   |End|Mut|V- |V+ |   |TG(SETTINGS)| |    |
   * |---------|  |-------------------------------------------------------------------------.
   * |    |    |  |    |    |    |                       |    |    |     |   |Prev|Play|Next|
   * `---------'  `------------------------------------------------------'   `--------------'
   */
  [MFUN] = LAYOUT_iso(
    _______, _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           DF(WIN), KC_PGUP, \
    _______, _______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,          _______, KC_PGDN, \
    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,                                     \
    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,          TG(SETTINGS),     _______,          \
    _______, _______, _______, _______, _______,                            _______,                            _______, _______, _______,          KC_MRWD, KC_MPLY, KC_MFFD  \
  ),

  /* Keymap WIN: (Second Base Layer) Default Layer for Windows
   * ,---------.  ,-------------------------------------------------------------. ,---------.
   * | F1 | F2 |  |Esc~| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backspa | |Ins |Home|
   * |---------|  |-------------------------------------------------------------| |---------|
   * | F3 | F4 |  |Tab  | Q | W | E | R | T | Y | U | I | O | P | Å | ¨ |  Ent  | |Del |End |
   * |---------|  |-------------------------------------------------------.     | `---------'
   * | F5 | F6 |  |FUNC  | A | S | D | F | G | H | J | K | L | Ö | Ä | '  |     |
   * |---------|  |-------------------------------------------------------------| ,----.
   * | F7 | F8 |  |Shft| \ | Z | X | C | V | B | N | M | , | . | - |Shift       | | Up |
   * |---------|  |--------------------------------------------------------------------------.
   * | F9 | F10|  |Ctrl|Win |Alt |      Space            |Alt |Win |Ctrl |   |Left|Dwn |Rig |
   * `---------'  `------------------------------------------------------'   `--------------'
   */
  [WIN] = LAYOUT_iso(
    KC_F1,  KC_F2,    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,          KC_INS,  KC_HOME, \
    KC_F3,  KC_F4,    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_ENT,           KC_DEL,  KC_END,  \
    KC_F5,  KC_F6,    MO(WFUN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,                                      \
    KC_F7,  KC_F8,    KC_LSFT,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,          KC_UP,            \
    KC_F9,  KC_F10,   KC_LCTL,  KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Keymap FUNCTION: Function Layer for WIN Layer
   * ,---------.  ,-------------------------------------------------------------. ,---------.
   * |    |    |  | §  |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete  | |    |PgUp|
   * |---------|  |-------------------------------------------------------------| |---------|
   * |    |    |  |     |   |Up |   |   |   |   |PgU|Up |PgD|   |   |   |       | |    |PgDn|
   * |---------|  |-------------------------------------------------------.     | `---------'
   * |    |    |  |      |Lft|Dwn|Rig|   |   |Hom|Lft|Dwn|Rig|   |   |    |     |
   * |---------|  |-------------------------------------------------------------| ,----.
   * |    |    |  |    |   |   |   |   |   |   |End|Mut|V- |V+ |   |TG(SETTINGS)| |    |
   * |---------|  |-------------------------------------------------------------------------.
   * |    |    |  |    |    |    |                       |    |    |     |   |Prev|Play|Next|
   * `---------'  `------------------------------------------------------'   `--------------'
   */
  [WFUN] = LAYOUT_iso(
    _______, _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           DF(MAC), KC_PGUP, \
    _______, _______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,          _______, KC_PGDN, \
    _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,                                     \
    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,          TG(SETTINGS),     _______,          \
    _______, _______, _______, _______, _______,                            _______,                            _______, _______, _______,          KC_MPRV, KC_MPLY, KC_MNXT  \
  ),

  /* Keymap SETTINGS: Settings Layer
   * ,---------.  ,-------------------------------------------------------------. ,---------.
   * |    |    |  |LaCl|   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL Toggl| |    |    |
   * |---------|  |-------------------------------------------------------------| |---------|
   * |    |    |  |     |   |   |   |   |   |   |   |   |   |   |   |   |       | |    |    |
   * |---------|  |-------------------------------------------------------.     | `---------'
   * |    |    |  |      |   |   |   |   |   |   |   |   |   |   |   |Rst |     |
   * |---------|  |-------------------------------------------------------------| ,----.
   * |    |    |  |    |   |   |   |   |   |   |   |   |   |   |   |            | |    |
   * |---------|  |-------------------------------------------------------------------------.
   * |    |    |  |    |    |    |                       |    |    |     |   |    |    |    |
   * `---------'  `------------------------------------------------------'   `--------------'
   */

  [SETTINGS] = LAYOUT_iso(
    XXXXXXX, XXXXXXX, KC_FN0,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  BL_INC,  BL_TOGG,          XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,                                       \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
};

const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(LFK_CLEAR),                               // FN0 - reset layers
    ACTION_FUNCTION(LFK_CLICK_FREQ_HIGHER),                   // FN1 - Increase Freq of audio click
    ACTION_FUNCTION(LFK_CLICK_FREQ_LOWER),                    // FN2 - Decrease Freq of audio click
    ACTION_FUNCTION(LFK_CLICK_TIME_LONGER),                   // FN3 - Increase length of audio click
    ACTION_FUNCTION(LFK_CLICK_TIME_SHORTER),                  // FN4 - Decrease length of audio click
    ACTION_FUNCTION(LFK_CLICK_TOGGLE),                        // FN5 - Toggle audio click
  };


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
    // This keymap only has a single base layer, so reset the default if needed
    if(eeconfig_read_default_layer() > 1){
        eeconfig_update_default_layer(1);
        default_layer_set(1);
    }
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
