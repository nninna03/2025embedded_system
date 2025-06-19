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
#include <pthread.h>

#include "led.h"
#include "button.h"
#include "buzzer.h"
pthread_mutex_t lock;

int melody[] = {
    DO, DO, DO, DO, DO,
    MI, SOL, SOL, MI, DO,
    SOL, SOL, MI, SOL, SOL, MI,
    DO, DO, DO
};

int noteDurations[] = {
    4, 8, 8, 4, 4,
    4, 8, 8, 4, 4,
    8, 8, 4, 8, 8, 4,
    4, 4, 2
};

int main(){
//******************************************** thread init ******************************
if (pthread_mutex_init(&lock, NULL) != 0)
      {
          printf ("\n Mutex Init Failed!!\n");
          return 1;
      }

//******************************************** init start ******************************
    printf("device init start\n");

    //init led
    int fd_led = ledLibInit();
    if (fd_led < 0) {
        printf("failed open LED file\n");
        return 1;
    }
    printf("led  init done\n");

    //init buzzer
     buzzerInit();
     printf("buzzer init done\n");

    //init button & message queue
    BUTTON_MSG_T Data;
    buttonInit();
    msgID = msgget (MESSAGE_ID, IPC_CREAT|0666);
    printf("button init done\n");
    //***************************** init Done ******************************************/

    //led

        for (int i = 0; i<=7; i++) {
            ledOnOff(i,1);
            printf("LED %d ON\n", i + 1);
            sleep(1);
        }

        for (int i = 0; i<=7; i++) {
            ledOnOff(i,0);
            printf("LED %d OFF\n", i + 1);
            sleep(1);
        }


    //buzzer
    for (int i = 0; i < 19; i++) {
        int durations = 1000 / noteDurations[i];
        buzzerTone(melody[i]);
        delay_ms(durations * 1.3);
        buzzerStop();
     }


while(1) {  
    //struct input_event stEvent;   
        int returnValue = 0;
        returnValue = msgrcv(msgID, &Data, sizeof(Data) - sizeof(long int), 0, 0);

        if(Data.type== EV_KEY){

            if ( Data.pressed ) {
                switch(Data.keyInput) {
                    case KEY_HOME:
                        printf("HOME KEY pressed \r\n");
                        break;
                    case KEY_BACK:
                        printf("BACK KEY pressed\r\n");
                        break;
                    case KEY_SEARCH:
                        printf("SEARCH KEY pressed \r\n");
                        break;
                    case KEY_MENU:
                        printf("MEMU KEY pressed \r\n");
                        break;
                    case KEY_VOLUMEUP:
                        printf("VOLUMEUP KEY pressed  \r\n");
                        break;
                    case KEY_VOLUMEDOWN:
                        printf("VOLUMEDOWN KEY pressed \r\n");
                        break;
                }
            }
            else {
                buzzerStop();
            }
        }
    }

//************************* finish (thread join, device exit)****************************
pthread_join (buttonTh_id, NULL);

}
