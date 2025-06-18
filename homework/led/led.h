#ifndef _LED_H_
#define _LED_H_
#define LED_DRIVER_NAME "/dev/periled"

int led_init();
int led_oper(int num, int operation);
int led_exit();

#endif _LED_H_
