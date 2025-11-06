#include QMK_KEYBOARD_H
#include "eeprom.h"

extern rgb_config_t rgb_matrix_config;

#define KC_BRIU KC_BRIGHTNESS_UP
#define KC_BRID KC_BRIGHTNESS_DOWN
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN
#define KC_VOLM KC_AUDIO_MUTE
#define KC_PAUS KC_MEDIA_PLAY_PAUSE
#define KC_TRIT LCTL(KC_TAB)
#define MC_TRIT LGUI(LOPT(KC_RIGHT))
#define KC_TLFT LCTL(LSFT(KC_TAB))
#define MC_TLFT LGUI(LOPT(KC_LEFT))
#define KC_SLFT LALT(LCTL(KC_LEFT))
#define MC_SLFT LCTL(KC_LEFT)
#define KC_SRIT LALT(LCTL(KC_RIGHT))
#define MC_SRIT LCTL(KC_RIGHT)
#define KC_LCLC MS_BTN1
#define KC_RCLC MS_BTN2
#define KC_WLFT LCTL(KC_LEFT)
#define KC_WRIT LCTL(KC_RIGHT)
#define MC_WLFT LALT(KC_LEFT)
#define MC_WRIT LALT(KC_RIGHT)
#define KC_MLFT MS_LEFT
#define KC_MRIT MS_RGHT
#define KC_MUP MS_UP
#define KC_MDWN MS_DOWN
#define KC_PLFT MS_WHLL
#define KC_PRIT MS_WHLR
#define KC_PUP MS_WHLU
#define KC_PDWN MS_WHLD
#define MC_PUP MS_WHLD
#define MC_PDWN MS_WHLU
#define KC_BWRD LCTL(KC_BSPC)
#define KC_DWRD LCTL(KC_DEL)
#define MC_BWRD LALT(KC_BSPC)
#define MC_DWRD LALT(KC_DELETE)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(KC_Y)
#define KC_R_GUI KC_RIGHT_GUI
#define MC_MENU LGUI(KC_SPACE)
#define TOG_MAC TG(_MAC_BASE)
#define MC_NTAB LGUI(KC_T)
#define MC_DTAB LGUI(KC_W)
#define MC_SRCH LGUI(KC_L)
#define KC_NTAB LCTL(KC_T)
#define KC_DTAB LCTL(KC_W)
#define KC_SRCH LCTL(KC_L)
#define C_WHI {0, 0, 255}
#define C_RED {0, 255, 255}
#define C_PUR {180, 255, 255}
#define C_YEL {43, 255, 255}
#define C_TEL {127, 255, 255}
#define C_GRE {85, 255, 255}
#define C_OFF {0, 0, 0}
#define C_BLU {170, 255, 255}
#define C_ORA {21, 255, 255}


#define _BASE 0
#define _NUMS 1
#define _SYMS 2
#define _FN 3
#define _MOS 4
#define _DEL 5
#define _MAC_BASE 6
#define _MAC_SYMS 7
#define _MAC_MOS 8
#define _MAC_DEL 9

#define HOLDING_TERM 65

