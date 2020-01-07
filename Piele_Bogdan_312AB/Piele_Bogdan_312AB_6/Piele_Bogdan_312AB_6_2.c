///Piele_Bogdan_312AB_6_2

#include <stdio.h>
#include <stdlib.h>

void f (int v[],int n,int * maxImp)
{
    for (int i=0;i<n;++i)
    {

        if ( v[i] % 2 != 0 && v[i] > *maxImp )
        {
            *maxImp = v[i];
        }
    }
    return ;
}

int main()
{
    int n,v[101],maxImp=0;

    scanf ("%d",&n);

    for (int i=0;i<n;++i)
    {
        scanf ("%d",&v[i]);
    }

    f(v,n,&maxImp);
    if ( maxImp == -1 )
    {
        printf ("Vectorul nu are elemente impare. \n");
        exit(1);
    }
    else
    {
        printf ("%d",maxImp);
    }

    return 0;
}
