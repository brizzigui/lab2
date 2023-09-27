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

Rental_list* rental_create()
{
    return NULL;
}

Rental_list* add_rental(Rental_list* lista_locacoes, List_clients* lista_clientes, Cars_list* lista_carros)
{
    system("clear || cls");
    if (list_len_clients(lista_clientes) == 0 || list_len_avaliable_carros(lista_carros) == 0)
    {
        if (list_len_clients(lista_clientes) == 0)
        {
            printf("Nao ha clientes cadastrados ainda.\n");
            printf("Cadastre um cliente e volte aqui para cadastrar sua locacao.\n\n");
        }

        if (list_len_avaliable_carros(lista_carros) == 0)
        {
            printf("Nao ha carros disponiveis.\n");
            printf("Cadastre ou devolva um carro e volte aqui para cadastrar sua locacao.\n\n");
        }

        return lista_locacoes;
    }


    printf("Listagem dos clientes:\n");
    list_all_clients(lista_clientes);

    int selected_index;
    do
    {
        printf("Digite o indice de um cliente para seleciona-lo para a locacao: ");
        scanf("%d", &selected_index); 

        if (selected_index < 1 || selected_index > list_len_clients(lista_clientes))
        {
            printf("Indice invalido. Tente novamente.\n");
        }
         
    } while (selected_index < 1 || selected_index > list_len_clients(lista_clientes));
    
    Rental_list* new = (Rental_list *)malloc(sizeof(Rental_list));
    new->info.cliente = find_client_pointer_by_index(lista_clientes, selected_index-1);
    printf("Cliente selecionado: %03d - %s.\n\n", selected_index, new->info.cliente->info.nome);

    printf("Listagem dos carros:\n");
    list_all_avaliable_cars(lista_carros);

    do
    {
        printf("Digite o indice de um carro para seleciona-lo para a locacao: ");
        scanf("%d", &selected_index); 

        if (selected_index < 1 || selected_index > list_len_avaliable_carros(lista_carros))
        {
            printf("Indice invalido. Tente novamente.\n");
        }
         
    } while (selected_index < 1 || selected_index > list_len_avaliable_carros(lista_carros));

    new->info.carro = find_avaliable_car_pointer_by_index(lista_carros, selected_index-1);
    printf("Carro selecionado: %03d - %s - %s.\n", selected_index, new->info.carro->info.modelo, new->info.carro->info.placa);
    
    printf("Insira a data de inicio da locacao (DD MM AAAA): ");
    scanf("%d %d %d", &new->info.data_inicio.day, &new->info.data_inicio.month, &new->info.data_inicio.year);

    // -1 indica que está ativa a locação
    new->info.data_fim.day = -1;

    new->info.carro->info.disponivel = false;
    new->next = lista_locacoes;
    return new;
}

int list_len_locacoes(Rental_list* lista_locacoes)
{
    Rental_list* ptr = lista_locacoes;
    int count = 0;

    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    return count;
}

void list_all_active_rentals(Rental_list* lista_locacoes)
{
    Rental_list* ptr = lista_locacoes;
    int count = 1;

    while (ptr != NULL)
    {
        if (ptr->info.data_fim.day == -1)
        {
            printf("Locacao #%03d:\n", count);
            printf("\tCliente: \n\t\tNome:%s - Telefone: %s - CNH: %s\n", ptr->info.cliente->info.nome, ptr->info.cliente->info.telefone, ptr->info.cliente->info.cnh);
            printf("\tCarro: \n\t\tPlaca: %s - Modelo: %s\n", ptr->info.carro->info.placa, ptr->info.carro->info.modelo);
        }

        count++;
        ptr = ptr->next;
    }
    
}

