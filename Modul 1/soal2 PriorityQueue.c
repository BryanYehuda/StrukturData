#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//Struktur Node
typedef struct pqueueNode_t
{
    int data;
    int id;
    struct pqueueNode_t *next;
} PQueueNode;

//Struktur PriorityQueue menggunakan Linked List
// Prioritas default: nilai minimum
typedef struct pqueue_t
{
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

//Function definition
void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue)
{
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value, int id)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode =
        (PQueueNode *)malloc(sizeof(PQueueNode));
    newNode->data = value;
    newNode->id = id;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue))
    {
        pqueue->_top = newNode;
        return;
    }

    if (value > pqueue->_top->data)
    {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else
    {
        while (temp->next != NULL &&
               temp->next->data > value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
    {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->id;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;
    pqueue_init(&myPque);
    
    int n, id, priority, i;
    char argumenin[30];
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)

    {
        scanf("%s", &argumenin);

        if (strncmp(argumenin, "MASUK", 5) == 0)
        {
            scanf("%d", &id);
            scanf("%d", &priority);
            pqueue_push(&myPque, priority, id);
        }
        else if (strncmp(argumenin, "LAYANI", 6) == 0)
        {

            if (!pqueue_isEmpty(&myPque))
            {
                printf("%d \n", pqueue_top(&myPque));
                pqueue_pop(&myPque);
            }
            else
            {
                printf("HORE");
            }
        }
    }
    return 0;
}
