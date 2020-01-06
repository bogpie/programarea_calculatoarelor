//Piele_Bogdan_312AB_9_2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persoana
{
    char nume[102];
    int varsta;
    struct persoana * urm;
};
typedef struct persoana PERSOANA;

void fStrCpy (char destinatie[100],char sursa[100])
{
    int i=0;
    for (i=0; sursa[i]!='\0'; ++i)
    {
        destinatie[i]=sursa[i];
    }
    destinatie[i]='\0';
}


int fCautaTanara(PERSOANA * ptrStart)
{
    PERSOANA * ptrCrt = ptrStart ;

    int existaGeorge19 = 0;

    while (ptrCrt!=NULL)
    {
        int varstaCrt=ptrCrt -> varsta;

        if (!strcmp(ptrCrt->nume,"George") && varstaCrt == 19)
        {
            existaGeorge19 = 1;


            if (ptrCrt->urm != NULL)
            {
                int varstaUrm = ptrCrt -> urm -> varsta;
                if ( varstaUrm < varstaCrt)
                {
                    return 1;
                }
            }
            else
            {
                return 4;
            }
        }

        ptrCrt = ptrCrt -> urm;
    }

    if (!existaGeorge19) return 2;

    return 0;
}


void fAfisareLista (PERSOANA * ptrStart)
{
    PERSOANA * ptrCrt = ptrStart;
    while (ptrCrt != NULL)
    {
        printf ("%s %d\n",ptrCrt->nume,ptrCrt->varsta);
        ptrCrt = ptrCrt -> urm;
    }
    return ;

}

void fFreeLista (PERSOANA * ptrStart)
{
    PERSOANA * ptrCrt = ptrStart;
    while (ptrCrt != NULL)
    {
        PERSOANA * ptrElim = ptrCrt;
        ptrCrt = ptrCrt->urm;
        free(ptrElim);
    }
    return ;

}

int main()
{
    int nPers,varsta;
    char nume[100];
    scanf ("%d",&nPers);

    PERSOANA * ptrStart = (PERSOANA*)malloc(sizeof(PERSOANA));
    ptrStart->urm = NULL ;

    scanf ("%s%d",ptrStart->nume,&ptrStart->varsta);

    PERSOANA * ptrCrt = ptrStart;

    for (int iPers=1; iPers<nPers; ++iPers)
    {
        scanf("%s",nume);
        scanf ("%d",&varsta);
        PERSOANA * ptrUrm = (PERSOANA*)malloc(sizeof(PERSOANA)) ;
        fStrCpy( ptrUrm->nume, nume);
        ptrUrm -> varsta = varsta;
        ptrUrm -> urm=NULL;
        ptrCrt -> urm=ptrUrm;
        ptrCrt = ptrCrt -> urm;
    }

    if ( fCautaTanara(ptrStart) == 4)
    {
        printf ("\nGeorge de 19 ani e ultimul din lista\n");
    }
    else if ( fCautaTanara(ptrStart) == 2 )
    {
        printf ("\n nu exista un George de 19 ani \n");
    }

    else if (!fCautaTanara(ptrStart))
    {
        printf ("\Nu, nu e mai tanara\n");
    }

    else printf ("\nDa, e mai tanara\n");


    fFreeLista(ptrStart);
    //fAfisareLista(ptrStart);

    return 0;
}
