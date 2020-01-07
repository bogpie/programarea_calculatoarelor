//camel??

#include <stdio.h>
#include <stdlib.h>

void fNumara(int x,int * adrNrCif,int * adrS, int * adrZ , int * adrU)
{
    int xbak=x;
    while (x)
    {
        ++ *adrNrCif;
        if (*adrNrCif==1) *adrU = x%10 ;
        else if (*adrNrCif==2) *adrZ = x%10 ;
        else *adrS = x%10;
        x/=10;
    }
}

int main()
{
    int x;
    scanf("%d",&x);

    if (x>999)
    {
        printf("Numar de mai mult de 3 cifre ! \n ");
        return 0;
    }

    int nrCif = 0 , s=0 , z=0 , u=0;
    fNumara(x,&nrCif,&s,&z,&u);

    printf ("Numarul are cifrele : ");

    if (s) printf("%d ",s);
    if (z) printf("%d ",z);
    printf("%d",u);

    printf (", in numar de %d",nrCif);

}
