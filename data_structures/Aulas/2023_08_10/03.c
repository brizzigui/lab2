#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void inverte(int n, int *vet)
{
    for (int i = 0; i < n/2; i++)
    {
        int temp = vet[i];
        vet[i] = vet[n-i-1];
        vet[n-i-1] = temp;
        printf("%d\n", vet[i]);
    }
    
}

int main(){
    printf("Qual o tamanho do vetor? ");
    int tamanho;
    scanf("%d", &tamanho);

    int *vetor = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }

    inverte(tamanho, vetor);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    
}
