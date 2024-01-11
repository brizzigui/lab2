#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include "mesa.h"

// compile using "gcc control.c lista.c fila.c pilha.c mesa.c -o control.exe"

void menu(Queue* clients_queue, Table* table_chart, Stack* clean_plates, int m, int n)
{
    int choice;
    do
    {
        printf("Menu: \n");
        printf("1. Chegada de clientes\n");
        printf("2. Finalizar refeicao\n");
        printf("3. Desistir de esperar\n");
        printf("4. Arrumar mesa\n");
        printf("5. Recolher e lavar pratos\n");
        printf("6. Ver pilha de pratos\n");
        printf("7. Listar mesas\n");
        printf("8. Pesquisar mesa por numero\n");
        printf("9. Ver mapa grafico de mesas\n");
        printf("10. Ver fila de clientes\n");
        printf("11. Ver quantia de pratos por mesa\n\n");

        printf("99. Sair\n");


        printf("\nSua opcao: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            receive_clients(clients_queue, table_chart, clean_plates, m, n);
            break;

        case 2:
            end_meal(table_chart, m, n);
            break;

        case 3:
            give_up_waiting(clients_queue);
            break;

        case 4:
            tidy_table(clients_queue, clean_plates, table_chart, m, n);
            break;

        case 5:
            refill_plates(clean_plates, table_chart, m, n);
            break;

        case 6:
            print_plates(clean_plates);
            break;

        case 7:
            print_tables(table_chart, m, n);
            break;

        case 8:
            search_table_status_by_index(table_chart, m, n);
            break;

        case 9:
            graphically_print_tables(table_chart, m, n);
            break;

        case 10:
            print_queue(clients_queue);
            break;

        case 11:
            print_amount_of_plates_per_table(table_chart, m, n);
            break;

        case 99:
            break;

        default:
            printf("Opcao invalida, tente novamente.\n\n");
            break;
        }

    } while (choice != 99);

    
}

int main()
{
    system("clear || cls");

    printf("Quais as dimensoes da matriz de mesas (m x n): ");
    int m, n;
    scanf("%d %d", &m, &n);

    Queue* clients_queue = queue_create();
    Table* table_chart = tables_create(m, n);
    Stack* clean_plates = stack_create();

    system("clear || cls");

    menu(clients_queue, table_chart, clean_plates, m, n);
    return 0;
}
