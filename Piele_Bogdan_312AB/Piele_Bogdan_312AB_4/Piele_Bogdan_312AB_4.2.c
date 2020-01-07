/// Piele Bogdan 312AB Setul 4 Prob 2

#include <stdio.h>
#include <stdlib.h>

float fmodul(float x)
{
    if (x<0) return -x;
    return x;
}

int main()
{
    const int EPS=1E-6;
    int n,i,v[101],min,existamed=0,sum=0;
    float med;

    scanf ("%d",&n);

    for (i=0;i<n;++i)
    {
        scanf ("%d",&v[i]);
    }

    min=sum=v[0];
    for (i=1;i<n;++i)
    {
        sum+=v[i];
        //printf ("%d %d",sum,n);
        if (v[i]<min) min=v[i];
    }
    // printf ("%d %d",sum,n);
    med=sum/(n*1.0); // printf ("%f\n",med);

    for (i=0;i<n;++i)
    {
        if ( fmodul(med-v[i]) <= EPS )
        {
            printf ("Valoarea medie %f apartine vectorului \n",med);
            existamed=1;
            break;
        }
    }

    if (!existamed) printf ("Valoarea medie %f nu exista in vector \n",med);



    printf ("Valoarea minima %d exista pe pozitiile : \n",min);

    for (i=0;i<n;++i)
    {
        if (v[i]==min)
        {
            printf ("%d ",i);
        }
    }


    return 0;
}
