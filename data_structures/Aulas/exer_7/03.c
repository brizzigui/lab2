#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct aluno
{
    int matricula;
    char nome[50];
};
typedef struct aluno Aluno;

struct lista
{
    Aluno* info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* list_create()
{
    return NULL;
}

Lista* list_insert(Lista* l, int matricula, char *nome)
{
    Aluno* current_info = (Aluno*)malloc(sizeof(Aluno));
    Lista* new = (Lista*)malloc(sizeof(Lista));
    new->info = current_info;

    new->info->matricula = matricula;
    strcpy(new->info->nome, nome);
    new->prox = l;

    l = new;
    return l;
    
}

void list_print(Lista* l)
{
    Lista* ptr = l;
    while (ptr != NULL)
    {
        printf("Matricula: %d - nome: %s\n", ptr->info->matricula, ptr->info->nome);
        ptr = ptr->prox;
    }
    
}

void main()
{
    Lista* l = list_create();

    printf("Quantas pessoas voce quer adicionar a lista? ");
    int range;
    scanf("%d", &range);

    for (int i = 0; i < range; i++)
    {
        printf("Digite a matricula: ");
        int matricula;
        scanf("%d", &matricula);

        printf("Digite o nome: ");
        char nome[50];
        scanf("%s", nome);

        l = list_insert(l, matricula, nome);
    }

    list_print(l);
    
}
