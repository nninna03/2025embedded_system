all : main.elf
	scp main.elf ecube@192.168.175.233:/home/ecube/2025_project/sensors/BUZZER
	rm -f buzzer.o libMyPeri.a main.elf

buzzer.o : buzzer.h buzzer.c
	arm-linux-gnueabi-gcc -static -o buzzer.o -c buzzer.c 

libMyPeri.a : buzzer.o
	arm-linux-gnueabi-ar rc libMyPeri.a buzzer.o

main.elf : main.c libMyPeri.a
	arm-linux-gnueabi-gcc -static -o main.elf main.c -l MyPeri -L.
