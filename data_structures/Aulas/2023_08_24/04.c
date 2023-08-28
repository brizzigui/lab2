#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "../list.h"

List* remove_value_previous_to(List* l, int v)
{
    for (int i = 0; i < list_len(l); i++)
    {
        if (list_content(l, i) == v)
        {
            if (i > 0)
            {
                l = list_remove_position(l, i-1); 
            }
        }
    }

    return l;
}

void main(){
    List* muitos_dinheiros;
    muitos_dinheiros = list_create(muitos_dinheiros);
    muitos_dinheiros = list_append(muitos_dinheiros, 0);
    muitos_dinheiros = list_append(muitos_dinheiros, 2);
    muitos_dinheiros = list_append(muitos_dinheiros, 0);
    muitos_dinheiros = list_append(muitos_dinheiros, 2);
    muitos_dinheiros = list_append(muitos_dinheiros, 0);
    muitos_dinheiros = list_append(muitos_dinheiros, 2);
 
    list_print(muitos_dinheiros);
    muitos_dinheiros = remove_value_previous_to(muitos_dinheiros, 2);

    list_print(muitos_dinheiros);


}
