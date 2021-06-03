/* 
 * 5/27/2021
 */
#pragma once
void SetVesaMode();
void SetVGAPallete();
/* Sets Backround of screen */
void SetBackround(uint_8 VGA_COLOR);
/* Puts Pixel At Coord */
void putpixel(int pos_x, int pos_y, unsigned char VGA_COLOR);
/* Fills A Rectangle */
void FillRectangle(int posx, int posy, int width, int height, unsigned char VGA_COLOR);
/* Clears Screen */
void ClearScreen();