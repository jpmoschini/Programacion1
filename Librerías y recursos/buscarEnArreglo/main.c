#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

int buscarChar(char A[], int c, char dato)
{
    int i = 0;
    int flag = 0;
    while(i < c && flag == 0)
    {
        if (dato == A[i])
        {
            flag = 1;
        } else i++;
    }
}
