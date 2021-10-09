#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "pila.h"


#define ESPACIO printf("\n");

//typedef struct
//{
//    int legajo;
//    char nombreYapellido[30];
//    int edad;
//
//}stAlumno;
typedef struct
{
    int matricula;
    char nombreYapellido[30];
    int edad;

}stAlumno;



int main()
{
    char comprobacion;
    int cantRegistros;

    Pila pilaAlumnos;

    inicpila(&pilaAlumnos);

    stAlumno arregloAlumnos[30];

    ///MUESTRO LA ULTIMA MATRICULA

    printf("Ultima matricula: %d \n", devolverUltimaMatricula("alumnos.bin"));

    ESPACIO

    ///AGREGO O NO ALUMNOS AL ARCHIVO

    printf("Quiere agregar alumnos al archivo? (s/n) \n");
    fflush(stdin);
    comprobacion= getch();

    ESPACIO

    if (comprobacion=='s')
    {
        cargarAlumnos("alumnos.bin");
    }

    ///MUESTRO O NO EL ARCHIVO DE ALUMNOS

    printf("Quiere ver todos los alumnos cargados hasta el momento? (s/n) \n");
    fflush(stdin);
    comprobacion= getch();

    ESPACIO

    if (comprobacion=='s')
    {
        mostrarAlumnos("alumnos.bin");
    }


    cantRegistros= devolverCantidadRegistros("alumnos.bin");

    ///CARGO O NO A UNA PILA LOS LEGAJOS DE LOS MAYORES DE EDAD Y LA MUESTRO

    printf("Quiere pasar los alumnos mayores a una pila? (s/n) \n");
    comprobacion=getch();

    ESPACIO

    if (comprobacion=='s')
    {
        cargarEnPilaMatriculaMayores("alumnos.bin", &pilaAlumnos);

        mostrar(&pilaAlumnos);
    }

    ///MUESTRO O NO LOS ALUMNOS POR RANGO DE EDAD

    printf("Quiere mostrar los alumnos por rango de edad? (s/n) \n");
    comprobacion=getch();

    ESPACIO

    if (comprobacion=='s')
    {
        int desde=0;
        int hasta=0;

        printf("Ingrese el rango de edad, primero desde y luego hasta \n");
        fflush(stdin);
        scanf("%d", &desde);
        fflush(stdin);
        scanf("%d", &hasta);

        mostrarAlumnosPorRangoEdad("alumnos.bin", desde, hasta);

        ESPACIO
    }

    ///MUESTRO O NO LOS DATOS DE LOS ALUMNOS MAYORES DE EDAD

    printf("Quiere mostrar los alumnos mayores de edad? (s/n) \n");
    comprobacion=getch();

    ESPACIO

    if (comprobacion=='s')
    {
        mostrarDatosAlumnosMayores("alumnos.bin");
    }

    ///CARGO O NO LOS ALUMNOS A UN ARREGLO Y LO MUESTRO

    printf("Quiere pasar los datos a un arreglo? (s/n) \n");
    comprobacion=getch();

    ESPACIO

    if (comprobacion=='s')
    {
        cargarArchivoEnArreglo("alumnos.bin", arregloAlumnos);

        mostrarArregloAlumnos(arregloAlumnos, cantRegistros);
    }

    ///MODIFICO O NO LOS REGISTROS

    printf("Quiere modificar algun registro? (s/n) \n");
    comprobacion=getch();

    ESPACIO

    if (comprobacion=='s')
    {
        int opcion;

        printf("Todo:0  Matricula:1  Nombre:2  Edad:3 \n");
        scanf("%d", &opcion);

        modificarRegistros("alumnos.bin", opcion);
    }

    ///BORRO O NO EL ARCHIVO

    printf("Desea borrar el archivo? (s/n) \n");
    comprobacion=getch();

    if (comprobacion=='s')
    {
        archivoEnBlanco("alumnos.bin");
    }

    return 0;
}

//FUNCIONES


