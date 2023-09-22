#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float *aloca_vetor(int tam)
{
    return (float *) malloc(tam * sizeof(float));
}

void le_vetor(int tam, float *vetor)
{
    for (int i = 0; i < tam; i++)
    {
        scanf("%f", &vetor[i]);
    }
    
}

float calc_media(int tam, float *vetor)
{
    float soma = 0;
    for (int i = 0; i < tam; i++)
    {
        soma += vetor[i];
    }

    return soma/tam;
    
}

float percent_nums_maiores(float media, int tam, float *vetor)
{
    int maior_que_media = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] > media)
        {
            maior_que_media++;
        }
        
    }

    return ((float)maior_que_media/tam)*100;
    
}

int main()
{
    int tam;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tam);

    float *vetor = aloca_vetor(tam);
    le_vetor(tam, vetor);
    float media = calc_media(tam, vetor);
    float percentual = percent_nums_maiores(media, tam, vetor);
    free(vetor);

    printf("A media foi de %.2f\n", media);
    printf("O percentual de valores maiores que a media foi %.2f%\n", percentual);
}
