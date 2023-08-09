#include <stdio.h>
#include <string.h>

struct triangulo
{
    int ladoA;
    int ladoB;
    int ladoC;
    char ehTriangulo;
    char tipo[20];
};
typedef struct triangulo Triangulo;

Triangulo verificaTriangulo (Triangulo t)
{
    if (t.ladoA < (t.ladoB + t.ladoC) && t.ladoB < (t.ladoA + t.ladoC) && t.ladoC < (t.ladoA + t.ladoB))
    {
        t.ehTriangulo = 's';
    }

    else
    {
        t.ehTriangulo = 'n';
    }

    if (t.ladoA == t.ladoB || t.ladoA == t.ladoC || t.ladoB == t.ladoC)
    {
        if (t.ladoA == t.ladoB && t.ladoA == t.ladoC)
        {
            strcpy(t.tipo, "Equilatero");
        }

        else
        {
            strcpy(t.tipo, "Isosceles");
        }
        
    }

    else
    {
        strcpy(t.tipo, "Escaleno");
    }

    return t;
    
}

int main(){
    
    Triangulo tri;
    printf("Digite o tamanho dos tres lados do triangulo: ");
    scanf("%d %d %d", &tri.ladoA, &tri.ladoB, &tri.ladoC);

    tri = verificaTriangulo(tri);

    if (tri.ehTriangulo == 's')
    {
        printf("Forma triangulo %s.", tri.tipo);
    }

    else
    {
        printf("Nao forma triangulo.");
    }
    
}
