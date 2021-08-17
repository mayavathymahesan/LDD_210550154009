#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int FDes;

	FDes=open("/dev/mychardevice",O_RDWR,0777);
	if(FDes<0)
	{
		printf("\nError in opening\n");
		exit(1);
	}
     
       close(FDes);
     printf("hello");

}
