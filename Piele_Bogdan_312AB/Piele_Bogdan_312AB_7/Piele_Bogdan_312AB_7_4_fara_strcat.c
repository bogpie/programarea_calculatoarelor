///Piele_Bogdan_312AB_7_4_fara_strcat

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fstrcat(char sir1[],char sir2[])
{
    int i=0 , j=0;

    while(sir1[i])
    {
        ++i;
    }

    while (sir2[j])
    {
        sir1[i++]=sir2[j++];
    }

    sir1[i]='\0';

}

int main()
{
    char car,sir1[100],sir2[100],sir3[100];

    gets(sir1);
    gets(sir2);
    gets(sir3);

    fstrcat(sir1,sir2);
    //printf("%s\n",sir1);
    fstrcat(sir1,sir3);
    printf("%s",sir1);

    return 0;
}
