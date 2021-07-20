#!/bin/bash

qemu-system-i386 -M isapc -monitor stdio -serial tcp::4444,server -kernel myos.bin