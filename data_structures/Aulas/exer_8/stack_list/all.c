#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct list
{
    float info;
    struct list* prox;
};

typedef struct list List;

struct stack
{
    List *top;
};

typedef struct stack Stack;

Stack* stack_create()
{
    Stack* new = (Stack *)malloc(sizeof(Stack));
    new->top = NULL;
    return new;
}

void push(Stack* s, float v)
{
    List* new = (List*)malloc(sizeof(List));
    new->prox = s->top;
    new->info = v;

    s->top = new;
}

float pop(Stack* s)
{
    if (s->top == NULL)
    {
        printf("Pilha vazia\n");
        return -1;
    }

    float v = s->top->info;
    List* aux = s->top;
    s->top = s->top->prox;
    free(aux);

    return v;
}

void stack_print(Stack* s)
{
    List* ptr = s->top;
    printf("Do topo a base: ");

    while (ptr != NULL)
    {
        printf(" %f ", ptr->info);
        ptr = ptr->prox;
    }
    
    printf("\n");
}

int stack_len(Stack* s)
{
    List* ptr = s->top;
    int size = 0;

    while (ptr != NULL)
    {
        size++;
        ptr = ptr->prox;
    }

    return size;
}

float stack_top(Stack* s)
{
    if (stack_len(s) > 0)
    {
        return s->top->info;
    }

    else
    {
        printf("Pilha vazia.\n");
        return -1;
    }
    
}

void stack_empty(Stack* s)
{
    List* ptr = s->top;
    while (ptr != NULL)
    {
        List* aux = ptr->prox;
        free(ptr);
        ptr = ptr->prox;
    }

    s->top = NULL;
    
}

bool is_palindrome(Stack* s)
{
    Stack* rev = stack_create();
    Stack* aux = stack_create();

    int size = stack_len(s);

    for (int i = 0; i < size; i++)
    {
        float v = pop(s);
        push(aux, v);
        push(rev, v);
    }

    for (int i = 0; i < size; i++)
    {
        push(s, pop(aux));
    }

    for (int i = 0; i < size; i++)
    {
        if (s->top->info != rev->top->info)
        {
            return false;
        }
        
    }

    return true;
}

void transfer_stack(Stack* target, Stack* origin)
{
    Stack* aux = stack_create();

    int size = stack_len(origin);

    for (int i = 0; i < size; i++)
    {
        push(aux, pop(origin));
    }

    for (int i = 0; i < size; i++)
    {
        push(target, pop(aux));
    }
}

void main()
{
    Stack* pilha = stack_create(); 
    push(pilha, 4);
    push(pilha, 3);
    pop(pilha);
    push(pilha, 8);
    pop(pilha);

    stack_print(pilha);

    pilha = stack_create(); 
    printf("Mais testes:\n");
    printf("Teste 1: ");
    push(pilha, 3);
    pop(pilha);
    pop(pilha);
    push(pilha, 4);
    stack_print(pilha);

    pilha = stack_create(); 
    printf("Teste 2: ");
    push(pilha, 1);
    pop(pilha);
    push(pilha, 2);
    push(pilha, 3);
    push(pilha, 4);
    push(pilha, 5);
    push(pilha, 6);
    push(pilha, 7);
    push(pilha, 8);
    stack_print(pilha);

    printf("O tamanho da pilha foi de: %d\n", stack_len(pilha));
    printf("No topo, esta o elemento: %f\n", stack_top(pilha));

    printf("Esvaziando a pilha!\n");
    printf("O tamanho da pilha foi de: %d\n", stack_len(pilha));
    printf("Tentando imprimir: ");
    stack_print(pilha);


    pilha = stack_create(); 
    printf("Teste palindromo #1: ");
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 1);
    printf("%d\n", (int)is_palindrome(pilha));


    pilha = stack_create(); 
    printf("Teste palindromo #2: ");
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 2);
    push(pilha, 2);
    printf("%d\n", (int)is_palindrome(pilha));

    printf("Concatenating stacks!\n");
    Stack *s1 = stack_create();
    Stack *s2 = stack_create();

    push(s1, 1);
    push(s1, 4.5);
    push(s1, 2.1);

    printf("Stack 1: ");
    stack_print(s1);

    push(s2, 9.8);
    push(s2, 3.1);
    push(s2, 7.2);

    printf("Stack 2: ");
    stack_print(s2);

    printf("Resulting stack: ");
    transfer_stack(s1, s2);
    stack_print(s1);
}
