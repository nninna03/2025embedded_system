#include "buzzer.h"

int main() {
  
    buzzerInit();
    
    for (int i = 0; i < 9999999; i++) {
        buzzerPlaySong(262); //do
    }
    buzzerStop();
    buzzerExit();
}
