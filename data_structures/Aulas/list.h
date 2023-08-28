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

List* list_flip_values(List* l);

List* list_append(List* l, int i);

float list_average(List* l);

List* list_remove_value(List* l, int v);

int list_find_value_index(List* l, int v);

List* list_remove_all_values(List* l, int v);

List* list_remove_position(List* l, int pos);

int list_content(List* l, int pos);

#endif