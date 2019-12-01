#include <stdio.h>
#include <stdlib.h>

int isPalindrom (int n)
{
    int ninvers=0;
    int nbak=n;

    while (n)
    {
        ninvers = ninvers * 10 + n % 10;
        n/=10;
    }
    n=nbak;

    if (n==ninvers)
    {
        return 1;
    }

    return 0;

}

int main()
{
    int n;
    scanf ("%d",&n);

    if (isPalindrom(n))
    {
        printf("Este palindrom");
    }
    else
    {
        printf ("Nu este palindrom");
    }

    return 0;
}
