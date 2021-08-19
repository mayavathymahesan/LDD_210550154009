
obj-m= p1.o
KDIR=/lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o app1 app1.c
	gcc -o app2 app2.c
clean:
	make -C $(KDIR) M=$(PWD) clean
	rm app1
	rm app2
