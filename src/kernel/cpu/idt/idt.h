#ifndef IDT_H
#define IDT_H

#include <stdint.h>
#include <functions.h>
#include <io.h>

// A struct describing an interrupt gate.
struct idt_entry_struct
{
   uint16_t base_lo;             // The lower 16 bits of the address to jump to when this interrupt fires.
   uint16_t sel;                 // Kernel segment selector.
   uint8_t  always0;             // This must always be zero.
   uint8_t  flags;               // More flags. See documentation.
   uint16_t base_hi;             // The upper 16 bits of the address to jump to.
} __attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;

// A struct describing a pointer to an array of interrupt handlers.
// This is in a format suitable for giving to 'lidt'.
struct idt_ptr_struct
{
   uint16_t limit;
   size_t base;                // The address of the first element in our idt_entry_t array.
} __attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

void idtInit();
extern "C" void isr0 ();
extern "C" void isr1 ();
extern "C" void isr2 ();
extern "C" void isr3 ();
extern "C" void isr4 ();
extern "C" void isr5 ();
extern "C" void isr6 ();
extern "C" void isr7 ();
extern "C" void isr8 ();
extern "C" void isr9 ();
extern "C" void isr10();
extern "C" void isr11();
extern "C" void isr12();
extern "C" void isr13();
extern "C" void isr14();
extern "C" void isr15();
extern "C" void isr16();
extern "C" void isr17();
extern "C" void isr18();
extern "C" void isr19();
extern "C" void isr20();
extern "C" void isr21();
extern "C" void isr22();
extern "C" void isr23();
extern "C" void isr24();
extern "C" void isr25();
extern "C" void isr26();
extern "C" void isr27();
extern "C" void isr28();
extern "C" void isr29();
extern "C" void isr30();
extern "C" void isr31();
extern "C" void irq0 ();
extern "C" void irq1 ();
extern "C" void irq2 ();
extern "C" void irq3 ();
extern "C" void irq4 ();
extern "C" void irq5 ();
extern "C" void irq6 ();
extern "C" void irq7 ();
extern "C" void irq8 ();
extern "C" void irq9 ();
extern "C" void irq10();
extern "C" void irq11();
extern "C" void irq12();
extern "C" void irq13();
extern "C" void irq14();
extern "C" void irq15();
extern "C" void irq16();


#endif