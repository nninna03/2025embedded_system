#ifndef _LED_H_
#define _LED_H_
int ledLibInit(void);
int ledOnOff(int ledNum, int onOff);
int ledLibExit(void);
#define LED_DRIVER_NAME "/dev/periled"

#endif _LED_H_
