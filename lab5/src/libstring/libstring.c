#include <stdio.h>

#include <libstring/libstring.h>

int slen(char* string)
{
    int count = 0;
    while (string[count] != '\0')
        count++;

    return count;
}
int stok(char* src, char symbol, char** strs)
{
    int i = 0;
    int numstrs = 0;
    while (src[i] != '\0') {
        if (src[i] == symbol) {
            src[i] = '\0';
            numstrs++;
            strs[numstrs] = &(src[i + 1]);
        }
        i++;
    }
    strs[0] = src;
    numstrs++;
    return numstrs;
}
int sspn(char* str, char* sym)
{
    int count = 0;
    for (int i = 0; i < slen(sym); i++) {
        for (int j = 0; j < slen(str); j++) {
            if (sym[i] == str[j])
                count++;
        }
    }

    return count;
}
int scmp(char* str1, char* str2)
{
    while (*str1 != NULL) {
        if (*str1 != *str2)
            break;
        str1++;
        str2++;
    }

    return (int)*str1 - (int)*str2;
}
char* scpy(char* toHere, char* fromHere)
{
    for (int i = 0; i < slen(fromHere) + 1; i++) {
        toHere[i] = fromHere[i];
    }

    return toHere;
}

char* sFindAndReplace(char* str, char sym, char newSym)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == sym) {
            str[i] = newSym;
        }
        i++;
    }
    return str;
}
char* sDeleteSym(char* str, char sym)
{
    char temp[100];
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == sym) {
            i++;
            continue;
        }

        temp[j] = str[i];
        j++;
        i++;
    }
    temp[j] = '\0';
    scpy(str, temp);
    return str;
}
char toLowerChar(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;

    return ch + 32;
}
char* scat(char* first, char* second)
{
    while (*first != '\0') {
        first++;
    }
    while (*second != '\0') {
        *first = *second;
        first++;
        second++;
    }
    *first = '\0';

    return first;
}