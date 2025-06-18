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

int main(int argc, char** argv) {
	
    int fd = led_init();
    
     for (int i = 0; i<=7; i++) {
            led_oper(i,1);
            printf("LED %d ON\n", i + 1);
            sleep(1);
        }
	
    printf("bye \n");
    led_exit();
    return 0;
    
}
