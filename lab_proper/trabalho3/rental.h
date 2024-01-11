#ifndef RENTAL_H
#define RENTAL_H

#include "cars.h"
#include "clients.h"
#include "time.h"

struct rental
{
    List_clients* cliente;
    Cars_list* carro;
    Date data_inicio;
    Date data_fim;
    float valor_pago;
}; 

typedef struct rental Rental;

struct rental_list
{
    Rental info;
    struct rental_list* next;
}; 

typedef struct rental_list Rental_list;

Rental_list* rental_create();
Rental_list* add_rental(Rental_list* lista_locacoes, List_clients* lista_clientes, Cars_list* lista_carros);
void return_car(Rental_list* lista_locacoes);
void list_all_rentals(Rental_list* lista_locacoes);
void list_all_client_rentals(Rental_list* lista_locacoes, char cnh[11]);
void list_all_active_rentals_in_a_date(Rental_list* lista_locacoes, Date data_meio);
void invoice_per_month(Rental_list* lista_locacoes, Date data_meio);

#endif