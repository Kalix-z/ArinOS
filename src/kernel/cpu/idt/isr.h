#ifndef ISR_H
#define ISR_H

#include <stdint.h>
/* to write to the screen */
#include <screen.h>

#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

typedef struct registers
{
    size_t ds;                  // Data segment selector
    size_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
    size_t int_no, err_code;    // Interrupt number and error code (if applicable)
    size_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t;

typedef void (*isr_t)(registers_t*);

void register_interrupt_handler(uint8_t n, isr_t handler);

// All x86 Exceptions 
static const char* errNames[17] = {
    "Divide By Zero",
    "Debug",
    "Non-Maskable Interupt",
    "Breakpoint",
    "Overflow",
    "Bound Range Exceeded",
    "Invalid Opcode",
    "Device Not Available",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Invalid TSS",
    "Segment Not Present",
    "Stack-Segment Fault",
    "General Protection Fault",
    "Page Fault",
    "N/A",
    "x87 Floating Point Exception"
};

#endif