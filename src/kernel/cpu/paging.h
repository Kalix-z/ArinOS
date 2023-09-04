#ifndef PAGING_H
#define PAGING_H

#include <stdint.h>
#include <isr.h>
#include <memory.h>

/*
* Page Directory - The main table which has 1024 entries pointing to page tables (not page table entries)
* Page Table - Table which points to 1024 page table entries
* Page Table Entry - Object of 32 bits containing data representing 4096 bytes of data in virtual memory
* Enabled in cr0 and cr3 registers in paging.asm 
*/

#define PAGE_TABLE_COUNT 1024
#define PAGE_ENTRY_COUNT 1024
#define DIRECTORY_ENTRY_SIZE 1024*4096
#define PAGE_TABLE_ENTRY_SIZE 4096
#define PAGE_DIRECTORY_EMPTY 0x00000002
#define PAGE_SIZE 4096

typedef struct page_table_entry
{
   size_t present    : 1;   // Page present in memory
   size_t rw         : 1;   // Read-only if 0, readwrite if 1
   size_t user       : 1;   // Kernel level only if 0
   size_t accessed   : 1;   // Has the page been accessed since last refresh?
   size_t dirty      : 1;   // Has the page been written to since last refresh?
   size_t unused     : 7;   // Amalgamation of unused and reserved bits
   size_t frame      : 20;  // Frame address (shifted right 12 bits)
} __attribute__((packed)) page_table_entry_t;

typedef struct page_directory_struct
{
   size_t present    : 1;   // Page present in memory
   size_t rw         : 1;   // Read-only if 0, readwrite if 1
   size_t user       : 1;   // Kernel level only if 0
   size_t pwt        : 1;
   size_t pcd        : 1;
   size_t accessed   : 1;   // Has the page been accessed since last refresh?
   size_t availible  : 1;   // Has the page been written to since last refresh?
   size_t ps         : 1;   // Amalgamation of unused and reserved bits
   size_t avl        : 4;
   size_t frame      : 20;  // Frame address (shifted right 12 bits)
} __attribute__((packed)) page_directory_struct_t;



static page_directory_struct_t page_directory[PAGE_TABLE_COUNT] __attribute__((aligned(4096)));

static page_table_entry_t page_table_entry1[PAGE_ENTRY_COUNT]__attribute__((aligned(4096)));

void paging_init();

 /* 
    Aligns the given address so that it is a multiple of a value
    size_t addr - the address to round
    size_t roundTo - the amount to round to, for example if this was 4096 the following will be true
    bool roundUp - if true, this will allways round up, so 4097 will be 8192, if false, will always round down, so 4097 will be 4096
 */
size_t alignAddress(size_t addr, size_t roundTo, bool roundUp);

/* 
   identity pages from startAddr to endAddr
   size_t startAddr - starting address to page from
   size_t endAddr - end address to page from
   userMode - true if page(s) are accesible in user mode
   readOnly - true if page(s) are read only
   returns true if success, false otherwise
*/
bool identity_page(size_t startAddr, size_t endAddr, bool userMode, bool readOnly);


/*
   pages from startPhysAddr to endPhysAddr, and maps it from startVirtAddr to endVirtAddr
   size_t startPhysAddr - starting address to page from
   size_t endPhysAddr - end address to page from
   size_t startVirtAddr - starting address to page to
   size_t endVirtAddr - ending address to page to
   bool userMode - true if page(s) are accesible in user mode
   bool readOnly - true if page(s) are read only
   returns true if success, false otherwise
*/
bool page_addresses(size_t startPhysAddr, size_t endPhysAddr, size_t startVirtAddr, size_t endVirtAddr, bool userMode, bool readOnly);


/*
 * Page Fault Handler
 * regs - a copy of all the registers
*/
void page_fault(registers_t* regs);

#endif