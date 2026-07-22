# Project 1 - Hello Kernel Module

## Goal
My first Linux kernel development project on Ubuntu 24.04.4 LTS running on a ThinkPad T490.

The goal of this project is to learn how to:
- write a simple out-of-tree Linux kernel module in C,
- build it with the Linux kernel build system,
- load and unload it safely,
- inspect kernel log output with `dmesg`,
- document the whole process on GitHub.

## Environment
- Laptop: Lenovo ThinkPad T490
- OS: Ubuntu 24.04.4 LTS
- Kernel: 6.8.0-28-generic
- Language: C
- Build tool: make
- Version control: Git + GitHub

## Project structure
```text
project1-hello-module/
├── hello_t490.c
├── Makefile
├── README.md
├── notes/
│ ├── day1-setup.md
│ ├── day2-first-module.md
│ └── troubleshooting.md
└── screenshots/
```

## Files
- `hello_t490.c` - first kernel module source code
- `Makefile` - builds the module against the current kernel
- `notes/day1-setup.md` - setup notes
- `notes/day2-first-module.md` - first successful module notes
- `notes/troubleshooting.md` - errors and fixes

## What this module does
When loaded, the module prints a message to the kernel log.
When unloaded, the module prints another message to the kernel log.

## Build
```bash
make
```

## Load
```bash
sudo insmod hello_t490.ko
sudo dmesg | tail -n 20
```

## Unload
```bash
sudo rmmod hello_t490
sudo dmesg | tail -n 20
```

## Example output
```text
hello_t490: module loaded on T490
hello_t490: module unloaded
```

## Notes
This is an out-of-tree module, so the kernel warns that it is not part of the main kernel source tree. That is expected for this project stage.

## What I learned
- Kernel modules are written in C
- Kernel modules can be built outside the main Linux source tree
- `make` uses the kernel build system
- `insmod` loads a module
- `rmmod` unloads a module
- `dmesg` shows kernel log messages

## Next steps
- Add module parameters
- Build a simple character device driver
- Later move toward a custom Ubuntu kernel build

