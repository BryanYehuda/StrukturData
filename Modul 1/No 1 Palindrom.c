#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//Struktur Node
char tmp[100];
int res = 0;
typedef struct stackNode_t
{
    char data;
    struct stackNode_t *next;
} StackNode;

//Struktur Stack
typedef struct stack_t
{
    StackNode *_top;
    unsigned _size;
} Stack;

//Function prototype
void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_pop(Stack *stack);
unsigned stack_size(Stack *stack);

//Function definition
void stack_init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack)
{
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode)
    {
        stack->_size++;

        newNode->data = value;
        if (stack_isEmpty(stack))
            newNode->next = NULL;
        else
            newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack)
{
    if (!stack_isEmpty(stack))
    {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

char stack_top(Stack *stack)
{
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack)
{
    return stack->_size;
}

void func(Stack *stack, int len)
{
    if (!stack_isEmpty(stack))
    {
        if ((stack_top(stack) == tmp[len]))
        {
            stack_pop(stack);
            func(stack, ++len);
        }
        else
        {
            res++;
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;
    stack_init(&myStack);
    
    int n;
    gets(tmp);
    n = strlen(tmp) / 2;

	int i;
    for (i = 0; i < n; i++)
        stack_push(&myStack, tmp[i]);
    if (strlen(tmp) % 2 == 0)
        func(&myStack, n);
    else
        func(&myStack, n + 1);

    if (res > 0)
    {
        printf("bukan palindrom");
    }
    else
    {
        printf("palindrom");
    }
    return 0;
}
