///Piele_Bogdan_312AB_7_5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char vstr[100];

    scanf ("%s",vstr);
    int lg=strlen(vstr);

//    printf("%s\n",vstr);
//    printf("%d\n",lg);


    for (int i=0;i<lg;++i)
    {
        char carElim=vstr[i];
        vstr[i]='\0';
        printf("%s%s\n",vstr,vstr+i+1);
        vstr[i]=carElim;
    }

    return 0;
}
