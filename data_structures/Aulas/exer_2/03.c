#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int** aloca_matriz (int m, int n)
{
    int** mat = (int**) malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        mat[i] = (int*) malloc(n*sizeof(int));
    }

    return mat;
    
}

void desaloca_matriz (int m, int** mat)
{
    for (int i = 0; i < m; i++)
    {
        free(mat[i]);
    }
    
    free(mat);
}

void preenche_matriz (int m, int n, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite os elementos: ");
            scanf("%d", &mat[i][j]);
        }
        
    }
    
}

void mostra_matriz (int m, int n, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("   %d   ", mat[i][j]);
        }

        printf("\n");
    }
}

void main(){
    int m,n;
    printf("Digite as dimensoes: ");
    scanf("%d %d", &m, &n);

    int** mat = aloca_matriz(m, n);
    preenche_matriz(m, n, mat);
    mostra_matriz(m, n, mat);
    desaloca_matriz(m, mat);
}
