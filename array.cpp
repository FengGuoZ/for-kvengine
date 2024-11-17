#include <stdlib.h>
#include <string.h>
#include "array.hpp"

Array array_create(int init_size)
{
    Array a;
    int byte_num = sizeof(int) * init_size;
    a.data = (int*)malloc(byte_num);
    memset(a.data, 0, byte_num);
    a.size = init_size;

    return a;
}

void array_free(Array* a)
{
    if (a->data)
    {
        free(a->data);
        a->data = nullptr;
        a->size = 0;
    }
}

int array_size(const Array* a)
{
    return a->size;
}

int* array_at(Array* a, int index)
{
    if (!a || a->size <= index) {
        return nullptr;
    }

    return &(a->data[index]);
}


void array_inflate(Array* a, int more_size)
{
    Array tmp = array_create(a->size + more_size);
    memcpy(tmp.data, a->data, a->size);
    
    array_free(a);

    *a = tmp;
}