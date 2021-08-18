
obj-m= chardriver.o
KDIR=/lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o application application.c

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm application
