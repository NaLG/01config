// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
// #define _DEFAULT 0
// #define _NAV 1
// #define _RESET 2

// #define _BASE 0
// #define _NAV 1
// #define _SYM 2
// #define _FN 3
// #define _DT 4

// enum custom_keycodes {
//   BASE = SAFE_RANGE,
//   NAV,
//   SYM,
//   FN,
//   DT,
// };

// // Shortcut to make keymap more readable
// // #define LCA(X)        LCTL(LALT(X)) // defined already
// #define LSCA(X)  LSFT(LCTL(LALT(X)))
// #define KC_ALAS LALT_T(KC_PAST)


#define _BASE 0 // mac layers
#define _MNAV 1 // mac layers
#define _MSYM 2 // mac layers
#define _MCAPS 3 // mac layers
#define _WLBASE 4 // windows and linux layers
#define _WLNAV  5 // windows and linux layers
#define _WLSYM 6 // windows and linux layers
// #define _WLFUNC 3 // Func layer shared
#define _WLCAPS 7 // windows and linux layers
#define _FUNC 8 // mac layers

enum custom_keycodes {
  BASE = SAFE_RANGE,
  MNAV,
  MSYM,
  MCAPS,
  WLBASE,
  WLNAVA,
  WLSYMB,
  // WLFUNC,
  WLCAPS,
  FUNC,
};

#define LSCA(X)  LSFT(LCTL(LALT(X)))
#define KC_ALAS LALT_T(KC_PAST)

// mac bits
#define MMOJI LCTL(LGUI(KC_SPC))  // can't pass mods through _T(), so BTT it to F18
// KC_MISSION_CONTROL   KC_MCTL  Open Mission Control
// KC_LAUNCHPAD   KC_LPAD  Open Launchpad

