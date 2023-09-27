#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "cars.h"
#include "clients.h"
#include "time.h"
#include "rental.h"

// compile using: gcc control.c rental.c clients.c cars.c time.c -o control.exe

void report1(Rental_list* locacoes){
    Date data_meio;
    printf("Insira a data (DD MM AAAA): ");
    scanf("%d %d %d", &data_meio.day, &data_meio.month, &data_meio.year);
    printf("\nLocacoes ativas durante a data informada: \n");
    list_all_active_rentals_in_a_date(locacoes, data_meio);
}

void report2(Rental_list* locacoes){
    char cnh[11];
    printf("Qual a CNH do cliente: ");
    scanf("%s", &cnh);
    printf("\nLocacoes do cliente: \n");
    list_all_client_rentals(locacoes, cnh);
}

void report3(Rental_list* locacoes){
    Date data_meio;
    data_meio.day = -1;
    printf("Insira a data para verificar o faturamento (MM AAAA): ");
    scanf("%d %d", &data_meio.month, &data_meio.year);
    printf("\nO faturamento total em %02d %d foi de: R$ ", data_meio.month, data_meio.year);
    invoice_per_month(locacoes, data_meio);
    printf("\n*esse valor se refere as devolucoes de veiculos realizados nesse mes\n");
}

void reorganizevector(int maisrodados[3], char placas[3][8]){
    int aux;
    char auxstr[8];
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            if(maisrodados[j] > maisrodados[i]){
                aux = maisrodados[i];
                maisrodados[i] = maisrodados[j];
                maisrodados[j] = aux;
                strcpy(auxstr, placas[i]);
                strcpy(placas[i], placas[j]);
                strcpy(placas[j], auxstr);
            }
        }  
    } 
}

void report4(Cars_list* carros){
    int maisrodados[3] = {0, 0, 0};
    char placas[3][8];
    Cars_list* ptr = carros;
    while(ptr != NULL){
        if(ptr->info.quilometragem_atual > maisrodados[2]){
            maisrodados[2] = ptr->info.quilometragem_atual;
            strcpy(placas[2], ptr->info.placa);
            reorganizevector(maisrodados, placas);
        }
        ptr = ptr->next;
    }
    printf("Veiculos mais rodados: \n");
    for (int i = 0; i < 3; i++)
    {
        if(maisrodados[i] != 0){
            printf("%d - Placa: %s, quilometragem: %d \n", i+1, placas[i], maisrodados[i]);
        }
    }
}

void report5(Cars_list* carros)
{
    list_all_avaliable_cars(carros);
}

void menu_locacoes(Cars_list* carros, List_clients* clientes, Rental_list* locacoes){
    int n;
    system("clear || cls");
    printf("--------------------------------------\n");
    printf("Qual relatorio deseja ver?\n");
    printf("1 - R1 - Todas locacoes ativas;\n"); 
    printf("2 - R2 - Todas locacoes de um cliente;\n");
    printf("3 - R3 - Faturmento mensal;\n");
    printf("4 - R4 - Veiculos mais rodados;\n");
    printf("5 - R5 - Veiculos disponiveis;\n");
    printf("--------------------------------------\n");

    printf("Sua opcao: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        report1(locacoes);
        break;
    case 2:
        report2(locacoes);
        break;
    case 3:
        report3(locacoes);
        break;
    case 4:
        report4(carros);
        break;
    case 5:
        report5(carros);
        break;
    default:
        printf("Digite uma opcao valida. \n");
        return;
        break;
    }
    return;
}

int main(){
    system("clear || cls");
    bool conti = true;
    int choice;

    Cars_list* carros = create_car_list();
    List_clients* clientes = clients_create();
    Rental_list* locacoes = rental_create();

    while(conti){
        printf("------------------------------\n");
        printf("\nQual acao deseja realizar?\n ");
        printf("1 - Cadastrar veiculo; \n 2 - Listar veiculos; \n 3 - Cadastrar cliente; \n 4 - Listar clientes;\n ");
        printf("5 - Locar veiculo; \n 6 - Devolver veiculo; \n 7 - Listar locacoes; \n 9 - Relatorios.\n 11 - Sair\n");
        printf("------------------------------\n");
        printf("Sua opcao: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            carros = add_car(carros);
            break;
        case 2:
            list_all_cars(carros);
            break;
        case 3:
            clientes = add_clients(clientes);
            break;
        case 4:
            list_all_clients(clientes);
            break;
        case 5:
            locacoes = add_rental(locacoes, clientes, carros);
            break;
        case 6:
            return_car(locacoes);
            break;
        case 7:
            list_all_rentals(locacoes);
            break;
        case 9:
            menu_locacoes(carros, clientes, locacoes);
            break;
        case 11:
            conti = false;
            break;
        default:
            printf("Digite uma opcao valida.");
            break;
        }
    }
    return 0;
}