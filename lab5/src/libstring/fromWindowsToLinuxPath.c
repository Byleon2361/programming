#include <stdio.h>

#include <libstring/fromWindowsToLinuxPath.h>
#include <libstring/libstring.h>
int input(char* string, char* delim)
{
    if (string == NULL || delim == NULL)
        return -1;

    puts("Введите разделитель\n");
    scanf("%c", delim);
    puts("Введите пути\n");
    scanf("%s", string);
    return 0;
}
char* process(char* result, char** paths, int count)
{
    for (int i = 0; i < count; i++) {
        paths[i] = sFindAndReplace(paths[i], '\\', '/');

        if ((paths[i][0] >= (int)'A') && (paths[i][0] <= (int)'Z')) {
            paths[i][0] = toLowerChar(paths[i][0]);
            sDeleteSym(paths[i], ':');
            scat(result, "/cygdrive/");
        }
        scat(result, paths[i]);
        if (i != count - 1)
            scat(result, "+");
    }
    return result;
}
int output(char* res)
{
    if (res == NULL)
        return -1;

    printf("%s\n", res);
    return 0;
}

int checkNameFile(char* string, char delim)
{
    char* paths[MAX_NUMBER_PATH];
    char temp[MAX_INPUT_DATA];
    scpy(temp, string);

    int count = stok(temp, delim, paths);

    for (int j = 0; j < count; j++) {
        if (slen(paths[j]) > MAX_PATH + 1) //+1 - символ конца строки
            return 1;
    }
    return 0;
}
int checkPaths(char* string, char delim)
{
    char* paths[MAX_NUMBER_PATH];
    char temp[MAX_INPUT_DATA];
    scpy(temp, string);
    int count = stok(temp, delim, paths);

    for (int i = 0; i < count; i++) {
        if (sstr(paths[i], "/") == NULL)
            if (sstr(paths[i], "\\") == NULL)
                return 1;
    }
    return 0;
}
int checkSymbols(char* string, char delim)
{
    char* paths[MAX_NUMBER_PATH];
    char temp[MAX_INPUT_DATA];
    scpy(temp, string);

    int count = stok(temp, delim, paths);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < slen(paths[i]); j++) {
            if (paths[i][j] == '\"' || paths[i][j] == '<' || paths[i][j] == '>'
                || paths[i][j] == '?' || paths[i][j] == '*'
                || paths[i][j] == '|')
                return 1;
        }
    }
    return 0;
}