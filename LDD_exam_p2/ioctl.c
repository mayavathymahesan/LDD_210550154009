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

    struct stats{
	    int buff;
	    char bull[];
	    int r_w;
    }*data;
	FDes=open("/dev/mychardriver",O_RDWR,0777);

	if(FDes<0)
	{
		printf("\nError in opening\n");
		exit(1);
	}
     
  
    
     ioctl(FDes,r_data,(int*),(struct stat*)data );
     
       close(FDes);


}
