#ifndef LIST_H
#define LIST_H

struct list
{
    int info;
    struct list* prox;
};

typedef struct list List;

List* list_insert(List* l, int info);

int list_len(List* l);

List* list_concatenate(List* l1, List* l2);

int list_larger(List* l, int n);

List* list_last(List* l);

List* list_create();

void list_print();

#endif