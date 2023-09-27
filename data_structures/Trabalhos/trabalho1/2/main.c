#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista
{
    int linha;
    int coluna;
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct esparsa
{
    int linhas;
    int colunas;
    struct lista* prim;
};
typedef struct esparsa Esparsa;

void cria_matriz(Esparsa *m)
{
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &m->linhas);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &m->colunas);

    m->prim = NULL;
}

void preenche_matriz(Esparsa *m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            int data;
            printf("Insira o conteudo em (%d, %d) (digite 0 para deixar vazio): ", i, j);
            scanf("%d", &data);

            if (data != 0)
            {
                Lista* new = (Lista *)malloc(sizeof(Lista));
                new->prox = NULL;
                new->info = data;
                new->linha = i;
                new->coluna = j;

                if(m->prim == NULL)
                {
                    m->prim = new;
                }

                else
                {
                    Lista* ptr = m->prim;
                    while (1)
                    {
                        if (ptr->prox == NULL)
                        {
                            break;
                        }
                        
                        ptr = ptr->prox;
                    }

                    ptr->prox = new;
                } 
            }
        }
    }
}

void imprime_matriz(Esparsa m)
{
    int lines = m.linhas;
    int columns = m.colunas;

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Lista* ptr = m.prim;
            bool found = false;
            while (ptr != NULL)
            {
                if (ptr->linha == i && ptr->coluna == j)
                {
                    found = true;
                    printf(" %d ", ptr->info);
                }
                
                ptr = ptr->prox;
            }

            if (!found)
            {
                printf(" 0 ");
            }
        }

        printf("\n");
    }
}

void consulta_elemento(Esparsa m)
{
    printf("Em que linha e coluna esta o elemento a ser buscado: ");
    int search_line, search_column;
    scanf("%d %d", &search_line, &search_column);

    Lista* ptr = m.prim;
    bool found = false;

    while (ptr != NULL)
    {
        if (ptr->linha == search_line && ptr->coluna == search_column)
        {
            printf("O valor na posicao (%d, %d): %d.\n", search_line, search_column, ptr->info);
            return;
        }

        ptr = ptr->prox;
    }

    printf("O valor na posicao (%d, %d): 0.\n", search_line, search_column);
    return;

}

void somatorio_linha(Esparsa m)
{
    Lista* ptr = m.prim;
    int sum_line;
    int sum = 0;

    printf("De que linha voce quer obter o somatorio? ");
    scanf("%d", &sum_line);

    while (ptr != NULL)
    {
        if (ptr->linha == sum_line)
        {
            sum += ptr->info;
        }

        ptr = ptr->prox;
    }

    printf("A soma foi de %d na linha %d.\n", sum, sum_line);
}

void percentual_ocupada(Esparsa m)
{
    Lista* ptr = m.prim;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->prox;
    }

    printf("O percentual ocupado foi de %f%%\n", ((float)count/(m.linhas * m.colunas))*100);
    
}

void main()
{
    Esparsa matriz;
    cria_matriz(&matriz);
    preenche_matriz(&matriz);

    int option;
    do
    {
        printf("\n\nO que voce deseja realizar agora? \n");
        printf("1 - imprimir a matriz.\n");
        printf("2 - consulta a elemento.\n");
        printf("3 - somatorio de uma linha.\n");
        printf("4 - ver o percentual de elementos nao nulos.\n");
        printf("5 - sair.\n");

        printf("Digite o numero correspondente a opcao desejada: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                imprime_matriz(matriz);
                break;
            
            case 2:
                consulta_elemento(matriz);
                break;

            case 3:
                somatorio_linha(matriz);
                break;

            case 4:
                percentual_ocupada(matriz);
                break;

        }

    } while (option != 5);

}