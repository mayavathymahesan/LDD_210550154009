//character driver with open and close functionality and test drivers by writing an application that opens and closes device driver



#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/kernel.h>

#define NAME mychardevice

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHYMAHESAN");


int NAME_open(struct inode *inode,struct file *filp);
int NAME_close(struct inode *inode ,struct file *filp);


// structure which defines the operations that the driver provides

struct file_operations fops =
{
	.owner   = THIS_MODULE,
	.open    = NAME_open,
	.release = NAME_close,
};


struct cdev *my_cdev;

// initialisation of module

static int __init chardd_init(void)
{
	int Major;
	int Minor;
	int result;
	dev_t mydev;
	mydev=MKDEV(255,0);
	Major=MAJOR(mydev);
	Minor=MINOR(mydev);
	result=register_chrdev_region(mydev,1,"mychardevice");

	printk("\nMajor number is %d and the Minor number is %d\n",Major,Minor);
        if(result<0)
	{
		printk("\n the region requested is not obtainable\n");
		return(-1);

	}

	my_cdev=cdev_alloc();
	my_cdev->ops= &fops;

	result=cdev_add(my_cdev,mydev,1);
	if(result<0)
	{
		printk(KERN_ALERT "\n THE CHAR DEVIVE IS NOT CREATED \n");
		unregister_chrdev_region(mydev,1);
		return (-1);
	
	}
	return 0;
}

// The exit module
 static void __exit chardd_exit(void)
{
	dev_t mydev;
	int Major,Minor;
	mydev=MKDEV(255,0);
	Major=MAJOR(mydev);
	Minor=MINOR(mydev);
	unregister_chrdev_region(mydev,1);
	cdev_del(my_cdev);
	printk("\n deallocated all\n");
	
}

int NAME_open(struct inode *inode,struct file *filp)
{
	printk(KERN_ALERT "\n OPEN CALL IN DRIVER\n");
	return 0;
}

int NAME_close(struct inode *inode,struct file *filp)
{
	printk(KERN_ALERT "\n CLOSE CALL IN DRIVER\n");
	return 0;
}

module_init(chardd_init);
module_exit(chardd_exit);



