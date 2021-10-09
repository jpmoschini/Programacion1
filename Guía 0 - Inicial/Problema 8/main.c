#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numCamisas;
    float precioUnit, precioTotal;

    printf("ingrese la cantidad de camisas: ");
    scanf("%d", &numCamisas);

    printf("ingrese el precio unitario de las camisas: ");
    scanf("%f", &precioUnit);

    if (numCamisas >= 3)
    {
        precioTotal = (numCamisas * precioUnit)*0.8;
    } else
        {
            precioTotal = (numCamisas * precioUnit) *0.9;
        }

    printf("El precio total a pagar es: ");
    printf("%0.2f", precioTotal);

    return 0;
}
