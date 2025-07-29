
#include QMK_KEYBOARD_H
#include "eeprom.h"

extern rgb_config_t rgb_matrix_config;

enum keycodes {
  DUMMY_INIT_VAL = SAFE_RANGE,
  m_mouse,
  m_syms,
  m_pnt,
  m_check,
  m_for,
  m_while,
  m_const,
  m_else,
  m_brew
};

enum layers {
  _base,
  _mac,
  _symbols,
  _mac_symbols,
  _math,
  _delete,
  _mac_delete,
  _mouse,
  _mouse_mac,
  _fn,
  _macro
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_base] = LAYOUT_planck_grid(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_DELETE, KC_BSPC, KC_Y, KC_U, KC_I,
        KC_O, KC_P, KC_A, KC_S, KC_D, KC_F, KC_G, KC_QUOTE, KC_TAB, KC_H, KC_J,
        KC_K, KC_L, KC_SCLN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESCAPE, KC_ENTER,
        KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_LEFT_CTRL, KC_LEFT_ALT,
        MO(_fn), KC_LSFT, MO(_symbols), KC_SPACE, KC_NO, MO(_math), MO(_mouse),
        MO(_macro), KC_LEFT_GUI, KC_LEFT_CTRL),
    [_mac] = LAYOUT_planck_grid(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_RIGHT_GUI,   KC_ROPT,  KC_TRANSPARENT, KC_TRANSPARENT, m_syms,
        KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, m_mouse, KC_TRANSPARENT,
        LGUI(KC_SPACE), KC_LEFT_CTRL),
    [_macro] = LAYOUT_planck_grid(
        KC_NO, m_while, m_else, KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_NO, KC_NO, m_check, KC_NO, m_pnt, KC_NO, KC_NO, KC_NO, m_for, KC_NO,
        KC_GRAVE, KC_TRANSPARENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, m_const, KC_NO, m_brew, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT),
    [_symbols] = LAYOUT_planck_grid(
        KC_NO, LCTL(LSFT(KC_TAB)), KC_NO, LCTL(KC_TAB), KC_TAB, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_NO, KC_EXLM, KC_LCBR, KC_RCBR, KC_AT, KC_NO,
        LALT(LCTL(KC_LEFT)), KC_LEFT_ALT, LALT(LCTL(KC_RIGHT)), KC_NO, KC_GRAVE,
        KC_TRANSPARENT, KC_NO, KC_HASH, KC_LPRN, KC_RPRN, KC_DLR, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_PIPE,
        KC_LBRC, KC_RBRC, KC_AMPR, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT),
    [_mac_symbols] = LAYOUT_planck_grid(
        KC_TRANSPARENT, LCTL(LSFT(KC_TAB)), KC_TRANSPARENT, LCTL(KC_TAB),
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, LCTL(KC_LEFT), KC_RIGHT_GUI, LCTL(KC_RIGHT),
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [_math] = LAYOUT_planck_grid(
        KC_0, KC_1, KC_2, KC_3, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
        KC_PERC, KC_TILD, KC_BSLS, KC_NO, KC_DOT, KC_4, KC_5, KC_6, KC_NO,
        KC_GRAVE, KC_TRANSPARENT, KC_NO, KC_MINUS, KC_PLUS, KC_SLASH, KC_ASTR,
        KC_EQUAL, KC_7, KC_8, KC_9, KC_NO, KC_CALCULATOR, KC_TRANSPARENT, KC_NO,
        KC_NO, KC_LABK, KC_RABK, KC_CIRC, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT),
    [_delete] = LAYOUT_planck_grid(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_DELETE),
        KC_DELETE, KC_NO, KC_NO, KC_TRANSPARENT, KC_NO, KC_BSPC, LCTL(KC_BSPC),
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT),
    [_mac_delete] = LAYOUT_planck_grid(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_DELETE), KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, LALT(KC_BSPC), KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [_mouse] = LAYOUT_planck_grid(
        KC_NO, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, LCTL(KC_V), KC_TRANSPARENT,
        KC_TRANSPARENT, KC_MS_ACCEL2, KC_MS_BTN1, KC_UP, KC_MS_BTN2, KC_NO,
        KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, LCTL(KC_C), KC_NO,
        KC_TRANSPARENT, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT,
        RCTL(KC_RIGHT), KC_MS_WH_LEFT, KC_MS_WH_UP, KC_NO, KC_MS_WH_DOWN,
        KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_ENTER,
        KC_NO, KC_NO, KC_END, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
    [_mouse_mac] = LAYOUT_planck_grid(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_V),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_LEFT),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_RIGHT), 
        KC_MS_WH_RIGHT, KC_MS_WH_DOWN,  KC_NO,          KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
        ),
    [_fn] = LAYOUT_planck_grid(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,
        KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_MPRV, KC_MNXT, KC_NO,
        KC_AUDIO_MUTE, TG(_mac), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_NO, KC_MEDIA_PLAY_PAUSE,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT)};

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_base] = {{0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
               {0, 0, 255},    {0, 255, 255},   {0, 255, 255},   {0, 0, 255},
               {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
               {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
               {0, 0, 255},    {0, 0, 255},     {180, 255, 255}, {0, 0, 255},
               {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
               {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
               {0, 0, 255},    {180, 255, 255}, {180, 255, 255}, {0, 0, 255},
               {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
               {43, 255, 255}, {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
               {43, 255, 255}, {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
               {43, 255, 255}, {43, 255, 255},  {43, 255, 255}},
    [_mac] = {{0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
              {0, 0, 255},    {0, 255, 255},   {0, 255, 255},   {0, 0, 255},
              {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
              {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
              {0, 0, 255},    {0, 0, 255},     {180, 255, 255}, {0, 0, 255},
              {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
              {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
              {0, 0, 255},    {180, 255, 255}, {180, 255, 255}, {0, 0, 255},
              {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
              {21, 255, 255}, {21, 255, 255},  {43, 255, 255},  {43, 255, 255},
              {43, 255, 255}, {0, 0, 255},     {43, 255, 255},  {21, 255, 255},
              {43, 255, 255}, {43, 255, 255},  {43, 255, 255}},
    [_macro] =
        {{0, 0, 0},       {127, 255, 255}, {127, 255, 255}, {0, 0, 0},
         {0, 0, 0},       {0, 255, 255},   {0, 255, 255},   {0, 0, 0},
         {0, 0, 0},       {127, 255, 255}, {0, 0, 0},       {127, 255, 255},
         {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {127, 255, 255},
         {0, 0, 0},       {0, 0, 255},     {180, 255, 255}, {0, 0, 0},
         {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
         {0, 0, 0},       {0, 0, 0},       {127, 255, 255}, {0, 0, 0},
         {127, 255, 255}, {180, 255, 255}, {180, 255, 255}, {0, 0, 0},
         {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255}},
    [_symbols] =
        {{0, 0, 0},       {85, 255, 255},  {0, 0, 0},       {85, 255, 255},
         {180, 255, 255}, {0, 255, 255},   {0, 255, 255},   {0, 0, 0},
         {210, 255, 255}, {0, 0, 255},     {0, 0, 255},     {170, 255, 255},
         {0, 0, 0},       {85, 255, 255},  {43, 255, 255},  {85, 255, 255},
         {0, 0, 0},       {0, 0, 255},     {180, 255, 255}, {0, 0, 0},
         {170, 255, 255}, {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
         {0, 0, 0},       {180, 255, 255}, {180, 255, 255}, {0, 0, 0},
         {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255}},
    [_mac_symbols] =
        {{0, 0, 255},    {85, 255, 255},  {0, 0, 255},     {85, 255, 255},
         {0, 0, 255},    {0, 255, 255},   {0, 255, 255},   {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 255},    {85, 255, 255},  {21, 255, 255},  {85, 255, 255},
         {0, 0, 255},    {0, 0, 255},     {180, 255, 255}, {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 255},    {180, 255, 255}, {180, 255, 255}, {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {43, 255, 255}, {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
         {43, 255, 255}, {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
         {43, 255, 255}, {43, 255, 255},  {43, 255, 255}},
    [_math] =
        {{0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 0},       {0, 255, 255},   {0, 255, 255},   {0, 0, 0},
         {170, 255, 255}, {0, 0, 255},     {0, 0, 255},     {0, 0, 0},
         {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 0},       {0, 0, 255},     {180, 255, 255}, {0, 0, 0},
         {0, 0, 255},     {85, 255, 255},  {0, 0, 255},     {85, 255, 255},
         {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 0},       {170, 255, 255}, {180, 255, 255}, {0, 0, 0},
         {0, 0, 0},       {0, 0, 255},     {0, 0, 255},     {85, 255, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255}},
    [_delete] =
        {{0, 0, 0},      {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
         {0, 0, 0},      {0, 255, 255},   {0, 255, 255},   {0, 0, 0},
         {0, 0, 0},      {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
         {0, 0, 0},      {0, 0, 0},       {0, 255, 255},   {0, 255, 255},
         {0, 0, 0},      {0, 0, 0},       {180, 255, 255}, {0, 0, 0},
         {0, 255, 255},  {0, 255, 255},   {0, 0, 0},       {0, 0, 0},
         {0, 0, 0},      {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
         {0, 0, 0},      {180, 255, 255}, {180, 255, 255}, {0, 0, 0},
         {0, 0, 0},      {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
         {43, 255, 255}, {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
         {43, 255, 255}, {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
         {43, 255, 255}, {43, 255, 255},  {43, 255, 255}},
    [_mac_delete] =
        {{0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 255},    {0, 255, 255},   {0, 255, 255},   {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {0, 255, 255},   {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {180, 255, 255}, {0, 0, 255},
         {0, 0, 255},    {0, 255, 255},   {0, 0, 255},     {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 255},    {180, 255, 255}, {180, 255, 255}, {0, 0, 255},
         {0, 0, 255},    {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {43, 255, 255}, {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
         {43, 255, 255}, {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
         {43, 255, 255}, {43, 255, 255},  {43, 255, 255}},
    [_mouse] =
        {{0, 0, 0},       {21, 255, 255},  {210, 255, 255}, {21, 255, 255},
         {21, 255, 255},  {0, 255, 255},   {0, 255, 255},   {43, 255, 255},
         {21, 255, 255},  {210, 255, 255}, {21, 255, 255},  {0, 0, 0},
         {0, 0, 0},       {210, 255, 255}, {210, 255, 255}, {210, 255, 255},
         {21, 255, 255},  {0, 0, 0},       {180, 255, 255}, {210, 255, 255},
         {210, 255, 255}, {210, 255, 255}, {210, 255, 255}, {210, 255, 255},
         {210, 255, 255}, {210, 255, 255}, {0, 0, 0},       {210, 255, 255},
         {210, 255, 255}, {180, 255, 255}, {180, 255, 255}, {210, 255, 255},
         {180, 255, 255}, {0, 0, 0},       {0, 0, 0},       {210, 255, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255}},
    [_mouse_mac] =
        {{0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {21, 255, 255},  {0, 255, 255},   {0, 255, 255},   {0, 0, 255},
         {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {21, 255, 255},  {0, 0, 255},     {180, 255, 255}, {210, 255, 255},
         {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {210, 255, 255},
         {210, 255, 255}, {210, 255, 255}, {0, 0, 0},       {210, 255, 255},
         {210, 255, 255}, {180, 255, 255}, {180, 255, 255}, {0, 0, 255},
         {0, 0, 255},     {0, 0, 255},     {0, 0, 255},     {0, 0, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
         {43, 255, 255},  {43, 255, 255},  {43, 255, 255}},
    [_fn] = {{170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255},
             {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255},
             {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255},
             {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
             {0, 0, 0},       {0, 0, 0},       {0, 255, 255},   {85, 255, 255},
             {210, 255, 255}, {210, 255, 255}, {0, 0, 0},       {0, 255, 255},
             {21, 255, 255},  {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
             {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},
             {0, 255, 255},   {85, 255, 255},  {0, 0, 0},       {0, 255, 255},
             {43, 255, 255},  {43, 255, 255},  {43, 255, 255},  {43, 255, 255},
             {43, 255, 255},  {0, 0, 255},     {43, 255, 255},  {43, 255, 255},
             {43, 255, 255},  {43, 255, 255},  {43, 255, 255}}};

uint16_t layer_state_set_user(uint16_t state) {
  bool _delete_is_on =
      layer_state_cmp(state, _symbols) && layer_state_cmp(state, _math);
  if (_delete_is_on) {
    state |= (1 << _delete);
  } else {
    state &= ~(1 << _delete);
  }

  bool _mac_delete_is_on =
      layer_state_cmp(state, _mac_symbols) && layer_state_cmp(state, _math);
  if (_mac_delete_is_on) {
    state |= (1 << _mac_delete);
  } else {
    state &= ~(1 << _mac_delete);
  }

  return state;
}

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

bool rgb_matrix_indicators_user(void) {
  int layer = -1;

  if (layer_state & (1UL << _mouse)) {
    layer = _mouse;
  }

  if (layer_state & (1UL << _symbols)) {
    layer = _symbols;
  }

  if (layer_state & (1UL << _delete)) {
    layer = _delete;
  }

  if (layer_state & (1UL << _mac_delete)) {
    layer = _delete;
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
  switch (keycode) {
  case DUMMY_INIT_VAL:
    return true;

  case m_mouse:
    if (record->event.pressed) {
      layer_on(_mouse);
      layer_on(_mouse_mac);
    } else {
      layer_off(_mouse_mac);
      layer_off(_mouse);
    }
    return false;
    break;

  case m_syms:
    if (record->event.pressed) {
      layer_on(_symbols);
      layer_on(_mac_symbols);
    } else {
      layer_off(_mac_symbols);
      layer_off(_symbols);
    }
    return false;
    break;

  case m_pnt:
    if (record->event.pressed) {
      SEND_STRING("System.out.println(");
    }
    break;

  case m_check:
    if (record->event.pressed) {
      SEND_STRING("- [ ]");
    }
    break;

  case m_for:
    if (record->event.pressed) {
      SEND_STRING("for");
    }
    break;

  case m_while:
    if (record->event.pressed) {
      SEND_STRING("while");
    }
    break;

  case m_const:
    if (record->event.pressed) {
      SEND_STRING("const");
    }
    break;

  case m_else:
    if (record->event.pressed) {
      SEND_STRING("else");
    }
    break;

  case m_brew:
    if (record->event.pressed) {
      SEND_STRING("brew");
    }
    break;
  }
  return true;
}
