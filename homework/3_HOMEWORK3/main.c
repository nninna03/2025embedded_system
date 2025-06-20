#include "accelManGyroTest.h"
#include "temperatureTest.h"
#include <stdio.h>

int main() {
    int gyro[3]; int accel[3]; int magnet[3];

    while(1) {
        int x = getGyro(gyro);
        int y = getAccel(accel);
        int z = getMagnet(magnet);

        printf("[Gyro] : %d, %d, %d\n", gyro[0], gyro[1], gyro[2]);
        printf("[Accel] : %d, %d, %d\n", accel[0], accel[1], accel[2]);
        printf("[Magnet] : %d, %d, %d\n", magnet[0], magnet[1], magnet[2]);
        int t = temp_read();
        printf("\n");
        sleep(1);
    }
    return 0;
}
