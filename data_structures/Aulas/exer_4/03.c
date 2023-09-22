#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "../list.h"

void main(){
    List* muitos_dinheiros;

    muitos_dinheiros = list_create(muitos_dinheiros);

    muitos_dinheiros = list_insert(muitos_dinheiros, 2);
    muitos_dinheiros = list_append(muitos_dinheiros, 3);

    list_print(muitos_dinheiros);

    printf("Average = %f\n", list_average(muitos_dinheiros));

}
