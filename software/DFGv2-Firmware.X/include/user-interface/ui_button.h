/* 
 * File:   ui_button.h
 * Author: pesho
 *
 * Created on February 21, 2020, 4:33 PM
 */

#ifndef UI_BUTTON_H
#define	UI_BUTTON_H

#include <inttypes.h>

#include "lcd-driver/lcd-driver.h"

#ifdef	__cplusplus
extern "C" {
#endif

enum button_state { ACTIVE, NOT_ACTIVE };
    
struct ui_button_t {
    uint16_t start_x;
    uint16_t start_y;
    uint16_t width;
    uint16_t height;
    enum button_state prev_state;
    enum button_state state;
    
    void (*draw)(struct ui_button_t *, void *);
    void (*active)(struct ui_button_t *, void *);
    void (*press)(struct ui_button_t *, void *);
};

void ui_button_set_state(struct ui_button_t *, enum button_state);

#ifdef	__cplusplus
}
#endif

#endif	/* UI_BUTTON_H */

