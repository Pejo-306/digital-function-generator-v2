#include "lcd-driver/graphics.h"

#include <inttypes.h>
#include <string.h>
#include <avr/pgmspace.h>

#include "lcd-driver/font8x8.h"
#include "lcd-driver/lcd-driver.h"

void graphic_area_init(struct graphic_area_t *area,
        uint16_t sc, uint16_t ec, uint16_t sp, uint16_t ep)
{
    area->sc = sc;
    area->ec = ec;
    area->sp = sp;
    area->ep = ep;
}

uint16_t get_area_width(struct graphic_area_t *area)
{
    return area->ec - area->sc;
}

uint16_t get_area_height(struct graphic_area_t *area)
{
    return area->ep - area->sp;
}

void area_draw_pixel(struct lcd_driver_t *driver, struct graphic_area_t *area, 
        uint16_t offx, uint16_t offy, uint16_t color)
{
    // TODO: error checking for coordinates
    lcd_column_address_set(driver, area->sc + offx, area->sc + offx);
    lcd_page_address_set(driver, area->sp + offy, area->sp + offy);
    lcd_memory_write(driver, &color, 1);
}

void area_fill(struct lcd_driver_t *driver, struct graphic_area_t *area,
        uint16_t color)
{
    /*
    lcd_column_address_set(driver, area->sc, area->ec);
    lcd_page_address_set(driver, area->sp, area->ep);
    // the first write operation must be a 'write_memory_start'
    // in order to set the value of the column register to 'SC'
    // and the value of the page register to 'SP'
    lcd_memory_write(driver, &color, 1);
    for (uint16_t i = area->sp; i <= area->ep; ++i) {
        for (uint16_t j = area->sc; j <= area->ec; ++j) {
            if (i == area->sp && j == area->sc) continue;  // skip first pixel
            lcd_memory_write_continue(driver, &color, 1);
        }
    }
    */
    struct graphic_rectangle_t area_rect = { 
        0, 
        0, 
        get_area_width(area), 
        get_area_height(area) 
    };
    
    area_fill_rectangle(driver, area, area_rect, color);
}

void area_draw_rectangle(struct lcd_driver_t *driver, struct graphic_area_t *area,
        struct graphic_rectangle_t rect, uint16_t color, uint8_t thickness)
{
    lcd_memory_write(driver, &color, 1);
    for (uint16_t i = 0; i < rect.height; ++i) {
        for (uint16_t j = 0; j < rect.width; ++j) {
            if (i >= thickness && i < rect.height - thickness 
                    && j >= thickness && j < rect.width - thickness)
                continue;
            lcd_column_address_set(driver, 
                    area->sc + rect.start_x + j, area->sc + rect.start_x + j);
            lcd_page_address_set(driver, 
                    area->sp + rect.start_y + i, area->sp + rect.start_y + i);
            lcd_memory_write(driver, &color, 1);
        }
    }
}

void area_fill_rectangle(struct lcd_driver_t *driver, struct graphic_area_t *area,
        struct graphic_rectangle_t rect, uint16_t color)
{
    lcd_column_address_set(driver,
            area->sc + rect.start_x, area->sc + rect.start_x + rect.width - 1);
    lcd_page_address_set(driver,
            area->sp + rect.start_y, area->sp + rect.start_y + rect.height - 1);
    // the first write operation must be a 'write_memory_start'
    // in order to set the value of the column register to 'SC'
    // and the value of the page register to 'SP'
    lcd_memory_write(driver, &color, 1);
    for (uint16_t i = 0; i < rect.height; ++i) {
        for (uint16_t j = 0; j < rect.width; ++j) {
            if (i == 0 && j == 0) continue;  // skip first pixel
            lcd_memory_write_continue(driver, &color, 1);
        }
    }
}

void area_draw_figure(struct lcd_driver_t *driver, struct graphic_area_t *area,
        uint16_t offx, uint16_t offy, uint16_t width, uint16_t height, uint16_t *pixels)
{
    // TODO: error checking
    lcd_column_address_set(driver, area->sc + offx, area->sc + offx + width - 1);
    lcd_page_address_set(driver, area->sp + offy, area->sp + offy + height - 1);
    lcd_memory_write(driver, pixels, width * height);
}

void area_draw_char(struct lcd_driver_t *driver, struct graphic_area_t *area,
        uint16_t offx, uint16_t offy, unsigned char ch, uint16_t color, uint8_t thickness)
{
    uint8_t row;
    struct graphic_rectangle_t pixel_rect;
    
    for (short i = 0; i < CHAR_HEIGHT; ++i) {
        row = pgm_read_byte(&font[ch][i]);
        for (short j = 0; j < CHAR_WIDTH; ++j) {
            if (row & (1 << j)) {
                if (thickness == 1) {
                    area_draw_pixel(driver, area, offx + j, offy + i, color);
                } else {
                    pixel_rect.start_x = offx + j * thickness;
                    pixel_rect.start_y = offy + i * thickness;
                    pixel_rect.width = thickness;
                    pixel_rect.height = thickness;
                    area_fill_rectangle(driver, area, pixel_rect, color);
                }
            }
        }
    }
}

void area_draw_string(struct lcd_driver_t *driver, struct graphic_area_t *area,
        uint16_t offx, uint16_t offy, const char *str, uint16_t color, uint8_t thickness)
{
    for (short i = 0; i < strlen(str); ++i)
        area_draw_char(driver, area, offx + CHAR_WIDTH * i * thickness, offy, 
                str[i], color, thickness);
}