// Plus other weird things, 
//   Symbiosis with BetterTouchTool,
//   the F13+ keys are BTT'd to do special things
//   the F13+ keys are BTT'd to do special things
//   the F13+ keys are BTT'd to do special things


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  ////////////////////////////////////
  ///////////  Mac Layers  /////////// - Get BACK here from win/nix with key 2xleft of N
  ////////////////////////////////////

  [_BASE] = LAYOUT( /* qwerty mod nalg */
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                               ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
     KC_ESC     ,KC_1       ,KC_2       ,KC_3       ,KC_4       ,KC_5                                       , KC_8      ,KC_9       ,KC_0       ,RSFT(KC_MINS),KC_MINS  ,KC_EQL ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_TAB     ,KC_Q       ,KC_W       ,KC_E       ,KC_R       ,KC_T                                       , KC_Y      ,KC_U       ,KC_I       ,KC_O       , KC_P      ,KC_BSLS ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤              
 LT(_MCAPS,KC_CAPS),KC_A     ,KC_S      ,KC_D       ,KC_F       ,KC_G                                       , KC_H      ,KC_BSPC    ,KC_ENT     ,KC_L       , KC_K      ,KC_QUOT ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
 RSFT_T(KC_F17) ,KC_Z       ,KC_X       ,KC_C       ,KC_V       ,KC_B                                       , KC_N      ,KC_M       ,KC_COMM    ,KC_DOT     , KC_J , RSFT_T(KC_SLSH),
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
 LGUI_T(KC_F19) ,KC_LALT    ,KC_LCTL    ,MMOJI      ,KC_SPC     ,MO(_MSYM),   LSFT_T(KC_F16),  MO(_MNAV)    , KC_SPC    ,TO(_MNAV)  , MO(_FUNC) ,TO(_MNAV)  ,KC_UP      , RCTL_T(KC_MPLY)
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘  └───────────┘ └───────────┘  └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘
  ),                                              


  [_MNAV] = LAYOUT(                                                                                         
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                               ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
     KC_TRNS ,LCTL(LGUI(KC_F)),KC_F2    ,KC_F3      ,KC_F4      ,KC_F5                                     ,RGUI(KC_LBRC),RGUI(KC_RBRC),RALT(KC_M),KC_F12,LGUI(KC_MINS),LGUI(KC_EQL),
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_TRNS    ,KC_TRNS    ,LGUI(KC_W) ,LAG(KC_SPC),RCS(KC_TAB),LCTL(KC_TAB)                              ,RSFT_T(KC_Y),KC_F14     ,KC_UP      ,KC_F15     ,KC_PGUP    ,KC_TRNS ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤              
LT(_MCAPS,KC_CAPS),LGUI(KC_A),LGUI(KC_S),LGUI_T(KC_D),LSFT(KC_TAB),KC_TAB                                  ,RGUI_T(KC_H),KC_LEFT    ,KC_DOWN    ,KC_RGHT    ,KC_PGDN    ,KC_ENT  ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_TRNS    ,LGUI(KC_Z) ,LGUI(KC_X) ,LGUI(KC_C) ,LGUI(KC_V) ,LGUI(KC_SLSH)                             ,RALT_T(KC_N),KC_M       ,KC_MS_U    ,KC_BTN2    ,KC_WH_U    ,KC_WH_L ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,    KC_TRNS ,    TO(_BASE)    ,KC_BTN1     ,KC_MS_L    ,KC_MS_D    ,KC_MS_R    ,KC_WH_D    ,KC_WH_R 
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘  └───────────┘ └───────────┘  └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘
  ),   



  [_MSYM] = LAYOUT(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                               ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
     KC_TILD    ,KC_GRV     ,KC_AT      ,KC_HASH    ,KC_DLR     ,KC_CIRC                                   ,KC_ASTR     ,KC_CIRC    ,KC_AMPR    ,KC_UNDS    ,KC_MINS    ,KC_PLUS ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_TRNS    ,KC_QUOT    ,KC_LBRC    ,KC_RBRC    ,KC_DQUO    ,KC_SCLN                                   ,KC_PSLS     ,KC_7       ,KC_8       ,KC_9       ,KC_ASTR    ,KC_PIPE ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤              
     KC_TRNS    ,KC_EXLM    ,KC_LPRN    ,KC_RPRN    ,KC_QUOT    ,KC_COLN                                   ,KC_BSPC     ,KC_4       ,KC_5       ,KC_6       ,KC_ASTR    ,KC_ENT  ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_TRNS    ,KC_QUES    ,KC_LCBR    ,KC_RCBR    ,KC_BSLS    ,KC_SLSH                                   ,KC_TRNS     ,KC_1       ,KC_2       ,KC_3       ,KC_COMM  ,RSFT_T(KC_SLSH) ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,KC_TRNS    ,    KC_TRNS ,    TO(_BASE)    ,KC_SPC      ,KC_0       ,KC_0       ,KC_DOT     ,KC_PENT    ,KC_RCTL 
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘  └───────────┘ └───────────┘  └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘
  ),   



  [_MCAPS] = LAYOUT(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                               ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
     QK_BOOT    ,LCTL(KC_1) ,LCTL(KC_2) ,LCTL(KC_3) ,LCTL(KC_4) ,LCTL(KC_5)                                 ,LCTL(KC_8) ,LCTL(KC_9) ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_NO ,LCTL(LALT(KC_LEFT)),LCTL(LALT(KC_RGHT)) ,KC_NO,KC_NO,KC_NO                                      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤              
     KC_NO ,LCTL(KC_LEFT),LCTL(KC_RGHT) ,KC_NO      ,KC_NO      ,KC_NO                                      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO                                      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,    KC_NO   ,    TO(_BASE)     ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO    
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘  └───────────┘ └───────────┘  └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘
  ),   






  //////////////////////////////////////////////////
  ///////////  Windows and Linux Layers  /////////// - Get here from mac with _FUNC layer, 'w' key
  //////////////////////////////////////////////////



  [_WLBASE] = LAYOUT( /* qwerty mod nalg */
  //┌────────────────┬─────────────────┬─────────────┬─────────────┬────────────────────┬──────────────┐                               ┌────────────────┬───────────────┬──────────────┬─────────────┬───────────────┬──────────────────┐
    KC_ESC           , KC_1            , KC_2        , KC_3        , KC_4               , KC_5                                         , KC_8           , KC_9          , KC_0         , KC_UNDS     , KC_MINS       , KC_EQL           ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
    LGUI_T(KC_TAB)   , KC_Q            , KC_W        , KC_E        , KC_R               , KC_T                                         , KC_Y           , KC_U          , KC_I         , KC_O        , KC_P          , KC_BSLS          ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤              
  LT(_WLCAPS,KC_CAPS), KC_A            , KC_S        , KC_D        , KC_F               , KC_G                                         , KC_H           , KC_BSPC       , KC_ENT       , KC_L        , KC_K          , KC_QUOT          ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
    RSFT_T(KC_LGUI)  , KC_Z            , KC_X        , KC_C        , KC_V               , KC_B                                         , KC_N           , KC_M          , KC_COMM      , KC_DOT      , KC_SLSH       , RSFT_T(KC_SLSH)  ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
    RCTL_T(KC_MPLY)  , KC_LGUI         , KC_LALT     ,LGUI(KC_DOT) , KC_SPC             , MO(_WLSYM)   , LSFT_T(KC_DEL),  MO(_WLNAV)   , KC_SPC         , TO(_WLNAV)    , MO(_FUNC)    , TO(_WLNAV)  , KC_APP        , RCTL_T(KC_MPLY)   
  //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
  ),                                            

  [_WLNAV] = LAYOUT(
  //┌────────────────┬─────────────────┬─────────────┬─────────────┬────────────────────┬──────────────┐                               ┌────────────────┬───────────────┬──────────────┬─────────────┬───────────────┬──────────────────┐
    LALT_T(KC_ESC)   , KC_F11          , KC_F2       , KC_F3       , KC_F4              , KC_F5                                        , LCTL(KC_LBRC)  , LCTL(KC_RBRC) , RCTL(KC_M)   , KC_F12      , RCTL(KC_MINS) , RCTL(KC_EQL)     ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
    KC_TRNS          , LCTL(KC_M)      , LCTL(KC_W)  , LGUI(KC_E)  , LCTL(LSFT(KC_TAB)) , LCTL(KC_TAB)                                 , RSFT_T(KC_Y)   , KC_HOME       , KC_UP        , KC_END      , KC_PGUP       , KC_BSPC          ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤              
  LT(_WLCAPS,KC_CAPS), LCTL(KC_A)      , LCTL(KC_S)  , LALT_T(KC_D), LSFT(KC_TAB)       , KC_TAB                                       , RALT_T(KC_APP) , KC_LEFT       , KC_DOWN      , KC_RGHT     , KC_PGDN       , KC_ENT           ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
    KC_TRNS          , LCTL(KC_Z)      , LCTL(KC_X)  , LCTL(KC_C)  , LCTL(KC_V)         , LCTL(KC_SLSH)                                , RCTL_T(KC_N)   , KC_BTN1       , KC_MS_U      , KC_BTN2     , KC_WH_U       , KC_WH_L          ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
    KC_TRNS          , KC_TRNS         , KC_TRNS     ,LGUI(KC_COMM), KC_TRNS            , MO(_WLSYM)   , LSFT_T(KC_DEL), TO(_WLBASE)   , KC_BTN1        , KC_MS_L       , KC_MS_D      , KC_MS_R     , KC_WH_D       , KC_WH_R          
  //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
  ),                                            


  [_WLSYM] = LAYOUT(                                                                                                            // SHIFT:  * (from8)        ( (from9)       ) (from0)      _             _               +
  //┌────────────────┬─~───────────────┬─@───────────┬─#───────────┬─$──────────────────┬─%────────────┐                      // SYM:  ┌─^─(of6)────────┬─&─(of7)───────┬─*─(of8)──────┬─_───────────┬─-─────────────┬─+────────────────┐
     KC_TRNS         , KC_TILD         , KC_AT       , KC_HASH     , KC_DLR             , KC_PERC                                      , KC_CIRC        , KC_AMPR       , KC_ASTR      , KC_UNDS     , KC_MINS       , KC_PLUS          ,
  //├────────────────┼─`───────────────┼─[───────────┼─]───────────┼─"──────────────────┼─;────────────┤                               ├─,──────────────┼─7─────────────┼─8────────────┼─9───────────┼─*─────────────┼─|────────────────┤
     KC_TRNS         , KC_GRV          , KC_LBRC     , KC_RBRC     , KC_DQUO            , KC_SCLN                                      , KC_COMM        , KC_7          , KC_8         , KC_9        , KC_ASTR       , KC_PIPE          ,
  //├────────────────┼─!───────────────┼─(───────────┼─)───────────┼─'──────────────────┼─:────────────┤                               ├─h──────────────┼─4─────────────┼─5────────────┼─6───────────┼─=─────────────┼─ret──────────────┤              
     KC_TRNS         , KC_EXLM         , KC_LPRN     , KC_RPRN     , KC_QUOT            , KC_COLN                                      , KC_BSPC        , KC_4          , KC_5         , KC_6        , KC_EQL        , KC_ENT           ,
  //├────────────────┼─?───────────────┼─{───────────┼─}───────────┼─/──────────────────┼─\────────────┤                               ├─n──────────────┼─1─────────────┼─2────────────┼─3───────────┼─,─────────────┼─/────────────────┤
     KC_TRNS         , KC_QUES         , KC_LCBR     , KC_RCBR     , KC_SLSH            , KC_BSLS                                      , KC_TRNS        , KC_1          , KC_2         , KC_3        , KC_COMMA      , KC_SLSH          ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├─ ──────────────┼─0─────────────┼─0────────────┼─.───────────┼─.─────────────┼──────────────────┤
     KC_TRNS         , KC_TRNS         , KC_TRNS     , KC_TRNS     , KC_TRNS            , KC_TRNS      ,    KC_TRNS   ,  TO(_WLBASE)   , KC_TRNS        , KC_0          , KC_0         , KC_DOT      , KC_DOT        , KC_TRNS          
  //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
  ),

  [_WLCAPS] = LAYOUT(    // just a few caps modifiers
  //┌────────────────┬─────────────────┬─────────────┬─────────────┬────────────────────┬──────────────┐                               ┌────────────────┬───────────────┬──────────────┬─────────────┬───────────────┬──────────────────┐
     KC_TRNS         , LCA(KC_1)       , LCA(KC_2)   , LCA(KC_3)   , LCA(KC_4)          , LCA(KC_5)                                    , LCA(KC_6)      , LCA(KC_7)     , LCA(KC_8)    , LCA(KC_9)   , KC_TRNS       , KC_TRNS          ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
     KC_TRNS         , LSCA(KC_LEFT)   ,LSCA(KC_RGHT), KC_TRNS     , KC_TRNS            , KC_TRNS                                      , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          ,  
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤              
     KC_TRNS         , LCA(KC_LEFT)    , LCA(KC_RGHT), KC_TRNS     , KC_TRNS            , KC_TRNS                                      , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
     KC_TRNS         , KC_TRNS         , KC_TRNS     , KC_TRNS     , KC_TRNS            , KC_TRNS                                      , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          ,
  //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
     KC_TRNS         , KC_TRNS         , KC_TRNS     , KC_TRNS     , KC_TRNS            , KC_TRNS         , KC_TRNS     , TO(_WLBASE)  , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          
  //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
  ),


  // W - to windows layer
  // A - to apple (mac) layer
  [_FUNC] = LAYOUT(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐                               ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
     QK_BOOT    ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO                                     ,KC_F1       ,KC_F2      ,KC_F3      ,KC_F4      ,KC_F5      ,QK_BOOT    ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_NO      ,KC_NO      ,DF(_WLBASE),KC_NO      ,KC_NO      ,KC_NO                                     ,KC_F6       ,KC_F7      ,KC_F8      ,KC_F9      ,KC_F10     ,KC_NO      ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤              
     KC_NO      ,DF(_BASE)  ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO                                     ,KC_F11      ,KC_F12     ,KC_F13     ,KC_F14     ,KC_F15     ,KC_MPRV    ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO                                     ,KC_F16      ,KC_F17     ,KC_F18     ,KC_F19     ,KC_F20     ,KC_MNXT    ,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤                               ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
     KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,KC_NO      ,    KC_NO   ,    DF(_BASE)    ,DF(_WLBASE) ,KC_MUTE    ,KC_NO      ,KC_VOLD    ,KC_VOLU    ,KC_MPLY    
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘  └───────────┘ └───────────┘  └───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘
  ),   

};








// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//   [_BASE] = LAYOUT( /* qwerty mod nalg */
//   //┌────────────────┬─────────────────┬─────────────┬─────────────┬────────────────────┬──────────────┐                               ┌────────────────┬───────────────┬──────────────┬─────────────┬───────────────┬──────────────────┐
//     KC_ESC           , KC_1            , KC_2        , KC_3        , KC_4               , KC_5                                         , KC_8           , KC_9          , KC_0         , KC_UNDS     , KC_MINS       , KC_EQL           ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//     LGUI_T(KC_TAB)   , KC_Q            , KC_W        , KC_E        , KC_R               , KC_T                                         , KC_Y           , KC_U          , KC_I         , KC_O        , KC_P          , KC_BSLS          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤              
//     LT(_DT,KC_CAPS)  , KC_A            , KC_S        , KC_D        , KC_F               , KC_G                                         , KC_H           , KC_BSPC       , KC_ENT       , KC_L        , KC_K          , KC_QUOT          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//     RSFT_T(KC_LGUI)  , KC_Z            , KC_X        , KC_C        , KC_V               , KC_B                                         , KC_N           , KC_M          , KC_COMM      , KC_DOT      , KC_SLSH       , RSFT_T(KC_SLSH)  ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//     RCTL_T(KC_MPLY)  , KC_LGUI         , KC_LALT     ,LGUI(KC_COMM), KC_SPC             , MO(_SYM)      , LSFT_T(KC_DEL), MO(_NAV)     , KC_SPC         , TO(_NAV)      , MO(_FN)      , TO(_NAV)    , KC_APP        , RCTL_T(KC_MPLY)   
//   //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
//   ),                                               // TT(_NAV) for left nav, LGUI(KC_COMM) for win emoji

