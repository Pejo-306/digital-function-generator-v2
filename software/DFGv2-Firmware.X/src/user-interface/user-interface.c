#include "user-interface/user-interface.h"

#include <string.h>

#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/font8x8.h"
#include "lcd-driver/graphics.h"
#include "user-interface/ui_button.h"

#define STR_10HZ        "10Hz"
#define STR_1KHZ        "1kHz"
#define STR_100KHZ      "100kHz"
#define STR_1V          "1V"
#define STR_2V          "2V"
#define STR_3V          "3V"
#define STR_BACK        "BACK"


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


