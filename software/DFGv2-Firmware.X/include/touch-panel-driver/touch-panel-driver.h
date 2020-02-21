/* 
 * File:   touch-panel-driver.h
 * Author: pesho
 *
 * Created on February 13, 2020, 12:52 PM
 */

#ifndef TOUCH_PANEL_DRIVER_H
#define	TOUCH_PANEL_DRIVER_H

#include <inttypes.h>
#include <avr/io.h>

#include "defs.h"
#include "touch-panel-driver/touch-panel-driver-chip.h"
#include "lcd-driver/lcd-driver.h"

#define SAMPLES 10

#define XFAC    663
#define XOFFSET -13
#define YFAC    894
#define YOFFSET -30

// deselect the Touch Panel driver (output a HIGH level to Chip Select)
#define _tcs_high(touch_driver) { \
    *touch_driver->tcs.port |= (1 << touch_driver->tcs.pin); \
}
    
// select the Touch Panel driver (output a LOW level to Chip Select)
#define _tcs_low(touch_driver) { \
    *touch_driver->tcs.port &= ~(1 << touch_driver->tcs.pin); \
}

// get the state of the Pen Interrupt output
#define _tirq_state(touch_driver) (*touch_driver->tirq.port & _BV(touch_driver->tirq.pin))

#ifdef	__cplusplus
extern "C" {
#endif
    
struct touch_driver_t {
    struct spi_interface_t *spi;  // SPI interface
    struct pin_ref_t tcs;  // Chip Select
    struct pin_ref_t tirq;  // Pen Interrupt
};

void touch_driver_init(struct touch_driver_t *, fbool);

uint16_t touch_read_x(struct touch_driver_t *);

uint16_t touch_read_y(struct touch_driver_t *);

short touch_scan(struct touch_driver_t *, uint16_t *, uint16_t *);

void touch_get_screen_coordinates(struct lcd_driver_t *, uint16_t *, uint16_t *);

#ifdef	__cplusplus
}
#endif

#endif	/* TOUCH_PANEL_DRIVER_H */

