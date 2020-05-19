/* 
 * File:   hardcode.h
 * Author: pesho
 *
 * Created on May 18, 2020, 3:40 PM
 */

#ifndef HARDCODE_H
#define	HARDCODE_H

#include <stddef.h>
#include <inttypes.h>

#include "defs.h"

#define FREQ_SETTING_10HZ   0
#define FREQ_SETTING_1KHZ   1
#define FREQ_SETTING_100KHZ 2

#ifdef	__cplusplus
extern "C" {
#endif

extern const uint16_t *g_wave_data;
extern uint16_t g_wave_size;
extern size_t g_freq_setting;
extern fbool g_wave_changed;
extern const uint16_t g_values[][5];

#ifdef	__cplusplus
}
#endif

#endif	/* HARDCODE_H */

