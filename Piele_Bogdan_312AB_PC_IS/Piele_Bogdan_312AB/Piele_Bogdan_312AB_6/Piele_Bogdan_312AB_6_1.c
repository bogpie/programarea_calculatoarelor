///Piele_Bogdan_312AB_6_1

#include <stdio.h>
#include <stdlib.h>

void f(int v[],int n,int * nPer)
{
    int i=1;
    while (i<n)
    {
        if (v[i]>v[i-1])
        {
            ++ *nPer;
            //printf ("%d %d \n" , v[i-1] , v[i]);
        }
        ++i;
    }
}

int main()
{
    int v[101],n,nPer=0;

    scanf ("%d",&n);

    for (int i=0;i<n;++i)
    {
        scanf ("%d",&v[i]);
    }

    f(v,n,&nPer);

    printf ("%d",nPer);

    return 0;
}
