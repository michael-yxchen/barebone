# Nothing But Serial
This piece of firmware runs on an x86 machine with the 16550 UART controller plugged in at port 0x3f8. It intializes the device, sends a "hello world" string to the serial device, and keeps reading from serial port until seeing the character 'q'. All characters read from serial are printed to the terminal. The terminal driver doesn't handle (telnet) newline characters `\r\n` well. It prints some special characters to the display. But one should be able to see the string read in.

## Building the firmware
Run `make`

## Cross Compiler Setup
Building the firmware requires the GCC Cross-Compiler. A tutorial can be found here: https://wiki.osdev.org/GCC_Cross-Compiler


## Running the firmware
In one terminal, run the `run.sh` script. This will start `qemu-system-i386` with the `isapc` machine model. It will wait for a telnet connection from `localhost:4444`.

In another terminal, run the command
```
telnet localhost 4444
```
This serves as the external serial I/O. 