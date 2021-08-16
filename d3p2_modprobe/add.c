// module program add.c that using MADPROBE then  average.c calls add function 

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHY MAHESAN");

static int add(int a,int b)
{
	return(a+b);
}

EXPORT_SYMBOL(add);


static int __init exp_init(void)
{
	printk(KERN_ALERT "\n we are in init function\n");
	return 0;
}

static void __exit exp_exit(void)
{
	printk(KERN_ALERT "\n goodbye\n");
}

module_init(exp_init);
module_exit(exp_exit);



