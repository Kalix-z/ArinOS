#pragma once
class String {
    public:
    int length;
    String(char* _string);
    String(const char* _string);
    static char* Append(char* str1, char* str2);
    char* getArray();
    void Split(char character, String array[]);

};