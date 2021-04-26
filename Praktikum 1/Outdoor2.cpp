#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <stdio.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main()
{
    Stack Bis;
    stack_init(&Bis);
    int n, i;
    int angka[1000];

    scanf("%d", &n); 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &angka[i]);
    }

    int x;
    scanf("%d", &x);
    int a = 1;
    int check = 1;
    for (i = 0; i < n; i++)
    {
        while (!stack_isEmpty(&Bis) && stack_top(&Bis) == a)
        {
            a++;
            stack_pop(&Bis);
        }

        if (angka[i] == a)
        {
            a++;
        }
        else if (!stack_isEmpty(&Bis) && angka[i] > stack_top(&Bis))
        {
            check = 0;
            break;
        }
        else
        {
            stack_push(&Bis, angka[i]);
        }        
    }
    if (check == 1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return(0);
}
