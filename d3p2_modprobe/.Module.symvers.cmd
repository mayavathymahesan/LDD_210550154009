cmd_/home/pi/device_drivers/native/hello_module/d3p2_modprobe/Module.symvers := sed 's/ko$$/o/' /home/pi/device_drivers/native/hello_module/d3p2_modprobe/modules.order | scripts/mod/modpost -m -a   -o /home/pi/device_drivers/native/hello_module/d3p2_modprobe/Module.symvers -e -i Module.symvers   -T -
