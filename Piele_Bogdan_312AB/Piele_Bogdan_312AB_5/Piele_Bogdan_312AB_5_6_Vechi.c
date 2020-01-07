///Piele_Bogdan_312AB_5_6


#include <stdio.h>
#include <stdlib.h>

int fPare (int xCitit, int * xPare)
{
    int cif=0,nPare=0,vPare[21];
    while (xCitit)
    {
        cif=xCitit%10;
        if (cif%2==0)
        {

            vPare[++nPare]=cif;
        }
        xCitit/=10;
    }

    if (!nPare) return 0;

    while (nPare)
    {
        cif=vPare[nPare];
        *xPare = *xPare * 10 + cif;
        --nPare;
    }

    return 1;
}

int main()
{
    int xCitit,xPare=0;
    scanf("%d",&xCitit);
    int posibil = fPare(xCitit,&xPare);

    if (!posibil && xCitit)
    {
        printf("nu se poate obtine un numar din cifrele pare");
        exit(1);
    }
    else
    {
        printf("numarul obtinut din %d este %d",xCitit,xPare);
    }

    return 0;

}
