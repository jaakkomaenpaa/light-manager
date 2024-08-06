#include "tuya_light.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************
 * PRIVATE FUNCTIONS *
 *********************/

/* Send command to tuya light */
void tuyaSendCommand(TuyaLight* light, char* cmd) {
    const char* baseCmd = "python control.py";
    char commandStr[256];

    sprintf(commandStr, "%s \"%s\" \"%s\" \"%s\" \"%s\"", baseCmd, light->id,
            light->ipAddress, light->localKey, cmd);

    system(commandStr);
}

/********************
 * PUBLIC FUNCTIONS *
 ********************/

/* Init a tuya light */
TuyaLight* tuyaCreate(char* ipAddress, char* id, char* localKey) {
    TuyaLight* light = (TuyaLight*)malloc(sizeof(TuyaLight));

    light->id = (char*)malloc(strlen(ipAddress) + 1);
    light->ipAddress = (char*)malloc(strlen(id) + 1);
    light->localKey = (char*)malloc(strlen(localKey) + 1);

    strcpy(light->id, id);
    strcpy(light->ipAddress, ipAddress);
    strcpy(light->localKey, localKey);

    return light;
}

void tuyaTurnOn(TuyaLight* light) {
    tuyaSendCommand(light, "on");
}

void tuyaTurnOff(TuyaLight* light) {
    tuyaSendCommand(light, "off");
}

/* Set color for light */
void tuyaSetScene(TuyaLight* light, int scene[3]) {
    char cmd[20];
    int r = scene[0];
    int g = scene[1];
    int b = scene[2];

    sprintf(cmd, "scene %d %d %d", r, g, b);
    tuyaSendCommand(light, cmd);
}

void tuyaFree(TuyaLight* light) {
    free(light->id);
    free(light->ipAddress);
    free(light->localKey);
    free(light);
}
