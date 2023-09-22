#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y)
{
    return x>=x0 && x<=x1 && y>=y0 && y<=y1;
}

int main(){
    
    int x0, y0;
    printf("Insira as coordenadas do ponto inferior esquerdo: ");
    scanf("%d %d", &x0, &y0);

    int x1, y1;
    printf("Insira as coordenadas do ponto superior direito: ");
    scanf("%d %d", &x1, &y1);

    int x, y;
    printf("Insira as coordenadas do ponto que voce quer analisar: ");
    scanf("%d %d", &x, &y);

    if(dentro_ret(x0, y0, x1, y1, x, y))
    {
        printf("Esta dentro do retangulo.\n");
    }

    else
    {
        printf("Esta fora do retangulo.\n");
    }
}
