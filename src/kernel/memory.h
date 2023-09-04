#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stddef.h>
#include "screen.h"

struct block {
    size_t size; 
    int free;    
    struct block *next;  
};

// Initializes the heap
void heap_init();

// dynamically allocates size_to_allocate on the heap and returns the address
void* kmalloc(size_t size_to_allocate);

// dynamically allocates size_to_allocate on the heap, and a has a choice to align to 4096 bytes and then returns the address
void* kmalloc(size_t noOfBytes, bool align);


void kfree(void* address_to_free);

#endif