#include "twi_driver.h"

#include <avr/io.h>

void twi_init(void)
{
    // set SCL frequency to 400 kHz
    TWSR = 0;
    //TWBR = ((F_CPU / TWI_FREQ) - 16) / (2 * TWSR);
    TWBR = 0x0C;
    TWAR = 0;  // TWI slave address is not required
    TWCR = (1 << TWEN) | (1 << TWIE);  // enable TWI
}

void twi_start(void)
{
    // send start condition
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN) | (1 << TWIE);
}
