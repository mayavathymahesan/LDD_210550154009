#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x4766f3ab, "module_layout" },
	{ 0xadfb6ea0, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x31ace3dd, "cdev_add" },
	{ 0xa8881d43, "cdev_alloc" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "26B3DA9ED5090C8AFAC1BEF");
