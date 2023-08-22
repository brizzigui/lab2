#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

void main()
{
    List* hit_list_kgb = list_create();

    int temp;

    while (true)
    {
        printf("Type a number to add to the first list. Type -1 to stop and go to the next list: ");
        scanf("%d", &temp);
        if (temp == -1)
        {
            break;
        }
        hit_list_kgb = list_insert(hit_list_kgb, temp);
    }
    
    List* hit_list_cia = list_create();
    
    while (true)
    {
        printf("Type a number to add to the second list. Type -1 to stop and go to the next list: ");
        scanf("%d", &temp);
        if (temp == -1)
        {
            break;
        }
        
        hit_list_cia = list_insert(hit_list_cia, temp);
    }
    
    

    printf("The lenght of the first list is %d; and of the second list is %d.\n", list_len(hit_list_kgb), list_len(hit_list_cia));
    printf("Printing elements in both lists!\n");
    list_print(hit_list_kgb);
    list_print(hit_list_cia);

    

    hit_list_kgb = list_concatenate(hit_list_kgb, hit_list_cia);
    printf("Lists have been concatenated. Printing!\n");

    list_print(hit_list_kgb);
    printf("Lenght of concatenatds list: %d\n", list_len(hit_list_kgb));

    List* last = list_last(hit_list_kgb);
    printf("The last element is %d.\n", last->info);

    printf("Type a number to search how many items are larger than it: ");
    int item;
    scanf("%d", &item);

    printf("%d items surpass entered amount.\n", list_larger(hit_list_kgb, item));

}
