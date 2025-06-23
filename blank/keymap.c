#include QMK_KEYBOARD_H

#define KC_BRIU KC_BRIGHTNESS_UP
#define KC_BRID KC_BRIGHTNESS_DOWN
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN
#define KC_VOLM KC_AUDIO_MUTE
#define KC_PAUS KC_MEDIA_PLAY_PAUSE
#define KC_TRIT LCTL(KC_TAB)
#define KC_TLFT LCTL(LSFT(KC_TAB))
#define KC_WLFT LALT(LCTL(KC_LEFT))
#define KC_WRIT LALT(LCTL(KC_RIGHT))
#define KC_LCLC KC_MS_BTN1
#define KC_RCLC KC_MS_BTN2
#define KC_WLFT LCTL(KC_LEFT)
#define KC_WRIT LCTL(KC_RIGHT)
#define KC_MLFT KC_MS_LEFT
#define KC_MRIT KC_MS_RIGHT
#define KC_MUP KC_MS_UP
#define KC_MDWN KC_MS_DOWN
#define KC_PLFT KC_MS_WH_LEFT
#define KC_PRIT KC_MS_WH_RIGHT
#define KC_PUP KC_MS_WH_UP
#define KC_PDWN KC_MS_WH_DOWN
#define KC_BWRD LCTL(KC_BSPC)
#define KC_DWRD LCTL(KC_DEL)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,                    KC_BSPC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_QUOTE,                  KC_TAB,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,                    KC_ENTER, KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLASH,
        KC_LCTL, KC_LALT, MO(3),   KC_LSFT, MO(2),   XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,   MO(1),   MO(4),   KC_LGUI, XXXXXXX, KC_RALT
        ),

    //Numbers
    [1] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_0,    KC_1,    KC_2,    KC_3,     XXXXXXX,  KC_TRNS,                   KC_TRNS, XXXXXXX, KC_PERC, KC_TILD, KC_BSLS, XXXXXXX,
        KC_DOT,  KC_4,    KC_5,    KC_6,     XXXXXXX,  KC_GRAVE,                  KC_TRNS, XXXXXXX, KC_MINUS,KC_PLUS, KC_SLASH,KC_ASTR,
        KC_EQUAL,KC_7,    KC_8,    KC_9,     XXXXXXX,  KC_TRNS,                   KC_TRNS, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, KC_CIRC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    //symbols
    [2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_TLFT, XXXXXXX, KC_TRIT, KC_TAB,  KC_TRNS,                   KC_TRNS, XXXXXXX, KC_EXLM, KC_LCBR, KC_RCBR, KC_AT,
        XXXXXXX, KC_WLFT, KC_LALT, KC_WRIT, XXXXXXX, KC_GRAVE,                  KC_TRNS, XXXXXXX, KC_HASH, KC_LPRN, KC_RPRN, KC_DLR,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,                   KC_TRNS, XXXXXXX, KC_PIPE, KC_LBRC, KC_RBRC, KC_AMPR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS               ),

    //FN layer
    [3] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_TRNS,                   KC_TRNS, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,
        XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_TRNS,                   KC_TRNS, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_VOLM,
        XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_TRNS,                   KC_TRNS, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_PAUS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    //mouse
    [4] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_RCLC, KC_MUP,  KC_LCLC, XXXXXXX, KC_TRNS,                   KC_TRNS, XXXXXXX, KC_LCLC, KC_UP,   KC_RCLC, XXXXXXX,
        XXXXXXX, KC_MLFT, KC_MDWN, KC_MRIT, XXXXXXX, KC_TRNS,                   KC_TRNS, KC_WLFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_WRIT,
        KC_PLFT, KC_PUP,  XXXXXXX, KC_PDWN, KC_PRIT, KC_TRNS,                   KC_TRNS, KC_HOME, KC_ENTER,XXXXXXX, XXXXXXX, KC_END,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    [5] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,                   KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_DWRD, KC_DEL,  XXXXXXX, KC_TRNS,                   KC_TRNS, XXXXXXX, KC_BSPC, KC_BWRD, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,                   KC_TRNS, XXXXXXX, KC_ENTER,XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, 1, 2, 5);
    return state;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_PDWN, KC_PUP),
            //Encoder 2
            ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
            },
    [1] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_UNDO, KC_REDO),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [2] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [3] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [4] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [5] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
};
#endif
