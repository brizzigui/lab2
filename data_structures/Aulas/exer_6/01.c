#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "../list_double.h"
    
void main()
{
    Lista2* neoliberais = list_create();
    neoliberais = list_insert(neoliberais, 10);
    neoliberais = list_insert(neoliberais, 10);
    neoliberais = list_insert(neoliberais, 12);

    list_print(neoliberais);
}

