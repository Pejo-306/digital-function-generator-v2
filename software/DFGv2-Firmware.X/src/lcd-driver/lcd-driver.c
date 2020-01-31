#include "lcd-driver/lcd-driver.h"

#include <util/delay.h>
#include <inttypes.h>

#include "defs.h"
#include "lcd-driver/lcd-driver-chip.h"
#include "avr_controllers/spi_controller.h"

static void _lcd_command_no_parameter(struct lcd_driver_t *, uint8_t);

static uint8_t _lcd_command_read_single_byte(struct lcd_driver_t *, 
        uint8_t);

static void _lcd_command_read_data(struct lcd_driver_t *, 
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

    driver->madctl = MADCTL_DEFAULT_VALUE;
    driver->res_x = (driver->madctl & MADCTL_MV) ? LCD_RESY : LCD_RESX;
    driver->res_y = (driver->madctl & MADCTL_MV) ? LCD_RESX : LCD_RESY;
    _dcx_data(driver);
    _csx_high(driver);
    _reset_high(driver);
}

void lcd_power_on(struct lcd_driver_t *driver)
{
    uint8_t pgc_values[15] = { 0x0f, 0x26, 0x24, 0x0b, 0x0e, 0x09, 0x54, 0xa8, 0x46, 0x0c, 0x17, 0x09, 0x0f, 0x07, 0x00 };
    uint8_t ngc_values[15] = { 0x00, 0x19, 0x1b, 0x04, 0x10, 0x07, 0x2a, 0x47, 0x39, 0x03, 0x06, 0x06, 0x30, 0x38, 0x0f };
    
    lcd_swreset(driver);
    _delay_ms(10);
    lcd_display_off(driver);
    lcd_interface_control(driver, 0x01, 0x01, 0x00);
    lcd_power_control_b(driver, 0x81, 0x30);
    lcd_power_on_sequence_control(driver, 0x64, 0x03, 0x12, 0x81);
    lcd_driver_timing_control_a(driver, 0x85, 0x10, 0x78);
    lcd_power_control_a(driver, 0x34, 0x02);
    lcd_pump_ratio_control(driver, 0x20);
    lcd_driver_timing_control_b(driver, 0x00);
    lcd_rgb_interface_signal_control(driver, 0x00);
    lcd_display_inversion_control(driver, 0x00);
    lcd_power_control_1(driver, 0x21);
    lcd_power_control_2(driver, 0x11);
    lcd_vcom_control_1(driver, 0x3F, 0x3C);
    lcd_vcom_control_2(driver, 0xB5);
    // lcd_memory_access_control(driver, MADCTL_MY | MADCTL_BGR);
    lcd_pixel_format_set(driver, DPI_16BIT | DBI_16BIT);
    lcd_frame_rate_control_1(driver, 0x00, 0x1B);
    // lcd_memory_access_control(driver, MADCTL_MX | MADCTL_BGR);
    lcd_enable_3G(driver, 0x00);
    lcd_gamma_set(driver, 0x01);
    lcd_positive_gamma_correction(driver, pgc_values);
    lcd_negative_gamma_correction(driver, ngc_values);
    lcd_entry_mode_set(driver, 0x07);
    lcd_sleep_out(driver);
    _delay_ms(150);
    lcd_display_on(driver);
}

void lcd_reset(struct lcd_driver_t *driver)
{
    _csx_high(driver);
    _reset_low(driver);
    _delay_us(20);
    _reset_high(driver);
}

// Level 1 commands

void lcd_nop(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_NOP);
}

void lcd_swreset(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_SWRESET);
}

uint32_t lcd_read_display_status(struct lcd_driver_t *driver)
{
    uint8_t data[4];
    uint32_t result;
    
    _lcd_command_read_data(driver, CMD_RDDST, data, 4);
    result = (uint32_t)(data[0]) 
            + ((uint32_t)(data[1]) << 8) 
            + ((uint32_t)(data[2]) << 16)
            + ((uint32_t)(data[3]) << 24);
    return result;
}

uint8_t lcd_read_display_power_mode(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDDPM);
}

uint8_t lcd_read_display_MADCTL(struct lcd_driver_t *driver)
{
    driver->madctl = _lcd_command_read_single_byte(driver, CMD_RDDMADCTL);
    return driver->madctl;
}

uint8_t lcd_read_display_pixel_format(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDDCOLMOD);
}

uint8_t lcd_read_display_image_format(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDDIM);
}

uint8_t lcd_read_display_signal_mode(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDDSM);
}

uint8_t lcd_read_display_self_diagnostic_result(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDDSDR);
}

void lcd_enter_sleep_mode(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_SPLIN);
}

void lcd_sleep_out(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_SLPOUT);
    _delay_us(5);  // wait for LCD chip to stabilize
}

