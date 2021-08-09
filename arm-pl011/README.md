# arm-pl011

## Building the firmware

In the current directory, run
```
mkdir build
cd build
cmake ..
make
```
The commands will create the firmware named `bare-metal.bin`.

## Running the firmware

In the `build` directory, run `make run` or run the QEMU command directly as
```
qemu-system-arm -M vexpress-a9 -m 512M -no-reboot -nographic -monitor telnet:127.0.0.1:1234,server,nowait -kernel bare-metal.bin -serial mon:stdio
```

## Expected behavior

The firmware will first print these three lines to the terminal:
> ABC

> I love drivers!

> Type below...

| Input | Output |
|-------|--------|
| help  |Just type and see what happens! |
| uname | bare-metal arm 06_uart |
| \<anything else\> | \<nothing\> |

## (Quit QEMU monitor on commandline)

Use `(Ctrl+A) + X` (pressing Ctrl + A together, release them both, then press X) to quit the terminal QEMU monitor.