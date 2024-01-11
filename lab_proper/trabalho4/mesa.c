#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "mesa.h"
#include "pilha.h"

Table* tables_create(int m, int n)
{
    Table* new = (Table *)malloc(m*n * sizeof(Table));
    for (int i = 0; i < m*n; i++)
    {
        new[i].available = true;
        new[i].set_up = true;
        new[i].dirty_dishes = false;
        new[i].ticket = 0;
    }
    
    return new;
}

int find_free_table(Table* t, int m, int n)
{
    for (int i = 0; i < m*n; i++)
    {
        if(t[i].available && t[i].set_up)
        {
            return i;
        }
    }

    return -1;
    
}

bool is_any_table_free(Table* t, int m, int n)
{
    if (find_free_table(t, m, n) != -1)
    {
        return true;
    }

    return false;
       
}

int next_ticket(Table* t, int m, int n){
    int nticket = 0;
    for (int i = 0; i < m * n; i++)
    {
        if(t[i].ticket > nticket){
            nticket = t[i].ticket;
        }
    }
    nticket++;
    return nticket;
}

void use_table(Table* t, int index, int people, Stack* s, int m, int n)
{
    t[index].available = false;
    t[index].set_up = false;
    t[index].people = people;
    t[index].ticket = next_ticket(t, m, n);
    if(t[index].people < 4){
        for (int i = t[index].people; i < 4; i++)
        {
            stack_push(s);
        }
    }
}

void print_tables(Table* t, int m, int n)
{
    for (int i = 0; i < m*n; i++)
    {
        if (!t[i].available)
        {
            printf("Mesa %02d: ocupada com %d pessoas. Ticket da mesa: %d \n", i+1, t[i].people, t[i].ticket);
        }
        
        else
        {
            if (t[i].set_up)
            {
                printf("Mesa %02d: disponivel arrumada.\n", i+1);   
            }

            else
            {
                if(t[i].dirty_dishes){
                    printf("Mesa %02d: disponivel com pratos sujos.\n", i+1);
                }
                else{
                    printf("Mesa %02d: disponivel vazia.\n", i+1);
                }
            }
        }
    }

    printf("\n\n");
    
}

void graphically_print_tables(Table* t, int m, int n)
{
    system("clear || cls");
    printf("  -------------------- Mapa das Mesas -------------------\n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("  Mesa %02d   ", i*n+j+1);
        }
        printf("\n");

        for (int j = 0; j < n; j++)
        {
            printf("  _______   ");
        }

        printf("\n");


        for (int j = 0; j < n; j++)
        {
            if (t[i*n+j].available && t[i*n+j].set_up && !t[i*n+j].dirty_dishes)
            {
                printf(" |   o   |  ");
            }

            else if (t[i*n+j].available && t[i*n+j].dirty_dishes)
            {
                printf(" |   x   |  ");
            }
            
            else if (t[i*n+j].available)
            {
                printf(" |       |  ");
            }

            else
            {
                printf(" |///////|  ");
            }
        }
        printf("\n");


        for (int j = 0; j < n; j++)
        {
            if (t[i*n+j].available && t[i*n+j].set_up && !t[i*n+j].dirty_dishes)
            {
                printf(" |o     o|  ");
            }

            else if (t[i*n+j].available && t[i*n+j].dirty_dishes)
            {
                printf(" |x     x|  ");
            }

            else if (t[i*n+j].available)
            {
                printf(" |       |  ");
            }

            else
            {
                printf(" |///////|  ");
            }
        }
        printf("\n");


        for (int j = 0; j < n; j++)
        {
            if (t[i*n+j].available && t[i*n+j].set_up && !t[i*n+j].dirty_dishes)
            {
                printf(" |___o___|  ");
            }

            else if (t[i*n+j].available && t[i*n+j].dirty_dishes)
            {
                printf(" |___x___|  ");
            }

            else if (t[i*n+j].available)
            {
                printf(" |_______|  ");
            }

            else
            {
                printf(" |///////|  ");
            }
        }

        printf("\n");

        for (int j = 0; j < n; j++)
        {
            if (!t[i*n+j].available)
            {
                printf(" Com.: %03d  ", t[i*n+j].ticket);
            }
        }

        printf("\n");

        for (int j = 0; j < n; j++)
        {
            if (!t[i*n+j].available)
            {
                printf("  %d pess.   ", t[i*n+j].people);
            }
        }
        
        printf("\n\n\n");        
    }
    
    printf("Mesas hachuradas estao ocupadas.\n");
    printf("Mesas com circulos indicam que a mesa esta disponivel e arrumada com pratos.\n");
    printf("Mesas com 'x' indicam que a mesa esta disponivel e com pratos sujos.\n");
    printf("Mesas sem marcacao sestao livres, mas nao arrumadas.\n");

    printf("\nAviso: quantia de pratos meramente ilustrativa. Usar funcao de pratos para verificacao correta.\n");

    printf("\nDigite uma tecla para sair: ");
    char temp;
    scanf(" %c", &temp);

    system("clear || cls");
}

