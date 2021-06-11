/*
 * 5/26/2021 
 */
#include "Types.h"
#include "Print.h"
#include "Math.h"


int strlen(const char *str)
{
    int retval;
    for(retval = 0; *str != '\0'; str++) {
        retval++;
    }
    return retval;
}

char* flipStr(char* str) {
    char temp; 
  	int i, j = 0; 
    for( i=0,j = strlen(str) - 1 ; i < j; i++,j--){ 
		temp = str[i]; 
		str[i] = str[j]; 
		str[j] = temp; 
	}   
    return str;
}

int intLength(int i) {
    int l=0;
    for(;i;i/=10) l++;
    return l==0 ? 1 : l;
}

int strToInt(const char* string) {
    int count = strlen(string);
    /* 48 is the ascii code for 0 */
    int final = 0;
    string = flipStr((char*)string);
    for(int i = 0; i < count; i++){
        if(i != 0) {
            final += ((int)string[i] - 48) * pow(10, i);
        } else {
            final += ((int)string[i] - 48);
        }
        
    }
    return final;
}

int oct2bin(unsigned char *str, int size) {
    int n = 0;
    unsigned char *c = str;
    while (size-- > 0) {
        n *= 8;
        n += *c - '0';
        c++;
    }
    return n;
}


int strToInt(const char* string, int index, int count) {
    /* 48 is the ascii code for 0 */
    int final = 0;
    string = flipStr((char*)string);
    for(int i = 0; i < count; i++){
        if(i != 0) {
            final += ((int)string[i + index] - 48) * pow(10, i);
        } else {
            final += ((int)string[i + index] - 48);
        }
        
    }
    return final;
}


/* Allocates memory at 'location' with 'size' bytes */
void malloc(uint_8* location, uint_32 size) {
    for(int i = 0; i<size; i++) {
        *location = 0x00;
        location++;
    }
} 

void *memcpy(void *dest, const void *src, int count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for(;count != 0;count--) 
        *dp++ = *sp++;
    return dest;
}

void *memset(void *dest, char val, int count)
{
    char *temp = (char *)dest;
    for(;count != 0; count--)
        *temp++ = val;
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
    unsigned short *temp = (unsigned short *)dest;
    for(;count != 0; count--) 
        *temp++ = val;
    return dest;
}



unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}