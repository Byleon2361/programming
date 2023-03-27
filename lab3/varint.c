#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#define MAX 100
/*size_t - 8 байт
 * Диапазон             Вероятность
 * -------------------- -----------
 * [0; 128)             90%
 * [128; 16384)         5%
 * [16384; 2097152)     4%
 * [2097152; 268435455) 1%
 */
uint32_t generate_number()
{
    const int r = rand();
    const int p = r % 100;
    if (p < 90)
    {
        return r % 128;
    }
    if (p < 95)
    {
        return r % 16384;
    }
    if (p < 99)
    {
        return r % 2097152;
    }
    return r % 268435455;
}
size_t encode_varint(uint32_t value, uint8_t *buf)
{
    assert(buf != NULL);
    uint8_t *cur = buf;
    while (value >= 0x80)
    {
        const uint8_t byte = (value & 0x7f) | 0x80;
        *cur = byte;
        value >>= 7;
        ++cur;
    }
    *cur = value;
    ++cur;
    return cur - buf;
}
uint32_t decode_varint(const uint8_t **bufp)
{
    const uint8_t *cur = *bufp;
    uint8_t byte = *cur++;
    uint32_t value = byte & 0x7f;
    size_t shift = 7;
    while (byte >= 0x80)
    {
        byte = *cur++;
        value += (byte & 0x7f) << shift;
        shift += 7;
    }
    *bufp = cur;
    return value;
}
void printArr(uint32_t *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf(" %ld ", arr[i]);
    }
    printf("\n-------------------------------------");
}
int main()
{
    uint32_t values[MAX] = {};
    size_t size = 0;
    uint8_t buf[4] = {};
    uint8_t compressed[MAX] = {};
    uint8_t *cur = compressed;
    for (int i = 0; i < MAX; i++) // заполняет массив
    {
        values[i] = generate_number();
    }

    for (int i = 0; i < MAX; i++)
    {
        size = encode_varint(values[i], buf);
        for (int j = 0; j < size; j++)
        {
            *cur = buf[j];
            cur++;
        }
    }
    FILE *f;

    f = fopen("uncompressed.dat", "wb"); // записывает из массив в uncompressed файл
    fwrite(values, sizeof(values[0]), sizeof(values) / sizeof(values[0]), f);
    fclose(f);

    f = fopen("compressed.dat", "wb"); // записывает из массив в compressed файл
    fwrite(compressed, sizeof(compressed[0]), sizeof(compressed) / sizeof(compressed[0]), f);
    fclose(f);


    /*uint32_t newValues[MAX] = {};
    uint8_t newCompressed[MAX] = {};

    f = fopen("uncompressed.dat", "rb"); // читает из массив в uncompressed файл
    if (f != NULL)
    {
        for (int i = 0; !feof(f); i++)
        {
            fread(&newValues[i], sizeof(uint32_t), 1, f);
        }
    }
    fclose(f);

    f = fopen("compressed.dat", "rb"); // читает из массив в compressed файл
    if (f != NULL)
    {
        for (int i = 0; !feof(f); i++)
        {
            fread(&newCompressed[i], sizeof(uint32_t), 1, f);
        }
    }
    fclose(f);*/

    // printArr(newValues, MAX);
    // printArr(newCompressed, MAX);
    return 0;
}