#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char nume[40];
    char sex;
    float nota;
};
typedef struct student STUDENT;

void fTest()
{
    FILE * binar = fopen("binar.dat","rb");
    int n;
    fread(&n,sizeof(n),1,binar);
    printf ("%d\n",n);
    STUDENT v[40];
    fread(v,sizeof(STUDENT),n,binar);
    int i;
    for (i=0;i<n;++i)
    {
        printf ("%s %c %f\n",v[i].nume,v[i].sex,v[i].nota);
    }
    fclose(binar);
}

void fInit()
{
    FILE * binar = fopen("binar.dat","wb");
    FILE * input = fopen("input.txt","r");

    int n; ///scanf ("%d",&n);
    fscanf(input,"%d",&n);

    fwrite(&n,sizeof(n),1,binar);
    STUDENT v[40];
    int i;
    for (i=0;i<n;++i)
    {
        ///fflush(stdin);printf("\nnume : ");
        ///gets(v[i].nume); fflush(stdin);
        ///printf("\nsexul si nota: "); scanf("%c%f",&v[i].sex,&v[i].nota);

        char br;
        fscanf(input,"%c",&br);
        fgets(v[i].nume,40,input);
        v[i].nume[strlen(v[i].nume)-1]='\0';
        fscanf(input,"%c%f",&v[i].sex,&v[i].nota);


    }
    fwrite(v,sizeof(STUDENT),n,binar);
    fclose(binar);
}

char * fExista(char nume[40])
{
    char * ptr = malloc(sizeof(char*)*9);
    FILE * binar = fopen("binar.dat","rb");
    int n;
    fread(&n,sizeof(n),1,binar);
    STUDENT v[40];
    fread(v,sizeof(STUDENT),n,binar);
    int i;
    for (i=0;i<n;++i)
    {
        if (!strcmp(nume,v[i].nume))
        {
            strcpy(ptr,"Exista");
            return ptr;
        }
    }
    strcpy(ptr,"Nu exista");
    fclose(binar);
    return ptr;
}

void fCount(int * adrNrBaieti, int * adrNrFete)
{
    int n;
    FILE * binar = fopen("binar.dat","rb");
    fread(&n,sizeof(n),1,binar);
    STUDENT v[40];
    fread(v,sizeof(STUDENT),n,binar);
    int i;
    float mx = -1;
    for (i=0;i<n;++i)
    {
        if (v[i].nota>mx)
        {
            mx=v[i].nota;
        }
    }
    for (i=0;i<n;++i)
    {
        if (v[i].nota==mx)
        {
            if (v[i].sex=='M')
            {
                ++*adrNrBaieti;
            }
            else ++*adrNrFete;
        }
    }
}

int main()
{
    fInit();
    fTest();
    char nume[]={"Alpha Onega"};
    char * ptr = malloc(sizeof(char*)*10); //"nu exista"
    ptr = fExista(nume);
    printf("\n%s : %s\n",nume,ptr);
    free(ptr);
    int nrBaieti=0,nrFete=0;
    fCount(&nrBaieti,&nrFete);
    printf("\n%d baieti si %d fete\n",nrBaieti,nrFete);
    return 0;
}
