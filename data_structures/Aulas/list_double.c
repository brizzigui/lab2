#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "list_double.h"

Lista2* list_create()
{
    return NULL;
}

void list_print(Lista2* l)
{
    Lista2* ptr = l;
    printf("[");
    while (ptr != NULL)
    {
        printf("%d", ptr->info);
        ptr = ptr->prox;
        if (ptr != NULL)
        {
            printf(", ");
        }
    }
    printf("]\n");
    
}

Lista2* list_insert(Lista2* l, int v)
{
    Lista2* new = (Lista2*)malloc(sizeof(Lista2));
    new->prox = l;
    new->info = v;
    new->ant = NULL;

    if (l != NULL)
    {
        l->ant = new;
    }

    return new;
}

Lista2* list_append(Lista2* l, int v)
{
    Lista2* new = (Lista2*)malloc(sizeof(Lista2));
    new->prox = NULL;
    new->info = v;

    Lista2* ptr = l;
    if (ptr == NULL)
    {
        new->ant = NULL;
        return new;
    }

    while (ptr->prox != NULL)
    {
        ptr = ptr->prox;
    }

    ptr->prox = new;
    new->ant = ptr;

    return l;
}

// use to compile: "gcc file.c ../list_double.c -o file.exe"
// "library" of list functions for data structures class