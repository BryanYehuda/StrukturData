#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Node Structure
struct DListNode {
    char data;
    DListNode *next, *prev;
};

struct Deque
{
    DListNode *_head, *_tail;
    unsigned _size;

    // Utility function
    DListNode* __createNode(char value)
    {
        DListNode *newNode = \
            (DListNode*) malloc (sizeof(DListNode));
    
        if (!newNode) return NULL;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        return (DListNode*) newNode;
    }

    void init() {
        _head = _tail = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL && _tail == NULL);
    }

    void pushFront(char value)
    {
        DListNode *newNode = __createNode(value);
        if (newNode) {
            _size++;
            if (isEmpty()) {
                _head = newNode;
                _tail = newNode;
                return;
            }

            newNode->next = _head;
            _head->prev = newNode;
            _head = newNode;
        }
    }

    void pushBack(char value)
    {
        DListNode *newNode = __createNode(value);
        if (newNode) {
            _size++;
            if (isEmpty()) {
                _head = newNode;
                _tail = newNode;
                return;
            }

            _tail->next = newNode;
            newNode->prev = _tail;
            _tail = newNode;
        }
    }

    char front()
    {
        if (!isEmpty())
            return _head->data;
        exit(-1);
    }

    char back()
    {
        if (!isEmpty())
            return _tail->data;
        exit(-1);
    }

    void popFront()
    {
        if (!isEmpty()) {
            DListNode *temp = _head;
            if (_head == _tail) {
                _head = NULL;
                _tail = NULL;
                free(temp);
            }
            else {
                _head = _head->next;
                _head->prev = NULL;
                free(temp);
            }
            _size--;   
        }
    }

    void popBack()
    {
        if (!isEmpty()) {
            DListNode *temp;
            if (_head == _tail) {
                temp = _head;
                _head = NULL;
                _tail = NULL;
                free(temp);
            }
            else {
                temp = _tail;
                _tail = _tail->prev;
                _tail->next = NULL;
                free(temp);
            }
            _size--;
        }
    }
};

int main(char argc, char const *argv[])
{
    
    return 0;
}
