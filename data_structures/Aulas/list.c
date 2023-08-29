#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

// use to compile: "gcc file.c ../list.c -o file.exe"

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
    if (l == NULL)
    {
        return NULL;
    }
    
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

List* list_flip_values(List* l)
{
    List* ptr = l;

    while(ptr != NULL)
    {
        ptr->info = ptr->info * -1;
        ptr = ptr->prox;
    }

    return l;
}

List* list_append(List* l, int i)
{
    List* ptr = list_last(l);
    if (ptr == NULL)
    {
        ptr = list_insert(NULL, i);
        return ptr;
    }
    
    ptr->prox = list_insert(NULL, i);
    return l;
}

float list_average(List* l)
{
    int sum = 0, count = 0;
    List* ptr = l;
    while (ptr != NULL)
    {
        sum += ptr->info;
        count++;

        ptr = ptr->prox;
    }

    return (float)sum/count;
    
}

List* list_remove_value(List* l, int v)
{
    List* ptr = l;
    List* ant = NULL;

    while (ptr != NULL && ptr->info != v)
    {
        ant = ptr;
        ptr = ptr->prox;
    }

    if (ant == NULL)
    {
        l = ptr->prox;
        free(ptr);
    }

    else if (ptr != NULL)
    {
        ant->prox = ptr->prox;
        free(ptr);
    }
    
    return l;

}

List* list_remove_all_values(List* l, int v)
{
    int len_previous;
    do
    {
        len_previous = list_len(l);
        l = list_remove_value(l, v);

    } while (len_previous != list_len(l));
    
    return l;
}

int list_find_value_index(List* l, int v)
{
    List* ptr = l;
    int count = 0;

    while (ptr != NULL)
    {
        if (ptr->info == v)
        {
            return count;
        }

        ptr = ptr->prox;
        count++;
    }

    return -1;
}

int list_content(List* l, int pos)
{
    List* ptr = l;
    int count = 0;
    int content = ptr->info;

    while (count < pos){
        ptr = ptr->prox;
        count++;
        content = ptr->info;
    }

    return content;
}

void list_modify(List* l, int pos, int content)
{
    List* ptr = l;
    int count = 0;

    while (count < pos){
        ptr = ptr->prox;
        count++;
        ptr->info = content;
    }
}

List* list_remove_position(List* l, int pos)
{
    List* ptr = l;
    List* ant = NULL;
    int count = 0;

    if (pos == 0)
    {
        l = l->prox;
        return l;
    }

    while (count < pos)
    {
        ant = ptr;
        ptr = ptr->prox;
        count++;
    }

    ant->prox = ptr->prox;
    return l;
    
}

List* list_split_by_value(List* l, int v)
{
    List* ptr = l;
    while (ptr != NULL)
    {
        if (ptr->info == v)
        {
            List* l2_start = ptr->prox;
            ptr->prox = NULL;
            return l2_start;
            
        }
        ptr = ptr->prox;
    }
    
    return l;
}

List* list_intercalate(List* l1, List* l2)
{
    List* intercalated = list_create();
    int idx_l1 = 0, idx_l2 = 0;

    for (int i = 0; i < list_len(l1) + list_len(l2); i++)
    {
        if (idx_l1 < list_len(l1))
        {
            intercalated = list_append(intercalated, list_content(l1, idx_l1));
            idx_l1++;
        }

        if (idx_l2 < list_len(l2))
        {
            intercalated = list_append(intercalated, list_content(l2, idx_l2));
            idx_l2++;
        }
    }
    
    return intercalated;
}

void list_invert(List* l)
{
    List* aux = list_create();
    for (int i = 0; i < list_len(l); i++)
    {
        aux = list_insert(aux, list_content(l, i));
    }
    
    return aux
}