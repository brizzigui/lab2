#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "mesa.h"
#include "pilha.h"

Stack* stack_create()
{
    Stack* new = (Stack *)malloc(sizeof(Stack));
    new->first = NULL;
    return new;
}

void stack_push(Stack* s)
{
    List* new = (List *)malloc(sizeof(List));
    new->info = 1;
    new->next = s->first;
    s->first = new;    
}

int stack_pop(Stack* s)
{
    if (s->first == NULL)
    {
        return -1;
    }
    
    int v = s->first->info;
    List* aux = s->first;
    s->first = s->first->next;
    free(aux);

    return v;    
}

int count_plates(Stack* s){
    List* aux = s->first;
    int count = 0;
    while(aux != NULL){
        count++;
        aux = aux->next;
    }
    return count;
}

void print_plates(Stack* s){
    int count = count_plates(s);
    for (int i = 0; i < count; i++)
    {
        if(i % 4 == 0){
            printf("\n");
        }
        printf("    \\___/  ");
    }
    printf("\nHa %d pratos na pilha. \n\n", count);
}

void refill_plates(Stack* s, Table* table_chart, int m, int n){
    if(is_any_table_messed(table_chart, m, n) == false){
        printf("Nao ha pratos para repor. \n");
        return;
    }

    int index;

    print_tables(table_chart, m, n);

    printf("Deseja recolher os pratos de qual mesa? \n");
    scanf("%d", &index);
    index--;
    if(table_chart[index].available == true && table_chart[index].dirty_dishes == true){
        for (int i = 0; i < table_chart[index].people; i++)
        {
            stack_push(s);
        }
        printf("Pratos repostos. \n\n");
        table_chart[index].dirty_dishes = false;
    }
    else{
        printf("Essa mesa nao tem pratos para serem repostos; \n\n");
    }
}

