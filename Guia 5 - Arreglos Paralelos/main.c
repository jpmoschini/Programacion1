#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <malloc.h>

///Prototipado de funciones
int cargadorArreglosParalelos();


int main()
{
    int legajos[20];
    char nombres[20][30];
    int anios[20];
    int tamanio = 0;
    int *a;
    int cantidad = 1;
    int nuevotamano = 0;
    int ubicacionPuntero = 0;
    a = (int *) malloc(cantidad * sizeof(int));

    //tamanio = cargadorArreglosParalelos(legajos, nombres, anios);
    //ejercicio2(legajos, tamanio);
    //ejercicio3(legajos, nombres, anios, tamanio);

    //mostrarRegistros (legajos, nombres, anios, tamanio);
    printf("\nIngrese el nuevo tamano para el arreglo; ");
    fflush(stdin);
    scanf("%i", &nuevotamano);
    ubicacionPuntero = redimensionarArregloDinamico(a, cantidad, nuevotamano);
    printf("\nEl valor del puntero donde empieza a escribir en el arreglo es: %i", ubicacionPuntero);
    system("pause");


    return 0;
}

///Funciones y subfunciones

///EJERCICIO 1
int cargadorArreglosParalelos(int leg[], char nom[][30], int ani[]) ///Crear una función que los cargue, hasta que el usuario lo decida.
{
    int elementosCargados = 0;
    char selector = 's';
    int i = 0;
    for (i = 0; selector == 's'; i++)
    {
        //Cargo en legajo
        printf("\nIngrese el número de legajo: ");
        fflush(stdin);
        scanf("%i", &leg[i]);
        //Cargo en nombre
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(&nom[i][0]);
        //Cargo en años
        printf("\nIngrese la edad: ");
        fflush(stdin);
        scanf("%i", &ani[i]);

        printf("\nIngrese 's' para cargar otro numero al arreglo o 'n' para salir: ");
        fflush(stdin);
        scanf("%c", &selector);
    }
    printf("\nYa cargaste %i numeros (en la funcion)\n", i);
    elementosCargados = i;

    return elementosCargados;
}


///EJERCICIO 2 ///Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor.
int devolverPosicion(int arr1[], int valor, int validos)
{
    int flag = 0;
    int i = 0;
    for (i = 0; (i <= validos) && (flag == 0); i++)
    {
        if (valor == arr1[i])
        {
            flag = 1;
        }else flag = 0;
    }
    printf("\n(comprobacion)el subindice 'i' esta en devolverPosicion en el valor  %i", i);
    return i-1;
}
int ejercicio2(int arr1[], int validos)
{
    int resultado = 0;
    int valor = 0;
    printf("\nIngrese el valor a buscar en los arreglos: ");
    fflush(stdin);
    scanf("%i", &valor);
    resultado = devolverPosicion(arr1, valor, validos);
    printf("\nEl indice del valor que ingresaste es: %i\n", resultado);
    return resultado;
}


///EJERCICIO 3 ///Hacer una función que reciba como parámetro todos los arreglos y encuentre el nombre correspondiente a un determinado legajo y lo imprima por pantalla. Se debe invocar la función 2.
void ejercicio3(int leg[], char nom[][30], int ani[], int validos)
{
    int buscador = 0;
    buscador = ejercicio2(leg, validos);
    //printf("%s", nom[buscador]);
    printf("\nEl nombre correspondiente al indice = %i, es: %s", buscador, nom[buscador]);
}


///EJERCICIO 4
int posicionMenor(int leg[ ], int cantVal, int u){
int menor = leg[u];
int posMenor = menor;
for(int index = u + 1; index < cantVal; index ++){
if(menor < leg[index]){
menor = leg[index];
posMenor = index;
}
}
return posMenor;
}
void intercambioPalabra(char pal[ ][30], int i, int j){
char aux[30];
strcpy(aux, pal[i]);
strcpy(pal[i], pal[j]);
strcpy(pal[j], aux);
}
void intercambioEntero(int numero[ ], int i, int j){
int aux = numero[i];
numero[i] = numero[j];
numero[j] = aux;
}
void ordenacionSeleccion(int leg[ ], char nombre[ ][30], int anio[ ], int cantVal ) {
//los tres arreglos tienen la misma cantidad de elementos válidos
int posMenor;
int i=0;
while(i<cantVal - 1){ /// llego hasta la anteúltima posición
posMenor = posicionMenor(leg, cantVal, i);
intercambioPalabra(nombre, posMenor, i);
intercambioEntero(leg, posMenor, i);
intercambioEntero(anio, posMenor, i);
i++;
}
printf("%s", nombre[1]);
}


///Ejercicio5 ///Mostrar por pantalla los 3 arreglos pero de a un “registro” por vez.
void mostrarRegistros (int leg[], char nom[][30], int ani[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        printf("\n%i", leg[i]);
        printf("\n%s", nom[i]);
        printf("\n%i", ani[i]);
    }

}

///EJERCICIO 7
/// Hacer una función que reciba un arreglo dinámico por parámetro, la cantidad de elementos
///válidos del mismo, y un valor que indique el nuevo tamaño que se le quiere dar a dicho
///arreglo. La función debe redimensionar el arreglo (usar la función realloc) y retornar el puntero
///a dicho espacio de memoria. Investigar el uso de la función realloc.
int redimensionarArregloDinamico(int arrDin[], int validos, int nuevaDim)
{
    nuevaDim = realloc(arrDin, nuevaDim);
    return nuevaDim;
}
