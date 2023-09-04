#include <isr.h>
#include "syscalls.h"

extern "C" void syscall_callback(registers_t* regs);

typedef size_t(*syscall_function)(size_t, size_t, size_t, size_t, size_t);

syscall_function syscall_table[256];

void register_syscalls() {
    register_interrupt_handler(48, &syscall_callback);
    syscall_table[0] = sys_printf;
}


extern "C" void syscall_callback(registers_t* regs) {
    size_t id = regs->eax;
    size_t arg1 = regs->ebx;
    size_t arg2 = regs->ecx;
    size_t arg3 = regs->edx;
    size_t arg4 = regs->edi;
    size_t arg5 = regs->esi;
    regs->eax = 0;
    if (id > 255)
        return;
    if ((size_t)syscall_table[id] != 0) {
        size_t retVal = syscall_table[id](arg1, arg2, arg3, arg4, arg5);
        regs->eax = retVal;
    }
}

size_t sys_printf(size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5) {
    const char* str = (const char*)arg1;
    kout << str;
    return "hello my name is OS";
}