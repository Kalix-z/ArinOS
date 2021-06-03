nasm Bootloader.asm -f bin -o Bootloader.bin 
nasm Sector2.asm -f elf32 -o Sector2.o
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -c "Main.cpp" -o "Main.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -c "Print.cpp" -o "Print.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -c "IO.cpp" -o "IO.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -c "Math.cpp" -o "Math.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -c "KeyboardInput.cpp" -o "KeyboardInput.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -c "GraphicsDriver.cpp" -o "GraphicsDriver.o"

#gcc  -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -c "IDT.cpp" -o "IDT.o"


ld -m elf_i386 -T "link.ld"

#objcopy -O binary Kernel.tmp Kernel.bin 

cat Bootloader.bin Kernel.bin > Bootloader.flp
