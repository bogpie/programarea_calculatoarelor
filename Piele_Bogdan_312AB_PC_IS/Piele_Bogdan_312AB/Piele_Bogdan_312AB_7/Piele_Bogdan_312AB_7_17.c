#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * f_strstr_poz_finala(char * a , char * b)
{
    /// cauta b in a

    char * acrt = a;
    char * bcrt = b;

    while (*acrt)
    {
        if (*acrt == *bcrt)
        {
            ++bcrt;
        }
        if (*bcrt == '\0')
        {
            return acrt;
        }

        ++acrt;
    }

    return NULL;
}

int main ()
{
    char a[20],b[20];
    scanf ("%s%s",a,b);

    char * pt = f_strstr_poz_finala(a,b);

    int afirmativ = 0;
    if (pt != NULL)
    {
        pt = f_strstr_poz_finala (pt+1,b);

        if (pt==NULL)
        {
            printf ("afirmativ");
            afirmativ = 1;
            //exit(1);
        }
    }
    if (!afirmativ)
    {
        printf ("negativ");
    }

    return 0;
}
