#include <stdio.h>
#include <stdlib.h>

int main()
{
    char car;

    do
    {
        printf ("Doriti sa continuati ? \n");
        scanf("%c",&car);
    }
    while (car=='D');
    return 0;
}
