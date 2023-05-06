#include <stdio.h>
char toLowerChar(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;

    return ch + 32;
}
int main()
{
    printf("%c", toLowerChar('A'));

    // char str[] = "C:\\Windows\\system32";
    // str[0] = toLowerChar(str[0]);
    // printf("%c\n", str[0]);
    // printf("%s\n", str);

    return 0;
}
