all : main.elf
	scp main.elf ecube@192.168.175.233:/home/ecube/2025_project/sensors/LED
	rm -f led.o libMyPeri.a main.elf

led.o : led.h led.c
	arm-linux-gnueabi-gcc -static -o led.o -c led.c 

libMyPeri.a : led.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o

main.elf : main.c libMyPeri.a
	arm-linux-gnueabi-gcc -static -o main.elf main.c -l MyPeri -L.
