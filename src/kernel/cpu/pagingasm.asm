[GLOBAL load_paging_dir]
load_paging_dir:
    push ebp
    mov ebp, esp
    mov eax, [esp + 8]
    mov cr3, eax
    mov esp, ebp
    pop ebp
    ret

[GLOBAL enable_paging]
enable_paging:
    push ebp
    mov ebp, esp
   
    mov eax, cr0
    or eax, 0x80000001
    mov cr0, eax
    mov esp, ebp
    pop ebp
    ret
