#include <stdlib.h>
#include <stdio.h>
using namespace std;

// Node Structure
struct QueueNode {
    char data;
    QueueNode *next;
};

/* Structure of Queue using List */
struct Queue
{
    QueueNode *_front, *_rear;
    unsigned _size;

    void init()
    {
        _size  = 0;
        _front = NULL;
        _rear  = NULL;
    }

    bool isEmpty() {
        return (_front == NULL && _rear == NULL);
    }

    void push(char value)
    {
        QueueNode *newNode =\
            (QueueNode*) malloc(sizeof(QueueNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (isEmpty())                 
                _front = _rear = newNode;
            else {
                _rear->next = newNode;
                _rear = newNode;
            }
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            QueueNode *temp = _front;
            _front = _front->next;
            free(temp);
            
            if (_front == NULL)
                _rear = NULL;
            _size--;
        }
    }

    char front()
    {
        if (!isEmpty())
            return _front->data;
        exit(-1);
    }

    unsigned size() {
        return _size;
    }
};

int main(char argc, char const *argv[])
{
    // Buat objek queue
    Queue myQueue;
    myQueue.init();

    myQueue.push('h');
    myQueue.push('a');
    myQueue.push('l');
    myQueue.push('o');

    // Cetak isi queue
    while (!myQueue.isEmpty()) {
        printf("%c ", myQueue.front());
        myQueue.pop();
    }
    return 0;
}
