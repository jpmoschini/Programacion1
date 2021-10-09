#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota1, nota2, nota3;
    float prom = 0;

    printf("Ingresar las tres notas del alumno separadas por enter: ");

    scanf("%f" "%f"  "%f", &nota1, &nota2, &nota3);

    prom = (nota1 + nota2 + nota3) / 3;

    printf("\nLas notas son: " "%0.2f, " "%0.2f, y " "%0.2f ", nota1, nota2, nota3);
    printf("\n\nEl promedio es: %0.2f", prom);

    if (prom >= 7)
    {
        printf("\n\nEl alumno aprueba");
    } else printf("\n\nEl alumno desaprueba");
    return 0;
}
