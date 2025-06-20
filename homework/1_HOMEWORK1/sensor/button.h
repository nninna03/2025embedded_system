#ifndef _BUTTON_H_
#define _BUTTON_H_

#define MESSAGE_ID 1122
typedef struct {
    long int messageNum;
    int keyInput;
    int pressed;
    unsigned short type;
} BUTTON_MSG_T;

int probeButtonPath(char *newPath);
int buttonInit(void);
int buttonExit(void);


static void *buttonThFunc(void);

#endif
