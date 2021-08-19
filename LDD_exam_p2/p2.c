// problem 2


#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>
#include<linux/ioctl.h>
#include"ioctl.h"
#define NAME mychardevice

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHYMAHESAN");


int NAME_open(struct inode *inode,struct file *filp);
int NAME_close(struct inode *inode ,struct file *filp);
ssize_t NAME_write(struct file *filp,const char __user *Ubuff,size_t count,loff_t *offp);
ssize_t NAME_read(struct file *filp,char __user *Ubuff,size_t count,loff_t *offp);
static long NAME_ioctl(struct file*flip,unsigned int cmd ,unsigned long arg);

// structure which defines the operations that the driver provides

struct file_operations fops =
{
	.owner   = THIS_MODULE,
	.open    = NAME_open,
	.read    = NAME_read,
	.write   = NAME_write,
	.release = NAME_close,
	.unlocked_ioctl=NAME_ioctl,
};


struct cdev *my_cdev;
static struct stats{
	int size;
	char buf[];
	int r_w;
};

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
	struct stats *stat;
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
 int count=1;
ssize_t NAME_write(struct file *filp,const char __user *Ubuff,size_t count,loff_t *offp)
{      
	char Kbuff[60];
     unsigned long result;

  	result=copy_from_user((char *)Kbuff,(char *)Ubuff,count);
	printk(KERN_ALERT "\nThe message from user space is ------%s-----\n",Kbuff);
	return count;
}

ssize_t NAME_read(struct file *filp,char __user *Ubuff,size_t count ,loff_t  *offp)
{
  char Kbuff[]="GOODMORNING";
  int result;
  
  result=copy_to_user((char *)Ubuff,(const char *)Kbuff,sizeof(Kbuff));

  return sizeof(Kbuff);
} 

static long NAME_ioctl(struct file *filp,unsigned int cmd,unsigned long arg)
{ switch(cmd)
	{  dataread=(struct stats*)dd;
		case r_data:
			 copy_to_user((struct stats*)arg,dataread,sizeod(dataread) );
			 break;
		default:
			 printk("nothing");
			 break;}
	return 0;
}


module_init(chardd_init);
module_exit(chardd_exit);



