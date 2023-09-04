#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <stddef.h>

/* reads one byte from port port */
unsigned char inb(uint16_t port);

/* outputs val on port */
void outb(uint16_t port, uint8_t val);

uint16_t inw (uint16_t port);

void outw (unsigned short port, unsigned short data);

void outl(size_t port, size_t value);

size_t inl(size_t port);

#endif