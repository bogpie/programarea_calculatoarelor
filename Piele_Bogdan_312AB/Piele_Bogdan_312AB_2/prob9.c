#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,term=1,sum=0;
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        term*=i;
        sum+=term;
    }
    printf("%d",sum);
    return 0;
}
