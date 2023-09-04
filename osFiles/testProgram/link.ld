OUTPUT_FORMAT(elf32-i386)
ENTRY (_start)

INPUT 
(   
    main.o
    syscall.o
)

OUTPUT 
(
    ../bin/test.bin
)

SECTIONS
{

    . = 20M;

    .boot :
    {
        *(.multiboot_header)
    }

    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.text)
    }
    
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }

}