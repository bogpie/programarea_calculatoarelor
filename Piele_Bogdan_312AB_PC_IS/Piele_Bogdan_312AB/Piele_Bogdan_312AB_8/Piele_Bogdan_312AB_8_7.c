/// Piele_Bogdan_312AB_8_7

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct sct_autor
{
    char nume[100];
    char prenume[100];
    char gen;
};

struct sct_carte
{
    char titlu[100];
    int an ;
    struct sct_autor autor;

};
typedef struct sct_carte CARTE;
int fCartiAutor (char nume[],char prenume[],CARTE vCarti[],int nCarti,int afiseaza);
void fAutorCuNrMaxCarti(CARTE vCarti[],int nCarti,int * adrMaxim);
void fSortare(CARTE vCarti[],int nCarti,int (*comparare)(CARTE,CARTE));
void fAfisare(CARTE vCarti[] , int nCarti);
int compCrescTitlu (CARTE a,CARTE b);
int compDescrescTitlu(CARTE a,CARTE b);

int main()
{

    printf ("carti :\n");

    int nCarti;

    scanf ("%d",&nCarti);
    CARTE vCarti[100];


    for (int i=0;i<nCarti;++i)
    {
        printf ("carte: ");

        scanf ("%s%d%s%s%c",vCarti[i].titlu,&vCarti[i].an,vCarti[i].autor.nume,vCarti[i].autor.prenume,&vCarti[i].autor.gen);
        fflush(stdin);
        // char car; scanf("%c",&car); // pentru linux
        // printf ("%s %d %s %s %c\n",vCarti[i].titlu,vCarti[i].an,vCarti[i].autor.nume,vCarti[i].autor.prenume,vCarti[i].autor.gen);

    }

    char nume[100],prenume[100];
    printf ("nume prenume pentru cartile cautate : \n");

    scanf("%s%s",nume,prenume);
    fCartiAutor(nume,prenume,vCarti,nCarti,1);

    int maxim=-1;
    fAutorCuNrMaxCarti(vCarti,nCarti,&maxim);

    //printf ("an si gen :\n");
    //scanf ("%d%c",an,gen);

    fSortare(vCarti,nCarti,compCrescTitlu);
    printf("\n\n\nSortare crescatoare dupa titlu:\n");
    fAfisare(vCarti,nCarti);

    fSortare(vCarti,nCarti,compDescrescTitlu);
    printf("\n\n\nSortare descrescatoare dupa titlu:\n");
    fAfisare(vCarti,nCarti);


    return 0;
}

void fSortare(CARTE vCarti[],int nCarti,int (*comparare)(CARTE,CARTE))
{
    int sortat=0;
    while (!sortat)
    {
        sortat = 1;
        for (int i=0;i<nCarti-1;++i)
        {
            if ((*comparare)(vCarti[i],vCarti[i+1])==1)
            {
                CARTE auxCarti = vCarti[i+1];
                vCarti[i+1]=vCarti[i];
                vCarti[i]=auxCarti;
                sortat=0;
            }
        }
    }
}

int fCartiAutor (char nume[],char prenume[],CARTE vCarti[],int nCarti,int afiseaza)
{
    int nCartiAutor=0;
    for (int i=0;i<nCarti;++i)
    {
        if(!strcmp(nume,vCarti[i].autor.nume) && !strcmp(prenume,vCarti[i].autor.prenume))
        {
            ++nCartiAutor;
            if (afiseaza == 1 ) printf ("%s %d %s %s %c\n",vCarti[i].titlu,vCarti[i].an,vCarti[i].autor.nume,vCarti[i].autor.prenume,vCarti[i].autor.gen);
        }
    }
    return nCartiAutor;
}
void fAutorCuNrMaxCarti(CARTE vCarti[],int nCarti,int * adrMaxim)
{
    char numeSol[100],prenumeSol[100];
    for (int i=0;i<nCarti;++i)
    {
        int nCartiAutor = fCartiAutor(vCarti[i].autor.nume,vCarti[i].autor.prenume,vCarti,nCarti,0);
        if (nCartiAutor > *adrMaxim)
        {
            *adrMaxim = nCartiAutor;
            strcpy (numeSol,vCarti[i].autor.nume);
            strcpy (prenumeSol,vCarti[i].autor.prenume);
        }
    }

    printf ("\n autorul cu cele mai multe carti : %s %s\n",numeSol,prenumeSol);
}


int compCrescTitlu(CARTE a,CARTE b)
{
    if (strcmp(a.titlu,b.titlu) == 1) return 1;
    return 0;
}

int compDescrescTitlu(CARTE a,CARTE b)
{
    if (strcmp(a.titlu,b.titlu) == -1) return 1;
    return 0;
}

void fAfisare(CARTE vCarti[],int nCarti)
{
    for (int i=0;i<nCarti;++i)
    {
         printf ("%s %d %s %s %c\n",vCarti[i].titlu,vCarti[i].an,vCarti[i].autor.nume,vCarti[i].autor.prenume,vCarti[i].autor.gen);
    }
}

