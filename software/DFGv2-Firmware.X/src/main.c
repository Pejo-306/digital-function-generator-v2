/*
 * File:   main.c
 * Author: pesho
 *
 * Created on January 25, 2020, 6:47 PM
 */

#include <avr/io.h>

#include "init_mcu.h"

int main(void) {   
    init_mcu();
    
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
    
    while (1) {
        
    }
}
