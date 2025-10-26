//
// Created by rosenberg on 11.10.2025.
//
#include "eq_control.h"
#include <hidapi/hidapi.h>

#include <math.h>
#include <string.h>

#include "raw_cmd.h"
#include "usb_control.h"

void set_equalizer_band(unsigned char cmd[65], float db, int band) {
    // 0x5a, 0x12, 0x07, 0x01, 0x96, 0x0b, 0x00, 0x00
    cmd[4] = 0x01;
    cmd[5] = 0x96; // seems to always be 0x96 when it comes to eq
    // band info, grows by 1 with each consecutive band
    // 0x0a is preamp
    cmd[6] = 0x0b + band;
    db = floorf(db * 100) / 100;
    memcpy(&cmd[7], &db, 4);
}

//TODO: separate arrays for phones and speakers
void change_eq(hid_device *dev, float speaker_eq_vals[10], float phone_eq_vals[10], float speaker_preamp, float phone_preamp) {
    printf("Starting to set EQ settings\n");
    unsigned char eq_cmd[65];
    const RAW_CMD eq_cmd_type = SetParameter;
    build_raw_cmd(eq_cmd, 65, eq_cmd_type, 0x07);
    printf("Setting pre-amp\n");
    set_equalizer_band(eq_cmd, speaker_preamp, -1);
    set_equalizer_band(eq_cmd, phone_preamp, -1);
    for (int i = 0; i < 9; i++) {
        printf("Writing EQ band %d\n", i + 1);
        // for headphones
        set_equalizer_band(eq_cmd, phone_eq_vals[i], i);
        write_hid_report_to_device(dev, eq_cmd, sizeof(eq_cmd));
        // for speakers
        set_equalizer_band(eq_cmd, phone_eq_vals[i], i);
        write_hid_report_to_device(dev, eq_cmd, sizeof(eq_cmd));
    }
}
