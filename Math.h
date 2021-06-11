#pragma once
#include "Types.h"
/* returns the absolute value of a float */
float abs(float num);
/* returns the absolute value of an int */
int abs(int num);
/*returns number to the 'powerth' power */
float pow(float num, float power);
/* returns largest value */
uint_8 Max (uint_8 n, uint_8 t);
int Max (int n, int t);
float Max (float n, float t);
uint_16 Max (uint_16 n, uint_16 t);
uint_32 Max (uint_32 n, uint_32 t);
/* returns smallest value */
float Min (float n, float t);
/* value of pi (to the 1000th digit) */
//int F(float x);
/* Checks if 2 Arrays are identical */
bool ArrayComparison(char ar1[], char ar2[]);
bool ArrayComparison(char ar1[], const char ar2[]);
bool ArrayContains(char array[], char check[]);

/* Credit to @Lakshya Raj on Stack Overflow */ 
int Floor(float x);