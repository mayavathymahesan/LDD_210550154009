// SIMLE HELLO WORLD PROGRAM
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHY MAHESAN");

static int hello_init(void)
{
	printk("HELLO WORLD\n");
	return 0;
}


static void hello_cleanup(void)
{
	printk("GOOD BYE\n");
}


module_init(hello_init);
module_exit(hello_cleanup);


