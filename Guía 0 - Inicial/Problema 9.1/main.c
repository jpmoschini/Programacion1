#include <stdio.h>
#include <stdlib.h>

int main()
{
//Declaro las variables
    int num1, num2, num3, mayor = 0;

//Presentación de las instrucciones por pantalla
    printf("Ingrese tres números separados por enter: \n");

//Lectura de elementos ingresados por el usuario
    fflush(stdin);
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    printf("%d y %d y %d", num1, num2, num3);

//Condicionales para determinar el orden de números
    if (num1 >= num2) {
        if (num1 >= num3) {
            printf("\nEl mayor es: %d", num1);
        } else printf("\nEl mayor es: %d", num3);
    } else {
        if (num2 >= num3) {
            printf("\nEl mayor es: %d", num2);
        } else printf("\nEl mayor es: %d", num3);
    }

//

    return 0;
}
