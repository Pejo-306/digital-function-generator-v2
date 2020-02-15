/* 
 * File:   XPT2046.h
 * Author: pesho
 *
 * Created on February 13, 2020, 12:43 PM
 */

#ifndef XPT2046_H
#define	XPT2046_H

#define TP_S        0x80
#define TP_A2       0x40
#define TP_A1       0x20
#define TP_A0       0x10
#define TP_MODE     0x08
#define TP_SERDFR   0x04
#define TP_PD1      0x02
#define TP_PD0      0x01
#define TP_CMD_RDX  0xD0  // TP_S | TP_A2 | TP_A0
#define TP_CMD_RDY  0x90  // TP_S | TP_A0

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* XPT2046_H */

