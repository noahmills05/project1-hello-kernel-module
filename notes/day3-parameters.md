# Day 3 - Module Parameters

## Goals 
Update my first Linux kernel module so it can accept a value when the module is loaded.

## What I changed
I added a string module parameter called `name` to `hello_t490.c`.

## Code added
```c
#include <linux/moduleparam.h>

static char *name = "Noah";
module_param(name, charp, 0644);
MODULE_PARM_DESC(name, "Namr to print when the module loads");
```

## What this means
The module can now accept a string value when it is loaded.

Example:
```bash
sudo insmod hello_t490.ko name="Noah"
```

`module_param(name, charp, 0644)` means:
- `name` is the parameter name
- `charp` measns teh parameter is a string
- `0644` sets the sysfs permissions for the parameter


`MODULE_PARM_DESC(name, "...")` adds a description for the parameter.

## Expected behaviour
When the module loads, it should print the name passed in as a parameter.
When the modules unloads, it should print a goodbye message using the same name.

## Commands used 
```bash
make clean
make
sudo insmod hello_t490.ko name="Noah"
sudo dmesg | tail -n 20
sudo rmmod hello_t490
sudo dmesg | tail -n 20

## Example expected output
```text
hello_t490: module loaded on T490, hello Noah
hello_t490: module unloaded, goodbye Noah
```

## Build issue I hit
During compilation, I got a syntax error around `MODULE_PARM_DESC(...)`.

### Cause
A tiny punctuation or formatting issue in a macro line can break compilation.

### Lesson
Kernel module macros must be written exactly correctly. Small mistakes such as missing comma, wrong quote, or malformed previous line can cause the compiler to fail.

## What I learned
- Linux kernel mdoules can accept values at laod time using `module_param()`
- String parameters use the `charp` type
- `MODULE_PARM_DESC` is used to document a parameter
- `dmesg` is used to verify kernel log messages
- Small C syntax mistakes in macros can stop a module from building

