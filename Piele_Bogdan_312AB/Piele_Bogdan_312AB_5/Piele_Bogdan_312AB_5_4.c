///Piele_Bogdan_312AB_5_4

#include <stdio.h>
#include <stdlib.h>

int isLowercase (char car)
{
    if (car>='a' && car<='z')
    {
        return 1;
    }
    return 0;
}

void fBulk (char * adrCar1, char * adrCar2, char * adrCar3,int * adrPosibil)
{
    char car1=*adrCar1;
    char car2=*adrCar2;
    char car3=*adrCar3;
    int posibil=*adrPosibil;

    //printf ("%c %c %c \n", car1,car2,car3); printf ("%d", isLowercase(car2)); //test

    if (isLowercase(car1) && isLowercase(car2) && isLowercase(car3))
    {
        posibil=1;
        car1 = car1 - 32;
        car2 = car2 - 32;
        car3 = car3 - 32;
    }

    *adrCar1 = car1;
    *adrCar2 = car2;
    *adrCar3 = car3;
    *adrPosibil = posibil;


}

int main()
{
    char car1,car2,car3;
    int posibil=0;

    const int scad='a'-'A';
    printf("'a'-'A' = %d\n",scad);

    printf ("Citeste caracterele fara spatii:\n");
    scanf("%c%c%c",&car1,&car2,&car3);
    printf("\n");

    fBulk(&car1,&car2,&car3,&posibil); /// parametrii sunt adresele

    if (posibil) printf ("Conversie posibila : %c %c %c \n",car1,car2,car3);
    else printf ("Nu este posibila conversia \n");
}
