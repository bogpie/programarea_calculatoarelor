#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,sum=0,val;

    scanf ("%d",&n);

    for (i=1;i<=n;++i)
    {
        scanf ("%d",&val);
        sum+=val;
    }
    printf ("Medie=%f",(float)sum/n);

    return 0;
}