void cargarAlumnos (char ruta[20]) ///EJERCICIO 1
{
    stAlumno alumno;
    char teclaUsuario='s';
    FILE* archivoAlumnos= fopen(ruta, "ab");

    if(archivoAlumnos!=0)
    {
       for (int i=0; teclaUsuario=='s'; i++)
       {

        printf("Ingrese numero de matricula: ");
        fflush(stdin);
        scanf("%d", &alumno.matricula);

        printf("Ingrese nombre y apellido: ");
        fflush(stdin);
        gets(&alumno.nombreYapellido);

        printf("Ingrese la edad: ");
        fflush(stdin);
        scanf("%d", &alumno.edad);

        fwrite(&alumno, sizeof(stAlumno), 1, archivoAlumnos);

        ESPACIO

        printf("Quiere seguir cargando alumnos? (s/n) \n");
        fflush(stdin);
        teclaUsuario=getch();

        ESPACIO

       }

       fclose(archivoAlumnos);
    }
}

void mostrarAlumno(stAlumno alumno) ///EJERCICIO 2
{

    printf("Matricula: %d \n", alumno.matricula);
    printf("Nombre y apellido: %s \n", alumno.nombreYapellido);
    printf("Edad: %d \n", alumno.edad);

    ESPACIO

    printf("----------------------------");

    ESPACIO

}

void mostrarAlumnos (char ruta[20]) ///
{
    stAlumno alumno;

    FILE* archivoAlumnos=fopen(ruta, "rb");

    if (archivoAlumnos!=0)
    {

        while(fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0)
        {
            mostrarAlumno(alumno);

            ESPACIO
        }

        fclose(archivoAlumnos);
    }
}

int devolverCantidadRegistros (char ruta[20])///EJERCICIO 3
{
    int cantRegistros;

    FILE* archivoAlumnos=fopen(ruta, "rb");

    if (archivoAlumnos!=0)
    {
        fseek(archivoAlumnos, 0 , SEEK_END);

        cantRegistros=ftell(archivoAlumnos) / sizeof(stAlumno);

    }

    return cantRegistros;
}

void cargarEnPilaMatriculaMayores(char ruta[20], Pila* pila)
{
    stAlumno alumno;

    FILE* archivoAlumnos=fopen(ruta, "rb");

    if (archivoAlumnos!=0)
    {
        while(fread((&alumno), sizeof(stAlumno), 1, archivoAlumnos)>0)
        {
            if (alumno.edad >= 18)
            {
                apilar(pila, alumno.matricula);
            }
        }

        fclose(archivoAlumnos);
    }
}

void archivoEnBlanco (char ruta[20])
{
    stAlumno alumno;

    FILE* archivoAlumnos=fopen(ruta, "wb");
}

int devolverUltimaMatricula (char ruta[20])
{
    int matriculaMayor=0;
    stAlumno alumno;

    FILE* archivoAlumnos= fopen(ruta, "rb");

    if(archivoAlumnos!=0)
    {
        rewind(archivoAlumnos);

        while (fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0)
        {
            if (matriculaMayor < alumno.matricula)
            {
                matriculaMayor=alumno.matricula;
            }
        }

        fclose(archivoAlumnos);
    }

    return matriculaMayor;
}

int devolverMenorMatricula(char ruta[20])
{
    int matriculaMenor= devolverUltimaMatricula(ruta);
    stAlumno alumno;

    FILE* archivoAlumnos= fopen(ruta, "rb");

    if(archivoAlumnos!=0)
    {
        rewind(archivoAlumnos);

        while (fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0)
        {
            if (matriculaMenor > alumno.matricula)
            {
                matriculaMenor=alumno.matricula;
            }
        }

        fclose(archivoAlumnos);
    }

    return matriculaMenor;
}

void mostrarAlumnosPorRangoEdad(char ruta[20], int desde, int hasta)
{
    stAlumno alumno;

    FILE* archivoAlumnos= fopen(ruta, "rb");

    if (archivoAlumnos!=0)
    {
         rewind(archivoAlumnos);

         printf("---- Alumnos de entre %d y %d anios---- \n", desde, hasta);

         ESPACIO

         while (fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0)
         {
            if(alumno.edad >= desde && alumno.edad <= hasta)
            {
                printf("%s \n", alumno.nombreYapellido);
            }
         }

         fclose(archivoAlumnos);
    }
}

void mostrarDatosAlumnosMayores(char ruta[20])
{
    stAlumno alumno;

    FILE* archivoAlumnos= fopen(ruta, "rb");

    if (archivoAlumnos!=0)
    {
        rewind(archivoAlumnos);

        while (fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0)
         {
            if(alumno.edad >= 18)
            {
                mostrarAlumno(alumno);
            }
         }

        fclose(archivoAlumnos);
    }

}

