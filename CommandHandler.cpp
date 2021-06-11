/*
 * 6/3/2021
 */
#include "Print.h"
#include "Color.h"
#include "Types.h"
#include "Math.h"
#include "List.h"
#include "Math.h"
#include "System.h"
List<char> TextTyped;
void AddTerminalSign() {
    Printf("Terminal $ ", White);
}

void KeyPressed(char key) {
    TextTyped.Add(key);
}


float* GetNumber(float startIndex) {
    int len = 0;
    int final = 0;
    bool negative = false;
    char curChar = TextTyped.get(startIndex);

    /*Goes through what was typed for as long as there is a number (the ascii value of they char is between 0 and 9 inclusive) */
    while((int)curChar >= '0' && (int)curChar <= '9') {
        /* Gets the int value of cur char by subtracting it by 0's ascii code (the numbers go up consistently in the ascii table) */
        final += ((int)curChar - '0');
        /* When the next number comes around, it needs to be 10 times as less */
        final *= 10;
        len++;
        curChar = TextTyped.get(startIndex + len);
    }

    /* Since we are multiplying by 10 at the end, we must divide by 10 again to reallign the value */
    if(len > 0) {
        final /= 10;
    }

    int i = 1;
    if(curChar == '.') {
        len++;
        curChar = TextTyped.get(startIndex + len);

        while((int)curChar >= '0' && (int)curChar <= '9') {
            final += ((int)curChar - '0') / (i*10);
            len++;
            curChar = TextTyped.get(startIndex + len);
            i++;
        }
    }
    

    
    float* finalArr = new float[2];
    finalArr[0] = final;
    finalArr[1] = len;
    return finalArr;
}


bool CheckAtStart(const char* command) {
    /* Converts the const char* to a char* */
    char* cmd = (char*)command;
    int sizeOfCommand = strlen(cmd);

    /* The Command Cant have been ran if nothing was typed */
    if(TextTyped.count < 1) {
        return false;
    }

    /* loops through the array and if any character isnt equal to the character at the same index in the command, the function returns false */
    for(int i = 0; i < sizeOfCommand; i++) {        
        if(cmd[i] != TextTyped.get(i)) {
            return false;
        }      
    }
    return true;
}

bool CheckForCommand(const char* command) {
    char* cmd = (char*)command;
    int sizeOfCommand = strlen(cmd);
    /* If the Length of what was typed is 0, dont bother looping through the rest */
    if(TextTyped.count < 1) {
        return false;
    }
    /* if the length of the command isnt the length of the text typed, return false */
    if(sizeOfCommand != TextTyped.count) { 
            return false;
    }
    /* if any character of what was typed doesnt match, return false */
    for(int i = 0; i < TextTyped.count; i++) {        
        if(cmd[i] != TextTyped.get(i)) {
            return false;
        }      
    }
    /* All other posiblities have been exausted */
    return true;    
}

void EnterPressed() {

    bool CommandRan = false;

    if(CheckAtStart("echo") || CheckAtStart("Echo")) {
        Printf("echo\n", 15);
        CommandRan = true;
    }

    if(CheckAtStart("ADD") || CheckAtStart("Add") || CheckAtStart("add")) {
        float* ar1 = GetNumber(4);
        float num1 = ar1[0];

        //4 is the length of add, ar1[1] is the size of the last number, and 1 is the space in between
        float* ar2 = GetNumber((ar1[1] + 4 + 1));
        float num2 = ar2[0];
        Printf(num1 + num2);
        Printf('\n', 15);

        CommandRan = true;
    }

    if(CheckAtStart("SUB") || CheckAtStart("Sub") || CheckAtStart("sub")) {
        float* ar1 = GetNumber((4));
        float num1 = ar1[0];
        float* ar2 = GetNumber((ar1[1] + 4 + 1));
        float num2 = ar2[0];
        Printf(num1 - num2);
        Printf('\n', 15);

        CommandRan = true;
    }

    if(CheckAtStart("MULTI") || CheckAtStart("Multi") || CheckAtStart("multi")) {
        float* ar1 = GetNumber(6);
        float num1 = ar1[0];
        float* ar2 = GetNumber((ar1[1] + 6 + 1));
        float num2 = ar2[0];
        Printf(num2 * num1);
        Printf('\n', 15);

        CommandRan = true;
    }

    if(CheckAtStart("DIV") || CheckAtStart("Div") || CheckAtStart("div")) {
        float* ar1 = GetNumber(4);
        float num1 = ar1[0];
        float* ar2 = GetNumber((ar1[1] + 4 + 1));
        float num2 = ar2[0];
        Printf(num1 / num2);
        Printf('\n', 15);

        CommandRan = true;
    }
    if(CheckForCommand("help") || CheckForCommand("Help")) {
        Printf("All Commands:\n\nHelp: This\nEcho: Returns Value Passed\nAdd:  Adds 2 Numbers\nSub:  Subtracts 2 Numbers\nMulti: Multiplies 2 Numbers\nDiv: Divides 2 Numbers", '\n', 15);
        CommandRan = true;
    } 

    if(CommandRan == false)
    {
        Printf("Unkown Command, try 'Help' For All Commands\n", 15);
    }
    TextTyped.Clear();
    AddTerminalSign();       
}

void BackspaceCMD() {
    TextTyped.RemoveLast();
}
