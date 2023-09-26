#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define TAM 10

struct fila
{
    int info[TAM];
    int init;
    int n;
};

typedef struct fila Fila;

Fila* create()
{
    Fila* f = (Fila *)malloc(sizeof(Fila));
    f->n = 0;
    f->init = 0;
}

void insert(Fila* f, int v)
{
    if (f->n == TAM)
    {
        printf("Fila cheia\n");
        return;
    }
    
    f->info[(f->init + f->n)%TAM] = v;
    f->n++;
}

int remove_fila(Fila* f)
{
    if (f->n == 0)
    {
        printf("Fila vazia\n");
        return -1;
    }
    
    int aux = f->info[f->init];
    f->n--;
    f->init = (f->init + 1) % TAM;

    return aux;
}


Fila* joga_pro_fim(Fila* f, int v)
{

    //essa solução é um pouco mais complicada do que necessitaria
    //mas foi realizada dessa maneira para usar as funções prontas de fila

    Fila* aux = create();
    
    int size = f->n;
    int occurances = 0;

    for (int i = 0; i < size; i++)
    {
        int number = remove_fila(f);

        if (number != v)
        {
            insert(aux, number);
        }

        else
        {
            occurances++;
        }
    }

    for (int i = 0; i < occurances; i++)
    {
        insert(aux, v);
    }

    return aux;
    
}

void print(Fila* f)
{
    printf("Fila, do inicio ao fim: \n");
    for (int i = f->init; i < f->init + f->n; i++)
    {
        printf(" %d ", f->info[i%TAM]);
    }
    printf("\n");
}

void main()
{
    Fila* f = create();
    insert(f, 1);
    insert(f, 2);
    insert(f, 3);
    insert(f, 1);
    insert(f, 2);
    insert(f, 2);
    insert(f, 2);

    print(f);

    f = joga_pro_fim(f, 1);

    print(f);
}
