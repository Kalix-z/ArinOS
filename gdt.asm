;[org 0x7c00]

;GLOBAL DESCRIPTOR TABLE



gdt_nulldesc:

    dd 0 ;sets nulls

    dd 0

gdt_codedesc:

    dw 0xffff ;sets the limit of the cpu

    dw 0x0000 ;sets the lowest point

    db 0x00 ;base

    db 10011010b ;access bits

    db 11001111b ;flag bits

    db 0x00 ;another base

gdt_datadesc:

    dw 0xffff ;sets limit

    dw 0x0000 ;base

    db 0x00 ;base

    db 10010010b ;access bits

    db 11001111b ;flag bits

    db 0x00 ;base



gdt_end:



gdt_descriptor:

    gdt_size:

        dw gdt_end - gdt_nulldesc - 1

        dd gdt_nulldesc

codeseg equ gdt_codedesc - gdt_nulldesc

dataseg equ gdt_datadesc - gdt_nulldesc

