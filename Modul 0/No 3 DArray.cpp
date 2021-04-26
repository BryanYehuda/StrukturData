#include <stdlib.h>
#include <iostream>
using namespace std;

struct DynamicArray
{
    char *_arr;
    unsigned char _size, _capacity;

    void init() {
        _arr = (char*) malloc(sizeof(char) * 2);
        _size = 0u;
        _capacity = 2u;
    }

    bool isEmpty() {
        return _size == 0;
    }

    void pushBack(char value)
    {
        if (_size + 1 > _capacity) {
            unsigned char it;
            _capacity *= 2;
            char *newArr = (char*) malloc(sizeof(char) * _capacity);
            
            for (it = 0; it < _size; ++it)
                newArr[it] = _arr[it];
            
            char *oldArray = _arr;
            _arr = newArr;
            free(oldArray);
        }
        _arr[_size++] = value;
    }

    void setAt(unsigned index, char value) {
        if (!isEmpty()) {
            if (index >= _size) _arr[_size-1] = value;
            else _arr[index] = value;
        }
        else exit(-1);
    }

    void popBack() {
        if (!isEmpty()) _size--;
        else exit(-1);
    }

    char back() {
        if (!isEmpty()) return _arr[_size - 1];
        else exit(-1);
    }

    char front() {
        if (!isEmpty()) return _arr[0];
        else exit(-1);
    }

    char getAt(unsigned index) {
        if (!isEmpty()) {
            if (index >= _size) return _arr[_size - 1];
            else return _arr[index];
        }
        else exit(-1);
    }
};

void printAll(DynamicArray darray)
{
    for (char i = 0; i < darray._size; ++i) {
        printf("%c ", darray.getAt(i));
    }
    printf("\n");
}

int main(char argc, char const *argv[])
{
    // Buat objek DynamicArray
    DynamicArray myArray;
    myArray.init();

    myArray.pushBack('s');
    myArray.pushBack('u');
    myArray.pushBack('s');
    myArray.pushBack('a');
    myArray.pushBack('h');
    printAll(myArray);
    // Isi array => [s, u, s, a, h]

    myArray.popBack();
    printAll(myArray);
    // Isi array => [s, u, s, a]
    return 0;   
}
