//Piele_Bogdan_312AB_9_3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    char cuv[15];
    struct element * urm;
};
typedef struct element ELEMENT;

void fStrCpy (char destinatie[],char sursa[])
{
    int i=0;
    for (i=0; sursa[i]!='\0'; ++i)
    {
        destinatie[i]=sursa[i];
    }
    destinatie[i]='\0';
    return ;
}

void fFreeLista (ELEMENT * ptrStart)
{
    ELEMENT * ptrCrt = ptrStart;
    while (ptrCrt != NULL)
    {
        ELEMENT * ptrElim = ptrCrt;
        ptrCrt = ptrCrt->urm;
        free(ptrElim);
    }
    return ;

}

int main()
{
    int nPers,varsta;
    char cuv[15];
    char fraza[100];

    scanf ("%d",&nPers);
    ELEMENT * ptrStart = (ELEMENT*)malloc(sizeof(ELEMENT));
    ptrStart->urm = NULL ;
    scanf ("%s",ptrStart->cuv);
    ELEMENT * ptrCrt = ptrStart;

    for (int iPers=1; iPers<nPers; ++iPers)
    {
        scanf("%s",cuv);
        ELEMENT * ptrUrm = (ELEMENT*)malloc(sizeof(ELEMENT)) ;
        fStrCpy( ptrUrm->cuv, cuv);
        ptrUrm -> urm=NULL;
        ptrCrt -> urm=ptrUrm;
        ptrCrt = ptrCrt -> urm;
    }

    ptrCrt = ptrStart;
    while (ptrCrt != NULL)
    {
        printf ("%s la adresa %p\n",ptrCrt->cuv,ptrCrt);
        strcat(fraza,ptrCrt->cuv);
        strcat(fraza," ");
        ptrCrt = ptrCrt -> urm;
    }
    //strcat(fraza,".");
    printf ("\nfraza este %s\n",fraza);

    fFreeLista(ptrStart);

    return 0;
}
