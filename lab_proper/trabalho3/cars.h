#ifndef CARS_H
#define CARS_H

struct car
{
    char placa[8];
    char marca[64];
    char modelo[64];
    int ano_fabricacao;
    int quilometragem_atual;
    float valor_diaria;
    bool disponivel;
}; 

typedef struct car Carros;

struct cars_list
{
    Carros info;
    struct cars_list* next;
}; 

typedef struct cars_list Cars_list;

Cars_list* create_car_list();
Cars_list* add_car(Cars_list* lista_carros);
void list_all_cars(Cars_list* lista_carros);
int list_len_avaliable_carros(Cars_list* lista_carros);
Cars_list* find_avaliable_car_pointer_by_index(Cars_list* lista_carros, int idx);
void list_all_avaliable_cars(Cars_list* lista_carros);

#endif