/*
 * File:   main.c
 * Author: pesho
 *
 * Created on January 25, 2020, 6:47 PM
 */

#include <util/delay.h>

#include "defs.h"
#include "init_mcu.h"
#include "avr_controllers/twi_controller.h"
#include "avr_controllers/spi_controller.h"
#include "lcd-driver/lcd-driver.h"
#include "touch-panel-driver/touch-panel-driver.h"
#include "user-interface/ui_helper.h"
#include "user-interface/ui_main_menu.h"
#include "user-interface/ui_options_menu.h"
#include "DFG-firmware/DDS_firmware.h"
#include "DFG-firmware/IOexpander_driver.h"
#include "DFG-firmware/programmable_oscillator_driver.h"

int main(void)
{       
    // initialize MCU
    init_mcu();
    twi_init();
    twi_set_speed(TWI_400KHZ, 0);
    twi_set_slave_address(0x00);
    
    // reset MCP23017
    ioex_reset();

    // initialize programmable oscillator (DS1085)
    osc_conf_mux_word(U8_TWI_ADDRESS, 0x2000);
    osc_output_disable();
    
    // initialize offset potentiometer
    set_dc_offset(0x80);
    
    // initialize touchscreen module
    struct spi_interface_t spi = { &DDRB, PB1, PB3, PB2 };
    struct touch_driver_t touch = { &spi, tcs_pin, tirq_pin };
    touch_driver_init(&touch, 0);
    struct lcd_driver_t driver = { &spi, dcx_pin, reset_pin, csx_pin };
    lcd_driver_init(&driver, FBOOL0);
    lcd_reset(&driver);
    _delay_ms(200);
    lcd_power_on(&driver);
    lcd_memory_access_control(&driver, MADCTL_MV | MADCTL_BGR);
    
    uint16_t x, y;
    enum menu_scene selected_menu_scene = NONE;
    void (*draw_menu_p)(struct lcd_driver_t *);
    void (*scan_menu_p)(struct lcd_driver_t *, uint16_t, uint16_t);
    while (1) {
        if (g_current_menu_scene != selected_menu_scene) {
            switch (g_current_menu_scene) {
            case MAIN_MENU:
                draw_menu_p = &draw_main_menu;
                scan_menu_p = &scan_main_menu;
                break;
            case OPTIONS_MENU:
                draw_menu_p = &draw_options_menu;
                scan_menu_p = &scan_options_menu;
                break;
            default:
                break;
            }
            selected_menu_scene = g_current_menu_scene;
            spi_set_speed(SPI_4MHZ);  // 4 MHz
            (*draw_menu_p)(&driver);
        }
        
        spi_set_speed(SPI_2MHZ);  // 2 MHz
        if (touch_scan(&touch, &x, &y)) {
            touch_get_screen_coordinates(&driver, &x, &y);
        } else {
            x = 0xFFFF;
            y = 0xFFFF;
        }
        spi_set_speed(SPI_4MHZ);  // 4 MHz
        (*scan_menu_p)(&driver, x, y);
    }
}
