[bits 16]
Program_Space equ 0x8000

DiskRead:
    mov ah, 0x02 ;tells the bios that when we call the interupt 0x13, we want to read from the disk
    mov bx, Program_Space ;tells the bios where the program is located (same as the orgin)
    mov al, 19;amount of sectors to read
    mov dl, [Boot_Disk] ;tells the bios which disk to read from, which is orginally stored in the Dl register (passed this in Bootloader.asm / the main file) 
    mov ch, 0x00 ; cylinderto read fron (n/a for us)
    mov dh, 0x00 ; head to read (n/a for us)
    mov cl, 0x02 ;Which sector to read from next

    int 0x13

    jc DiskReadFailed
     
    ret

Boot_Disk:
    db 0

DiskReadFailed:
    mov ah, 0x0e
    mov al, 'd'
    int 0x10

    jmp $