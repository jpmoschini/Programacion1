#include <stdio.h>
#include <stdlib.h>

void ordenacionSeleccion();
int posicionMenor();
void insertar();

int main() {
   int A[] = {1,4,2,8,9,5,7,6,0,3};
   int B[] = {6,5.3,1,8,7,2,4};
   ordenacionSeleccion (A, 10);
   //ordenacionInsercion(B, 8);
   printf("%d", A[3]);
   system("pause");
   return 0;
}

///Ordenación por Selección

void ordenacionSeleccion (int A[], int c)
{
    int posmenor;
    int aux;
    int i = 0;
    while (i<c-1)
    {
        posmenor = posicionMenor(A,i,c);
        aux = A[posmenor];
        A[posmenor]=A[i];
        A[i]= aux;
        i++;
    }
}

int posicionMenor (int A[], int pos, int c)
{
    int menor = A[pos];
    int posmenor = pos;
    int i = pos +1;
    while (i<c)
    {
        if (menor > A[i])
        {
            menor = A[i];
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

///Ordenación por Inserción

void insertar(int B[], int u, int dato)
{
    int i = u;
    while(i>=0 && dato <B[i])
    {
        B[i+1]=B[i];
        i--;
    }
    B[i+1]=dato;
}
void ordenacionInsercion (int B[], int c)
{
    int u = 0;
    while (u<c-1)
    {
        insertar(B,u,B[u+1]);
        u++;
    }
}
