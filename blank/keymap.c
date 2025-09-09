#include QMK_KEYBOARD_H
#include "pointing_device.h"
#include <math.h>

#define POINTING_ACCEL_SLOPE 0.01f
#define KC_BRIU KC_BRIGHTNESS_UP
#define KC_BRID KC_BRIGHTNESS_DOWN
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN
#define KC_VOLM KC_AUDIO_MUTE
#define KC_PAUS KC_MEDIA_PLAY_PAUSE
#define KC_TRIT LCTL(KC_TAB)
#define MC_TRIT LGUI(LALT(KC_LEFT)) 
#define KC_TLFT LCTL(LSFT(KC_TAB))
#define MC_TLFT LGUI(LALT(KC_RIGHT))
#define MC_SLFT LCTL(KC_LEFT)
#define KC_SRIT LALT(LCTL(KC_RIGHT))
#define MC_SRIT LCTL(KC_RIGHT)
#define KC_LCLC KC_MS_BTN1
#define KC_RCLC KC_MS_BTN2
#define KC_WLFT LCTL(KC_LEFT)
#define KC_WRIT LCTL(KC_RIGHT)
#define MC_WLFT LALT(KC_LEFT)
#define MC_WRIT LALT(KC_RIGHT)
#define KC_MLFT KC_MS_LEFT
#define KC_MRIT KC_MS_RIGHT
#define KC_MUP KC_MS_UP
#define KC_MDWN KC_MS_DOWN
#define KC_PLFT KC_MS_WH_LEFT
#define KC_PRIT KC_MS_WH_RIGHT
#define KC_PUP KC_MS_WH_UP
#define KC_PDWN KC_MS_WH_DOWN
#define MC_PUP KC_MS_WH_DOWN
#define MC_PDWN KC_MS_WH_UP
#define KC_BWRD LCTL(KC_BSPC)
#define KC_DWRD LCTL(KC_DEL)
#define MC_BWRD LALT(KC_BSPC)
#define MC_DWRD LALT(KC_DELETE)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(KC_Y)
#define KC_R_GUI KC_RIGHT_GUI
#define TOG_MAC TG(_MAC_BASE)
#define MC_MENU LGUI(KC_SPC)
#define MC_NTAB LGUI(KC_T)
#define MC_DTAB LGUI(KC_W)
#define MC_SRCH LGUI(KC_L)
#define KC_NTAB LCTL(KC_T)
#define KC_DTAB LCTL(KC_W)
#define KC_SRCH LCTL(KC_L)
#define RMACR_1 DYN_REC_START1
#define PMACR_1 DYN_MACRO_PLAY1
#define MACRO_S DYN_REC_STOP

#define _BASE 0
#define _MAC_BASE 1
#define _NUMS 2
#define _SYMS 3
#define _MAC_SYMS 4
#define _FN 5
#define _MOS 6
#define _MAC_MOS 7
#define _DEL 8
#define _MAC_DEL 9

#define HOLDING_TERM 65

