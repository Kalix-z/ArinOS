/**
 * 5/19/2021
 **/


/** 
 * outb(): outbuts byte a into position b
 * short: 16 bit data type [2 bytes]
 * char: 8 bit data type [1 byte]
 **/
#include "IO.h"
#include "Types.h"
#include "Math.h"
#define VGA_MEMORY (uint_8*)0xb8000
#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH 80
uint_16 CursorPosition;

 //Sets Cursor Position (note: the 'position' is not width and height!)
void SetCursorPosition(uint_16 position) { 
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint_16)(position & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint_16)((position >> 8) /**shifts position by 8**/ & 0xFF));
    CursorPosition = position;
}
 
void SetPositionFromCoords(uint_8 x, uint_8 y) {
    uint_16 position = y * SCREEN_WIDTH + x;
    SetCursorPosition(position);
}




/* Converts an int to a char* */
void intToStr(int num, char ar[]) {
	
	char digits[11]; /* 2^32 has 11 digits, so this is the max digits needed */
	int count = 0;
	if (num == 0) {
		ar[0] = '0';
	}
	int tempNum = num;
	while (tempNum != 0) {
		int remainder = abs(tempNum) % 10;
		tempNum = abs(tempNum) / 10;
		digits[count] = '0' + remainder;
		count++;
	}

    /* adds negative sign if nessisary */
	int t;
	if (num < 0) {
		t = 1;
		ar[0] = '-';
	}
	else {
		t = 0;
	}
    /* Flips string back into right order */
	for (int i = count; i > 0; i--) {
		ar[t] = digits[i - 1];
		t++;
	}
	ar[t + 1] = 0x0; /* Null Terminates string */
	

}

/*Prints string to screen 
Colors:
    0: Black
    1: Blue
    2: Green
    3: Cyan
    4: Red
    5: Magenta
    6: Brown
    7: Light Gray
    8: Dark Gray
    9: Light Blue
    10: Light Green
    11: Light Cyan
    12: Light Red
    13: Light Magenta
    14: Yellow
    15: White

*/
void PrintfWithoutMovingCursor(const char* str, uint_8 color) {
       uint_8* charPtr = (uint_8*) str;
    uint_16 index = CursorPosition;
    while (*charPtr != 0)
    {
        
        switch(*charPtr) {
            case 10:
                index += SCREEN_WIDTH;
                break;
            default:
                *(VGA_MEMORY + index * 2) = *charPtr;
                *(VGA_MEMORY + index * 2 + 1) = color;
                index++;
        }

        charPtr++;
    }
}

void Printf(const char* str, uint_8 color) {
    uint_8* charPtr = (uint_8*) str;
    uint_16 index = CursorPosition;
    while (*charPtr != 0)
    {
        
        switch(*charPtr) {
            case 10:
                index += SCREEN_WIDTH;
                break;
            default:
                *(VGA_MEMORY + index * 2) = *charPtr;
                *(VGA_MEMORY + index * 2 + 1) = color;

                index++;
        }

        charPtr++;
    }
    SetCursorPosition(index);
}

/*void Printf(const char* str, uint_8 color) {
	uint_8* charPtr = (uint_8*)str;
	uint_16 offset = CursorPosition;
        //int* ptr = (int*) 0xb8000;
        //*ptr = 'x';
	while (*charPtr != 0) { //Checks for null termination
        
		switch (*charPtr) {
		case 10: //checking for \n
			offset -= offset % SCREEN_WIDTH;
			offset += SCREEN_WIDTH; //Creates new line
			break;
		case 13:
			offset -= offset % SCREEN_WIDTH;
			break;
		default:
			*(VGA_MEMORY + offset * 2) = *charPtr; //prints to the mouse location
			//*(VGA_MEMORY + offset * 2 + 1) = color;
			offset++;
		}
		charPtr++;

	}
	SetCursorPosition(offset);
} */

/* Prints num to screen */
void Printf(const int num) {
    char a[11] = "";
    intToStr(num, a);
    Printf(a, 15);
}


void ClearScreen() {
    int* ptr = (int*)VGA_MEMORY;
    for(int i = 0; i < 4000; i++) {
        *ptr = ' ';
        ptr++;
    }
}


/**
 *     
global _idt_load
extern _idtp
_idt_load:
    lidt [_idtp]
    ret
**/

