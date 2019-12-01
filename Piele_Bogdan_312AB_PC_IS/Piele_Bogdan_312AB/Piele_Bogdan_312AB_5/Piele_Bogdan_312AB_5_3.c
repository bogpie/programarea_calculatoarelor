///Piele_Bogdan_312AB_5_3

#include <stdio.h>
#include <stdlib.h>

char fVerif(int a,int b,int c)
{
    if (a<b && b<c) return 'C';
    else if (a>b && b>c) return 'D';
    else if (a==b && b==c) return 'I';
    return 'N';

}

int main()
{
    int a,b,c;

    char raspuns='D';

    while (raspuns=='D' || raspuns=='d')
    {
        printf ("Tastati 3 numere\n");
        scanf ("%d%d%d",&a,&b,&c);

        char rez = fVerif(a,b,c);
        printf ("%c\n",rez);
        printf ("Continuati (D/N)?\n");

        // fflush(stdin); raspuns=getchar();
        raspuns=getchar(); raspuns=getchar();

        printf ("\n\n");
    }



    return 0;
}
