//
// Created by rosenberg on 11.10.2025.
//

#include "usb_control.h"

void write_hid_report_to_device(hid_device *dev, unsigned char cmd[65], size_t cmd_size)
{
    for (int i = 0; i < 65; i++) {
        printf("%x", cmd[i]);
    }
    printf("Writing HID report to the device: %d\n", hid_write(dev, cmd, cmd_size));
    printf("Errors: %ls\n", hid_read_error(dev));
    // Will show errors from the underlying macOS IOKit
    printf("error: %ls\n", hid_error(dev));
}