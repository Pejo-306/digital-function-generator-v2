#include "lcd-driver/lcd-driver.h"

#include <util/delay.h>
#include <inttypes.h>

#include "defs.h"
#include "lcd-driver/lcd-driver-chip.h"
#include "avr_controllers/spi_controller.h"

static void _lcd_command_no_parameter(struct lcd_driver_t *, uint8_t);

static uint8_t _lcd_command_read_single_byte_with_dummy(struct lcd_driver_t *, 
        uint8_t);

static void _lcd_command_read_data_with_dummy(struct lcd_driver_t *, 
        uint8_t, uint8_t *, short);

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

void lcd_reset(struct lcd_driver_t *driver)
{
    _reset_low(driver);
    _delay_us(10);
    _reset_high(driver);
}

void lcd_nop(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_NOP);
}

void lcd_swreset(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_SOFTWARE_RESET);
}

void lcd_read_display_status(struct lcd_driver_t *driver, uint8_t *status_data)
{
    // WARNING: 'status_data[]' must be 4 bytes long
    _lcd_command_read_data_with_dummy(driver, CMD_READ_DISPLAY_STATUS, 
            status_data, 4);
}

uint8_t lcd_read_display_madctl(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte_with_dummy(driver, 
            CMD_READ_DISPLAY_MADCTL);
}

static void _lcd_command_no_parameter(struct lcd_driver_t *driver, 
        uint8_t command)
{
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    mspi_transmit(command);  // transmit the command
    _csx_high(driver);  // deselect the device
}

static uint8_t _lcd_command_read_single_byte_with_dummy(struct lcd_driver_t *driver, 
        uint8_t command)
{
    uint8_t result;
    
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    mspi_transmit(command);  // transmit the command
    _dcx_data(driver);
    mspi_transmit(_LCD_DRIVER_NO_VALUE);  // read dummy parameter (1st)
    result = mspi_transmit(_LCD_DRIVER_NO_VALUE);  // read data (2nd)
    _csx_high(driver);  // deselect the device
    return result;
}

static void _lcd_command_read_data_with_dummy(struct lcd_driver_t *driver, 
        uint8_t command, uint8_t *data, short nparams)
{
    // WARNING: the 'data' array must be with length 'nparams'
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    mspi_transmit(command);  // transmit the command
    _dcx_data(driver);
    mspi_transmit(_LCD_DRIVER_NO_VALUE);  // read dummy parameter (1st)
    for (short i = 0; i < nparams; ++i)
        data[i] = mspi_transmit(_LCD_DRIVER_NO_VALUE);  // receive each data byte
    _csx_high(driver);  // deselect the device
}
