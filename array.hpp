#ifndef __ARRAY___
#define __ARRAY___

struct Array
{
    int* data;
    int size;
};

Array array_create(int init_size);

void array_free(Array* a);

int array_size(const Array* a);

int* array_at(Array* a, int index);

void array_inflate(Array* a, int more_size);

#endif // __ARRAY___