/* 
 * File:   defs.h
 * Author: pesho
 *
 * Created on January 28, 2020, 4:33 PM
 */

#ifndef DEFS_H
#define	DEFS_H

#include <inttypes.h>
#include <avr/io.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define CPU_IC      (1000000000 / F_CPU)    // in ns
#define DELAY_TICK  (CPU_IC * 3)            // in ns; see '_delay_loop_1()' of 'delay_basic.h'
    
#define FBOOL0 0x01
#define FBOOL1 0x02
#define FBOOL2 0x04
#define FBOOL3 0x08
#define FBOOL4 0x10
#define FBOOL5 0x20
#define FBOOL6 0x40
#define FBOOL7 0x80

#define setrst(reg, bit, to_set) { \
    if ((to_set)) (reg) |= (1 << (bit)); \
    else (reg) &= ~(1 << (bit)); \
}
    
typedef volatile uint8_t * SFR8_p;

typedef uint8_t SFRPIN;

typedef uint8_t fbool;

struct pin_ref_t {
    SFR8_p port;
    SFRPIN pin;
};

#define setpinref(pin_ref) { \
    *((pin_ref).port) |= _BV((pin_ref).pin); \
}

#define resetpinref(pin_ref) { \
    *((pin_ref).port) &= ~_BV((pin_ref).pin); \
}

#define pinrefstate(pin_ref) (*pin_ref.port & _BV(pin_ref.pin))

#ifdef	__cplusplus
}
#endif

#endif	/* DEFS_H */