Rental_list* find_rental_pointer_by_index(Rental_list* lista_locacoes, int idx)
{
    Rental_list* ptr = lista_locacoes;
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

void return_car(Rental_list* lista_locacoes)
{
    list_all_active_rentals(lista_locacoes);

    int selected_index;
    do
    {
        printf("Digite o indice de uma locacao para seleciona-la para a devolucao: ");
        scanf("%d", &selected_index); 

        if (selected_index < 1 || selected_index > list_len_locacoes(lista_locacoes))
        {
            printf("Indice invalido. Tente novamente.\n");
        }
         
    } while (selected_index < 1 || selected_index > list_len_locacoes(lista_locacoes));

    Rental_list* ptr = find_rental_pointer_by_index(lista_locacoes, selected_index-1);

    printf("Insira a data de fim da locacao (DD MM AAAA): ");
    scanf("%d %d %d", &ptr->info.data_fim.day, &ptr->info.data_fim.month, &ptr->info.data_fim.year);

    printf("Insira a quilometragem rodada: ");
    int rodado;
    scanf("%d", &rodado);
    ptr->info.carro->info.quilometragem_atual += rodado;

    ptr->info.valor_pago = ptr->info.carro->info.valor_diaria * (float)daysBetweenDates(ptr->info.data_inicio, ptr->info.data_fim);
    printf("O valor pago foi: R$ %.2f", ptr->info.valor_pago);

    ptr->info.carro->info.disponivel = true;
}

void list_all_rentals(Rental_list* lista_locacoes)
{
    Rental_list* ptr = lista_locacoes;
    int count = 1;

    while (ptr != NULL)
    {
        printf("Locacao #%03d:\n", count);
        printf("\tCliente: \n\t\tNome:%s - Telefone: %s - CNH: %s\n", ptr->info.cliente->info.nome, ptr->info.cliente->info.telefone, ptr->info.cliente->info.cnh);
        printf("\tCarro: \n\t\tPlaca: %s - Modelo: %s\n", ptr->info.carro->info.placa, ptr->info.carro->info.modelo);

        ptr = ptr->next;
        count++;
    }
    
}

void list_all_client_rentals(Rental_list* lista_locacoes, char cnh[11]){
    Rental_list* ptr = lista_locacoes;
    int count = 1;

    while(ptr != NULL){
        if(strcmp(cnh, ptr->info.cliente->info.cnh) == 0){
            printf("Locacao #%03d:\n", count);
            printf("\tCliente: \n\t\tNome:%s - Telefone: %s - CNH: %s\n", ptr->info.cliente->info.nome, ptr->info.cliente->info.telefone, ptr->info.cliente->info.cnh);
            printf("\tCarro: \n\t\tPlaca: %s - Modelo: %s\n", ptr->info.carro->info.placa, ptr->info.carro->info.modelo);
            count++;
        }
        ptr = ptr->next;
        
    }
}

void list_all_active_rentals_in_a_date(Rental_list* lista_locacoes, Date data_meio){
    Rental_list* ptr = lista_locacoes;
    int count = 1;

    while(ptr != NULL){
        if(daysBetweenDates(ptr->info.data_inicio, data_meio) >= 0 && ptr->info.data_fim.day == -1 || daysBetweenDates(ptr->info.data_inicio, data_meio) >= 0 && daysBetweenDates(ptr->info.data_fim, data_meio) <= 0){
            printf("Locacao #%03d:\n", count);
            printf("\tCliente: \n\t\tNome:%s - Telefone: %s - CNH: %s\n", ptr->info.cliente->info.nome, ptr->info.cliente->info.telefone, ptr->info.cliente->info.cnh);
            printf("\tCarro: \n\t\tPlaca: %s - Modelo: %s\n", ptr->info.carro->info.placa, ptr->info.carro->info.modelo);

            count++;
        }

        ptr = ptr->next;
    }
}

void invoice_per_month(Rental_list* lista_locacoes, Date data_meio){
    Rental_list* ptr = lista_locacoes;
    float total_invoice = 0;

    while(ptr != NULL){
        if(ptr->info.data_fim.month == data_meio.month && ptr->info.data_fim.year == data_meio.year){
            total_invoice += ptr->info.valor_pago;
        }
        ptr = ptr->next;
    }

    printf("%.2f", total_invoice);
    
}