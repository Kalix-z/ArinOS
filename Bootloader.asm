[bits 16]



;[org 0x7c00]



jmp Enable32BitMode

%include "gdt.asm"

mov ah, 0x02 ; ah <- 'read' function

mov al, 0x01   ; al <- sectors to read (only 512 bytes)

mov cl, 0x02 ; cl 

             ; 1 is  boot sector, 2 is the first 'available' sector

mov ch, 0x00 ; ch <- cylinder 

mov dh, 0x00 ; dh <- head number 

mov dl, 0x00

; 00H-7FH floppy disk

; 80H-FFH fixed disk



; dl <- drive number

; (0 = floppy, 1 = floppy2, 0x80 = hdd, 0x81 = hdd2)



mov bx, 0x9000  ; location where we load our kernel code

int 0x13  



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







jmp word 0x0008:0x9000



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







times 510-($-$$) db 0 ;fills the rest of the bytes till byte 510 with 0s

db 0x55 ;sets the last 2 bytes to 0x55 and 0xaa, so the bios knows its bootable

db 0xaa







