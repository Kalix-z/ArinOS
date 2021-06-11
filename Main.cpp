#include "Print.h"
#include "IO.h"
#include "KeyboardInput.h"
#include "String.h"
#include "CommandHandler.h"
#include "ReadDisk.cpp"

extern "C" void _start()
{
    SetPositionFromCoords(26, 0);
    String StartingText = "Starting Slav Dog OS\n";
    Printf(StartingText, 2);
    Printf('\n', 15);
    AddTerminalSign();
    while(true) { 
        char key = GetKey();
        CheckForShift();
        /* NULL is the code for no key being pressed */
        if(key != 0x00 && key != enter /* enter */ && key != backspace /* backspace */) {  
            textCount++;
            Printf(key, 15);        
            KeyPressed(key);
        } 
        /* enter */
        else if(key == enter) {
            Printf('\n', 15);
            EnterPressed();
        }
        /* Backspace */
        else if(key == backspace) {
            Backspace();
        }
    }

}
/* TODO: 
 * Finish String.Apppend()
 * Dont Let User Backspace past what they wrote
*/