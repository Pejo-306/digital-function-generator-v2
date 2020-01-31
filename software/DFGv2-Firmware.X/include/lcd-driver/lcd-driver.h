/* 
 * File:   lcd-driver.h
 * Author: pesho
 *
 * Created on January 28, 2020, 9:14 PM
 */

#ifndef LCD_DRIVER_H
#define	LCD_DRIVER_H

#include <inttypes.h>

#include "defs.h"
#include "lcd-driver/lcd-driver-chip.h"
#include "avr_controllers/spi_controller.h"

#define _LCD_DRIVER_NO_VALUE 0x00

// send a data byte via the D/CX line
#define _dcx_data(lcd_driver) { \
    *lcd_driver->dcx.port |= (1 << lcd_driver->dcx.pin); \
}
    
// send a command byte via the D/CX line
#define _dcx_command(lcd_driver) { \
    *lcd_driver->dcx.port &= ~(1 << lcd_driver->dcx.pin); \
}
    
// deselect the LCD driver (output a HIGH level to Chip Select)
#define _csx_high(lcd_driver) { \
    *lcd_driver->csx.port |= (1 << lcd_driver->csx.pin); \
}
    
// select the LCD driver (output a LOW level to Chip Select)
#define _csx_low(lcd_driver) { \
    *lcd_driver->csx.port &= ~(1 << lcd_driver->csx.pin); \
}

// output a HIGH level to the RESET line
#define _reset_high(lcd_driver) { \
    *lcd_driver->reset.port |= (1 << lcd_driver->reset.pin); \
}
    
// output a LOW level to the RESET line
#define _reset_low(lcd_driver) { \
    *lcd_driver->reset.port &= ~(1 << lcd_driver->reset.pin); \
}

#ifdef	__cplusplus
extern "C" {
#endif

struct lcd_driver_t {
    struct spi_interface_t spi;  // SPI interface
    struct pin_ref_t dcx;  // Data/Command
    struct pin_ref_t reset;  // Reset
    struct pin_ref_t csx;  // Chip Select
    uint8_t madctl;
    uint16_t res_x;
    uint16_t res_y;
};

void lcd_driver_init(struct lcd_driver_t *, fbool);

void lcd_power_on(struct lcd_driver_t *);

void lcd_reset(struct lcd_driver_t *);

// Level 1 commands

void lcd_nop(struct lcd_driver_t *);

void lcd_swreset(struct lcd_driver_t *);

uint32_t lcd_read_display_status(struct lcd_driver_t *);

uint8_t lcd_read_display_power_mode(struct lcd_driver_t *);

uint8_t lcd_read_display_MADCTL(struct lcd_driver_t *);

uint8_t lcd_read_display_pixel_format(struct lcd_driver_t *);

uint8_t lcd_read_display_image_format(struct lcd_driver_t *);

uint8_t lcd_read_display_signal_mode(struct lcd_driver_t *);

uint8_t lcd_read_display_self_diagnostic_result(struct lcd_driver_t *);

void lcd_enter_sleep_mode(struct lcd_driver_t *);

void lcd_sleep_out(struct lcd_driver_t *);

void lcd_partial_mode_on(struct lcd_driver_t *);

void lcd_normal_display_mode_on(struct lcd_driver_t *);

void lcd_display_inversion_off(struct lcd_driver_t *);

void lcd_display_inversion_on(struct lcd_driver_t *);

signed short lcd_gamma_set(struct lcd_driver_t *, uint8_t);

void lcd_display_off(struct lcd_driver_t *);

void lcd_display_on(struct lcd_driver_t *);

signed short lcd_column_address_set(struct lcd_driver_t *, uint16_t, uint16_t);

signed short lcd_page_address_set(struct lcd_driver_t *, uint16_t, uint16_t);

void lcd_memory_write(struct lcd_driver_t *, uint16_t *, uint32_t);

// NOTE: Color Set (2Dh) is used in 16-bit parallel interface

// TODO: Memory Read (2Eh)

signed short lcd_partial_area(struct lcd_driver_t *, uint16_t, uint16_t);

signed short lcd_vertical_scrolling_definition(struct lcd_driver_t *,
        uint16_t, uint16_t, uint16_t);

void lcd_tearing_effect_line_off(struct lcd_driver_t *);

void lcd_tearing_effect_line_on(struct lcd_driver_t *, uint8_t);

void lcd_memory_access_control(struct lcd_driver_t *, uint8_t);

signed short lcd_vertical_scrolling_start_address(struct lcd_driver_t *, uint16_t);

void lcd_idle_mode_off(struct lcd_driver_t *);

void lcd_idle_mode_on(struct lcd_driver_t *);

void lcd_pixel_format_set(struct lcd_driver_t *, uint8_t);

void lcd_memory_write_continue(struct lcd_driver_t *, uint16_t *, uint32_t);

// TODO: Read Memory Continue (3Eh)

// TODO: Set Tear Scanline (44h)

// TODO: Get Scanline (45h)

void lcd_write_display_brightness(struct lcd_driver_t *, uint8_t);

uint8_t lcd_read_display_brightness(struct lcd_driver_t *);

void lcd_write_ctrl_display(struct lcd_driver_t *, uint8_t);

uint8_t lcd_read_ctrl_display(struct lcd_driver_t *);

void lcd_write_content_adaptive_brightness_control(struct lcd_driver_t *, uint8_t);

uint8_t lcd_read_content_adaptive_brightness_control(struct lcd_driver_t *);

void lcd_write_cabc_minimum_brightness(struct lcd_driver_t *, uint8_t);

uint8_t lcd_read_cabc_minimum_brightness(struct lcd_driver_t *);

uint8_t lcd_read_id1(struct lcd_driver_t *);

uint8_t lcd_read_id2(struct lcd_driver_t *);

uint8_t lcd_read_id3(struct lcd_driver_t *);

// Level 2 commands

void lcd_rgb_interface_signal_control(struct lcd_driver_t *, uint8_t);

void lcd_frame_rate_control_1(struct lcd_driver_t *, uint8_t, uint8_t);

void lcd_display_inversion_control(struct lcd_driver_t *, uint8_t);

void lcd_entry_mode_set(struct lcd_driver_t *, uint8_t);

void lcd_power_control_1(struct lcd_driver_t *, uint8_t);

void lcd_power_control_2(struct lcd_driver_t *, uint8_t);

void lcd_vcom_control_1(struct lcd_driver_t *, uint8_t, uint8_t);

void lcd_vcom_control_2(struct lcd_driver_t *, uint8_t);

void lcd_positive_gamma_correction(struct lcd_driver_t *, uint8_t *);

void lcd_negative_gamma_correction(struct lcd_driver_t *, uint8_t *);

// Extended register command set

void lcd_interface_control(struct lcd_driver_t *, uint8_t, uint8_t, uint8_t);

void lcd_power_control_a(struct lcd_driver_t *, uint8_t, uint8_t);

void lcd_power_control_b(struct lcd_driver_t *, uint8_t, uint8_t);

void lcd_driver_timing_control_a(struct lcd_driver_t *, uint8_t, uint8_t, uint8_t);

void lcd_driver_timing_control_b(struct lcd_driver_t *, uint8_t);

void lcd_power_on_sequence_control(struct lcd_driver_t *, 
        uint8_t, uint8_t, uint8_t, uint8_t);

void lcd_enable_3G(struct lcd_driver_t *, uint8_t);

void lcd_pump_ratio_control(struct lcd_driver_t *, uint8_t);

uint16_t color565(uint8_t, uint8_t, uint8_t);

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_DRIVER_H */
