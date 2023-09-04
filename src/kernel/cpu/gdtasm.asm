[GLOBAL gdt_flush]    ; Allows the C code to call gdt_flush().

gdt_flush:
   mov eax, [esp+4]  ; Get the pointer to the GDT, passed as a parameter.
   lgdt [eax]        ; Load the new GDT pointer

   mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
   mov ds, ax        ; Load all data segment selectors
   mov es, ax
   mov fs, ax
   mov gs, ax
   mov ss, ax
   jmp 0x08:.flush   ; 0x08 is the offset to the code segment: Far jump
.flush:
   ret

[GLOBAL tss_flush]
tss_flush:
   cli
   mov ax, word 0x2B
   ltr ax
   sti
   ret

[GLOBAL internal_switch_to_user]
internal_switch_to_user:
   cli
   mov ebx, [esp+4]
   mov ax, (4 * 8) | 3
   mov ds, ax
   mov es, ax
   mov fs, ax
   mov gs, ax
                  
      
   mov eax, esp
   push (4 * 8) | 3
   push eax
   pushf
   pop eax
   or eax, 0x200
   push eax
   push (3 * 8) | 3
   push ebx
   sti
   iret