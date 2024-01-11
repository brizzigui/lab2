#ifndef LISTA_H
#define LISTA_H

struct list
{
    int info;
    int password;
    struct list *next;
};

typedef struct list List;

List* list_create();
List* list_insert(List* l, int v);


#endif