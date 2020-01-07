///Piele_Bogdan_312AB_7_3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char car,nume[100];

    struct persoana
    {
        char nume[100];
        int varsta;
    } vpers[2];

    for (int ipers=0; ipers<2; ++ipers)
    {

        gets(vpers[ipers].nume);
        scanf("%d",&vpers[ipers].varsta);
        getchar();

    }

    int indiceCautat=0;

    if ( strcmp ( vpers[0].nume, vpers[1].nume ) )  /// diferite
    {
        if (vpers[0].varsta == vpers[1].varsta)
        {
            printf ("%s\n%s",vpers[0].nume,vpers[1].nume);
        }

        else
        {
            if ( vpers[1].varsta < vpers[0].varsta )
            {
                indiceCautat = 1 ;
            }

            printf("%s\n",vpers[indiceCautat].nume);
        }
        ///return 0;
    }

    else
    {
        printf ("Persoanele au acelasi nume ! ");
        ///return 0;

    }



    return 0;
}
