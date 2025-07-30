/********************************************************************************
*  @file       main.c
*  @brief      Hello World kernel module for Linux.
*  @author     Rudra
* *******************************************************************************/

#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rudra");
MODULE_DESCRIPTION("A simple Hello World kernel module");

//Prototype for functions
void start(void);
void end(void);

//Function to be called when the module is loaded
void start(void)
{
    printk(KERN_INFO "Module is starting...\n");
}

void end(void)
{
    printk(KERN_INFO "Module is Ending...\n");
}



// Called everytime when module is loaded
static int __init hello_init(void) 
{
    printk(KERN_INFO "Hello, world! This is a kernel module.\n");

    start();

    return 0;
}

// Called everytime when the module is unloaded
static void __exit hello_exit(void) {

    printk(KERN_INFO "Goodbye, world! Unloading kernel module.\n");

    end();
}

// Register the initialization and cleanup functions with the kernel
module_init(hello_init);
module_exit(hello_exit);

//check module loaded -> lsmod | grep <module_name.ko>
//Load sudo insmod main.ko
//Unload sudo rmmod main.ko
//For logs: sudo dmesg | tail -n <number_of_lines> or sudo dmesg >logs.txt
