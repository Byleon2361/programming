#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "IntVector.h"
void printVector(IntVector *vector)
{
    puts("Array:\n");
    for(int i = 0; i < vector->size; i++)
    {
        printf("%d, ",vector->data[i]);
    }
    puts("\n--------------------------------------------");
    printf("Size: %d",vector->size);
    puts("\n--------------------------------------------");
    printf("Capacity: %d\n\n",vector->capacity);  
}
int main()
{
    IntVector *vector1 = int_vector_new(10);
    
    IntVector *vector2 =  malloc(sizeof(IntVector));
    vector2->size = 4;
    vector2->capacity = 10;
    vector2->data = malloc(vector2->capacity * sizeof(int));
    vector2->data[0] = 1;
    vector2->data[1] = 2;
    vector2->data[2] = 3;
    vector2->data[3] = 4;
    
    puts("          int_vector_new\n");
    puts("\n Первый вектор, созданный с помощью int_vector_new \n");
    printVector(vector1);
    puts("Второй вектор\n");
    printVector(vector2);
    
    puts("          int_vector_copy\n");
    puts("\nКопируем Второй вектор в Первый\n");
    vector1 = int_vector_copy(vector2);
    puts("Первый вектор\n");
    printVector(vector1);
    puts("Второй вектор\n");
    printVector(vector2);

    puts("          int_vector_free. Очистим второй вектор.\n"); 
    int_vector_free(vector2);
    printVector(vector1);

    puts("          int_vector_get_item.\n");
    printf("Index %d: %d\n",3,int_vector_get_item(vector1, 3));

    puts("          int_vector_set_item. Заменим второй индекс на значение 1\n");
    int_vector_set_item(vector1, 2, 1);
    printVector(vector1);

    puts("          int_vector_get_size\n");
    printf("Size: %ld\n",int_vector_get_size(vector1));

    puts("          int_vector_get_capacity\n");
    printf("Capacity: %ld\n",int_vector_get_capacity(vector1));

    puts("          int_vector_push_back. Добавим в конец значение 2\n"); 
    int_vector_push_back(vector1, 2);
    printVector(vector1);

    puts("          int_vector_pop_back. Удалим посдеднюю двойку\n"); 
    int_vector_pop_back(vector1);
    printVector(vector1);

    puts("          int_vector_shrink_to_fit. Уменьшает емкость массива до его размера\n"); 
    int_vector_shrink_to_fit(vector1);
    printVector(vector1);

    puts("          int_vector_resize. Изменим размер массива на 11\n"); 
    int_vector_resize(vector1, 11);
    printVector(vector1);

    puts("          int_vector_reserve. Изменим емкость массива на 20\n"); 
    int_vector_reserve(vector1,20);
    printVector(vector1);
    

    return 0;
}