#include <stdio.h>
#include <string.h>

#include "command.h"
#include "coder.h"
// TODO: При decode появилась лишняя пятерка
// Сделать проверки
//  Разобраться
//  Написать  отчет
//
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        puts("The number of arguments passed must be three");
        return 0;
    }
    const char *command = argv[1];
    const char *in_file_name = argv[2];
    const char *out_file_name = argv[3];

    if (strcmp(command, "encode") == 0)
    {

        if (encode_file(in_file_name, out_file_name) != 0)
        {
            printf("Не удалось откыть файлы");
        }
    }

    if (strcmp(command, "decode") == 0)
    {
        if (decode_file(in_file_name, out_file_name) != 0)
        {
            printf("Не удалось откыть файлы");
        }
    }
    return 0;
}