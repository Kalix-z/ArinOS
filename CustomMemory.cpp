/*
 * 6/4/2021
 */
// @ts-nocheck
#include "Types.h"
#include "System.h"
uint_8* MemoryLocation = (uint_8*)0x400000;



void * operator new(unsigned int n)throw() {
    
    malloc(MemoryLocation, n);
    MemoryLocation+=n;
    return MemoryLocation-n;
}

void operator delete(void * p) {
    return;
}
void *operator new[](unsigned int s)throw() {
    
    malloc(MemoryLocation, s);
    MemoryLocation+=s;
    return MemoryLocation-s;
}

void operator delete[](void *p) {
    return;
}

 