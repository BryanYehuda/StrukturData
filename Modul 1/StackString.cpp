#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

// Node structure
struct StackNode {
    char data;
    StackNode *next;
};

/* Structure of Stack using List */
struct Stack
{
    StackNode *_top;
    unsigned _size;

    void init() 
    {
        _size = 0;
        _top = nullptr;
    }

    bool isEmpty() {
        return (_top == nullptr);
    }

    void push(char value)
    {
        StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
        if (newNode) {
            _size++;
            newNode->data = value;

            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _top;
            _top = newNode;
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            StackNode *temp = _top;
            _top = _top->next;
            free(temp);
            _size--;
        }
    }

    char top()
    {
        if (!isEmpty())
            return _top->data;
        exit(-1);
    }
};

int main(char argc, char const *argv[])
{
    // Buat objek stack
    Stack myStack;
    myStack.init();
    
    char tmp[100];
    int i; 
    gets(tmp);
    int n = strlen(tmp);
    for (i = n; i >= 0; i--)
        myStack.push(tmp[i]);
        
    // Cetak isi stack
    while (!myStack.isEmpty()) {
        printf("%c", myStack.top());
        myStack.pop();
    }
    return 0;
}
