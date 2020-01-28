/* 
 * File:   twi_driver.h
 * Author: pesho
 *
 * Created on January 27, 2020, 11:10 AM
 */

#ifndef TWI_DRIVER_H
#define	TWI_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define TWI_FREQ 400000
    
void twi_init(void);
    
void twi_start(void);


#ifdef	__cplusplus
}
#endif

#endif	/* TWI_DRIVER_H */

