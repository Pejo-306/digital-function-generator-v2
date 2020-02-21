#include "user-interface/user-interface.h"

#include <string.h>

#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/font8x8.h"
#include "lcd-driver/graphics.h"
#include "user-interface/ui_button.h"

#define STR_START       "START"
#define STR_STOP        "STOP"
#define STR_OPTIONS     "OPTIONS"
#define STR_10HZ        "10Hz"
#define STR_1KHZ        "1kHz"
#define STR_100KHZ      "100kHz"
#define STR_1V          "1V"
#define STR_2V          "2V"
#define STR_3V          "3V"
#define STR_BACK        "BACK"

static void draw_mm_start_button(struct ui_button_t *, struct lcd_driver_t *);

static void active_mm_start_button(struct ui_button_t *, struct lcd_driver_t *);

static void draw_mm_stop_button(struct ui_button_t *, struct lcd_driver_t *);

static void active_mm_stop_button(struct ui_button_t *, struct lcd_driver_t *);

static void draw_mm_options_button(struct ui_button_t *, struct lcd_driver_t *);

static void active_mm_options_button(struct ui_button_t *, struct lcd_driver_t *);

struct ui_button_t main_menu_buttons[] = {
    { 
        0x64, 0x19, 0x78, 0x32, NOT_ACTIVE, NOT_ACTIVE,
        &draw_mm_start_button, &active_mm_start_button 
    },  // START button
    { 
        0x64, 0x5F, 0x78, 0x32, NOT_ACTIVE, NOT_ACTIVE,
        &draw_mm_stop_button, &active_mm_stop_button
    },  // STOP button
    { 
        0x64, 0xA5, 0x78, 0x32, NOT_ACTIVE, NOT_ACTIVE,
        &draw_mm_options_button, &active_mm_options_button 
    },  // OPTIONS button
};

static uint16_t horizontal_str_offset(const char *, uint16_t, uint8_t);

static uint16_t vertical_str_offset(const char *, uint16_t, uint8_t);

void draw_main_menu(struct lcd_driver_t *driver)
{
    static const uint16_t bg_color = 0x00;
    
    // Background
    fill_rectangle(driver, 0x00, 0x00, driver->res_x, driver->res_y, bg_color);
    // START button
    (*main_menu_buttons[0].draw)(&main_menu_buttons[0], driver);
    // STOP button
    (*main_menu_buttons[1].draw)(&main_menu_buttons[1], driver);
    // OPTIONS button
    (*main_menu_buttons[2].draw)(&main_menu_buttons[2], driver);
}

void scan_main_menu(struct lcd_driver_t *driver, uint16_t touched_x, uint16_t touched_y)
{
    for (size_t i = 0; i < MAIN_MENU_BUTTONS_SIZE; ++i) {
        if ((touched_x >= main_menu_buttons[i].start_x 
                && touched_x <= main_menu_buttons[i].start_x + main_menu_buttons[i].width)
                && (touched_y >= main_menu_buttons[i].start_y 
                && touched_y <= main_menu_buttons[i].start_y + main_menu_buttons[i].height))
            ui_button_set_state(&main_menu_buttons[i], ACTIVE);
        else
            ui_button_set_state(&main_menu_buttons[i], NOT_ACTIVE);
    }
    for (size_t i = 0; i < MAIN_MENU_BUTTONS_SIZE; ++i) {
        if (main_menu_buttons[i].state != main_menu_buttons[i].prev_state) {
            if (main_menu_buttons[i].state == ACTIVE)
                main_menu_buttons[i].active(&main_menu_buttons[i], driver);
            else
                main_menu_buttons[i].draw(&main_menu_buttons[i], driver);
        }
    }
}

// void draw_options_menu(struct lcd_driver_t *driver);

