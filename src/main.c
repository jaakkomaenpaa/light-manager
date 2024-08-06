#include "config.h"
#include "constants/scenes.h"
#include "constants/user_cmds.h"
#include "error.h"
#include "helpers.h"
#include "tuya_light.h"
#include "wiz_light.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    Config config = getConfig();

    WizLight* wizLight = wizCreate(config.wizIpAddress, config.wizPort);

    TuyaLight* tuyaLight = tuyaCreate(config.tuyaIpAddress, config.tuyaDeviceId,
                                      config.tuyaLocalKey);

    int scenes[][3] = {SCENE_1, SCENE_2, SCENE_3, SCENE_4};

    /* Adjust if inputs start getting longer */
    char input[30];
    char* command;
    int sceneId;

    while (1) {
        printf("cmd> ");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        sceneId = -1;

        /* Check if is scene command */
        if (containsNumber(input)) {
            sceneId = getNumFromStr(input);
            command = getCmdFromStr(input);
        } else {
            command = input;
        }

        if (equalsEither(command, QUIT, QUIT_SHORT)) {
            break;

        } else if (equalsEither(command, HELP, HELP_SHORT)) {
            printf("\nUsage:\n\n");
            printf("q|quit          quit program\n");
            printf("help            show commands\n");
            printf("tuya <on|off>   turn tuya bulb on/off\n");
            printf("wiz <on|off>    turn wiz bulb on/off\n");
            printf("both <on|off>   turn both bulbs on/off\n");
            printf("tuya scene <i>  set color for tuya bulb\n");
            printf("wiz scene <i>   set color for wiz bulb\n");
            printf("both scene <i>  set color for both bulbs\n");
            printf("\n");

        } else if (equalsEither(command, TUYA_ON, TUYA_ON_SHORT)) {
            tuyaTurnOn(tuyaLight);

        } else if (equalsEither(command, TUYA_OFF, TUYA_OFF_SHORT)) {
            tuyaTurnOff(tuyaLight);

        } else if (equalsEither(command, WIZ_ON, WIZ_ON_SHORT)) {
            wizTurnOn(wizLight);

        } else if (equalsEither(command, WIZ_OFF, WIZ_OFF_SHORT)) {
            wizTurnOff(wizLight);

        } else if (equalsEither(command, BOTH_ON, BOTH_ON_SHORT)) {
            tuyaTurnOn(tuyaLight);
            wizTurnOn(wizLight);

        } else if (equalsEither(command, BOTH_OFF, BOTH_OFF_SHORT)) {
            tuyaTurnOff(tuyaLight);
            wizTurnOff(wizLight);

        } else if (equalsEither(command, CONFIG, CONFIG_SHORT)) {
            printConfig(config);

        } else if (equalsEither(command, WIZ_SCENE, WIZ_SCENE_SHORT)) {
            if (sceneId >= 1 && sceneId <= SCENES_AMT) {
                wizSetScene(wizLight, scenes[sceneId - 1]);
            } else {
                printf("\nInvalid scene (range is 1-%d).\n\n", SCENES_AMT);
            }

        } else if (equalsEither(command, TUYA_SCENE, TUYA_SCENE_SHORT)) {
            if (sceneId >= 1 && sceneId <= SCENES_AMT) {
                tuyaSetScene(tuyaLight, scenes[sceneId - 1]);
            } else {
                printf("\nInvalid scene (range is 1-%d).\n\n", SCENES_AMT);
            }

        } else if (equalsEither(command, BOTH_SCENE, BOTH_SCENE_SHORT)) {
            if (sceneId >= 1 && sceneId <= SCENES_AMT) {
                tuyaSetScene(tuyaLight, scenes[sceneId - 1]);
                wizSetScene(wizLight, scenes[sceneId - 1]);
            } else {
                printf("\nInvalid scene (range is 1-%d).\n\n", SCENES_AMT);
            }

        } else {
            printf("\nUnknown command. Use \"help\"\n\n");
        }
    }

    printf("\nExiting program\n");

    free(command);
    wizFree(wizLight);
    tuyaFree(tuyaLight);

    return 0;
}
