#include<stdio.h>

int fcountdiv(int elem)
{
    if (elem<=1) return 1;

    int ndiv=2,div;
    for (div=2; div*div<elem; ++div)
    {
        if (elem%div==0)
        {
            ndiv+=2;
        }
    }
    ++div;
    if (div*div==elem)
        ++ndiv;
    return ndiv;

}

void fafis(int n,int v[101])
{
    for (int i=0; i<n; ++i)
    {
        printf ("%d ",v[i]);
    }
}

int main()
{
    int n,v[101],i,j,elem,prag;


    printf ("Introdueti numarul n de elemente ale vectorului :\n");
    scanf ("%d",&n);
    printf ("Introdueti elemente ale vectorului :\n");

    for (i=0; i<n; ++i)
    {
        scanf ("%d",&v[i]);
    }
    printf("\nIntroduceti pragul \n");
    scanf ("%d",&prag);

    printf ("Depasesc pragul %d valorile : \n", prag);

    for (i=0; i<n; ++i)
    {
        if (v[i] > prag)
        {
            printf ("Valoarea %d de pe pozitia %d \n",v[i],i);
        }
    }

    printf ("\nSe afla pe pozitii pare valorile:\n");

    for (i=0; i<n; i+=2)
    {
        printf ("%d ",v[i]);
    }

    for (i=0; i<n; ++i)
    {
        if (!v[i])
        {
            for (j=i; j<n-1; ++j)
            {
                v[j]=v[j+1];
            }
            --n;
            --i;
        }
    }

    printf ("\nVectorul in urma eliminarii valorilor nule este : \n ");

    fafis(n,v);

    for (i=0; i<n; ++i)
    {
        v[i]=fcountdiv(v[i]);
    }

    printf ("\nVectorul in urma inlocuirilor este : \n ");

    fafis(n,v);

    return 0;


}
