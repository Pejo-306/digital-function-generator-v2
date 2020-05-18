#include "DFG-firmware/IOexpander_driver.h"

#include <avr/io.h>
#include <util/delay.h>

#include "defs.h"
#include "init_mcu.h"
#include "avr_controllers/twi_controller.h"
#include "DFG-firmware/chips/MCP23017.h"

void ioex_reset(void)
{
    resetpinref(ioex_reset_pin);
    _delay_us(IOEX_RESET_TIME);
    setpinref(ioex_reset_pin);
    _delay_us(IOEX_RESET_TIME);
}

uint8_t ioex_set_iodir(uint8_t address, uint8_t dir, fbool options)
{
    /* fbool options:
     * bit 0: IOCON.BANK bit
     * bit 1: port - '0' for port A
     *             - '1' for port B
     * bits 2-7: not used
     */
    uint8_t twi_data[2];
    
    twi_data[1] = dir;
    if (options & FBOOL0)  // IOCON.BANK = 1
        twi_data[0] = (options & FBOOL1) ? MCP23017_B1_IODIRB : MCP23017_B1_IODIRA;
    else  // IOCON.BANK = 0
        twi_data[0] = (options & FBOOL1) ? MCP23017_B0_IODIRB : MCP23017_B0_IODIRA;
    return twi_write(address, twi_data, 2);
}

uint8_t ioex_set_gppu(uint8_t address, uint8_t gppu, fbool options)
{
    /* fbool options:
     * bit 0: IOCON.BANK bit
     * bit 1: port - '0' for port A
     *             - '1' for port B
     * bits 2-7: not used
     */
    uint8_t twi_data[2];
    
    twi_data[1] = gppu;
    if (options & FBOOL0)  // IOCON.BANK = 1
        twi_data[0] = (options & FBOOL1) ? MCP23017_B1_GPPUB : MCP23017_B1_GPPUA;
    else  // IOCON.BANK = 0
        twi_data[0] = (options & FBOOL1) ? MCP23017_B0_GPPUB : MCP23017_B0_GPPUA;
    return twi_write(address, twi_data, 2);
}

uint8_t ioex_write_gpio(uint8_t address, uint8_t data, fbool options)
{
    /* fbool options:
     * bit 0: IOCON.BANK bit
     * bit 1: port - '0' for port A
     *             - '1' for port B
     * bits 2-7: not used
     */
    uint8_t twi_data[2];
    
    twi_data[1] = data;
    if (options & FBOOL0)  // IOCON.BANK = 1
        twi_data[0] = (options & FBOOL1) ? MCP23017_B1_GPIOB : MCP23017_B1_GPIOA;
    else  // IOCON.BANK = 0
        twi_data[0] = (options & FBOOL1) ? MCP23017_B0_GPIOB : MCP23017_B0_GPIOA;
    return twi_write(address, twi_data, 2);
}

uint8_t ioex_read_gpio(uint8_t address, uint8_t *data, fbool options)
{
    /* fbool options:
     * bit 0: IOCON.BANK bit
     * bit 1: port - '0' for port A
     *             - '1' for port B
     * bits 2-7: not used
     */
    uint8_t rc;
    uint8_t reg_addr;
    
    if (options & FBOOL0)  // IOCON.BANK = 1
        reg_addr = (options & FBOOL1) ? MCP23017_B1_GPIOB : MCP23017_B1_GPIOA;
    else  // IOCON.BANK = 0
        reg_addr = (options & FBOOL1) ? MCP23017_B0_GPIOB : MCP23017_B0_GPIOA;
    
    if ((rc = twi_start()) != 0) return rc;             // transmit START condition
    if ((rc = twi_write_SLAW(address)) != 0) return rc; // transmit SLA+W
    if ((rc = twi_write8(reg_addr)) != 0) return rc;    // transmit register address
    if ((rc = twi_repeated_start()) != 0) return rc;    // transmit REPEATED START condition
    if ((rc = twi_write_SLAR(address)) != 0) return rc; // transmit SLA+R
    if ((rc = twi_read8(data, 0)) != 0) return rc;      // receive GPIO state
    twi_stop();                                         // transmit STOP condition
    return 0;
}

uint8_t ioex_read_olat(uint8_t address, uint8_t *data, fbool options)
{
    /* fbool options:
     * bit 0: IOCON.BANK bit
     * bit 1: port - '0' for port A
     *             - '1' for port B
     * bits 2-7: not used
     */
    uint8_t rc;
    uint8_t reg_addr;
    
    if (options & FBOOL0)  // IOCON.BANK = 1
        reg_addr = (options & FBOOL1) ? MCP23017_B1_OLATB : MCP23017_B1_OLATA;
    else  // IOCON.BANK = 0
        reg_addr = (options & FBOOL1) ? MCP23017_B0_OLATB : MCP23017_B0_OLATA;
    
    if ((rc = twi_start()) != 0) return rc;             // transmit START condition
    if ((rc = twi_write_SLAW(address)) != 0) return rc; // transmit SLA+W
    if ((rc = twi_write8(reg_addr)) != 0) return rc;    // transmit register address
    if ((rc = twi_repeated_start()) != 0) return rc;    // transmit REPEATED START condition
    if ((rc = twi_write_SLAR(address)) != 0) return rc; // transmit SLA+R
    if ((rc = twi_read8(data, 0)) != 0) return rc;      // receive output latches' state
    twi_stop();                                         // transmit STOP condition
    return 0;
}
