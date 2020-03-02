/*
 * File:   main.c
 * Author: pesho
 *
 * Created on January 25, 2020, 6:47 PM
 */

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "init_mcu.h"
#include "avr_controllers/twi_controller.h"
#include "avr_controllers/spi_controller.h"
#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/graphics.h"

#include "lcd-driver/font8x8.h"

#include "user-interface/ui_helper.h"
#include "user-interface/ui_main_menu.h"
#include "user-interface/ui_options_menu.h"
#include "touch-panel-driver/touch-panel-driver.h"

#include "DFG-firmware/DDS_firmware.h"
#include "DFG-firmware/IOexpander_driver.h"
#include "DFG-firmware/programmable_oscillator_driver.h"

int main(void)
{       
    init_mcu();
    twi_init();
    twi_set_speed(TWI_400KHZ, 0);
    twi_set_slave_address(0x00);
    
    struct pin_ref_t oscoe = { &PORTF, PF2 };
    osc_conf_mux_word(U8_TWI_ADDRESS, 0x2780);  // sets P0 and P1 to 8
    osc_output_disable(oscoe);
    
    uint8_t pot_data[] = { 0x00, 0xFF };
    twi_write(U15_TWI_ADDRESS, pot_data, 2);
     
    struct pin_ref_t pwrdwn = { &PORTF, PF0 };
    struct pin_ref_t cmr1 = { &PORTB, PB4 };
    struct pin_ref_t cmr2 = { &PORTB, PB5 };
    struct pin_ref_t cp = { &PORTB, PB7 };
    power_up(pwrdwn);
    
    struct pin_ref_t rw = { &PORTB, PB6 };
    uint16_t data[64] = { 
0x2000, 0x2320, 0x263c, 0x2948, 0x2c3c, 0x2f14, 0x31c4, 0x3448, 
0x369c, 0x38b8, 0x3a98, 0x3c34, 0x3d8c, 0x3e9c, 0x3f60, 0x3fd4, 
0x3ffc, 0x3fd4, 0x3f60, 0x3e9c, 0x3d8c, 0x3c34, 0x3a98, 0x38b8, 
0x369c, 0x3448, 0x31c4, 0x2f14, 0x2c3c, 0x2948, 0x263c, 0x2320, 
0x2000, 0x1cdc, 0x19c0, 0x16b4, 0x13c0, 0x10e8, 0xe38, 0xbb4, 
0x960, 0x744, 0x564, 0x3c8, 0x270, 0x160, 0x9c, 0x28, 
0x0, 0x28, 0x9c, 0x160, 0x270, 0x3c8, 0x564, 0x744, 
0x960, 0xbb4, 0xe38, 0x10e8, 0x13c0, 0x16b4, 0x19c0, 0x1cdc, 
    };
    for (int i = 0; i < 4096 / 64; ++i) {
        set_address_counter(i * 64, cp, cmr1, cmr2);
        sram_write(data, 64, rw, pwrdwn, cp);
    }
    load_into_dac(rw, pwrdwn);
    
    reset_address_counter(cmr1, cmr2);
    setpinref(cmr2);  // disable counter 2
    DDRB &= ~_BV(PB7);
    PORTB &= ~_BV(PB7);
    osc_conf_div(U8_TWI_ADDRESS, 16);
    osc_conf_freq(U8_TWI_ADDRESS, 2, 8);
    osc_output_enable(oscoe);
    while (1) {

    }
    
    /*
    // enable internal pull-up on ~SS
    PORTB = (1 << PB0);
     
    struct spi_interface_t spi = { &DDRB, PB1, PB3, PB2 };
    struct pin_ref_t dcx = { &PORTD, PD2 };
    struct pin_ref_t reset = { &PORTD, PD3 };
    struct pin_ref_t csx = { &PORTD, PD4 };
    struct lcd_driver_t driver = { &spi, dcx, reset, csx };
    
    // Concfigure the LCD signal lines RESET, D/CX and CSX as outputs
    // DDRD = (1 << PD2) | (1 << PD3) | (1 << PD4);
    
    struct pin_ref_t tcs = { &PORTD, PD5 };
    struct pin_ref_t tirq = { &PIND, PD6 };
    struct touch_driver_t touch = { &spi, tcs, tirq };
    touch_driver_init(&touch, 0);
    lcd_driver_init(&driver, FBOOL0);
    */
    // NOTE: for ATmega328p
    // enable internal pull-up on ~SS
    /*
    PORTB = (1 << PB2);
     
    struct spi_interface_t spi = { &DDRB, PB5, PB4, PB3 };
    struct pin_ref_t dcx = { &PORTC, PC0 };
    struct pin_ref_t reset = { &PORTC, PC1 };
    struct pin_ref_t csx = { &PORTC, PC2 };
    struct lcd_driver_t driver = { &spi, dcx, reset, csx };
    
    // Concfigure the LCD signal lines RESET, D/CX and CSX as outputs
    DDRC = (1 << PC0) | (1 << PC1) | (1 << PC2);
    
    struct pin_ref_t tcs = { &PORTC, PC3 };
    struct pin_ref_t tirq = { &PINC, PC4 };
    struct touch_driver_t touch = { &spi, tcs, tirq };
    touch_driver_init(&touch, 0);
    DDRC |= (1 << PC3) | (1 << PC5);
    */
    
    /*
    lcd_reset(&driver);
    _delay_ms(200);
    lcd_power_on(&driver);
    lcd_memory_access_control(&driver, MADCTL_MV | MADCTL_BGR);
    */
 
    /*
    uint16_t pixels[25] = {
        0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, color2, 0x0, 0x0, 0x0,
        color2, 0x0, color2, 0x0, color2,
        0x0, 0x0, 0x0, color2, 0x0,
        0x0, 0x0, 0x0, 0x0, 0x0
    };
    area_draw_figure(&driver, &area, 5, 5, 5, 5, pixels);
    */
    /*
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
            draw_pixel(&driver, x, y, 0xFFFF);
        } else {
            x = 0xFFFF;
            y = 0xFFFF;
        }
        spi_set_speed(SPI_4MHZ);  // 4 MHz
        (*scan_menu_p)(&driver, x, y);
    }
    */
}