enum custom_keycodes {
    H_ESC = SAFE_RANGE,
    H_QUOTE,
    H_TAB,
    H_ENTER,
    M_MOUSE,
    M_SYMS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_DEL,   KC_BSPC,   KC_Y,      KC_U,      KC_I,      KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      H_QUOTE,  H_TAB,     KC_H,      KC_J,      KC_K,      KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      H_ESC,    H_ENTER,   KC_N,      KC_M,      KC_COMMA,  KC_DOT,  KC_SLASH,
        KC_LCTL, KC_LALT, MO(_FN), KC_LSFT, MO(_SYMS), KC_SPC,   KC_SPC,    MO(_NUMS), MO(_MOS),  XXXXXXX,   KC_RCTL, KC_LGUI
        ),
    [_MAC_BASE] = LAYOUT_planck_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_R_GUI, KC_ROPT,  KC_TRNS,  KC_TRNS,  M_SYMS,    KC_TRNS,  KC_TRNS,  KC_TRNS,   M_MOUSE,  KC_TRNS,  KC_TRNS,  MC_MENU
        ),
    [_NUMS] = LAYOUT_planck_grid(
        KC_0,     KC_1,    KC_2,    KC_3,     XXXXXXX,  KC_TRNS,   KC_TRNS, XXXXXXX,  KC_PERC,  KC_TILD,  KC_BSLS,  XXXXXXX,
        KC_DOT,   KC_4,    KC_5,    KC_6,     XXXXXXX,  KC_GRAVE,  KC_TRNS, XXXXXXX,  KC_MINUS, KC_PLUS,  KC_SLASH, KC_ASTR,
        KC_EQUAL, KC_7,    KC_8,    KC_9,     XXXXXXX,  KC_TRNS,   KC_TRNS, XXXXXXX,  XXXXXXX,  KC_LABK,  KC_RABK,  KC_CIRC,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        ),
    [_SYMS] = LAYOUT_planck_grid(
        KC_DTAB,  KC_TLFT, KC_NTAB, KC_TRIT, KC_TAB,    KC_TRNS,   KC_TRNS, XXXXXXX,  KC_EXLM,  KC_LCBR,  KC_RCBR,  KC_AT,
        KC_SRCH,  KC_SLFT, KC_LALT, KC_SRIT, XXXXXXX,   KC_GRAVE,  KC_TRNS, XXXXXXX,  KC_HASH,  KC_LPRN,  KC_RPRN,  KC_DLR,
        XXXXXXX,  KC_PUP,  XXXXXXX, KC_PDWN, XXXXXXX,   KC_TRNS,   KC_TRNS, XXXXXXX,  KC_PIPE,  KC_LBRC,  KC_RBRC,  KC_AMPR,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        ),
    [_MAC_SYMS] = LAYOUT_planck_grid(
        MC_DTAB,  MC_TLFT,  MC_NTAB,  MC_TRIT,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        MC_SRCH,  MC_SLFT,  KC_R_GUI, MC_SRIT,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  MC_PUP,   KC_TRNS,  MC_PDWN,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        ),
    [_FN] = LAYOUT_planck_grid(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, KC_VOLM,
        TOG_MAC, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, KC_PAUS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [_MOS] = LAYOUT_planck_grid(
        XXXXXXX, KC_RCLC, KC_MUP,  KC_LCLC, XXXXXXX, KC_TRNS, KC_TRNS, XXXXXXX, KC_LCLC, KC_UP,   KC_RCLC, XXXXXXX,
        XXXXXXX, KC_MLFT, KC_MDWN, KC_MRIT, XXXXXXX, KC_TRNS, KC_TRNS, KC_WLFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_WRIT,
        KC_PLFT, KC_PUP,  XXXXXXX, KC_PDWN, KC_PRIT, KC_TRNS, KC_TRNS, KC_HOME, KC_ENTER,XXXXXXX, XXXXXXX, KC_END,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [_MAC_MOS] = LAYOUT_planck_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  MC_WLFT,   KC_TRNS,  KC_TRNS,  KC_TRNS,  MC_WRIT,
        KC_TRNS,  MC_PUP,   KC_TRNS,  MC_PDWN,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        ),

    [_DEL] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_DWRD, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_ESC,  KC_ENTER,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_BWRD, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [_MAC_DEL] = LAYOUT_planck_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  MC_DWRD,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_ESC,   KC_ENTER, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  MC_BWRD,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        ),
};

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = {
        C_WHI, C_WHI, C_WHI, C_WHI, C_WHI, C_RED, C_RED, C_WHI, C_WHI, C_WHI, C_WHI, C_WHI,
        C_WHI, C_WHI, C_WHI, C_WHI, C_WHI, C_WHI, C_PUR, C_WHI, C_WHI, C_WHI, C_WHI, C_WHI,
        C_WHI, C_WHI, C_WHI, C_WHI, C_WHI, C_PUR, C_PUR, C_WHI, C_WHI, C_WHI, C_WHI, C_WHI,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
        },
    [_MAC_BASE] = {
        C_WHI, C_WHI, C_WHI, C_WHI, C_WHI, C_RED, C_RED, C_WHI, C_WHI, C_WHI, C_WHI, C_WHI,
        C_WHI, C_WHI, C_WHI, C_WHI, C_WHI, C_WHI, C_PUR, C_WHI, C_WHI, C_WHI, C_WHI, C_WHI,
        C_WHI, C_WHI, C_WHI, C_WHI, C_WHI, C_PUR, C_PUR, C_WHI, C_WHI, C_WHI, C_WHI, C_WHI,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
      },
    [_NUMS] ={
        C_WHI, C_WHI, C_WHI, C_WHI, C_OFF, C_RED, C_RED, C_OFF, C_BLU, C_BLU, C_WHI, C_OFF,
        C_WHI, C_WHI, C_WHI, C_WHI, C_OFF, C_WHI, C_PUR, C_OFF, C_RED, C_GRE, C_RED, C_GRE,
        C_BLU, C_WHI, C_WHI, C_WHI, C_OFF, C_PUR, C_PUR, C_OFF, C_OFF, C_WHI, C_WHI, C_GRE,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
      },
    [_SYMS] ={
        C_RED, C_ORA, C_GRE, C_ORA, C_WHI, C_RED, C_RED, C_OFF, C_RED, C_WHI, C_WHI, C_BLU,
        C_BLU, C_ORA, C_YEL, C_ORA, C_OFF, C_WHI, C_PUR, C_OFF, C_BLU, C_WHI, C_WHI, C_GRE,
        C_OFF, C_ORA, C_OFF, C_ORA, C_OFF, C_PUR, C_PUR, C_OFF, C_WHI, C_WHI, C_WHI, C_WHI,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
      },
    [_MAC_SYMS] = {
        C_RED, C_ORA, C_GRE, C_ORA, C_WHI, C_RED, C_RED, C_OFF, C_RED, C_WHI, C_WHI, C_BLU,
        C_BLU, C_ORA, C_YEL, C_ORA, C_OFF, C_WHI, C_PUR, C_OFF, C_BLU, C_WHI, C_WHI, C_GRE,
        C_OFF, C_ORA, C_OFF, C_ORA, C_OFF, C_PUR, C_PUR, C_OFF, C_WHI, C_WHI, C_WHI, C_WHI,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
      },
    [_FN] = {
        C_OFF, C_BLU, C_BLU, C_BLU, C_BLU, C_OFF, C_OFF, C_OFF, C_RED, C_GRE, C_OFF, C_OFF,
        C_OFF, C_BLU, C_BLU, C_BLU, C_BLU, C_OFF, C_OFF, C_OFF, C_RED, C_GRE, C_OFF, C_GRE,
        C_ORA, C_BLU, C_BLU, C_BLU, C_BLU, C_OFF, C_OFF, C_OFF, C_PUR, C_PUR, C_OFF, C_RED,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
      },
    [_MOS] = {
        C_OFF, C_PUR, C_ORA, C_PUR, C_OFF, C_RED, C_RED, C_RED, C_PUR, C_ORA, C_PUR, C_OFF,
        C_OFF, C_ORA, C_ORA, C_ORA, C_OFF, C_WHI, C_PUR, C_ORA, C_ORA, C_ORA, C_ORA, C_ORA,
        C_ORA, C_ORA, C_OFF, C_ORA, C_ORA, C_PUR, C_PUR, C_ORA, C_PUR, C_OFF, C_OFF, C_ORA,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
      },
    [_DEL] = {
        C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_RED, C_RED, C_OFF, C_OFF,
        C_OFF, C_OFF, C_PUR, C_PUR, C_OFF, C_OFF, C_OFF, C_OFF, C_RED, C_RED, C_OFF, C_OFF,
        C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
      },
    [_MAC_DEL] = {
        C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_RED, C_RED, C_OFF, C_OFF,
        C_OFF, C_OFF, C_PUR, C_PUR, C_OFF, C_OFF, C_OFF, C_OFF, C_RED, C_RED, C_OFF, C_OFF,
        C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF, C_OFF,
        C_YEL, C_YEL, C_YEL, C_YEL, C_YEL,        C_WHI, C_YEL, C_YEL, C_OFF, C_YEL, C_YEL,
      },
};

