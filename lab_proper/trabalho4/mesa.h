#ifndef MESA_H
#define MESA_H

struct table
{
    bool available;
    bool set_up;
    bool dirty_dishes;
    int ticket;
    int people;
};

typedef struct table Table;

#include "pilha.h"
#include "fila.h"

Table* tables_create(int m, int n);
int find_free_table(Table* t, int m, int n);
bool is_any_table_free(Table* t, int m, int n);
void use_table(Table* t, int index, int people, Stack* s, int m, int n);
void print_tables(Table* t, int m, int n);
void end_meal(Table* table_chart, int m, int n);
void graphically_print_tables(Table* t, int m, int n);
bool is_any_table_messed(Table* t, int m, int n);
void tidy_table(Queue* clients_queue, Stack* s, Table* table_chart, int m, int n);
void print_amount_of_plates_per_table(Table* table_chart, int m, int n);
void search_table_status_by_index(Table* table_chart, int m, int n);

#endif