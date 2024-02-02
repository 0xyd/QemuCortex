
ARMGNU = arm-none-eabi

AOPS = --warn --fatal-warnings -mcpu=cortex-m4
COPS = -Wall -Werror -Os -nostartfiles -ffreestanding 

all : main.bin

clean:
	rm -f *.bin
	rm -f *.o
	rm -f *.elf
	rm -f *.list

startup.o : startup.s
	$(ARMGNU)-as $(AOPS) startup.s -o startup.o

main.o : main.c
	$(ARMGNU)-gcc $(COPS) -mthumb -c main.c -o main.o

main.bin : LinkerScript.ld startup.o main.o
	$(ARMGNU)-gcc -specs=nosys.specs -specs=nano.specs -o main.elf -T LinkerScript.ld startup.o main.o
	$(ARMGNU)-objdump -D main.elf > main.list
	$(ARMGNU)-objcopy main.elf main.bin -O binary


