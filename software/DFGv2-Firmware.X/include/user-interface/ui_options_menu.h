/* 
 * File:   ui_options_menu.h
 * Author: pesho
 *
 * Created on February 21, 2020, 9:18 PM
 */

#ifndef UI_OPTIONS_MENU_H
#define	UI_OPTIONS_MENU_H

#include <inttypes.h>

#include "lcd-driver/lcd-driver.h"

#ifdef	__cplusplus
extern "C" {
#endif

void draw_options_menu(struct lcd_driver_t *);

void scan_options_menu(struct lcd_driver_t *, uint16_t, uint16_t);

#ifdef	__cplusplus
}
#endif

#endif	/* UI_OPTIONS_MENU_H */

