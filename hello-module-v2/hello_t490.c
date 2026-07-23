#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Noah Mills");
MODULE_DESCRIPTION("A simple parameterized kernel module on a ThinkPad T490");
MODULE_VERSION("0.2");

static char *name = "Noah";
module_param(name, charp, 0644);
MODULE_PARM_DESC(name, "Name to print when the module loads");

static int __init hello_start(void)
{
pr_info("hello_t490: module loaded on T490, hello %s\n", name);
return 0;
}

static void __exit hello_end(void)
{
pr_info("hello_t490: module unloaded, goodbye %s\n", name);
}

module_init(hello_start);
module_exit(hello_end);
