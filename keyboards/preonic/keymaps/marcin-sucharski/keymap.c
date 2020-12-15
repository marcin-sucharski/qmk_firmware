// based on the default preonic keymap

#include "preonic.h"
#include "action_layer.h"

float code_song[][2] = SONG(DVORAK_SOUND);
float game_song[][2] = SONG(COLEMAK_SOUND);
float qwerty_song[][2] = SONG(QWERTY_SOUND);

enum preonic_layers {
  _QWERTY,
  _CODE,
  _LOWER,
  _RAISE,
  _CENTER,
  _CENTER_CODE,
  _ADJUST
//  _GAME
};

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  QWERTY,
  CODE,
//  GAME,

//  BACKLIT
};

enum preonic_tap_dance_keycodes {
  TD_LGPS // LGui PrintScreen
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// base
[_QWERTY] = {
  {KC_GRV,                   KC_1,    KC_2,    KC_3,         KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,                   KC_Q,    KC_W,    KC_E,         KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL },
  {LT(_CENTER_CODE, KC_ESC), KC_A,    KC_S,    KC_D,         KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT,                  KC_Z,    KC_X,    KC_C,         KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT)},
  {KC_LCTL,                  KC_LCTL, KC_LALT, KC_LGUI,      LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT, XXXXXXX, XXXXXXX, KC_RCTL}
},

// temporal
[_LOWER] = {
  {G(A(KC_GRV)), G(A(KC_1)), G(A(KC_2)), G(A(KC_3)), G(A(KC_4)), G(A(KC_5)), G(A(KC_6)), G(A(KC_7)), G(A(KC_8)), G(A(KC_9)), G(A(KC_0)), G(A(KC_BSPC))},
  {_______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______},
  {KC_DEL,       KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE},
  {_______,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     S(KC_NUHS), S(KC_NUBS), KC_HOME,    KC_END,     _______},
  {_______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______}
},

// temporal
[_RAISE] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, _______, _______},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

// temporal
//[_CENTER] = {
//  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______, _______, KC_LCTL, KC_LSFT, KC_LALT, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______},
//  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
//},

// persistent; extends base
//[_CODE] = {
//  {_______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {LT(_CENTER_CODE, KC_ESC),  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
//},

// temporal
[_CENTER_CODE] = {
  {_______, _______, _______, _______, _______, _______,         _______, _______, _______,     _______,      _______, _______},
  {_______, _______, _______, _______, _______, _______,         _______, _______, MEH(KC_INS), _______,      _______, _______},
  {_______, _______, KC_LCTL, KC_LSFT, KC_LALT, _______,         KC_LEFT, KC_DOWN, KC_UP,       KC_RGHT,      _______, MEH(KC_QUOT)},
  {_______, _______, _______, _______, _______, S(LALT(KC_F10)), _______, _______, MEH(KC_LBRC),MEH(KC_RBRC), _______, _______},
  {_______, _______, _______, _______, _______, _______,         _______, _______, KC_LEFT,     KC_DOWN,      KC_UP,   KC_RGHT}
},

// temporal
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

// persistent; extends base
//[_GAME] = {
//  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
//  {_______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
//}
};

// template for new layers
// {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
// {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
// {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
// {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
// {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}

// const uint16_t PROGMEM fn_actions[] = {
// };

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LGPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_PSCR)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            layer_clear();
            default_layer_set(_QWERTY);
#ifdef AUDIO_ENABLE
            PLAY_SONG(qwerty_song);
#endif
          }
          return false;
          break;

//        case CODE:
//          if (record->event.pressed) {
//            layer_clear();
//            default_layer_set(_QWERTY);
//            layer_on(_CODE);
//#ifdef AUDIO_ENABLE
//            PLAY_SONG(code_song);
//#endif
//          }
//          return false;
//          break;

//        case GAME:
//          if (record->event.pressed) {
//            layer_clear();
//            default_layer_set(_QWERTY);
//            layer_on(_GAME);
//#ifdef AUDIO_ENABLE
//#endif
//          }
//          return false;
//          break;

        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;

        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;

//        case BACKLIT:
//          if (record->event.pressed) {
//            register_code(KC_RSFT);
//            #ifdef BACKLIGHT_ENABLE
//              backlight_step();
//            #endif
//            PORTE &= ~(1<<6);
//          } else {
//            // unregister_code(KC_RSFT);
//            PORTE |= (1<<6);
//          }
//          return false;
//          break;
      }
    return true;
};
