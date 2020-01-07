#include <stdio.h>
#include <stdlib.h>

int main()
{
    int npoz=0,nneg=0;

    // int x;
    float x;

    do
    {
        //scanf ("%d",&x);
        scanf ("%f",&x);

        if (x>0) ++npoz;
        else if (x<0) ++nneg;

    }while (x!=0);

    printf ("numarul numerelor pozitive citite este %d \n",npoz);
    printf ("numarul numerelor negative citite este %d \n",nneg);

    return 0;
}
