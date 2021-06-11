#pragma once
#include "Types.h"

/* Allocates memory at 'location' with 'size' bytes */
void malloc(uint_8* location, uint_32 size);

/* copies memory at src to dest */
extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);

/* sets count bytes at dest to val */
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);

/* Memset but with 16 bytes */
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);

/* returns the length of a null terminated char* */
extern int strlen(const char *str);

/* Returns the value at the specified port */
extern unsigned char inportb (unsigned short _port);

/* Sets the value at the specified port */
extern void outportb (unsigned short _port, unsigned char _data);

int strToInt(const char* string);

char* flipStr(char* str);

int strToInt(const char* string, int index, int count);
/* Returns Length of int */
int intLength(int i);

int oct2bin(unsigned char *str, int size);