//   [_NAV] = LAYOUT(
//   //┌────────────────┬─────────────────┬─────────────┬─────────────┬────────────────────┬──────────────┐                               ┌────────────────┬───────────────┬──────────────┬─────────────┬───────────────┬──────────────────┐
//     LALT_T(KC_ESC)   , KC_F11          , KC_F2       , KC_F3       , KC_F4              , KC_F5                                        , LCTL(KC_LBRC)  , LCTL(KC_RBRC) , RCTL(KC_M)   , KC_F12      , RCTL(KC_MINS) , RCTL(KC_EQL)     ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//     KC_TRNS          , LCTL(KC_M)      , LCTL(KC_W)  , LGUI(KC_E)  , LCTL(LSFT(KC_TAB)) , LCTL(KC_TAB)                                 , RSFT_T(KC_Y)   , KC_HOME       , KC_UP        , KC_END      , KC_PGUP       , KC_BSPC          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤              
//     LT(_DT,KC_CAPS)  , LCTL(KC_A)      , LCTL(KC_S)  , LALT_T(KC_D), LSFT(KC_TAB)       , KC_TAB                                       , RALT_T(KC_APP) , KC_LEFT       , KC_DOWN      , KC_RGHT     , KC_PGDN       , KC_ENT           ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//     KC_TRNS          , LCTL(KC_Z)      , LCTL(KC_X)  , LCTL(KC_C)  , LCTL(KC_V)         , LCTL(KC_SLSH)                                , RCTL_T(KC_N)   , KC_BTN1       , KC_MS_U      , KC_BTN2     , KC_WH_U       , KC_WH_L          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//     KC_TRNS          , KC_TRNS         , KC_TRNS     ,LGUI(KC_COMM), KC_TRNS            , MO(_SYM)      , LSFT_T(KC_DEL), TO(_BASE)     , KC_BTN1        , KC_MS_L       , KC_MS_D      , KC_MS_R     , KC_WH_D       , KC_WH_R          
//   //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
//   ),                                             // TO(_BASE)  to return, LGUI(KC_COMM) for win emoji


