#include "user-interface/ui_options_menu.h"

#include <stddef.h>
#include <inttypes.h>

#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/graphics.h"
#include "user-interface/ui_helper.h"
#include "user-interface/ui_button.h"
#include "DFG-firmware/waveforms.h"
#include "DFG-firmware/DDS_firmware.h"
#include "DFG-firmware/programmable_oscillator_driver.h"
#include "hardcode.h"

#define STR_10HZ    "10Hz"
#define STR_1KHZ    "1kHz"
#define STR_100KHZ  "100kHz"
#define STR_1V      "1V"
#define STR_2V      "2V"
#define STR_3V      "3V"
#define STR_BACK    "BACK"

#define OPTIONS_MENU_BUTTONS_SIZE 10

struct _draw_params_t {
    struct lcd_driver_t *driver;
    const char *str;
    uint16_t outline_color;
    uint16_t fill_color;
    uint8_t outline_thickness;
    uint8_t char_thickness;
    uint16_t string_color;
};

static void _draw_om_text_button(struct ui_button_t *, void *);

static void _draw_om_figure_button(struct ui_button_t *, void *);

static void _press_om_sin_wave_button(struct ui_button_t *, void *);

static void _press_om_tri_wave_button(struct ui_button_t *, void *);

static void _press_om_sq_wave_button(struct ui_button_t *, void *);

static void _press_om_10hz_button(struct ui_button_t *, void *);

static void _press_om_1khz_button(struct ui_button_t *, void *);

static void _press_om_100khz_button(struct ui_button_t *, void *);

static void _press_om_1v_button(struct ui_button_t *, void *);

static void _press_om_2v_button(struct ui_button_t *, void *);

static void _press_om_3v_button(struct ui_button_t *, void *);

static void _press_om_back_button(struct ui_button_t *, void *);

static struct ui_button_t _options_menu_buttons[OPTIONS_MENU_BUTTONS_SIZE] = {
    { 
        0x001E, 0x000F, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_figure_button, 
        &_draw_om_figure_button,
        &_press_om_sin_wave_button
    },  // sin wave button
    { 
        0x0082, 0x000F, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_figure_button,
        &_draw_om_figure_button,
        &_press_om_tri_wave_button
    },  // triangle wave button
    { 
        0x00E6, 0x000F, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_figure_button,
        &_draw_om_figure_button,
        &_press_om_sq_wave_button
    },  // square wave button
    { 
        0x001E, 0x0041, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_text_button,
        &_draw_om_text_button,
        &_press_om_10hz_button
    },  // 10Hz button
    { 
        0x0082, 0x0041, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_text_button,
        &_draw_om_text_button,
        &_press_om_1khz_button
    },  // 1kHz button
    { 
        0x00E6, 0x0041, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_text_button,
        &_draw_om_text_button,
        &_press_om_100khz_button
    },  // 100kHz button
    { 
        0x001E, 0x0073, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_text_button,
        &_draw_om_text_button,
        &_press_om_1v_button
    },  // 1V button
    { 
        0x0082, 0x0073, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_text_button,
        &_draw_om_text_button,
        &_press_om_2v_button
    },  // 2V button
    { 
        0x00E6, 0x0073, 0x003C, 0x0028, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_text_button,
        &_draw_om_text_button,
        &_press_om_3v_button
    },  // 3V button
    { 
        0x0064, 0x00A5, 0x0078, 0x003C, NOT_ACTIVE, NOT_ACTIVE,
        &_draw_om_text_button,
        &_draw_om_text_button,
        &_press_om_back_button
    },  // BACK button
};

void draw_options_menu(struct lcd_driver_t *driver)
{
    static const uint16_t bg_color = 0x00;
    struct _draw_params_t draw_params = {
        driver,
        NULL,
        0x4800,
        0xBB02,
        4,
        1,
        0xFFFF
    };
    
    // Background
    fill_rectangle(driver, 0x00, 0x00, driver->res_x, driver->res_y, bg_color);
    // sin wave button
    _options_menu_buttons[0].draw(&_options_menu_buttons[0], &draw_params);
    // triangle wave button
    _options_menu_buttons[1].draw(&_options_menu_buttons[1], &draw_params);
    // square wave button
    _options_menu_buttons[2].draw(&_options_menu_buttons[2], &draw_params);
    // 10Hz button
    draw_params.str = STR_10HZ;
    _options_menu_buttons[3].draw(&_options_menu_buttons[3], &draw_params);
    // 1kHz button
    draw_params.str = STR_1KHZ;
    _options_menu_buttons[4].draw(&_options_menu_buttons[4], &draw_params);
    // 100kHz button
    draw_params.str = STR_100KHZ;
    _options_menu_buttons[5].draw(&_options_menu_buttons[5], &draw_params);
    // 1V button
    draw_params.str = STR_1V;
    _options_menu_buttons[6].draw(&_options_menu_buttons[6], &draw_params);
    // 2V button
    draw_params.str = STR_2V;
    _options_menu_buttons[7].draw(&_options_menu_buttons[7], &draw_params);
    // 3V button
    draw_params.str = STR_3V;
    _options_menu_buttons[8].draw(&_options_menu_buttons[8], &draw_params);
    // BACK button
    draw_params.str = STR_BACK;
    draw_params.char_thickness = 2;
    _options_menu_buttons[9].draw(&_options_menu_buttons[9], &draw_params);
}

