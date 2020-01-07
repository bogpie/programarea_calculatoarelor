///Piele_Bogdan_312AB_recursiv_1

#include <stdio.h>

int fFact (int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        return n * fFact(n-1);
    }
}


int main()
{
    FILE *input,*output;
    input=fopen("input.txt","r");
    output=fopen("output.txt","w");

    int n,fact;
    fscanf(input,"%d",&n);
    fact = fFact(n);
    fprintf(output,"%d",fact);
    return 0;
}
