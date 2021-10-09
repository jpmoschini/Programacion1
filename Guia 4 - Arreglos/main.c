///Guía 4 - Arreglos
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "string.h"

///Constantes para el manejo de los arreglos
#define ELEMENTOS 24
#define ELEMENTOS2 100


///Prototipado
void menu();
int opciones();
void funcion_x();
int ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
int cargadorArreglos();
float sumadorElementos();
void ejercicio6();
void cargadorCadenas();
void ejercicio7();


int main()
{
    int arreglo1[ELEMENTOS];
    float arreglo2[ELEMENTOS2];
    char cadena1[ELEMENTOS];
    Pila pila1;
    inicpila(&pila1);

    menu(&arreglo1, &pila1, &arreglo2, &cadena1);
    return 0;
}
///Menu de opciones y subfunciones
void menu(int *unArreglo, Pila *unaPila, float *otroArreglo, char *unaCadena)//int argc, char *argv[])
{
    int seleccion;

    do
    {
        seleccion = opciones();
        switch(seleccion)
        {
        case 1:;
            int j = ejercicio1(unArreglo);

            printf("\Cargaste %i numeros", j);
            printf("\nEl elemento 1 del arreglo cargado es: %i\n", unArreglo[1]);
            system("pause");
            break;
        case 2:
            ejercicio2(unArreglo, j);
            system("pause");
            break;
        case 3:
            ejercicio3(unArreglo, j);
            system("pause");
            break;
        case 4:
            ejercicio4(unArreglo, j, unaPila);
            system("pause");
            break;
        case 5:
            ejercicio5(otroArreglo);
            system("pause");
            break;
        case 6:
            ejercicio6(unaCadena);
            system("pause");
            break;
        case 7:
            ejercicio7(unaCadena);
            system("pause");
            break;
        case 8:
            funcion_x();
            system("pause");
            break;
        case 9:
            funcion_x();
            system("pause");
            break;
        case 10:
            funcion_x();
            system("pause");
            break;
        case 0:
            printf("\n\nSALIENDO\n");

            break;
        }

    }
    while(seleccion!=0);

    system("PAUSE");
}

int opciones()
{
    int elegida;
    system("cls");
    printf("\nOPCIONES\n");
    printf("\n1-****");
    printf("\n2-****");
    printf("\n3-****");
    printf("\n4-****");
    printf("\n5-****");
    printf("\n6-****");
    printf("\n7-****");
    printf("\n8-****");
    printf("\n9-****");
    printf("\n10-****");
    printf("\n0-SALIR");
    printf("\n\nINGRESE UNA PARA CONTINUAR: ");
    scanf("%d",&elegida);
    return elegida;
}
void funcion_x()
{
    printf("\nAca va la opcion elegida: ");
    system("pause");
}
///Fin del menu y subfunciones


///Funciones

int ejercicio1(int *unArreglo)
{
    int elementosCargados = 0;
    printf("\nEjercicio 1: \n");
    char selector = 's';
    int cargador = 0;
    int i = 0;
    for (i = 0; selector == 's'; i++)
    {
        printf("\nIngrese un numero entero al arreglo: ");
        fflush(stdin);
        scanf("%i", &cargador);
        unArreglo[i] = cargador;
        printf("\nIngrese 's' para cargar otro numero al arreglo o 'n' para salir: ");
        fflush(stdin);
        scanf("%c", &selector);
    }
    printf("\nYa cargaste %i numeros (en la funcion)\n", i);
    elementosCargados = i;

    return elementosCargados;
}

void ejercicio2(int *unArreglo, int *j)
{
    for (int i = 0; i < j; i++)
    {
        printf("%i, ", unArreglo[i]);
    }
}

void ejercicio3(int *unArreglo, int *j)
{
    int suma = 0;
    for (int i = 0; i <j; i++)
    {
        suma = suma + unArreglo[i];
    }
    printf("\nLa suma de los elementos de la matriz es: %i\n", suma);
}

void ejercicio4(int *unArreglo, int *j, Pila *unaPila)
{
    for (int i = 0; i < j; i++)
    {
        apilar(unaPila, unArreglo[i]);
    }
    mostrar(unaPila);
}
void ejercicio5(float *otroArreglo)
{
    int cantidadCargada = cargadorArreglos(otroArreglo);
    printf("\nLa suma de los elementos del arreglo es: %0.2f \n", sumadorElementos(otroArreglo, cantidadCargada));

}
int cargadorArreglos(float *arregloFloat)
{
    int elementosCargados = 0;
    char selector = 's';
    int i = 0;
    for (i = 0; selector == 's'; i++)
    {
        printf("\nIngrese un numero al arreglo: ");
        fflush(stdin);
        scanf("%f", &arregloFloat[i]);
        printf("\nIngrese 's' para cargar otro numero al arreglo o 'n' para salir: ");
        fflush(stdin);
        scanf("%c", &selector);
    }
    printf("\nYa cargaste %i numeros (en la funcion)\n", i);
    elementosCargados = i;

    return elementosCargados;
}
float sumadorElementos(float *arregloFloat, int *valorFinal)
{
    float sumaFloat = 0;
    for (int i = 0; i < valorFinal; i++)
    {
        sumaFloat = sumaFloat + arregloFloat[i];
    }
    return sumaFloat;
}

void ejercicio6(char *cadena)
{
    char chequeando;
    int validador;

    cargadorCadenas(cadena);
    printf("\nIngrese una letra para comparar con la cadena: ");
    fflush(stdin);
    scanf("%c", &chequeando);

    for (int i = 0; i < ELEMENTOS; i++)
    {
        if (chequeando == cadena[i])
        {
            printf("\nHay coincidencia en la posicion %i,\n" , i);
        } else printf("\nNO hay coincidencia\n");
    }
}
void cargadorCadenas(char *cadena)
{
    printf("\ningrese una palabra, o frase de max 28 caracteres: ");
    fflush(stdin);
    gets (cadena);
}

void ejercicio7(char *cadena)
{
    char valorcito;
    int i = 0;
    printf("\nIngrese un caracter para introducir en el arreglo, y a continuacion los demas caracteres que tienen que estar ordenados alfabeticamente: ");
    fflush(stdin);
    scanf("%c", &valorcito);
    cargadorCadenas(cadena);

    for ( i = sizeof(cadena); i >= 0; i--)
    {
        printf("%c - ", cadena[i]);
    }

}
