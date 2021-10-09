#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///Prototipado
void menu();
int opciones();
void funcion_x();


int main()
{
    menu();
    return 0;
}
///Menu de opciones y subfunciones
void menu()//int argc, char *argv[])
{
    int seleccion;

    do
    {
        seleccion = opciones();
        switch(seleccion)
        {
        case 1:
            funcion_x();
            break;
        case 2:
            funcion_x();
            break;
        case 3:
            funcion_x();
            break;
        case 4:
            funcion_x();
            break;
        case 5:
            funcion_x();
            break;
        case 6:
            funcion_x();
            break;
        case 7:
            funcion_x();
            break;
        case 8:
            funcion_x();
            break;
        case 9:
            funcion_x();
            break;
        case 10:
            funcion_x();
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
