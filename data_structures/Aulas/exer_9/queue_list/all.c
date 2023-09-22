#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct lista 
{
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

struct fila 
{
    Lista* ini;
    Lista* fim;
};
typedef struct fila Fila;

Fila* queue_create()
{
    Fila* new = (Fila*)malloc(sizeof(Fila));
    new->ini = NULL;
    new->fim = NULL;
    return new;
}

void queue_insert(Fila* f, float v)
{
    Lista* new = (Lista*)malloc(sizeof(Lista));
    new->info = v;
    new->prox = NULL;
    
    if (f->fim == NULL)
    {
        f->ini = new;
        f->fim = new;
    }

    else
    {
        f->fim->prox = new;
        f->fim = new;
    }
}

float queue_remove(Fila* f)
{
    if (f->ini == NULL)
    {
        printf("Fila vazia.\n");
        return -1;
    }

    float v = f->ini->info;

    Lista* aux = f->ini;
    f->ini = f->ini->prox;
    free(aux);

    return v;
}

void queue_print(Fila* f)
{
    Lista* ptr = f->ini;
    printf("Fila do inicio ao fim: ");
    while(ptr != NULL)
    {
        printf(" %f ", ptr->info);
        ptr = ptr->prox;
    }

    printf("\n");
}

int queue_len(Fila* f)
{
    Lista* ptr = f->ini;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->prox;
    }
    
    return count;
}

void queue_intercalate(Fila* target, Fila* origin_1, Fila* origin_2)
{
    while (queue_len(origin_1) > 0 || queue_len(origin_2) > 0)
    {
        if (queue_len(origin_1) > 0)
        {
            queue_insert(target, queue_remove(origin_1));
        }

        if (queue_len(origin_2) > 0)
        {
            queue_insert(target, queue_remove(origin_2));
        }
    }
}

void join_sorted(Fila* target, Fila* origin_1, Fila* origin_2)
{
    while (queue_len(origin_1) > 0 || queue_len(origin_2) > 0)
    {
        if (origin_1->ini != NULL)
        {
            if (origin_2->ini == NULL)
            {
                queue_insert(target, queue_remove(origin_1));
            }
            
            else if (origin_1->ini->info <= origin_2->ini->info)
            {
                queue_insert(target, queue_remove(origin_1));
            }
        }

        if (origin_2->ini != NULL)
        {
            if (origin_1->ini == NULL)
            {
                queue_insert(target, queue_remove(origin_1));
            }

            else if (origin_2->ini->info <= origin_1->ini->info)
            {
                queue_insert(target, queue_remove(origin_2));
            }
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
