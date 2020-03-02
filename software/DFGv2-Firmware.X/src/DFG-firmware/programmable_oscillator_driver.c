#include "DFG-firmware/programmable_oscillator_driver.h"

#include <inttypes.h>
#include <util/delay.h>

#include "defs.h"
#include "avr_controllers/twi_controller.h"
#include "DFG-firmware/chips/DS1085.h"

void osc_output_enable(struct pin_ref_t oscoe)
{
    resetpinref(oscoe);
}

void osc_output_disable(struct pin_ref_t oscoe)
{
    setpinref(oscoe);
}

uint8_t osc_conf_mux_word(uint8_t address, uint16_t mux_word)
{
    // mux_word is assumed to be in format bbbbbbbb bbxxxxxx
    uint8_t access_mux[3] = { DS1085_ACCESS_MUX, (mux_word >> 8), (mux_word & 0xFF) };
    uint8_t rc;
    
    if ((rc = twi_write(address, access_mux, 3)) != 0) return rc;
    _delay_ms(10);
    return 0;
}

uint8_t osc_conf_freq(uint8_t address, uint16_t dac_word, uint8_t offset_byte)
{
    // dac_word is assumed to be in format xxxxxxbb bbbbbbbb
    // where b is a valid bit
    // and x is invalid
    uint8_t access_dac[3] = { DS1085_ACCESS_DAC, (dac_word >> 2), (dac_word & 0x03) };
    uint8_t access_offset[2] = { DS1085_ACCESS_OFFSET, offset_byte };
    uint8_t rc;
    
    if ((rc = twi_write(address, access_dac, 3)) != 0) return rc;
    _delay_ms(10);
    if ((rc = twi_write(address, access_offset, 2)) != 0) return rc;
    _delay_ms(10);
    return 0;
}

uint8_t osc_conf_div(uint8_t address, uint16_t div_word)
{
    // div_word is assumed to be in format xxxxxxbb bbbbbbbb
    uint8_t access_div[3] = { DS1085_ACCESS_DIV, (div_word >> 2), (div_word & 0x03) };
    uint8_t rc;
    
    if ((rc = twi_write(address, access_div, 3)) != 0) return rc;
    _delay_ms(10);
    return 0;
}
