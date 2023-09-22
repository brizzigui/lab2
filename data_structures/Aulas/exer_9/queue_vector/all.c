#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 15

struct fila {
    int n;
    int ini;
    float vet[SIZE];
};

typedef struct fila Fila;

Fila* queue_create()
{
    Fila* new = (Fila *)malloc(sizeof(Fila));
    new->ini = 0;
    new->n = 0;
    return new;
}

void queue_insert(Fila* f, float v)
{
    if (f->n == SIZE)
    {
        printf("Capacidade maxima atingida.\n");
        return;
    }
    
    f->vet[(f->ini+f->n) % SIZE] = v;
    f->n++;
}

float queue_remove(Fila* f)
{
    if (f->n <= 0)
    {
        printf("Fila vazia.\n");
    }
    
    float v = f->vet[(f->ini)];
    f->ini = (f->ini + 1)%SIZE;
    f->n--;

    return v;
}

void queue_print(Fila* f)
{
    printf("Fila do inicio ao fim: ");
    for (int i = f->ini; i < f->ini+f->n; i++)
    {
        printf(" %f ", f->vet[i % SIZE]);
    }

    printf("\n");
    
}

void queue_intercalate(Fila* target, Fila* origin_1, Fila* origin_2)
{
    while (origin_1->n > 0 || origin_2->n > 0)
    {
        if (origin_1->n > 0)
        {
            queue_insert(target, queue_remove(origin_1));
        }

        if (origin_2->n > 0)
        {
            queue_insert(target, queue_remove(origin_2));
        }
    }
}

void join_sorted(Fila* target, Fila* origin_1, Fila* origin_2)
{
    while (origin_1->n > 0 || origin_2->n > 0)
    {
        if (origin_1->n > 0 && origin_1->vet[origin_1->ini] <= origin_2->vet[origin_2->ini])
        {
            queue_insert(target, queue_remove(origin_1));
        }

        if (origin_2->n > 0 && origin_2->vet[origin_2->ini] <= origin_1->vet[origin_1->ini])
        {
            queue_insert(target, queue_remove(origin_2));
        }
    }
}

void main()
{
    Fila* fila = queue_create();
    printf("Testes iniciais: \n");
    queue_insert(fila, 1);
    queue_insert(fila, 2);
    queue_insert(fila, 3);
    queue_insert(fila, 2);
    queue_remove(fila);
    queue_print(fila);

    printf("Intercalando filas!\n");
    Fila* f_res = queue_create();
    Fila* f_1 = queue_create();
    Fila* f_2 = queue_create();
    
    queue_insert(f_1, 2.1);
    queue_insert(f_1, 4.5);
    queue_insert(f_1, 1);

    queue_insert(f_2, 7.2);
    queue_insert(f_2, 3.1);
    queue_insert(f_2, 9.8);

    queue_intercalate(f_res, f_1, f_2);
    queue_print(f_res);

    printf("Juntando ordenadamente!\n");
    f_res = queue_create();
    f_1 = queue_create();
    f_2 = queue_create();

    queue_insert(f_1, 2);
    queue_insert(f_1, 4);
    queue_insert(f_1, 9);

    queue_insert(f_2, 1);
    queue_insert(f_2, 3);
    queue_insert(f_2, 5);

    join_sorted(f_res, f_1, f_2);
    queue_print(f_res);
}
