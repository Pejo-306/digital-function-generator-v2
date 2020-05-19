/* 
 * File:   graphics.h
 * Author: pesho
 *
 * Created on January 31, 2020, 3:39 PM
 */

#ifndef GRAPHICS_H
#define	GRAPHICS_H

#include <inttypes.h>

#include "defs.h"
#include "lcd-driver/lcd-driver.h"

#ifdef	__cplusplus
extern "C" {
#endif

void draw_pixel(struct lcd_driver_t *, uint16_t, uint16_t, uint16_t);

void fill_rectangle(struct lcd_driver_t *, uint16_t, uint16_t, uint16_t, uint16_t, 
        uint16_t);

void draw_rectangle(struct lcd_driver_t *, uint16_t, uint16_t, uint16_t, uint16_t, 
        uint16_t, uint8_t);

void draw_figure(struct lcd_driver_t *, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t *);

void draw_figure_pgm(struct lcd_driver_t *, uint16_t, uint16_t, uint16_t, uint16_t, const uint16_t *);

/*
void draw_figure2_pgm(struct lcd_driver_t *, uint16_t, uint16_t, uint16_t, uint16_t, 
        const uint16_t *, const uint8_t *);
*/

void draw_char(struct lcd_driver_t *, uint16_t, uint16_t, unsigned char, 
        uint16_t, uint16_t, uint8_t, fbool);

void draw_string(struct lcd_driver_t *, uint16_t, uint16_t, const char *,
        uint16_t, uint16_t, uint8_t, fbool);

#ifdef	__cplusplus
}
#endif

#endif	/* GRAPHICS_H */

