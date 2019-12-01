///Piele_Bogdan_312AB_7_2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char vstr[100];
    scanf ("%s",vstr);
    printf ("%d\n", strlen(vstr) );

    int lg=strlen(vstr);
    for (int i=0;i<lg;++i)
    {
        printf ("%c ",vstr[i]);
    }

    return 0;
}
