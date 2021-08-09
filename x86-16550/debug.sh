#!/bin/bash

qemu-system-i386 -M isapc -monitor stdio -s -S -serial file:serial.out -kernel myos.bin