//   [_SYM] = LAYOUT(                                                                                                            // SHIFT:  * (from8)        ( (from9)       ) (from0)      _             _               +
//   //┌────────────────┬─~───────────────┬─@───────────┬─#───────────┬─$──────────────────┬─%────────────┐                      // SYM:  ┌─^─(of6)────────┬─&─(of7)───────┬─*─(of8)──────┬─_───────────┬─-─────────────┬─+────────────────┐
//      KC_TRNS         , KC_TILD         , KC_AT       , KC_HASH     , KC_DLR             , KC_PERC                                      , KC_CIRC        , KC_AMPR       , KC_ASTR      , KC_UNDS     , KC_MINS       , KC_PLUS          ,
//   //├────────────────┼─`───────────────┼─[───────────┼─]───────────┼─"──────────────────┼─;────────────┤                               ├─,──────────────┼─7─────────────┼─8────────────┼─9───────────┼─*─────────────┼─|────────────────┤
//      KC_TRNS         , KC_GRV          , KC_LBRC     , KC_RBRC     , KC_DQUO            , KC_SCLN                                      , KC_COMM        , KC_7          , KC_8         , KC_9        , KC_ASTR       , KC_PIPE          ,
//   //├────────────────┼─!───────────────┼─(───────────┼─)───────────┼─'──────────────────┼─:────────────┤                               ├─h──────────────┼─4─────────────┼─5────────────┼─6───────────┼─=─────────────┼─ret──────────────┤              
//      KC_TRNS         , KC_EXLM         , KC_LPRN     , KC_RPRN     , KC_QUOT            , KC_COLN                                      , KC_BSPC        , KC_4          , KC_5         , KC_6        , KC_EQL        , KC_ENT           ,
//   //├────────────────┼─?───────────────┼─{───────────┼─}───────────┼─/──────────────────┼─\────────────┤                               ├─n──────────────┼─1─────────────┼─2────────────┼─3───────────┼─,─────────────┼─/────────────────┤
//      KC_TRNS         , KC_QUES         , KC_LCBR     , KC_RCBR     , KC_SLSH            , KC_BSLS                                      , KC_TRNS        , KC_1          , KC_2         , KC_3        , KC_COMMA      , KC_SLSH          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├─ ──────────────┼─0─────────────┼─0────────────┼─.───────────┼─.─────────────┼──────────────────┤
//      KC_TRNS         , KC_TRNS         , KC_TRNS     , KC_TRNS     , KC_TRNS            , KC_TRNS         , KC_TRNS     , TO(_BASE)     , KC_TRNS        , KC_0          , KC_0         , KC_DOT      , KC_DOT        , KC_TRNS          
//   //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
//   ),

