/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published byfile:///C:/Users/N/Downloads/keymap.c
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8



// Snugged from atreus config

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCE 5
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


// fix mousekeys
#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          10
#define MOUSEKEY_MAX_SPEED         9
#define MOUSEKEY_TIME_TO_MAX       60
#define MOUSEKEY_WHEEL_DELAY       0
#define MOUSEKEY_WHEEL_INTERVAL    20
#define MOUSEKEY_WHEEL_MAX_SPEED   12
#define MOUSEKEY_WHEEL_TIME_TO_MAX 65

#define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 175
#define TAPPING_TOGGLE 1            


