#include "lcd-driver/lcd-driver.h"

#include "defs.h"
#include "lcd-driver/lcd-driver-chip.h"
#include "avr_controllers/spi_controller.h"

void lcd_driver_init(struct lcd_driver_t *driver, fbool init_spi)
{
    /* fbool init_spi:
     * bit 0: initialize Master SPI
     * bits 1-7: not used
     */
    // optionally initialize the SPI interface
    if (init_spi & FBOOL0)
        mspi_init(&driver->spi);
    
    _dcx_data(driver);
    _csx_high(driver);
    _reset_high(driver);
}

void lcd_nop(struct lcd_driver_t *driver)
{
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    mspi_transmit(CMD_NOP);
    _csx_high(driver);
}
