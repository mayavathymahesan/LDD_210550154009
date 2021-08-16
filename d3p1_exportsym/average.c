// average function which uses tr add function

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"header.h"


MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHY MAHESAN");


static int val1=10;
static int val2=40;
static int average;
static int __init avg_init(void)
{
	printk(KERN_ALERT "\n we are in the init function\n");
	average=(add(val1,val2)/2);
	printk(KERN_ALERT "\n AVERAGE OF %d AND %d IS %d \n",val1,val2,average);
	return 0;
}

static void __exit avg_exit(void)
{
	printk(KERN_ALERT "\n good bye\n");
}

module_init(avg_init);
module_exit(avg_exit);

