/* 
 * File:   ui_main_menu.h
 * Author: pesho
 *
 * Created on February 21, 2020, 7:26 PM
 */

#ifndef UI_MAIN_MENU_H
#define	UI_MAIN_MENU_H

#include <inttypes.h>

#include "lcd-driver/lcd-driver.h"

#ifdef	__cplusplus
extern "C" {
#endif

void draw_main_menu(struct lcd_driver_t *);

void scan_main_menu(struct lcd_driver_t *, uint16_t, uint16_t);

#ifdef	__cplusplus
}
#endif

#endif	/* UI_MAIN_MENU_H */

