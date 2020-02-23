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

#define TWI_MTSC_START      0x08
#define TWI_MTSC_SLA_ACK    0x18
#define TWI_MTSC_SLA_NACK   0x20
#define TWI_MTSC_DATA_ACK   0x28
#define TWI_MTSC_DATA_NACK  0x30

#ifdef	__cplusplus
extern "C" {
#endif

void twi_set_speed(uint32_t, fbool);

void twi_set_slave_address(uint8_t);

short twi_start(void);

short twi_write(uint8_t, uint8_t *, size_t);

#ifdef	__cplusplus
}
#endif

#endif	/* TWI_CONTROLLER_H */

