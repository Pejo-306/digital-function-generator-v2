#include "hardcode.h"

#include <stddef.h>

#include "defs.h"
#include "DFG-firmware/waveforms.h"

const uint16_t *g_wave_data = sine_wave;
uint16_t g_wave_size = SINE_SIZE;
size_t g_freq_setting = FREQ_SETTING_1KHZ;
fbool g_wave_changed = FBOOL0;
const uint16_t g_values[][5] = {
    { 1024, 0x2780, 998, -2, 2}, // 10 Hz
    { 1024, 0x2780, 8, -2, 2}, // 1 kHz
    { 256, 0x2200 , 2, +2, 10 }  // 100 kHz
    // resolution, mux word, div word, offset byte, dac word
};
