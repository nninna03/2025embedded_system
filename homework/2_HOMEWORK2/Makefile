all: main.elf
        scp main.elf ecube@192.168.175.233:/home/ecube/2025_project/HW2
        echo "InA's HW2 : [scp elf file]"
        rm -f textlcd.o colorLEDtest.o fndtest.o libMyPeri.a main.elf
 
textlcd.o : textlcd.h textlcddrv.h textlcd.c
        arm-linux-gnueabi-gcc -static -o textlcd.o -c textlcd.c 
        echo "InA's HW2 : [make textlcd.o]"

fndtest.o : fndtest.h fndtest.c
        arm-linux-gnueabi-gcc -static -o fndtest.o -c fndtest.c 
        echo "InA's HW2 : [make fnd.o]"

colorLEDtest.o : colorLEDtest.h colorLEDtest.c
        arm-linux-gnueabi-gcc -static -c colorLEDtest.c -o colorLEDtest.o
        echo "InA's HW2 : [make colorLEDtest.o]"

libMyPeri.a: textlcd.o colorLEDtest.o fndtest.o
        arm-linux-gnueabi-ar rc libMyPeri.a textlcd.o colorLEDtest.o fndtest.o
        echo "InA's HW2 : [make libMyPeri.a]"

main.elf: main.c libMyPeri.a
        arm-linux-gnueabi-gcc -static -o main.elf main.c -l MyPeri -L. -lpthread
        echo "InA's HW2 : [make main.elf]"
