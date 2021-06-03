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
        if(key != (char*)1311691 && key != (char*)1001111111111011 /* enter */ && key != (char*)1101111111111111 /* backspace */) {
            
            Printf(key, 15);
        } 
        else if(key == (char*)1001111111111011) {
            Printf("\n", 15);
        }
        else if(key == (char*)1101111111111111) {
            Backspace();
        }
    }

}

  






