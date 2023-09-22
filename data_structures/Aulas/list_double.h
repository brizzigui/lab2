#ifndef LIST_DOUBLE_H
#define LIST_DOUBLE_H

struct lista2
{
    int info;
    struct lista2* ant;
    struct lista2* prox;
};

typedef struct lista2 Lista2;

void list_print(Lista2* l);

Lista2* list_create();

Lista2* list_insert(Lista2* l, int v);

#endif