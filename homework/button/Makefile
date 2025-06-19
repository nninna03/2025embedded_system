all : main.elf
	scp main.elf ecube@192.168.175.233:/home/ecube/2025_project/sensors/BUTTON
	rm -f led.o libMyPeri.a main.elf

button.o : button.h button.c
	arm-linux-gnueabi-gcc -static -o button.o -c button.c 

libMyPeri.a : button.o
	arm-linux-gnueabi-ar rc libMyPeri.a button.o

main.elf : main.c libMyPeri.a
	arm-linux-gnueabi-gcc -static -o main.elf main.c -l MyPeri -L.
