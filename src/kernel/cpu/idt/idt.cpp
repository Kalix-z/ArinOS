#include <idt.h>

idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;

void idt_set_gate(uint8_t,size_t,uint16_t,uint8_t);

extern "C" void idt_flush(size_t);

 

void idtInit()
{
    idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
    idt_ptr.base  = (size_t)&idt_entries;

    memset((uint8_t*)&idt_entries, 0, sizeof(idt_entry_t)*256);

    // Remap the irq table.
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);

    idt_set_gate( 0, (size_t)isr0 , 0x08, 0x8E);
    idt_set_gate( 1, (size_t)isr1 , 0x08, 0x8E);
    idt_set_gate( 2, (size_t)isr2 , 0x08, 0x8E);
    idt_set_gate( 3, (size_t)isr3 , 0x08, 0x8E);
    idt_set_gate( 4, (size_t)isr4 , 0x08, 0x8E);
    idt_set_gate( 5, (size_t)isr5 , 0x08, 0x8E);
    idt_set_gate( 6, (size_t)isr6 , 0x08, 0x8E);
    idt_set_gate( 7, (size_t)isr7 , 0x08, 0x8E);
    idt_set_gate( 8, (size_t)isr8 , 0x08, 0x8E);
    idt_set_gate( 9, (size_t)isr9 , 0x08, 0x8E);
    idt_set_gate(10, (size_t)isr10, 0x08, 0x8E);
    idt_set_gate(11, (size_t)isr11, 0x08, 0x8E);
    idt_set_gate(12, (size_t)isr12, 0x08, 0x8E);
    idt_set_gate(13, (size_t)isr13, 0x08, 0x8E);
    idt_set_gate(14, (size_t)isr14, 0x08, 0x8E);
    idt_set_gate(15, (size_t)isr15, 0x08, 0x8E);
    idt_set_gate(16, (size_t)isr16, 0x08, 0x8E);
    idt_set_gate(17, (size_t)isr17, 0x08, 0x8E);
    idt_set_gate(18, (size_t)isr18, 0x08, 0x8E);
    idt_set_gate(19, (size_t)isr19, 0x08, 0x8E);
    idt_set_gate(20, (size_t)isr20, 0x08, 0x8E);
    idt_set_gate(21, (size_t)isr21, 0x08, 0x8E);
    idt_set_gate(22, (size_t)isr22, 0x08, 0x8E);
    idt_set_gate(23, (size_t)isr23, 0x08, 0x8E);
    idt_set_gate(24, (size_t)isr24, 0x08, 0x8E);
    idt_set_gate(25, (size_t)isr25, 0x08, 0x8E);
    idt_set_gate(26, (size_t)isr26, 0x08, 0x8E);
    idt_set_gate(27, (size_t)isr27, 0x08, 0x8E);
    idt_set_gate(28, (size_t)isr28, 0x08, 0x8E);
    idt_set_gate(29, (size_t)isr29, 0x08, 0x8E);
    idt_set_gate(30, (size_t)isr30, 0x08, 0x8E);
    idt_set_gate(31, (size_t)isr31, 0x08, 0x8E);
    idt_set_gate(32, (size_t)irq0, 0x08, 0x8E);
    idt_set_gate(33, (size_t)irq1, 0x08, 0x8E);
    idt_set_gate(34, (size_t)irq2, 0x08, 0x8E);
    idt_set_gate(35, (size_t)irq3, 0x08, 0x8E);
    idt_set_gate(36, (size_t)irq4, 0x08, 0x8E);
    idt_set_gate(37, (size_t)irq5, 0x08, 0x8E);
    idt_set_gate(38, (size_t)irq6, 0x08, 0x8E);
    idt_set_gate(39, (size_t)irq7, 0x08, 0x8E);
    idt_set_gate(40, (size_t)irq8, 0x08, 0x8E);
    idt_set_gate(41, (size_t)irq9, 0x08, 0x8E);
    idt_set_gate(42, (size_t)irq10, 0x08, 0x8E);
    idt_set_gate(43, (size_t)irq11, 0x08, 0x8E);
    idt_set_gate(44, (size_t)irq12, 0x08, 0x8E);
    idt_set_gate(45, (size_t)irq13, 0x08, 0x8E);
    idt_set_gate(46, (size_t)irq14, 0x08, 0x8E);
    idt_set_gate(47, (size_t)irq15, 0x08, 0x8E);
    idt_set_gate(48, (size_t)irq16, 0x08, 0x8E);


   idt_flush((size_t)&idt_ptr);
   kout << "IDT Initialized\n";
}

void idt_set_gate(uint8_t num, size_t base, uint16_t sel, uint8_t flags)
{
   idt_entries[num].base_lo = base & 0xFFFF;
   idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

   idt_entries[num].sel     = sel;
   idt_entries[num].always0 = 0;

   idt_entries[num].flags   = flags  | 0x60 ;
}
