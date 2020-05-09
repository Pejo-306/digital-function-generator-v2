/* 
 * File:   init_mcu.h
 * Author: pesho
 *
 * Created on January 25, 2020, 6:59 PM
 */

#ifndef INIT_MCU_H
#define	INIT_MCU_H

#include "defs.h"

#ifdef	__cplusplus
extern "C" {
#endif

extern struct pin_ref_t cmr1_pin;
extern struct pin_ref_t cmr2_pin;
extern struct pin_ref_t rw_pin; 
extern struct pin_ref_t cp_pin;
extern struct pin_ref_t dcx_pin;
extern struct pin_ref_t reset_pin;
extern struct pin_ref_t csx_pin;
extern struct pin_ref_t tcs_pin;
extern struct pin_ref_t tirq_pin; 
extern struct pin_ref_t pwrdwn_pin;
extern struct pin_ref_t ioex_reset_pin;
extern struct pin_ref_t oscoe_pin;
    
void init_mcu(void);

#ifdef	__cplusplus
}
#endif

#endif	/* INIT_MCU_H */

