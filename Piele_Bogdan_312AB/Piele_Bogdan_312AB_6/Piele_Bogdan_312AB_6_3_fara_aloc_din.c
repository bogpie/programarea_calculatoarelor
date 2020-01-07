///Piele_Bogdan_312AB_6_3
/// varianta in care construim vectorul in main

#include <stdio.h>
#include <stdlib.h>

void f (int v[] , int n , int * npoz , int * nneg, int * nnul)
{
    for (int i=0;i<n;++i)
    {
        if (!v[i]) ++*nnul;
        else if (v[i]>0) ++*npoz;
        else ++*nneg;
    }
    return;
}

int main()
{
    int n,v[100],npoz=0,nneg=0,nnul=0,i;

    scanf ("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf ("%d",&v[i]);
    }

    f (v,n, &npoz, &nneg, &nnul);

    printf ("%d pozitive , %d negative , %d nule",npoz,nneg,nnul);

    return 0;
}
