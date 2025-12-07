# Lily58 Pro Keyboard Configurations

My QMK firmware configurations for the Lily58 Pro split keyboard.

## Current Configuration: Ocean Dream + Luna

**Firmware Size:** 26,568/28,672 bytes (92%, 2,104 bytes free)  
**Last Updated:** 2025-12-07

### Features

#### Left OLED (Vertical, Master Side)
- **OS Detection**: Automatically detects and displays connected OS (Windows/Mac/Linux icon)
- **Layer Status**: Shows current layer (0-3)
- **NKRO Status**: Displays NKRO on/off state
- **WPM Counter**: Real-time words per minute
- **Luna Cat Animation**: 
  - Sits when idle
  - Walks at 10+ WPM
  - Runs at 40+ WPM
  - Jumps when pressing Space
  - Sneaks when holding Ctrl
  - Barks when Caps Lock is on
  - Stops animating 30s before timeout

#### Right OLED (Vertical, Slave Side)
- **Ocean Dream Animation**: Animated ocean scene
  - Twinkling stars
  - Shooting stars (increases with WPM)
  - Animated waves (rougher with higher WPM)
  - Island with palm tree
  - Moon with phases
  - Responds to typing speed
  - Stops animating 30s before timeout

#### Keyboard Features
- **Mouse Keys**: Layer 1 (mouse buttons), Layer 3 (mouse movement + wheel)
- **NKRO Toggle**: Hold LOWER+RAISE, press right encoder
- **Rotary Encoder**: Volume control (right side)
- **Arrow Keys**: Layer 2, positioned under 6/7/8/9 (LEFT/DOWN/UP/RIGHT)
- **VIA Support**: Enabled for real-time keymap editing
- **Auto OLED Timeout**: 30 seconds with fade out effect

### Keymap Layers

- **Layer 0 (Base)**: QWERTY layout
- **Layer 1 (Lower)**: Function keys, symbols, mouse buttons
- **Layer 2 (Raise)**: Numbers, F-keys, arrow keys
- **Layer 3 (Adjust): Mouse movement, wheel scroll, OLED toggle, NKRO toggle

## Directory Structure

```
lily58pro/
├── README.md                                    # This file
├── ocean_dream/lily58_rev1_ocean_dream.hex  # Compiled firmware
├── ocean_dream/                                 # Current active config
│   ├── config.h                                 # Hardware settings
│   ├── keymap.c                                 # Key mappings
│   ├── rules.mk                                 # Build configuration
│   └── lib/
│       ├── lily58_oled.c/h                      # Custom OLED handler
│       ├── luna.c/h                             # Luna cat animation
│       └── ocean_dream.c/h                      # Ocean Dream animation
└── bongocat/                                    # Previous config (backup)
    ├── config.h
    ├── keymap.c
    ├── rules.mk
    ├── lily58.layout.json                       # VIA layout
    └── lib/
        └── bongocat.c/h                         # Old BongoCat animation
```

## Flashing Firmware

### Using QMK MSYS (Windows)

```bash
cd ~/qmk_firmware
qmk compile -kb lily58/rev1 -km my_config_with_bongoCat
qmk flash -kb lily58/rev1 -km my_config_with_bongoCat
```

Then press the reset button on your keyboard.

### Pre-compiled Firmware

Flash `ocean_dream/lily58_rev1_ocean_dream.hex` using QMK Toolbox or:
```bash
qmk flash ocean_dream/lily58_rev1_ocean_dream.hex
```

## Configuration Details

### OLED Settings
- **Timeout**: Disabled (manual toggle via OLED_TOG key)
- **Rotation**: 270° (vertical orientation on both sides)
- **Split OLED**: Enabled for independent left/right displays
- **Manual Control**: Use LOWER+RAISE+B to toggle screens on/off

### Build Options
- **LTO**: Enabled (reduces firmware size)
- **NKRO**: Enabled (N-Key Rollover for gaming/fast typing)
- **Mouse Keys**: Enabled
- **Encoders**: Enabled (right side only)
- **WPM Tracking**: Enabled with split support
- **VIA**: Enabled for GUI keymap editing
- **OS Detection**: Enabled (Windows/Mac/Linux/iOS)
- **OLED Fade Out**: Enabled with 5-step interval

### Disabled Features (to save space)
- Bootmagic: Disabled
- RGB/LED: Disabled (no RGB hardware)
- Audio: Disabled
- Console/Command: Disabled


## Special Key Combinations

- **NKRO Toggle**: LOWER + RAISE + Right Encoder
- **Adjust Layer**: Hold LOWER + RAISE simultaneously
- **Ocean Dream Calm Mode**: Hold Ctrl (makes waves calm)
- **Luna Jump**: Press Space
- **Luna Sneak**: Hold Ctrl

## Credits

- **Ocean Dream Animation**: [@snowe2010](https://github.com/snowe2010/qmk_firmware)
- **Luna Cat Animation**: QMK Community
- **QMK Firmware**: [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware)

## Changelog

### 2025-12-07 - OS Detection and OLED Timeout Fix
- Added OS detection with icon display (Windows/Mac/Linux/iOS)
- Fixed OLED timeout flickering issue with guard clause
- Implemented automatic OLED timeout (30s) with fade out effect
- Animation stops 30s before timeout to allow proper screen shutdown
- Removed manual OLED toggle (now fully automatic)
- Fixed ADJUST layer keymap comment formatting
- Optimized OLED display layout (OS icon + Layer + NKRO + WPM)

### 2025-12-06 - Ocean Dream + Luna Implementation
- Replaced BongoCat with Ocean Dream (right OLED)
- Added Luna cat animation (left OLED)
- Reorganized OLED layout: Layer/NKRO/WPM/Luna
- Added mouse keys to Layer 1 and Layer 3
- Repositioned arrow keys to match VIA layout
- Added NKRO toggle key
- Fixed OLED timeout flickering issues
- Added Luna jump (Space) and sneak (Ctrl) triggers
- Optimized firmware size: 26,568 bytes (2,104 bytes free)
- Removed unused keylog code (saved ~1,266 bytes)
- Enabled moon animation (uses 182 bytes)
