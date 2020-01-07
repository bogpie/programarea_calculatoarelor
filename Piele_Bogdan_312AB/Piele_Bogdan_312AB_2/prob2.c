#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a,b,c;
    scanf ("%d%d%d",&a,&b,&c);

    if ( a<0 || b<0 || c<0 )
    {
        printf ("ai introdus un numar negativ");
        return 0;
    }

    else if (a+b < c || a+c < b || b+c < a)
    {
        printf ("suma a doua laturi este mai mica sau egala decat a treia");
        return 0;
    }

    else if (a==b || a==c || b==c)
    {
        if (a==b && b==c & a==c)
        {
            printf ("triunghi echilateral");
            return 0;
        }
        else printf ("triunghi isoscel");

    }

    else if (a*a + b*b == c*c || a*a+c*c == b*b || b*b+c*c==a*a)
    {
        printf ("triunghi dreptunghic");
        return 0;
    }

    else
    {
        printf ("triunghi oarecare");
        return 0;
    }

    return 0;
}
