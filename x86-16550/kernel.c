#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "serial.h"
#include "terminal.h"
 
/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif
 
void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();
 
	/* Newline support is left as an exercise. */
	terminal_writestring("Hello, kernel World!\n");

	// init i8259 PIC

	// init serial
	init_serial();
	// write a string to serial output
	char test_string[] = "hello world";
	serial_write_string(test_string);

	char c;

	while ((c = serial_read_char()) != 'q') {
		terminal_putchar(c);
	}
	terminal_writestring("Bye kernel world!\n");

	return;
}