#include "user-interface/ui_main_menu.h"

#include <stddef.h>
#include <inttypes.h>

#include "defs.h"
#include "hardcode.h"
#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/graphics.h"
#include "user-interface/ui_helper.h"
#include "user-interface/ui_button.h"
#include "DFG-firmware/programmable_oscillator_driver.h"
#include "DFG-firmware/DDS_firmware.h"

#define MAIN_MENU_BUTTONS_SIZE 3

#define STR_START   "START"
#define STR_STOP    "STOP"
#define STR_OPTIONS "OPTIONS"
#define STR_ON      "ON "
#define STR_OFF     "OFF"

struct _draw_params_t {
    struct lcd_driver_t *driver;
    const char *str;
    uint16_t outline_color;
    uint16_t fill_color;
    uint8_t outline_thickness;
    uint8_t char_thickness;
    uint16_t string_color;
};

struct _mm_start_button_press_params_t {
    struct lcd_driver_t *driver;
    uint16_t start_x;
    uint16_t start_y;
    uint16_t string_color;
    uint16_t bg_color;
    uint8_t char_thickness;
};

struct _mm_stop_button_press_params_t {
    struct lcd_driver_t *driver;
    uint16_t start_x;
    uint16_t start_y;
    uint16_t string_color;
    uint16_t bg_color;
    uint8_t char_thickness;
};

static void _draw_mm_button(struct ui_button_t *, void *);

static void _press_mm_start_button(struct ui_button_t *, void *);

static void _press_mm_stop_button(struct ui_button_t *, void *);

static void _press_mm_options_button(struct ui_button_t *, void *);

static struct ui_button_t _main_menu_buttons[MAIN_MENU_BUTTONS_SIZE] = {
    { 
        0x64, 0x19, 0x78, 0x32, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_mm_button, &_draw_mm_button, &_press_mm_start_button
    },  // START button
    { 
        0x64, 0x5F, 0x78, 0x32, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_mm_button, &_draw_mm_button, &_press_mm_stop_button
    },  // STOP button
    { 
        0x64, 0xA5, 0x78, 0x32, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_mm_button, &_draw_mm_button, &_press_mm_options_button
    },  // OPTIONS button
};

void draw_main_menu(struct lcd_driver_t *driver)
{
    static const uint16_t bg_color = 0x00;
    struct _draw_params_t draw_params = {
        driver,
        NULL,
        0x4800,
        0xBB02,
        4,
        2,
        0xFFFF
    };
    
    // Background
    fill_rectangle(driver, 0x00, 0x00, driver->res_x, driver->res_y, bg_color);
    // START button
    draw_params.str = STR_START;
    _main_menu_buttons[0].draw(&_main_menu_buttons[0], &draw_params);
    // STOP button
    draw_params.str = STR_STOP;
    _main_menu_buttons[1].draw(&_main_menu_buttons[1], &draw_params);
    // OPTIONS button
    draw_params.str = STR_OPTIONS;
    _main_menu_buttons[2].draw(&_main_menu_buttons[2], &draw_params);
}

