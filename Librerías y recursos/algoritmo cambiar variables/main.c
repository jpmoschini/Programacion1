#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 3;
    int b = 8;


    printf("Hello world!\n");
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Antes a era 3, ahora es %i, y b era 8, ahora es %i.", a, b);
    return 0;
}
