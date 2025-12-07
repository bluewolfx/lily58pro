LTO_ENABLE = yes
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = yes
BACKLIGHT_ENABLE = no
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = no
SWAP_HANDS_ENABLE = no
OLED_ENABLE = yes
WPM_ENABLE = yes
VIA_ENABLE = yes
ENCODER_ENABLE = yes
SLEEP_LED_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
OLED_FADE_OUT = yes
OLED_FADE_OUT_INTERVAL = 5

# Ocean Dream Animation
OCEAN_DREAM_ENABLE = yes
# Luna Cat Animation
LUNA_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += lib/lily58_oled.c
    
    ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
        SRC += lib/ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif
    
    ifeq ($(strip $(LUNA_ENABLE)), yes)
        SRC += lib/luna.c
        OPT_DEFS += -DLUNA_ENABLE
    endif
endif
