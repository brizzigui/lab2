#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "fila.h"
#include "mesa.h"

Queue* queue_create()
{
    Queue* f = (Queue*) malloc(sizeof(Queue));
    f->start = NULL;
    f->end = NULL;
    return f;
}

int next_ticket_queue(Queue* f){
    List* new = (List *)malloc(sizeof(List));
    new = f->start;
    int ticket = 0;
    while(new != NULL){
        if(new->password > ticket){
            ticket = new->password;
        }
        new = new->next;
    }
    ticket++;
    return ticket;
}

void queue_insert(Queue* f, int v)
{
    List* new = (List *)malloc(sizeof(List));
    new->info = v;
    new->password = next_ticket_queue(f);
    new->next = NULL;

    if (f->start == NULL)
    {
        f->start = new;
    }

    if (f->end != NULL)
    {
        f->end->next = new;    
    }
    
    f->end = new;
}

void queue_remove_first(Queue* f)
{ 
    queue_remove_by_index(f, 0);
}

void queue_remove_by_index(Queue* f, int index)
{
    List* ptr = f->start;
    List* ant = NULL;
    int count = 0;
    while (ptr != NULL)
    {
        if (count == index)
        {
            if (ant != NULL)
            {
                ant->next = ptr->next;
            }

            if (ptr->next == NULL)
            {
                f->end = ant;
            }

            if (ant == NULL)
            {
                f->start = ptr->next;
            }

            free(ptr);
            return;
        }
        
        count++;
        ant = ptr;
        ptr = ptr->next;
    }

}

int seat_clients(int amount_of_clients, Table* table_chart, Stack* s, int m, int n)
{
    while (amount_of_clients > 0 && is_any_table_free(table_chart, m, n))
    {
        int index = find_free_table(table_chart, m, n);

        int seated_people = (amount_of_clients > 4) ? 4 : amount_of_clients;
        amount_of_clients -= seated_people;

        use_table(table_chart, index, seated_people, s, m, n);
    }

    return amount_of_clients;
}

void call_next_in_queue(Queue* clients_queue, Table* table_chart, Stack* s, int m, int n)
{
    if(clients_queue->start == NULL)
    {
        printf("Nao ha clientes esperando na fila. A mesa continua vazia.\n");
        return;
    }

    printf("Tentando alocar clientes da fila.\n");
    
    if (!is_any_table_free(table_chart, m, n))
    {
        printf("Nao ha mesas livres.\n");
        return;
    }
    
    int unseated = seat_clients(clients_queue->start->info, table_chart, s, m, n);
    printf("%d pessoas foram alocadas em uma mesa.\n", clients_queue->start->info-unseated);

    if (unseated > 0)
    {
        clients_queue->start->info = unseated;
    }

    else
    {
        queue_remove_first(clients_queue);
    }

    return;
}

void receive_clients(Queue* clients_queue, Table* table_chart, Stack* s, int m, int n)
{
    printf("Chegada de Clientes\n\n");
    printf("Digite o numero de clientes no grupo: ");

    int amount_of_clients;
    scanf("%d", &amount_of_clients);

    int remaining = seat_clients(amount_of_clients, table_chart, s, m, n);

    if (remaining > 0)
    {
        queue_insert(clients_queue, remaining);   
    }
    
}

void print_queue(Queue* clients_queue)
{
    List* ptr = clients_queue->start;
    int total_people = 0;

    if (ptr == NULL){
        printf("Fila vazia. \n\n");
        return;
    }

    printf("Fila de clientes, do inicio ao fim:\n\n");

    int index = 0;

    while (ptr != NULL)
    {
        index++;
        printf("Grupo #%03d: ", index);
        printf("%d clientes, ", ptr->info);
        printf("ticket: %d \n", ptr->password);

        total_people += ptr->info;

        ptr = ptr->next;
    }

    printf("\n");
    printf("Ha um total de %d pessoas na fila.\n", total_people);
    printf("\n\n");
    

}

void give_up_waiting(Queue* clients_queue)
{
    printf("Selecione um grupo para desistir:\n\n");
    print_queue(clients_queue);

    printf("Digite o indice do grupo: ");
    int index;
    scanf("%d", &index);

    queue_remove_by_index(clients_queue, index-1);
}
