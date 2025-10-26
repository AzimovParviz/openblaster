//
// Created by rosenberg on 11.10.2025.
//
#include <json-c/json.h>
#include <stdio.h>
#include "parse_eq_preset.h"

void parse_eq_preset(json_object *eq_preset, float speaker_eq_vals[10], float phone_eq_vals[10], float *speaker_preamp, float *phone_preamp) {
    // default fallback
    json_object *settings_array;
    int settings_exist = json_object_object_get_ex(eq_preset, "Settings", &settings_array);
    if (settings_exist == 1 && json_object_is_type(settings_array, json_type_array) == 1) {
        //2.1, 0.1, -1.6, -1.5, 1.2, 0.5, -3.8, 3.4, 2.8, -3.5
        json_object *speaker_bands = json_object_array_get_idx(settings_array, 0);
        json_object *phone_bands = json_object_array_get_idx(settings_array, 1);
        json_object *speaker_band_array;
        json_object_object_get_ex(speaker_bands, "Bands", &speaker_band_array);
        json_object *phone_band_array;
        json_object_object_get_ex(phone_bands, "Bands", &phone_band_array);
        int speaker_band_count = (int) json_object_array_length(speaker_band_array);
        int phone_band_count = (int) json_object_array_length(phone_band_array);
        json_object* spao;
        json_object_object_get_ex(speaker_bands, "PreAmp", &spao);
        json_object* ppao;
        json_object_object_get_ex(phone_bands, "PreAmp", &ppao);
        *speaker_preamp = (float)json_object_get_double(spao);
        *phone_preamp = (float)json_object_get_double(ppao);
        // TODO: might make more sense to put into a single loop
        // TODO: get the preamp
        for (int i = 0; i < speaker_band_count; i++) {
            json_object *value_obj = NULL;
            if (json_object_object_get_ex(json_object_array_get_idx(speaker_band_array, i), "Value", &value_obj)) {
                double val = 0.0;
                val = json_object_get_double(value_obj);
                speaker_eq_vals[i] = (float) val;
            } else {
                printf("stupid\n");
            }
        }
        for (int i = 0; i < phone_band_count; i++) {
            json_object *value_obj = NULL;
            if (json_object_object_get_ex(json_object_array_get_idx(phone_band_array, i), "Value", &value_obj) ==
                1) {
                double val = 0.0;
                val = json_object_get_double(value_obj);
                phone_eq_vals[i] = (float) val;
            } else {
                printf("fuck\n");
            }
        }
    }
}
