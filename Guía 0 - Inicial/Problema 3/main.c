#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hombres, mujeres, suma;
    float promH = 0;
    float promM = 0;

    printf("ingrese el total de hombres, presione enter y luego el total de mujeres: " );

    scanf("%d", &hombres);
    scanf("%d", &mujeres);

    suma = (hombres + mujeres);
    promH = (hombres / suma)*100;
    promM = (mujeres / suma)*100;

    printf("%d", suma);
    printf("El promedio de hombres es: %f y el promedio de mujeres es: %f", promH, promM);

    return 0;
}
