///Piele_Bogdan_312AB_7_1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char car,vstr[100];



    scanf("%[^\n]s",vstr);
    printf("%s\n",vstr);

    scanf ("%c",&car); /// adaugam un caracter pentru preluarea '\n' sa din buffer
    gets(vstr); ///
    printf("%s\n",vstr);

    return 0;
}
