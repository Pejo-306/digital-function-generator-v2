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

int main(void) {   
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
    PORTB = (1 << PB2);
     
    struct spi_interface_t spi = {&DDRB, PB5, PB4, PB3};
    struct pin_ref_t dcx = {&PORTD, PD5};
    struct pin_ref_t reset = {&PORTD, PD6};
    struct pin_ref_t csx = {&PORTD, PD7};
    struct lcd_driver_t driver = {spi, dcx, reset, csx};
    
    // Concfigure the LCD signal lines RESET, D/CX and CSX as outputs
    DDRD = (1 << PD5) | (1 << PD6) | (1 << PD7);
    lcd_driver_init(&driver, FBOOL0);  // set SCK clock frequency to fclk/16
    spi_set_speed(FBOOL0);
    
    while (1) {
        lcd_nop(&driver);
    }

}

ISR(TWI_vect)
{
    PINC = 0xff;
    twi_start();
}