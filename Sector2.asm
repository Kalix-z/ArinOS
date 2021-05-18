;[org 0x7e00]
[bits 16]
jmp Enable32BitMode
enable_A20:
    in al, 0x92
    or al, 2
    out 0x92, al
    ret       


%include "gdt.asm"
Enable32BitMode:

    call enable_A20 ;enables a20 line as x86 cpus boot in real mode (x86_16) for backwards compatibility

    cli ;disables interupts

    lgdt [gdt_descriptor] ;Loads gdt 

    mov eax, cr0 
    or eax, 1       ; set PE (Protection Enable) bit in CR0 (Control Register 0)
    mov cr0, eax
    jmp codeseg:Start32Bit

;00000a00 ;c++ code



[bits 32]
[extern _start]
Start32Bit:

    mov ax, dataseg ;moves dataseg (found in gdt, into registers ds to gs)
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov esp, 0x493E0
    call _start
    jmp $





times 2048 - ($-$$) db 0 ;fills the disk with 2kb of 0's
