all: main.elf
	scp main.elf ecube@192.168.175.233:/home/ecube/2025_project/HW3
	echo "InA's HW3 : [scp elf file]"
	rm -f accelManGyroTest.o temperatureTest.o libMyPeri.a main.elf
 
accelManGyroTest.o : accelManGyroTest.h accelManGyroTest.c
	arm-linux-gnueabi-gcc -static -o accelManGyroTest.o -c accelManGyroTest.c 
	echo "InA's HW3 : [make accelManGyroTest.o]"
 
temperatureTest.o : temperatureTest.h temperatureTest.c
	arm-linux-gnueabi-gcc -static -o temperatureTest.o -c temperatureTest.c 
	echo "InA's HW3 : [make temperatureTest.o]"

libMyPeri.a: accelManGyroTest.o temperatureTest.o
	arm-linux-gnueabi-ar rc libMyPeri.a accelManGyroTest.o temperatureTest.o 
	echo "InA's HW3 : [make libMyPeri.a]"

main.elf: main.c libMyPeri.a
	arm-linux-gnueabi-gcc -static -o main.elf main.c -l MyPeri -L. -lpthread
	echo "InA's HW3 : [make main.elf]"
