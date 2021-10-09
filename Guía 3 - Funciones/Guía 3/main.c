#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Prototipado
void leerMuchos();
void pasarPila();
void pasarPilaOrdenada();
int buscarMenor();
int generarOrdenada();

///Main
int main()
{
    Pila pila1, pila2;
    inicpila(&pila1);
    inicpila(&pila2);
    printf("Hello world!\n");

    ///Ejercicio 1
    leerMuchos(&pila1);
    mostrar(&pila1);

    ///Ejercicio 2
    //pasarPila(&pila1, &pila2);
    //mostrar(&pila1);
    //mostrar(&pila2);


    ///Ejercicio 3
    //pasarPilaOrdenada(&pila1, &pila2);
    //mostrar(&pila2);

    ///Ejercicio 4
    //buscarMenor(&pila1);
    //mostrar(&pila1);

    ///Ejercicio 5
    //generarOrdenada(&pila1, &pila2);
    //mostrar(&pila2);

    ///Ejercicio 6


    return 0;
}

///Funciones de cada ejercicio

///Ejercicio 1
void leerMuchos (Pila * pila)
{
    char letra='n';

    printf("\nDesea cargar un elemento? Ingrese s= si o n= no: ");
    fflush(stdin);
    scanf("%c", &letra);

    while (letra=='s')
    {
        leer(pila);
        printf("\nDesea cargar un elemento? Ingrese s= si o n= no: ");
        fflush(stdin);
        scanf("%c",&letra);
    }
}

///Ejercicio 2
void pasarPila(Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

///Ejercicio 3
void pasarPilaOrdenada(Pila *origen, Pila *destino)
{
    Pila aux;
    inicpila(&aux);
    pasarPila(origen, &aux);
    pasarPila(&aux, destino);
}

///Ejercicio 4
int buscarMenor(Pila *origen)
{
    Pila aux;
    inicpila(&aux);
    int menorvalor = 0;

    if (!pilavacia(origen))
    {
        menorvalor = desapilar(origen);
        while (!pilavacia(origen))
        {
            if (menorvalor < tope(origen))
            {
                //apilar(origen, menorvalor);
                apilar(&aux, desapilar(origen));
            } else
                {
                    apilar(&aux, menorvalor);
                    menorvalor = desapilar(origen);
                }
        }
    } else printf("\nLa pila de origen está vacía");

    pasarPila(&aux, origen);
    printf("%i", menorvalor);

    return menorvalor;
}

///Ejercicio 5
int generarOrdenada(Pila *origen, Pila *destino)
{
    Pila intermedia;
    inicpila(&intermedia);

    while (!pilavacia(origen))
    {
        apilar(destino, buscarMenor(origen));
    }
    //mostrar(&intermedia);
    //pasarPila(&intermedia, destino);
    return destino;
}

///Ejercicio 6
