#ifndef _BUZZER_H_
#define _BUZZER_H_

#defineMAX_SCALE_STEP 8
#define BUZZER_BASE_SYS_PATH "/sys/bus/platform/devices/"
#define BUZZER_FILENAME "peribuzzer"
#define BUZZER_ENABLE_NAME "enable"
#define BUZZER_FREQUENCY_NAME "frequency"
char gBuzzerBaseSysDir[128]; //sys/bus/platform/devices/peribuzzer.XX가 결정됨
// const int musicScale[MAX_SCALE_SETP] = {262, 294, 330, 349, 392, 440, 494}; // do re mi ... si do
int findBuzzerSysPath();
void doHelp(void);
void buzzerEnable(int bEnable);
void setFrequency(int frequency);
 int buzzerInit(void);
 int buzzerPlaySong(int scale);
 int buzzerStopSong(void);
 int buzzerExit(void);
#endif 
