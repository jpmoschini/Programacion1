#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numA, numB;

    printf("Ingrese dos números separados por ENTER: ");

    scanf("%f %f", &numA, &numB);
    //anf("%f", &numB);

    if (numA > numB)
    {
        printf("%0.2f \n%0.2f", numA, numB);
            //printf("\n%0.2f", numB);

    } else
        {
            printf("%0.2f \n%0.2f", numB, numA);
        //printf("\n%0.2f", numA);
        }

    return 0;
}
