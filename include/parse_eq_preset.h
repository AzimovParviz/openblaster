//
// Created by rosenberg on 11.10.2025.
//
#pragma once
#include <json-c/json.h>

void parse_eq_preset(json_object *eq_preset, float speaker_eq_vals[10], float phone_eq_vals[10], float *speaker_preamp, float *phone_preamp);
