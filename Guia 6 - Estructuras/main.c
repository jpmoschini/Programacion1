#include <stdio.h>
#include <stdlib.h>

#define ELEMENTOS 20

typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

int main()
{
    stAlumno arregloAlumnos[ELEMENTOS];
    stAlumno datoEjercicio6 = {3, "pepito", "m"};
    //Ejercicio 1
    int cargados = cargadorEstructuras(arregloAlumnos);
    printf("%s", arregloAlumnos[0].nombre);
    //printf("%i", cargados);

    //Ejercicio 2
    //mostrarArreglo (arregloAlumnos, cargados);

    //Ejercicio 3
    //mostrarDatos (arregloAlumnos, cargados);

    //Ejercicio 5
    //char selectorGenero = 'm';
    //mostrarSegunGenero(arregloAlumnos, cargados, selectorGenero);

    //Ejercicio 6
    cargados = insertarOrdenado(arregloAlumnos, cargados, datoEjercicio6);

    mostrarArreglo(arregloAlumnos, cargados);

    return 0;
}

///Ejercicio 1 Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
int cargadorEstructuras(stAlumno unArreglo[])
{
    int elementosCargados = 0;
    char selector = 's';
    int i = 0;
    for (i = 0; selector == 's'; i++)
    {
        printf("\nIngrese matrícula, luego nombre y luego genero del alumno %i: ", i+1);
        fflush(stdin);
        scanf("%i", &unArreglo[i].matricula);
        fflush(stdin);
        gets(unArreglo[i].nombre);
        fflush(stdin);
        scanf("%c", &unArreglo[i].genero);
        printf("\nIngrese 's' para cargar otro numero al arreglo o 'n' para salir: ");
        fflush(stdin);
        scanf("%c", &selector);
    }
    printf("\nYa cargaste %i numeros (en la funcion)\n", i);
    elementosCargados = i;

    return elementosCargados;
}

///Ejercicio 2 Hacer una función que muestre un arreglo de alumnos por pantalla, modularizar.
void mostrarArreglo (stAlumno unArreglo[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf("\nAlumno %i - ", i);
        printf("\Matricula: %i, ", unArreglo[i].matricula);
        printf("\Nombre: %s, ", unArreglo[i].nombre);
        printf("\Genero: %c", unArreglo[i].genero);
    }
}

///Ejercicio 3 Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
void mostrarDatos (stAlumno unArreglo[], int validos)
{
    int buscador = 0;
    printf("\nIngrese la matricula del alumno: ");
    fflush(stdin);
    scanf("%i", &buscador);
    for (int i = 0; i < validos; i++)
    {
        if (buscador == unArreglo[i].matricula)
        {
            printf("\n%i, %s, %c", unArreglo[i].matricula, unArreglo[i].nombre, unArreglo[i].genero);
            i = i + 100;
        }
    }
}

///Ejercicio 5 Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.
void mostrarSegunGenero(stAlumno unArreglo[], int validos, char elegido)
{
    for (int i = 0; i < validos; i++)
    {
        if (elegido == unArreglo[i].genero)
        {
            printf("\n%i, %s, %c", unArreglo[i].matricula, unArreglo[i].nombre, unArreglo[i].genero);
        }
    }
}

///Ejercicio 6 Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
int insertarOrdenado(stAlumno unArreglo[],int validos, stAlumno unDato)
{
    for (int i = validos; i >= 0; i--)
    {
        if (unDato.matricula <= unArreglo[i].matricula)
        {
            unArreglo[i+1] = unArreglo[i];
            unArreglo[i] = unDato;
        }else
        unArreglo[i+1] = unDato;
        break;
    }
    validos = validos +1;
    return validos;
}

