#ifndef WIZ_LIGHT_H
#define WIZ_LIGHT_H

typedef struct {
    char* ipAddress;
    int port;
} WizLight;

WizLight* wizCreate(char* ipAddress, int port);
void wizTurnOn(WizLight* light);
void wizTurnOff(WizLight* light);
void wizFree(WizLight* light);
void wizSetScene(WizLight* light, int scene[3]);

#endif // WIZ_LIGHT_H