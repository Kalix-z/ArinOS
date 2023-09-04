#include "paging.h"

extern "C" void load_paging_dir(page_directory_struct_t* page_direc);
extern "C" void enable_paging();



/* enables paging, identity pages kernel, enables proper malloc */
void paging_init() {
    for (size_t i = 0; i < PAGE_TABLE_COUNT; i++) {
        page_directory[i].present = 0;
        page_directory[i].user = 0;
        page_directory[i].rw = 1;
    }


    // Kernel is loaded at 1 MB
    bool b = identity_page(0x100000, 16*0x100000, false, false);
    // Video memory is from 0x000A0000 to 0x000BFFFF
    bool c = identity_page(0x000A0000, 0x000BFFFF, false, false);
    if (!(b || c))
        kout << "Error identity paging\n";

    load_paging_dir(page_directory);
    enable_paging();
    kout << "Paging enabled\n";
    register_interrupt_handler(14, &page_fault);
}

bool identity_page(size_t startAddr, size_t endAddr, bool userMode, bool readOnly) {
    /*
     * We want the addresses to include everything the caller wants, so include the floor of the start and the ceiling of the end 
    */
    startAddr = alignAddress(startAddr, PAGE_SIZE, false);
    endAddr = alignAddress(endAddr, PAGE_SIZE, true);

    for (size_t currentAddress = startAddr; currentAddress < endAddr; currentAddress+=PAGE_SIZE) {
        // figure out which index of the page_directory this page belongs to
        size_t directoryAlignedAddr = alignAddress(currentAddress, PAGE_SIZE*PAGE_ENTRY_COUNT, false);

        int index = directoryAlignedAddr / (PAGE_SIZE*PAGE_ENTRY_COUNT);
        
        if (index < 0)
            return false;

        // check if the page_table exists or needs to be made
        if (page_directory[index].present) {
            /* The page table exists, so overwrite the settings
               Find the index of the page_table_entry inside, first subtract the directory alligned address from the whole address, then 
               divide this by the size of each page entry
            */
            size_t pageTableIndex = (currentAddress - directoryAlignedAddr) / PAGE_SIZE;
            // because the address of the page table array is shifted by 12, unshift it
            page_table_entry_t* entry = (page_table_entry_t*)(page_directory[index].frame << 12);
            if (!entry)
                return false;
            entry[pageTableIndex].present = 1;
            entry[pageTableIndex].rw = !readOnly;
            entry[pageTableIndex].user = userMode;
            entry[pageTableIndex].frame = currentAddress >> 12;         
        } else {
            
            size_t pageTableIndex = (currentAddress - directoryAlignedAddr) / PAGE_SIZE;

            // dynamically allocates a new entry into the page directory
            page_table_entry_t* entry = (page_table_entry_t*)kmalloc(sizeof(page_table_entry_t)*PAGE_ENTRY_COUNT, true);
            if (!entry) {
                return false;
            }
            page_directory[index].present = 1;
            page_directory[index].user = userMode;
            page_directory[index].rw = !readOnly;
            page_directory[index].frame = (size_t)entry >> 12;

            entry[pageTableIndex].present = 1;
            entry[pageTableIndex].rw = !readOnly;
            entry[pageTableIndex].user = userMode;
            entry[pageTableIndex].frame = currentAddress >> 12;

        }


    }
    return true;
}


bool page_addresses(size_t startPhysAddr, size_t endPhysAddr, size_t startVirtAddr, size_t endVirtAddr, bool userMode, bool readOnly) {
    // If the amount to page isnt equal, incorrect values were passed
    if (endPhysAddr - startPhysAddr != endVirtAddr - startVirtAddr) {
        return false;
    }

        /*
     * We want the addresses to include everything the caller wants, so include the floor of the start and the ceiling of the end 
    */
    startPhysAddr = alignAddress(startPhysAddr, PAGE_SIZE, false);
    endPhysAddr = alignAddress(endPhysAddr, PAGE_SIZE, true);

    startVirtAddr = alignAddress(startVirtAddr, PAGE_SIZE, false);
    endVirtAddr = alignAddress(endVirtAddr, PAGE_SIZE, true);

    size_t currentPhysAddr = startPhysAddr;
    
    for (size_t currentVirtAddr = startVirtAddr; currentVirtAddr < endVirtAddr; currentVirtAddr+=PAGE_SIZE) {
        // figure out which index of the page_directory this page belongs to
        size_t directoryAlignedAddr = alignAddress(currentVirtAddr, PAGE_SIZE*PAGE_ENTRY_COUNT, false);

        int index = directoryAlignedAddr / (PAGE_SIZE*PAGE_ENTRY_COUNT);
        
        if (index < 0)
            return false;

        // check if the page_table exists or needs to be made
        if (page_directory[index].present) {
            /* The page table exists, so overwrite the settings
               Find the index of the page_table_entry inside, first subtract the directory alligned address from the whole address, then 
               divide this by the size of each page entry
            */
            size_t pageTableIndex = (currentVirtAddr - directoryAlignedAddr) / PAGE_SIZE;
            // because the address of the page table array is shifted by 12, unshift it
            page_table_entry_t* entry = (page_table_entry_t*)(page_directory[index].frame << 12);
            if (!entry)
                return false;
            entry[pageTableIndex].present = 1;
            entry[pageTableIndex].rw = !readOnly;
            entry[pageTableIndex].user = userMode;
            entry[pageTableIndex].frame = currentPhysAddr >> 12;  
        } else {
            
            size_t pageTableIndex = (currentVirtAddr - directoryAlignedAddr) / PAGE_SIZE;
            
            
            // dynamically allocates a new entry into the page directory
            page_table_entry_t* entry = (page_table_entry_t*)kmalloc(sizeof(page_table_entry_t)*PAGE_ENTRY_COUNT, true);
            if (!entry) {
                return false;
            }
            page_directory[index].present = 1;
            page_directory[index].user = userMode;
            page_directory[index].rw = !readOnly;
            page_directory[index].frame = (size_t)entry >> 12;

            entry[pageTableIndex].present = 1;
            entry[pageTableIndex].rw = !readOnly;
            entry[pageTableIndex].user = userMode;
            entry[pageTableIndex].frame = currentPhysAddr >> 12;
        }
        currentPhysAddr += PAGE_SIZE;
    }
    return true;
}
 

size_t alignAddress(size_t addr, size_t roundTo, bool roundUp) {
    int mod = addr % roundTo;

    // the value is already aligned
    if (mod == 0) 
        return addr;
    addr = addr - mod;
    if (roundUp) 
        addr += roundTo;
    return addr;
}

void page_fault(registers_t* regs)
{
   // A page fault has occurred.
   // The faulting address is stored in the CR2 register.
   uint32_t faulting_address;
   asm volatile("mov %%cr2, %0" : "=r" (faulting_address));

   // The error code gives us details of what happened.
   int present   = !(regs->err_code & 0x1); // Page not present
   int rw = regs->err_code & 0x2;           // Write operation?
   int us = regs->err_code & 0x4;           // Processor was in user-mode?
   int reserved = regs->err_code & 0x8;     // Overwritten CPU-reserved bits of page entry?
   int id = regs->err_code & 0x10;          // Caused by an instruction fetch?

   // Output an error message.
   kprintf("Page fault ( ");
   if (present) {kprintf("not present ");}
   if (rw) {kprintf("read-only ");}
   if (us) {kprintf("user-mode ");}
   if (reserved) {kprintf("reserved ");}
   if (id) {kprintf("instruction fetch ");}
   kprintf(") at 0x");
   kout << hex << faulting_address << '\n';
   asm("hlt");
}