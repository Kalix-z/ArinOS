#include "String.h"
#include "System.h"
#include "Types.h"
char* string;
int length = 0;
String::String(char* _string) {
    string = _string;
    char cur = string[0];
    while(cur != 0) {
    length++;
    cur = string[length];
    }
}
String::String(const char* _string) {
    string = (char*)_string;
    char cur = string[0];
    while(cur != 0) {
    length++;
    cur = string[length];
    }
}


char* String::Append(char* str1, char* str2) {
    int i, j;
    
    for(i=0; str1[i] != '\0'; i++) {}
    for(j=0; str2[j] != '\0'; i++,j++) {
        string[i] = str2[j];
    }
    str1[i]='\0';
    return str1;
}
char* String::getArray() {
    return string;
}


void String::Split(char character, String output[]) {
    String buffer = "";
    int times = 0;
    for(int i = 0; i < length; i++) {
        if(string[i] == character) {
            output[times] = buffer;
            times++;
        }
        else {
            buffer = "a";
        }
    }
}