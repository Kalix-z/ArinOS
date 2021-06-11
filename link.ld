OUTPUT_FORMAT(binary)
ENTRY (_start)

INPUT
(
    Sector2.o
    Main.o
    Print.o
    IO.o
    Math.o
    KeyboardInput.o
    GraphicsDriver.o
    String.o
    CustomMemory.o
    System.o
    CommandHandler.o
)

OUTPUT
(
    Kernel.bin
)

SECTIONS
{
    . = 0x8000;
    .text : ALIGN(0x1000)
    {
        *(.text)
    }

    .data : ALIGN(0x1000)
    {
        *(.data)
    }

    .rodata : ALIGN(0x1000)
    {
        *(.rodata)
    }

    .bss : ALIGN(0x1000)
    {
        *(COMMON)
        *(.bss)
    }
}