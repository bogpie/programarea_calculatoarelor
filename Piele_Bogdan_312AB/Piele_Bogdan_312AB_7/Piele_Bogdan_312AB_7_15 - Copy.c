#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void fCount1(char sir[],int lg,int * adr_nCuv)
{
    //sir[lg] =' ';++lg;

    int pozPrima=0;
    for (int i=0;i<lg;++i)
    {
        if (sir[i]==' ')
        {
            ++*adr_nCuv;
            sir[i]='\0';
            printf ("%s\n",sir+pozPrima);
            pozPrima = i+1;
        }
    }

    if(sir[lg]!='.')
    {
        ++*adr_nCuv;
        printf ("%s\n",sir+pozPrima);

    }
}


void fCount2(char sir[],int lg,int * adr_nCuv)
{
    sir[lg+1]='.';
    sir[lg+2]='\0';
    ++lg;

    char * pch = strtok(sir," .");
    while (pch!=NULL)
    {
        printf ("%s\n",pch);
        pch = strtok(NULL," .");
        ++*adr_nCuv;

    }
}

int main ()
{
    char sir[100];
    gets(sir);
    int lg=strlen(sir);
    int nCuv=0;

    fCount1(sir,lg,&nCuv);
    ///fCount2(sir,lg,&nCuv);

    printf ("\n%d cuvinte \n\n\n",nCuv);
    /// printf ("\nsirul dupa distrugere cu strtok: %s\n",sir);
    /// printf ("\nsirul sir+4 dupa distrugere : %s\n",sir+4);

    return 0;
}
