#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

List* list_insert(List* l, int info)
{
    List* new = (List*) malloc(sizeof(List));
    new->info = info;
    new->prox = l;
    return new;
}

int list_len(List* l)
{
    int size = 0;
    List* ptr = l;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->prox;
    }
    
    return size;
}

List* list_concatenate(List* l1, List* l2)
{
    List* ptr = l1;

    while (true)
    {
        if (ptr->prox == NULL)
        {
            ptr->prox = l2;
            break;
        }
        
        ptr = ptr->prox;
    }

    return l1;
}

int list_larger(List* l, int n)
{
    int bigger = 0;
    List* ptr = l;
    while (ptr != NULL)
    {
        if (ptr->info > n)
        {
            bigger++;
        }
        ptr = ptr->prox;
    }

    return bigger;
}

List* list_last(List* l)
{
    List* ptr = l;
    while (true)
    {
        if (ptr->prox == NULL)
        {
            return ptr;
        }

        ptr = ptr->prox;
    }
}

List* list_create()
{
    return NULL;
}

void list_print(List* l)
{
    List* ptr = l;
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