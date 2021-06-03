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
                return (char*)1001111111111011;
            }
            else {
                return (char*)1001111111111011;
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
                return (char*)1101111111111111;
            }
            else {
                return (char*)1101111111111111;
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


    /* 1 ! */
    if(ScanCode == 0x02) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"1";
            }
            else {
                return (char*)"!";
            }
        }
    }
    if(ScanCode == 0x82) {
        toggle = false;
    }

    /* 2 @ */
    if(ScanCode == 0x03) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"2";
            }
            else {
                return (char*)"@";
            }
        }
    }
    if(ScanCode == 0x83) {
        toggle = false;
    }

    /* 3 # */
    if(ScanCode == 0x04) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"3";
            }
            else {
                return (char*)"#";
            }
        }
    }
    if(ScanCode == 0x84) {
        toggle = false;
    }

    /* 4 $ */
    if(ScanCode == 0x05) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"4";
            }
            else {
                return (char*)"$";
            }
        }
    }
    if(ScanCode == 0x85) {
        toggle = false;
    }

    /* 5 % */
    if(ScanCode == 0x06) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"5";
            }
            else {
                return (char*)"%";
            }
        }
    }
    if(ScanCode == 0x86) {
        toggle = false;
    }

    /* 6 ^ */
    if(ScanCode == 0x07) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"6";
            }
            else {
                return (char*)"^";
            }
        }
    }
    if(ScanCode == 0x87) {
        toggle = false;
    }

    /* 7 & */
    if(ScanCode == 0x08) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"7";
            }
            else {
                return (char*)"&";
            }
        }
    }
    if(ScanCode == 0x88) {
        toggle = false;
    }

    /* 8 * */
    if(ScanCode == 0x09) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"8";
            }
            else {
                return (char*)"*";
            }
        }
    }
    if(ScanCode == 0x89) {
        toggle = false;
    }

    /* 9 ( */
    if(ScanCode == 0x0A) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"9";
            }
            else {
                return (char*)"(";
            }
        }
    }
    if(ScanCode == 0x8A) {
        toggle = false;
    }

    /* 0 ) */
    if(ScanCode == 0x0B) {     
        if(toggle == false) {
            toggle = true;
            if (isShift == false) {
                return (char*)"0";
            }
            else {
                return (char*)")";
            }
        }
    }
    if(ScanCode == 0x8B) {
        toggle = false;
    }
    /* q */
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
                return (char*)R"(\)";
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
                return (char*)R"(")";
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
    

    return (char*)1311691;
}
