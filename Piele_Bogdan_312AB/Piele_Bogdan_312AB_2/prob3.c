#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x,prim=1;

    printf ("x = ");
    scanf ("%d",&x);

    if (x<=1 || x%2==0)
    {
        prim=0;
    }
    else if (x>=4)
    {
        for (int div=3;div*div<=x;div+=2)
        {
            if (x%div==0)
            {
                prim=0;
                break;
            }
        }

    }

    if (!prim)
    {
        printf ("Nu e prim");
    }
    else
    {
        printf ("E prim");
    }



    return 0;
}