void lcd_partial_mode_on(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_PTLON);
}

void lcd_normal_display_mode_on(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_NORON);
}

void lcd_display_inversion_off(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_DINVOFF);
}

void lcd_display_inversion_on(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_DINVON);
}

signed short lcd_gamma_set(struct lcd_driver_t *driver, uint8_t gamma_curve)
{   
    uint8_t curve_bit;
    
    // gamma_curve: a value between 1 and 4 incl.
    if (gamma_curve < 1 || gamma_curve > 4) return -1;
    
    curve_bit = 1 << (gamma_curve - 1);
    _lcd_write_command(driver, CMD_GAMSET, &curve_bit, 1);
    return 0;
}

void lcd_display_off(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_DISPOFF);
}

void lcd_display_on(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_DISPON);
}

signed short lcd_column_address_set(struct lcd_driver_t *driver, 
        uint16_t sc, uint16_t ec)
{
    uint8_t data[4];
    
    // SC[15:0] <= EC[15:0]
    if (sc > ec) return -1;
    // SC and EC cannot be out of range
    if (sc > driver->res_x || ec > driver->res_x) return -2;
    
    data[0] = sc >> 8;      // 1st parameter
    data[1] = sc & 0xFF;    // 2nd parameter
    data[2] = ec >> 8;      // 3rd parameter
    data[3] = ec & 0xFF;    // 4th parameter
    _lcd_write_command(driver, CMD_CASET, data, 4);
    return 0;
}

signed short lcd_page_address_set(struct lcd_driver_t *driver,
        uint16_t sp, uint16_t ep)
{
    uint8_t data[4];
    
    // SP[15:0] <= EP[15:0]
    if (sp > ep) return -1;
    // SP and EP cannot be out of range
    if (sp > driver->res_y || ep > driver->res_y) return -2;
    
    data[0] = sp >> 8;      // 1st parameter
    data[1] = sp & 0xFF;    // 2nd parameter
    data[2] = ep >> 8;      // 3rd parameter
    data[3] = ep & 0xFF;    // 4th parameter
    _lcd_write_command(driver, CMD_PASET, data, 4);
    return 0;
}

void lcd_memory_write(struct lcd_driver_t *driver, uint16_t *data, uint32_t size)
{
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    spi_transfer(CMD_RAMWR);  // transmit the command
    _dcx_data(driver);  // transmit data
    for (uint32_t i = 0; i < size; ++i) {
        spi_transfer(data[i] >> 8);
        spi_transfer(data[i] & 0xFF);
    }
    _csx_high(driver);  // deselect the device
}

signed short lcd_partial_area(struct lcd_driver_t *driver, 
        uint16_t sr, uint16_t er)
{
    uint8_t data[4];
    
    if (sr == 0 || er == 0 
            || sr > driver->res_y || er > driver->res_y) return -1;
    
    data[0] = sr >> 8;      // 1st parameter
    data[1] = sr & 0xFF;    // 2nd parameter
    data[2] = er >> 8;      // 3rd parameter
    data[3] = er & 0xFF;    // 4th parameter
    _lcd_write_command(driver, CMD_PLTAR, data, 4);
    return 0;
}

signed short lcd_vertical_scrolling_definition(struct lcd_driver_t *driver,
        uint16_t tfa, uint16_t vsa, uint16_t bfa)
{
    uint8_t data[6];
    
    data[0] = tfa >> 8;     // 1st parameter
    data[1] = tfa & 0xFF;   // 2nd parameter
    data[2] = vsa >> 8;     // 3rd parameter
    data[3] = vsa & 0xFF;   // 4th parameter
    data[4] = bfa >> 8;     // 5th parameter
    data[5] = bfa & 0xFF;   // 6th parameter
    _lcd_write_command(driver, CMD_VSCRDEF, data, 6);
    return 0;
}

void lcd_tearing_effect_line_off(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_TEOFF);
}

void lcd_tearing_effect_line_on(struct lcd_driver_t *driver, uint8_t mode)
{
    /* mode:
     * bit 0: m
     * bits 1-7: not used
     */
    _lcd_write_command(driver, CMD_TEON, &mode, 1);
}

void lcd_memory_access_control(struct lcd_driver_t *driver, uint8_t madctl)
{       
    driver->madctl = madctl;
    driver->res_x = (madctl & MADCTL_MV) ? LCD_RESY : LCD_RESX;
    driver->res_y = (madctl & MADCTL_MV) ? LCD_RESX : LCD_RESY;
    _lcd_write_command(driver, CMD_MADCTL, &madctl, 1);
}

