#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
int main()
{
    printf("Hello world!\n");
   /* Pila p;
    inicpila(&p);
    apilar(&p, 5);
    apilar(&p, 5);
    apilar(&p, 5);
    apilar(&p, 5);
    apilar(&p, 5);
    mostrar(&p);*/

    //Declarar variables
    Pila DADA, AUX1, AUX2;

    //Inicializar pilas
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);

    //Repetir 5 veces
        for (int i = 0; i < 5; i++)
        {
            //Cargar dato a pila DADA
            int dato = 0;
            printf("Ingrese un elemento para apilar a DADA: ");
            fflush(stdin);
            scanf("%d", &dato);
            apilar(&DADA, dato);
        }

    //Repetir 3 veces
        for (int i = 0; i < 3; i++)
        {
            //Desapilar DADA en AUX1
            apilar(&AUX1, desapilar(&DADA));
        };
    //Repetir 2 veces
        for (int i = 0; i < 2; i++)
        {
            //Desapilar DADA en AUX2
            apilar(&AUX2, desapilar(&DADA));
        };


    //Mostrar las pilas
    mostrar(&DADA);
    mostrar(&AUX1);
    mostrar(&AUX2);
    return 0;
}
