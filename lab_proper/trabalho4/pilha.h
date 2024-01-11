#ifndef PILHA_H
#define PILHA_H

#include "lista.h"
#include "mesa.h" 

struct stack
{
    List* first;
};

typedef struct stack Stack;

Stack* stack_create();
int stack_pop(Stack* s);
void stack_push(Stack* s);

void print_plates(Stack* s);
int count_plates(Stack* s);
void refill_plates(Stack* s, Table* table_chart, int m, int n);

#endif