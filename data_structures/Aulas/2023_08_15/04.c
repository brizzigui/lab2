#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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

int** aloca_matriz (int m, int n)
{
    int** mat = (int**) malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        mat[i] = (int*) malloc(n*sizeof(int));
    }

    return mat;
    
}

int** soma_matriz (int m, int n, int** mat1, int** mat2)
{  
    int** mat3 = aloca_matriz(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }  
    }
    
    return mat3;
}

void preenche_matriz (int m, int n, int **mat)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite um elemento: ");
            scanf("%d", &mat[i][j]);
        }
        
    }
    
}

int main(){
    int m, n;
    printf("Insira as dimensoes: ");
    scanf("%d %d", &m, &n);

    int** mat1 = aloca_matriz(m, n);
    int** mat2 = aloca_matriz(m, n);    

    printf("Elementos da matriz 1:\n");
    preenche_matriz(m, n, mat1);

    printf("Elementos da matriz 2:\n");
    preenche_matriz(m, n, mat2);

    int** mat3 = soma_matriz(m, n, mat1, mat2);

    mostra_matriz(m, n, mat3);


}