/*
struct menu_t options_menu_init(struct lcd_driver_t *driver)
{
    struct menu_t menu;
    
    menu.driver = driver;
    // background area
    graphic_area_init(&menu.areas[0], 0x00, driver->res_x, 0x00, driver->res_y);
    // sin wave button
    graphic_area_init(&menu.areas[1], 0x001E, 0x005A, 0x000F, 0x0037);
    // triangle wave button
    graphic_area_init(&menu.areas[2], 0x0082, 0x00BE, 0x000F, 0x0037);
    // square wave button
    graphic_area_init(&menu.areas[3], 0x00E6, 0x0122, 0x000F, 0x0037);
    // 10 Hz button
    graphic_area_init(&menu.areas[4], 0x001E, 0x005A, 0x0041, 0x0069);
    // 1 kHz button
    graphic_area_init(&menu.areas[5], 0x0082, 0x00BE, 0x0041, 0x0069);
    // 100 kHz button
    graphic_area_init(&menu.areas[6], 0x00E6, 0x0122, 0x0041, 0x0069);
    // 1 V button
    graphic_area_init(&menu.areas[7], 0x001E, 0x005A, 0x0073, 0x009B);
    // 2 V button
    graphic_area_init(&menu.areas[8], 0x0082, 0x00BE, 0x0073, 0x009B);
    // 3 V button
    graphic_area_init(&menu.areas[9], 0x00E6, 0x0122, 0x0073, 0x009B);
    // BACK button
    graphic_area_init(&menu.areas[10], 0x0064, 0x00DC, 0x00A5, 0x00E1);
    return menu;
}

void draw_options_menu(struct menu_t *menu)
{
    static const uint16_t outline_color = 0x4800;
    static const uint16_t fill_color = 0xBB02;
    static const uint16_t bg_color = 0x00;
    static const uint8_t outline_thickness = 4;
    struct graphic_rectangle_t small_button_rect = { 
        0, 
        0, 
        get_area_width(&menu->areas[1]),
        get_area_height(&menu->areas[1])
    };
    struct graphic_rectangle_t button_rect = { 
        0, 
        0, 
        get_area_width(&menu->areas[10]), 
        get_area_height(&menu->areas[10])
    };

    // Background
    area_fill(menu->driver, &menu->areas[0], bg_color);
    
    // sin wave button
    area_fill(menu->driver, &menu->areas[1], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[1], small_button_rect,
        outline_color, outline_thickness);
    // TODO: area_draw_figure
    
    // triangle wave button
    area_fill(menu->driver, &menu->areas[2], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[2], small_button_rect,
        outline_color, outline_thickness);
    // TODO: area_draw_figure
    
    // square wave button
    area_fill(menu->driver, &menu->areas[3], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[3], small_button_rect,
        outline_color, outline_thickness);
    // TODO: area_draw_figure
    
    // 10 Hz button
    area_fill(menu->driver, &menu->areas[4], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[4], small_button_rect,
        outline_color, outline_thickness);
    area_draw_string(menu->driver, &menu->areas[4],
        horizontal_str_offset(STR_10HZ, small_button_rect.width, 1),
        vertical_str_offset(STR_10HZ, small_button_rect.height, 1), 
        STR_10HZ, 0xFFFF, 1);
    
    // 1 kHz button
    area_fill(menu->driver, &menu->areas[5], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[5], small_button_rect,
        outline_color, outline_thickness);
    area_draw_string(menu->driver, &menu->areas[5],
        horizontal_str_offset(STR_1KHZ, small_button_rect.width, 1),
        vertical_str_offset(STR_1KHZ, small_button_rect.height, 1), 
        STR_1KHZ, 0xFFFF, 1);
    
    // 100 kHz button
    area_fill(menu->driver, &menu->areas[6], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[6], small_button_rect,
        outline_color, outline_thickness);
    area_draw_string(menu->driver, &menu->areas[6],
        horizontal_str_offset(STR_100KHZ, small_button_rect.width, 1),
        vertical_str_offset(STR_100KHZ, small_button_rect.height, 1), 
        STR_100KHZ, 0xFFFF, 1);
    
    // 1 V button
    area_fill(menu->driver, &menu->areas[7], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[7], small_button_rect,
        outline_color, outline_thickness);
    area_draw_string(menu->driver, &menu->areas[7],
        horizontal_str_offset(STR_1V, small_button_rect.width, 1),
        vertical_str_offset(STR_1V, small_button_rect.height, 1), 
        STR_1V, 0xFFFF, 1);
    
    // 2 V button
    area_fill(menu->driver, &menu->areas[8], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[8], small_button_rect,
        outline_color, outline_thickness);
    area_draw_string(menu->driver, &menu->areas[8],
        horizontal_str_offset(STR_2V, small_button_rect.width, 1),
        vertical_str_offset(STR_2V, small_button_rect.height, 1), 
        STR_2V, 0xFFFF, 1);
    
    // 3 V button
    area_fill(menu->driver, &menu->areas[9], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[9], small_button_rect,
        outline_color, outline_thickness);
    area_draw_string(menu->driver, &menu->areas[9],
        horizontal_str_offset(STR_3V, small_button_rect.width, 1),
        vertical_str_offset(STR_3V, small_button_rect.height, 1), 
        STR_3V, 0xFFFF, 1);
    
    // BACK button
    area_fill(menu->driver, &menu->areas[10], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[10], button_rect,
        outline_color, outline_thickness);
    area_draw_string(menu->driver, &menu->areas[10],
        horizontal_str_offset(STR_BACK, button_rect.width, 2),
        vertical_str_offset(STR_BACK, button_rect.height, 2),
        STR_BACK, 0xFFFF, 2);
}
*/

