#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct snode_t
{
    int data;
    struct snode_t *next;

} snode;

typedef struct slist_t
{
    unsigned _size;
    snode *_head;
} List;

bool slist_isEmpty(List *list)
{
    return (list->_head == NULL);
}

void slist_pushBack(List *list, int value)
{
    snode *newNode = (snode *)malloc(sizeof(snode));
    if (newNode)
    {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else
        {
            snode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void printElement(int *elem)
{
    cout << *elem << " ";
}

void multiply2(int *elem)
{
    *elem *= 2;
}

void reverseEach(int *elem)
{
	int rev = 0, remainder;	
    while (*elem != 0) 
	{
        remainder = *elem % 10;
        rev = rev * 10 + remainder;
        *elem /= 10;
    }
    *elem = rev;
}

void dlist_init(List *dlist)
{
    dlist->_head = NULL;
    dlist->_size = 0;
}

void forEachElement(List *dlist, void (*f)(int *))
{
    snode *tmp = dlist->_head;

    while (tmp != NULL)
    {
        (*f)(&tmp->data);

        tmp = tmp->next;
    }
}

int main()
{
    List myList;
    dlist_init(&myList);

    slist_pushBack(&myList, 1);
    slist_pushBack(&myList, 2);
    slist_pushBack(&myList, 3);
    slist_pushBack(&myList, 4);
    slist_pushBack(&myList, 6);

    // contoh fungsi forEachElement untuk mencetak data pada list
    forEachElement(&myList, printElement);
    cout << endl;

    // contoh fungsi forEachElement untuk mengalikan setiap elemen
    // dengan 2
    forEachElement(&myList, multiply2);
    forEachElement(&myList, printElement);
    cout << endl;
    
    // contoh fungsi reverseEach untuk membalik integer
    forEachElement(&myList, reverseEach);
    forEachElement(&myList, printElement);
    
    return 0;
}
