[org 0x7e00]

mov ah, 0x0e
mov al, 'h'
int 0x10

jmp $
times 2048 - ($-$$) db 0x00 ;fills the disk with 2kb of 0's
