#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int FDes;
       
	char Kbuff[50];
	FDes=open("/dev/mychardevice",O_RDWR,0777);
	if(FDes<0)
	{
		printf("\nError in opening\n");
		exit(1);
	}
   
     read(FDes,Kbuff,50);
     printf("\n The data read from kernal is __%s ___\n",Kbuff);
       close(FDes);


}
