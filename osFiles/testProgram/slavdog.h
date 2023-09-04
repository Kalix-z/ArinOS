#ifndef __SLAV__DOG_H__
#define __SLAV__DOG_H__

extern "C" size_t syscall(size_t id, size_t arg1, size_t arg2, size_t arg3, size_t arg4, size_t arg5);


inline void sys_print(const char* str) {
    syscall(0, (size_t)str, 0, 0, 0, 0);
}



#endif