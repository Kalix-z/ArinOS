nasm Bootloader.asm -f bin -o Bootloader.bin 
nasm Sector2.asm -f bin -o Sector2.bin #change to elf32 format and .o 
#gcc -ffreestanding -mno-red-zone -m32 -c "ReadText.cpp" -o "ReadText.o"
#ld -m elf_i386 -o Kernel.tmp -Ttext 0x7e00 Sector2.o ReadText.o

#objcopy -O binary Sector2.bin Kernel.bin #change to Kernel.tmp

cat Bootloader.bin Sector2.bin > Bootloader.flp
