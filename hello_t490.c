#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Noah Mills");
MODULE_DESCRIPTION("A simple first kernel module on a ThinkPad T490");
MODULE_VERSION("0.1");

static int __init hello_start(void)
{
    pr_info("hello_t490: module loaded on T490\n");
    return 0;
}

static void __exit hello_end(void)
{
    pr_info("hello_t490: module unloaded\n");
}

module_init(hello_start);
module_exit(hello_end);
