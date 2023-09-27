#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int*** aloca_matriz (int m, int n, int z)
{
    int ***p = (int ***)malloc(m * sizeof(int **));
    for (int i = 0; i < m; i++)
    {
        p[i] = (int **)malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++)
        {
            p[i][j] = (int *)malloc(z * sizeof(int));
        }
        
    }
    
    return p;
}

void preenche_matriz (int m, int n, int z, int ***mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < z; k++)
            {
                printf("Insira o elemento presente em (%d, %d, %d): ", i, j, k);
                scanf("%d", &mat[i][j][k]);
            }   
        }
    }    
}

void imprime_matriz (int m, int n, int z, int ***mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[");
            for (int k = 0; k < z; k++)
            {
                printf(" %d ", mat[i][j][k]);
            }   
            printf("]");
        }

        printf("\n");
    }    
}

void main()
{  
    int m, n, z;
    printf("Digite as 3 dimensoes da matriz: ");
    scanf("%d %d %d", &m, &n, &z);

    int ***mat = aloca_matriz(m, n, z);
    preenche_matriz(m, n, z, mat);
    imprime_matriz(m, n, z, mat);

}
