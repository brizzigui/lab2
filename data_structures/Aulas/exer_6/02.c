#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "../list_double.h"

Lista2* list_remove_value_previous_to(Lista2* l, int v)
{
    Lista2* ptr = l;
    while (ptr != NULL)
    {
        if (ptr->info == v)
        {
            if (ptr->ant != NULL)
            {
                if (ptr->ant->ant != NULL)
                {
                    ptr->ant->ant->prox = ptr;
                }

                else if(ptr->ant->ant == NULL)
                {
                    l = l->prox;
                    l->ant = NULL;
                }
            }

        }

        ptr = ptr->prox;
        
    }

    return l;

}

void main()
{
    printf("Insira a qual elemento voce quer remover os valores anteriores: ");
    int v;
    scanf("%d", &v);

    Lista2* neoliberais = list_create();
    neoliberais = list_insert(neoliberais, 1);
    neoliberais = list_insert(neoliberais, 2);
    neoliberais = list_insert(neoliberais, 3);

    list_print(neoliberais);
    neoliberais = list_remove_value_previous_to(neoliberais, 2);
    list_print(neoliberais);

}
