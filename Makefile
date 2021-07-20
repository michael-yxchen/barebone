.PHONY: clean
ELF_GCC_FLAGS=-std=gnu99 -ffreestanding -O0 -Wall -Wextra -Iinclude -g


all: myos.bin

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

serial.o: serial.c
	i686-elf-gcc -c $^ -o $@ $(ELF_GCC_FLAGS)

kernel.o: kernel.c
	i686-elf-gcc -c $^ -o $@ $(ELF_GCC_FLAGS)

lib.o: lib.c
	i686-elf-gcc -c $^ -o $@ $(ELF_GCC_FLAGS)

terminal.o: terminal.c
	i686-elf-gcc -c $^ -o $@ $(ELF_GCC_FLAGS)

myos.bin: boot.o serial.o kernel.o lib.o terminal.o
	i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib $^ -lgcc

clean:
	rm -f *.o myos.bin serial.out
