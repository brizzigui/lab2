#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define TAM 10

struct pilha
{
    int info[TAM];
    int n;
};

typedef struct pilha Pilha;

Pilha* create()
{
    Pilha* p = (Pilha *)malloc(sizeof(Pilha));
    p->n = 0;

    return p;
}

void push(Pilha* p, int v)
{
    p->info[p->n] = v;
    p->n++;
}

int pop(Pilha* p)
{
    p->n--;
    return p->info[p->n];
}

bool compara(Pilha* p1, Pilha* p2)
{
    if (p1->n == 0 || p2->n == 0)
    {
        printf("Nao ha elementos\n");
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
    printf("Da base ao topo: ");

    for (int i = 0; i < p->n; i++)
    {
        printf(" %d ", p->info[i]);
    }

    printf("\n");
}

void main()
{
    Pilha* p1 = create();
    Pilha* p2 = create();


    push(p1, 10);
    push(p1, 20);
    push(p1, 30);
    push(p2, 10);
    push(p2, 10);
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
