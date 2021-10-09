#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cantidad = 0;
    int arregloEnteros [20];

    cantidad = ingresaValoresArreglo(arregloEnteros, 20, cantidad);
    printf("%i", cantidad);
    mostrarArreglo(arregloEnteros, cantidad);
    return 0;
}

int ingresaValoresArreglo(int A [], int dimension, int validos)
{
    char control = 's';

    while(control == 's' && validos < dimension)
    {
        printf("\nIngrese un valor para el arreglo: ");
        fflush(stdin);
        scanf("&d", &A[validos]);
        validos++;
        printf("\nDesea ingresar otro elemento? ingrese 's' para continuar  o 'n' para terminar\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}
void mostrarArreglo (int A[], int validos)
{
    int i = 0;
    printf("\nArreglo: ");
    while (i < validos)
    {
        printf("%d -", A[i]);
        i++;
    }
}
