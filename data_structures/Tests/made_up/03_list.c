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

int len(Pilha* p)
{
    List* ptr = p->top;
    int count = 0;
    
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->prox;
    }

    return count;
    
}

void topo_para_base(Pilha* pA, Pilha* pB)
{
    int size_A = len(pA);
    Pilha* aux = create();

    for (int i = 0; i < size_A; i++)
    {
        push(aux, pop(pA));
    }

    int v = pop(pB);
    push(pB, v);
    push(pA, v);

    for (int i = 0; i < size_A; i++)
    {
        push(pA, pop(aux));
    }
    
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

    topo_para_base(p1, p2);
    
    print(p1);
    print(p2);
}
