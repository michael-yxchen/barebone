#include "serial.h"
#include "lib.h"
int init_serial(void) {
    outb(PORT + 1, 0x00); // Disable all interrupts
    outb(PORT + 3, 0x80); // Enable DLAB (set baud rate divisor)
    outb(PORT + 0, 0x03); // Set divisor to 3 (lo byte) 38400 baud
    outb(PORT + 1, 0x00); //                  (hi byte)
    outb(PORT + 3, 0x03); // 8 bits, no parity, one stop bit
    outb(PORT + 2, 0xC7); // Enable FIFO, clear them, with 14-byte threshold
    outb(PORT + 4, 0x0B); // IRQs enabled, RTS/DSR set
    outb(PORT + 4, 0x1E); // Set in loopback mode, test the serial chip
    outb(PORT + 0, 0x41); // Test serial chip (send byte 0xAE and check if
                          // serial returns same byte)

    // Check if serial is faulty (i.e: not same byte as sent)
    uint16_t in_byte = inb(PORT + 0);
    if (in_byte != 0x41) {
        return 1;
    }

    // If serial is not faulty set it in normal operation mode
    // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
    outb(PORT + 4, 0x0F);
    return 0;
}

static int is_transmit_empty() { return inb(PORT + 5) & 0x20; }

static void write_serial(char a) {
    while (is_transmit_empty() == 0)
        ;

    outb(PORT, a);
}

static int serial_received() { return inb(PORT + 5) & 1; }

static char read_serial() {
    while (serial_received() == 0)
        ;

    return inb(PORT);
}

int serial_write_string(char *str) {
    char *str_start = str;
    while (*str) {
        write_serial(*str);
        ++str;
    }
    return str - str_start;
}

char serial_read_char(void) {
    return read_serial();
}