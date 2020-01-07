///Piele_Bogdan_312AB_Fisiere_Binare_Afisat

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fisier;
    fisier = fopen("fisierBinar.dat","wb");
    if (!fisier)
    {
        printf ("fisierul nu a putut fi creat");
        exit (1);
    }


    //printf ("Numar elemente matrice: ");
    //scanf ("%d",&n);


    int  nLin, nCol, nElem=0;
    int tab[5][5];
    int vElem[25];


    printf ("Numarul liniilor , coloanelor : ");

    scanf ("%d%d",&nLin,&nCol);

    fwrite(&nLin,sizeof(nLin),1,fisier);

    //fseek (fisier,sizeof(nLin),SEEK_CUR);

    fwrite(&nCol,sizeof(nCol),1,fisier);

    //fseek (fisier,sizeof(nCol),SEEK_CUR);

    for (int i = 0 ;i < nLin ; ++i)
    {
        for (int j = 0 ; j < nCol ; ++j)
        {
            scanf("%d",&tab[i][j]);
            vElem[nElem++] = tab[i][j];
        }
    }


    fwrite(vElem,sizeof(int),nLin*nCol,fisier);

    fclose(fisier);

}
