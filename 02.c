#include <stdio.h>

struct retangulo
{
    float base;
    float altura;
    float perimetro;
    float area;
};

typedef struct retangulo Retangulo;

void calculaPeriArea (Retangulo ret)
{
    ret.area = ret.base * ret.altura;
    ret.perimetro = ret.base * 2 + ret.altura * 2;
    printf("Area do retangulo: %.2f\n", ret.area);
    printf("Perimetro do retangulo: %.2f\n", ret.perimetro);
    printf("\n");
}

void get_info(Retangulo *ret)
{
    printf("Digite a base e a altura deste retangulo: ");
    scanf("%f %f", &ret->base, &ret->altura);
}

int main()
{
    Retangulo ret[5];

    for (int i = 0; i < 5; i++)
    {
        get_info(&ret[i]);
        calculaPeriArea(ret[i]);
    }
     
}
