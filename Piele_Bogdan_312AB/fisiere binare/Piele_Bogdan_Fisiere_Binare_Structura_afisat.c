///Piele_Bogdan_Fisiere_Binare_Structura.c

#include <stdio.h>
#include <stdlib.h>

struct elev
{
    char nume[20];
    int id;
    float medie;
};
typedef struct elev ELEV;

int main()
{
    FILE *fisier;
    fisier = fopen("fisierBinarStruct.dat","rb");
    if (fisier!=NULL)
    {
        printf ("fisierul nu a putut fi creat");
        exit (1);
    }

    ELEV vElevi[100];

    int iElev=0,nElevi;

    fread(&nElevi,sizeof(int),1,fisier);

    printf ("%d\n",nElevi);

    fread(vElevi,sizeof(ELEV),nElevi,fisier);


    for (int iElev=0; iElev<nElevi;++iElev)
    {
        printf ("%s %d %f\n",vElevi[iElev].nume,vElevi[iElev].id,vElevi[iElev].medie);
    }

    fclose(fisier);

    return 0;

}
