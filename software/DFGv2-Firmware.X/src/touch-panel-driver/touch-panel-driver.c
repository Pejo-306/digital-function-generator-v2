#include "touch-panel-driver/touch-panel-driver.h"

#include <inttypes.h>

#include "defs.h"
#include "touch-panel-driver/touch-panel-driver-chip.h"
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
    return _touch_multiread(driver, TP_CMD_RDX);
}

uint16_t touch_read_y(struct touch_driver_t *driver)
{
    return _touch_multiread(driver, TP_CMD_RDY);
}

short touch_scan(struct touch_driver_t *driver, uint16_t *x, uint16_t *y)
{
    if (!_tirq_state(driver)) {  // touch panel is pressed
        *x = touch_read_x(driver);
        *y = touch_read_x(driver);
        return 1;
    }
    return 0;
}

static uint16_t _touch_read_ADC(struct touch_driver_t *driver, uint8_t cmd)
{
    uint8_t lsb, msb;
    
    _tcs_low(driver);           // select the device
    spi_transfer(cmd);          // transfer the control byte
    msb = spi_transfer(0x00);   // read the 8 most significant bits
    lsb = spi_transfer(0x00);   // read the 8 least significant bits
    _tcs_high(driver);          // deselect the device
    return (msb << 4) | (lsb >> 4);

}

static uint16_t _touch_multiread(struct touch_driver_t *driver, uint8_t cmd)
{
    uint32_t sum = 0;
    
    for (short i = 0; i < SAMPLES; ++i)
        sum += _touch_read_ADC(driver, cmd);
    return sum / SAMPLES;
}
