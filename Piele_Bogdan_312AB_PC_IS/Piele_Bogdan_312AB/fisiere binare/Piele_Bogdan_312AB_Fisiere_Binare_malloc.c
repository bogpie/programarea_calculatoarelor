///Piele_Bogdan_312AB_Fisiere_Binare_final

#include <stdio.h>
#include <stdlib.h>


void fIntroducere(FILE *fisierBinar)
{
    fisierBinar = fopen("fisierBinar.dat","wb");
    if (!fisierBinar)
    {
        printf ("fisierul nu a putut fi creat");
        exit (1);
        /// return 0;
    }

    int nLin,nCol,nElem=0;

    printf ("dimensiunile matricei (linii coloane) : ");
    scanf ("%d%d",&nLin,&nCol);

    int * adrHeap = (int*)malloc(sizeof(int)*nLin*nCol);
    fwrite(&nLin,sizeof(nLin),1,fisierBinar);
    fwrite(&nCol,sizeof(nCol),1,fisierBinar);

    for (int iLin = 0 ; iLin < nLin ; ++iLin)
    {
        for (int iCol=0;iCol<nCol;++iCol)
        {
            scanf("%d",&adrHeap[nElem]);
            nElem++;
        }
    }
    fwrite(adrHeap,sizeof(nElem),nElem,fisierBinar);
    fclose(fisierBinar);
    free(adrHeap);
}

void fAfisare (FILE *fisierBinar)
{
    fisierBinar = fopen("fisierBinar.dat","rb");
    int nLin,nCol,nElem=0;
    fread(&nLin,sizeof(nLin),1,fisierBinar);
    fread(&nCol,sizeof(nCol),1,fisierBinar);

    int * adrHeap = (int*)malloc(sizeof(int)*nLin*nCol);
    fread(adrHeap,sizeof(int),nLin*nCol,fisierBinar);
    printf ("%d linii %d coloane\n",nLin,nCol);

    for (int iLin=0;iLin<nLin;++iLin)
    {
        for (int iCol=0;iCol<nCol;++iCol)
        {
            printf ("%d ",adrHeap[nElem++]);
        }
        printf("\n");
    }

    fclose(fisierBinar);
    free(adrHeap);
}

int main()
{
    FILE *fisierBinar;

    fIntroducere(fisierBinar);
    fAfisare(fisierBinar);





}