enum custom_keycodes {
    DUMMY_INIT_VAL = SAFE_RANGE,
    SCROLL_DOWN_FAST,
    H_ESC,
    H_QUOTE,
    H_TAB,
    H_ENTER,
    M_MOUSE,
    M_SYMS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,                     XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_DEL,                      KC_BSPC, KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      H_QUOTE,                     H_TAB,   KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      H_ESC,                       H_ENTER, KC_N,      KC_M,    KC_COMMA,KC_DOT,  KC_SLASH,
        KC_LCTL, KC_LALT, MO(_FN), KC_LSFT, MO(_SYMS), KC_SPC,   KC_LCLC, XXXXXXX,  KC_SPC,  MO(_NUMS), MO(_MOS),XXXXXXX, KC_RCTL, KC_LGUI
        ),

    [_MAC_BASE] = LAYOUT(
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,                     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_R_GUI, KC_ROPT,  KC_TRNS,  KC_TRNS,  M_SYMS,    KC_TRNS,  KC_TRNS,  XXXXXXX, KC_TRNS,  KC_TRNS,   M_MOUSE,  KC_TRNS,  KC_TRNS,  MC_MENU
        ),

    [_NUMS] = LAYOUT(
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_0,     KC_1,    KC_2,    KC_3,     XXXXXXX,  KC_TRNS,                   KC_TRNS, XXXXXXX, KC_PERC, KC_TILD, KC_BSLS, XXXXXXX,
        KC_DOT,   KC_4,    KC_5,    KC_6,     XXXXXXX,  KC_GRAVE,                  KC_TRNS, XXXXXXX, KC_MINUS,KC_PLUS, KC_SLASH,KC_ASTR,
        KC_EQUAL, KC_7,    KC_8,    KC_9,     XXXXXXX,  KC_TRNS,                   KC_TRNS, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, KC_CIRC,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [_SYMS] = LAYOUT(
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_DTAB,  KC_TLFT, KC_NTAB, KC_TRIT, KC_TAB,  KC_TRNS,                   KC_TRNS, XXXXXXX, KC_EXLM, KC_LCBR, KC_RCBR, KC_AT,
        KC_SRCH,  KC_SLFT, KC_LALT, KC_SRIT, XXXXXXX, KC_GRAVE,                  KC_TRNS, XXXXXXX, KC_HASH, KC_LPRN, KC_RPRN, KC_DLR,
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,                   KC_TRNS, XXXXXXX, KC_PIPE, KC_LBRC, KC_RBRC, KC_AMPR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS               
        ),

    [_MAC_SYMS] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,                     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        MC_DTAB,  MC_TLFT,  MC_NTAB,  MC_TRIT,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        MC_SRCH,  MC_SLFT,  KC_R_GUI, MC_SRIT,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  XXXXXXX, KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        ),

    [_FN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  XXXXXXX,                   XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX,                   XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, KC_VOLM,
        TOG_MAC, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX,                   XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, KC_PAUS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [_MOS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_RCLC, KC_MUP,  KC_LCLC, XXXXXXX, KC_TRNS,                   KC_TRNS, XXXXXXX, KC_LCLC, KC_UP,   KC_RCLC, XXXXXXX,
        XXXXXXX, KC_MLFT, KC_MDWN, KC_MRIT, XXXXXXX, KC_TRNS,                   KC_TRNS, KC_WLFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_WRIT,
        KC_PLFT, KC_PUP,  XXXXXXX, KC_PDWN, KC_PRIT, KC_TRNS,                   KC_TRNS, KC_HOME, KC_ENTER,XXXXXXX, XXXXXXX, KC_END,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [_MAC_MOS] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,                     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  MC_WLFT,   KC_TRNS,  KC_TRNS,  KC_TRNS,  MC_WRIT,
        KC_TRNS,  MC_PUP,   KC_TRNS,  MC_PDWN,   KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  XXXXXXX, KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        ),

    [_DEL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RMACR_1, MACRO_S, PMACR_1, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_DEL,  KC_DWRD, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_BSPC, KC_BWRD, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
    
    [_MAC_DEL] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,                     XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  MC_DWRD,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  MC_BWRD,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_ESC,   KC_ENTER, KC_TRNS,   KC_TRNS,                     KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  XXXXXXX, KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
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

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    float magnitude = sqrtf(mouse_report.x * mouse_report.x + mouse_report.y * mouse_report.y);

    float accel = 1.0f + POINTING_ACCEL_SLOPE * magnitude;

    mouse_report.x = (int16_t)(mouse_report.x * accel);
    mouse_report.y = (int16_t)(mouse_report.y * accel);
    return mouse_report;
}

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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_PDWN, KC_PUP),
            //Encoder 2
            ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
            },
    [_MAC_BASE] =   {
            //Encoder 1
            ENCODER_CCW_CW(MC_PDWN, MC_PUP),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [_NUMS] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [_SYMS] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [_MAC_SYMS] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [_FN] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [_MOS] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [_MAC_MOS] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [_DEL] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [_MAC_DEL] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
};
#endif