void scan_main_menu(struct lcd_driver_t *driver, uint16_t touched_x, uint16_t touched_y)
{
    static const uint16_t fill_color = 0xBB02;
    static const uint16_t outline_color = 0x4800;
    static const char *_button_strings[MAIN_MENU_BUTTONS_SIZE] = { STR_START, STR_STOP, STR_OPTIONS };
    static struct _draw_params_t draw_params = {
        NULL,
        NULL,
        0x4800,
        0xBB02,
        4,
        2,
        0xFFFF
    };
    static struct _mm_start_button_press_params_t mm_start_button_press_params = {
        NULL,
        0x0014,
        0x0014,
        0x47E0,
        0x0000,
        2
    };
    static struct _mm_stop_button_press_params_t mm_stop_button_press_params = {
        NULL,
        0x0014,
        0x0014,
        0xD860,
        0x0000,
        2
    };
    static void *press_params[MAIN_MENU_BUTTONS_SIZE] = {
        &mm_start_button_press_params,
        &mm_stop_button_press_params
    };
    
    draw_params.driver = driver;
    mm_start_button_press_params.driver = driver;
    mm_stop_button_press_params.driver = driver;
    
    for (size_t i = 0; i < MAIN_MENU_BUTTONS_SIZE; ++i) {
        if ((touched_x >= _main_menu_buttons[i].start_x 
                && touched_x <= _main_menu_buttons[i].start_x + _main_menu_buttons[i].width)
                && (touched_y >= _main_menu_buttons[i].start_y 
                && touched_y <= _main_menu_buttons[i].start_y + _main_menu_buttons[i].height))
            ui_button_set_state(&_main_menu_buttons[i], ACTIVE);
        else
            ui_button_set_state(&_main_menu_buttons[i], NOT_ACTIVE);
    }
    
    for (size_t i = 0; i < MAIN_MENU_BUTTONS_SIZE; ++i) {
        if (_main_menu_buttons[i].state != _main_menu_buttons[i].prev_state) {
            draw_params.str = _button_strings[i];
            if (_main_menu_buttons[i].state == ACTIVE) {
                draw_params.fill_color = outline_color;
                draw_params.outline_color = fill_color;
                _main_menu_buttons[i].active(&_main_menu_buttons[i], &draw_params);
            } else {
                draw_params.fill_color = fill_color;
                draw_params.outline_color = outline_color;
                _main_menu_buttons[i].draw(&_main_menu_buttons[i], &draw_params);
            }
            
            if (_main_menu_buttons[i].prev_state == ACTIVE 
                    && _main_menu_buttons[i].state == NOT_ACTIVE) {
                _main_menu_buttons[i].press(&_main_menu_buttons[i], press_params[i]);
            }
        }
    }
}

static void _draw_mm_button(struct ui_button_t *button, void *params_p)
{
    struct _draw_params_t params = *((struct _draw_params_t *)params_p);
    
    fill_rectangle(params.driver, button->start_x, button->start_y,
            button->width, button->height, params.fill_color);
    draw_rectangle(params.driver, button->start_x, button->start_y,
            button->width, button->height, params.outline_color, params.outline_thickness);
    draw_string(params.driver, 
        button->start_x + _horizontal_str_offset(params.str, button->width, params.char_thickness),
        button->start_y + _vertical_str_offset(params.str, button->height, params.char_thickness), 
        params.str, params.string_color, 0x0000, params.char_thickness, 0);
}

static void _press_mm_start_button(struct ui_button_t *button, void *params_p)
{
    struct _mm_start_button_press_params_t params = *((struct _mm_start_button_press_params_t *)params_p);
    
    if (g_wave_changed & FBOOL0) {
        uint8_t os;
        
        set_waveform(g_wave_data, g_wave_size, g_values[g_freq_setting][0], 4096);
        osc_read_range(U8_TWI_ADDRESS, &os);
        osc_conf_mux_word(U8_TWI_ADDRESS, g_values[g_freq_setting][1]);
        osc_conf_div(U8_TWI_ADDRESS, g_values[g_freq_setting][2]);
        osc_conf_freq(U8_TWI_ADDRESS, g_values[g_freq_setting][4], os + g_values[g_freq_setting][3]);
        load_into_dac();
        g_wave_changed = 0;
    }
    draw_string(params.driver, params.start_x, params.start_y, STR_ON, 
        params.string_color, params.bg_color, params.char_thickness, FBOOL0);
    osc_output_enable();
}

static void _press_mm_stop_button(struct ui_button_t *button, void *params_p)
{
    struct _mm_stop_button_press_params_t params = *((struct _mm_stop_button_press_params_t *)params_p);

    draw_string(params.driver, params.start_x, params.start_y, STR_OFF, 
        params.string_color, params.bg_color, params.char_thickness, FBOOL0);
    osc_output_disable();
}

static void _press_mm_options_button(struct ui_button_t *button, void *params_p)
{
    set_menu_scene(OPTIONS_MENU);
}
