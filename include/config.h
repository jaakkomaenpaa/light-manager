#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    char wizIpAddress[16];
    int wizPort;

    char tuyaIpAddress[16];
    char tuyaDeviceId[32];
    char tuyaLocalKey[32];
} Config;

Config getConfig();
void printConfig(Config config);

#endif // CONFIG_H
