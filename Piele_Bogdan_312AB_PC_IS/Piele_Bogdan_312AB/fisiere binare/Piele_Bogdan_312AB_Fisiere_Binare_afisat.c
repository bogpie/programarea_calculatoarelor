///Piele_Bogdan_312AB_Fisiere_Binare_afisat

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fisier;
    fisier = fopen("fisierBinar.dat","rb");
    if (!fisier)
    {
        printf ("fisierul nu a putut fi creat");
        exit (1);
    }

    int vElem[30],iElem=0;


    int nLin,nCol;

    fread(&nLin,sizeof(int),1,fisier);

    //fseek (fisier,sizeof(nLin),SEEK_CUR);

    fread(&nCol,sizeof(int),1,fisier);

    //fseek (fisier,sizeof(nCol),SEEK_CUR);
    fread(vElem,sizeof(int),nLin*nCol,fisier); ///


    printf("%d %d\n",nLin,nCol);
    for (int iLin=0;iLin<nLin;++iLin)
    {
        for (int iCol=0;iCol<nCol;++iCol)
        {
            printf("%d ",vElem[iElem++]);
        }
        printf ("\n");
    }

    fclose(fisier);
}