signed short lcd_vertical_scrolling_start_address(struct lcd_driver_t *driver, 
        uint16_t vsp)
{
    uint8_t data[2];
    
    data[0] = vsp >> 8;     // 1st parameter
    data[1] = vsp & 0xFF;   // 2nd parameter
    _lcd_write_command(driver, CMD_VSCRSADD, data, 2);
    return 0;
}

void lcd_idle_mode_off(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_IDMOFF);
}

void lcd_idle_mode_on(struct lcd_driver_t *driver)
{
    _lcd_command_no_parameter(driver, CMD_IDMON);
}

void lcd_pixel_format_set(struct lcd_driver_t *driver, uint8_t format)
{
    // NOTE: please use the DPI_xBIT/DBI_xBIT macros in the chip's header file
    _lcd_write_command(driver, CMD_PIXSET, &format, 1);
}

void lcd_memory_write_continue(struct lcd_driver_t *driver, 
        uint16_t *data, uint32_t size)
{
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    spi_transfer(CMD_WRITE_MEMORY_CONTINUE);  // transmit the command
    _dcx_data(driver);  // transmit data
    for (uint32_t i = 0; i < size; ++i) {
        spi_transfer(data[i] >> 8);
        spi_transfer(data[i] & 0xFF);
    }
    _csx_high(driver);  // deselect the device
}

void lcd_write_display_brightness(struct lcd_driver_t *driver, uint8_t dbv)
{
    _lcd_write_command(driver, CMD_WRDISBV, &dbv, 1);
}

uint8_t lcd_read_display_brightness(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDDISBV);
}

void lcd_write_ctrl_display(struct lcd_driver_t *driver, uint8_t parameter)
{
    // NOTE: please use the BLCTRL_x macros in the chip's header file
    _lcd_write_command(driver, CMD_WRCTRLD, &parameter, 1);
}

uint8_t lcd_read_ctrl_display(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDCTRLD);
}

void lcd_write_content_adaptive_brightness_control(struct lcd_driver_t *driver, 
        uint8_t cabc)
{
    _lcd_write_command(driver, CMD_WRCABC, &cabc, 1);
}

uint8_t lcd_read_content_adaptive_brightness_control(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDCABC);
}

void lcd_write_cabc_minimum_brightness(struct lcd_driver_t *driver,
        uint8_t cmb)
{
    _lcd_write_command(driver, CMD_WRITE_CABC_MINIMUM_BRIGHTNESS, &cmb, 1);
}

uint8_t lcd_read_cabc_minimum_brightness(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_READ_CABC_MINIMUM_BRIGHTNESS);
}

uint8_t lcd_read_id1(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDID1);
}

uint8_t lcd_read_id2(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDID2);
}

uint8_t lcd_read_id3(struct lcd_driver_t *driver)
{
    return _lcd_command_read_single_byte(driver, CMD_RDID3);
}

// Level 2 commands

void lcd_rgb_interface_signal_control(struct lcd_driver_t *driver, uint8_t settings)
{
    _lcd_write_command(driver, CMD_IFMODE, &settings, 1);
}

void lcd_frame_rate_control_1(struct lcd_driver_t *driver, 
        uint8_t diva, uint8_t rtna)
{
    uint8_t data[2];
    
    data[0] = diva;
    data[1] = rtna;
    _lcd_write_command(driver, CMD_FRMCTR1, data, 2);
}

void lcd_display_inversion_control(struct lcd_driver_t *driver, uint8_t inv_mode)
{
    _lcd_write_command(driver, CMD_INVTR, &inv_mode, 1);
}

void lcd_entry_mode_set(struct lcd_driver_t *driver, uint8_t settings)
{
    _lcd_write_command(driver, CMD_ETMOD, &settings, 1);
}

void lcd_power_control_1(struct lcd_driver_t *driver, uint8_t vrh)
{
    _lcd_write_command(driver, CMD_PWCTRL1, &vrh, 1);
}

void lcd_power_control_2(struct lcd_driver_t *driver, uint8_t bt)
{
    _lcd_write_command(driver, CMD_PWCTRL2, &bt, 1);
}

void lcd_vcom_control_1(struct lcd_driver_t *driver, uint8_t vmh, uint8_t vml)
{
    uint8_t data[2];
    
    data[0] = vmh;
    data[1] = vml;
    _lcd_write_command(driver, CMD_VMCTRL1, data, 2);
}

void lcd_vcom_control_2(struct lcd_driver_t *driver, uint8_t vmf)
{
    _lcd_write_command(driver, CMD_VMCTRL2, &vmf, 1);
}

void lcd_positive_gamma_correction(struct lcd_driver_t *driver, uint8_t *data)
{
    _lcd_write_command(driver, CMD_PGAMCTRL, data, 15);
}

void lcd_negative_gamma_correction(struct lcd_driver_t *driver, uint8_t *data)
{
    _lcd_write_command(driver, CMD_NGAMCTRL, data, 15);
}

