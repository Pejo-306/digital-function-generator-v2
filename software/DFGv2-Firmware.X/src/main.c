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
    
    PORTD = (1 << PD0) | (1 << PD1);

    twi_init();
    sei();
    twi_start();
    while (1) {    
        PINA = 0xff;
    }
}

ISR(TWI_vect)
{
    PINC = 0xff;
    twi_start();
}