#include "init_mcu.h"

#include <avr/io.h>

static void _spi_master_init(void);
static void _twi_init(void);

void init_mcu(void)
{ 
    /* configure all PORT A pins as inputs:
     * PA0 - input/pull-up disabled
     * PA1 - input/pull-up disabled
     * PA2 - input/pull-up disabled
     * PA3 - input/pull-up disabled
     * PA4 - input/pull-up disabled
     * PA5 - input/pull-up disabled
     * PA6 - input/pull-up disabled
     * PA7 - input/pull-up disabled
     */
    DDRA = 0x00;
    PORTA = 0x00;
    
    /* configure the 4 most significant pins as digital outputs:
     * PB0 (~SS)  - output/LOW level
     * PB1 (SCK)  - output/LOW level
     * PB2 (MOSI) - output/LOW level
     * PB3 (MISO) - input/pull-up disabled
     * PB4 (CMR1) - output/LOW level
     * PB5 (CMR2) - output/LOW level
     * PB6 (R/~W) - output/HIGH level
     * PB7 (~CP)  - output/HIGH level. 
     */
    DDRB = 0xF7;
    PORTB = 0xC0;
    
    /* configure all PORT C pins as inputs:
     * PC0 - input/pull-up disabled
     * PC1 - input/pull-up disabled
     * PC2 - input/pull-up disabled
     * PC3 - input/pull-up disabled
     * PC4 - input/pull-up disabled
     * PC5 - input/pull-up disabled
     * PC6 - input/pull-up disabled
     * PC7 - input/pull-up disabled
     */
    DDRC = 0x00;
    PORTC = 0x00;
    
    /* configure all but PD0 and PD1 to accommodate communication with the
     * touchscreen LCD:
     * PD0 (SCL)        - input/pull-up disabled
     * PD1 (SDA)        - input/pull-up disabled
     * PD2 (DC/~RS_LCD) - output/HIGH level
     * PD3 (~RESET_LCD) - output/HIGH level
     * PD4 (~CS_LCD)    - output/HIGH level
     * PD5 (~CS_T)      - output/HIGH level
     * PD6 (IRQ_T)      - input/pull-up disabled
     * PD7 (~CS_SD)     - output/HIGH level
     */
    DDRD = 0xBC;
    PORTD = 0xBC;
    
    /* configure all PORT E pins as inputs:
     * PE0 - input/pull-up disabled
     * PE1 - input/pull-up disabled
     * PE2 - input/pull-up disabled
     * PE3 - input/pull-up disabled
     * PE4 - input/pull-up disabled
     * PE5 - input/pull-up disabled
     * PE6 - input/pull-up disabled
     * PE7 - input/pull-up disabled
     */
    DDRE = 0x00;
    PORTE = 0x00;
    
    /* configure PORT F pins:
     * PF0 - output/LOW level
     * PF1 - output/HIGH level
     * PF2 - output/HIGH level
     * PF3 - input/pull-up disabled
     * PF4 - input/pull-up disabled
     * PF5 - input/pull-up disabled
     * PF6 - input/pull-up disabled
     * PF7 - input/pull-up disabled
     */
    DDRF = 0x07;
    PORTF = 0x06;
    
    /* configure PORT G pins:
     * PG0 - input/pull-up disabled
     * PG1 - input/pull-up disabled
     * PG2 - input/pull-up disabled
     * PG3 - input/pull-up disabled
     * PG4 - input/pull-up disabled
     * PG5 - output/LOW level
     */
    DDRG = 0x20;
    PORTG = 0x00;
    
    _spi_master_init();
}

void _spi_master_init(void)
{
    // enable SPI in Master mode
    SPCR = (1 << SPE) | (1 << MSTR);
}

void _twi_init(void)
{
    // set SCL frequency to 400 kHz
    TWBR = 0x0C;
    TWSR = 0x00;
    TWCR = (1 << TWEN);  // enable TWI
}
