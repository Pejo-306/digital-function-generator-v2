#include "avr_controllers/twi_controller.h"

#include <stddef.h>
#include <inttypes.h>
#include <avr/io.h>
#include <util/twi.h>

#include "defs.h"

void twi_init(void)
{
    TWCR = _BV(TWEN);
}

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

uint8_t twi_start(void)
{
    // transmit START condition
    TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN); // send START condition
    while (!(TWCR & _BV(TWINT)));               // wait for START condition to transmit
    if (TW_STATUS != TW_START)                  // check status code for TWI
        return TW_STATUS;                       // if start has not been transmitted, return error status code
    // TWCR &= ~_BV(TWEN);                      // manually clear TWEN bit of TWCR (for debugging)
    return 0;
}

void twi_stop(void)
{
    // transmit STOP condition
    TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTO);
}

uint8_t twi_write_SLAW(uint8_t slave)
{
    // transmit SLA+W
    TWDR = (slave << 1) | TW_WRITE; // load SLA+W into data register
    TWCR = _BV(TWINT) | _BV(TWEN);  // start SLA+W transmission
    while (!(TWCR & _BV(TWINT)));   // wait for SLA+W to transmit
    if (TW_STATUS != TW_MT_SLA_ACK) // check status code for TWI
        return TW_STATUS;           // if ACK has not been received, return error status code
    // TWCR &= ~_BV(TWEN);          // manually clear TWEN bit of TWCR (for debugging)
    return 0;
}

uint8_t twi_write8(uint8_t data)
{
    // transmit a byte of data
    TWDR = data;                        // load data into data register
    TWCR = _BV(TWINT) | _BV(TWEN);      // start data transmission
    while (!(TWCR & _BV(TWINT)));       // wait for data to transmit
    if (TW_STATUS != TW_MT_DATA_ACK)    // check status code for TWI
        return TW_STATUS;               // if ACK has not been received, return error status code
    // TWCR &= ~_BV(TWEN);              // manually clear TWEN bit of TWCR (for debugging)
    return 0;
}

uint8_t twi_write(uint8_t slave, uint8_t *buffer, size_t size)
{
    if (twi_start() != 0) return -1;                    // transmit START condition
    if (twi_write_SLAW(slave) != 0) return TW_STATUS;   // transmit SLA+W
    for (size_t i = 0; i < size; ++i)                   // transmit each data byte
        if (twi_write8(buffer[i]) != 0) return TW_STATUS;  
    twi_stop();                                         // transmit STOP condition
    return 0;
}
