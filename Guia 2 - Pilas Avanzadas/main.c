///Guía 3 - Funciones
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Prototipado
void leerMuchos();
void pasarPila();
void pasarPilaOrdenada();
int buscarMenor();
int generarOrdenada();
void insertarEnOrden();
int sumarValores();
int cantidadValores();
float division();
float calcularPromedios();

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
    //insertarEnOrden(&pila1, &pila2);

    ///Ejercicio 8
    //sumarDosPrimeros(&pila1);

    ///Ejercicio 9
    //int cantValores = cantidadValores(&pila1);
    //printf("\nLa cantidad de valores (en main) que ingresaste es: %i", cantValores);
    //int sumadeValores = sumarValores(&pila1);
    //printf("\nLa suma de los valores (en main) es: %i", sumadeValores);
    calcularPromedios(&pila1);

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
    //Pila intermedia;
    //inicpila(&intermedia);

    while (!pilavacia(origen))
    {
        apilar(destino, buscarMenor(origen));
    }
    //mostrar(&intermedia);
    //pasarPila(&intermedia, destino);
    return destino;
}

///Ejercicio 6
void insertarEnOrden(Pila *origen, Pila *destino)
{
    int elemento = 0;

    printf("\nIngrese un numero: ");
    fflush(stdin);
    scanf("%i", &elemento);

    apilar(origen, elemento);

    generarOrdenada(origen, destino);

    mostrar(destino);
}

///Ejercicio 7

///Ejercicio 8
int sumarDosPrimeros(Pila *origen)
{
    Pila aux;
    inicpila(&aux);
    int resultado = 0;
    int contador = 0;

    while (!pilavacia(origen) && (contador < 2))
    {
        resultado = resultado + tope(origen);
        apilar(&aux, desapilar(origen));
        contador++;
    }
    while (!pilavacia(&aux))
    {
        apilar(origen, desapilar(&aux));
    }

    printf("\nEl resultado de la suma de los dos primeros valores de la pila dada es: %i", resultado);
    return resultado;
}

///Ejercicio 9 (4 funciones para calcular el promedio)
float calcularPromedios (Pila *origen) //Función que hace el cálculo invocando a las otras tres y retorna el valor
{
    float resultado;
    resultado = division(sumarValores(origen), cantidadValores(origen));
    printf("\nEl resultado de la division (en la funcion) es: %0.2f", resultado);

    return resultado;
}

float division(int sumando, int divisor)
{
    float resultad = 0;
    resultad = ((sumando + 0.0) / divisor);
    return resultad;
}

int sumarValores(Pila pila1) //función que suma los valores de la pila, la paso por valor para no modificar la pila original
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&pila1))
    {
        suma = suma + desapilar(&pila1);
    }
    return suma;
}

int cantidadValores(Pila pila1) //función que calcula la cantidad de valores de la pila, la paso por valor para no modificar la pila original
{
    int cantidad = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&pila1))
    {
        apilar(&aux, desapilar(&pila1));
        cantidad ++;
    }
    return cantidad;
}
