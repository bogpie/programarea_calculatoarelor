#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct concurent
{
    char nume[50];
    int varsta;
    int vRez[3];
    int suma;
};
typedef struct concurent CONCURENT;

void fPodium(CONCURENT vPers[50],int nPers,int & adrNrGold, int & adrNrSilver, int & adrNrBronze)
{
    int iPers=0;
    int gold=0,silver=0,bronze=0;

    for (int iPers=0;iPers<nPers;++iPers)
    {
        if (vPers[iPers].suma>gold)
        {
            gold=vPers[iPers].suma
        }
    }
    for (int iPers=0;iPers<nPers;++iPers)
    {
        if (vPers[iPers].suma>silver && vPers[iPers].suma<gold)
        {
            silver=vPers[iPers].suma;
        }
    }
    for (int iPers=0;iPers<nPers;++iPers)
    {
        if (vPers[iPers].suma>bronze && vPers[iPers].suma<silver)
        {
            bronze=vPers[iPers].suma;
        }
    }

    int nrGold=0,nrSilver=0,nrBronze=0;

    for (int iPers=0;iPers<nPers;++iPers)
    {
        if (vPers[iPers].suma==gold)
        {
            ++nGold;
        }
    }
    for (int iPers=0;iPers<nPers;++iPers)
    {
        if (vPers[iPers].suma==silver)
        {
            ++nSilver;
        }
    }
    for (int iPers=0;iPers<nPers;++iPers)
    {
        if (vPers[iPers].suma==bronze)
        {
            ++nBronze;
        }
    }

    *adrNrGold=nGold;
    *adrNrSilver=nSilver;
    *adrNrBronze=nBronze;



}

void fInit(CONCURENT vPers[50],int nPers)
{
    int iRez,iPers;
    CONCURENT vPers[40];
    for (iPers=0;iPers<nPers;++iPers)
    {
        vPers.iPers.suma=0;
        for (iRez=0;iRez<nRez;++iRez)
        {
            scanf("%d",vPers[iPers].vRez[iRez]);
            vPers[iPers].suma+=vPers[iPers].iRez;
        }
    }
}

int main()
{
    CONCURENT vPers[40];
    scanf ("%d",&nPers);
    fInit(vPers,nPers);
    fPodium(vPers,nPers);
    return 0;
}
