#include <stdio.h>
#include <stdlib.h>

int isPerfect(int n)
{
    if (n==1) return 1;
    if (n==2) return 0;

    int sum=1,div=2;

    while (div*div<=n)
    {
        if (n%div==0)
        {
            sum = sum + div + n/div;
        }
        ++div;
    }
    --div;
    if (div * div == n)
    {
        sum-=div;
    }

    //36 test // printf ("%d",sum); printf ("%d",1+2+3+4+6+9+12+18);

    if (sum==n)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    scanf ("%d",&n);

    if (isPerfect(n))
    {
        printf("Este perfect");
    }
    else
    {
        printf ("Nu este perfect");
    }

    return 0;
}