// Extended register command set

void lcd_interface_control(struct lcd_driver_t *driver, 
        uint8_t first, uint8_t second, uint8_t third)
{
    uint8_t data[3];
    
    data[0] = first;  // 1st parameter
    data[1] = second;  // 1st parameter
    data[2] = third;  // 1st parameter
    _lcd_write_command(driver, CMD_IFCTL, data, 3);
}

void lcd_power_control_a(struct lcd_driver_t *driver,
        uint8_t vcore_control, uint8_t ddvdh_control)
{
    uint8_t data[5];
    
    data[0] = 0x39;
    data[1] = 0x2C;
    data[2] = 0x00;
    data[3] = vcore_control;
    data[4] = ddvdh_control;
    _lcd_write_command(driver, CMD_POWER_CONTROL_A, data, 5);
}

void lcd_power_control_b(struct lcd_driver_t *driver,
        uint8_t power_control, uint8_t dc_ena)
{
    uint8_t data[3];
    
    data[0] = 0x00;
    data[1] = power_control;
    data[2] = dc_ena;
    _lcd_write_command(driver, CMD_POWER_CONTROL_B, data, 3);
}

void lcd_driver_timing_control_a(struct lcd_driver_t *driver,
        uint8_t first, uint8_t second, uint8_t third)
{
    uint8_t data[3];
    
    data[0] = first;
    data[1] = second;
    data[2] = third;
    _lcd_write_command(driver, CMD_DRIVER_TIMING_CONTROL_A, data, 3);
}

void lcd_driver_timing_control_b(struct lcd_driver_t *driver, uint8_t first)
{
    uint8_t data[2];
    
    data[0] = first;
    data[1] = 0x00;
    _lcd_write_command(driver, CMD_DRIVER_TIMING_CONTROL_B, data, 2);
}

void lcd_power_on_sequence_control(struct lcd_driver_t *driver, 
        uint8_t first, uint8_t second, uint8_t third, uint8_t forth)
{
    uint8_t data[4];
    
    data[0] = first;
    data[1] = second;
    data[2] = third;
    data[3] = forth;
    _lcd_write_command(driver, CMD_POWER_ON_SEQUENCE_CONTROL, data, 4);
}

void lcd_enable_3G(struct lcd_driver_t *driver, uint8_t enb_3G)
{
    _lcd_write_command(driver, CMD_ENABLE_3G, &enb_3G, 1);
}

void lcd_pump_ratio_control(struct lcd_driver_t *driver, uint8_t ratio_control)
{
    _lcd_write_command(driver, CMD_PUMP_RATIO_CONTROL, &ratio_control, 1);
}

uint16_t color565(uint8_t r, uint8_t g, uint8_t b)
{
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3);
}

static void _lcd_command_no_parameter(struct lcd_driver_t *driver, 
        uint8_t command)
{
    _csx_low(driver);  // select the device
    _dcx_command(driver);  // transmit a command
    spi_transfer(0x00);
    spi_transfer(command);  // transmit the command
    _csx_high(driver);  // deselect the device
}

static uint8_t _lcd_command_read_single_byte(struct lcd_driver_t *driver, 
        uint8_t command)
{
    uint8_t result;
    
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    spi_transfer(command);  // transmit the command
    _dcx_data(driver);  // transmit data
    spi_transfer(_LCD_DRIVER_NO_VALUE);  // read dummy parameter (1st)
    result = spi_transfer(_LCD_DRIVER_NO_VALUE);  // read data (2nd)
    _csx_high(driver);  // deselect the device
    return result;
}

static void _lcd_command_read_data(struct lcd_driver_t *driver, 
        uint8_t command, uint8_t *data, short nparams)
{
    // WARNING: the 'data' array must be with length 'nparams'
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    spi_transfer(command);  // transmit the command
    _dcx_data(driver);  // transmit data
    spi_transfer(_LCD_DRIVER_NO_VALUE);  // read dummy parameter (1st)
    for (short i = 0; i < nparams; ++i)
        data[i] = spi_transfer(_LCD_DRIVER_NO_VALUE);  // receive each data byte
    _csx_high(driver);  // deselect the device
}

static void _lcd_write_command(struct lcd_driver_t *driver, 
        uint8_t command, uint8_t *data, short nparams)
{
    // WARNING: the 'data' array must be with length 'nparams'
    _dcx_command(driver);  // transmit a command
    _csx_low(driver);  // select the device
    spi_transfer(0x00);
    spi_transfer(command);  // transmit the command
    _dcx_data(driver);  // transmit data
    for (short i = 0; i < nparams; ++i)
        spi_transfer(data[i]);
    _csx_high(driver);  // deselect the device
}
