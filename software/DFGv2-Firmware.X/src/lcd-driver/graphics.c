#include "lcd-driver/graphics.h"

#include <inttypes.h>
#include <string.h>
#include <avr/pgmspace.h>

#include "defs.h"
#include "lcd-driver/font8x8.h"
#include "lcd-driver/lcd-driver.h"

void draw_pixel(struct lcd_driver_t *driver, uint16_t x, uint16_t y, uint16_t color)
{
    // TODO: error checking for coordinates
    lcd_column_address_set(driver, x, x);
    lcd_page_address_set(driver, y, y);
    lcd_memory_write(driver, &color, 1);
}

void fill_rectangle(struct lcd_driver_t *driver, uint16_t start_x, uint16_t start_y, 
        uint16_t width, uint16_t height, uint16_t color)
{
    lcd_column_address_set(driver, start_x, start_x + width - 1);
    lcd_page_address_set(driver, start_y, start_y + height - 1);
    lcd_memory_write_optimized(driver, color, (uint32_t)width * height);
}

void draw_rectangle(struct lcd_driver_t *driver, uint16_t start_x, uint16_t start_y, 
        uint16_t width, uint16_t height, uint16_t color, uint8_t thickness)
{
    // draw top and bottom sides
    lcd_column_address_set(driver, start_x, start_x + width - 1);
    lcd_page_address_set(driver, start_y, start_y + thickness - 1);
    lcd_memory_write_optimized(driver, color, (uint32_t)width * thickness);
    lcd_page_address_set(driver, start_y + height - thickness, start_y + height);
    lcd_memory_write_optimized(driver, color, (uint32_t)width * thickness);
    
    // draw left and right sides
    lcd_column_address_set(driver, start_x, start_x + thickness - 1);
    lcd_page_address_set(driver, start_y + thickness, start_y + height - thickness);
    lcd_memory_write_optimized(driver, color, ((uint32_t)height * thickness) - 2 * thickness);
    lcd_column_address_set(driver, start_x + width - thickness, start_x + width - 1);
    lcd_memory_write_optimized(driver, color, ((uint32_t)height * thickness) - 2 * thickness);
}

void draw_figure(struct lcd_driver_t *driver, uint16_t start_x, uint16_t start_y, 
        uint16_t width, uint16_t height, uint16_t *pixels)
{
    // TODO: error checking
    lcd_column_address_set(driver, start_x, start_x + width - 1);
    lcd_page_address_set(driver, start_y, start_y + height - 1);
    lcd_memory_write(driver, pixels, width * height);
}

void draw_char(struct lcd_driver_t *driver, uint16_t start_x, uint16_t start_y, 
        unsigned char ch, uint16_t color, uint16_t bg_color, uint8_t thickness, fbool options)
{
    /* fbool options:
     * bit 0: add background color to character
     * bits 1-7: not used
     */
    uint8_t row;
    
    for (short i = 0; i < CHAR_HEIGHT; ++i) {
        row = pgm_read_byte(&font[ch][i]);
        for (short j = 0; j < CHAR_WIDTH; ++j) {
            if (row & (1 << j)) {
                if (thickness == 1) {
                    draw_pixel(driver, start_x + j, start_y + i, color);
                } else {
                    fill_rectangle(driver, start_x + j * thickness, start_y + i * thickness, 
                            thickness, thickness, color);
                }
            } else if (options & FBOOL0) {
                if (thickness == 1) {
                    draw_pixel(driver, start_x + j, start_y + i, bg_color);
                } else {
                    fill_rectangle(driver, start_x + j * thickness, start_y + i * thickness, 
                            thickness, thickness, bg_color);
                }
            }
        }
    }
}

void draw_string(struct lcd_driver_t *driver, uint16_t start_x, uint16_t start_y, 
        const char *str, uint16_t color, uint16_t bg_color, uint8_t thickness, fbool options)
{
    /* fbool options:
     * bit 0: add background color to string
     * bits 1-7: not used
     */
    for (short i = 0; i < strlen(str); ++i)
        draw_char(driver, start_x + CHAR_WIDTH * i * thickness, start_y, 
                str[i], color, bg_color, thickness, options);
}
