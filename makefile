FLAGS = -ffreestanding -m32 -Ttext 1M -fno-pie -fno-rtti -mno-red-zone -fno-exceptions -fpermissive -I src/stl -I src/drivers -I src/kernel -I src/kernel/filesystem -I src/kernel/cpu -I src/kernel/cpu/idt -D __KERNEL_MODE_=1 -D _KERNEL_DEBUG=1 -D __SLAV_DOG_=1
bin/Kernel.bin: bin/kmain.o bin/syscalls.o bin/_start.o bin/multiboot_header.o bin/fat16.o bin/filesystem.o bin/diskATA.o bin/memory.o bin/screen.o bin/io.o bin/keyboard.o bin/isr.o bin/gdt.o bin/gdtasm.o bin/idt.o bin/idtasm.o bin/functions.o bin/paging.o bin/pagingasm.o bin/program_loader.o
CPP = /usr/local/x86_64elfgcc/bin/x86_64-elf-g++

$(shell /usr/local/x86_64elfgcc/bin/x86_64-elf-ld -m elf_i386 -T"link.ld")

#compiling the multiboot header for grub
$(shell nasm src/boot/multiboot_header.asm -f elf32 -o bin/multiboot_header.o)
$(shell nasm src/boot/_start.asm -f elf32 -o bin/_start.o)
$(shell nasm src/kernel/cpu/gdtasm.asm -f elf32 -o bin/gdtasm.o)
$(shell nasm src/kernel/cpu/idt/idtasm.asm -f elf32 -o bin/idtasm.o)
$(shell nasm src/kernel/cpu/pagingasm.asm -f elf32 -o bin/pagingasm.o)
$(shell nasm src/kernel/cpu/idt/interupt.asm -f elf32 -o bin/interupt.o)

#kernel files
bin/kmain.o: src/kernel/kmain.cpp
	$(CPP) $(FLAGS) -c src/kernel/kmain.cpp -o bin/kmain.o 

bin/screen.o: src/kernel/screen.cpp
	$(CPP) $(FLAGS) -c src/kernel/screen.cpp -o bin/screen.o 

bin/gdt.o: src/kernel/cpu/gdt.cpp
	$(CPP) $(FLAGS) -c src/kernel/cpu/gdt.cpp -o bin/gdt.o 

bin/paging.o: src/kernel/cpu/paging.cpp
	$(CPP) $(FLAGS) -c src/kernel/cpu/paging.cpp -o bin/paging.o 

bin/idt.o: src/kernel/cpu/idt/idt.cpp
	$(CPP) $(FLAGS) -c src/kernel/cpu/idt/idt.cpp -o bin/idt.o 

bin/program_loader.o: src/kernel/program/program_loader.cpp
	$(CPP) $(FLAGS) -c src/kernel/program/program_loader.cpp -o bin/program_loader.o 

bin/isr.o: src/kernel/cpu/idt/isr.cpp
	$(CPP) $(FLAGS) -c src/kernel/cpu/idt/isr.cpp -o bin/isr.o 

bin/syscalls.o: src/kernel/cpu/syscalls.cpp
	$(CPP) $(FLAGS) -c src/kernel/cpu/syscalls.cpp -o bin/syscalls.o

bin/io.o: src/kernel/cpu/io.cpp
	$(CPP) $(FLAGS) -c src/kernel/cpu/io.cpp -o bin/io.o

bin/functions.o: src/kernel/functions.cpp
	$(CPP) $(FLAGS) -c src/kernel/functions.cpp -o bin/functions.o

bin/memory.o: src/kernel/memory.cpp
	$(CPP) $(FLAGS) -c src/kernel/memory.cpp -o bin/memory.o

bin/fat16.o: src/kernel/filesystem/fat16.cpp
	$(CPP) $(FLAGS) -c src/kernel/filesystem/fat16.cpp -o bin/fat16.o

bin/filesystem.o: src/kernel/filesystem/filesystem.cpp
	$(CPP) $(FLAGS) -c src/kernel/filesystem/filesystem.cpp -o bin/filesystem.o

bin/keyboard.o: src/drivers/keyboard.cpp
	$(CPP) $(FLAGS) -c src/drivers/keyboard.cpp -o bin/keyboard.o

bin/diskATA.o: src/drivers/diskATA.cpp
	$(CPP) $(FLAGS) -c src/drivers/diskATA.cpp -o bin/diskATA.o



clean: 
	rm bin/*
clean-fsystem:
	rm filesystem.img 
	$(shell sudo dd if=/dev/zero of=bin/temp.bin bs=512 count=20480 )

