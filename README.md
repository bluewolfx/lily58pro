# Lily58 Pro Keyboard Configurations

My QMK firmware configurations for the Lily58 Pro split keyboard.

## Current Configuration: Vial + Luna + Mod Indicators


### Features

#### Left OLED (Vertical, Master Side)
- **Layer Status**: Shows current layer number (0-3)
- **WPM Counter**: Real-time words per minute
- **Luna Cat Animation**:
  - Sits when idle
  - Walks at 10+ WPM
  - Runs at 40+ WPM
  - Jumps when pressing Space
  - Sneaks when holding Ctrl
  - Stops animating after OLED timeout

#### Right OLED (Vertical, Slave Side)
- **Keyboard Name**: "lily58" header
- **Layer Name**: Active layer displayed (QWRT / LOWR / RISE / ADJS)
- **Modifier Indicators**: Highlights active modifiers — SFT, CTL, ALT, GUI
- **Caps Lock Indicator**: Shows `CAP!` when Caps Lock is on, blank when off

#### Keyboard Features
- **Mouse Keys**: Layer 1 (mouse buttons BTN1-5), Layer 3 (mouse cursor + wheel scroll)
- **Rotary Encoder**: Volume control (right side only)
- **Arrow Keys**: Layer 2, positioned under H/J/K/L (LEFT/DOWN/UP/RIGHT)
- **Vial Support**: Full dynamic keymap editing via [vial.rocks](https://vial.rocks) or Vial desktop app
- **EEPROM Reset**: LOWER+RAISE+left encoder click clears saved Vial layout
- **Auto OLED Timeout**: 30 seconds with fade out effect

### Keymap Layers

- **Layer 0 (Base)**: QWERTY layout
- **Layer 1 (Lower)**: Function keys, symbols, mouse buttons, media controls
- **Layer 2 (Raise)**: Numbers, F-keys, arrow keys, brackets, operators
- **Layer 3 (Adjust)**: Mouse cursor movement, wheel scroll, EEPROM reset

## Directory Structure

```
lily58pro/
├── README.md                                    # This file
├── vial_luna_mods/                              # Current active config (Vial + Luna + Mod indicators)
│   ├── config.h                                 # Hardware settings, Vial UID, tapping term
│   ├── keymap.c                                 # Key mappings
│   ├── rules.mk                                 # Build configuration
│   ├── vial.json                                # Vial keyboard layout definition
│   └── lib/
│       ├── lily58_oled.c                        # Custom OLED handler
│       └── luna.c/h                             # Luna cat animation
├── ocean_dream/                                 # Previous config (no Vial, has Ocean Dream animation)
│   ├── config.h
│   ├── keymap.c
│   ├── rules.mk
│   ├── lily58_rev1_ocean_dream.hex              # Pre-compiled firmware
│   └── lib/
│       ├── lily58_oled.c/h
│       ├── luna.c/h
│       └── ocean_dream.c/h                      # Ocean Dream animation
└── bongocat/                                    # Oldest config (backup)
    ├── config.h
    ├── keymap.c
    ├── rules.mk
    ├── lily58.layout.json                       # VIA layout
    └── lib/
        └── bongocat.c/h
```

## Flashing Firmware

### Primary Workflow — Windows QMK MSYS + vial-qmk

The main build environment is **QMK MSYS on Windows** with `vial-qmk` at `C:\Users\ricar\vial-qmk`.  
The `lily58pro/` directory in WSL is a backup of the source files.

Keymap files live at:
```
C:\Users\ricar\vial-qmk\keyboards\lily58\keymaps\vial_luna_mods\
```

To compile and flash from QMK MSYS:
```bash
qmk flash -kb lily58/rev1 -km vial_luna_mods
```

Then press the reset button on the keyboard when prompted.

### Syncing from WSL to Windows

```bash
cp -r ~/lily58pro/vial_luna_mods /mnt/c/Users/ricar/vial-qmk/keyboards/lily58/keymaps/
```

## Configuration Details

### OLED Settings
- **Timeout**: 30 seconds with automatic fade out
- **Rotation**: 270° (vertical orientation on both sides)
- **Split OLED**: Enabled for independent left/right displays

### Build Options (`vial_luna_mods`)
- **LTO**: Enabled (reduces firmware size)
- **NKRO**: Disabled
- **Mouse Keys**: Enabled
- **Encoders**: Enabled (right side only)
- **WPM Tracking**: Enabled with split support
- **Vial**: Enabled for dynamic keymap editing
- **Luna Animation**: Enabled
- **Ocean Dream**: Removed (dead code cleanup)
- **OLED Fade Out**: Enabled with 5-step interval
- **Tap Dance**: Enabled
- **Bootmagic**: Disabled
- **RGB/LED**: Disabled (no RGB hardware)
- **Audio**: Disabled
- **Console/Command**: Disabled

### Special Key Combinations

- **Adjust Layer**: Hold LOWER + RAISE simultaneously
- **EEPROM Reset**: LOWER + RAISE + left encoder click (clears Vial saved layout)
- **Mute**: Right encoder click on RAISE layer
