/* 
 * File:   lcd-driver.h
 * Author: pesho
 *
 * Created on January 28, 2020, 9:14 PM
 */

#ifndef LCD_DRIVER_H
#define	LCD_DRIVER_H

#include "defs.h"
#include "lcd-driver/lcd-driver-chip.h"
#include "avr_controllers/spi_controller.h"

#ifdef	__cplusplus
extern "C" {
#endif

// send a data byte via the D/CX line
#define _dcx_data(lcd_driver) { \
    *lcd_driver->dcx.port |= (1 << lcd_driver->dcx.pin); \
}
    
// send a command byte via the D/CX line
#define _dcx_command(lcd_driver) { \
    *lcd_driver->dcx.port &= ~(1 << lcd_driver->dcx.pin); \
}
    
// deselect the LCD driver (output a HIGH level to Chip Select)
#define _csx_high(lcd_driver) { \
    *lcd_driver->csx.port |= (1 << lcd_driver->csx.pin); \
}
    
// select the LCD driver (output a LOW level to Chip Select)
#define _csx_low(lcd_driver) { \
    *lcd_driver->csx.port &= ~(1 << lcd_driver->csx.pin); \
}

// output a HIGH level to the RESET line
#define _reset_high(lcd_driver) { \
    *lcd_driver->reset.port |= (1 << lcd_driver->reset.pin); \
}
    
// output a LOW level to the RESET line
#define _reset_low(lcd_driver) { \
    *lcd_driver->reset.port &= ~(1 << lcd_driver->reset.pin); \
}
    
struct lcd_driver_t {
    struct spi_interface_t spi;  // SPI interface
    struct pin_ref_t dcx;  // Data/Command
    struct pin_ref_t reset;  // Reset
    struct pin_ref_t csx;  // Chip Select
};

void lcd_driver_init(struct lcd_driver_t *, fbool);

void lcd_nop(struct lcd_driver_t *);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_DRIVER_H */
