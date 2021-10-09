#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2, resultado;

    printf("Ingrese dos números separados por enter: ");

    scanf("%f", &num1);
    scanf("%f", &num2);

    printf("los números son:  %0.2f y %0.2f", num1, num2);

    if (num1 == num2) {
        resultado = num1 * num2;
    }
    else if (num1 > num2) {
                resultado = num1 - num2;
            }
    else {
        resultado = num1 + num2;
    }
    printf("\nEl resultado es: %0.2f", resultado);

    return 0;
}
