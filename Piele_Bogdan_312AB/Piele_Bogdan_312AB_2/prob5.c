#include <stdio.h>
#include <stdlib.h>


int main()
{

    int n;
    scanf ("%d",&n);

    if (n<=0)
    {
        printf ("numar negativ !");
    }

    int a=0,b=1,c=0;

    printf ("0 ");
    if (n==1) return 0;

    printf ("1 ");
    if (n==2) return 0;

    int i=3;

    while (i<=n)
    {
        c=a+b;
        a=b;
        b=c;
        printf ("%d ",c);
        ++i;
    }


    return 0;
}
