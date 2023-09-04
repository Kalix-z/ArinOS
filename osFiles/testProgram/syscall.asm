[GLOBAL syscall]
syscall:
    push ebp         
    mov ebp, esp
  ;  mov ebp, [esp+32] ; arg5 of syscall
    mov esi, [esp+28] ; arg4 of syscall
    mov edi, [esp+24] ; arg3 of syscall
    mov edx, [esp+20] ; arg2 of syscall
    mov ecx, [esp+16] ; arg1 of syscall
    mov ebx, [esp+12] ; arg0 of syscall
    mov eax, [esp+8] ; syscall number
    int 48           ; do the syscall  
    mov esp, ebp
    pop ebp
    ret