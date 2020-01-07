///Piele_Bogdan_312AB_recursiv_3

#include <stdio.h>

float fAbs(float f)
{
    if (f<0) return -f;
    return f;
}

float fSqrt(float n,float a,float e)
{
    if ( fAbs(a*a-n) < e )
    {
        return a;
    }
    float aNew = (a*a+n)/(2*a);
    return fSqrt(n, aNew, e);
}

int main()
{
    FILE *input,*output;
    input=fopen("input.txt","r");
    output=fopen("output.txt","w");

    float n,a,e,sol;
    fscanf(input,"%f%f%f",&n,&a,&e);
    //float a=n/2;
    //float e = 0.01;

    sol = fSqrt(n,a,e);
    fprintf(output,"%f",sol);
    return 0;
}
