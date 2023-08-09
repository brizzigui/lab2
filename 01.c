#include <stdio.h>

#define PI 3.14

float get_radius()
{
    printf("Qual o raio da esfera? ");
    int radius;
    scanf("%d", &radius);
    return radius;
}

void calc_esfera(float r, float *area, float *volume)
{
    *area = 4 * PI * r * r;
    *volume = (4/3) * PI * r * r * r;
}

void show_info(float area, float volume)
{
    printf("Area da esfera: %.2f\n", area);
    printf("Volume da esfera: %.2f\n", volume);
}

int main(){
    float radius = get_radius();
    float area, volume;
    calc_esfera(radius, &area, &volume);

    show_info(area, volume);

}
