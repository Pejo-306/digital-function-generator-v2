#include "DFG-firmware/DDS_firmware.h"

#include <stddef.h>
#include <inttypes.h>
#include <util/delay.h>

#include "defs.h"
#include "DFG-firmware/IOexpander_driver.h"

void power_up(struct pin_ref_t pwrdwn)
{
    resetpinref(pwrdwn);
    _delay_us(POWER_UP_TIME);
}

void power_down(struct pin_ref_t pwrdwn)
{
    setpinref(pwrdwn);
}

fbool is_powered_down(struct pin_ref_t pwrdwn)
{
    return ((pinrefstate(pwrdwn) == 0) ? 0 : 1);
}

void set_address_counter(uint16_t address, struct pin_ref_t cp,
        struct pin_ref_t cmr1, struct pin_ref_t cmr2)
{
    setpinref(cp);
    reset_address_counter(cmr1, cmr2);
    setpinref(cmr2);  // disable 12-bit binary counter #2
    for (uint16_t i = 0; i < (address & 0x0FFF); ++i)
        increment_address_counter(cp);
}

void reset_address_counter(struct pin_ref_t cmr1, struct pin_ref_t cmr2)
{
    setpinref(cmr1);
    setpinref(cmr2);
#if defined(DELAY_TICK) && DELAY_TICK <= ADDRESS_COUNTER_PULSE_WIDTH_NS
    _delay_us(ADDRESS_COUNTER_PULSE_WIDTH_US);
#endif
    resetpinref(cmr1);
    resetpinref(cmr2);
#if defined(DELAY_TICK) && DELAY_TICK <= ADDRESS_COUNTER_RECOVERY_TIME_NS
    _delay_us(ADDRESS_COUNTER_RECOVERY_TIME_US);
#endif
}

void increment_address_counter(struct pin_ref_t cp)
{
    resetpinref(cp);
#if defined(DELAY_TICK) && DELAY_TICK <= ADDRESS_COUNTER_PULSE_WIDTH_NS
    _delay_us(ADDRESS_COUNTER_PULSE_WIDTH_US);
#endif
    setpinref(cp);
#if defined(DELAY_TICK) && DELAY_TICK <= ADDRESS_COUNTER_PULSE_WIDTH_NS
    _delay_us(ADDRESS_COUNTER_PULSE_WIDTH_US);
#endif
}

uint8_t sram_write(uint16_t *data, size_t size, struct pin_ref_t rw, 
        struct pin_ref_t pwrdwn, struct pin_ref_t cp)
{
    uint8_t rc;
    
    // set all pins on both PORT A and PORT B as outputs
    if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0x00, 0)) != 0) return rc;
    if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0x00, FBOOL1)) != 0) return rc;
    resetpinref(rw);                                                    // write to SRAM
    for (size_t i = 0; i < size; ++i) {
        power_up(pwrdwn);                                               // activate the chip
        rc = ioex_write_gpio(U10_TWI_ADDRESS, data[i] & 0xFF, FBOOL1);  // write LSBs to GPIOB
        if (rc != 0) return rc;
        rc = ioex_write_gpio(U10_TWI_ADDRESS, data[i] >> 8, 0);         // write MSBs to GPIOA
        if (rc != 0) return rc;
        power_down(pwrdwn);                                             // deselect the chip
        increment_address_counter(cp);                                  // move to next memory cell
    }
    return 0;
}

uint8_t load_into_dac(struct pin_ref_t rw, struct pin_ref_t pwrdwn)
{
    uint8_t rc;
    
    // set all pins on both PORT A and PORT B as inputs
    if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0xFF, 0)) != 0) return rc;
    if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0xFF, FBOOL1)) != 0) return rc;
    setpinref(rw);      // read from SRAM
    power_up(pwrdwn);   // activate the chip
    return 0;
}
