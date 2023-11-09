#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Lista* list_create()
{
    return NULL;
}

Lista* list_insert(Lista* l, int info, int i, int j)
{
    Lista* new = (Lista *)malloc(sizeof(Lista));
    new->prox = l;

    new->info = info;
    new->i = i;
    new->j = j;

    return new;
}

int list_find_id_matrix_value(Lista* l, int i, int j)
{
    Lista* ptr = l;

    while (ptr != NULL)
    {
        if (ptr->i == i && ptr->j == j)
        {
            return ptr->info;
        }
        
        ptr = ptr->prox;
    }
    
    // cai aqui se não encontrar
    if (i == j)
    {
        return 1;
    }
    
    return 0;
}

void list_print_violating_id_matrix_values(Lista* l)
{
    printf("Listagem de elementos que violam a matriz identidade: \n");
    Lista* ptr = l;

    while (ptr != NULL)
    {
        printf("%d em (%d, %d)\n", ptr->info, ptr->i, ptr->j);
        
        ptr = ptr->prox;
    }
}
