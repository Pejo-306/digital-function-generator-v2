/* 
 * File:   spi_controller.h
 * Author: pesho
 *
 * Created on January 28, 2020, 4:35 PM
 */

#ifndef SPI_CONTROLLER_H
#define	SPI_CONTROLLER_H

#include <inttypes.h>

#include "defs.h"

#define SPI_1MHZ (FBOOL0)           // when fclk = 16 MHz
#define SPI_2MHZ (FBOOL2 | FBOOL0)  // when fclk = 16 MHz
#define SPI_4MHZ 0                  // when fclk = 16 MHz

#ifdef	__cplusplus
extern "C" {
#endif

struct spi_interface_t {
    SFR8_p ddr_spi;
    SFRPIN sck_pin;
    SFRPIN miso_pin;
    SFRPIN mosi_pin;
};

void mspi_init(struct spi_interface_t *);

void spi_set_speed(fbool);

void spi_set_data_mode(fbool);

uint8_t spi_transfer(uint8_t);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_CONTROLLER_H */
