///Piele_Bogdan_312AB_6_3
/// varianta cu alocare dinamica

#include <stdio.h>
#include <stdlib.h>

void fTest ( int * p )
{
    if (p==NULL)
    {
        printf ("Alocarea dinamica de memorie nu a functionat\n");
        exit(1);
    }
}

void fCiteste (int * p , int n)
{
    int dim=n*sizeof(int);
    int * sfarsit = p + n;


}

void fCount(int n,int * npoz, int * nneg ,int *nnul)
{
    int * p = (int*)malloc();
    fCiteste(p,n);
}

int main()
{
    int n,npoz=0,nneg=0,nnul=0,i;

    scanf ("%d",&n);

    fCount(n,&npoz,&nneg,&nnul);

    return 0;
}
