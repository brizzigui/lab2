/*
    Resolução das questões da p1 2023/1 de
    Estruturas de Dados, profª Deise
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// parte 1
struct aluno{
    char matricula[10];
    char nome[100];
    int anoIngresso;
};
typedef struct aluno Aluno;

// questão 1
Aluno** aloca_matriz (int m, int n)
{
    Aluno** mat = (Aluno **)malloc(sizeof(Aluno *));
    for (int i = 0; i < m; i++)
    {
        mat[i] = (Aluno*)malloc(n*sizeof(Aluno));
    }
    
    return mat;
}

// questão 2
void libera_matriz (Aluno** matriz, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}

// funções não requisitadas - a propósito de depuração

void print_matrix(Aluno** mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", mat[i][j].anoIngresso);
        }
        
        printf("\n");
    }
}

void fill_matrix(Aluno** mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &(mat[i][j].anoIngresso));
        }
    }
}



// parte 2

struct lista
{
    int cpf;
    char nome[100];
    int fator;
    struct lista* prox;
};
typedef struct lista Lista;

// questão 3

Lista* lst_insere (Lista* l, int cpf, char *nome, int fator)
{

    Lista* new = (Lista*)malloc(sizeof(Lista));
    new->cpf = cpf;
    strcpy(new->nome, nome);
    new->fator = fator;

    Lista* ptr = l;
    Lista* ant = NULL;

    if (ptr == NULL)
    {
        // se a lista está vazia
        l = new;
        new->prox = NULL;
        return l;
    }

    // se a lista tem elementos, andar até o fator
    while (ptr != NULL && fator > ptr->fator)
    {
        ant = ptr;
        ptr = ptr->prox;
    }

    if (ant != NULL)
    {
        ant->prox = new;  
    }

    else
    {
        // caso o fator esteja no primeiro
        l = new;
    }
    
    new->prox = ptr;

    return l;
}

void print(Lista* l)
{
    Lista* ptr = l;
    while (ptr != NULL)
    {
        printf("%d - %d - %s\n", ptr->fator, ptr->cpf, ptr->nome);
        ptr = ptr->prox;
    }
    printf("--------\n");
}

Lista* lst_remove (Lista* l, int fator)
{
    Lista* ptr = l;
    Lista* ant = NULL;

    while (ptr != NULL)
    {
        if (ptr->fator == fator)
        {
            if (ant == NULL)
            {
                l = ptr->prox;
            }

            else
            {
                ant = ptr->prox;
            }
            
        }

        else
        {
            ant = ptr;
        }

        ptr = ptr->prox;
        
    }
    
    return l;
}

void main(){

    // parte 1
    printf("Insira o tamanho da matriz m x n: ");
    int m, n;
    scanf("%d %d", &m, &n);
    Aluno** mat = aloca_matriz(m, n);
    fill_matrix(mat, m, n);
    print_matrix(mat, m, n);
    libera_matriz(mat, m);

    // parte 2
    Lista* l = NULL;

    l = lst_insere(l, 999, "lula", 1);
    l = lst_insere(l, 999, "bolsonaro", 2);
    l = lst_insere(l, 999, "stalin", 3);
    l = lst_insere(l, 999, "kim", 2);
    l = lst_insere(l, 999, "mao", 1);
    l = lst_insere(l, 999, "xi", 1);
    l = lst_insere(l, 999, "zolin", 1);
    print(l);

    l = lst_remove(l, 1);
    print(l);
}
