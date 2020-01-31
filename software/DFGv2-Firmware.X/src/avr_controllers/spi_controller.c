#include "avr_controllers/spi_controller.h"

#include <avr/io.h>
#include <inttypes.h>

void mspi_init(struct spi_interface_t *spi)
{
    // configure SCK and MOSI pins as outputs
    *spi->ddr_spi |= (1 << spi->mosi_pin) | (1 << spi->sck_pin);
    // configure MISO pin as input
    *spi->ddr_spi &= ~(1 << spi->miso_pin);
    
    // enable SPI in Master mode; 
    SPCR = (1 << SPE) | (1 << MSTR);
}

void spi_set_speed(fbool clockrate)
{
    /*
     * flagsbool clockrate:
     * bit 0: SPR0
     * bit 1: SPR1
     * bit 2: SPI2X
     * bits 3-7: not used
     */
    // set/reset SCK frequency
    setrst(SPCR, SPR0, clockrate & FBOOL0);
    setrst(SPCR, SPR1, clockrate & FBOOL1);
    // set/reset SPI 2x clock speed
    setrst(SPSR, SPI2X, clockrate & FBOOL2);
}

void spi_set_data_mode(fbool data_mode)
{
    /*
     * flagsbool data_mode:
     * bit 0: CPHA
     * bit 1: CPOL
     * bit 2: DORD
     * bits 3-7: not used
     */
    // set/reset clock phase
    setrst(SPCR, CPHA, data_mode & FBOOL0);
    // set/reset clock polarity
    setrst(SPCR, CPOL, data_mode & FBOOL1);
    // set/reset data order
    setrst(SPCR, DORD, data_mode & FBOOL2);
}

uint8_t spi_transfer(uint8_t data)
{
    // start SPI transmission
    SPDR = data;
    // wait for transmission to complete
    while (!(SPSR & _BV(SPIF)));
    // return received data from slave
    return SPDR;
}
