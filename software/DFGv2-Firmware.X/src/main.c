/*
 * File:   main.c
 * Author: pesho
 *
 * Created on January 25, 2020, 6:47 PM
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "init_mcu.h"
#include "twi_driver.h"
#include "avr_controllers/spi_controller.h"
#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/graphics.h"

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
     
    struct spi_interface_t spi = {&DDRB, PB5, PB4, PB3};
    struct pin_ref_t dcx = {&PORTC, PC0};
    struct pin_ref_t reset = {&PORTC, PC1};
    struct pin_ref_t csx = {&PORTC, PC2};
    struct lcd_driver_t driver = {spi, dcx, reset, csx};
    
    // Concfigure the LCD signal lines RESET, D/CX and CSX as outputs
    DDRC = (1 << PC0) | (1 << PC1) | (1 << PC2);
    
    lcd_driver_init(&driver, FBOOL0);  // set SCK clock frequency to fclk/16
    spi_set_speed(FBOOL0);
    // spi_set_data_mode(FBOOL2);

    /*
    uint8_t res = lcd_read_display_self_diagnostic_result(&driver);
    lcd_gamma_set(&driver, res);
     */
    /*
    uint8_t res = lcd_read_id3(&driver);
    lcd_gamma_set(&driver, res);
    */
    /*
    uint16_t data[8] = {
        0x14AF,
        0x32E2,
        0xAABA,
        0xE3E5,
        0xF002,
        0x0012,
        0xBEF2,
        0x0F2F
    };
    lcd_memory_write_continue(&driver, data, 8);
    lcd_nop(&driver);
    */
    /*
    lcd_sleep_out(&driver);
    lcd_display_on(&driver);
    lcd_pixel_format_set(&driver, DBI_16BIT);
    // Write CTRL display?
    uint16_t color = color565(0xE5, 0xB7, 0x5E);  // 0xE5AB
    draw_pixel(&driver, color);
    */
    lcd_reset(&driver);
    _delay_ms(200);
    lcd_power_on(&driver);
    uint16_t color = color565(0xE5, 0xB7, 0x5E);  // 0xE5AB
    // area_draw_pixel(&driver, color);
    struct graphic_area_t area;
    graphic_area_init(&area, 0x00, 0x0F, 0x00, 0x0F);
    area_fill(&driver, &area, color);
    uint16_t color2 = color565(0xFF, 0x00, 0x00);  // red
    area_draw_pixel(&driver, &area, 7, 7, color2);
    uint16_t pixels[25] = {
        0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, color2, 0x0, 0x0, 0x0,
        color2, 0x0, color2, 0x0, color2,
        0x0, 0x0, 0x0, color2, 0x0,
        0x0, 0x0, 0x0, 0x0, 0x0
    };
    //area_draw_figure(&driver, &area, 5, 5, 5, 5, pixels);
    while (1) {
    }
}

ISR(TWI_vect)
{
    PINC = 0xff;
    twi_start();
}