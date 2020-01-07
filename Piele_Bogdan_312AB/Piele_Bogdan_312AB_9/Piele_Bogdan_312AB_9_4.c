//Piele_Bogdan_312AB_9_4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    int intreg;
    struct element * urm;
};
typedef struct element ELEMENT;

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
    int nr;

    ELEMENT * ptrStart = (ELEMENT *)malloc(sizeof(ELEMENT));
    ptrStart -> urm = NULL;
    scanf ("%d",&ptrStart->intreg);

    ELEMENT * ptrCrt = ptrStart;

    if (ptrStart -> intreg == 6)
    {
        printf ("lista incepe cu 6\n");
        exit (1);
    }

    for (int i=1;i<nr;++i)
    {
        ELEMENT * ptrUrm = (ELEMENT *)malloc(sizeof(ELEMENT));
        ptrUrm->urm = NULL;
        scanf ("%d",ptrUrm->intreg);
        ptrCrt->urm = ptrUrm;
        ptrCrt = ptrCrt -> urm;
    }

    ptrCrt = ptrStart ->urm ;
    ELEMENT * ptrOld = ptrStart ;



    while (ptrCrt != NULL)
    {

        if (ptrCrt -> intreg == 6)
        {
            ptrOld -> urm = ptrOld -> urm -> urm;
            ptrCrt = ptrOld -> urm;
            free(ptrCrt);
        }
        else
        {
            ptrOld = ptrCrt;
            ptrCrt = ptrCrt -> urm;

        }
    }

    ptrCrt = ptrStart;

    int i=0;

    while (i<2 && ptrCrt!=NULL)
    {
        ptrCrt = ptrCrt -> urm;
    }

    ELEMENT * ptrNou = malloc(sizeof(ELEMENT));
    ptrNou -> urm = NULL;
    printf ("\nElementul inserat pe pozitia a 3-a este : \n");
    scanf ("%d",ptrNou->intreg);

    ptrNou -> urm = ptrCrt -> urm;
    ptrCrt -> urm = ptrNou;



    return 0;
}
