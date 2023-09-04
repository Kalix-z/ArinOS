#ifndef ___SYSCALLS_H_
#define ___SYSCALLS_H_


/*
 * enables system calls from user mode
*/
void register_syscalls();

size_t sys_printf(size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5);

#endif