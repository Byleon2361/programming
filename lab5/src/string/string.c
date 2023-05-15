#include <libstring/fromWindowsToLinuxPath.h>
#include <libstring/libstring.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // input
    // C:\Windows\system32+E:\Distrib\msoffice.exe+/home/alex/prog/lab4.c
    int count = 0;
    char** paths = malloc(sizeof(char**) * MAX_NUMBER_PATH);
    char delim;
    char* string = malloc(sizeof(char*) * MAX_INPUT_DATA);
    char* result = malloc(sizeof(char*) * MAX_OUTPUT_DATA);

    input(string, &delim);
    if (checkPaths(string, delim) == 1) {
        printf("Введен не путь\n");
        free(paths);
        free(string);
        free(result);
        exit(1);
    }
    if (checkNameFile(string, delim) == 1) {
        printf("Полное имя файлов не должно превышмть 260 символов\n");
        free(paths);
        free(string);
        free(result);
        exit(1);
    }
    if (checkSymbols(string, delim) == 1) {
        printf("Неверный символ в полном имени файла\n");
        free(paths);
        free(string);
        free(result);
        exit(1);
    }
    count = stok(string, delim, paths);
    process(result, paths, count);
    output(result);

    free(paths);
    free(string);
    free(result);
    return 0;
}