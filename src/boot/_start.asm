GLOBAL _start
EXTERN kmain
EXTERN kprintf

_start:
    ;reserves space for the stack  
    section .bss

    stack_begin:
        resb 16384  ; Reserve 16 KiB stack space
    stack_end:
    section .text
    mov esp, stack_end
    ; ensure the multiboot finished correctly
    cmp eax, 0x2BADB002
    jne error
    
    call kmain
    jmp $

    error:
        push errorStr
        call kprintf
    section .text
    jmp $
    section .rodata
    errorStr:
        db "Error In Multiboot", 0
