cmd_/home/pi/device_drivers/native/hello_module/char_dd_d2p3/Module.symvers := sed 's/ko$$/o/' /home/pi/device_drivers/native/hello_module/char_dd_d2p3/modules.order | scripts/mod/modpost -m -a   -o /home/pi/device_drivers/native/hello_module/char_dd_d2p3/Module.symvers -e -i Module.symvers   -T -
