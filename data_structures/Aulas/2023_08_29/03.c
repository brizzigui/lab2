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
    comunismo = list_append(comunismo, 1);
    comunismo = list_append(comunismo, 1);
    comunismo = list_append(comunismo, 1);
    list_print(comunismo);

    List* socialismo = list_create(socialismo);
    socialismo = list_append(socialismo, 2);
    socialismo = list_append(socialismo, 2);
    socialismo = list_append(socialismo, 2);
    socialismo = list_append(socialismo, 2);
    socialismo = list_append(socialismo, 2);
    socialismo = list_append(socialismo, 2);


    list_print(socialismo);

    List* capitalismo = list_intercalate(comunismo, socialismo);
    list_print(capitalismo);
}
