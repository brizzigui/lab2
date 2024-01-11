#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

List* create_list(){
    return NULL;
}

List* insert_list(List* l){
    List* new = (List*)malloc(sizeof(List)); 
    
    printf("Digite a matricula do aluno: ");
    scanf("%lld", &new->registration);
    getchar();
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]", new->name);
    printf("Digite o ano de entrada do aluno: ");
    scanf("%d", &new->entry_year);

    List* ptr = l;
    List* ant = NULL;

    if(ptr == NULL){
        l = new;
        new->next = NULL;
        return l;
    }

    while(ptr != NULL && new->registration > ptr->registration){
        ant = ptr;
        ptr = ptr->next;
    }

    if (ant != NULL){
        ant->next = new;
    }
    else{
        l = new;
    }
    new->next = ptr;

    return l;
}

void print_list(List* l){
    List* ptr = l;
    if(ptr == NULL){
        printf("Nao ha alunos cadastrados. \n");
        return;
    }

    int count = 1;
    while(ptr != NULL){
        printf("\t\tAluno #%02d \n", count);
        printf("\t\t\tMatricula: %lld; ", ptr->registration);
        printf("Nome: %s; ", ptr->name);
        printf("Ano de ingresso: %lld; \n", ptr->entry_year);

        count++;

        ptr = ptr->next;
    }
}

List* remove_from_list(List* l){
    print_list(l);
    
    if (l == NULL)
    {
        return l;
    }
    
    long long mat;
    printf("Digite a matricula do aluno que deseja remover da lista: ");
    scanf("%lld", &mat);
    
    List* ant = NULL;
    List* ptr = l;

    while(ptr != NULL && mat != ptr->registration){
        ant = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL){
        printf("Nao ha nenhum aluno com esta matricula. \n");
        return l;
    }
    if(ant == NULL){
        l = l->next;
    }
    else{
        ant->next = ptr->next;
    }

    return l;
}