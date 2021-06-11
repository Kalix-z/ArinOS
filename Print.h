#pragma once
#include "Types.h"
#include "String.h"

extern int textCount;

/* index of vga memory */
//static uint_16 index;
/* Prints string to cursor position */
void Printf(const char* str, uint_8 color);
/* Will remove the last character */
void Backspace();
/* Sets Position given an 'x' and 'y' coord */
void SetPositionFromCoords(uint_8 x, uint_8 y);
/* (Dont Use) Sets cursor position linearly */
void SetCursorPosition(uint_16 position);
/* Prints char* */
void Printf(const int str);
/* converts int into string */
void intToStr(int num, char ar[]);
/* Clears Screen */
void ClearScreen();
/* Prints a char*, but the cursor stays at the original position */
void PrintfWithoutMovingCursor(const char* str, uint_8 color);
/* Prints a String */
void Printf(String str, uint_8 color);
/* Prints a String with the specified character at the end */
void Printf(const char* str, char endChar, uint_8 color);
/* Prints a character with the specified color */
void Printf(char str, uint_8 color);

void Printf(float num);