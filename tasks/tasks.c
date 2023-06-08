#include <stdio.h>
void countOddEven()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};
    int size = 10;
    int odd = 0;
    int even = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            even += arr[i];
        else
            odd += arr[i];
    }
    printf("Odd: %d\n", odd);
    printf("Even: %d\n", even);
}
int slen(char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
char *scpy(char *resStr, char *str)
{
    for (int i = 0; i < slen(str); i++)
    {
        resStr[i] = str[i];
    }
    return resStr;
}
char *scat(char *first, char *second) // Возвращает '\0' -> можно просто сделать void
{
    if (first == NULL)
    {
        scpy(first, second);
        return first;
    }

    while (*first != '\0')
        first++;

    while (*second != '\0')
    {

        *first = *second;
        first++;
        second++;
    }
    *first = '\0';
    return first;
}
char *toUpperString(char *str)
{
    char l = 'a' - 'A';
    for (int i = 0; i < slen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= l;
        }
    }
    return str;
}
char *toLowerString(char *str)
{
    int l = 'a' - 'A';
    for (int i = 0; i < slen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += l;
        }
    }
    return str;
}
int isEqualWithRegister(char *str1, char *str2)
{
    while (*str1 != '\0')
    {
        if (*str1 != *str2)
            return 0;
        str1++;
        str2++;
    }
    if (*str2 != '\0')
        return 0;

    return 1;
}
char toLowerChar(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch + 32;

    return ch;
}
char toUpperChar(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch - 32;

    return ch;
}
int isEqualWithoutRegister(char *str1, char *str2)
{
    while (*str1 != '\0')
    {
        if (toLowerChar(*str1) != toLowerChar(*str2))
            return 0;
        str1++;
        str2++;
    }
    if (*str2 != '\0')
        return 0;

    return 1;
}
int scmp(char *str1, char *str2) //!
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            break;
        str1++;
        str2++;
    }
    return (int)*str1 - (int)*str2;
}
int sspn(char *str, char *underStr)
{
    int res = 0;
    for (int i = 0; i < slen(str); i++)
    {
        for (int j = 0; j < slen(underStr); j++)
        {
            if (str[i] == underStr[j])
                res++;
        }
    }
    return res;
}
char *fromCamelToSnake(char *str) // fromCamelToSnake -> from_camel_to_snake
{
    char res[100];
    char *pRes = res;
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *pRes = '_';
            pRes++;
        }
        *pRes = toLowerChar(*str);
        pRes++;
        str++;
    }
    *pRes = '\0';
    scpy(str, res);
    return str;
}
char *fromSnakeToCamel(char *str) // from_camel_to_snake -> fromCamelToSnake
{
    char res[100];
    char *pRes = res;
    while (*str != '\0')
    {
        if (*str == '_')
        {
            *pRes = toUpperChar(*(str + 1));
            pRes++;
            str += 2;
            continue;
        }
        *pRes = *str;
        pRes++;
        str++;
    }
    *pRes = '\0';
    scpy(str, res);
    return str;
}
int stok(char *str, char ch, char **strArr) //!
{
    int size = 1;
    strArr[0] = &(*(str));
    while (*str != '\0')
    {
        if (*str == ch)
        {
            *str = '\0';
            strArr[size] = str + 1;
            size++;
        }
        str++;
    }
    return size;
}
void sRepair(char *str, char ch, char strArr[][100], int size) //!
{
    for (int i = 0; i < size; i++)
    {

        scat(str, strArr[i]);
        if (i != size - 1)
            scat(str, "+");
    }
}
int myPow(int base, int number)
{
    for (int i = 0; i < number; i++)
    {
        base *= base;
    }
    return base;
}
int toInt(char *str)
{
    int res = 0;
    while (*str >= '0' && *str <= '9')
    {
        res *= 10;
        res += *str - '0';
        str++;
    }
    return res;
}
int sizeNum(int number)
{
    int size = 0;
    while (number % 10 != 0)
    {
        size++;
        number /= 10;
    }
    return size;
}
char *toStr(int number, char str[])
{
    int size = sizeNum(number);
    for (int i = 0; i < size; i++)
    {
        str[size - i - 1] = (number % 10) + '0';
        number /= 10;
    }
    str[size + 1] = '\0';
    return str;
}
double toDouble(char *str) // atof
{
    double res = 0.0;
    while (*str >= '0' && *str <= '9' && *str != '.')
    {
        res *= 10;
        res += *str - '0';
        str++;
    }
    str++;
    int mantis = 0;
    while (*str >= '0' && *str <= '9')
    {
        res *= 10;
        res += *str - '0';
        str++;
        mantis++;
    }
    for (int i = 0; i < mantis; i++)
    {
        res *= 0.1;
    }

    return res;
}
char *sstr(char *str, char *underStr)
{
    int i = 0;
    while (*str != '\0')
    {
        if (*str == underStr[i])
        {
            i++;
        }
        else
        {
            i = 0;
        }
        if (i == slen(underStr))
        {
            return underStr;
        }
        str++;
    }
    return NULL;
}
char *delUnderStr(char *str, char *underStr)
{
    int i = 0;
    char *first = NULL;
    for (int j = 0; str[j] != '\0'; j++)
    {
        if (str[j] == underStr[i])
        {
            i++;
            if (first == NULL)
                first = &str[j];
        }
        else
        {
            i = 0;
        }
        if (i == slen(underStr))
        {
            *first = '\0';
            first = &(str[j + 1]);
        }
    }
    scat(str, first);
    return str;
}
char *addUnderStr(char *str, char *underStr, int index)
{
    char res[100];
    char *strPtr = str;
    int size = slen(str) + slen(underStr) + 1;
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            while (*underStr != '\0')
            {
                res[i] = *underStr;
                underStr++;
                i++;
            }
        }
        res[i] = *strPtr;
        strPtr++;
    }
    scpy(str, res);
    return str;
}
char *prefWithSym(char *str, char *underStr)
{
    int a = 0;
    while (*str != '\0')
    {
        for (int i = 0; i < slen(underStr); i++)
        {
            if (*str == underStr[i])
            {
                a = 1;
            }
        }

        if (a != 1)
        {
            *str = '\0';
            return str;
        }
        str++;
        a = 0;
    }
    return NULL;
}
char *prefWithoutSym(char *str, char *underStr)
{
    while (*str != '\0')
    {
        for (int i = 0; i < slen(underStr); i++)
        {
            if (*str == underStr[i])
            {
                *str = '\0';
                return str;
            }
        }
        str++;
    }
    return NULL;
}
int main()
{
    return 0;
}