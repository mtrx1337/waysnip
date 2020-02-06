#ifndef WAYSNIP_SCREENSHOT_H
#define WAYSNIP_SCREENSHOT_H

#include <stdlib.h>
#include <string.h>

char* read_process_output(char* cmd) {
    FILE* fp;
    if ((fp = popen(cmd, "r")) != NULL) {
        char buffer[255];
        char* string = "";
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            if (strncmp(string, "", 1)) {
                printf("\n\ntest\n\n");
                string = realloc(string, sizeof(string) + 256);
            } else {
                string = malloc(255);
            }
            scanf(string, buffer);
        }
        return string;
    } else {
        printf("Couldnt create subprocess with command:\n\t'%s'", cmd);
        exit(1);
    }
}

int screenshot_area_select(char* temp_path) {
    /* read window geometry to pass it to grim */
    char* geometry;
    if ((geometry = read_process_output("slurp -d")) != NULL) {
        /* was the selection cancelled? */
        if (strncmp(geometry, "selection cancelled", sizeof("selection cancelled"))) {
            printf("Selection was cancelled.\n");
            exit(0);
        /* take screenshot with the geometry */
        } else {
            /* grim -o <path> -g <geo> */
            char* cmd = strcat(strcat(strcat("grim -o ", temp_path), " -g "), geometry);
            char* grim_output;
            if (strncmp(grim_output = read_process_output(cmd), "", 1)) {
                /* finished */
                exit(0);
            } else {
                /* nothing was selected, exit */
                printf("Grim failed to take a screenshot.\n\t'%s'Command used:\n\t'%s'", grim_output, cmd);
                exit(0);
            }
        }
    } else {
        printf("Couldn't read slurp output.");
        exit(1);
    }
}

int screenshot_fullscreen(char* temp_path) {
    char* cmd = strcat("grim -o ", temp_path);
    if (popen(cmd, "r") != NULL) {
        return 0;
    } else {
        printf("Couldn't take a screenshot with the following command\n\t'%s'\n", cmd);
        exit(1);
    }
}

#endif
