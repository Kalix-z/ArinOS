FLAGS = -ffreestanding -m32 -Ttext 20M -fno-pie -mno-red-zone -fno-exceptions -fpermissive
CPP = /usr/local/x86_64elfgcc/bin/x86_64-elf-g++

all: main.o syscall.o

$(shell /usr/local/x86_64elfgcc/bin/x86_64-elf-ld -m elf_i386 -T"link.ld")

main.o: main.cpp
	$(CPP) $(FLAGS) -c main.cpp -o main.o

syscall.o: syscall.asm
	nasm syscall.asm -f elf32 -o syscall.o
