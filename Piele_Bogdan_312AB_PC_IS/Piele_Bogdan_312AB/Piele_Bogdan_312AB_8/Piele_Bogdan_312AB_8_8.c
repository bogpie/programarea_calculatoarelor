///Piele_Bogdan_312AB_8_8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct struct_persoana
{
    char nume[100];
    char prenume[100];
    char cnp[100];
};

typedef struct struct_persoana PERSOANA;

/// cnp -> *YYMMDD...

int extragereAn (char cnp[])
{
    if (cnp[0]-'0' == 5 || cnp[0]-'0' == 6)
    {
        /// e nascut dupa 2000;

        return 2000 + ( cnp[1] - '0' ) * 10 + (cnp[2] - '0');
    }
    else
    {
        /// e nascut intre 1900 si 1999;
        return 1900 + ( cnp[1] - '0' ) * 10 + (cnp[2] - '0');
    }


    //return 1900 + (cnp[0]-'0' == 5 || cnp[0]-'0' == 6) * 100 + ( cnp[1] - '0' ) * 10 + (cnp[2] - '0');
}
int extragereLuna (char cnp[])
{
    return ( cnp[3] - '0' ) * 10 + (cnp[4] - '0');
}
int extragereZi (char cnp[])
{
    return ( cnp[5] - '0' ) * 10 + (cnp[6] - '0');
}

int comp_catalog (PERSOANA pers1,PERSOANA pers2)
{
    if ( strcmp(pers1.nume , pers2.nume) == 0);
    {
        return ( strcmp(pers1.prenume , pers2.prenume) > 0 );
    }
    return (strcmp(pers1.nume,pers1.nume) > 0 );

}

int comp_desc_data_nasterii (PERSOANA pers1,PERSOANA pers2)
{
    int an1 = extragereAn (pers1.cnp);
    int an2 = extragereAn (pers2.cnp);

    int luna1 = extragereLuna (pers1.cnp);
    int luna2 = extragereLuna (pers2.cnp);

    int zi1 = extragereZi (pers1.cnp);
    int zi2 = extragereZi (pers2.cnp);

    if (an1 == an2)
    {
        if (luna1 == luna2)
        {
            return zi1<zi2;
        }
        return luna1<luna2;
    }
    return an1<an2;

}

void fAfisare (PERSOANA vPers[],int nPers)
{
    printf ("\n\n");
    for (int i=0;i<nPers;++i)
    {
        printf ("%s %s %s\n",vPers[i].nume,vPers[i].prenume,vPers[i].cnp);
    }
    printf ("\n\n");
}

void fSortare (PERSOANA vPers[],int nPers,int (*comp)(PERSOANA,PERSOANA))
{
    int ordonat=0;

    while (!ordonat)
    {
        ordonat = 1;
        for (int i=0; i<nPers-1; ++i)
        {
            if ( (*comp)(vPers[i],vPers[i+1]))
            {
                PERSOANA auxPers = vPers[i];
                vPers[i] = vPers[i+1];
                vPers[i+1] = auxPers;
                ordonat = 0;
            }
        }
    }
}

int main()
{

    int nPers;
    printf ("numarul de persoane: ");
    scanf ("%d",&nPers);

    PERSOANA vPers[100];

    for (int i=0; i<nPers; ++i)
    {
        scanf ("%s%s%s",vPers[i].nume,vPers[i].prenume,vPers[i].cnp);
    }

    fSortare(vPers,nPers,comp_desc_data_nasterii);
    fAfisare (vPers,nPers);


    fSortare(vPers,nPers,comp_catalog);
    fAfisare (vPers,nPers);


    return 0;
}
