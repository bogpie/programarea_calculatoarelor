//Piele_Bogdan_312AB_9_1

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int val;
    struct element * urm;
};

typedef struct element ELEM;


void fTestarePointer (void * ptrCrt)
{
    if (ptrCrt==NULL)
    {
        printf("alocarea nu a reusit");
        exit(1);
    }
    return;
}

void fAdaugaDreapta (ELEM * ptrCrt,int val)
{
    ELEM * ptrUrm = (ELEM*)malloc(sizeof(ELEM)) ;
    fTestarePointer(ptrUrm);
    ptrUrm->val = val;
    ptrUrm->urm=NULL;
    ptrCrt->urm=ptrUrm;
    ptrCrt=ptrUrm;
    return;
}

void fSterge ( ELEM * ptrElim, ELEM ** adrPtrStart)
{
    ELEM * ptrStart = *adrPtrStart;
    ELEM * ptrCrt;

    if (ptrElim == ptrStart)
    {
        ptrStart = ptrStart -> urm;
    }
    else
    {
        ptrCrt = ptrStart;

        while ( ( ptrCrt!=NULL ) && ( ptrCrt->urm != ptrElim ) )
        {
            ptrCrt = ptrCrt -> urm;
        }
        if (ptrCrt==NULL)
        {
            printf ("acest pointer nu corespunde niciunui element din lista !");
            exit(1);
        }

        ptrCrt -> urm = ptrCrt -> urm -> urm;
    }

    *adrPtrStart = ptrStart;
    free(ptrElim);

    return;
}

void fAfisareLista( ELEM * ptrStart )
{
    printf ("\n\nAu ramas elementele : ");

    ELEM * ptrCrt = ptrStart;

    while ( ptrCrt != NULL )
    {
        printf ("%d ", ptrCrt -> val);
        ELEM * ptrElim = ptrCrt;
        ptrCrt = ptrCrt -> urm;
    }
    return;

}

void fFreeLista( ELEM * ptrStart )
{
    ELEM * ptrCrt = ptrStart;

    while ( ptrCrt != NULL )
    {
        ELEM * ptrElim = ptrCrt;
        ptrCrt = ptrCrt -> urm;
        free(ptrElim);
    }
    return;

}

int main()
{
    int i,nr;
    ELEM *ptrStart,*ptrCrt;
    printf ("numarul de elemente intregi : ");
    scanf("%d",&nr);

    ptrCrt=(ELEM*)malloc(sizeof(ELEM));
    fTestarePointer(ptrCrt);

    //notite pentru mine
    // pointer de elemente de lista care point-uieste la un element din lista alocat dinamic
    //malloc returneaza void * => cast-uim cu (ELEM*)


    ///printf ("\nprimul element este : ");
    scanf ("%d", &ptrCrt->val);
    ptrCrt -> urm = NULL;

    ptrStart=ptrCrt;

    for (i=1; i<nr; ++i)
    {
        ///printf ("\nal %d - lea element este : ",i+1);
        int val;
        scanf ("%d",&val);
        fAdaugaDreapta(ptrCrt,val);
        ptrCrt = ptrCrt->urm; //ptrCrt = (*ptrCrt).urm;
    }

    ptrCrt = ptrStart;

    while (ptrCrt!=NULL)
    {
        ELEM * ptrUrm = ptrCrt -> urm;

        if ( ptrCrt -> val % 2 == 0 )
        {
            fSterge(ptrCrt,&ptrStart);
        }

        ptrCrt = ptrUrm;
    }


    if (ptrStart == NULL)
    {
        printf("DOAR ELEMENTE PARE IN LISTA INITIALA");
        exit(1);
    }

    fAfisareLista(ptrStart);

    fFreeLista(ptrStart);


    return 0;
}
