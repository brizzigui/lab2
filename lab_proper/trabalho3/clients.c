#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "cars.h"
#include "clients.h"
#include "time.h"
#include "rental.h"

List_clients* clients_create()
{
    return NULL;
}

List_clients* add_clients(List_clients* lista_clientes)
{
    system("clear || cls");
    List_clients* new = (List_clients *)malloc(sizeof(List_clients));

    printf("Insercao de clientes\n");
    printf("------------------------------\n\n");
    printf("Insira o nome do cliente: ");
    getchar();
    scanf("%[^\n]", new->info.nome);
    getchar();
    
    printf("Insira a CNH do cliente: ");
    scanf("%s", &new->info.cnh);

    printf("Insira o telefone do cliente: ");
    scanf("%s", &new->info.telefone);
    
    printf("Cliente adicionado!\n\n");

    new->next = lista_clientes;
    return new;
    
}

void list_all_clients(List_clients* lista_clientes)
{
    List_clients* ptr = lista_clientes;
    int count = 0;

    if (ptr == NULL)
    {
        printf("Nao ha clientes cadastrados.\n");
        printf("Cadastre um cliente e volte para ve-lo aqui.\n");
        return;
    }

    printf("------------------------------\n\n");
    while (ptr != NULL)
    {
        printf("#%03d - Nome: %s - CNH: %s", count+1, ptr->info.nome, ptr->info.cnh);
        printf(" - Telefone: %s\n", ptr->info.telefone);

        ptr = ptr->next;
        count++;
    }

    printf("------------------------------\n\n");

}

List_clients* find_client_pointer_by_index(List_clients* lista_clientes, int idx)
{
    List_clients* ptr = lista_clientes;
    int count = 0;

    while (ptr != NULL)
    {
        if (count == idx)
        {
            return ptr;
        }
        
        ptr = ptr->next;
        count++;
    }
}

int list_len_clients(List_clients* lista_clientes)
{
    List_clients* ptr = lista_clientes;
    int count = 0;

    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    return count;
}
