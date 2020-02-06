#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "screenshot.h"

int take_screenshot(char* temp_path, int capture_type) {
    int grim_fp = system("which grim > /dev/null");
    int slurp_fp = system("which slurp > /dev/null");

    if (grim_fp == 0 && slurp_fp == 0) {
        switch (capture_type) {
            case 0:
                screenshot_fullscreen(temp_path);
                break;
            case 1:
                screenshot_area_select(temp_path);
                break;
            default:
                break;
        }
        return 0;
    } else {
        printf("Couldn't find grim or slurp. Make sure to install both of them!\n");
        exit(1);
    }
}
