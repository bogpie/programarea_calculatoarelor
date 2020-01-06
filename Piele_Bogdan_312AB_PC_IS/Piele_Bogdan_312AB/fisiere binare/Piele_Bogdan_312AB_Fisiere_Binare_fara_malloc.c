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

    int nLin,nCol,nElem=0,vElem[25],tab[5][5];

    printf ("dimensiunile matricei (linii coloane) : ");
    scanf ("%d%d",&nLin,&nCol);

    int * adrHeap;
    adrHeap = (int*)malloc(sizeof(int)*nLin*nCol);

    //size_t fwrite ( const void * ptrWritten, size_t sizeElementInBytes, size_t count, FILE * stream );
    fwrite(&nLin,sizeof(nLin),1,fisierBinar);
    fwrite(&nCol,sizeof(nCol),1,fisierBinar);

    for (int iLin = 0 ; iLin < nLin ; ++iLin)
    {
        for (int iCol=0;iCol<nCol;++iCol)
        {
            scanf("%d",&tab[iLin][iCol]);
            vElem[nElem++] = tab[iLin][iCol];
        }
    }
    fwrite(vElem,sizeof(nElem),nElem,fisierBinar);
    fclose(fisierBinar);
}

void fAfisare (FILE *fisierBinar)
{
    fisierBinar = fopen("fisierBinar.dat","rb");
    int nLin,nCol,iElem=0,vElem[25],tab[5][5];
    fread(&nLin,sizeof(nLin),1,fisierBinar);
    fread(&nCol,sizeof(nCol),1,fisierBinar);
    fread(vElem,sizeof(int),nLin*nCol,fisierBinar);

    printf ("%d linii %d coloane\n",nLin,nCol);
    for (int iLin=0;iLin<nLin;++iLin)
    {
        for (int iCol=0;iCol<nCol;++iCol)
        {
            printf ("%d ",vElem[iElem++]);
        }
        printf("\n");
    }

}

int main()
{
    FILE *fisierBinar;

    fIntroducere(fisierBinar);
    fAfisare(fisierBinar);





}
