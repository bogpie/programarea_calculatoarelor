#include <stdio.h>
#include <stdlib.h>

void ffor()
{
    int i,n,sum=0,val;

    scanf ("%d",&n);


    for (i=1;i<=n;++i)
    {
        scanf ("%d",&val);
        sum+=val;
    }

    printf ("Medie=%f",(float)sum/n);

}

void fwhile()
{
    int i,n,sum=0,val;

    scanf ("%d",&n);
    i=n;

    while (n>0)
    {
        scanf ("%d",&val);
        sum+=val;
        n=n-1;
    }
 printf ("Medie=%d\n",sum);

    printf ("Medie=%f",(float)sum/i);

}

int main()
{
    //ffor();
    fwhile();


    return 0;
}
