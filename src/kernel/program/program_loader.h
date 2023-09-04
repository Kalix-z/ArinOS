#ifndef __PROGRAM_LOADER_H_
#define __PROGRAM_LOADER_H_

#include <stddef.h>
#include <stdint.h>
#include <screen.h>
#include <paging.h>
#include <filesystem.h>
#include <memory.h>
#include <gdt.h>

# define ELF_NIDENT	16

#define ELF_MAGIC_NUM 0x7F
#define ELF_32_BIT 1
#define ELF_LITTLE_ENDIAN 1
#define ELF_EXECUTABLE 2
#define ELF_x86 3

typedef struct {
	uint8_t		e_ident[ELF_NIDENT];
	uint16_t	e_type;
	uint16_t	e_machine;
	size_t	e_version;
	size_t	e_entry;
	size_t	e_phoff;
	size_t	e_shoff;
	size_t	e_flags;
	uint16_t	e_ehsize;
	uint16_t	e_phentsize;
	uint16_t	e_phnum;
	uint16_t	e_shentsize;
	uint16_t	e_shnum;
	uint16_t	e_shstrndx;
}__attribute__((packed)) elf_header_t;

typedef struct {
	size_t	sh_name;
	size_t	sh_type;
	size_t	sh_flags;
	size_t	sh_addr;
	size_t	sh_offset;
	size_t	sh_size;
	size_t	sh_link;
	size_t	sh_info;
	size_t	sh_addralign;
	size_t	sh_entsize;
} elf_section_header_t;

enum sht_types {
	SHT_NULL	= 0,   // Null section
	SHT_PROGBITS	= 1,   // Program information
	SHT_SYMTAB	= 2,   // Symbol table
	SHT_STRTAB	= 3,   // String table
	SHT_RELA	= 4,   // Relocation (w/ addend)
	SHT_NOBITS	= 8,   // Not present in file
	SHT_REL		= 9,   // Relocation (no addend)
};
 
enum sht_attr {
	SHF_WRITE	= 0x01, // Writable section
	SHF_ALLOC	= 0x02  // Exists in memory
};

bool valid_elf_header(elf_header_t* header);
bool load_program(const char* path);

#endif