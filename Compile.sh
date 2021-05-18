nasm Bootloader.asm -f bin -o Bootloader.bin 
nasm Sector2.asm -f elf32 -o Sector2.o
gcc -ffreestanding -m32 -fno-pie -mno-red-zone -c "ReadText.cpp" -o "ReadText.o" # -m32

ld -m elf_i386 -o Kernel.tmp -Ttext 0x7e00 Sector2.o ReadText.o

objcopy -O binary Kernel.tmp Kernel.bin 

cat Bootloader.bin Kernel.bin > Bootloader.flp
