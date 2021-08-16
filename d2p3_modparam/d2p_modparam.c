// program to pass two int type parameter and one string type param and perform that string operation

#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/string.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHY MAHESAN");

static int var1 =10;
static int var2=20;
static char *charvar="add";


static int add(int,int);
static int sub(int,int);
static int mul(int,int);
static int div(int,int);


module_param(var1,int ,S_IRUGO);
module_param(var2,int ,S_IRUGO);
module_param(charvar,charp,S_IRUGO);

static int __init mparam_init(void)
{
	printk(KERN_ALERT "\n the mumber are %d and %d\n",var1,var2);
	printk(KERN_ALERT "\n Entered string is %s\n",charvar);

	if(strcmp(charvar,"add")==0)
	{
		printk(KERN_ALERT "\n ADDED VALUE IS %d\n",add(var1,var2));
        }
	if(strcmp(charvar,"sub")==0)

	{
	       	printk(KERN_ALERT "\n SUBTRACTED VALUE IS %d\n",sub(var1,var2));
	}
	if(strcmp(charvar,"mul")==0)
	{
		printk(KERN_ALERT"\n MULTIPIED VALUE IS %d\n",mul(var1,var2));
	}
	if(strcmp(charvar,"div")==0)
	{
		printk(KERN_ALERT "\n DIVIDED VALUE IS %d\n",div(var1,var2));
	}
	return 0;
}

static void __exit mparam_exit(void)
{
	printk(KERN_ALERT "\ngod byr\n");
}

static int add(int a,int b)
{
	return(a+b);
}

static int sub(int a,int b)
{
	return (a-b);
}

static int mul(int a,int b)
{ return(a*b);
}

static int div(int a,int b)
{
	return(a/b);
}

module_init(mparam_init);
module_exit(mparam_exit);
