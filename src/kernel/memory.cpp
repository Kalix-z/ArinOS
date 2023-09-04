#include "memory.h"

#define HEAP_SIZE 0x100000
// due to .bss not fully storing stuff, set it to one
char memory[HEAP_SIZE] = {1};

char* placementAddr;

size_t totalAlloced = 0;


void heap_init() {
    memset((uint8_t*)memory, 0, HEAP_SIZE);
    placementAddr = memory;
    kout << "initialized heap with " << HEAP_SIZE << " MB\n";
}


void *kmalloc(size_t size_to_allocate, bool align_to_page_length) {

    if (align_to_page_length == true && ((size_t)placementAddr & 0xFFFFF000)) {
        *(size_t*)&placementAddr &= 0xFFFFF000;
        placementAddr += 0x1000;
    }

    size_t tmp = (size_t)placementAddr;
    placementAddr += size_to_allocate;
    if ((placementAddr + size_to_allocate) - memory > HEAP_SIZE) {
    
        kout << "CRITICAL ERROR! OUT OF HEAP SPACE\n";
        asm volatile("hlt");
        return nullptr;
    }
    return (void*)tmp;
}

void* kmalloc (size_t size_to_allocate) {
    size_t prev = (size_t)placementAddr;
    if ((placementAddr + size_to_allocate) - memory > HEAP_SIZE) {
    
        kout << "CRITICAL ERROR! OUT OF HEAP SPACE\n";
        asm volatile("hlt");
        return nullptr;
    }
    placementAddr += size_to_allocate;
    return (void*)prev;
}

void kfree(void* address_to_free) {
    return;
}

void* operator new(size_t size_to_allocate) {
    return kmalloc (size_to_allocate);
    
}

void* operator new[](size_t size_to_allocate) {
    return kmalloc (size_to_allocate);
}

void operator delete (void* address_to_free) {
    kfree(address_to_free);
}

void operator delete (void* address_to_free, size_t __unused) {
    kfree(address_to_free);
}

void operator delete[] (void* address_to_free) {
    kfree(address_to_free);
}