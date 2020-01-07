/// Piele Bogdan 312AB Setul 4 Prob 4

/// NETERMINAT !!!!

#include <stdio.h>
#include <stdlib.h>


void fcopy (int i,int lg,int v[101],int i3,int v3[101])
{
    while (i<lg)
    {
        if (v[i]%2)
        {
            v3[i3++]=v[i];
        }

        ++i;
    }
}

int main()
{
    int v1[101],v2[101],v3[101];
    int lg1=0,lg2=0,i1=0,i2=0,lg3=0,i3=0;

    scanf ("%d",&lg1);
    for (i1=0; i1<lg1; ++i1)
    {
        scanf ("%d",&v1[i1]);
    }

    scanf ("%d",&lg2);
    for (i2=0; i2<lg2; ++i2)
    {
        scanf ("%d",&v2[i2]);
    }

    i1=i2=0;
    while (i1<=lg1 && i2<=lg2)
    {

        while (v1[i1]%2==0 && i1<lg1)
        {
            ++i1;
        }

        while (v2[i2]%2==0 && i2<lg2)
        {
            ++i2;
        }

        if (v1[i1]%2==0)
        {
            ++i1;
            break;
        }
        if (v2[i2]%2==0)
        {
            ++i2;
            break;
        }


        if (v1[i1] < v2[i2])
        {
            v3[i3] = v1[i1];
            ++i1;
        }
        else
        {
            v3[i3] = v2[i2];
            ++i2;
        }
        ++i3;
    }
    lg3=i3;

    if (i1!=lg1)
    {
        fcopy(i1,lg1,v1,i3,v3);
    }

    else if (i2!=lg2)
    {
        fcopy(i2,lg2,v2,i3,v3);
    }

    for (i3=0; i3<lg3; ++i3)
    {
        printf ("%d ",v3[i3]);
    }

    return 0;
}
