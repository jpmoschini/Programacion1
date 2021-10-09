#include <stdio.h>
#include <stdlib.h>

int main()
{
    float compra, precio;

    printf("Ingrese el valor de su compra: ");

    scanf("%f", &compra);

    if (compra >= 5000)
    {
        precio = compra*0.8;
        printf("\nLa cantidad a pagar es: $");
        printf("%0.2f", precio);
    } else {
        printf("\nLa cantidad a pagar es $");
        printf("%0.2f", compra);
        }
    return 0;
}
