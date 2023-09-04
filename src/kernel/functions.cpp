#include "functions.h"

// Copy len bytes from src to dest.
void memcpy(void *_dest, const void *_src, size_t len)
{
    char* dest = (char*)_dest;
    char* src = (char*)_src;
    for (size_t i = 0; i < len; i++) {
        *dest = *src;
        dest++;
        src++;
    }
}

// Write len copies of val into dest.
void memset(uint8_t *dest, uint8_t val, size_t len)
{
    uint8_t *temp = (uint8_t *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

/* converts int to string */
void itoa (char* buf, int num, int base) {

     char digits[11]; /* 2^32 has 11 digits, so this is the max digits needed */
        int count = 0;
        if (num == 0) {
            buf[0] = '0';
            buf[1] = 0x00;
            return;
        }
        int tempNum = num;
        while (tempNum != 0) {
            int remainder = abs(tempNum) % base;
            tempNum = abs(tempNum) / base;
            if (remainder < 10)
                digits[count] = '0' + remainder;
            else
                digits[count] = 'A' + remainder - 10;
            count++;
        }

        /* adds negative sign if nessisary */
        int t;
        if (num < 0) {
            t = 1;
            buf[0] = '-';
        }
        else {
            t = 0;
        }
        /* Flips string back into right order */
        for (int i = count; i > 0; i--) {
            buf[t] = digits[i - 1];
            t++;
        }
        buf[t] = 0x0; /* Null Terminates string */
}


/* converts int to string */
void itoa (char* buf, size_t num, int base) {

     char digits[11]; /* 2^32 has 11 digits, so this is the max digits needed */
        int count = 0;
        if (num == 0) {
            buf[0] = '0';
            buf[1] = 0x00;
            return;
        }
        size_t tempNum = num;
        while (tempNum != 0) {
            size_t remainder = tempNum % base;
            tempNum = tempNum / base;
            if (remainder < 10)
                digits[count] = '0' + remainder;
            else
                digits[count] = 'A' + remainder - 10;
            count++;
        }
        int t = 0;
        /* Flips string back into right order */
        for (int i = count; i > 0; i--) {
            buf[t] = digits[i - 1];
            t++;
        }
        buf[t] = 0x0; /* Null Terminates string */
}

int abs (int val) {
    if (val >= 0)
        return val;
    return -val;
}

size_t strlen(const char* str) {
    size_t rVal = 0;
    const char* ptr = str;
    while (*ptr != '\0') {
        rVal++;
        ptr++;
    }
    return rVal;
}