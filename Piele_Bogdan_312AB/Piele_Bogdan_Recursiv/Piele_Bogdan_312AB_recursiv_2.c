///Piele_Bogdan_312AB_recursiv_2

#include <stdio.h>

int fFib(int n)
{
    if (n<=1)
    {
        return 1;
    }
    return fFib(n-1)+fFib(n-2);
}

int main()
{
    FILE *input,*output;
    input=fopen("input.txt","r");
    output=fopen("output.txt","w");

    int n,fib;

    fscanf(input,"%d",&n);

    fib = fFib(n);

    fprintf(output,"fib(%d)=%d\n",n,fFib(n));

/*
    for (int i = 0 ;i<10;++i)
    {
        fprintf(output,"fib(%d)=%d\n",i,fFib(i));
    }
*/
    return 0;
}
