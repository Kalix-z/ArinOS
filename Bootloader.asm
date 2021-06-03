[bits 16]
[org 0x7c00]

mov [Boot_Disk], dl

mov bp, 0x7c00
mov sp, bp

call DiskRead


jmp Program_Space


jmp $
%include "ReadDisk.asm"

  
times 510 - ($ - $$) db 0 ;fills the rest of the bytes till byte 510 with 0s
db 0x55 ;sets the last 2 bytes to 0x55 and 0xaa, so the bios knows its bootable
db 0xaa


   
