#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int negativos(int n, float *vet)
{
    int qnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(vet + i) < 0)
        {
            qnt++;
        }
    }
    
    return qnt;
}

int main(){
    
    int size;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &size);

    float *vetor = malloc(size * sizeof(float));

    for (int i = 0; i < size; i++)
    {
        scanf("%f", &vetor[i]);
    }

    int qnt_neg = negativos(size, vetor);
    printf("Havia %d numeros negativos.\n", qnt_neg);
}
