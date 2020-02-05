#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NSTUDENTI 100
#define LGNUME 40

struct student
{
    char nume[40];
    char sex;
    float nota;
};

typedef struct student STUDENT;

char * fExista(char nume[])
{
    FILE * binar = fopen("binar.dat","rb");
    char * ptr = (char*)malloc(sizeof(char*) * 8);
    char str[10];
    int n;
    fread(&n,sizeof(n),1,binar);
    STUDENT v[NSTUDENTI];
    fread(v,sizeof(STUDENT),n,binar);

    for (int i=0;i<n;++i)
    {
        if ( strcmp(v[i].nume,nume) == 0 )
        {
            strcpy(ptr,"Exista");
            return ptr;
        }
    }
    strcpy(ptr,"Nu exista");
    fclose(binar);
    /// free(ptr); // I still need to return it
    return ptr;
}

void fInit()
{
    FILE * binar;
    STUDENT student;
    binar = fopen("binar.dat","wb");

    if (binar==NULL)
    {
        printf ("nu a putut fi creat");
        exit(1);
    }
    int n;
    scanf("%d",&n);
    STUDENT v[NSTUDENTI];

    fwrite(&n,sizeof(n),1,binar);


    for (int i=0;i<n;++i)
    {
        printf("Cititi numele:\n");
        fflush(stdin);
        gets(v[i].nume);

        printf("Cititi sexul si nota:\n");
        fflush(stdin);
        scanf ("%c%f",&v[i].sex,&v[i].nota);

    }
    fwrite(v,sizeof(STUDENT),n,binar);

    fclose(binar);

    printf("\n\n");
}

void fCount (int * adrNrBaieti,int * adrNrFete)
{
    FILE * binar = fopen("binar.dat","rb");
    int n;
    fread(&n,sizeof(n),1,binar);
    STUDENT v[NSTUDENTI];
    fread(v,sizeof(STUDENT),n,binar);

    float mx=-1;
    for (int i=0;i<n;++i)
    {
        if (v[i].nota>mx)
        {
            mx=v[i].nota;
        }
    }

    for (int i=0;i<n;++i)
    {
        printf("%c",v[i].sex);

        if (v[i].nota==mx)
        {
            if (v[i].sex == 'M')
            {
                printf("%c",&v[i].sex);
                *adrNrBaieti = *adrNrBaieti + 1;
            }
            else if(v[i].sex=='F')
            {
                *adrNrFete == *adrNrFete + 1;
            }
        }
    }
    fclose(binar);
}

int main ()
{
    fInit();

    char str[LGNUME];
    char * ptr = (char*)malloc( sizeof(char*) * 8);
    strcpy(str,"Alpha");
    ptr = fExista(str);
    printf ("%s : %s\n",str,ptr);


    int nrBaieti=0,nrFete=0;
    fCount(&nrBaieti,&nrFete);

    printf ("\n%d baieti, %d fete\n",nrBaieti,nrFete);


    free(ptr);

    return 0;
}
