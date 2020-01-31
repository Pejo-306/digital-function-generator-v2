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

void draw_pixel(struct lcd_driver_t *, uint16_t);

#ifdef	__cplusplus
}
#endif

#endif	/* GRAPHICS_H */

