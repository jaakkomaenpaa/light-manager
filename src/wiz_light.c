#include "wiz_light.h"
#include "constants/api_cmds.h"
#include "constants/scenes.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

/*********************
 * PRIVATE FUNCTIONS *
 *********************/

/* Send command to wiz light */
void wizSendCommand(WizLight* light, char* command) {
    WSADATA wsa;
    SOCKET s;

    struct sockaddr_in server;

    int slen = sizeof(server);

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        setError("WSAStartup failed");
    }

    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
        setError("Creating socket failed");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(light->port);
    server.sin_addr.s_addr = inet_addr(light->ipAddress);

    if (sendto(s, command, strlen(command), 0, (struct sockaddr*)&server,
               slen) == SOCKET_ERROR) {
        setError("sendto() failed");
    }

    closesocket(s);
    WSACleanup();
}

/********************
 * PUBLIC FUNCTIONS *
 ********************/

/* Init a wiz light */
WizLight* wizCreate(char* ipAddress, int port) {
    WizLight* light = (WizLight*)malloc(sizeof(WizLight));

    light->ipAddress = (char*)malloc(strlen(ipAddress) + 1);
    light->port = port;

    strcpy(light->ipAddress, ipAddress);

    return light;
}

void wizTurnOn(WizLight* light) {
    wizSendCommand(light, WIZ_API_ON);
    return;
}

void wizTurnOff(WizLight* light) {
    wizSendCommand(light, WIZ_API_OFF);
    return;
}

void wizFree(WizLight* light) {
    free(light->ipAddress);
    free(light);
}

/* Set color for light */
void wizSetScene(WizLight* light, int scene[3]) {
    char command[100];
    int r = scene[0];
    int g = scene[1];
    int b = scene[2];

    sprintf(command,
            "{\"method\":\"setPilot\",\"params\":{\"r\":%d, \"g\":%d, "
            "\"b\":%d, \"w\": 5, \"c\": 5}}",
            r, g, b);

    wizSendCommand(light, command);
}