void cargarArchivoEnArreglo (char ruta[20], stAlumno arregloAlumnos[30])
{

  int i=0;

  stAlumno alumno;

  FILE* archivoAlumnos= fopen("alumnos.bin", "rb");

  if (archivoAlumnos!=0)
  {
      rewind(archivoAlumnos);

      while(fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0)
      {
          arregloAlumnos[i].matricula=alumno.matricula;
          arregloAlumnos[i].edad=alumno.edad;
          strcpy(arregloAlumnos[i].nombreYapellido, alumno.nombreYapellido);

          i++;
      }

    fclose(archivoAlumnos);
  }
}

void mostrarArregloAlumnos(stAlumno arregloAlumnos[30], int validos)
{

    for(int i=0; i<validos; i++)
    {
        printf("Matricula: %d \n", arregloAlumnos[i].matricula);
        printf("Nombre y apellido: %s \n", arregloAlumnos[i].nombreYapellido);
        printf("Edad: %d \n", arregloAlumnos[i].edad);

        ESPACIO

        printf("-------------------------");

        ESPACIO
    }

}

void modificarRegistros (char ruta[30], int tipoDeModificacion)
{
    FILE* archivoAlumnos=fopen(ruta, "r+b");

    stAlumno alumno;

    int matricula;
    char nombre[30];
    int edad;
    int flag=0;

    if (archivoAlumnos!=0)
    {

        printf("Que alumno quiere modificar? (busqueda por matricula) \n");
        scanf("%d", &matricula);

        if(tipoDeModificacion==0) //todo
        {
            rewind(archivoAlumnos);
            while(fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0 && flag==0)
            {

                if(matricula==alumno.matricula)
                {
                    flag=1;
                }
            }

            if (flag==1)
            {
                printf("Ingrese nuevo numero de matricula: ");
                fflush(stdin);
                scanf("%d", &matricula);

                printf("Ingrese nuevo nombre y apellido: ");
                fflush(stdin);
                gets(nombre);

                printf("Ingrese la nueva edad: ");
                fflush(stdin);
                scanf("%d", &edad);

                alumno.matricula=matricula;
                strcpy(alumno.nombreYapellido, nombre);
                alumno.edad=edad;
            }

            fseek(archivoAlumnos, sizeof(stAlumno)* -1, SEEK_CUR);

            fwrite(&alumno, sizeof(stAlumno), 1, archivoAlumnos);
        }

        else if(tipoDeModificacion==1) //matricula
        {
            rewind(archivoAlumnos);
            while(fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0 && flag==0)
            {
                if(matricula==alumno.matricula)
                {
                  flag=1;
                }
            }

            if(flag=1)
            {
                printf("Ingrese nuevo numero de matricula: ");
                fflush(stdin);
                scanf("%d", &matricula);

                alumno.matricula=matricula;
            }

            fseek(archivoAlumnos, sizeof(stAlumno)* -1, SEEK_CUR);

            fwrite(&alumno, sizeof(stAlumno), 1, archivoAlumnos);
        }
        else if(tipoDeModificacion==2) //nombre y apellido
        {
            rewind(archivoAlumnos);
            while(fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0 && flag==0)
            {
                if(matricula==alumno.matricula)
                {
                    flag=1;
                }
            }

            if (flag=1)
            {
                printf("Ingrese nuevo nombre y apellido: ");
                fflush(stdin);
                gets(&nombre);

                strcpy(alumno.nombreYapellido, nombre);
            }

            fseek(archivoAlumnos, sizeof(stAlumno)* -1, SEEK_CUR);

            fwrite(&alumno, sizeof(stAlumno), 1, archivoAlumnos);
        }
        else if(tipoDeModificacion==3) //edad
        {
            rewind(archivoAlumnos);
            while(fread(&alumno, sizeof(stAlumno), 1, archivoAlumnos)>0 && flag==0)
            {
                if(matricula==alumno.matricula)
                {
                  flag=1;
                }
            }

            if (flag=1)
            {
                printf("Ingrese la nueva edad: ");
                fflush(stdin);
                scanf("%d", &edad);

                alumno.edad=edad;
            }

            fseek(archivoAlumnos, sizeof(stAlumno)* -1, SEEK_CUR);

            fwrite(&alumno, sizeof(stAlumno), 1, archivoAlumnos);
        }

        if(flag==0)
        {
            printf("No se encontro el registro \n");
        }

        fclose(archivoAlumnos);
    }
}
