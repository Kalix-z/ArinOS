nasm  -f elf32 -o Bootloader.o Bootloader.asm

gcc -ffreestanding -m32 -fno-pic -c ReadText.cpp -o ReadText.o

ld -m elf_i386 -o Bootloader.tmp -Ttext 0x7c00 Bootloader.o ReadText.o



objcopy -O binary "Bootloader.tmp" "Bootloader.bin"
