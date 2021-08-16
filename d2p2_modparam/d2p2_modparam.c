//writw a module parameter program and display the value

#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHYMAHEASAN");

static int var=30;

module_param(var,int,S_IRUGO);

static int __init param_init(void)
{
	printk(KERN_ALERT"\n we are in init function\n");
	printk(KERN_ALERT "\n The integer value is %d \n",var);
	return 0;
}

static void __exit param_exit(void)
{
	printk(KERN_ALERT "\n goodbye\n");
}

module_init(param_init);
module_exit(param_exit);

