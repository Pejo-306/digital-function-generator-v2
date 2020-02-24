/* 
 * File:   DDS_firmware.h
 * Author: pesho
 *
 * Created on February 23, 2020, 3:41 PM
 */

#ifndef DDS_FIRMWARE_H
#define	DDS_FIRMWARE_H

#include <stddef.h>
#include <inttypes.h>

#include "defs.h"

#define U8_TWI_ADDRESS  0x58  // DS1085Z-10+
#define U10_TWI_ADDRESS 0x20  // MCP23017
#define U15_TWI_ADDRESS 0x2E  // MCP4551-103E
#define U18_TWI_ADDRESS 0x60  // MCP4716-A0T

#define POWER_UP_TIME                       100 // in us
#define ADDRESS_COUNTER_RECOVERY_TIME_NS    15  // in ns; from 74HC4040
#define ADDRESS_COUNTER_PULSE_WIDTH_NS      24  // in ns; from 74HC4040
#define ADDRESS_COUNTER_RECOVERY_TIME_US    (ADDRESS_COUNTER_RECOVERY_TIME_NS / 1000.0)
#define ADDRESS_COUNTER_PULSE_WIDTH_US      (ADDRESS_COUNTER_PULSE_WIDTH_NS / 1000.0)    

#ifdef	__cplusplus
extern "C" {
#endif

void power_up(struct pin_ref_t);
    
void power_down(struct pin_ref_t);

fbool is_powered_down(struct pin_ref_t);

void set_address_counter(uint16_t, struct pin_ref_t, struct pin_ref_t, struct pin_ref_t);

void reset_address_counter(struct pin_ref_t, struct pin_ref_t);

void increment_address_counter(struct pin_ref_t);

uint8_t sram_write(uint16_t *, size_t, struct pin_ref_t, struct pin_ref_t, 
        struct pin_ref_t cp);

uint8_t load_into_dac(struct pin_ref_t, struct pin_ref_t);

#ifdef	__cplusplus
}
#endif

#endif	/* DDS_FIRMWARE_H */

