#ifndef TUYA_LIGHT_H
#define TUYA_LIGHT_H

typedef struct {
    char* ipAddress;
    char* id;
    char* localKey;
} TuyaLight;

TuyaLight* tuyaCreate(char* ipAddress, char* id, char* localKey);
void tuyaTurnOn(TuyaLight* light);
void tuyaTurnOff(TuyaLight* light);
void tuyaSetScene(TuyaLight* light, int scene[3]);
void tuyaFree(TuyaLight* light);

#endif // TUYA_LIGHT_H