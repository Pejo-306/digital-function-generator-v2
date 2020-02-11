#include "user-interface/user-interface.h"

#include <string.h>

#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/font8x8.h"

#define START   "START"
#define STOP    "STOP"
#define OPTIONS "OPTIONS"

struct menu_t main_menu_init(struct lcd_driver_t *driver)
{
    struct menu_t menu;
    
    menu.driver = driver;
    // background area
    graphic_area_init(&menu.areas[0], 0x00, driver->res_x, 0x00, driver->res_y);
    // start button
    graphic_area_init(&menu.areas[1], 0x64, 0xDC, 0x19, 0x4B);
    // stop button
    graphic_area_init(&menu.areas[2], 0x64, 0xDC, 0x5F, 0x91);
    // options button
    graphic_area_init(&menu.areas[3], 0x64, 0xDC, 0xA5, 0xD7);
    return menu;
}

void main_menu(struct menu_t *menu)
{
    static const uint16_t outline_color = 0x4800;
    static const uint16_t fill_color = 0xBB02;
    static const uint16_t bg_color = 0x00;
    static const uint8_t outline_thickness = 4;
    static const uint8_t char_thickness = 2;
    struct graphic_rectangle_t button_rect = { 
        0, 
        0, 
        get_area_width(&menu->areas[1]), 
        get_area_height(&menu->areas[1])
    };
    uint16_t offset_x, offset_y;
    
    area_fill(menu->driver, &menu->areas[0], bg_color);
    
    area_fill(menu->driver, &menu->areas[1], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[1], button_rect,
        outline_color, outline_thickness);
    offset_x = (button_rect.width - (strlen(START) * char_thickness * CHAR_WIDTH)) / 2 + 1;
    offset_y = (button_rect.height - (char_thickness * CHAR_HEIGHT)) / 2 + 1;
    area_draw_string(menu->driver, &menu->areas[1], offset_x, offset_y, 
        START, 0xFFFF, char_thickness);
    
    area_fill(menu->driver, &menu->areas[2], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[2], button_rect,
        outline_color, outline_thickness);
    offset_x = (button_rect.width - (strlen(STOP) * char_thickness * CHAR_WIDTH)) / 2 + 1;
    offset_y = (button_rect.height - (char_thickness * CHAR_HEIGHT)) / 2 + 1;
    area_draw_string(menu->driver, &menu->areas[2], offset_x, offset_y, 
        STOP, 0xFFFF, char_thickness);
    
    area_fill(menu->driver, &menu->areas[3], fill_color);
    area_draw_rectangle(menu->driver, &menu->areas[3], button_rect,
        outline_color, outline_thickness);
    offset_x = (button_rect.width - (strlen(OPTIONS) * char_thickness * CHAR_WIDTH)) / 2 + 1;
    offset_y = (button_rect.height - (char_thickness * CHAR_HEIGHT)) / 2 + 1;
    area_draw_string(menu->driver, &menu->areas[3], offset_x, offset_y, 
        OPTIONS, 0xFFFF, char_thickness);
}
