#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nNume;
    FILE * input = fopen("input.txt","r");

    fscanf(input,"%d",&nNume);
    printf("%d\n",nNume);
    char br;
    fscanf(input,"%c",&br);
    char nume[50];
    for (int i=0;i<nNume;++i)
    {
        fscanf(input,"%[^\n]",nume);
        char br;
        fscanf(input,"%c",&br);

        printf("%s\n",nume);
    }
}
