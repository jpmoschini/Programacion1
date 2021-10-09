#include <stdio.h>
#include <stdlib.h>

int main()
{
    float compra;
    printf("Ingrese el valor total de los productos: ");
    scanf("%f", &compra);
    compra = (compra - compra*0.15);
    printf("El precio a pagar es: %f", compra);
    return 0;
}
