nasm Bootloader.asm -f bin -o Bootloader.bin 
nasm Sector2.asm -f elf32 -o Sector2.o
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "Main.cpp" -o "Main.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "Print.cpp" -o "Print.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "IO.cpp" -o "IO.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -Wno-sizeof-array-argument -c "Math.cpp" -o "Math.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "KeyboardInput.cpp" -o "KeyboardInput.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "GraphicsDriver.cpp" -o "GraphicsDriver.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "String.cpp" -o "String.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "CustomMemory.cpp" -o "CustomMemory.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "System.cpp" -o "System.o"
g++ -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive -c "CommandHandler.cpp" -o "CommandHandler.o"



ld -m elf_i386 -T "link.ld"

cat Bootloader.bin Kernel.bin > Bootloader.flp
