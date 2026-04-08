#ifdef OLED_ENABLE

#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdio.h>

#ifdef LUNA_ENABLE
#    include "luna.h"
#endif

#ifdef OCEAN_DREAM_ENABLE
#    include "ocean_dream.h"
#endif

bool is_master = false;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    is_master = is_keyboard_master();
    return OLED_ROTATION_270;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("L:"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("0"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("1"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("2"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("3"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?"), false);
            break;
    }
}

void render_wpm_status(void) {
    oled_write_P(PSTR("W:"), false);
    char wpm[6];
    itoa(get_current_wpm(), wpm, 10);
    oled_write(wpm, false);
    oled_write_P(PSTR("\n"), false);
}

void render_right_oled(void) {
    // Keyboard name header
    oled_write_P(PSTR("lily\n58\n----\n"), false);

    // Layer name
    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_P(PSTR("QWRT"), false); break;
        case 1: oled_write_P(PSTR("LOWR"), false); break;
        case 2: oled_write_P(PSTR("RISE"), false); break;
        case 3: oled_write_P(PSTR("ADJS"), false); break;
        default: oled_write_P(PSTR("????"), false); break;
    }
    oled_write_P(PSTR("\n\n"), false);

    // Modifier indicators (lit up when held)
    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(mods & MOD_MASK_SHIFT ? PSTR("SFT\n") : PSTR("   \n"), false);
    oled_write_P(mods & MOD_MASK_CTRL  ? PSTR("CTL\n") : PSTR("   \n"), false);
    oled_write_P(mods & MOD_MASK_ALT   ? PSTR("ALT\n") : PSTR("   \n"), false);
    oled_write_P(mods & MOD_MASK_GUI   ? PSTR("GUI\n") : PSTR("   \n"), false);

    // Caps lock
    oled_write_P(PSTR("\n"), false);
    led_t leds = host_keyboard_led_state();
    oled_write_P(leds.caps_lock ? PSTR("CAP!") : PSTR("cap "), false);
}

bool oled_task_user(void) {
    if (!is_oled_on()) {
        return false;
    }
    
    if (is_master) {
        if (timer_elapsed32(last_input_activity_time()) < OLED_TIMEOUT) {
            oled_render_layer_state();
            render_wpm_status();
#ifdef LUNA_ENABLE
            led_usb_state = host_keyboard_led_state();
            render_luna(0, 13);
#endif
        }
    } else {
        render_right_oled();
    }
    return false;
}

#endif  // OLED_ENABLE
