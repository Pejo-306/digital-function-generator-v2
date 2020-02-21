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
#include "twi_driver.h"
#include "avr_controllers/spi_controller.h"
#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/graphics.h"

#include "lcd-driver/font8x8.h"

#include "user-interface/ui_helper.h"
#include "user-interface/ui_main_menu.h"
#include "user-interface/ui_options_menu.h"
#include "touch-panel-driver/touch-panel-driver.h"

int main(void)
{   
    // init_mcu();
    
    /*
    DDRA = 0xff;
    DDRC = 0xff;
    DDRE = 0xff;
    DDRF = 0xf0;
    DDRG = 0xf;
    PORTA = 0xff;
    PORTC = 0xff;
    PORTE = 0xff;
    PORTF = 0xf0;
    PORTG = 0xf;
    */
    
    // FOR SIMULATION:
    
    /*
    PORTD = (1 << PD0) | (1 << PD1);

    twi_init();
    sei();
    twi_start();
    while (1) {    
        PINA = 0xff;
    }
    */
    /*
    // enable internal pull-up on ~SS
    PORTB = (1 << PB0);
     
    struct spi_interface_t spi = {&DDRB, PB1, PB3, PB2};
    struct pin_ref_t dcx = {&PORTD, PD2};
    struct pin_ref_t reset = {&PORTD, PD3};
    struct pin_ref_t csx = {&PORTD, PD4};
    struct lcd_driver_t driver = {spi, dcx, reset, csx};
    
    // Concfigure the LCD signal lines RESET, D/CX and CSX as outputs
    DDRD = (1 << PD2) | (1 << PD3) | (1 << PD4);
    */
    // NOTE: for ATmega328p
    // enable internal pull-up on ~SS
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
       
    lcd_driver_init(&driver, FBOOL0);  // set SCK clock frequency to fclk/16
    // spi_set_speed(FBOOL0);
    spi_set_speed(0);
    // spi_set_data_mode(FBOOL2);

    lcd_reset(&driver);
    _delay_ms(200);
    lcd_power_on(&driver);
    lcd_memory_access_control(&driver, MADCTL_MV | MADCTL_BGR);
 
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
            (*draw_menu_p)(&driver);
        }
        
        if (touch_scan(&touch, &x, &y)) {
            touch_get_screen_coordinates(&driver, &x, &y);
            draw_pixel(&driver, x, y, 0xFFFF);
        } else {
            x = 0xFFFF;
            y = 0xFFFF;
        }
        (*scan_menu_p)(&driver, x, y);
    }
}


ISR(TWI_vect)
{
    PINC = 0xff;
    twi_start();
}