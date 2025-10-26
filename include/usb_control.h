//
// Created by rosenberg on 11.10.2025.
//

#pragma once
#include <hidapi/hidapi.h>

void write_hid_report_to_device(hid_device *dev, unsigned char cmd[65], size_t cmd_size);