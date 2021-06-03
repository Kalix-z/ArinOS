/* 
 * 5/25/2021
 */
#include "Types.h"
#include "IO.h"
#include "Print.h"

bool toggle = false;
bool isShift = false;



void CheckForShift() {
    uint_8 ScanCode = inb(0x60);     
    /* Checking if either lshift or rshift is being held down */
    if(ScanCode == 0x2A || ScanCode == 0x36) { 
        isShift = true;
    }
    /* Checking if either lshift or rshift is no longer being pressed */
    if(ScanCode == 0xAA || ScanCode == 0xB6) {
        isShift = false;
    }

}

char* GetKey() {
    
    uint_8 ScanCode = inb(0x60);
    /* enter */
    if(ScanCode == 0x1C) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)10010111;
            }
            else {
                return (char*)10010111;
            }
        }
    }
    if(ScanCode == 0x9C) {
        toggle = false;
    }

    /* backspace */
    if(ScanCode == 0xE) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"backspace";
            }
            else {
                return (char*)"backspace";
            }
        }
    }
    if(ScanCode == 0x8E) {
        toggle = false;
    }

    /* space */
    if(ScanCode == 0x39) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)" ";
            }
            else {
                return (char*)" ";
            }
        }
    }
    if(ScanCode == 0xB9) {
        toggle = false;
    }


    /* make code checking (called when key is pressed) */
    if(ScanCode == 0x10) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"q";
            }
            else {
                return (char*)"Q";
            }
        }
    }
    /* break code checking (called when key is not pressed) */
    if(ScanCode == 0x90) { 
        toggle = false;
    }

    /* w */
    if(ScanCode == 0x11) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"w";
            }
            else {
                return (char*)"W";
            }
        }
    }
    if(ScanCode == 0x91) {
        toggle = false;
    }

    /* e */
    if(ScanCode == 0x12) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"e";
            }
            else {
                return (char*)"E";
            }
        }
    }
    if(ScanCode == 0x92) {
        toggle = false;
    }

    /* r */
    if(ScanCode == 0x13) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"r";
            }
            else {
                return (char*)"R";
            }
        }
    }
    if(ScanCode == 0x93) {
        toggle = false;
    }
        
    /* t */
    if(ScanCode == 0x14) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"t";
            }
            else {
                return (char*)"T";
            }
        }
    }
    if(ScanCode == 0x94) {
        toggle = false;
    }

    /* y */
    if(ScanCode == 0x15) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"y";
            }
            else {
                return (char*)"Y";
            }
        }
    }
    if(ScanCode == 0x95) {
        toggle = false;
    }

    /* u */
    if(ScanCode == 0x16) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"u";
            }
            else {
                return (char*)"U";
            }
        }
    }
    if(ScanCode == 0x96) {
        toggle = false;
    }

    /* i */
    if(ScanCode == 0x17) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"i";
            }
            else {
                return (char*)"I";
            }
        }
    }
    if(ScanCode == 0x97) {
        toggle = false;
    }

    /* o */
    if(ScanCode == 0x18) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"o";
            }
            else {
                return (char*)"O";
            }
        }
    }
    if(ScanCode == 0x98) {
        toggle = false;
    }

    /* p */
    if(ScanCode == 0x19) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"p";
            }
            else {
                return (char*)"P";
            }
        }
    }
    if(ScanCode == 0x99) {
        toggle = false;
    }

    /* [ / { */
    if(ScanCode == 0x1A) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"[";
            }
            else {
                return (char*)"{";
            }
        }
    }
    if(ScanCode == 0x9A) {
        toggle = false;
    }

    /* ] / } */
    if(ScanCode == 0x1B) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"]";
            }
            else {
                return (char*)"}";
            }
        }
    }
    if(ScanCode == 0x9B) {
        toggle = false;
    }

    /* | */
    if(ScanCode == 0x2B) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"|";
            }
            else {
                return (char*)"|";
            }
        }
    }
    if(ScanCode == 0xAB) {
        toggle = false;
    }

    /* a */
    if(ScanCode == 0x1e) {     
        if(toggle == false) {
            toggle = true;
            if(isShift == false) {
                return (char*)"a";
            }
            else {
                return (char*)"A";
            }
        }
    }
    if(ScanCode == 0x9e) {
        toggle = false;
    }
        
    /* s */
    if(ScanCode == 0x1F) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"s";
            }
            else {
                return (char*)"S";
            }
        }
    }
    if(ScanCode == 0x9F) {
        toggle = false;
    }

    /* d */
    if(ScanCode == 0x20) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"d";
            }
            else {
                return (char*)"D";
            }
        }
    }
    if(ScanCode == 0xA0) {
        toggle = false;
    }

    /* f */
    if(ScanCode == 0x21) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"f";
            }
            else {
                return (char*)"F";
            }
        }
    }
    if(ScanCode == 0xA1) {
        toggle = false;
    }

    /* g */
    if(ScanCode == 0x22) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"g";
            }
            else {
                return (char*)"G";
            }
        }
    }
    if(ScanCode == 0xA2) {
        toggle = false;
    }

    /* h */
    if(ScanCode == 0x23) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"h";
            }
            else {
                return (char*)"H";
            }
        }
    }
    if(ScanCode == 0xA3) {
        toggle = false;
    }

    /* j */
    if(ScanCode == 0x24) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"j";
            }
            else {
                return (char*)"J";
            }
        }
    }
    if(ScanCode == 0xA4) {
        toggle = false;
    }

    /* k */
    if(ScanCode == 0x25) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"k";
            }
            else {
                return (char*)"K";
            }
        }
    }
    if(ScanCode == 0xA5) {
        toggle = false;
    }

    /* s */
    if(ScanCode == 0x26) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"l";
            }
            else {
                return (char*)"L";
            }
        }
    }
    if(ScanCode == 0xA6) {
        toggle = false;
    }

    /* ; */
    if(ScanCode == 0x27) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)";";
            }
            else {
                return (char*)":";
            }
        }
    }
    if(ScanCode == 0xA7) {
        toggle = false;
    }

    /* ' */
    if(ScanCode == 0x28) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"'";
            }
            else {
                return (char*)"'";
            }
        }
    }
    if(ScanCode == 0xA8) {
        toggle = false;
    }

    

    /* z */
    if(ScanCode == 0x2C) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"z";
            }
            else {
                return (char*)"Z";
            }
        }
    }
    if(ScanCode == 0xAC) {
        toggle = false;
    }

    /* x */
    if(ScanCode == 0x2D) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"x";
            }
            else {
                return (char*)"X";
            }
        }
    }
    if(ScanCode == 0xAD) {
        toggle = false;
    }

    /* c */
    if(ScanCode == 0x2E) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"c";
            }
            else {
                return (char*)"C";
            }
        }
    }
    if(ScanCode == 0xAE) {
        toggle = false;
    }

    /* v */
    if(ScanCode == 0x2F) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"v";
            }
            else {
                return (char*)"V";
            }
        }
    }
    if(ScanCode == 0xAF) {
        toggle = false;
    }

    /* b */
    if(ScanCode == 0x30) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"b";
            }
            else {
                return (char*)"B";
            }
        }
    }
    if(ScanCode == 0xB0) {
        toggle = false;
    }

    /* n */
    if(ScanCode == 0x31) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"n";
            }
            else {
                return (char*)"N";
            }
        }
    }
    if(ScanCode == 0xB1) {
        toggle = false;
    }

    /* m */
    if(ScanCode == 0x32) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"m";
            }
            else {
                return (char*)"M";
            }
        }
    }
    if(ScanCode == 0xB2) {
        toggle = false;
    }

    /* , / < */
    if(ScanCode == 0x33) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)",";
            }
            else {
                return (char*)"<";
            }
        }
    }
    if(ScanCode == 0xB3) {
        toggle = false;
    }

    /* . / > */
    if(ScanCode == 0x34) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)".";
            }
            else {
                return (char*)">";
            }
        }
    }
    if(ScanCode == 0xB4) {
        toggle = false;
    }

    /* / & ? */
    if(ScanCode == 0x35) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"/";
            }
            else {
                return (char*)"?";
            }
        }
    }
    if(ScanCode == 0xB5) {
        toggle = false;
    }
    /* Keyboard Layout 
    switch (inb(0x60))
    {
    case 0x10:
        return (char*)"q";
    case 0x11:
        return (char*)"w";
    case 0x12:
        return (char*)"e";
    case 0x13:
        return (char*)"r";
    case 0x14:
        return (char*)"t";
    case 0x15:
        return (char*)"y";
    case 0x16:
        return (char*)"u";
    case 0x17:
        return (char*)"i";
    case 0x18:
        return (char*)"o";
    case 0x19:
        return (char*)"p";
    case 0x9E:
        return (char*)"a";
    case 31:
        return (char*)"s";
    case 32:
        return (char*)"d";
    case 33:
        return (char*)"f";
    case 34:
        return (char*)"g";
    case 35:
        return (char*)"h";
    case 36:
        return (char*)"j";
    case 37:
        return (char*)"k";
    case 38:
        return (char*)"l";
    case 39:
        return (char*)";";
    case 40:
        return (char*)"'";
    case 44:
        return (char*)"z";
    case 45:
        return (char*)"x";
    case 46:
        return (char*)"c";
    case 47:
        return (char*)"v";
    case 48:
        return (char*)"b";
    case 49:
        return (char*)"n";
    case 50:
        return (char*)"m";

    }
    */

    return (char*)1311691;
}