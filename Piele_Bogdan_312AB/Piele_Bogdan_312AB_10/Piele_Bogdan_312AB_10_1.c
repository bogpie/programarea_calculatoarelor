///Piele_Bogdan_312AB_10_1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ScriereTotala (FILE *fout, char sir[])
{
    fprintf(fout,"%s",sir);
    fprintf(fout,"\n\n");

    return;
}

void ScriereCarCuCar (FILE *fout, char sir[])
{
    int lg=strlen(sir);

    for (int i = 0 ; i < lg ; ++i)
    {
        char car = sir[i];
        fprintf(fout,"%c ",car);
    }
    fprintf(fout,"\n\n");
    return ;

}

void ScriereCuvCuCuv (FILE * fout,char sir[],int linDif)
{
    int lg=strlen(sir);

    char * pch = strtok ( sir, ". !,");

    while (pch != NULL)
    {
        fprintf (fout,"%s ",pch);

        if (linDif == 1)
        {
            fprintf(fout,"\n");
        }

        pch = strtok(NULL,". !,");
    }

    fprintf(fout,"\n\n");

    return ;
}

void AfisareTotala (char sir[])
{
    printf ("%s",sir);
    printf ("\n");
    return;
}

void AfisareCarCuCar (char sir[])
{
    int lg = strlen(sir);
    for (int i=0;i<lg;++i)
    {
        printf ("%c ",sir[i]);
    }
    return;
}

void AfisareCuvCuCuv (char sir[])
{
    char * pch = strtok (sir," ");

    while (pch!=NULL)
    {
        printf ("%s_",pch);
        pch = strtok (NULL," " );
    }

    printf ("\n");

    return;
}

int main ()
{
    FILE * fout;
    char sir[100];

    gets (sir);
    int lg=strlen(sir);

    fout = fopen("Piele_Bogdan_312AB_10_1.txt","w");

    if (fout == NULL)
    {
        exit (1);
    }

    ScriereTotala(fout,sir);
    ScriereCarCuCar(fout,sir);


    char sirBak[100];
    strcpy(sirBak,sir);
    ScriereCuvCuCuv(fout,sir,0);

    strcpy(sir,sirBak);
    ScriereCuvCuCuv(fout,sir,1);

    fclose(fout);
    FILE * fin;
    fin = fopen("Piele_Bogdan_312AB_10_1.txt","r");

    if (fin == NULL)
    {
        exit (1);
    }


    // while (!feof(fin))
    {
        fgets (sir,100,fin);
    }

    AfisareCarCuCar(sir);
    AfisareTotala(sir);
    AfisareCuvCuCuv(sir);

}
