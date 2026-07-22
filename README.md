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

## Module parameter version

The modules now supports a string parameter called `name`.

#### Parameter code
```c
static char *name = "Noah";
module_param(name, charp, 0644);
MODULE_PARM_DESC(name, "Name to print when the module laods");
```

### Example usage
```bash
sudo insmod hello_t490.ko name="Noah"
dmesg | tail -n 20
sudo rmmod hello_t490
dmesg | tail -n 20
```

### Expected output
```text 
hello_t490: module loaded on T490, hello Noah
hello_t490: module unloaded, goodbye Noah
```

### What changed
This version improves the original hello module by allowing a module to be passed into the module at load time.

## Next steps
- Finish testing the parameterised version
- Build a simple character device driver
- Continue documenting all milestones on GitHub
