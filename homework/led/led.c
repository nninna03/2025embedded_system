#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "led.h"

static unsigned int ledValue = 0;
static int fd = 0;

int led_init() {
    fd = open(LED_DRIVER_NAME, O_WRONLY);
    ledValue = 0;
    return fd;
}


void led_oper(int num, int operation) {
    int i = 1;
    i = i << num;
    ledValue = ledValue & (~i);
    if (operation != 0) {
        ledValue |= i;
    }
    write(fd, &ledValue, 4);
}

void led_exit() {
    ledValue = 0;
    ledOnOff(0, 0);
    close(fd);
}
