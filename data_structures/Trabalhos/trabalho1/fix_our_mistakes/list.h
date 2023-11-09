#ifndef LIST_H
#define LIST_H

struct lista
{
    struct lista *prox;
    int info;
    int i;
    int j;
};

typedef struct lista Lista;

Lista* list_create();
Lista* list_insert(Lista* l, int info, int i, int j);
int list_find_id_matrix_value(Lista* l, int i, int j);
void list_print_violating_id_matrix_values(Lista* l);


#endif