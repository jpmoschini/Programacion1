#include <stdio.h>
#include <stdlib.h>

int main()
{
    int horas, horasExtra, salario, totalHoras;

    printf("Ingrese la cantidad de horas trabajadas: ");

    scanf("%d", &horas);

    if (horas >= 40)
    {
        horasExtra = (horas - 40);
        salario = ((40*300) + (horasExtra*400));
    } else {
        salario = horas*300;
    }

    printf("El salario mensual es: $");
    printf("%d", salario);
    return 0;
}
