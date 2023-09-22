#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define ALUNO_TYPE 0
#define PROFESSOR_TYPE 1

struct professor
{
    int codigo;
    char nome[50];
    float salario;
};
typedef struct professor Professor;

struct aluno
{
    int matricula;
    char nome[50];
};
typedef struct aluno Aluno;

struct listaHet
{
    int tipo;
    void* info;
    struct listaHet* prox;
};
typedef struct listaHet ListaHet;

ListaHet* list_create()
{
    return NULL;
}

ListaHet* list_insert_aluno(ListaHet* l, int matricula, char *nome)
{
    Aluno* current_info = (Aluno*)malloc(sizeof(Aluno));
    ListaHet* new = (ListaHet*)malloc(sizeof(ListaHet));
    new->info = current_info;
    new->tipo = ALUNO_TYPE;

    current_info->matricula = matricula;
    strcpy(current_info->nome, nome);

    new->prox = l;
    l = new;

    return l;
}

ListaHet* list_insert_professor(ListaHet* l, int codigo, char *nome, float salario)
{
    Professor* current_info = (Professor*)malloc(sizeof(Professor));
    ListaHet* new = (ListaHet*)malloc(sizeof(ListaHet));
    new->info = current_info;
    new->tipo = PROFESSOR_TYPE;

    current_info->codigo = codigo;
    current_info->salario = salario;
    strcpy(current_info->nome, nome);

    new->prox = l;
    l = new;
}

void list_print(ListaHet* l)
{
    ListaHet* ptr = l;
    while (ptr != NULL)
    {
        if (ptr->tipo == ALUNO_TYPE)
        {
            printf("\nAluno:\n");
            printf("\tMatricula: %d - Nome: %s\n", ((Aluno*)(ptr->info))->matricula, ((Aluno*)(ptr->info))->nome);
        }

        else
        {
            printf("\nProfessor:\n");
            printf("\tCodigo: %d - Nome: %s - Salario: %f\n", ((Professor*)(ptr->info))->codigo, ((Professor*)(ptr->info))->nome, ((Professor*)(ptr->info))->salario);
        }

        ptr = ptr->prox;
    }
    
}

void main()
{
    ListaHet* l = list_create();

    printf("Quantos alunos voce quer adicionar a lista? ");
    int range_alunos;
    scanf("%d", &range_alunos);

    for (int i = 0; i < range_alunos; i++)
    {
        printf("Digite a matricula: ");
        int matricula;
        scanf("%d", &matricula);

        printf("Digite o nome: ");
        char nome[50];
        scanf("%s", nome);

        l = list_insert_aluno(l, matricula, nome);
    }

    printf("Quantos professores voce quer adicionar a lista? ");
    int range_professores;
    scanf("%d", &range_professores);

    for (int i = 0; i < range_professores; i++)
    {
        printf("Digite o codigo: ");
        int codigo;
        scanf("%d", &codigo);

        printf("Digite o nome: ");
        char nome[50];
        scanf("%s", nome);

        printf("Digite o salario: ");
        float salario;
        scanf("%f", &salario);

        l = list_insert_professor(l, codigo, nome, salario);
    }

    list_print(l);
    
}
