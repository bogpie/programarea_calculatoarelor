#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf ("insereaza : ");
    while (1)
    {
        char car;
        scanf ("%c",&car);
        if (car>='A' && car<='Z')
        {
            printf ("Litera mare\n");
        }
        else if (car>='a' && car<='z')
        {
            printf ("Litera mica\n");
        }
        else if (car>='1' && car<='9')
        {
            printf ("Cifra\n");
        }
        else if (car=='\n')
        {
            printf ("insereaza : ");
        }
        else printf ("Alt caracter\n");

    }

    return 0;
}
