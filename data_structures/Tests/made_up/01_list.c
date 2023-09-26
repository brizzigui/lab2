#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct list
{
    int info;
    struct list *prox;
};

typedef struct list List;

struct pilha
{
    List* top;
};

typedef struct pilha Pilha;

Pilha* create()
{
    Pilha* p = (Pilha *)malloc(sizeof(Pilha));
    p->top = NULL;
}

void push(Pilha* p, int v)
{
    List* new = (List *)malloc(sizeof(List));

    new->info = v;
    new->prox = p->top;
    p->top = new;
}

int pop(Pilha* p)
{
    if (p->top == NULL)
    {
        printf("Pilha vazia\n");
        return -1;
    }

    int v = p->top->info;
    List* aux = p->top;
    p->top = p->top->prox;
    free(aux);

    return v;
}

bool compara(Pilha* p1, Pilha* p2)
{
    if (p1->top == NULL || p2->top == NULL)
    {
        printf("Nao ha elementos.\n");
        return false;
    }
    
    int aux1 = pop(p1);
    int aux2 = pop(p2);

    push(p1, aux1);
    push(p2, aux2);

    if (aux1 == aux2)
    {
        return true;
    }
    
    return false;
}

void print(Pilha* p)
{
    List* ptr = p->top;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->info);
        ptr = ptr->prox;
    }
    printf("\n");
}

void main()
{
    Pilha* p1 = create();
    Pilha* p2 = create();

    push(p1, 10);
    push(p2, 10);

    push(p1, 20);
    push(p2, 10);

    push(p1, 30);
    push(p2, 30);
    
    print(p1);
    print(p2);
    printf("O elemento no topo coincide: %d\n", (int)compara(p1, p2));

    pop(p1);
    pop(p2);

    print(p1);
    print(p2);
    printf("O elemento no topo coincide: %d\n", (int)compara(p1, p2));
}
