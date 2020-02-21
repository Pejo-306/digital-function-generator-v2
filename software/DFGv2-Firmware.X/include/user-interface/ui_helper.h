/* 
 * File:   ui_helper.h
 * Author: pesho
 *
 * Created on February 21, 2020, 7:32 PM
 */

#ifndef UI_HELPER_H
#define	UI_HELPER_H

#include <inttypes.h>

#ifdef	__cplusplus
extern "C" {
#endif

uint16_t horizontal_str_offset(const char *, uint16_t, uint8_t);

uint16_t vertical_str_offset(const char *, uint16_t, uint8_t);

#ifdef	__cplusplus
}
#endif

#endif	/* UI_HELPER_H */

