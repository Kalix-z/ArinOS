#pragma once
#include "Types.h"
/* Prints string to cursor position */
void Printf(const char* str, uint_8 color);
/* Sets Position given an 'x' and 'y' coord */
void SetPositionFromCoords(uint_8 x, uint_8 y);
/* (Dont Use) Sets cursor position linearly */
void SetCursorPosition(uint_16 position);
/* Prints string */
void Printf(const int str);
/* turns int into string */
void intToStr(int num, char ar[]);
/* Clears Screen */
void ClearScreen();
void PrintfWithoutMovingCursor(const char* str, uint_8 color);