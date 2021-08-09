.PHONY: clean
CROSS_CC=i686-elf-gcc
CROSS_AS=i686-elf-as
ELF_GCC_FLAGS=-std=gnu99 -ffreestanding -O0 -Wall -Wextra -Iinclude -g


all: myos.bin

boot.o: boot.s
	$(CROSS_AS) boot.s -o boot.o

serial.o: serial.c
	$(CROSS_CC) -c $^ -o $@ $(ELF_GCC_FLAGS)

kernel.o: kernel.c
	$(CROSS_CC) -c $^ -o $@ $(ELF_GCC_FLAGS)

lib.o: lib.c
	$(CROSS_CC) -c $^ -o $@ $(ELF_GCC_FLAGS)

terminal.o: terminal.c
	$(CROSS_CC) -c $^ -o $@ $(ELF_GCC_FLAGS)

myos.bin: boot.o serial.o kernel.o lib.o terminal.o
	$(CROSS_CC) -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib $^ -lgcc

clean:
	rm -f *.o myos.bin serial.out
