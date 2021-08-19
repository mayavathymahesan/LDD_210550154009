#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/ioctl.h>
#include"ioctl.h"


int main()
{
	int FDes;

	int val, n1,n2,oper;

     
	FDes=open("/dev/MYIOCTL",O_RDWR,0777);

	if(FDes<0)
	{
		printf("\nError in opening\n");
		exit(1);
	}
     
     
     printf("\n Enter \n 1.addition\n2.subtraction\n3.multiplication\n 4.division\n ");
     scanf("%d",&oper);
     ioctl(FDes,operation,(int*) &oper);


     printf("enter the first num\n");
     scanf("%d",&n1);
     printf("enter the second num\n");
     scanf("%d",&n2);


     ioctl(FDes,num1,(int*) &n1);
     ioctl(FDes,num2,(int*) &n2);
     ioctl(FDes,r_data,(int*) &val);

       close(FDes);


}
