//
// Created by rosenberg on 11.10.2025.
//

/*  217:31:225 RGB value for the LED, for example.
 * #D91FE1
 * "5a3a090a0003065ff[e11ed9]00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
 */
// Copied straight from Wireshark (Copy -> ...as C array
// 10, 11, 12 are color values (not counting the Record ID at index 0)
// Sometimes it won't change the colour, need more investigation still
#include <hidapi/hidapi.h>
#include "led_control.h"
#include "raw_cmd.h"
#include "usb_control.h"

void set_led_color_static(unsigned char cmd[65], int r, int g, int b) {
    // Still no idea what these mean
    cmd[4] = 0x0a;
    cmd[6] = 0x03;
    cmd[7] = 0x01;
    cmd[8] = 0x01;
    cmd[9] = 0xff;
    cmd[10] = (unsigned char) b;
    cmd[11] = (unsigned char) g;
    cmd[12] = (unsigned char) r;
}

void change_led_static(hid_device *dev, int r, int g, int b) {
    printf("Setting LED colors\n");
    unsigned char led_cmd[65];
    const RAW_CMD led_cmd_type = FeatureControl;
    build_raw_cmd(led_cmd, 65, led_cmd_type, 0x09);
    set_led_color_static(led_cmd, r, g, b);
    write_hid_report_to_device(dev, led_cmd, sizeof(led_cmd));
    // hid_write(dev, led_cmd, sizeof(led_cmd));
}
