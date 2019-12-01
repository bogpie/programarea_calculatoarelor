///Piele_Bogdan_312AB_5_Suplimentare_1

#include <stdio.h>
#include <stdlib.h>

int fibo(int n)
{
    if (!n)
        return 0;
    int a=1;
    int b=1;
    if (n==1 || n==2)
        return 1;

    for (int i=3; i<=n; ++i)
    {
        int bOld=b;
        b=a+b;
        a=bOld;
    }
    return b;
}

int fact(int n)
{
    int solFact=1;
    for (int i=1; i<=n; ++i)
    {
        solFact*=i;
    }
    return solFact;
}

float expresie(int n)
{
    return ( ( 1.0 * fibo(n) ) / ( fact(n) ) ) ;
}

int main()
{
    int n;

    scanf ("%d",&n);

    printf ("%d %d \n",fibo(n),fact(n));

    printf ("%f", expresie(n) ) ;

    return 0;
}
