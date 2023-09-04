#include "program_loader.h"

bool load_program(const char* path) {
    // reading the file
    FHANDLE f = fatOpen(path);
    if (!f) {
        kout << "failed to open";
        return false;
    }
    
    size_t sz = fatFileSize(f);
    char* file = kmalloc(sz+1, true);
    if (!file)
        return false;
    fatFileRead(f, file, sz, 0);
    
    // the header is at the start of the file
    elf_header_t* header = (elf_header_t*)file;
    if (!valid_elf_header(header))
        return false;
    //identity_page(20 * 0x100000, 20 * 0x100000 + sz, true, false);
    size_t v;
    // e_shoff is the offset in the file where the first section header is
    elf_section_header_t* section_header = (elf_section_header_t*)(header->e_shoff + (size_t)file);
    section_header++;

    
    // go through each section header
    for (int i = 0; i < header->e_shnum; i++) {
        if (section_header->sh_type == SHT_NULL) {
            section_header++;
            continue;
        }
          
        // if the address is 0, the rest of the sections are empty
        if (section_header->sh_addr == 0)
            continue;

            
        page_addresses((size_t)(file + section_header->sh_offset), ((size_t)(file + section_header->sh_offset + section_header->sh_size)), section_header->sh_addr, section_header->sh_addr+section_header->sh_size, true, false);
        
        section_header++;     
    }
    
    void(*_start)() = (void(*)())header->e_entry;

    switch_to_usr(_start);
    return true;
}

bool valid_elf_header(elf_header_t* header) {
    // check magic num
    if (header->e_ident[0] != ELF_MAGIC_NUM || header->e_ident[1] != 'E' || header->e_ident[2] != 'L' || header->e_ident[3] != 'F')
        return false;
    // if this byte is 1, the elf header is 32 bit, if its 2 it is 64 bit
    if (header->e_ident[4] != ELF_32_BIT)
        return false;
    // if this byte is 1, the program is little endian
    if (header->e_ident[5] != ELF_LITTLE_ENDIAN)
        return false;
    // for this byte, 1 = relocatable, 2 = executable, 3 = shared, 4 = core
    if (header->e_type != ELF_EXECUTABLE)
        return false;
    // for this byte, 3 means this is for x86, anything else is another cpu
    if (header->e_machine != ELF_x86)
        return false;
    return true;
}