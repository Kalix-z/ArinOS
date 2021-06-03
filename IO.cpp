/**
 * 5/18/2021
 **/
#include "Types.h"

 // Function for outputing a byte to a specified place
void outb(uint_16 port, uint_8 val){ 
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}



 //Function for Inputing a byte and outputing via the I/O bus
unsigned char inb(uint_16 port){ 
    unsigned char returnVal;
    asm volatile ("inb %1, %0"
    : "=a"(returnVal)
    : "Nd"(port));
    return returnVal;
}