//   [_FN] = LAYOUT(
//   //┌────────────────┬─────────────────┬─────────────┬─────────────┬────────────────────┬──────────────┐                               ┌────────────────┬───────────────┬──────────────┬─────────────┬───────────────┬──────────────────┐
//      QK_BOOT         , KC_F11          , KC_HOME     , KC_F3       , KC_F4              , KC_F5                                        , KC_F1          , KC_F2         , KC_F3        , KC_F4       , KC_F5         , QK_BOOT          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//      KC_TRNS         , LCTL(KC_W)      , LGUI_T(KC_END), KC_UP     , LCTL(LSFT(KC_TAB)) , LCTL(KC_TAB)                                 , KC_F6          , KC_F7         , KC_F8        , KC_F9       , KC_F10        , KC_NO            ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤              
//      KC_F13          , LALT_T(KC_F14)  , KC_LEFT     , KC_DOWN     , KC_RGHT            , LSFT(KC_TAB)                                 , KC_F11         , KC_F12        , KC_F13       , KC_F14      , KC_F15        , KC_MPRV          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//      KC_WH_L         , KC_WH_U         , KC_BTN2     , KC_MS_U     , KC_BTN1            , KC_TAB                                       , KC_F16         , KC_F17        , KC_F18       , KC_F19      , KC_F20        , KC_MNXT          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//      KC_WH_R         , KC_WH_D         , KC_MS_L     , KC_MS_D     , KC_MS_R            , KC_BTN1       , LSFT_T(KC_DEL), TO(_BASE)     , KC_SPC         , KC_MUTE       , KC_TRNS      , KC_VOLD     , KC_VOLU       , KC_MPLY       
//   //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
//   ),

