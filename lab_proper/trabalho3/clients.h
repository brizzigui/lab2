#ifndef CLIENTS_H
#define CLIENTS_H

struct clients
{
    char cnh[11];
    char nome[64];
    char telefone[17];
};

typedef struct clients Clients;

struct list_clients
{
    Clients info;
    struct list_clients *next;
};

typedef struct list_clients List_clients;

List_clients* clients_create();
List_clients* add_clients(List_clients* lista_clientes);
void list_all_clients(List_clients* lista_clientes);
int list_len_clients(List_clients* lista_clientes);
List_clients* find_client_pointer_by_index(List_clients* lista_clientes, int idx);

#endif