static void draw_mm_start_button(struct ui_button_t *button, struct lcd_driver_t *driver)
{
    static const uint16_t outline_color = 0x4800;
    static const uint16_t fill_color = 0xBB02;
    static const uint8_t outline_thickness = 4;
    static const uint8_t char_thickness = 2;
    static const uint16_t string_color = 0xFFFF;
    
    fill_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, fill_color);
    draw_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, outline_color, outline_thickness);
    draw_string(driver, 
        button->start_x + horizontal_str_offset(STR_START, button->width, char_thickness),
        button->start_y + vertical_str_offset(STR_START, button->height, char_thickness), 
        STR_START, string_color, char_thickness);
}

static void active_mm_start_button(struct ui_button_t *button, struct lcd_driver_t *driver)
{
    static const uint16_t outline_color = 0xBB02;
    static const uint16_t fill_color = 0x4800;
    static const uint8_t outline_thickness = 4;
    static const uint8_t char_thickness = 2;
    static const uint16_t string_color = 0xFFFF;
    
    fill_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, fill_color);
    draw_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, outline_color, outline_thickness);
    draw_string(driver, 
        button->start_x + horizontal_str_offset(STR_START, button->width, char_thickness),
        button->start_y + vertical_str_offset(STR_START, button->height, char_thickness), 
        STR_START, string_color, char_thickness);
}

static void draw_mm_stop_button(struct ui_button_t *button, struct lcd_driver_t *driver)
{
    static const uint16_t outline_color = 0x4800;
    static const uint16_t fill_color = 0xBB02;
    static const uint8_t outline_thickness = 4;
    static const uint8_t char_thickness = 2;
    static const uint16_t string_color = 0xFFFF;
    
    fill_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, fill_color);
    draw_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, outline_color, outline_thickness);
    draw_string(driver, 
        button->start_x + horizontal_str_offset(STR_STOP, button->width, char_thickness),
        button->start_y + vertical_str_offset(STR_STOP, button->height, char_thickness), 
        STR_STOP, string_color, char_thickness);
}

static void active_mm_stop_button(struct ui_button_t *button, struct lcd_driver_t *driver)
{
    static const uint16_t outline_color = 0xBB02;
    static const uint16_t fill_color = 0x4800;
    static const uint8_t outline_thickness = 4;
    static const uint8_t char_thickness = 2;
    static const uint16_t string_color = 0xFFFF;
    
    fill_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, fill_color);
    draw_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, outline_color, outline_thickness);
    draw_string(driver, 
        button->start_x + horizontal_str_offset(STR_STOP, button->width, char_thickness),
        button->start_y + vertical_str_offset(STR_STOP, button->height, char_thickness), 
        STR_STOP, string_color, char_thickness);
}

static void draw_mm_options_button(struct ui_button_t *button, struct lcd_driver_t *driver)
{
    static const uint16_t outline_color = 0x4800;
    static const uint16_t fill_color = 0xBB02;
    static const uint8_t outline_thickness = 4;
    static const uint8_t char_thickness = 2;
    static const uint16_t string_color = 0xFFFF;
    
    fill_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, fill_color);
    draw_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, outline_color, outline_thickness);
    draw_string(driver, 
        button->start_x + horizontal_str_offset(STR_OPTIONS, button->width, char_thickness),
        button->start_y + vertical_str_offset(STR_OPTIONS, button->height, char_thickness), 
        STR_OPTIONS, string_color, char_thickness);
}

static void active_mm_options_button(struct ui_button_t *button, struct lcd_driver_t *driver)
{
    static const uint16_t outline_color = 0xBB02;
    static const uint16_t fill_color = 0x4800;
    static const uint8_t outline_thickness = 4;
    static const uint8_t char_thickness = 2;
    static const uint16_t string_color = 0xFFFF;
    
    fill_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, fill_color);
    draw_rectangle(driver, button->start_x, button->start_y,
            button->width, button->height, outline_color, outline_thickness);
    draw_string(driver, 
        button->start_x + horizontal_str_offset(STR_OPTIONS, button->width, char_thickness),
        button->start_y + vertical_str_offset(STR_OPTIONS, button->height, char_thickness), 
        STR_OPTIONS, string_color, char_thickness);
}

static uint16_t horizontal_str_offset(const char *str, uint16_t width, uint8_t thickness)
{
    return (width - (strlen(str) * thickness * CHAR_WIDTH)) / 2 + 1;
}

static uint16_t vertical_str_offset(const char *str, uint16_t height, uint8_t thickness)
{
    return (height - (thickness * CHAR_HEIGHT)) / 2 + 1;
}
