#include "config.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Read config file and return its data */
Config getConfig() {
    Config config;

    char line[128];

    FILE* confFile = fopen("config.txt", "r");
    if (confFile == NULL) {
        setError("Error opening config file");
    }

    memset(&config, 0, sizeof(config));

    while (fgets(line, sizeof(line), confFile)) {

        if (strcmp(line, "\n") == 0) {
            continue;
        }

        line[strcspn(line, "\n")] = '\0';

        char* key = strtok(line, " ");
        char* value = strtok(NULL, " ");

        if (strcmp(key, "WIZ_IP_ADDRESS") == 0) {
            strcpy(config.wizIpAddress, value);
        } else if (strcmp(key, "WIZ_PORT") == 0) {
            config.wizPort = atoi(value);
        } else if (strcmp(key, "TUYA_IP_ADDRESS") == 0) {
            strcpy(config.tuyaIpAddress, value);
        } else if (strcmp(key, "TUYA_DEVICE_ID") == 0) {
            strcpy(config.tuyaDeviceId, value);
        } else if (strcmp(key, "TUYA_LOCAL_KEY") == 0) {
            strcpy(config.tuyaLocalKey, value);
        }
    }

    fclose(confFile);

    return config;
}

void printConfig(Config config) {
    printf("\nConfig:\n\n");
    printf("Wiz IP: %s\n", config.wizIpAddress);
    printf("Wiz port: %d\n", config.wizPort);
    printf("Tuya IP: %s\n", config.tuyaIpAddress);
    printf("Tuya device ID: %s\n", config.tuyaDeviceId);
    printf("Tuya local key: %s\n", config.tuyaLocalKey);
    printf("\n");
}