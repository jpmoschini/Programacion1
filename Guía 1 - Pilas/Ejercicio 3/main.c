#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    //Declarar variables
    Pila DADA, DISTINTOS, DESCARTE;

    //Inicializar pilas
    inicpila(&DADA);
    inicpila(&DISTINTOS);
    inicpila(&DESCARTE);

    //Leer datos para ingresar  a las pilas
    leer(&DADA);
    leer(&DADA);
    leer(&DADA);
    leer(&DADA);
    leer(&DADA);

    //Recorrer la pila mientras no esté vacía
        while (!pilavacia(&DADA))
        {
            //Si el elemento es distinto a  a 8
            if (tope(&DADA) != 8)
            {
                //Desapilo y apilo en distintos
                apilar(&DISTINTOS, desapilar(&DADA));
            } else
            {
                //Sino apilo en descarte
                apilar(&DESCARTE, desapilar(&DADA));
            }
        }



    //Mostrar las pilas
    printf("\nLa pila de distintos es: \n");
    mostrar(&DISTINTOS);
    printf("\nLa pila de descarte es: \n");
    mostrar(&DESCARTE);
    return 0;
}
