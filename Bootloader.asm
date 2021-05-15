[bits 16]



;[org 0x7c00]



jmp Enable32BitMode

%include "gdt.asm"





Enable32BitMode:

    cli      ;disables interupts

    call enable_A20

    lgdt [gdt_descriptor]

    mov eax, cr0 

    or eax, 1       ; set PE (Protection Enable) bit in CR0 (Control Register 0)

    mov cr0, eax

    jmp codeseg:Start32Bit



enable_A20:

    in al, 0x92

    or al, 2

    out 0x92, al

    ret       



[bits 32]

[extern _start]



Start32Bit:





    mov ax, dataseg ;moves dataseg (found in gdt, into registers ds to gs)

    mov ds, ax

    mov ss, ax

    mov es, ax

    mov fs, ax

    mov gs, ax

    call _start

mov edx, 0xb8000 ;clears the screen by looping through all the pixels and adding a space character (0x20) with the color black (0x00) 

mov cx, 5000 ;times to loop 

    ClearScreen:        

        mov [edx], byte 0x20 ;Square brackets due to wanting to move the value specified (0x20) into the address in edx, not into the register

        add edx, 2

        



        ;call _start ;_start();

loop ClearScreen

jmp $



times 510-($-$$) db 0 ;fills the rest of the bytes till byte 510 with 0s

db 0x55 ;sets the last 2 bytes to 0x55 and 0xaa, so the bios knows its bootable

db 0xaa


