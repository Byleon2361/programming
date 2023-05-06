#pragma once
int slen(char* string);
int stok(char* src, char symbol, char** strs);
// Считает количество символов, перечисленых в sym, в строке str
int sspn(char* str, char* sym);
int scmp(char* str1, char* str2);
char* scpy(char* toHere, char* fromHere);
char* sFindAndReplace(char* str, char sym, char newSym);
char* sDeleteSym(char* str, char sym);
char toLowerChar(char ch);
char* scat(char* first, char* second);