void end_meal(Table* table_chart, int m, int n)
{
    printf("Selecione uma mesa para terminar a refeicao.\n\n");
    print_tables(table_chart, m, n);

    printf("Digite o indice: ");
    int index;
    scanf("%d", &index);

    index--;

    if (table_chart[index].available)
    {
        printf("Mesa nao possui clientes.\n");
        printf("Tente novamente.\n");
    }

    else
    {
        table_chart[index].available = true;
        table_chart[index].dirty_dishes = true;

        printf("Refeicao da mesa #%02d terminada. Mesa liberada.\n", index+1);
    }

}

void tidy_table(Queue* clients_queue, Stack* s, Table* table_chart, int m, int n){
    int index;

    if(count_plates(s) < 4){
        printf("Pratos insuficientes na pilha. \n");
        return;
    }

    print_tables(table_chart, m, n);

    printf("Qual mesa deseja arrumar? \n");
    scanf("%d", &index);
    index--;
    if(table_chart[index].available == true && table_chart[index].set_up == false && table_chart[index].dirty_dishes == false){
        for (int i = 0; i < 4; i++)
        {
            stack_pop(s);
        }
        table_chart[index].set_up = true;
        table_chart[index].dirty_dishes = false;
        printf("Mesa arrumada. \n\n");
    }
    else if (table_chart[index].available == false){
        printf("Essa mesa esta ocupada. \n");
    }
    else if(table_chart[index].available == true && table_chart[index].set_up == true){
        printf("Essa mesa ja esta arrumada. \n");
    }
    else if(table_chart[index].dirty_dishes == true){
        printf("Guarde os pratos sujos antes de arrumar a mesa. \n");
    }

    call_next_in_queue(clients_queue, table_chart, s, m, n);

}

int find_messed_table(Table* t, int m, int n)
{
    for (int i = 0; i < m*n; i++)
    {
        if(t[i].available && t[i].set_up == false && t[i].dirty_dishes)
        {
            return i;
        }
    }

    return -1;
    
}

bool is_any_table_messed(Table* t, int m, int n)
{
    if (find_messed_table(t, m, n) != -1)
    {
        return true;
    }

    return false;
       
}

void print_amount_of_plates_per_table(Table* table_chart, int m, int n)
{
    for (int i = 0; i < m*n; i++)
    {
        printf("Mesa %02d: ", i+1);
        if (table_chart[i].dirty_dishes)
        {
            printf("%d pratos sujos.\n", table_chart[i].people);
        }

        else if(table_chart[i].available && table_chart[i].set_up)
        {
            printf("4 pratos limpos.\n");
        }

        else
        {
            printf("%d pratos sendo usados.\n", table_chart[i].people);
        }        
    }
    
    
}

void search_table_status_by_index(Table* table_chart, int m, int n)
{
    printf("Digite o numero da mesa para consultar seu status: ");

    int requested_index;
    do
    {
        scanf("%d", &requested_index);

        if (requested_index < 1 || requested_index > m*n)
        {
            printf("Indice invalido\n");
        }
        
    } while (requested_index < 1 || requested_index > m*n);
    
    requested_index--;
    

    if (!table_chart[requested_index].available)
    {
        printf("Mesa %02d: ocupada com %d pessoas. Ticket da mesa: %d \n", requested_index+1, table_chart[requested_index].people, table_chart[requested_index].ticket);
    }
    
    else
    {
        if (table_chart[requested_index].set_up)
        {
            printf("Mesa %02d: disponivel arrumada.\n", requested_index+1);   
        }

        else
        {
            if(table_chart[requested_index].dirty_dishes){
                printf("Mesa %02d: disponivel com pratos sujos.\n", requested_index+1);
            }
            else{
                printf("Mesa %02d: disponivel vazia.\n", requested_index+1);
            }
        }
    }

    printf("\n\n");
}
