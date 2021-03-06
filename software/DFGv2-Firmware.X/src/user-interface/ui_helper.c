#include "user-interface/ui_helper.h"

#include <inttypes.h>
#include <string.h>

#include "lcd-driver/font8x8.h"

enum menu_scene g_current_menu_scene = MAIN_MENU;

void set_menu_scene(enum menu_scene menu)
{
    g_current_menu_scene = menu;
}

uint16_t _horizontal_str_offset(const char *str, uint16_t width, uint8_t thickness)
{
    return (width - (strlen(str) * thickness * CHAR_WIDTH)) / 2 + 1;
}

uint16_t _vertical_str_offset(const char *str, uint16_t height, uint8_t thickness)
{
    return (height - (thickness * CHAR_HEIGHT)) / 2 + 1;
}
