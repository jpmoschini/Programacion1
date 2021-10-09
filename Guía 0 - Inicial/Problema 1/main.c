#include <stdio.h>
#include <stdlib.h>

int main()
{
    int inversion = 0;
    printf("Ingrese el valor a invertir: ");
    scanf("%d", &inversion);
    int ganancia = (inversion + inversion*0.02);
    printf("La ganancia luego de un mes es: %d", ganancia);
    return 0;
}
