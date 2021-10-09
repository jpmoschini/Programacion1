#include <stdio.h>
#include <stdlib.h>

int main()
{
    //definir variables (nota suma y promedio)
    float notai, sumanotas, promedio = 0;

    //repetir 7 veces
    for (int i = 0; i < 7; i++)
    {
        printf("\nIngrese la nota %d:", i+1);
        //leer notas
        fflush(stdin);
        scanf("%f", &notai);
        //sumar nota(i) a la nota anterior
        sumanotas += notai;
    }

    //dividir la suma por 7
    promedio = sumanotas / 7;
    //mostrar resultado por pantalla
    printf("El promedio de notas es: %0.2f", promedio);

    return 0;
}
