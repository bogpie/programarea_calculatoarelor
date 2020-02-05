#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char nume[50];
    int vNote[3];
};
typedef struct student STUDENT;

void fInit(STUDENT vStud[],int * adrNrStud)
{
    FILE *input = fopen("input.txt","r");

    int nStud;
    fscanf(input,"%d",&nStud);
    *adrNrStud=nStud;

    int iStud=0;
    for (iStud=0;iStud<nStud;++iStud)
    {
        char br;
        fscanf(input,"%c",&br);
        fgets(vStud[iStud].nume,50,input);
        vStud[iStud].nume[strlen(vStud[iStud].nume)-1]='\0';

        for (int iNota=0;iNota<3;++iNota)
        {
            fscanf(input,"%d",&vStud[iStud].vNote[iNota]);
        }
    }
}

void fBest(STUDENT vStud[],int nStud,char vBest[][50],int * adrNrBest,int materie)
{

    printf("best:\n");
    int mx=-1;
    for (int iStud=0;iStud<nStud;++iStud)
    {
        if (vStud[iStud].vNote[materie]>mx)
        {
            mx=vStud[iStud].vNote[materie];
        }

    }
    int nBest=0;
    for (int iStud=0;iStud<nStud;++iStud)
    {
        if (vStud[iStud].vNote[materie]==mx)
        {
            strcpy(vBest[nBest++],vStud[iStud].nume);
        }


    }

    int sortat = 0;
    while (!sortat)
    {
        sortat=1;
        for (int iBest=1;iBest<nBest;++iBest)
        {
            if (strcmp(vBest[iBest-1],vBest[iBest])==1)
            {
                char aux[50];
                strcpy(aux,vBest[iBest-1]);
                strcpy(vBest[iBest-1],vBest[iBest]);
                strcpy(vBest[iBest],aux);
                sortat=0;
            }
        }
    }

    for(int iBest=0;iBest<nBest;++iBest)
    {
        printf("%s\n",vBest[iBest]);
    }
    *adrNrBest=nBest;
}

int fCauta(char nume[],char vBest[][50],int nBest)
{
    for (int iBest=0;iBest<nBest;++iBest)
    {
        if (strcmp(nume,vBest[iBest])==0)
        {
            return 1;
        }
    }
    return 0;
}

void fPass(STUDENT vStud[50],int nStud)
{
    FILE * binar = fopen("binar.dat","wb");
    for (int iStud=0;iStud<nStud;++iStud)
    {
        int pass=1;
        for (int iNota=0;iNota<3;++iNota)
        {
            if (vStud[iStud].vNote[iNota]<5)
            {
                pass=0;
            }
        }
        if (pass)
        {
            //printf("passed: %s\n",vStud[iStud].nume);
            fwrite(vStud[iStud].nume,sizeof(vStud[iStud].nume),1,binar);
        }
    }
    fclose(binar);

    binar = fopen("binar.dat","rb");



    char nume[50];

    while (fread (nume,sizeof(nume),1,binar) != 0)
    {
        printf("passed: %s\n",nume);

    }
}

int main()
{
    STUDENT vStud[50];
    int nStud;
    fInit(vStud,&nStud);

    char vBest[50][50];

    int materie=0,nBest=0;
    fBest(vStud,nStud,vBest,&nBest,materie);
    char nume[50];

    printf("nume de cautat: ");
    gets (nume);
    printf("\n");

    int gasit=fCauta(nume,vBest,nBest);
    if (!gasit) printf("%s nu se gaseste\n",nume);
    else printf("%s se gaseste\n",nume);


    fPass(vStud,nStud);

    return 0;
}
