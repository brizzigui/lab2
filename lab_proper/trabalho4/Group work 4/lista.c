#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "lista.h"

List* list_create()
{
    return NULL;
}

List* list_insert(List* l, int v)
{
    List* new = (List *)malloc(sizeof(List));
    new->info = v;
    new->password = 0;
    new->next = l;

    return new;
}