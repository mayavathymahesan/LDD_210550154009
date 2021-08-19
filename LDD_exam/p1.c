// kernal sinchronization


#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>

#define NAME mychardevice
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
/*
struct file_operation fop={
	.owner=THIS_MODULR,
	.open=DEV_NAME_open,
	.write=DEV2_NAME_write,
	.read=DEV2_NAME_read,
	.release=DEV2_NAME_close,
};*/


struct cdev *my_cdev;
struct cdev *m_cdev;
// initialisation of module

static int __init chardd_init(void)
{
	int Major1,Major2;
	int Minor1,Minor2;
	int result,res;
	dev_t mydev;
	dev_t mdev;
	mydev=MKDEV(255,0);
	mdev=MKDEV(255,1);
	Major1=MAJOR(mydev);
	Minor1=MINOR(mydev);
	Major2=MAJOR(mdev);
	Minor2=MINOR(mdev);
	result=register_chrdev_region(mydev,1,"mychardevice");
	res=register_chrdev_region(mdev,1,"mchar");

	printk("\nMajor1 number is %d and the Minor1 number is %d\n",Major1,Minor1);
	printk("\nmajor2 is %d and minor2 is %d  \n",Major2,Minor2);


        if((result||res)<0)
	{
		printk("\n the region requested is not obtainable\n");
		return(-1);

	}

	my_cdev=cdev_alloc();
	my_cdev->ops= &fops;
        m_cdev=cdev_alloc();
	m_cdev->ops=&fops;



         res=cdev_add(m_cdev,mdev,1);
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
	dev_t mydev,mdev;
	int Major1,Minor1,Major2,Minor2;
	mydev=MKDEV(255,0);
	mdev=MKDEV(255,1);
	Major1=MAJOR(mydev);
	Minor1=MINOR(mydev);
	Major2=MAJOR(mdev);
	Minor2=MINOR(mdev);


	unregister_chrdev_region(mydev,1);
	unregister_chrdev_region(mdev,1);
	cdev_del(m_cdev);
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



