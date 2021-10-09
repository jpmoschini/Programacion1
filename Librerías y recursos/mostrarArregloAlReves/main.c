#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ARREGLO [10] = {3, 5,6};
    mostrarArregloAlReves(ARREGLO[10]);
    return 0;
}
void mostrarArregloAlReves(char *cadena)
{
    for ( int i = sizeof(cadena); i >= 0; i--)
    {
        printf("%c - ", cadena[i]);
    }

}

