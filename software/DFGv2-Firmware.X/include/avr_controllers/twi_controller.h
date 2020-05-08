/* 
 * File:   twi_controller.h
 * Author: pesho
 *
 * Created on February 23, 2020, 11:59 AM
 */

#ifndef TWI_CONTROLLER_H
#define	TWI_CONTROLLER_H

#include <stddef.h>
#include <inttypes.h>

#include "defs.h"

#define TWI_400KHZ 400000

#ifdef	__cplusplus
extern "C" {
#endif

void twi_init(void);
    
void twi_set_speed(uint32_t, fbool);

void twi_set_slave_address(uint8_t);

uint8_t twi_start(void);

uint8_t twi_repeated_start(void);

void twi_stop(void);

uint8_t twi_write_SLAW(uint8_t slave);

uint8_t twi_write_SLAR(uint8_t slave);

uint8_t twi_write8(uint8_t data);

uint8_t twi_read8(uint8_t *data, fbool ack);

uint8_t twi_write(uint8_t, uint8_t *, size_t);

#ifdef	__cplusplus
}
#endif

#endif	/* TWI_CONTROLLER_H */

