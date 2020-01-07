///Piele_Bogdan_312AB_5_Suplimentare_2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rezultat(int a,int b,int c,float * x1,float * x2)
{
    int solDelta=delta(a,b,c);
    *x1 = ( -b - sqrt (solDelta) ) / (2*a) ;
    *x2 = ( -b + sqrt (solDelta) ) / (2*a) ;
}

int delta(int a,int b,int c)
{
    return (b*b-4*a*c);
}

int main()
{
    int a,b,c;
    float x1,x2;
    scanf("%d%d%d",&a,&b,&c);
    rezultat(a,b,c,&x1,&x2);

    printf ("Solutiile sunt %f si %f \n",x1,x2);

    return 0;
}
