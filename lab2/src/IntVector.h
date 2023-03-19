#ifndef INTVECTOR_H
#define INTVECTOR_H
typedef struct{
	int *data;
	int size;
    int capacity;
} IntVector;

IntVector *int_vector_new(size_t initial_capacity); //Создает массив нулевого размера
IntVector *int_vector_copy(const IntVector *v); //Указатель на копию вектора
void int_vector_free(IntVector *v); //Освобождает память, выделенную для вектора
int int_vector_get_item(const IntVector *v, size_t index); //возвращает элемент под номером index
void int_vector_set_item(IntVector *v, size_t index, int item); // Присваивает элементу под номером index значение item
size_t int_vector_get_size(const IntVector *v); // размер вектора.
size_t int_vector_get_capacity(const IntVector *v);// емкость вектора.
int int_vector_push_back(IntVector *v, int item);//Добавляет элемент в конец массива
void int_vector_pop_back(IntVector *v);//Удаляет последний элемент из массива
int int_vector_shrink_to_fit(IntVector *v);//Уменьшает емкость массива до его размера.
int int_vector_resize(IntVector *v, size_t new_size);//Изменить размер массива.
int int_vector_reserve(IntVector *v, size_t new_capacity);//Изменить емкость массива.
#endif