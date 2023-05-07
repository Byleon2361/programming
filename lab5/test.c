#include <stdbool.h>
#include <stdio.h>
int scmp(char* str1, char* str2)
{
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2)
            break;
        str1++;
        str2++;
    }

    return (int)*str1 - (int)*str2;
}
char* sstr(char* str, char* underStr)
{
    while (*str != '\0') {
        if ((*str == *underStr) && (scmp(str, underStr) != 0)) {
            return str;
        }
        str++;
    }

    return NULL;
}
int main()
{
    if (sstr("asdf", "asd") != NULL)
        printf("INPUT\n");
    else
        printf("not INPUT\n");
    return 0;
}
