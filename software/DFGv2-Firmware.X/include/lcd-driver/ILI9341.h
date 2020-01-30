/* 
 * File:   ILI9341.h
 * Author: pesho
 *
 * Created on January 28, 2020, 9:08 PM
 */

#ifndef ILI9341_H
#define	ILI9341_H

#define LCD_RESX 240  // 0x00EF
#define LCD_RESY 320  // 0x013F

// Level 1 commands
#define CMD_NOP                                 0x00
#define CMD_SWRESET                             0x01
#define CMD_RDDIDIF                             0x04
#define CMD_RDDST                               0x09
#define CMD_RDDPM                               0x0A
#define CMD_RDDMADCTL                           0x0B
#define CMD_RDDCOLMOD                           0x0C
#define CMD_RDDIM                               0x0D
#define CMD_RDDSM                               0x0E
#define CMD_RDDSDR                              0x0F
#define CMD_SPLIN                               0x10
#define CMD_SLPOUT                              0x11
#define CMD_PTLON                               0x12
#define CMD_NORON                               0x13
#define CMD_DINVOFF                             0x20
#define CMD_DINVON                              0x21
#define CMD_GAMSET                              0x26
#define CMD_DISPOFF                             0x28
#define CMD_DISPON                              0x29
#define CMD_CASET                               0x2A
#define CMD_PASET                               0x2B
#define CMD_RAMWR                               0x2C
#define CMD_RGBSET                              0x2D
#define CMD_RAMRD                               0x2E
#define CMD_PLTAR                               0x30
#define CMD_VSCRDEF                             0x33
#define CMD_TEOFF                               0x34
#define CMD_TEON                                0x35
#define CMD_MADCTL                              0x36
#define CMD_VSCRSADD                            0x37
#define CMD_IDMOFF                              0x38
#define CMD_IDMON                               0x39
#define CMD_PIXSET                              0x3A
#define CMD_WRITE_MEMORY_CONTINUE               0x3C
#define CMD_READ_MEMORY_CONTINUE                0x3E
#define CMD_SET_TEAR_SCANLINE                   0x44
#define CMD_GET_SCANLINE                        0x45
#define CMD_WRDISBV                             0x51
#define CMD_RDDISBV                             0x52
#define CMD_WRCTRLD                             0x53
#define CMD_RDCTRLD                             0x54
#define CMD_WRCABC                              0x55
#define CMD_RDCABC                              0x56
#define CMD_WRITE_CABC_MINIMUM_BRIGHTNESS       0x5E
#define CMD_READ_CABC_MINIMUM_BRIGHTNESS        0x5F
#define CMD_RDID1                               0xDA
#define CMD_RDID2                               0xDB
#define CMD_RDID3                               0xDC

// Level 2 commands
#define CMD_IFMODE                              0xB0
#define CMD_FRMCTR1                             0xB1
#define CMD_FRMCTR2                             0xB2
#define CMD_FRMCTR3                             0xB3
#define CMD_INVTR                               0xB4
#define CMD_PRCTR                               0xB5
#define CMD_DISCTRL                             0xB6
#define CMD_ETMOD                               0xB7
#define CMD_BACKLIGHT_CONTROL_1                 0xB8
#define CMD_BACKLIGHT_CONTROL_2                 0xB9
#define CMD_BACKLIGHT_CONTROL_3                 0xBA
#define CMD_BACKLIGHT_CONTROL_4                 0xBB
#define CMD_BACKLIGHT_CONTROL_5                 0xBC
#define CMD_BACKLIGHT_CONTROL_7                 0xBE
#define CMD_BACKLIGHT_CONTROL_8                 0xBF
#define CMD_PWCTRL1                             0xC0
#define CMD_PWCTRL2                             0xC1
#define CMD_VMCTRL1                             0xC5
#define CMD_VMCTRL2                             0xC7
#define CMD_NVMWR                               0xD0
#define CMD_NVMPKEY                             0xD1
#define CMD_RDNVM                               0xD2
#define CMD_RDID4                               0xD3
#define CMD_PGAMCTRL                            0xE0
#define CMD_NGAMCTRL                            0xE1
#define CMD_DGAMCTRL1                           0xE2
#define CMD_DGAMCTRL2                           0xE3
#define CMD_IFCTL                               0xF6

// Extended register command set
#define CMD_POWER_CONTROL_A                     0xCB
#define CMD_POWER_CONTROL_B                     0xCF
#define CMD_DRIVER_TIMING_CONTROL_A             0xE8
#define CMD_DRIVER_TIMING_CONTROL_B             0xEA
#define CMD_POWER_ON_SEQUENCE_CONTROL           0xED
#define CMD_ENABLE_3G                           0xF2
#define CMD_PUMP_RATIO_CONTROL                  0xF7
    
#define MADCTL_DEFAULT_VALUE 0x00

#define DPI_16BIT 0x50
#define DPI_18BIT 0x60
#define DBI_16BIT 0x05
#define DBI_18BIT 0x06

#define BLCTRL_BCTRL    0x20
#define BLCTRL_DD       0x08
#define BLCTRL_BL       0x04

#ifdef	__cplusplus
extern "C" {
#endif
    
#ifdef	__cplusplus
}
#endif

#endif	/* ILI9341_H */
