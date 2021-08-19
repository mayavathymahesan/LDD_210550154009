//character driver thar implement the ioctl functionality to demonstrate calculater functionality


#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/uaccess.h>
#include<linux/ioctl.h>
#include"ioctl.h"

#define NAME MYIOCTL

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYAVATHY MAHESAN");


int val1=0;
int val2=0;
int fun=0;
int val=0;

 dev_t dev;

 struct cdev *m_cdev;
 
static long NAME_ioctl(struct file *filp,unsigned int cmd,unsigned long arg);
static struct file_operations fops=
{
	.owner=THIS_MODULE,
	
	.unlocked_ioctl=NAME_ioctl,
};


static long NAME_ioctl(struct file *filp ,unsigned int cmd,unsigned long arg)
{
	

	switch(cmd)
	{
		case operation:
			copy_from_user(&fun,(int*)arg,sizeof(fun));
			printk("\n the operation is %d \n",fun);
			break;
		case num1:
			copy_from_user(&val1,(int*)arg,sizeof(val1));
			printk("\nthe val1 is %d \n",val1);
			break;
		case num2:
			copy_from_user(&val2,(int*)arg,sizeof(val2));
			printk("\n the val2 is %d \n",val2);
			break;
		case r_data:
			if (fun==1)
			{ 
				val=val1+val2;
				printk("Addition of %d and %d=%d \n",val1,val2,val);
			}
			else if(fun==2)
			{
				val=val1-val2;
				printk("Subtraction of %d and %d is %d \n",val1,val2,val);

			}
			else if(fun==3)
			{
				val=val*val2;
				printk("multiplication of  %d and %d ids %d \n",val1,val2,val);

			}
			else if(fun==4)
			{
				val=val1/val2;
				printk("Division of %d and %d is %d \n",val,val1,val2);
			}	
			copy_to_user((int*)arg,&val,sizeof(val));
			break;
             default:
			printk("error\n");
			break;
	}

			
			return 0;
}
static int __init my_ioctl_init(void)
{
	if((alloc_chrdev_region(&dev,0,1,"MYIOCTL"))<0)
	{	
		printk("\n not allocated\n");
                return -1;
	}
	printk("major is %d and minor is %d\n",MAJOR(dev),MINOR(dev));


 m_cdev=cdev_alloc();
 m_cdev->ops=&fops;
  if(cdev_add(m_cdev,dev,1)<0)
  {printk("\n not created\n");
  return -1;
  }
  return 0;
}
static void __exit my_ioctl_exit(void)
{
	unregister_chrdev_region(dev,1);
	cdev_del(m_cdev);
	printk("\n deallocated\n");
}


module_init(my_ioctl_init);
module_exit(my_ioctl_exit);

