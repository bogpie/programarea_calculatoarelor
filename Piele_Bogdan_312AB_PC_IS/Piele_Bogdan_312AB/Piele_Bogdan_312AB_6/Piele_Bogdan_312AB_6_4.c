///Piele_Bogdan_312AB_6_4

#include <stdio.h>
#include <stdlib.h>



void fCitire (int v[],int n)
{
    for (int i=0;i<n;++i)
    {
        scanf ("%d",&v[i]);
    }
}

void fConstr(int v1[],int v2[],int v3[],int n1,int n2,int * pn3)
{
    for ( int i1 = 0 ; i1 <n1 ; ++i1)
    {
        for ( int i2=0 ; i2<n2; ++i2)
        {
            if (v1[i1]==v2[i2])
            {
                v3[*pn3]=v1[i1];
                *pn3 = *pn3 + 1 ;
                break;
            }
        }
    }
}

int main()
{
    int v1[101],v2[101],v3[101];
    int n3=0,n1,n2;

    scanf ("%d",&n1);
    fCitire( v1, n1);
    scanf ("%d",&n2);
    fCitire( v2, n2);


    fConstr( v1, v2, v3, n1 , n2 , &n3);
    if (!n3)

    {
        printf("Nu exista valori comune\n");
        exit(1);
    }
    printf ("\n%d\n",n3);

    for (int i3=0;i3<n3;++i3)
    {
        printf ("%d ",v3[i3]);
    }

    return 0;
}
