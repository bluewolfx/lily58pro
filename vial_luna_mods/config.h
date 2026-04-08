/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
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

/* VIAL UID for Lily58 */
#define VIAL_KEYBOARD_UID {0x7E, 0xFD, 0xFC, 0x5B, 0x7D, 0x39, 0x48, 0x06}

/* VIAL secure unlock keystroke - both big keys (SPACE/ENTER) */
#define VIAL_UNLOCK_COMBO_ROWS {4, 9}
#define VIAL_UNLOCK_COMBO_COLS {4, 4}

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define MASTER_LEFT
#define QUICK_TAP_TERM 120
#define TAPPING_TERM 200
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE
#define OLED_TIMEOUT 30000
#define USB_SUSPEND_WAKEUP_DELAY 200

#define ENCODER_A_PINS { }
#define ENCODER_B_PINS { }
#define ENCODER_RESOLUTIONS { }
#define ENCODER_A_PINS_RIGHT { F4 }
#define ENCODER_B_PINS_RIGHT { D4 }
#define ENCODER_RESOLUTIONS_RIGHT { 4 }
