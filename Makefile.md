
$(shell nasm Bootloader.asm -f bin -o Bootloader.bin)
$(shell nasm Sector2.asm -f elf32 -o Sector2.o)
FLAGS = -ffreestanding -m32 -Ttext 0x8000 -fno-pie -mno-red-zone -fno-exceptions -fpermissive

Kernel.bin: Main.o Print.o IO.o Math.o KeyboardInput.o GraphicsDriver.o String.o CustomMemory.o System.o CommandHandler.o

$(shell ld -m elf_i386 -T "link.ld")
Main.o: Main.cpp
	g++ $(FLAGS) -c Main.cpp

Print.o: Print.cpp
	g++ $(FLAGS) -c Print.cpp

IO.o: IO.cpp
	g++ $(FLAGS) -c IO.cpp

Math.o: Math.cpp
	g++ $(FLAGS) -Wno-sizeof-array-argument -c Math.cpp

KeyboardInput.o: KeyboardInput.cpp
	g++ $(FLAGS) -c KeyboardInput.cpp

GraphicsDriver.o: GraphicsDriver.cpp
	g++ $(FLAGS) -c GraphicsDriver.cpp

String.o: String.cpp
	g++ $(FLAGS) -c String.cpp

CustomMemory.o: CustomMemory.cpp
	g++ $(FLAGS) -c CustomMemory.cpp

System.o: System.cpp
	g++ $(FLAGS) -c System.cpp

CommandHandler.o: CommandHandler.cpp
	g++ $(FLAGS) -c CommandHandler.cpp

clean:
	rm *.o Bootloader.flp Bootloader.bin image.img

$(shell cat Bootloader.bin Kernel.bin > Bootloader.flp)
$(shell sudo sudo dd if=Bootloader.flp bs=512 count=255 of=image.img)
$(shell sudo fallocate -l 130560 image.img)
