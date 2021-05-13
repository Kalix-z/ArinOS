[bits 16]
[org 0x7c00]

mov ah, 0x00 ;bios interupt for clearing screen
mov al, 0x00
int 0x10
jmp Enable32BitMode
%include "gdt.asm"



global start

;[extern _start]

;call _start
section .text
Enable32BitMode:
    call enable_A20
    cli ;disables interupts
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
Start32Bit:
    mov ax, dataseg ;moves dataseg (found in gdt, into registers ds to gs)
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000 ;clears stack
    mov esp, ebp    
    %include "StartingText.asm"
    jmp $

  
times 510 - ($ - $$) db 0 ;fills the rest of the bytes till byte 510 with 0s
db 0x55 ;sets the last 2 bytes to 0x55 and 0xaa, so the bios knows its bootable
db 0xaa
