#include "Print.h"
#include "Types.h"
#include "IO.h"
#include "Color.h"
#include "KeyboardInput.h"
#include "GraphicsDriver.h" 

extern "C" void _start()
{
    SetPositionFromCoords(25, 0);
    Printf("Starting Slav Dog OS\n", 2);
    while(true) {
        
        char* key = GetKey();
        CheckForShift();
        /* 1311691 is the code i gave to no key being pressed */
        if(key != (char*)1311691) {
            
            Printf(key, 15);
        } 
    }

}
/**
 * 
 * 
 *     
 * char* ptr = (char*)0xB8000000;
    *ptr = 0x4F;
    ptr++;
    *ptr = 0x20;
 **/

