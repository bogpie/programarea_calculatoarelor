///Piele_Bogdan_312AB_7_4_strcat

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char car,sir1[100],sir2[100],sir3[100];

    gets(sir1);
    gets(sir2);
    gets(sir3);

    strcat(sir1,sir2);
    strcat(sir1,sir3);


  //scanf("%s",sir1);
    printf("%s",sir1);

    return 0;
}
