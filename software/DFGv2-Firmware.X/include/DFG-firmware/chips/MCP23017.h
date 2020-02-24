/* 
 * File:   MCP23017.h
 * Author: pesho
 *
 * Created on February 24, 2020, 12:33 PM
 */

#ifndef MCP23017_H
#define	MCP23017_H

// Control registers (IOCON.BANK = 0)
#define MCP23017_B0_IOCON       0x0A // 0x0B is also valid
#define MCP23017_B0_IODIRA      0x00
#define MCP23017_B0_IODIRB      0x01
#define MCP23017_B0_IPOLA       0x02
#define MCP23017_B0_IPOLB       0x03
#define MCP23017_B0_GPINTENA    0x04
#define MCP23017_B0_GPINTENB    0x05
#define MCP23017_B0_DEFVALA     0x06
#define MCP23017_B0_DEFVALB     0x07
#define MCP23017_B0_INTCONA     0x08
#define MCP23017_B0_INTCONB     0x09
#define MCP23017_B0_GPPUA       0x0C
#define MCP23017_B0_GPPUB       0x0D
#define MCP23017_B0_INTFA       0x0E
#define MCP23017_B0_INTFB       0x0F
#define MCP23017_B0_INTCAPA     0x10
#define MCP23017_B0_INTCAPB     0x11
#define MCP23017_B0_GPIOA       0x12
#define MCP23017_B0_GPIOB       0x13
#define MCP23017_B0_OLATA       0x14
#define MCP23017_B0_OLATB       0x15

// Control registers (IOCON.BANK = 1)
#define MCP23017_B1_IOCON       0x05 // 0x15 is also valid
#define MCP23017_B1_IODIRA      0x00
#define MCP23017_B1_IPOLA       0x01
#define MCP23017_B1_GPINTENA    0x02
#define MCP23017_B1_DEFVALA     0x03
#define MCP23017_B1_INTCONA     0x04
#define MCP23017_B1_GPPUA       0x06
#define MCP23017_B1_INTFA       0x07
#define MCP23017_B1_INTCAPA     0x08
#define MCP23017_B1_GPIOA       0x09
#define MCP23017_B1_OLATA       0x0A
#define MCP23017_B1_IODIRB      0x10
#define MCP23017_B1_IPOLB       0x11
#define MCP23017_B1_GPINTENB    0x12
#define MCP23017_B1_DEFVALB     0x13
#define MCP23017_B1_INTCONB     0x14
#define MCP23017_B1_GPPUB       0x16
#define MCP23017_B1_INTFB       0x17
#define MCP23017_B1_INTCAPB     0x18
#define MCP23017_B1_GPIOB       0x19
#define MCP23017_B1_OLATB       0x1A


#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* MCP23017_H */

