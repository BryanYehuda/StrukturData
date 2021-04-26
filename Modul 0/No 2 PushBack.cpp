#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct
{
    int *_arr;
    unsigned _size, _capacity;

    void init()
    {
        _arr = (int *)malloc(sizeof(int) * 2);
        _size = 0u;
        _capacity = 2u;
    }

    void pushBack(int value)
    {
        if (_size + 1 > _capacity)
        {
            unsigned int it;
            _capacity *= 2;
            int *newArr = (int *)malloc(sizeof(int) * _capacity);

            for (it = 0; it < _size; ++it)
                newArr[it] = _arr[it];

            int *oldArray = _arr;
            _arr = newArr;
            free(oldArray);
        }
        _arr[_size++] = value;
    }

    bool isEmpty()
    {
        return _size == 0;
    }

    int getAt(unsigned index)
    {
        if (!isEmpty())
        {
            if (index >= _size)
                return _arr[_size - 1];
            else
                return _arr[index];
        }
        else
            exit(-1);
    }

} DynamicArray, Dynamic;

bool dArray_isEmpty(DynamicArray *darray)
{
    return (darray->_size == 0);
}

void dArray_insertAt(DynamicArray *darray, unsigned index, int value)
{
    if (darray->_size + 1 > darray->_capacity)
    {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int *)malloc(sizeof(int) * darray->_capacity);

        for (it = 0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];

        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    unsigned it, tmp, x;
    darray->_size++;
    x = darray->_arr[index];
    for (it = index; it < darray->_size; it++)
    {

        tmp = darray->_arr[it + 1];
        darray->_arr[it + 1] = x;
        x = tmp;
    }
    darray->_arr[index] = value;
}

void dArray_removeAt(Dynamic *darray, unsigned index)
{
    if (!dArray_isEmpty(darray))
    {
        unsigned tmp, x, it;
        darray->_size--;
        for (it = index; it < darray->_size; it++)
        {
            darray->_arr[it] = darray->_arr[it + 1];
        }
    }
}

void printAll(DynamicArray darray)
{
    for (int i = 0; i < darray._size; ++i)
    {
        printf("%d ", darray.getAt(i));
    }
    printf("\n");
}

int main()
{
    DynamicArray DArray;
    DArray.init();
    DArray.pushBack(1);
    DArray.pushBack(2);
    DArray.pushBack(3);
    DArray.pushBack(4);
    DArray.pushBack(5);
    printAll(DArray);
    //memasukkan angka 8 di posisi ke 4
    dArray_insertAt(&DArray, 4, 8);
    printAll(DArray);
    //menghilangkan angka di posisi 3
    dArray_removeAt(&DArray, 3);
    printAll(DArray);
    return 0;
}

