/// Piele Bogdan 312AB Setul 4 Prob 1


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cresc=1,descresc=1,constant=1,x=0,y=0,n,i;

    scanf ("%d",&n);

    scanf ("%d",&x);

    for (i=1;i<n;++i)
    {
        scanf("%d",&y);

        if (y!=x)
        {
            constant=0;
            if (y<x) cresc=0;
            else if (y>x) descresc=0;
        }

       // printf ("%d %d %d \n",constant,cresc,descresc);

        x=y;
    }

    if (constant)
    {
        printf("constant");
    }
    else
    {
        if (cresc)
        {
            printf("crescator");
        }
        else if (descresc)
        {
            printf("descrescator");
        }
        else printf("oarecare");
    }


    return 0;
}
