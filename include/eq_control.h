//
// Created by rosenberg on 11.10.2025.
//

#pragma once
#include <hidapi/hidapi.h>

/*
 * each equalizer setting command starts like this: 5a120701960e0000
 * Each EQ band is 32-bit IEEE 754 floating point
 */
void set_equalizer_band(unsigned char cmd[65], float db, int band);
void change_eq(hid_device *dev, float speaker_eq_vals[10], float phone_eq_vals[10], float speaker_preamp, float phone_preamp);
