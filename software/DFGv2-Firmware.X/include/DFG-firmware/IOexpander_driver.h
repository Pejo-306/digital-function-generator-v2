/* 
 * File:   IOexpander_driver.h
 * Author: pesho
 *
 * Created on February 24, 2020, 12:34 PM
 */

#ifndef IOEXPANDER_DRIVER_H
#define	IOEXPANDER_DRIVER_H

#include <inttypes.h>

#include "defs.h"

#define IOEX_RESET_TIME 10  // in us

#ifdef	__cplusplus
extern "C" {
#endif

void ioex_reset(struct pin_ref_t);

uint8_t ioex_set_iodir(uint8_t, uint8_t, fbool);

uint8_t ioex_write_gpio(uint8_t, uint8_t, fbool);

#ifdef	__cplusplus
}
#endif

#endif	/* IOEXPANDER_DRIVER_H */
