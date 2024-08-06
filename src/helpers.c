#include "helpers.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* Checks if input equals either option */
int equalsEither(char* cmp, char* str1, char* str2) {
    return (strcmp(cmp, str1) == 0 || strcmp(cmp, str2) == 0);
}

/* Checks if string contains a number */
int containsNumber(char* str) {
    while (*str) {
        if (isdigit((unsigned char)*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

/* Extracts number from string */
int getNumFromStr(char* str) {
    char num_str[3] = {0}; // Hold max two digits
    int i = 0;

    while (*str) {
        if (isdigit((unsigned char)*str)) {

            while (isdigit((unsigned char)*str) && i < 2) {
                num_str[i++] = *str++;
            }

            return atoi(num_str);
        }
        str++;
    }

    return -1;
}

/* Extracts command from string (excludes numbers) */
char* getCmdFromStr(char* str) {
    char* cmd = malloc(strlen(str) + 1);
    int i = 0;

    while (str[i] != '\0') {
        if (isdigit((unsigned char)str[i])) {
            break;
        }
        cmd[i] = str[i];
        i++;
    }

    cmd[i - 1] = '\0'; // Eliminate the trailing space

    cmd = realloc(cmd, strlen(cmd));

    return cmd;
}