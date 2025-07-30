obj-m := main.o # Specifies the object file to be built

#KDIR := /lib/modules/6.8.0-40-generic/build # Path to kernel source directory use this if you have a specific kernel version
KDIR := /lib/modules/$(shell uname -r)/build # Dynamically gets the kernel source directory based on the current kernel version

all:
	make -C $(KDIR) M=$(PWD) modules # Compiles the module

clean:
	make -C $(KDIR) M=$(PWD) clean # Cleans up compiled files

#Files created

# main.c: C source file
# Makefile: Makefile
# main.o: object file 
# main.mod.c: Kernel-generated containing module info (license, version, and dependencies)
# main.mod.o: Object file generated from compiling main.mod.c
# main.ko: Final kernel module binary. This is specific to the kernel version and architecture.
# Module.symvers: Contains exported symbols from the kernel and other modules, used for resolving dependencies
# modules.order: Lists the order of module compilation and creation
# .cmd files (e.g., main.o.cmd, main.ko.cmd): Part of the Kbuild system's optimization strategy. 
# Record the command lines used for compilation and linking hence avoiding unnecessary rebuilds.
# During rebuild compares the current command line with the recorded one

