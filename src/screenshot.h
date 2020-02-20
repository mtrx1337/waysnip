#ifndef WAYSNIP_SCREENSHOT_H
#define WAYSNIP_SCREENSHOT_H

#include <stdlib.h>
#include <string.h>

void read_process_output(char* cmd, char* buffer, int size) {
    FILE* fp;
    if ((fp = popen(cmd, "r")) != NULL) {
        while (fgets(buffer, size, fp) != NULL);
    } else {
        printf("Couldnt create subprocess with command:\n\t'%s'\n", cmd);
        exit(1);
    }
}

void screenshot_area_select(char* temp_path) {
    /* read window geometry to pass it to grim */
    char geometry[1024];
    read_process_output("slurp -d  2>&1 | grep -v cancelled | tr -d '\n'", geometry, sizeof(geometry));
    printf("%s\n", geometry);
    /* If a geometry was returned, call grim with it. */
    if (!strcmp(geometry, "")) {
        char cmd[2048];
        snprintf(cmd, sizeof(cmd), "grim -g '%s' '%s'", geometry, temp_path);
        char grim_output[1024];
        printf("%s\n", cmd);
        read_process_output(cmd, grim_output, sizeof(grim_output));
        if (strcmp(grim_output, "")) {
            exit(0);
        } else {
            printf("Grim failed to take a screenshot.\n\t'%s'Command used:\n\t'%s'", grim_output, cmd);
            printf("%s\n", grim_output);
            exit(1);
        }
    } else {
        printf("Couldn't read slurp output.");
        exit(1);
    }
}

void screenshot_fullscreen(char* temp_path) {
    char* cmd = strcat("grim -o ", temp_path);
    FILE* fp;
    if ((fp = popen(cmd, "r")) != NULL) {
        pclose(fp);
    } else {
        printf("Couldn't take a screenshot with the following command\n\t'%s'\n", cmd);
        exit(1);
    }
}

#endif
