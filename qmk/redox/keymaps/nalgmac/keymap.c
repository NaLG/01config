#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _NAVA 1
#define _SYMB 2
#define _FUNC 3
#define _CAPS 4

enum custom_keycodes {
  BASE = SAFE_RANGE,
  NAVA,
  // NAVB,
  SYMB,
  FUNC,
  CAPS,
};

// mac bits
// KC_MISSION_CONTROL   KC_MCTL  Open Mission Control
// KC_LAUNCHPAD   KC_LPAD  Open Launchpad

// Plus other weird things, 
//   Symbiosis with BetterTouchTool,
//   the F13+ keys are BTT'd to do special things

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_8    ,KC_9    ,KC_0 ,RSFT(KC_MINS),KC_MINS,KC_EQL ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_6    ,                          KC_7    ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤//LT(_FUNC,KC_ENT)       ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 LT(_CAPS,KC_CAPS) ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,LT(_FUNC,KC_ENT),            KC_MENU ,KC_H    ,KC_BSPC ,KC_ENT  ,KC_L    ,KC_K    ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 RSFT_T(KC_F17),KC_Z  ,KC_X    ,KC_C    ,KC_V    ,KC_B ,LCTL(KC_LEFT),LCTL(KC_RGHT), KC_LPAD ,KC_F13 , KC_N    ,KC_M    ,KC_COMM ,KC_DOT,  KC_J, RSFT_T(KC_SLSH) ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
 KC_LGUI,KC_LALT,KC_LCTL,LCTL(LGUI(KC_SPC)),LCTL_T(KC_SPC),MO(_SYMB),LSFT_T(KC_F16),MO(_NAVA),KC_SPC  ,   TO(_NAVA),   MO(_FUNC),TO(_NAVA),KC_UP  ,RCTL_T(KC_MPLY)
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAVA] = LAYOUT(                                                                                                 //RALT(KC_RBRC)
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
 KC_TRNS,LCTL(LGUI(KC_F)),KC_F2, KC_F3  , KC_F4  , KC_F5  ,                               RGUI(KC_RBRC),RALT(KC_LBRC),RALT(KC_M),KC_F12,LGUI(KC_MINS),LGUI(KC_EQL) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐ //KC_LALT space         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS,KC_TRNS,LGUI(KC_W),LAG(KC_SPC),RCS(KC_TAB),LCTL(KC_TAB),KC_LALT,            RGUI(KC_LBRC),RSFT_T(KC_Y),RGUI(KC_LEFT),KC_UP,RGUI(KC_RGHT),KC_PGUP,KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS,LGUI(KC_A),LGUI(KC_S),LGUI_T(KC_D),LSFT(KC_TAB),KC_TAB,KC_GRV ,                      KC_APP  ,RGUI_T(KC_H),KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_ENT  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 KC_TRNS,LGUI(KC_Z),LGUI(KC_X),LGUI(KC_C),LGUI(KC_V),LGUI(KC_SLSH),KC_TRNS,KC_TRNS,  KC_TRNS ,KC_TRNS ,RALT_T(KC_N),KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,KC_WH_L ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,     KC_TRNS ,    KC_TRNS ,KC_TRNS ,        TO(_BASE),KC_BTN1,    KC_MS_L ,     KC_MS_D ,KC_MS_R ,KC_WH_D ,KC_WH_R 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD ,KC_GRV  ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_CIRC ,                                            KC_ASTR ,KC_CIRC ,KC_AMPR ,KC_UNDS ,KC_MINS ,KC_PLUS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_QUOT ,KC_LBRC ,KC_RBRC ,KC_DQUO ,KC_SCLN ,KC_CIRC ,                          KC_AMPR ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_ASTR ,KC_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_EXLM ,KC_LPRN ,KC_RPRN ,KC_QUOT ,KC_COLN ,KC_TRNS ,                          KC_TRNS ,KC_BSPC ,KC_P4   ,KC_P5   ,KC_P6   ,KC_ASTR ,KC_ENT  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_QUES ,KC_LCBR ,KC_RCBR ,KC_BSLS ,KC_SLSH ,KC_TRNS ,KC_TRNS ,        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_P1   ,KC_P2   ,KC_P3   ,KC_COMM ,RSFT_T(KC_SLSH) ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,     KC_TRNS ,    KC_TRNS ,KC_TRNS ,       TO(_BASE),KC_SPC  ,    KC_0    ,     KC_P0   ,KC_DOT  ,KC_PENT ,KC_RCTL 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                                            KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,QK_BOOT  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_NO    ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_F11  ,KC_F12  ,KC_F13  ,KC_F14  ,KC_F15  ,KC_MPRV  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,KC_F16  ,KC_F17  ,KC_F18  ,KC_F19  ,KC_F20  ,KC_MNXT  ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,     KC_NO   ,    KC_NO   ,KC_NO   ,       TO(_BASE),KC_NO   ,    KC_MUTE ,     KC_NO   ,KC_VOLD ,KC_VOLU ,KC_MPLY  
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_CAPS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
  QK_BOOT,LCTL(KC_1),LCTL(KC_2),LCTL(KC_3),LCTL(KC_4),LCTL(KC_5),                                   LCTL(KC_8),LCTL(KC_9),KC_NO  ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  KC_NO,LCTL(LALT(KC_LEFT)),LCTL(LALT(KC_RGHT)),KC_NO,KC_NO,KC_NO,LCTL(KC_6),               LCTL(KC_7),KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  KC_NO,LCTL(KC_LEFT),LCTL(KC_RGHT),KC_NO,KC_NO  ,KC_NO   ,KC_NO   ,                          KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,        KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,     KC_NO   ,    KC_NO   ,KC_NO   ,       TO(_BASE),KC_NO   ,    KC_NO   ,     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO    
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
