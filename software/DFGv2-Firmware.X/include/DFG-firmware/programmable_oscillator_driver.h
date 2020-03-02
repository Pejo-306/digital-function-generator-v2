/* 
 * File:   programmable_oscillator_driver.h
 * Author: pesho
 *
 * Created on March 1, 2020, 3:08 AM
 */

#ifndef PROGRAMMABLE_OSCILLATOR_DRIVER_H
#define	PROGRAMMABLE_OSCILLATOR_DRIVER_H

#include <inttypes.h>

#include "defs.h"
#include "DFG-firmware/chips/DS1085.h"

#ifdef	__cplusplus
extern "C" {
#endif

void osc_output_enable(struct pin_ref_t);

void osc_output_disable(struct pin_ref_t);

uint8_t osc_conf_mux_word(uint8_t, uint16_t);

uint8_t osc_conf_freq(uint8_t, uint16_t, uint8_t);

uint8_t osc_conf_div(uint8_t, uint16_t);

#ifdef	__cplusplus
}
#endif

#endif	/* PROGRAMMABLE_OSCILLATOR_DRIVER_H */

