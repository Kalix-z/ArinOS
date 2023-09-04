#include "gdt.h"

/* exposes gdt_flush to assembly */
extern "C" void gdt_flush(size_t p_gdt);
extern "C" void tss_flush();
extern "C" void internal_switch_to_user(void(*callback)());


/* function prototypes*/
static void init_gdt();
static void set_gdt_gate(int32_t num, size_t base, size_t limit, uint8_t access, uint8_t gran);
void write_tss(int32_t num, uint16_t ss, size_t esp);

gdt_entry_t gdt_entries[6];
gdt_ptr_t   p_gdt;
tss_entry_t tss_entry;

/* initializes the gdts null segment, kernel&user code segment, kernel&user data segment, */
void gdt_init()
{
   p_gdt.limit = (sizeof(gdt_entry_t) * 6) - 1;
   p_gdt.base  = (size_t)&gdt_entries;

   set_gdt_gate(0, 0, 0, 0, 0);                /* Null segment */
   set_gdt_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); /* Code segment */
   set_gdt_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); /* Data segment */
   set_gdt_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); /* User mode code segment */
   set_gdt_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); /* User mode data segment */
   write_tss(5, 0x10, 0);


   gdt_flush((size_t)&p_gdt);
   tss_flush();
   kout << "GDT Initialized\n";
}

/* sets each gdt gate */
void set_gdt_gate(int32_t num, size_t base, size_t limit, uint8_t access, uint8_t gran)
{
   gdt_entries[num].base_low    = (base & 0xFFFF);
   gdt_entries[num].base_middle = (base >> 16) & 0xFF;
   gdt_entries[num].base_high   = (base >> 24) & 0xFF;

   gdt_entries[num].limit_low   = (limit & 0xFFFF);
   gdt_entries[num].granularity = (limit >> 16) & 0x0F;

   gdt_entries[num].granularity |= gran & 0xF0;
   gdt_entries[num].access      = access;
}

void write_tss(int32_t num, uint16_t ss, size_t esp) {
   size_t base = (size_t)&tss_entry;
   size_t limit =  base + sizeof(tss_entry);

   set_gdt_gate(num, base, limit, 0xE9, 0x0);

   memset((uint8_t*)&tss_entry, 0, sizeof(tss_entry));

   tss_entry.ss0 = ss;
   tss_entry.esp0 = esp;

   tss_entry.cs = 0x0b;
   tss_entry.ss = tss_entry.ds = tss_entry.es = tss_entry.fs = tss_entry.gs = 0x13;
}

void switch_to_usr(void(*callback)()) {
   char* stack = new char[4096];
   tss_entry.esp0 = (size_t)stack;
   internal_switch_to_user(callback);
   delete[] stack;
}