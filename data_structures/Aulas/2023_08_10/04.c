#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void invertiert_drucken(int *vetor)
{
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[TAM-i-1]);
    }
}

int main()
{
    int *vetor = malloc(TAM * sizeof(int));

    printf("Insira os 10 valores do vetor:\n");
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &vetor[i]);
    }

    invertiert_drucken(vetor);
}
