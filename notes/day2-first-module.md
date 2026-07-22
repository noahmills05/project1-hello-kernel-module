# Day 2 - First kernel module

## Goal
Create, build, load, and unload my first Linux kernel module.

## Files I created
- `hello_t490.c`
- `Makefile`

## What the module does
This module prints a message to the kernel log when it is loaded and another message when it is unloaded.

## Commands I used
```bash
make
sudo insmod hello_t490.ko
sudo dmesg | tail -n 20
sudo rmmod hello_t490
sudo dmesg | tail -n 20
```

## Result
The module built successfully and produced `hello_t490.ko`.
I loaded it with `insmod` and confirmed the log message with `dmesg`.
I unloaded it with `rmmod` and confirmed the unload message in `dmesg`.

## What I learned
- Linux kernel modules are written in C
- A kernel module can be built outside the main kernel source tree
- `make` uses the kernel build system to compile the module
- `insmod` loads a module into the running kernel
- `rmmod` removes the module from the running kernel
- `dmesg` shows messages from the kernel ring buffer
