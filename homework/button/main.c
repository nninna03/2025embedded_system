#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>    // for open/close
#include <fcntl.h>     // for O_RDWR
#include <sys/ioctl.h> // for ioctl
#include <sys/msg.h>
#include <pthread.h>
#include "button.h"

int main(int argc, char *argv[]) 
{
buttonInit();
  //path 지정
  //msgget
  //pthread_create & buttonTHFunc 연동
  //--> stEvent 구조체 값을 button_msg 구조체 주소로 옮김
while(1) {
    if(button_msg.type== EV_KEY){
        printf("EV_KEY(");
        switch(button_msg.keyInput)
        {
            case KEY_VOLUMEUP: printf("Volume up key):"); break;
            case KEY_HOME: printf("Home key):"); break;
            case KEY_SEARCH: printf("Search key):"); break;
            case KEY_BACK: printf("Back key):"); break;
            case KEY_MENU: printf("Menu key):"); break;
            case KEY_VOLUMEDOWN: printf("Volume down key):"); break;
        }
    if ( button_msg.pressed )printf("pressed\n");
    else printf("released\n");
    } 
} 
    buttonExit();
}
