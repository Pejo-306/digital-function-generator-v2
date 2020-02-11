/* 
 * File:   graphics.h
 * Author: pesho
 *
 * Created on January 31, 2020, 3:39 PM
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H

#include "lcd-driver/lcd-driver.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
struct graphic_area_t {
    uint16_t sc;  // starting column
    uint16_t ec;  // ending column
    uint16_t sp;  // starting page
    uint16_t ep;  // ending page
};

struct graphic_rectangle_t {
    uint16_t start_x;  // offset against area SC
    uint16_t start_y;  // offset against area SP
    uint16_t width;
    uint16_t height;
};

void graphic_area_init(struct graphic_area_t *, 
        uint16_t, uint16_t, uint16_t, uint16_t);

uint16_t get_area_width(struct graphic_area_t *);

uint16_t get_area_height(struct graphic_area_t *);

void area_draw_pixel(struct lcd_driver_t *, struct graphic_area_t *,
        uint16_t, uint16_t, uint16_t);

void area_fill(struct lcd_driver_t *, struct graphic_area_t *, uint16_t);

void area_draw_rectangle(struct lcd_driver_t *, struct graphic_area_t *,
        struct graphic_rectangle_t, uint16_t, uint8_t);

void area_fill_rectangle(struct lcd_driver_t *, struct graphic_area_t *,
        struct graphic_rectangle_t, uint16_t);

void area_draw_figure(struct lcd_driver_t *, struct graphic_area_t *,
        uint16_t, uint16_t, uint16_t, uint16_t, uint16_t *);

void area_draw_char(struct lcd_driver_t *, struct graphic_area_t *,
        uint16_t, uint16_t, unsigned char, uint16_t, uint8_t);

void area_draw_string(struct lcd_driver_t *, struct graphic_area_t *,
        uint16_t, uint16_t, const char *, uint16_t, uint8_t);

#ifdef	__cplusplus
}
#endif

#endif	/* GRAPHICS_H */

