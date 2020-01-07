#include <stdio.h>
/// Piele_Bogdan_312AB_autoapelare_4_si_5
/// autoapelare nonrecursiva

void fAfisare (FILE *output,int v[],int n)
{
    if (n==0)
    {
        return;
    }
    fAfisare(output,v,n-1);
    fprintf(output,"%d ",v[n-1]);
}

void fAfisareInversa (FILE *output,int v[],int n)
{
    if (n==0)
    {
        return;
    }
    fprintf(output,"%d ",v[n-1]);
    fAfisareInversa(output,v,n-1);

}

int main()
{
    FILE *input,*output;
    input=fopen("input.txt","r");
    output=fopen("output.txt","w");


    int v[100],n;
    fscanf (input,"%d",&n);
    for(int i=0;i<n;++i)
    {
        fscanf(input,"%d",&v[i]);
    }

    int invers = 1;
    fAfisare(output,v,n);
    fprintf(output,"\n");
    fAfisareInversa(output,v,n);

}
