#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "../list.h"

void main(){
    List* comunismo;
    comunismo = list_create(comunismo);
    comunismo = list_append(comunismo, 1);
    comunismo = list_append(comunismo, 2);
    comunismo = list_append(comunismo, 3);
    comunismo = list_append(comunismo, 4);
    list_print(comunismo);

    List* socialismo = list_split_by_value(comunismo, 2);
    list_print(comunismo);
    list_print(socialismo);

}
