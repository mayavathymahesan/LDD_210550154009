//character driver with open,read ,write and close functionality and test drivers by writing an application  device driver



#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>

#define NAME mychardev

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHYMAHESAN");


int NAME_open(struct inode *inode,struct file *filp);
int NAME_close(struct inode *inode ,struct file *filp);
ssize_t NAME_write(struct file *filp,const char __user *Ubuff,size_t count,loff_t *offp);
ssize_t NAME_read(struct file *filp,char __user *Ubuff,size_t count,loff_t *offp);

// structure which defines the operations that the driver provides

struct file_operations fops =
{
	.owner   = THIS_MODULE,
	.open    = NAME_open,
	.read    = NAME_read,
	.write   = NAME_write,
	.release = NAME_close,
};


struct cdev *my_cdev;
 dev_t mydev;
// initialisation of module

static int __init chardd_init(void)
{   
	
	int result;
	result=alloc_chrdev_region(&mydev,0,1,"mychardev");

	printk("\nMajor number is %d and the Minor number is %d\n",MAJOR(mydev),MINOR(mydev));
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




module_init(chardd_init);
module_exit(chardd_exit);



