/* 
 * File:   MCP455X.h
 * Author: pesho
 *
 * Created on March 9, 2020, 1:42 PM
 */

#ifndef MCP455X_H
#define	MCP455X_H

#define MCP4551_VOLATILE_WIPER_0        0x00  // 00h << 4
#define MCP4551_VOLATILE_WIPER_1        0x10  // 01h << 4
#define MCP4551_VOLATILE_TCON_REGISTER  0x40  // 04h << 4

#define MCP4551_WRITE_CMD       0x00  // 00x
#define MCP4551_INCREMENT_CMD   0x02  // 01x
#define MCP4551_DECREMENT_CMD   0x04  // 10x
#define MCP4551_READ_CMD        0x06  // 11x

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* MCP455X_H */

