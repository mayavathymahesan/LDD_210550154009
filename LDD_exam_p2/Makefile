
obj-m= p2.o
KDIR=/lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o read read.c
	gcc -o write write.c
	gcc -o ioctl ioctl.c

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm read
	rm write
	rm ioctl
