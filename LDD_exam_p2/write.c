#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int FDes;
        char Ubuff[]="sending data to the kernal...";

	FDes=open("/dev/mychardevice",O_RDWR,0777);
	if(FDes<0)
	{
		printf("\nError in opening\n");
		exit(1);
	}
     write(FDes,Ubuff,sizeof(Ubuff));
 
       close(FDes);


}
