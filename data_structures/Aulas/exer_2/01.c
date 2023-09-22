#include <stdio.h>
#include <stdlib.h>

void imprime_matriz(int m, int n, int* mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("  %d  ", mat[i*n + j]);
        }
        printf("\n");
        
    }
}

void main()
{
    printf("Digite as dimensoes da matriz: ");
    int m, n;
    scanf("%d %d", &m, &n);

    int *mat = (int*) malloc(m*n*sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Elemento %d,%d: ", i, j);
            scanf("%d", &mat[i*n + j]);
        }
        
    }

    imprime_matriz(m, n, mat);
}