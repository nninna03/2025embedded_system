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
#include "textlcddrv.h"
#include "textlcd.h"
#include "fndtest.h"
#include "colorLEDtest.h"

#define TEXT1 "GwonInA"
#define TEXT2 "60221846"
#define LINE 1  // 1 or 1

int main() {
    colorLED_init();
    colorLED_pwmEnable();
	
    int fd = TlcdLibInit();
	if ( fd < 0 )
	{
		perror("driver (//dev//peritextlcd) open error.\n");
		return 1;
	}


		lcdtextwrite(TEXT1, 1);
		printf("InA : first line, 'GwonInA'\n");
        sleep(1);
		lcdtextwrite(TEXT2, 2);
		printf("InA : second line, '60221846'\n");
		sleep(1);

    for (int i = 0; i <= 10; i++) {
        fndInit(i, 0);
        printf("[FND] : %d\r\n", i);
        sleep(1);
    }

    while(1) {
        colorLED_serPercent(25, 0);
        colorLED_serPercent(0, 1);
        colorLED_serPercent(0, 2);
        printf("InA : COLOR LED --> RED\r\n");
        sleep(1);

        colorLED_serPercent(0, 0);
        colorLED_serPercent(25, 1);
        colorLED_serPercent(0, 2);
        printf("InA : COLOR LED -->  GREEN\r\n");
        sleep(1);
        
        colorLED_serPercent(0, 0);
        colorLED_serPercent(0, 1);
        colorLED_serPercent(25, 2);
        printf("InA : COLOR LED -->  BLUE\r\n");
        sleep(1);
    }

    fndExit();
    

    return 0;
}
