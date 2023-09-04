#include <stddef.h>
#include "slavdog.h"

extern "C" void _start() {
    sys_print("testing syscall");
    while(1){}
}

