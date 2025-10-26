//
// Created by rosenberg on 11.10.2025.
//
#include "raw_cmd.h"
#include <stdio.h>
#include <string.h>
#include "globals.h"

void build_raw_cmd(unsigned char cmd[65], size_t cmd_size, RAW_CMD command, unsigned char unknown_p) {
    memset(cmd, 0, cmd_size);
    cmd[0] = RID;
    cmd[1] = CMD_START;
    cmd[2] = command;
    cmd[3] = unknown_p;
}
