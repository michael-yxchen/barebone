#ifndef _SERIAL_H
#define _SERIAL_H
#define PORT 0x3f8          // COM1

int init_serial(void);
int serial_write_string(char* str);
char serial_read_char(void);

#endif