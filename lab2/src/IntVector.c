#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"
IntVector *int_vector_new(size_t initial_capacity) //Создает массив нулевого размера
{
    IntVector *vec =  malloc(sizeof(IntVector));
    if(vec == NULL )
    {
        free(vec);
        return NULL;
    }   
    vec->capacity = initial_capacity;
    vec->data = malloc(vec->capacity * sizeof(size_t));
    if(vec->data == NULL )
    {
        free(vec->data);
        return NULL;
    }
    vec->size = 0;
    return vec;
}
IntVector *int_vector_copy(const IntVector *v)//Указатель на копию вектора
{
    IntVector *vec =  malloc(sizeof(IntVector));
    if(vec == NULL)
    {
        free(vec);
        return NULL;
    }
    vec->data = malloc(v->capacity * sizeof(int)); 
    if(vec->data == NULL )
    {
        free(vec->data);
        return NULL;
    }
    memcpy(vec->data, v->data, sizeof(int) * v->capacity);
    vec->capacity = v->capacity;
    vec->size = v->size;
    return vec;
}
void int_vector_free(IntVector *v)//Освобождает память, выделенную для вектора
{
    free(v->data);
    free(v);
}
int int_vector_get_item(const IntVector *v, size_t index)//возвращает элемент под номером index
{
        return v->data[index];
}
void int_vector_set_item(IntVector *v, size_t index, int item) // Присваивает элементу под номером index значение item
{
    if(index <= v->capacity)
        v->data[index] = item;
}
size_t int_vector_get_size(const IntVector *v)// размер вектора.
{
    return v->size;
}
size_t int_vector_get_capacity(const IntVector *v)// емкость вектора
{
    return v->capacity;
}
int int_vector_push_back(IntVector *v, int item)//Добавляет элемент в конец массива
{
    v->size++;
    if(v->size >= v->capacity)
    {
        v->capacity *= 2;
        v->data = realloc(v->data,sizeof(int) * v->capacity);
        if(v->data == NULL )
        {
           free(v);
           return -1;
        }
    }
    v->data[v->size - 1] = item;
    return 0;
}
void int_vector_pop_back(IntVector *v)//Удаляет последний элемент из массива
{
    if(v->size == 0)
        return;

    v->size--;

}
int int_vector_shrink_to_fit(IntVector *v)//Уменьшает емкость массива до его размера.
{
    if(v->size > v->capacity)
    {
        return -1;
    }
    v->capacity = v->size;
    v->data = realloc(v->data,sizeof(int) * v->capacity);
    if(v->data == NULL )
    {
        free(v);
       return -1;
    }
    return 0;
}
int int_vector_resize(IntVector *v, size_t new_size)//Изменить размер массива.
{
    if(new_size > v->size)
    {
        if(new_size >= v->capacity) 
        {
            v->capacity = new_size;
        }
        else
        {
            return -1;
        }
        int tempSize = v->size;
        v->size =new_size;
        v->data = realloc(v->data,sizeof(int) * v->capacity);
        if(v->data == NULL )
        {
           free(v);
           return -1;
        }
        for(int i = tempSize ; i < new_size;i++)
        {
            v->data[i] = 0;
        }
    }
    else
    {
        int_vector_shrink_to_fit(v);
    }
    return 0;
}
int int_vector_reserve(IntVector *v, size_t new_capacity)//Изменить емкость массива.
{
    if(new_capacity <= v->capacity)
    {
        return -1;
    }
    v->capacity = new_capacity;
    v->data = realloc(v->data,sizeof(int) * v->capacity);
    if(v->data == NULL )
    {
        return -1;
    }
    return 0;
}