cmd_/home/pi/device_drivers/native/hello_module/hello/Module.symvers := sed 's/ko$$/o/' /home/pi/device_drivers/native/hello_module/hello/modules.order | scripts/mod/modpost -m -a   -o /home/pi/device_drivers/native/hello_module/hello/Module.symvers -e -i Module.symvers   -T -
