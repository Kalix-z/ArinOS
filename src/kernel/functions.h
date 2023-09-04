#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdint.h>
#include <stddef.h>



size_t strlen(const char* str);

void memcpy(void *dest, const void *src, size_t len);

void memset(uint8_t *dest, uint8_t val, size_t len);

void itoa (char* buf, int num, int base);

void itoa (char* buf, size_t num, int base);

int abs (int val);
#include <screen.h>
#endif