void scan_options_menu(struct lcd_driver_t *driver, uint16_t touched_x, uint16_t touched_y)
{
    static const uint16_t fill_color = 0xBB02;
    static const uint16_t outline_color = 0x4800;
    static const char *_button_strings[OPTIONS_MENU_BUTTONS_SIZE] = { 
        NULL, NULL, NULL,
        STR_10HZ, STR_1KHZ, STR_100KHZ,
        STR_1V, STR_2V, STR_3V,
        STR_BACK
    };
    static const uint8_t _button_char_thicknesses[OPTIONS_MENU_BUTTONS_SIZE] = {
        1, 1, 1,
        1, 1, 1,
        1, 1, 1,
        2,
    };
    static struct _draw_params_t draw_params = {
        NULL,
        NULL,
        0x4800,
        0xBB02,
        4,
        1,
        0xFFFF
    };
    static void *press_params[OPTIONS_MENU_BUTTONS_SIZE] = {
        NULL, NULL, NULL,
        NULL, NULL, NULL,
        NULL, NULL, NULL,
        NULL
    };
        
    draw_params.driver = driver;
    
    for (size_t i = 0; i < OPTIONS_MENU_BUTTONS_SIZE; ++i) {
        if ((touched_x >= _options_menu_buttons[i].start_x 
                && touched_x <= _options_menu_buttons[i].start_x + _options_menu_buttons[i].width)
                && (touched_y >= _options_menu_buttons[i].start_y 
                && touched_y <= _options_menu_buttons[i].start_y + _options_menu_buttons[i].height))
            ui_button_set_state(&_options_menu_buttons[i], ACTIVE);
        else
            ui_button_set_state(&_options_menu_buttons[i], NOT_ACTIVE);
    }
    
    for (size_t i = 0; i < OPTIONS_MENU_BUTTONS_SIZE; ++i) {
        if (_options_menu_buttons[i].state != _options_menu_buttons[i].prev_state) {
            draw_params.str = _button_strings[i];
            draw_params.char_thickness = _button_char_thicknesses[i];
            if (_options_menu_buttons[i].state == ACTIVE) {
                draw_params.fill_color = outline_color;
                draw_params.outline_color = fill_color;
                _options_menu_buttons[i].active(&_options_menu_buttons[i], &draw_params);
            } else {
                draw_params.fill_color = fill_color;
                draw_params.outline_color = outline_color;
                _options_menu_buttons[i].draw(&_options_menu_buttons[i], &draw_params);
            }
            
            if (_options_menu_buttons[i].prev_state == ACTIVE 
                    && _options_menu_buttons[i].state == NOT_ACTIVE) {
                _options_menu_buttons[i].press(&_options_menu_buttons[i], press_params[i]);
            }
        }
    }
}

static void _draw_om_text_button(struct ui_button_t *button, void *params_p)
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

static void _draw_om_figure_button(struct ui_button_t *button, void *params_p)
{
    struct _draw_params_t params = *((struct _draw_params_t *)params_p);
    
    fill_rectangle(params.driver, button->start_x, button->start_y,
            button->width, button->height, params.fill_color);
    draw_rectangle(params.driver, button->start_x, button->start_y,
            button->width, button->height, params.outline_color, params.outline_thickness);
}

static void _press_om_sin_wave_button(struct ui_button_t *button, void *param_p)
{
    osc_output_disable();
    g_wave_data = sine_wave;
    g_wave_size = SINE_SIZE;
    g_wave_changed = FBOOL0;
}

static void _press_om_tri_wave_button(struct ui_button_t *button, void *param_p)
{
    osc_output_disable();
    g_wave_data = tri_wave;
    g_wave_size = TRI_SIZE;
    g_wave_changed = FBOOL0;
}

static void _press_om_sq_wave_button(struct ui_button_t *button, void *param_p)
{
    osc_output_disable();
    g_wave_data = sq_wave;
    g_wave_size = SQ_SIZE;
    g_wave_changed = FBOOL0;
}

static void _press_om_10hz_button(struct ui_button_t *button, void *param_p)
{
    osc_output_disable();
    g_freq_setting = FREQ_SETTING_10HZ;
    g_wave_changed = FBOOL0;
}

static void _press_om_1khz_button(struct ui_button_t *button, void *param_p)
{
    osc_output_disable();
    g_freq_setting = FREQ_SETTING_1KHZ;
    g_wave_changed = FBOOL0;
}

static void _press_om_100khz_button(struct ui_button_t *button, void *param_p)
{    
    osc_output_disable();
    g_freq_setting = FREQ_SETTING_100KHZ;
    g_wave_changed = FBOOL0;
}

static void _press_om_1v_button(struct ui_button_t *button, void *param_p)
{
    
}

static void _press_om_2v_button(struct ui_button_t *button, void *param_p)
{
    
}

static void _press_om_3v_button(struct ui_button_t *button, void *param_p)
{
    
}

static void _press_om_back_button(struct ui_button_t *button, void *param_p)
{
    set_menu_scene(MAIN_MENU);
}
