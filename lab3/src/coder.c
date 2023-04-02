#include "coder.h"
#include <stdint.h>
#include <stdio.h>
int encode(uint32_t code_point,
           CodeUnit *code_unit) // code_point - то, что нужно закодировать,
                                // code_unit - туда будет помещен результат
{
    if (code_point < 0x80)
    {
        code_unit->length = 1;
        code_unit->code[0] = code_point;
    }
    else if (code_point < 0x800)
    {
        code_unit->length = 2;
        code_unit->code[0] = 0xc0 | (code_point >> 6);
        code_unit->code[1] = 0x80 | (code_point & 0x3f);
    }
    else if (code_point < 0x10000)
    {
        code_unit->length = 3;
        code_unit->code[0] = 0xe0 | (code_point >> 12);
        code_unit->code[1] = 0x80 | ((code_point >> 6) & 0x3f);
        code_unit->code[2] = 0x80 | (code_point & 0x3f);
    }
    else if (code_point < 0x200000)
    {
        code_unit->length = 4;
        code_unit->code[0] = 0xf0 | (code_point >> 18);
        code_unit->code[1] = 0x80 | ((code_point >> 12) & 0x3f);
        code_unit->code[2] = 0x80 | ((code_point >> 6) & 0x3f);
        code_unit->code[3] = 0x80 | (code_point & 0x3f);
    }
    else
    {
        return -1;
    }
    return 0;
}
uint32_t decode(const CodeUnit *code_unit)
{
    if (code_unit->length == 1)
    {
        return code_unit->code[0];
    }
    else if (code_unit->length == 2)
    {
        code_unit->code[0] = 0xc0 | (code_point >> 6);
        code_unit->code[1] = 0x80 | (code_point & 0x3f);
    }
    else if (code_unit->length == 3)
    {
        code_unit->code[0] = 0xe0 | (code_point >> 12);
        code_unit->code[1] = 0x80 | ((code_point >> 6) & 0x3f);
        code_unit->code[2] = 0x80 | (code_point & 0x3f);
    }
    else if (code_unit->length == 4)
    {
        code_unit->code[0] = 0xf0 | (code_point >> 18);
        code_unit->code[1] = 0x80 | ((code_point >> 12) & 0x3f);
        code_unit->code[2] = 0x80 | ((code_point >> 6) & 0x3f);
        code_unit->code[3] = 0x80 | (code_point & 0x3f);
    }
    else
    {
        return -1;
    }
}
int read_next_code_unit(FILE *in, CodeUnit *code_unit) {//Выключить все байты,кроме 4 первых, а дальше реализовать проверки if}
int write_code_unit(FILE *out, const CodeUnit *code_unit)
{
    int result = fwrite(code_unit->code, 1, code_unit->length, out);
    return result;
}