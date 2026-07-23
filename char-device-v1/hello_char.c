#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Noah Mills");
MODULE_DESCRIPTION("A simple first character device driver");
MODULE_VERSION("0.1");

#define DEVICE_NAME "hello_char"

static int major_number;

static int dev
