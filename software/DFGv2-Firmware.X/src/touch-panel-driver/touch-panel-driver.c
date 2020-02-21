#include "touch-panel-driver/touch-panel-driver.h"

#include <inttypes.h>

#include "defs.h"
#include "touch-panel-driver/touch-panel-driver-chip.h"
#include "lcd-driver/lcd-driver.h"
#include "avr_controllers/spi_controller.h"

#include <avr/io.h>

static uint16_t _touch_read_ADC(struct touch_driver_t *, uint8_t);

static uint16_t _touch_multiread(struct touch_driver_t *, uint8_t);

void touch_driver_init(struct touch_driver_t *driver, fbool options)
{
    /* fbool options:
     * bit 0: initialize Master SPI
     * bits 1-7: not used
     */
    // optionally initialize the SPI interface
    if (options & FBOOL0)
        mspi_init(driver->spi);
    
    _tcs_high(driver);
}

uint16_t touch_read_x(struct touch_driver_t *driver)
{
    return ((long)XFAC * _touch_multiread(driver, TP_CMD_RDX)) / 10000 + XOFFSET;
}

uint16_t touch_read_y(struct touch_driver_t *driver)
{
    return ((long)YFAC * _touch_multiread(driver, TP_CMD_RDY)) / 10000 + YOFFSET;
}

short touch_scan(struct touch_driver_t *driver, uint16_t *x, uint16_t *y)
{
    if (!_tirq_state(driver)) {  // touch panel is pressed
        *x = touch_read_x(driver);
        *y = touch_read_y(driver);
        return 1;
    }
    return 0;
}

void touch_get_screen_coordinates(struct lcd_driver_t *lcd_driver,
        uint16_t *x, uint16_t *y)
{
    uint16_t temp;
    enum rotation screen_rotation = lcd_get_rotation(lcd_driver);
    
    switch (screen_rotation) {
        case NORTHEAST:
            *y = lcd_driver->res_y - *y;
            break;
        case SOUTHWEST:
            *x = lcd_driver->res_x - *x;
            break;
        case NORTHWEST:
            *x = lcd_driver->res_x - *x;
            *y = lcd_driver->res_y - *y;
            break;
        case SOUTHEAST:
            break;
        case EASTNORTH:
            temp = *x;
            *x = lcd_driver->res_x - *y;
            *y = temp;
            break;
        case WESTSOUTH:
            temp = *x;
            *x = *y;
            *y = lcd_driver->res_y - temp;
            break;
        case WESTNORTH:
            temp = *x;
            *x = lcd_driver->res_x - *y;
            *y = lcd_driver->res_y - temp;
            break;
        case EASTSOUTH:
            temp = *x;
            *x = *y;
            *y = temp;
            break;
    }
}

static uint16_t _touch_read_ADC(struct touch_driver_t *driver, uint8_t cmd)
{
    uint8_t lsb, msb;
    
    _tcs_low(driver);           // select the device
    spi_transfer(cmd);          // transfer the control byte
    msb = spi_transfer(0x00);   // read the 8 most significant bits
    lsb = spi_transfer(0x00);   // read the 8 least significant bits
    _tcs_high(driver);          // deselect the device
    if (cmd & TP_SERDFR)  // single-ended conversion (12 clk cycles)
        return (msb << 4) | (lsb >> 4);
    else  // ratiometric conversion (13 clk cycles)
        return (msb << 5) | (lsb >> 3);
}

static uint16_t _touch_multiread(struct touch_driver_t *driver, uint8_t cmd)
{
    uint32_t sum = 0;
    
    for (short i = 0; i < SAMPLES; ++i)
        sum += _touch_read_ADC(driver, cmd);
    return sum / SAMPLES;
}
