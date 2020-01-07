#include <stdio.h>
#include <stdlib.h>


int main()
{

    int n,ncif=0,vcif[102];

    scanf("%d",&n);

    while (n)
    {
        vcif[++ncif]=n%10;
        n/=10;
    }

    while (ncif)
    {
        printf ("%d ",vcif[ncif]);
        --ncif;
    }

    return 0;
}
