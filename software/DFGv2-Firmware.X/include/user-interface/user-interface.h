/* 
 * File:   user-interface.h
 * Author: pesho
 *
 * Created on February 11, 2020, 6:01 PM
 */

#ifndef USER_INTERFACE_H
#define	USER_INTERFACE_H

#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/graphics.h"

#define MAX_AREAS 16

#ifdef	__cplusplus
extern "C" {
#endif

struct menu_t {
    struct lcd_driver_t *driver;
    struct graphic_area_t areas[MAX_AREAS];
};

struct menu_t main_menu_init(struct lcd_driver_t *);

void draw_main_menu(struct menu_t *);

struct menu_t options_menu_init(struct lcd_driver_t *);

void draw_options_menu(struct menu_t *);

#ifdef	__cplusplus
}
#endif

#endif	/* USER_INTERFACE_H */

