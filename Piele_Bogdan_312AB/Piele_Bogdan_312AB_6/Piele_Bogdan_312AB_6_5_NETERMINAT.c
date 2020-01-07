///Piele_Bogdan_312AB_6_5

#include <stdio.h>
#include <stdlib.h>


void fFind(int v[],int n,int vpoz[])
{
    int ipoz=0;
    int xmin=v[0];
    for (int i=1;i<n;++i)
    {
        if (v[i]<xmin)
        {
            xmin=v[i];
        }
    }

    for (int i=0;i<n;++i)
    {
        if (v[i] == xmin)
        {
            vpoz[ipoz++]=i;
        }
    }


}

void fCitire (int v[],int n)
{
    for (int i=0;i<n;++i)
    {
        scanf ("%d",&v[i]);
    }
}

int main()
{
    int v[101],vpoz[101];

    scanf ("%d",&n);
    fCitire(v,n);
    fFind(v,n,vpoz)

    for (i=0;i<npoz;++i)
    {

    }

    return 0;
}
