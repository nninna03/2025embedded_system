all: main.elf
        scp main.elf ecube@192.168.175.233:/home/ecube/2025_project/HW1
        rm -f led.o button.o buzzer.o libMyPeri.a main.elf
 
led.o : led.h led.c
        arm-linux-gnueabi-gcc -static -o led.o -c led.c 
 
button.o : button.h button.c
        arm-linux-gnueabi-gcc -static -c button.c -o button.o
 
buzzer.o : buzzer.h buzzer.c
        arm-linux-gnueabi-gcc -static -o buzzer.o -c buzzer.c 

libMyPeri.a: led.o button.o buzzer.o 
        arm-linux-gnueabi-ar rc libMyPeri.a led.o button.o buzzer.o 

main.elf: main.c libMyPeri.a
        arm-linux-gnueabi-gcc -static -o main.elf main.c -l MyPeri -L. -lpthread
