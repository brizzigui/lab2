#ifndef FILA_H
#define FILA_H

#include "lista.h"

struct queue {
    List* start;
    List* end;
};

typedef struct queue Queue;

#include "mesa.h"

Queue* queue_create();
void queue_insert(Queue* f, int v);
void receive_clients(Queue* clients_queue, Table* table_chart, Stack* s, int m, int n);
void print_queue(Queue* clients_queue);
void give_up_waiting(Queue* clients_queue);
void call_next_in_queue(Queue* clients_queue, Table* table_chart, Stack* s, int m, int n);
void queue_remove_by_index(Queue* f, int index);

#endif