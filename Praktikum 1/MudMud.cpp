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
void pindah(Stack *awal,Stack *akhir);
void print(Stack *adik,Stack *kakak);

int main(int argc, char const *argv[])
{
    Stack mudmud;
    Stack kakak;

    stack_init(&mudmud);
 	stack_init(&kakak);
 
 	int n,t,a,b;
 	scanf("%d",&n);
 	int nn=n;
 	bool tumpukan_salah=false;
 
 	while(n)
 	{
  		stack_push(&mudmud,n);
  		n--;
 	}
 	scanf("%d",&t);
 	while(t)
 	{
  		scanf("%d %d",&a,&b);
  		if(a==1)
  		{
   			while(b)
   			{
    			pindah(&mudmud, &kakak);
    			b--;
   			}
  		}
  		else if(a==2)
  		{
   			while(b)
   			{
    			pindah(&kakak, &mudmud);
    			b--;
   			}
  		}
  		else if(a!=1 && a!=2)
  		{		
   			tumpukan_salah=true;
  		}
  		t--;
 	}
 	if(tumpukan_salah)
 	{
  		printf("TumpukAnnya saLah! :(\n");
 	}
 	else if(nn<=0 && !tumpukan_salah)
 	{
  		printf("MudMud SangaT MaraH!\n");
	}
 	else
  	print(&mudmud,&kakak);
    return 0;
}

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
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        newNode->data = value;
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

void pindah(Stack *awal,Stack *akhir) 
{
 int move;
 if(!stack_isEmpty(awal))
 {
  move = awal->_top->data;
  stack_push(akhir,move);
     stack_pop(awal);
 }
}

void print(Stack *adik,Stack *kakak)
{
 	int sizeadik = stack_size(adik);
 	int sizekakak = stack_size(kakak);
 
 	while (!stack_isEmpty(adik) || !stack_isEmpty(kakak)) 
	 {
  		if (stack_isEmpty(adik) && sizeadik >= 0){
   		printf("-\t");
   		sizeadik = -1;
  	}
  	else if (!stack_isEmpty(adik)) 
	{
   		if(stack_top(adik) == 0)
    	continue;
   		else
		{
    		printf("%d ", stack_top(adik));
       		stack_pop(adik);
   		}
  	}
  	else if(stack_isEmpty(adik) && sizeadik == -1)
	{
   		printf(" ");
  	}
  	if (stack_isEmpty(kakak) && sizekakak >= 0)
	{
   		printf(":(");
   		sizekakak = -1;
  	}
  	else if (!stack_isEmpty(kakak)) 
	{
   		printf("%d", stack_top(kakak));
        stack_pop(kakak);
  	}
  	printf("\n");
 	}
}
