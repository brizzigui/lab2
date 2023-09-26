#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct lista
{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

bool is_prime(int n)
{
    if (n == 1)
    {   
        return false;
    }
    
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        } 
    }

    return true;
    
}

Lista* create()
{
    return NULL;
}

Lista* insert(Lista* l, int v)
{
    Lista* new = (Lista *)malloc(sizeof(Lista));
    new->info = v;
    new->prox = l;
    return new;
}

Lista* remove_primos(Lista* l)
{
    Lista* ptr = l;
    Lista* ant = NULL;

    while (ptr != NULL)
    {
        if (is_prime(ptr->info))
        {
            if (ant == NULL)
            {
                l = ptr->prox;
            }

            else
            {
                ant->prox = ptr->prox;
            }
            
            Lista* aux = ptr;
            ptr = ptr->prox;
            free(aux);
        }

        else
        {
            ant = ptr;
            ptr = ptr->prox;
        }
    }
    
    return l;
}

void print(Lista* l)
{
    Lista* ptr = l;

    while (ptr != NULL)
    {
        printf(" %d ", ptr->info);
        ptr = ptr->prox;
    }

    printf("\n");
    
}

void main()
{
    Lista* l = create();
    l = insert(l, 2);
    l = insert(l, 3);
    l = insert(l, 10);
    l = insert(l, 6);
    l = insert(l, 8);
    l = insert(l, 7);
    l = insert(l, 8);
    l = insert(l, 7);

    print(l);

    l = remove_primos(l);

    print(l);

}
