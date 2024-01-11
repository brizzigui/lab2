#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct aluno
{
    float nota1;
    float nota2;
    int aulasAssistidas;
    float media;
    char status;
};
typedef struct aluno Aluno;

struct disciplina
{
    Aluno vet[5];
    int aulasMinistradas;
};
typedef struct disciplina Disciplina;

void le_notas(Aluno *user)
{
    printf("Insira a nota 1: ");
    scanf("%f", &user->nota1);

    printf("Insira a nota 2: ");
    scanf("%f", &user->nota2);

    printf("Insira o numero de aulas assistidas: ");
    scanf("%d", &user->aulasAssistidas);
}

void calc_media(Aluno *user)
{
    user->media = (user->nota1 + user->nota2) / 2;
}

bool frequencia(int aulas, int presencas)
{
    return (float)presencas / (float)aulas >= 0.75;
}

void checa_aprov(Aluno *user, Disciplina cadeira)
{
    if (user->media >= 6 && frequencia(cadeira.aulasMinistradas, user->aulasAssistidas))
    {
        user->status = 'A';
    }

    else
    {
        user->status = 'B';
    }
    
}

int le_info_disciplina()
{
    int aulas;
    printf("Quantas aulas foram ministradas nessa disciplina? ");
    scanf("%d", &aulas);

    return aulas;
}

void mostra_resultados(Aluno user)
{
    if (user.status == 'A')
    {
        printf("\nEsse aluno foi aprovado\n");
    }
    
    else
    {
        printf("\nEsse aluno foi reprovado\n");
    }

    printf("Sua media final foi de %.2f.\n\n", user.media);
}

int main(){
    
    Disciplina cadeira;
    cadeira.aulasMinistradas = le_info_disciplina(cadeira);

    for (int i = 0; i < 5; i++)
    {
        le_notas(&cadeira.vet[i]);
        calc_media(&cadeira.vet[i]);
        checa_aprov(&cadeira.vet[i], cadeira);
        mostra_resultados(cadeira.vet[i]);
    }
    
}
