/* 
 * 5/27/2021
 */
#include "Types.h"
#include "GraphicsDriver.h"
#include "anime.cpp"
#include "Color.h"
void DisplayImg() {
    const float width = Swidth;
    const float height = Sheight;

    int widthCount = 0;
    int heightCount = 0;
    for(int i = 0; i < width * height; i++) {
        if(anime[(int)i] != 0x00) {
            if(widthCount == width) {
                heightCount++;
                widthCount = 0;
                putpixel(widthCount,heightCount, Red);
            }
            else {
                putpixel(widthCount,heightCount, Red);

            }
        }

        if(anime[(int)i] == 0x00) {
            if(widthCount == width) {
                heightCount++;
                widthCount = 0;
                putpixel(widthCount,heightCount, Black);
            }
            else {
                putpixel(widthCount,heightCount, Black);

            }
        }
        widthCount++;
    }
}



