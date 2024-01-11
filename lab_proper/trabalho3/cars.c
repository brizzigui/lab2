#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "cars.h"
#include "clients.h"
#include "time.h"
#include "rental.h"

Cars_list* create_car_list(){
    return NULL;
}

Cars_list* add_car(Cars_list* lista_carros){
    Cars_list* new = (Cars_list*)malloc(sizeof(Cars_list));

    system("clear || cls");
    printf("Cadastro de carros\n");
    printf("------------------------------\n\n");

    // adicionei uns getchar pq tava dando bug no buffer da entrada
    printf("Qual a placa do carro? ");
    scanf("%s", new->info.placa);
    getchar();
    printf("Qual a marca do carro? ");
    scanf("%[^\n]", new->info.marca);
    getchar();
    printf("Qual a modelo do carro? ");
    scanf("%[^\n]", new->info.modelo);
    getchar();
    printf("Qual o ano de fabricacao do carro? ");
    scanf("%d", &new->info.ano_fabricacao);
    printf("Qual a quilometragem atual do carro? ");
    scanf("%d", &new->info.quilometragem_atual);
    printf("Qual o valor da diaria do carro? ");
    scanf("%f", &new->info.valor_diaria);

    new->info.disponivel = true;

    new->next = lista_carros;
    return new;
}

void list_all_cars(Cars_list* lista_carros){
    system("clear || cls");

    int count = 1;
    Cars_list* ptr = lista_carros;

    if (ptr == NULL)
    {
        printf("Nao ha carros cadastrados.\n");
        printf("Cadastre um carro e volte aqui para ve-lo.\n");
        return;
    }

    while(ptr != NULL){

        printf("%03d:\n\tPlaca: %s\n", count, ptr->info.placa);
        printf("\tMarca: %s\n", ptr->info.marca);
        printf("\tModelo: %s\n", ptr->info.modelo);
        printf("\tAno fabricacao: %d\n", ptr->info.ano_fabricacao);
        printf("\tQuilometragem atual: %d\n", ptr->info.quilometragem_atual);
        printf("\tValor diaria: %.2f\n", ptr->info.valor_diaria);
        if(ptr->info.disponivel){
            printf("\tDisponivel\n\n");
        }
        else{
            printf("\tIndisponivel\n\n"); 
        }
        count++;
        ptr = ptr->next;
    }
}

void list_all_avaliable_cars(Cars_list* lista_carros){
    int count = 1;
    Cars_list* ptr = lista_carros;

    if (ptr == NULL)
    {
        printf("Nao ha carros cadastrados.\n");
        printf("Cadastre um carro e volte aqui para ve-lo.\n");
        return;
    }

    printf("------------------------------\n\n");

    while(ptr != NULL){

        if (ptr->info.disponivel)
        {
            printf("%03d:\n\tPlaca: %s\n", count, ptr->info.placa);
            printf("\tMarca: %s\n", ptr->info.marca);
            printf("\tModelo: %s\n", ptr->info.modelo);
            printf("\tAno fabricacao: %d\n", ptr->info.ano_fabricacao);
            printf("\tQuilometragem atual: %d\n", ptr->info.quilometragem_atual);
            printf("\tValor diaria: %.2f\n", ptr->info.valor_diaria);
            count++;
        }

        ptr = ptr->next;
    }

    printf("------------------------------\n\n");
}

int list_len_avaliable_carros(Cars_list* lista_carros)
{
    Cars_list* ptr = lista_carros;
    int count = 0;

    while (ptr != NULL)
    {
        if (ptr->info.disponivel)
        {
            count++;
        }

        ptr = ptr->next;
    }

    return count;
}

Cars_list* find_avaliable_car_pointer_by_index(Cars_list* lista_carros, int idx)
{
    Cars_list* ptr = lista_carros;
    int count = 0;

    while (ptr != NULL)
    {        
        if (ptr->info.disponivel)
        {
            if (count == idx)
            {
                return ptr;
            }

            count++;
        }

        ptr = ptr->next;
    }
}
