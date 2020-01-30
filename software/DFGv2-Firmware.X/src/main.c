/*
 * File:   main.c
 * Author: pesho
 *
 * Created on January 25, 2020, 6:47 PM
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "init_mcu.h"
#include "twi_driver.h"
#include "avr_controllers/spi_controller.h"
#include "lcd-driver/lcd-driver.h"

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
    // enable internal pull-up on ~SS
    PORTB = (1 << PB0);
     
    struct spi_interface_t spi = {&DDRB, PB1, PB3, PB2};
    struct pin_ref_t dcx = {&PORTD, PD2};
    struct pin_ref_t reset = {&PORTD, PD3};
    struct pin_ref_t csx = {&PORTD, PD4};
    struct lcd_driver_t driver = {spi, dcx, reset, csx};
    
    // Concfigure the LCD signal lines RESET, D/CX and CSX as outputs
    DDRD = (1 << PD2) | (1 << PD3) | (1 << PD4);
    lcd_driver_init(&driver, FBOOL0);  // set SCK clock frequency to fclk/16
    spi_set_speed(FBOOL0);

    /*
    uint8_t res = lcd_read_display_self_diagnostic_result(&driver);
    lcd_gamma_set(&driver, res);
     */
    /*
    uint8_t res = lcd_read_id3(&driver);
    lcd_gamma_set(&driver, res);
    */
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
    lcd_write_memory_continue(&driver, data, 8);
    lcd_nop(&driver);
    while (1) {
    }
}

ISR(TWI_vect)
{
    PINC = 0xff;
    twi_start();
}