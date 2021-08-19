
obj-m= ioctl_1.o
KDIR=/lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o ioctlapp ioctlapp.c

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm ioctlapp
