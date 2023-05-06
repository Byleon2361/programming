#include <stdio.h>

#include <libstring/fromWindowsToLinuxPath.h>
#include <libstring/libstring.h>

#define MAX_PATH 260
char** input(char** paths, int* num)
{
    char delim;
    char string[100];
    puts("Введите разделитель\n");
    scanf("%c", &delim);
    puts("Введите пути\n");
    scanf("%s", string);
    *num = stok(string, delim, paths);
    return paths;
}
int checkNameFile(char** paths, int count)
{
    for (int i = 0; i < count; i++) {
        if (slen(paths[i]) > MAX_PATH + 1) //+1 - символ конца строки
            return 1;
    }
    return 0;
}