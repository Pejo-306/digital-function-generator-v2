/*
 * File:   main.c
 * Author: pesho
 *
 * Created on January 25, 2020, 6:47 PM
 */

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "init_mcu.h"
#include "avr_controllers/twi_controller.h"
#include "avr_controllers/spi_controller.h"
#include "lcd-driver/lcd-driver.h"
#include "lcd-driver/graphics.h"

#include "lcd-driver/font8x8.h"

#include "user-interface/ui_helper.h"
#include "user-interface/ui_main_menu.h"
#include "user-interface/ui_options_menu.h"
#include "touch-panel-driver/touch-panel-driver.h"

#include "DFG-firmware/DDS_firmware.h"
#include "DFG-firmware/IOexpander_driver.h"
#include "DFG-firmware/programmable_oscillator_driver.h"

int main(void)
{       
    init_mcu();
    twi_init();
    twi_set_speed(TWI_400KHZ, 0);
    twi_set_slave_address(0x00);
    
    struct pin_ref_t oscoe = { &PORTF, PF2 };
    osc_conf_mux_word(U8_TWI_ADDRESS, 0x2780);  // sets P0 and P1 to 8
    osc_output_disable(oscoe);
    
    set_dc_offset(0x0);
     
    struct pin_ref_t pwrdwn = { &PORTF, PF0 };
    struct pin_ref_t cmr1 = { &PORTB, PB4 };
    struct pin_ref_t cmr2 = { &PORTB, PB5 };
    struct pin_ref_t cp = { &PORTB, PB7 };
    power_up(pwrdwn);
    
    struct pin_ref_t rw = { &PORTB, PB6 };
    uint16_t data[1024] = { 
0x8000, 0x80c0, 0x8190, 0x8250, 0x8320, 0x83e0, 0x84b0, 0x8570, 
0x8640, 0x8710, 0x87d0, 0x88a0, 0x8960, 0x8a30, 0x8af0, 0x8bc0, 
0x8c80, 0x8d50, 0x8e10, 0x8ee0, 0x8fa0, 0x9070, 0x9130, 0x91f0, 
0x92c0, 0x9380, 0x9450, 0x9510, 0x95e0, 0x96a0, 0x9760, 0x9830, 
0x98f0, 0x99b0, 0x9a80, 0x9b40, 0x9c00, 0x9cc0, 0x9d90, 0x9e50, 
0x9f10, 0x9fd0, 0xa090, 0xa150, 0xa220, 0xa2e0, 0xa3a0, 0xa460, 
0xa520, 0xa5e0, 0xa6a0, 0xa760, 0xa820, 0xa8e0, 0xa9a0, 0xaa50, 
0xab10, 0xabd0, 0xac90, 0xad50, 0xae00, 0xaec0, 0xaf80, 0xb030, 
0xb0f0, 0xb1b0, 0xb260, 0xb320, 0xb3d0, 0xb490, 0xb540, 0xb600, 
0xb6b0, 0xb760, 0xb820, 0xb8d0, 0xb980, 0xba30, 0xbae0, 0xbba0, 
0xbc50, 0xbd00, 0xbdb0, 0xbe60, 0xbf10, 0xbfc0, 0xc060, 0xc110, 
0xc1c0, 0xc270, 0xc320, 0xc3c0, 0xc470, 0xc520, 0xc5c0, 0xc670, 
0xc710, 0xc7b0, 0xc860, 0xc900, 0xc9a0, 0xca50, 0xcaf0, 0xcb90, 
0xcc30, 0xccd0, 0xcd70, 0xce10, 0xceb0, 0xcf50, 0xcff0, 0xd090, 
0xd120, 0xd1c0, 0xd260, 0xd2f0, 0xd390, 0xd420, 0xd4c0, 0xd550, 
0xd5f0, 0xd680, 0xd710, 0xd7a0, 0xd830, 0xd8c0, 0xd950, 0xd9e0, 
0xda70, 0xdb00, 0xdb90, 0xdc20, 0xdca0, 0xdd30, 0xddc0, 0xde40, 
0xded0, 0xdf50, 0xdfd0, 0xe060, 0xe0e0, 0xe160, 0xe1e0, 0xe260, 
0xe2e0, 0xe360, 0xe3e0, 0xe460, 0xe4e0, 0xe550, 0xe5d0, 0xe650, 
0xe6c0, 0xe740, 0xe7b0, 0xe820, 0xe8a0, 0xe910, 0xe980, 0xe9f0, 
0xea60, 0xead0, 0xeb40, 0xebb0, 0xec10, 0xec80, 0xecf0, 0xed50, 
0xedc0, 0xee20, 0xee80, 0xeef0, 0xef50, 0xefb0, 0xf010, 0xf070, 
0xf0d0, 0xf130, 0xf190, 0xf1f0, 0xf240, 0xf2a0, 0xf300, 0xf350, 
0xf3a0, 0xf400, 0xf450, 0xf4a0, 0xf4f0, 0xf540, 0xf590, 0xf5e0, 
0xf630, 0xf680, 0xf6d0, 0xf710, 0xf760, 0xf7a0, 0xf7f0, 0xf830, 
0xf870, 0xf8c0, 0xf900, 0xf940, 0xf980, 0xf9c0, 0xf9f0, 0xfa30, 
0xfa70, 0xfaa0, 0xfae0, 0xfb10, 0xfb50, 0xfb80, 0xfbb0, 0xfbf0, 
0xfc20, 0xfc50, 0xfc80, 0xfca0, 0xfcd0, 0xfd00, 0xfd30, 0xfd50, 
0xfd80, 0xfda0, 0xfdc0, 0xfdf0, 0xfe10, 0xfe30, 0xfe50, 0xfe70, 
0xfe90, 0xfeb0, 0xfec0, 0xfee0, 0xff00, 0xff10, 0xff30, 0xff40, 
0xff50, 0xff60, 0xff70, 0xff80, 0xff90, 0xffa0, 0xffb0, 0xffc0, 
0xffd0, 0xffd0, 0xffe0, 0xffe0, 0xffe0, 0xfff0, 0xfff0, 0xfff0, 
0xfff0, 0xfff0, 0xfff0, 0xfff0, 0xffe0, 0xffe0, 0xffe0, 0xffd0, 
0xffd0, 0xffc0, 0xffb0, 0xffa0, 0xff90, 0xff80, 0xff70, 0xff60, 
0xff50, 0xff40, 0xff30, 0xff10, 0xff00, 0xfee0, 0xfec0, 0xfeb0, 
0xfe90, 0xfe70, 0xfe50, 0xfe30, 0xfe10, 0xfdf0, 0xfdc0, 0xfda0, 
0xfd80, 0xfd50, 0xfd30, 0xfd00, 0xfcd0, 0xfca0, 0xfc80, 0xfc50, 
0xfc20, 0xfbf0, 0xfbb0, 0xfb80, 0xfb50, 0xfb10, 0xfae0, 0xfaa0, 
0xfa70, 0xfa30, 0xf9f0, 0xf9c0, 0xf980, 0xf940, 0xf900, 0xf8c0, 
0xf870, 0xf830, 0xf7f0, 0xf7a0, 0xf760, 0xf710, 0xf6d0, 0xf680, 
0xf630, 0xf5e0, 0xf590, 0xf540, 0xf4f0, 0xf4a0, 0xf450, 0xf400, 
0xf3a0, 0xf350, 0xf300, 0xf2a0, 0xf240, 0xf1f0, 0xf190, 0xf130, 
0xf0d0, 0xf070, 0xf010, 0xefb0, 0xef50, 0xeef0, 0xee80, 0xee20, 
0xedc0, 0xed50, 0xecf0, 0xec80, 0xec10, 0xebb0, 0xeb40, 0xead0, 
0xea60, 0xe9f0, 0xe980, 0xe910, 0xe8a0, 0xe820, 0xe7b0, 0xe740, 
0xe6c0, 0xe650, 0xe5d0, 0xe550, 0xe4e0, 0xe460, 0xe3e0, 0xe360, 
0xe2e0, 0xe260, 0xe1e0, 0xe160, 0xe0e0, 0xe060, 0xdfd0, 0xdf50, 
0xded0, 0xde40, 0xddc0, 0xdd30, 0xdca0, 0xdc20, 0xdb90, 0xdb00, 
0xda70, 0xd9e0, 0xd950, 0xd8c0, 0xd830, 0xd7a0, 0xd710, 0xd680, 
0xd5f0, 0xd550, 0xd4c0, 0xd420, 0xd390, 0xd2f0, 0xd260, 0xd1c0, 
0xd120, 0xd090, 0xcff0, 0xcf50, 0xceb0, 0xce10, 0xcd70, 0xccd0, 
0xcc30, 0xcb90, 0xcaf0, 0xca50, 0xc9a0, 0xc900, 0xc860, 0xc7b0, 
0xc710, 0xc670, 0xc5c0, 0xc520, 0xc470, 0xc3c0, 0xc320, 0xc270, 
0xc1c0, 0xc110, 0xc060, 0xbfc0, 0xbf10, 0xbe60, 0xbdb0, 0xbd00, 
0xbc50, 0xbba0, 0xbae0, 0xba30, 0xb980, 0xb8d0, 0xb820, 0xb760, 
0xb6b0, 0xb600, 0xb540, 0xb490, 0xb3d0, 0xb320, 0xb260, 0xb1b0, 
0xb0f0, 0xb030, 0xaf80, 0xaec0, 0xae00, 0xad50, 0xac90, 0xabd0, 
0xab10, 0xaa50, 0xa9a0, 0xa8e0, 0xa820, 0xa760, 0xa6a0, 0xa5e0, 
0xa520, 0xa460, 0xa3a0, 0xa2e0, 0xa220, 0xa150, 0xa090, 0x9fd0, 
0x9f10, 0x9e50, 0x9d90, 0x9cc0, 0x9c00, 0x9b40, 0x9a80, 0x99b0, 
0x98f0, 0x9830, 0x9760, 0x96a0, 0x95e0, 0x9510, 0x9450, 0x9380, 
0x92c0, 0x91f0, 0x9130, 0x9070, 0x8fa0, 0x8ee0, 0x8e10, 0x8d50, 
0x8c80, 0x8bc0, 0x8af0, 0x8a30, 0x8960, 0x88a0, 0x87d0, 0x8710, 
0x8640, 0x8570, 0x84b0, 0x83e0, 0x8320, 0x8250, 0x8190, 0x80c0, 
0x8000, 0x7f30, 0x7e60, 0x7da0, 0x7cd0, 0x7c10, 0x7b40, 0x7a80, 
0x79b0, 0x78e0, 0x7820, 0x7750, 0x7690, 0x75c0, 0x7500, 0x7430, 
0x7370, 0x72a0, 0x71e0, 0x7110, 0x7050, 0x6f80, 0x6ec0, 0x6e00, 
0x6d30, 0x6c70, 0x6ba0, 0x6ae0, 0x6a10, 0x6950, 0x6890, 0x67c0, 
0x6700, 0x6640, 0x6570, 0x64b0, 0x63f0, 0x6330, 0x6260, 0x61a0, 
0x60e0, 0x6020, 0x5f60, 0x5ea0, 0x5dd0, 0x5d10, 0x5c50, 0x5b90, 
0x5ad0, 0x5a10, 0x5950, 0x5890, 0x57d0, 0x5710, 0x5650, 0x55a0, 
0x54e0, 0x5420, 0x5360, 0x52a0, 0x51f0, 0x5130, 0x5070, 0x4fc0, 
0x4f00, 0x4e40, 0x4d90, 0x4cd0, 0x4c20, 0x4b60, 0x4ab0, 0x49f0, 
0x4940, 0x4890, 0x47d0, 0x4720, 0x4670, 0x45c0, 0x4510, 0x4450, 
0x43a0, 0x42f0, 0x4240, 0x4190, 0x40e0, 0x4030, 0x3f90, 0x3ee0, 
0x3e30, 0x3d80, 0x3cd0, 0x3c30, 0x3b80, 0x3ad0, 0x3a30, 0x3980, 
0x38e0, 0x3840, 0x3790, 0x36f0, 0x3650, 0x35a0, 0x3500, 0x3460, 
0x33c0, 0x3320, 0x3280, 0x31e0, 0x3140, 0x30a0, 0x3000, 0x2f60, 
0x2ed0, 0x2e30, 0x2d90, 0x2d00, 0x2c60, 0x2bd0, 0x2b30, 0x2aa0, 
0x2a00, 0x2970, 0x28e0, 0x2850, 0x27c0, 0x2730, 0x26a0, 0x2610, 
0x2580, 0x24f0, 0x2460, 0x23d0, 0x2350, 0x22c0, 0x2230, 0x21b0, 
0x2120, 0x20a0, 0x2020, 0x1f90, 0x1f10, 0x1e90, 0x1e10, 0x1d90, 
0x1d10, 0x1c90, 0x1c10, 0x1b90, 0x1b10, 0x1aa0, 0x1a20, 0x19a0, 
0x1930, 0x18b0, 0x1840, 0x17d0, 0x1750, 0x16e0, 0x1670, 0x1600, 
0x1590, 0x1520, 0x14b0, 0x1440, 0x13e0, 0x1370, 0x1300, 0x12a0, 
0x1230, 0x11d0, 0x1170, 0x1100, 0x10a0, 0x1040, 0xfe0, 0xf80, 
0xf20, 0xec0, 0xe60, 0xe00, 0xdb0, 0xd50, 0xcf0, 0xca0, 
0xc50, 0xbf0, 0xba0, 0xb50, 0xb00, 0xab0, 0xa60, 0xa10, 
0x9c0, 0x970, 0x920, 0x8e0, 0x890, 0x850, 0x800, 0x7c0, 
0x780, 0x730, 0x6f0, 0x6b0, 0x670, 0x630, 0x600, 0x5c0, 
0x580, 0x550, 0x510, 0x4e0, 0x4a0, 0x470, 0x440, 0x400, 
0x3d0, 0x3a0, 0x370, 0x350, 0x320, 0x2f0, 0x2c0, 0x2a0, 
0x270, 0x250, 0x230, 0x200, 0x1e0, 0x1c0, 0x1a0, 0x180, 
0x160, 0x140, 0x130, 0x110, 0xf0, 0xe0, 0xc0, 0xb0, 
0xa0, 0x90, 0x80, 0x70, 0x60, 0x50, 0x40, 0x30, 
0x20, 0x20, 0x10, 0x10, 0x10, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x10, 0x20, 
0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 
0xa0, 0xb0, 0xc0, 0xe0, 0xf0, 0x110, 0x130, 0x140, 
0x160, 0x180, 0x1a0, 0x1c0, 0x1e0, 0x200, 0x230, 0x250, 
0x270, 0x2a0, 0x2c0, 0x2f0, 0x320, 0x350, 0x370, 0x3a0, 
0x3d0, 0x400, 0x440, 0x470, 0x4a0, 0x4e0, 0x510, 0x550, 
0x580, 0x5c0, 0x600, 0x630, 0x670, 0x6b0, 0x6f0, 0x730, 
0x780, 0x7c0, 0x800, 0x850, 0x890, 0x8e0, 0x920, 0x970, 
0x9c0, 0xa10, 0xa60, 0xab0, 0xb00, 0xb50, 0xba0, 0xbf0, 
0xc50, 0xca0, 0xcf0, 0xd50, 0xdb0, 0xe00, 0xe60, 0xec0, 
0xf20, 0xf80, 0xfe0, 0x1040, 0x10a0, 0x1100, 0x1170, 0x11d0, 
0x1230, 0x12a0, 0x1300, 0x1370, 0x13e0, 0x1440, 0x14b0, 0x1520, 
0x1590, 0x1600, 0x1670, 0x16e0, 0x1750, 0x17d0, 0x1840, 0x18b0, 
0x1930, 0x19a0, 0x1a20, 0x1aa0, 0x1b10, 0x1b90, 0x1c10, 0x1c90, 
0x1d10, 0x1d90, 0x1e10, 0x1e90, 0x1f10, 0x1f90, 0x2020, 0x20a0, 
0x2120, 0x21b0, 0x2230, 0x22c0, 0x2350, 0x23d0, 0x2460, 0x24f0, 
0x2580, 0x2610, 0x26a0, 0x2730, 0x27c0, 0x2850, 0x28e0, 0x2970, 
0x2a00, 0x2aa0, 0x2b30, 0x2bd0, 0x2c60, 0x2d00, 0x2d90, 0x2e30, 
0x2ed0, 0x2f60, 0x3000, 0x30a0, 0x3140, 0x31e0, 0x3280, 0x3320, 
0x33c0, 0x3460, 0x3500, 0x35a0, 0x3650, 0x36f0, 0x3790, 0x3840, 
0x38e0, 0x3980, 0x3a30, 0x3ad0, 0x3b80, 0x3c30, 0x3cd0, 0x3d80, 
0x3e30, 0x3ee0, 0x3f90, 0x4030, 0x40e0, 0x4190, 0x4240, 0x42f0, 
0x43a0, 0x4450, 0x4510, 0x45c0, 0x4670, 0x4720, 0x47d0, 0x4890, 
0x4940, 0x49f0, 0x4ab0, 0x4b60, 0x4c20, 0x4cd0, 0x4d90, 0x4e40, 
0x4f00, 0x4fc0, 0x5070, 0x5130, 0x51f0, 0x52a0, 0x5360, 0x5420, 
0x54e0, 0x55a0, 0x5650, 0x5710, 0x57d0, 0x5890, 0x5950, 0x5a10, 
0x5ad0, 0x5b90, 0x5c50, 0x5d10, 0x5dd0, 0x5ea0, 0x5f60, 0x6020, 
0x60e0, 0x61a0, 0x6260, 0x6330, 0x63f0, 0x64b0, 0x6570, 0x6640, 
0x6700, 0x67c0, 0x6890, 0x6950, 0x6a10, 0x6ae0, 0x6ba0, 0x6c70, 
0x6d30, 0x6e00, 0x6ec0, 0x6f80, 0x7050, 0x7110, 0x71e0, 0x72a0, 
0x7370, 0x7430, 0x7500, 0x75c0, 0x7690, 0x7750, 0x7820, 0x78e0, 
0x79b0, 0x7a80, 0x7b40, 0x7c10, 0x7cd0, 0x7da0, 0x7e60, 0x7f30, 
    };
    for (int i = 0; i < 4096 / 1024; ++i) {
        set_address_counter(i * 1024, cp, cmr1, cmr2);
        sram_write(data, 1024, rw, pwrdwn, cp);
    }
    load_into_dac(rw, pwrdwn);
    
    reset_address_counter(cmr1, cmr2);
    setpinref(cmr2);  // disable counter 2
    DDRB &= ~_BV(PB7);
    PORTB &= ~_BV(PB7);
    osc_conf_div(U8_TWI_ADDRESS, 8);
    osc_conf_freq(U8_TWI_ADDRESS, 2, 8);
    osc_output_enable(oscoe);
    while (1) {

    }
    
    /*
    // enable internal pull-up on ~SS
    PORTB = (1 << PB0);
     
    struct spi_interface_t spi = { &DDRB, PB1, PB3, PB2 };
    struct pin_ref_t dcx = { &PORTD, PD2 };
    struct pin_ref_t reset = { &PORTD, PD3 };
    struct pin_ref_t csx = { &PORTD, PD4 };
    struct lcd_driver_t driver = { &spi, dcx, reset, csx };
    
    // Concfigure the LCD signal lines RESET, D/CX and CSX as outputs
    // DDRD = (1 << PD2) | (1 << PD3) | (1 << PD4);
    
    struct pin_ref_t tcs = { &PORTD, PD5 };
    struct pin_ref_t tirq = { &PIND, PD6 };
    struct touch_driver_t touch = { &spi, tcs, tirq };
    touch_driver_init(&touch, 0);
    lcd_driver_init(&driver, FBOOL0);
    */
    // NOTE: for ATmega328p
    // enable internal pull-up on ~SS
    /*
    PORTB = (1 << PB2);
     
    struct spi_interface_t spi = { &DDRB, PB5, PB4, PB3 };
    struct pin_ref_t dcx = { &PORTC, PC0 };
    struct pin_ref_t reset = { &PORTC, PC1 };
    struct pin_ref_t csx = { &PORTC, PC2 };
    struct lcd_driver_t driver = { &spi, dcx, reset, csx };
    
    // Concfigure the LCD signal lines RESET, D/CX and CSX as outputs
    DDRC = (1 << PC0) | (1 << PC1) | (1 << PC2);
    
    struct pin_ref_t tcs = { &PORTC, PC3 };
    struct pin_ref_t tirq = { &PINC, PC4 };
    struct touch_driver_t touch = { &spi, tcs, tirq };
    touch_driver_init(&touch, 0);
    DDRC |= (1 << PC3) | (1 << PC5);
    */
    
    /*
    lcd_reset(&driver);
    _delay_ms(200);
    lcd_power_on(&driver);
    lcd_memory_access_control(&driver, MADCTL_MV | MADCTL_BGR);
    */
 
    /*
    uint16_t pixels[25] = {
        0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, color2, 0x0, 0x0, 0x0,
        color2, 0x0, color2, 0x0, color2,
        0x0, 0x0, 0x0, color2, 0x0,
        0x0, 0x0, 0x0, 0x0, 0x0
    };
    area_draw_figure(&driver, &area, 5, 5, 5, 5, pixels);
    */
    /*
    uint16_t x, y;
    enum menu_scene selected_menu_scene = NONE;
    void (*draw_menu_p)(struct lcd_driver_t *);
    void (*scan_menu_p)(struct lcd_driver_t *, uint16_t, uint16_t);
    while (1) {
        if (g_current_menu_scene != selected_menu_scene) {
            switch (g_current_menu_scene) {
            case MAIN_MENU:
                draw_menu_p = &draw_main_menu;
                scan_menu_p = &scan_main_menu;
                break;
            case OPTIONS_MENU:
                draw_menu_p = &draw_options_menu;
                scan_menu_p = &scan_options_menu;
                break;
            default:
                break;
            }
            selected_menu_scene = g_current_menu_scene;
            spi_set_speed(SPI_4MHZ);  // 4 MHz
            (*draw_menu_p)(&driver);
        }
        
        spi_set_speed(SPI_2MHZ);  // 2 MHz
        if (touch_scan(&touch, &x, &y)) {
            touch_get_screen_coordinates(&driver, &x, &y);
            draw_pixel(&driver, x, y, 0xFFFF);
        } else {
            x = 0xFFFF;
            y = 0xFFFF;
        }
        spi_set_speed(SPI_4MHZ);  // 4 MHz
        (*scan_menu_p)(&driver, x, y);
    }
    */
}
