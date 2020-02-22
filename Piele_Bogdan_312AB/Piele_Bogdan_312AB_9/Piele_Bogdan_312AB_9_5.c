#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    int id;
    int cant;
    float pret;
    struct element * urm;
};
typedef struct element ELEMENT;

void fInit(FILE * input,ELEMENT * start,ELEMENT * startCos)
{
    int n;
    fscanf(input,"%d",&n);
    char br;
    fscanf(input,"%c",&br);
    fscanf(input,"%d%d%f",&start->id,&start->cant,&start->pret);
    //fscanf(input,"%c",&br);

    ELEMENT* crt=start;

    for (int i=1;i<n;++i)
    {
        ELEMENT* urm = (ELEMENT*)malloc(sizeof(ELEMENT*));

        fscanf(input,"%d%d%f",&urm->id,&urm->cant,&urm->pret);
        crt->urm=urm;
        urm->urm=NULL;
        crt = crt->urm;
    }
    return;
}

void fAfis(ELEMENT * start)
{
    ELEMENT * crt=start;
    while (crt!=NULL)
    {
        printf("%d %d %f\n",crt->id,crt->cant,crt->pret);
        crt=crt->urm;
        /// (*crt).urm
    }
}

int main()
{
    FILE * input = fopen("5.txt","r");
    ELEMENT* start=(ELEMENT*)malloc(sizeof(ELEMENT*));
    ELEMENT* startCos=(ELEMENT*)malloc(sizeof(ELEMENT*));

    fInit(input,start,startCos);
    fclose(input);
    fAfis(start);




    return 0;
}
