/* 
 * File:   programmable_oscillator_driver.h
 * Author: pesho
 *
 * Created on March 1, 2020, 3:08 AM
 */

#ifndef PROGRAMMABLE_OSCILLATOR_DRIVER_H
#define	PROGRAMMABLE_OSCILLATOR_DRIVER_H

#include <inttypes.h>

#ifdef	__cplusplus
extern "C" {
#endif

void osc_output_enable(void);

void osc_output_disable(void);

uint8_t osc_conf_mux_word(uint8_t address, uint16_t mux_word);

uint8_t osc_conf_freq(uint8_t address, uint16_t dac_word, uint8_t offset_byte);

uint8_t osc_conf_div(uint8_t address, uint16_t div_word);

uint8_t osc_read_range(uint8_t address, uint8_t *os);

#ifdef	__cplusplus
}
#endif

#endif	/* PROGRAMMABLE_OSCILLATOR_DRIVER_H */

