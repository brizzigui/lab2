#include <stdio.h>
#include <stdlib.h>

struct usuario
{
    char sexo;
    int idade;
    int qtdade;
};
typedef struct usuario Usuario;

void leVetor(int tamanho, Usuario* vet)
{
    for (int i = 1; i < tamanho+1; i++)
    {
        printf("Usuario %d\n", i);

        printf("Sexo (m/f): ", i);
        scanf(" %c", &(vet + i)->sexo);

        printf("Idade: ", i);
        scanf("%d", &(vet + i)->idade);

        printf("Livros lidos: ", i);
        scanf("%d", &(vet + i)->qtdade);

        printf("\n");
    }
    
}

int calculaQtidadeLivros(int tamanho, Usuario* vet)
{
    int livros_lidos_menores = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if ((vet + i)->idade < 10)
        {
            livros_lidos_menores += (vet + i)->qtdade;
        }
        
    }

    return livros_lidos_menores;
    
}

int calculaQtidadeMulheres(int tamanho, Usuario* vet)
{
    int mulheres_leitoras = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if((vet + i)->sexo == 'f')
        {
            if((vet + i)->qtdade >= 5)
            {
                mulheres_leitoras++;  
            }
        }
    }
    
    return mulheres_leitoras;
}

void mostra_resultados(int livros_da_criancada, int mulheres_leitoras)
{
    printf("A quantidade de livros lidos por criancas menores de 10 anos foi: %d.\n", livros_da_criancada);
    printf("A quantidade de mulheres que leu cinco ou mais livros foi: %d.\n", mulheres_leitoras);
}

int main()
{
    int qnt_users;
    printf("Quantos usuarios serao analisados? ");
    scanf("%d", &qnt_users);

    Usuario *all_users = malloc(qnt_users * sizeof(Usuario));

    leVetor(qnt_users, all_users);
    int livros_da_criancada = calculaQtidadeLivros(qnt_users, all_users);
    int mulheres_leitoras = calculaQtidadeMulheres(qnt_users, all_users);

    mostra_resultados(livros_da_criancada, mulheres_leitoras);
}
