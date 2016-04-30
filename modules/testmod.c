#include <linux/init.h>
#include <linux/module.h>

int mod_entry(void)
{
	printk(KERN_ALERT "AMOD: Entry\n");
	return 0;
}

int mod_exit(void)
{
	printk(KERN_ALERT "AMOD: Exit\n");
	return 0;
}

module_init(mod_entry);
module_exit(mod_exit);
