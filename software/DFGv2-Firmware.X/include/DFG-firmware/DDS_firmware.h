/* 
 * File:   DDS_firmware.h
 * Author: pesho
 *
 * Created on February 23, 2020, 3:41 PM
 */

#ifndef DDS_FIRMWARE_H
#define	DDS_FIRMWARE_H

#define U8_ADDRESS  0x58  // DS1085Z-10+
#define U10_ADDRESS 0x20  // MCP23017
#define U15_ADDRESS 0x2E  // MCP4551-103E
#define U18_ADDRESS 0x60  // MCP4716-A0T

#define MCP23017_B0_IOCON  0x0A // 0x0B is also valid
#define MCP23017_B0_IODIRA 0x00
#define MCP23017_B0_GPIOA  0x12
#define MCP23017_B0_OLATA  0x14
#define MCP23017_B0_IODIRB 0x01
#define MCP23017_B0_GPIOB  0x13
#define MCP23017_B0_OLATB  0x15

#define MCP23017_B1_IOCON  0x05 // 0x15 is also valid
#define MCP23017_B1_IODIRA 0x00
#define MCP23017_B1_GPIOA  0x09
#define MCP23017_B1_OLATA  0x0A
#define MCP23017_B1_IODIRB 0x10
#define MCP23017_B1_GPIOB  0x19
#define MCP23017_B1_OLATB  0x1A

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* DDS_FIRMWARE_H */

