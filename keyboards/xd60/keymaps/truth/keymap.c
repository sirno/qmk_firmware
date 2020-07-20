#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  [0] = LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_SLSH, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_DEL,      \
      KC_LCTL, KC_LALT, KC_LGUI,                          KC_SPC,                          MO(1),   TG(2),    KC_LEFT, KC_DOWN,  KC_RIGHT),

  // 1: Function Layer
  [1] = LAYOUT_all(
      RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,   KC_F14,    \
      KC_NO,   KC_WH_U, KC_UP,   KC_WH_D, KC_BSPC,KC_HOME,KC_CALC,KC_NO,  KC_INS, KC_NO,   KC_PSCR, KC_SLCK,  KC_PAUS,           KC_DEL,    \
      KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_DEL, KC_END, KC_PGDN,KC_NO,  KC_NO,  KC_NO,   KC_HOME, KC_PGUP,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_GRV,  KC_NO,   KC_APP,  BL_STEP,KC_NO,  KC_NO,  KC_VOLD,KC_VOLU,KC_MUTE, KC_END,  KC_PGDN,  KC_RSFT, KC_PGUP,  KC_INS,      \
      KC_LCTL, KC_LALT, KC_LGUI,                          KC_SPC,                          MO(1),   TG(2),    KC_HOME, KC_PGDOWN,KC_END),

  // 2: alternative Base Layer
  [2] = LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_SLSH, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_DEL,      \
      KC_LCTL, KC_LGUI, MO(3),                          KC_SPC,                            KC_LALT, TG(2),    KC_LEFT, KC_DOWN,  KC_RIGHT),

  // 3: alternative Key Layer
  [3] = LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,    \
      KC_TAB,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      KC_GRV,  KC_H,    KC_J,    KC_K,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_B,    KC_N,    KC_M,    KC_COMM,KC_DOT, KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_DEL,      \
      KC_LCTL, KC_LGUI,   MO(3),                        KC_SPC,                            KC_LALT, TG(2),    KC_LEFT, KC_DOWN,  KC_RIGHT),
};

// Loop
void matrix_scan_user(void) {
  // Empty
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case 1:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case 2:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case 3:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
};

// Debug
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;
};
