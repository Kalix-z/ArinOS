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
#include "String.h"
#include "CommandHandler.h"
#include "Print.h"

#define VGA_MEMORY (uint_8*)0xb8000
#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH 80

int textCount = 0;
uint_16 CursorPosition;
static uint_16 index;


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

void floatToStr(float num, char ar[]) {
    bool lessthan0 = false;
    char digits[12]; /* 2^32 has 11 digits, so this is the max digits needed, plus one for null termination */
	int count = 0;
	if (num == 0) {
		ar[0] = '0';
	}
	int tempNum = num;
	while (tempNum != 0x00) {
        /* This is Reached When we hit the decimal sign */
        if(tempNum < 0) {
            tempNum *= 10;
            float remainder = Floor(tempNum) % 10;
		    tempNum = abs(tempNum) / 10;
		    digits[count] = '0' + remainder;
		    count++;
        }
		float remainder = Floor(tempNum) % 10;
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
    /*Flips string back into right order */
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
    index = CursorPosition;
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
void Printf(char str, uint_8 color) {
    uint_8 charPtr = (uint_8) str;
    index = CursorPosition;
   
        
        switch(charPtr) {
            /* /r case */
            case 13:
			index -= index % SCREEN_WIDTH;
			break;
            /* /n case */
            case 10:
                index += SCREEN_WIDTH;
                index -= index % SCREEN_WIDTH;
                break;
            default:
                *(VGA_MEMORY + index * 2) = charPtr;
                *(VGA_MEMORY + index * 2 + 1) = color;

                index++;
        }

        charPtr++;
    
    SetCursorPosition(index);
}

void Printf(const char* str, uint_8 color) {
    uint_8* charPtr = (uint_8*) str;
    index = CursorPosition;
    while (*charPtr != 0)
    {
        
        switch(*charPtr) {
            case 13:
			index -= index % SCREEN_WIDTH;
			break;
            case 10:
                index += SCREEN_WIDTH;
                index -= index % SCREEN_WIDTH;
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

void Printf(const char* str, char endChar, uint_8 color) {
    uint_8* charPtr = (uint_8*) str;
    index = CursorPosition;
    while (*charPtr != 0)
    {
        
        switch(*charPtr) {
            case 13:
			index -= index % SCREEN_WIDTH;
			break;
            case 10:
                index += SCREEN_WIDTH;
                index -= index % SCREEN_WIDTH;
                break;
            default:
                *(VGA_MEMORY + index * 2) = *charPtr;
                *(VGA_MEMORY + index * 2 + 1) = color;

                index++;
        }

        charPtr++;
    }
    SetCursorPosition(index);
    Printf(endChar, 15);
}



void Printf(String str, uint_8 color) {
    uint_8* charPtr = (uint_8*) str.getArray();
    index = CursorPosition;
    while (*charPtr != 0)
    {
        
        switch(*charPtr) {
            case 13:
			index -= index % SCREEN_WIDTH;
			break;
            case 10:
                index += SCREEN_WIDTH;
                index -= index % SCREEN_WIDTH;
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




/* Handles Backspaces */
void Backspace() {
    if(textCount > 0) {
        index--;
        *(VGA_MEMORY + index * 2) = 0x00;
        SetCursorPosition(index);
        BackspaceCMD();
        textCount --;
    }
}

/* Prints num to screen */
void Printf(int num) {
    char a[11] = "";
    intToStr(num, a);
    Printf(a, 15);
}

/* Prints float to screen */
void Printf(float num) {
    char a[11] = "";
    floatToStr(num, a);
    Printf(a, 15);
}

/* Clears Screen */
void ClearScreen() {
    int* ptr = (int*)VGA_MEMORY;
    for(int i = 0; i < 4000; i++) {
        *ptr = ' ';
        ptr++;
    }
}



