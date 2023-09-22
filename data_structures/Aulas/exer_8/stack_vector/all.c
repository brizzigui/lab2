#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// implementação com vetor
#define N 10

struct stack
{
    int n;
    float vet[N];
};
typedef struct stack Stack;

Stack* stack_create()
{
    Stack* s = (Stack *)malloc(sizeof(Stack));
    s->n = 0;

    return s;
}

void push(Stack* s, float v)
{
    if (s->n == N)
    {
        printf("Pilha cheia.\n");
    }
    
    s->vet[s->n] = v;
    s->n++;
}

float pop(Stack* s)
{
    if (s->n == 0)
    {
        printf("Pilha vazia.\n");
        return -1;
    }
    
    s->n--;
    return s->vet[s->n];
}

void stack_print(Stack* s)
{
    for (int i = 0; i < s->n; i++)
    {
        printf("%f  ", s->vet[i]);
    }
    printf("\n");
}

int stack_len(Stack* s)
{
    return s->n;
}

float stack_top(Stack* s)
{
    if (stack_len(s) > 0)
    {
        return s->vet[s->n-1];
    }
    
    printf("Pilha vazia\n");
    return -1;
}

void stack_empty(Stack* s)
{
    s->n = 0;
}

bool is_palindrome(Stack* s)
{
    Stack* rev = stack_create();
    Stack* aux = stack_create();

    int size = s->n;

    for (int i = 0; i < size; i++)
    {
        float v = pop(s);
        push(rev, v);
        push(aux, v);
    }

    for (int i = 0; i < size; i++)
    {
        push(s, pop(aux));
    }
    
    for (int i = 0; i < size; i++)
    {
        if (s->vet[i] != rev->vet[i])
        {
            return false;
        }
        
    }

    return true;
}

void transfer_stack(Stack* target, Stack* origin)
{
    Stack* aux = stack_create();

    int size = origin->n;

    for (int i = 0; i < size; i++)
    {
        push(aux, pop(origin));
    }

    for (int i = 0; i < size; i++)
    {
        push(target, pop(aux));
    }
}

void main(){
    Stack *pilha = stack_create();
    push(pilha, 4);
    stack_print(pilha);

    push(pilha, 3);
    stack_print(pilha);

    pop(pilha);
    stack_print(pilha);

    push(pilha, 8);
    stack_print(pilha);

    pop(pilha);
    stack_print(pilha);


    pilha = stack_create();

    push(pilha, 3);
    pop(pilha);
    pop(pilha);
    push(pilha, 4);
    stack_print(pilha);

    pilha = stack_create();

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

    pop(pilha);
    stack_print(pilha);

    pilha = stack_create();
    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 2);
    push(pilha, 1);

    printf("Palindrome check #1: ");
    printf("%d\n", (int)is_palindrome(pilha));
    stack_print(pilha);



    pilha = stack_create();
    push(pilha, 1);
    push(pilha, 3);
    push(pilha, 2);
    push(pilha, 1);

    printf("Palindrome check #2: ");
    printf("%d\n", (int)is_palindrome(pilha));
    stack_print(pilha);


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