uint16_t layer_state_set_user(uint16_t state) {
  bool _delete_is_on = layer_state_cmp(state, _SYMS) && layer_state_cmp(state, _NUMS);
  if (_delete_is_on) {
    state |= (1 << _DEL);
  } else {
    state &= ~(1 << _DEL);
  }

  bool _mac_delete_is_on = layer_state_cmp(state, _MAC_SYMS) && layer_state_cmp(state, _NUMS);
  if (_mac_delete_is_on) {
    state |= (1 << _MAC_DEL);
  } else {
    state &= ~(1 << _MAC_DEL);
  }

  return state;
}

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

bool rgb_matrix_indicators_user(void) {
  int layer = -1;

  if (layer_state & (1UL << _MOS)) {
    layer = _MOS;
  }

  if (layer_state & (1UL << _SYMS)) {
    layer = _SYMS;
  }

  if (layer_state & (1UL << _DEL)) {
    layer = _DEL;
  }

  if (layer_state & (1UL << _MAC_DEL)) {
    layer = _MAC_DEL;
  }

  if (layer == -1) {
    layer = biton32(layer_state);
  }

  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
        .h = pgm_read_byte(&ledmap[layer][i][0]),
        .s = pgm_read_byte(&ledmap[layer][i][1]),
        .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color(i, 0, 0, 0);
    } else {
      RGB rgb = hsv_to_rgb(hsv);
      float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
  }

  return true;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t hold_timer;

    switch (keycode) {
        case H_ESC:
        case H_QUOTE:
        case H_TAB:
        case H_ENTER:
            if (record->event.pressed) {
                hold_timer = timer_read();
            } else {
                if (timer_elapsed(hold_timer) > HOLDING_TERM) {
                    switch (keycode) {
                        case H_ESC:    tap_code(KC_ESC);    break;
                        case H_QUOTE:  tap_code(KC_QUOTE);  break;
                        case H_TAB:    tap_code(KC_TAB);    break;
                        case H_ENTER:  tap_code(KC_ENTER);  break;
                    }
                }
            }
            return false;

        case M_MOUSE:
            if (record->event.pressed) {
                layer_on(_MOS);
                layer_on(_MAC_MOS);
            } else {
                layer_off(_MAC_MOS);
                layer_off(_MOS);
            }
            return false;

        case M_SYMS:
            if (record->event.pressed) {
                layer_on(_SYMS);
                layer_on(_MAC_SYMS);
            } else {
                layer_off(_MAC_SYMS);
                layer_off(_SYMS);
            }
            return false;
    }

    return true;
}