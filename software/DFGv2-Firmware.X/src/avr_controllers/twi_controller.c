#include "avr_controllers/twi_controller.h"

#include <stddef.h>
#include <inttypes.h>
#include <avr/io.h>

#include "defs.h"

void twi_set_speed(uint32_t twi_freq, fbool prescaler)
{
    /*
     * flagsbool prescaler:
     * bit 0: TWPS0
     * bit 1: TWPS1
     * bits 2-7: not used
     */
    // set prescaler value
    setrst(TWSR, TWPS0, prescaler & FBOOL0);
    setrst(TWSR, TWPS1, prescaler & FBOOL1);
    // calculate TWI bit rate
    TWBR = ((F_CPU / twi_freq) - 16) / 2;
}

void twi_set_slave_address(uint8_t slave_address)
{
    TWAR = slave_address;  // set TWI slave address
}

short twi_start(void)
{
    TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN); // send START condition
    while (!(TWCR & _BV(TWINT)));               // wait for START condition to transmit
    TWCR &= ~_BV(TWSTA);                        // manually clear TWSTA bit of TWCR
    if ((TWSR & 0xF8) != TWI_MTSC_START)        // check status code for TWI
        return -1;                              // if start has not been transmitted, return error
    TWCR &= ~_BV(TWEN);                         // manually clear TWEN bit of TWCR (for debugging)
    return 0;
}

short twi_write(uint8_t slave, uint8_t *buffer, size_t size)
{
    // transmit START
    if (twi_start() != 0)                       // transmit START condition
        return -1;                              // stop operation if START is not transmitted
    
    // transmit SLA+W
    // TWDR = (slave << 1) & ~1;
    TWDR = slave << 1;                          // load SLA+W into data register
    TWCR = _BV(TWINT) | _BV(TWEN);              // start SLA+W transmission
    while (!(TWCR & _BV(TWINT)));               // wait for SLA+W to transmit
    if ((TWSR & 0xF8) != TWI_MTSC_SLA_ACK)      // check status code for TWI
        return -1;                              // if ACK has not been received, return error
    TWCR &= ~_BV(TWEN);                         // manually clear TWEN bit of TWCR (for debugging)
    
    // transmit data
    for (size_t i = 0; i < size; ++i) {
        TWDR = buffer[i];                       // load data into data register
        TWCR = _BV(TWINT) | _BV(TWEN);          // start data transmission
        while (!(TWCR & _BV(TWINT)));           // wait for data to transmit
        if ((TWSR & 0xF8) != TWI_MTSC_DATA_ACK) // check status code for TWI
            return -1;                          // if ACK has not been received, return error
        TWCR &= ~_BV(TWEN);                     // manually clear TWEN bit of TWCR (for debugging)
    }
    
    // transmit STOP condition
    TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTO);
    TWCR &= ~_BV(TWEN);                         // turn of TWI
    return 0;
}
