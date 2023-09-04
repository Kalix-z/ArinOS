#include <vector>
#include <keyboard.h>
#include <gdt.h>
#include <idt.h>
#include <isr.h>
#include <filesystem.h>
#include <paging.h>
#include <syscalls.h>
#include "memory.h"
#include "screen.h"
#include "program/program_loader.h"

void testMethod();

extern "C" void kmain() {
    kout << "Starting OS\n";

    heap_init();
    gdt_init();
    idtInit();
    initFS();
    paging_init();
    pit_init();
    register_syscalls();

    load_program("C:/SlavOS/test.bin");

    while (true)
    {
        KeyState_t state = GetKeyState('a');

        if (state.isDown && state.firstTimeDown)
            kprintf("A down\n");
    }
    
}
