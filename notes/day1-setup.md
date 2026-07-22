# Day 1 - Ubuntu setup and kernel module environment

## Goal
Set up my ThinkPad T490 with Ubuntu 24.04.4 LTS for Linux kernel development.

## System
- Laptop: Lenovo ThinkPad T490
- OS: Ubuntu 24.04.4 LTS
- Kernel: 6.8.0-28-generic

## Commands I ran
```bash
sudo apt update
sudo apt upgrade -y
sudo apt install -y linux-headers-$(uname -r) build-essential git
```

## Why I installed these packages
- `linux-headers-$(uname -r)` installs the header files for the exact kernel I am currently running
- `build-essential` installs important development tools such as `gcc`, `g++`, and `make`
- `git` is used for version control and GitHub

## What I learned
To build a kernel module, I need the Linux kernel headers that match my current running kernel version.

