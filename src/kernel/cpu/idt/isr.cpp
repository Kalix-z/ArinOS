#include "isr.h"

isr_t interrupt_handlers[256];

extern "C" void isr_handler(registers_t regs)
{
    if (interrupt_handlers[regs.int_no] != nullptr) {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(&regs);
        return;
    }
        
    kout << "ERROR, recieved interrupt: " << (int)regs.int_no << '\n';
    kout << "instruction pointer: " << hex << "0x" << regs.eip << '\n';
    kout << "Error Code: " << errNames[regs.int_no];
    asm volatile ("cli\nhlt");
}

extern "C" void irq_handler(registers_t regs)
{

   // Send an EOI (end of interrupt) signal to the PICs.
   // If this interrupt involved the slave.
   if (regs.int_no >= 40)
   {
       // Send reset signal to slave.
       outb(0xA0, 0x20);
   }
   // Send reset signal to master. (As well as slave, if necessary).
   outb(0x20, 0x20);

   if (interrupt_handlers[regs.int_no] != 0)
   {
       isr_t handler = interrupt_handlers[regs.int_no];
       handler(&regs);
       
   }
}

void register_interrupt_handler(uint8_t n, isr_t handler)
{
  interrupt_handlers[n] = handler;
}