#include <stdbool.h>
#include <stdio.h>
#include <string.h>
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
    for (int i = 0, k = 0; i < slen(str); i++) {
        if (str[i] == underStr[0]) {
            for (int j = 0; j < slen(underStr); j++)
                if (str[i + j] == underStr[j])
                    k++;
            if (k == slen(underStr))
                return &str[i];
        }
        k = 0;
    }
    return NULL;
}
int main()
{
    if (sstr("abcd", "bd") != NULL)
        printf("INPUT\n");
    else
        printf("not INPUT\n");
    return 0;
}
