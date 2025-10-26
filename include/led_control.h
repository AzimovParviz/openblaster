//
// Created by rosenberg on 11.10.2025.
//
#pragma once
#include <hidapi/hidapi.h>

void set_led_color_static(unsigned char cmd[65], int r, int g, int b);
void change_led_static(hid_device *dev, int r, int g, int b);