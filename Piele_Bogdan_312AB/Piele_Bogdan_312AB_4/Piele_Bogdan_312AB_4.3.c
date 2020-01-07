/// Piele Bogdan 312AB Setul 4 Prob 3

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,i,old=0,v[101],lg,st,lgsol=0,stsol;

    scanf ("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf ("%d",&v[i]);
    }

    old=v[0];
    lg=1;
    st=0;

    for (i=1;i<n;++i)
    {
        if (v[i]>old)
        {
            ++lg;
        }
        else if (lg>lgsol)
        {
            lgsol=lg;
            lg=1;
            stsol=st;
            st=i;
        }

        old=v[i];
    }

    if (lg>lgsol)
    {
        lgsol=lg;
        lg=1;
        stsol=st;
        st=i;
    }

    while (lgsol)
    {
        printf ("%d ",v[stsol++]);
        --lgsol;
    }

    return 0;
}
