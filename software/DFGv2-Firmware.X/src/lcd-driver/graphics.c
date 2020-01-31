#include "lcd-driver/graphics.h"

#include <inttypes.h>

#include "lcd-driver/lcd-driver.h"

void draw_pixel(struct lcd_driver_t *driver, uint16_t color)
{
    lcd_memory_write(driver, &color, 1);
    for (uint32_t i = 0; i < 76800 / 2; ++i) {
        lcd_memory_write_continue(driver, &color, 1);
    }
}
