#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Node structure
struct SListNode 
{
    char data;
    SListNode *next;
}; 

/* Structure of Singly Linked List */
struct SinglyList
{
    SListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

    void pushFront(char value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            
            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _head;
            _head = newNode;
        }
    }

    void pushBack(char value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (isEmpty()) 
                _head = newNode;
            else {
                SListNode *temp = _head;
                while (temp->next != NULL) 
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }

    void popFront()
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            _head = _head->next;
            free(temp);
            _size--;
        }
    }

    void popBack()
    {
        if (!isEmpty()) {
            SListNode *nextNode = _head->next;
            SListNode *currNode = _head;

            if (currNode->next == NULL) {
                free(currNode);
                _head = NULL;
                return;
            }

            while (nextNode->next != NULL) {
                currNode = nextNode;
                nextNode = nextNode->next;
            }
            currNode->next = NULL;
            free(nextNode);
            _size--;
        }
    }

    void insertAt(char index, char value)
    {
        if (isEmpty() || index >= _size) {
            pushBack(value);
            return;
        }
        else if (index == 0) {
            pushFront(value);
            return;
        }

        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            SListNode *temp = _head;
            char _i = 0;
            
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            _size++;
        }
    }

    void removeAt(char index)
    {
        if (!isEmpty()) {
            
            /* Kasus apabila posisinya melebihi batas */
            if (index >= _size) {
                popBack();
                return;    
            }
            else if (index == 0 || index < 0) {
                popFront();
                return;
            }

            SListNode *temp = _head;
            char _i = 0;
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            SListNode *nextinto = temp->next->next;
            free(temp->next);
            temp->next = nextinto;
            _size--;
        }
    }

    void remove(char value)
    {
        if (!isEmpty()) {
            SListNode *temp, *prev;
            temp = _head;

            if (temp->data == value) {
                popFront();
                return;
            }
            while (temp != NULL && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) return;
            prev->next = temp->next;
            free(temp);
            _size--;
        }
    }

    char front() {
        if (!isEmpty()) return _head->data;
        else exit(-1);
    }

    char back() 
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            while (temp->next != NULL)
                temp = temp->next;
            return temp->data;
        }
        else exit(-1);
    }

    char getAt(char index) {
        if (!isEmpty()) {
            SListNode *temp = _head;
            char _i = 0;
            while (temp->next != NULL && _i < index) {
                temp = temp->next;
                _i++;
            }
            return temp->data;
        }
        else exit(-1);
    }
};

int main(char argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList myList;
    myList.init();
    
    myList.pushBack('c');
    myList.pushBack('a');
    myList.pushBack('p');
    myList.pushBack('e');
    myList.pushBack('k');
    // isi list => [c, a, p, e, k]
    // print isi list dari depan ke belakang
    for (char i = 0; i < myList._size; i++) {
        printf("%c ", myList.getAt(i));
    }
    printf("\n");

    myList.pushFront('h');
    myList.pushFront('u');
    myList.pushFront('q');
    myList.pushFront('a');
    // isi list => [a, q, u, h, c, a, p, e, k]
    // print isi list dari depan ke belakang
    for (char i = 0; i < myList._size; i++) {
        printf("%c ", myList.getAt(i));
    }
    printf("\n");
    
    myList.popFront();
    myList.popBack();
    myList.insertAt(2, 'k');
    myList.insertAt(4, 'H');
    // isi list => [q, u, k, h, H, c, a, p, e]
    // print isi list dari depan ke belakang
    for (char i = 0; i < myList._size; i++) {
        printf("%c ", myList.getAt(i));
    }
    printf("\n");

    myList.removeAt(1);
    myList.remove(3);
    // isi list => [q, k, h, H, c, a, p, e]
    // print isi list dari depan ke belakang
    for (char i = 0; i < myList._size; i++) {
        printf("%c ", myList.getAt(i));
    }
    printf("\n");

    // print list reversed
    while (!myList.isEmpty()) {
        printf("%c ", myList.back());
        myList.popBack();
    }
    return 0;
}
