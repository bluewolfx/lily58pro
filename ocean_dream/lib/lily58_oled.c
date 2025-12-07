#ifdef OLED_ENABLE

#include QMK_KEYBOARD_H
#include "quantum.h"
#include <stdio.h>
#include "os_detection.h"

#ifdef LUNA_ENABLE
#    include "luna.h"
led_t led_usb_state;
#endif

#ifdef OCEAN_DREAM_ENABLE
#    include "ocean_dream.h"
#endif

bool is_master = false;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    is_master = is_keyboard_master();
    if (!is_master) {
        return OLED_ROTATION_270;
    }
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

void render_nkro_status(void) {
    oled_write_P(PSTR("N:"), false);
    oled_write_P(keymap_config.nkro ? PSTR("ON") : PSTR("OF"), false);
    oled_write_P(PSTR("\n"), false);
}

void render_wpm_status(void) {
    oled_write_P(PSTR("W:"), false);
    char wpm[6];
    itoa(get_current_wpm(), wpm, 10);
    oled_write(wpm, false);
    oled_write_P(PSTR("\n"), false);
}

void render_os_logo(void) {
    os_variant_t detected_os = detected_host_os();
    static const char PROGMEM windows_logo[] = {0x9D, 0x9E, 0xBD, 0xBE, 0x00};
    static const char PROGMEM apple_logo[] = {0x9F, 0x00};
    static const char PROGMEM linux_logo[] = {0x1E, 0x1F, 0x00};
    
    switch (detected_os) {
        case OS_WINDOWS:
            oled_write_P(windows_logo, false);
            break;
        case OS_MACOS:
            oled_write_P(apple_logo, false);
            break;
        case OS_LINUX:
            oled_write_P(linux_logo, false);
            break;
        case OS_IOS:
            oled_write_P(apple_logo, false);
            break;
        case OS_UNSURE:
        default:
            oled_write_P(PSTR("?"), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);
}

bool oled_task_user(void) {
    if (!is_oled_on()) {
        return false;
    }
    
    if (is_master) {
        render_os_logo();
        oled_render_layer_state();
        render_nkro_status();
        render_wpm_status();
#ifdef LUNA_ENABLE
        if (timer_elapsed32(last_input_activity_time()) < OLED_TIMEOUT) {
            led_usb_state = host_keyboard_led_state();
            render_luna(0, 13);
        }
#endif
    } else {
#ifdef OCEAN_DREAM_ENABLE
        if (timer_elapsed32(last_input_activity_time()) < OLED_TIMEOUT) {
            render_stars();
        }
#endif
    }
    return false;
}

#endif  // OLED_ENABLE
