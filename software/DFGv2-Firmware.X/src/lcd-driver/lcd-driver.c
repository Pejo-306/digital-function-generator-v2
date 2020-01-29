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

static void _lcd_write_command(struct lcd_driver_t *, uint8_t, uint8_t *, short);

void lcd_driver_init(struct lcd_driver_t *driver, fbool options)
{
    /* fbool options:
     * bit 0: initialize Master SPI
     * bits 1-7: not used
     */
    // optionally initialize the SPI interface
    if (options & FBOOL0)
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

uint32_t lcd_read_display_status(struct lcd_driver_t *driver)
{
    uint8_t data[4];
    uint32_t result;
    
    _lcd_command_read_data_with_dummy(driver, CMD_READ_DISPLAY_STATUS, data, 4);
    result = (uint32_t)(data[0]) 
            + ((uint32_t)(data[1]) << 8) 
            + ((uint32_t)(data[2]) << 16)
            + ((uint32_t)(data[3]) << 24);
    return result;
}

uint8_t lcd_read_display_madctl(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte_with_dummy(driver, 
            CMD_READ_DISPLAY_MADCTL);
}

signed short lcd_gamma_set(struct lcd_driver_t *driver, uint8_t gamma_curve)
{   
    uint8_t curve_bit;
    
    // gamma_curve: a value between 1 and 4 incl.
    if (gamma_curve < 1 || gamma_curve > 4) return -1;
    
    curve_bit = 1 << (gamma_curve - 1);
    _lcd_write_command(driver, CMD_GAMMA_SET, &curve_bit, 1);
    return 0;
}

signed short lcd_column_address_set(struct lcd_driver_t *driver, 
        uint16_t sc, uint16_t ec)
{
    uint8_t data[4];
    
    // SC[15:0] <= EC[15:0]
    if (sc > ec) return -1;
    
    data[0] = sc >> 8;  // 1st parameter
    data[1] = sc & 0xFF;  // 2nd parameter
    data[2] = ec >> 8;  // 3rd parameter
    data[3] = ec & 0xFF;  // 4th parameter
    _lcd_write_command(driver, CMD_COLUMN_ADDRESS_SET, data, 4);
    return 0;
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
    _dcx_data(driver);  // transmit a data command
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
    _dcx_data(driver);  // transmit a data command
    mspi_transmit(_LCD_DRIVER_NO_VALUE);  // read dummy parameter (1st)
    for (short i = 0; i < nparams; ++i)
        data[i] = mspi_transmit(_LCD_DRIVER_NO_VALUE);  // receive each data byte
    _csx_high(driver);  // deselect the device
}

static void _lcd_write_command(struct lcd_driver_t *driver, 
        uint8_t command, uint8_t *data, short nparams)
{
    // WARNING: the 'data' array must be with length 'nparams'
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    mspi_transmit(command);  // transmit the command
    _dcx_data(driver);  // transmit a data command
    for (short i = 0; i < nparams; ++i)
        mspi_transmit(data[i]);
    _csx_high(driver);  // deselect the device
}
