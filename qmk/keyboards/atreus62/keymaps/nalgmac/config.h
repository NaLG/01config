
// nalg:

// fix mousekeys
#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          8  // win: 10
#define MOUSEKEY_MAX_SPEED         12 // win: 9
#define MOUSEKEY_TIME_TO_MAX       60
#define MOUSEKEY_WHEEL_DELAY       0
#define MOUSEKEY_WHEEL_INTERVAL    25 // win: 20
#define MOUSEKEY_WHEEL_MAX_SPEED   8  // win: 12
#define MOUSEKEY_WHEEL_TIME_TO_MAX 65

// f'd up on mac after 0.20.8.  Permissive hold isn't working, can sidestep by shortening tapping_term but hacky.
// TO BUILD
//   git checkout 0.20.8
//   make atreus62:nalgmac:flash
#define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT // now the default
#define TAPPING_TERM 175 
// #define TAPPING_TOGGLE 1 



// // for atreus62???
// /* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
// /* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE


