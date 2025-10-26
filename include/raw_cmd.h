//
// Created by rosenberg on 11.10.2025.
//
#pragma once

#include <stdio.h>

typedef enum {
    SetParameter = 0x12,
    FeatureControl = 0x3a // I saw 58 for the LED but I haven't seen such a value anywhere in the decompiled code
} RAW_CMD;

/*
 * 100 byte length + report ID
 */
// TODO: figure out if i want cmd_size as a separate parameter going forward
void build_raw_cmd(unsigned char cmd[65], size_t cmd_size, RAW_CMD command, unsigned char unknown_p);
