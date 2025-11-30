# Lily58 Pro - Custom QMK Firmware

Custom QMK firmware for Lily58 Pro with bongocat OLED animation, VIA support, and rotary encoder.

## Features

- Animated Bongocat on right OLED (reacts to typing speed)
- WPM Counter + Layer indicator on left OLED
- Rotary Encoder support (volume control)
- Mouse Keys enabled (ready for Ploopy trackball)
- VIA Support for keymap customization
- LTO Optimization - firmware fits in 96% (970 bytes free)
- 4 Layers: QWERTY, LOWER, RAISE, ADJUST

## OLED Displays

### Left OLED (Master)
- Current WPM (Words Per Minute)
- Active layer name
- Caps Lock indicator
- GUI status

### Right OLED (Slave)
- Animated bongocat
- Idle animation when not typing
- Bongo animation when typing (speed increases with WPM)
- Auto-sleep after 10 minutes of inactivity

## Keymap Layers

See [lily58.layout.json](via/lily58.layout.json) for full VIA configuration.

### Layer 0: QWERTY (Base)
```
,-----------------------------------------.                    ,-----------------------------------------.
| ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
| Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
|------+------+------+------+------+------|                    |------+------+------+------+------+------|
|LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
|------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
|LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
`-----------------------------------------/       /     \      \-----------------------------------------'
                  | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
                  |      |      |      |/       /         \      \ |      |      |      |
                  `----------------------------'           '------''--------------------'
```

### Layer 1: LOWER
Function keys (F1-F12) and symbols

### Layer 2: RAISE
Numbers and arrow keys

### Layer 3: ADJUST
System controls and RGB (accessed by holding LOWER + RAISE)

## Hardware Configuration

- **MCU:** ATmega32U4
- **Bootloader:** Caterina
- **Encoder:** Single rotary encoder on right half (F4/D4 pins)
- **OLED:** 128x32 SSD1306 displays on both halves
- **Split:** TRRS cable connection

## Build Configuration

### Enabled Features
- `LTO_ENABLE = yes`
- `VIA_ENABLE = yes`
- `OLED_ENABLE = yes`
- `WPM_ENABLE = yes`
- `ENCODER_ENABLE = yes`
- `MOUSEKEY_ENABLE = yes`
- `EXTRAKEY_ENABLE = yes`

### Firmware Size
27,702 / 28,672 bytes (96%) - 970 bytes free

## Credits

- Bongocat Animation: [xxqxpxx/lily58_bongocat_mac](https://github.com/xxqxpxx/lily58_bongocat_mac)
- QMK Firmware: [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware)
- Lily58: [kata0510/Lily58](https://github.com/kata0510/Lily58)

## Configuration Details

- OLED timeout: 10 minutes
- Master hand: LEFT
- Encoder: Volume up/down on right half
- WPM tracking updates bongocat animation speed

## Changelog

### November 30, 2025
- Fixed bongocat flickering issue after idle timeout
- Added timer reset when OLED wakes from sleep to prevent rapid frame cycling

---

Last Updated: November 30, 2025 
QMK Version: 0.30.13

