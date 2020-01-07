///Piele_Bogdan_312AB_6_6

#include <stdio.h>
#include <stdlib.h>


void fElim (int * v,int * adr_n)
{
    int n = *adr_n;
    int deEliminat = v[0];
    int prim = v[0];

    for (int i=1;i<n;++i)
    {
        v[i-1]=v[i];
    }
    --n;

    for (int i=0;i<n;++i)
    {
        if (v[i] == deEliminat)
        {
            for (int j=i+1;j<n;++j)
            {
                v[j-1]=v[j];
            }
            --i;
            --n;
        }
    }
    *adr_n = n;
}

int main()
{
    int n;
    scanf ("%d",&n);

    int * v = (int *)malloc(n*sizeof(int));
    if (v==NULL)
    {
        printf ("A esuat alocarea dinamica\n");
        exit(1);
    }

    for (int i=0;i<n;++i)
    {
        scanf ("%d",&v[i]);
        ///scanf ("%d",v+i);

    }

    printf("\n");
    for (int i=0;i<n;++i)
    {
        printf ("%d ",v[i]);
       // printf ("%d ",*(v+i));
    }
    printf("\n");

    fElim (v,&n);

    for (int i=0;i<n;++i)
    {
        printf ("%d ",v[i]);
       // printf ("%d ",*(v+i));
    }


    return 0;
}
