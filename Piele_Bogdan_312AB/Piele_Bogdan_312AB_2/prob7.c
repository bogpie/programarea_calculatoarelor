#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nr,gresit=0;

    printf ("Introdu numere pozitive ! \n");

    do
    {
        scanf("%d",&nr);
        if (nr<0)
        {
            printf ("Ai introdus un numar negativ ! \n");
            break;
        }
    }
    while (nr>0);

    return 0;
}
