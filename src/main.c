#include <stdio.h>
#include <unistd.h>
#include <hidapi/hidapi.h>
#include <json-c/json.h>
#include "eq_control.h"
#include "globals.h"
#include "led_control.h"
#include "parse_eq_preset.h"


int main(int argc, char *argv[]) {
    int r, g, b = 0;
    json_object *eq_preset;
    int opt;
	if (argc < 2) {
		fprintf(stderr, "Usage: %s [-r,g,b int value] [-e /path/to/json]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
    while ((opt = getopt(argc, argv, "r:g:b:e:")) != -1) {
        switch (opt) {
            case 'r':
                r = atoi(optarg);
                rgb_flag = 1;
                break;
            case 'g':
                g = atoi(optarg);
                rgb_flag = 1;
                break;
            case 'b':
                b = atoi(optarg);
                rgb_flag = 1;
                break;
            case 'e':
                eq_preset = json_object_from_file(optarg);
                if (!eq_preset) {
                    fprintf("json parsing error: %s", json_util_get_last_err());
                    fprintf(stderr, "EQ preset %s: file not found", optarg);
                } else {
                    eq_flag = 1;
                }
                break;
            default:
                fprintf(stderr, "Usage: %s [-r,g,b int value] [-e /path/to/json]\n",
                        argv[0]);
                exit(EXIT_FAILURE);
        }
    }
    float speaker_eq_vals[10] = {0};
    float speaker_preamp = 0.0;
    float *spa_ptr = &speaker_preamp;
    float phone_eq_vals[10] = {0};
    float phone_preamp = 0.0;
    float *ppa_ptr = &phone_preamp;
    if (eq_flag) {
        parse_eq_preset(eq_preset, speaker_eq_vals, phone_eq_vals, spa_ptr, ppa_ptr);
    }
    const int res = hid_init();
    if (res != 0) {
        printf("Failed to initialize hidapi\n");
        return 1;
    }

    hid_device *sbg6 = hid_open(VID, PID, SN);
    // TODO: if color change command, send it 3 times to assure it works. Check the wireshark scan to see what the inbetween packets did
    if (sbg6 != NULL) {
        if (rgb_flag) {
            change_led_static(sbg6, r, g, b);
        }
        if (eq_flag) {
            change_eq(sbg6, speaker_eq_vals, phone_eq_vals, speaker_preamp, phone_preamp);
        }
    } else {
        printf("Device not found error: %ls\n", hid_error(NULL));
    }

    hid_exit();

    return 0;
}
