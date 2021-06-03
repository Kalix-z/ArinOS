/* 
 * 5/27/2021
 */
#define PALETTE_MASK  0x3C6
#define PALETTE_READ  0x3C7
#define PALETTE_WRITE 0x3C8
#define PALETTE_DATA  0x3C9
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define VGA_MEMORY 0xA0000
#include "Types.h"
#include "IO.h"

uint_8 BACKROUND_COLOR;

void putpixel(int pos_x, int pos_y, uint_8 VGA_COLOR)
{
    /* 0xA0000 is where VGA memory is stored in the mode we are using */
    uint_8* location = (unsigned char*) VGA_MEMORY + SCREEN_WIDTH * pos_y + pos_x;
    *location = VGA_COLOR;
}


void FillRectangle(int posx, int posy, int width, int height, uint_8 VGA_COLOR) {
    /* loops through the coords of the box and places a pixel */
    for(int x = posx; x < width + posx; x++) {
        for(int y = posy; y < height + posy; y++) {
            putpixel(x,y, VGA_COLOR);
        }
    }
}

/* Sets the whole screen to the color specified */
void SetBackround(uint_8 VGA_COLOR) {
    FillRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, VGA_COLOR);
    BACKROUND_COLOR = VGA_COLOR;

}

/* Clears the screen with the backround color */
void ClearScreenPixel() {
    SetBackround(BACKROUND_COLOR);
}

void SetupCMD(uint_8 bg, uint_8 textColor) {
    SetBackround(bg);

}

void SetupCMD(uint_8 bg, uint_8 textColor, uint_8 spacing) {

}

void SetupCMD(uint_8 bg, uint_8 textColor, uint_8 spacing, uint_8 font_size) {

}