//   [_DT] = LAYOUT(    // just a few caps modifiers
//   //┌────────────────┬─────────────────┬─────────────┬─────────────┬────────────────────┬──────────────┐                               ┌────────────────┬───────────────┬──────────────┬─────────────┬───────────────┬──────────────────┐
//      KC_TRNS         , LCA(KC_1)       , LCA(KC_2)   , LCA(KC_3)   , LCA(KC_4)          , LCA(KC_5)                                    , LCA(KC_6)      , LCA(KC_7)     , LCA(KC_8)    , LCA(KC_9)   , KC_TRNS       , KC_TRNS          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//      KC_TRNS         , LSCA(KC_LEFT)   ,LSCA(KC_RGHT), KC_TRNS     , KC_TRNS            , KC_TRNS                                      , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          ,  
//      // KC_TRNS    , LSFT(LGUI(KC_LEFT)), LSFT(LGUI(KC_RGHT)), KC_TRNS, KC_TRNS            , KC_TRNS                                      , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤              
//      KC_TRNS         , LCA(KC_LEFT)    , LCA(KC_RGHT), KC_TRNS     , KC_TRNS            , KC_TRNS                                      , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//      KC_TRNS         , KC_TRNS         , KC_TRNS     , KC_TRNS     , KC_TRNS            , KC_TRNS                                      , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          ,
//   //├────────────────┼─────────────────┼─────────────┼─────────────┼────────────────────┼──────────────┤                               ├────────────────┼───────────────┼──────────────┼─────────────┼───────────────┼──────────────────┤
//      KC_TRNS         , KC_TRNS         , KC_TRNS     , KC_TRNS     , KC_TRNS            , KC_TRNS         , KC_TRNS     , KC_TRNS      , KC_TRNS        , KC_TRNS       , KC_TRNS      , KC_TRNS     , KC_TRNS       , KC_TRNS          
//   //└────────────────┴─────────────────┴─────────────┴─────────────┴────────────────────┴──────────────┘  └───────────┘ └───────────┘  └────────────────┴───────────────┴──────────────┴─────────────┴───────────────┴──────────────────┘
//   ),


//   /*
//   [_TRNS] = LAYOUT(
//     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
//     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
//     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
//     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
//     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
//   ),
//   */

// };