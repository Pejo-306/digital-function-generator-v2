/* 
 * File:   user-interface.h
 * Author: pesho
 *
 * Created on February 11, 2020, 6:01 PM
 */

#ifndef USER_INTERFACE_H
#define	USER_INTERFACE_H

#include <inttypes.h>

#include "lcd-driver/lcd-driver.h"
#include "user-interface/ui_button.h"

#define MAIN_MENU_BUTTONS_SIZE 3

#ifdef	__cplusplus
extern "C" {
#endif

extern struct ui_button_t main_menu_buttons[MAIN_MENU_BUTTONS_SIZE];

void draw_main_menu(struct lcd_driver_t *);

void scan_main_menu(struct lcd_driver_t *, uint16_t, uint16_t);

void draw_options_menu(struct lcd_driver_t *);

#ifdef	__cplusplus
}
#endif

#endif	/* USER_INTERFACE_H */

