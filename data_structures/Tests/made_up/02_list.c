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

struct fila
{
    List* init;
    List* fim;
};

typedef struct fila Fila;

int len(Fila* f)
{
    List* ptr = f->init;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->prox;
    }
    
    return count;
}

Fila* create()
{
    Fila* f = (Fila *)malloc(sizeof(Fila));
    f->init = NULL;
    f->fim = NULL;
}

void insert(Fila* f, int v)
{
    List* new = (List *)malloc(sizeof(List));
    new->info = v;

    new->prox = NULL;

    if (f->fim == NULL)
    {
        f->init = new;
        f->fim = new;
        return;
    }

    else
    {
        f->fim->prox = new;
        f->fim = new;
    }
    
}

int remove_fila(Fila* f)
{
    if (f->init == NULL)
    {
        printf("Fila vazia\n");
        return -1;
    }
    
    List* aux = f->init;
    int v = f->init->info;
    f->init = f->init->prox;
    
    free(aux);

    return v;
}

Fila* joga_pro_fim(Fila* f, int v)
{

    //essa solução é um pouco mais complicada do que necessitaria
    //mas foi realizada dessa maneira para usar as funções prontas de fila

    Fila* aux = create();
    
    int size = len(f);
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
    List* ptr = f->init;

    printf("Fila, do inicio ao fim:\n");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->info);
        ptr = ptr->prox;
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
