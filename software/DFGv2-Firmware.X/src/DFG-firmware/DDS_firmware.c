#include "DFG-firmware/DDS_firmware.h"

#include <stddef.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "defs.h"
#include "init_mcu.h"
#include "avr_controllers/twi_controller.h"
#include "DFG-firmware/IOexpander_driver.h"
#include "DFG-firmware/chips/MCP455X.h"

void power_up(void)
{
    resetpinref(pwrdwn_pin);
    _delay_us(POWER_UP_TIME);
}

void power_down(void)
{
    setpinref(pwrdwn_pin);
}

fbool is_powered_down(void)
{
    return ((pinrefstate(pwrdwn_pin) == 0) ? 0 : 1);
}

void set_address_counter(uint16_t address)
{
    setpinref(cp_pin);
    reset_address_counter();
    setpinref(cmr2_pin);  // disable 12-bit binary counter #2
    for (uint16_t i = 0; i < (address & 0x0FFF); ++i)
        increment_address_counter();
}

void reset_address_counter(void)
{
    setpinref(cmr1_pin);
    setpinref(cmr2_pin);
#if defined(DELAY_TICK) && DELAY_TICK <= ADDRESS_COUNTER_PULSE_WIDTH_NS
    _delay_us(ADDRESS_COUNTER_PULSE_WIDTH_US);
#endif
    resetpinref(cmr1_pin);
    resetpinref(cmr2_pin);
#if defined(DELAY_TICK) && DELAY_TICK <= ADDRESS_COUNTER_RECOVERY_TIME_NS
    _delay_us(ADDRESS_COUNTER_RECOVERY_TIME_US);
#endif
}

void increment_address_counter(void)
{
    resetpinref(cp_pin);
#if defined(DELAY_TICK) && DELAY_TICK <= ADDRESS_COUNTER_PULSE_WIDTH_NS
    _delay_us(ADDRESS_COUNTER_PULSE_WIDTH_US);
#endif
    setpinref(cp_pin);
#if defined(DELAY_TICK) && DELAY_TICK <= ADDRESS_COUNTER_PULSE_WIDTH_NS
    _delay_us(ADDRESS_COUNTER_PULSE_WIDTH_US);
#endif
}

uint8_t sram_write(const uint16_t *data, size_t size, size_t step)
{
    // NOTE: the data array should be saved in program space!
    uint8_t rc;
    uint16_t val;
    uint8_t lsbs, msbs;
    uint16_t gpio;
    
    if ((rc = ioex_set_gppu(U10_TWI_ADDRESS, 0xFF, FBOOL1)) != 0) return rc;                    // enable internal pull-ups on PORT B
    if ((rc = ioex_set_gppu(U10_TWI_ADDRESS, 0xFF, 0)) != 0) return rc;                         // enable internal pull-ups on PORT A
    for (size_t i = 0; i < size; i += step) {
        val = pgm_read_word(&data[i]);
        do {
            if ((rc = ioex_write_gpio(U10_TWI_ADDRESS, val & 0xFF, FBOOL1)) != 0) return rc;    // write LSBs to GPIOB
            if ((rc = ioex_write_gpio(U10_TWI_ADDRESS, val >> 8, 0)) != 0) return rc;           // write MSBs to GPIOA
            if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0x00, FBOOL1)) != 0) return rc;           // set all pins on PORT B as outputs
            if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0x00, 0)) != 0) return rc;                // set all pins on PORT A as outputs
            power_up();                                                                         // activate the chip
            resetpinref(rw_pin);                                                                // write to SRAM
            power_down();                                                                       // deselect the chip
            setpinref(rw_pin);                                                                  // read from SRAM        
            if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0xFF, FBOOL1)) != 0) return rc;           // set all pins on PORT B as inputs
            if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0xFF, 0)) != 0) return rc;                // set all pins on PORT A as inputs
            power_up();                                                                         // activate the chip
            if ((rc = ioex_read_gpio(U10_TWI_ADDRESS, &lsbs, FBOOL1)) != 0) return rc;          // read the value of PORT B
            if ((rc = ioex_read_gpio(U10_TWI_ADDRESS, &msbs, 0)) != 0) return rc;               // read the value of PORT A
            power_down();                                                                       // deselect the chip
            gpio = (msbs << 8) | lsbs;
        } while (gpio != val);
        increment_address_counter();                                                            // move to next memory cell
    }
    return 0;
}

uint8_t load_into_dac(void)
{
    uint8_t rc;
    
    if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0xFF, FBOOL1)) != 0) return rc;   // set all pins on PORT B as outputs
    if ((rc = ioex_set_iodir(U10_TWI_ADDRESS, 0xFF, 0)) != 0) return rc;        // set all pins on PORT A as outputs
    if ((rc = ioex_set_gppu(U10_TWI_ADDRESS, 0x00, FBOOL1)) != 0) return rc;    // disable internal pull-ups on PORT B
    if ((rc = ioex_set_gppu(U10_TWI_ADDRESS, 0x00, 0)) != 0) return rc;         // disable internal pull-ups on PORT A
    setpinref(rw_pin);      // read from SRAM
    power_up();             // activate the chip
    return 0;
}

uint8_t set_dc_offset(uint16_t wiper_value)
{
    uint8_t pot_data[2];
    
    wiper_value = (wiper_value & 0x100) ? 0x100 : wiper_value;  // cap the wiper value at 100h
    pot_data[0] = MCP4551_VOLATILE_WIPER_0                      // address volatile wiper 0 register
            | MCP4551_WRITE_CMD                                 // write command
            | ((wiper_value >> 8) & 0x01);                      // D8 bit
    pot_data[1] = wiper_value & 0xFF;                           // D7-D0 bits
    return twi_write(U15_TWI_ADDRESS, pot_data, 2);
}

// NOTE: this function should be deprecated
void set_waveform(const uint16_t *wave, size_t wave_size, size_t resolution, size_t sram_size)
{
    size_t step = wave_size / resolution;
    
    for (size_t i = 0; i < sram_size / resolution; ++i) {
        set_address_counter(i * resolution);
        sram_write(wave, wave_size, step);
    }
}
