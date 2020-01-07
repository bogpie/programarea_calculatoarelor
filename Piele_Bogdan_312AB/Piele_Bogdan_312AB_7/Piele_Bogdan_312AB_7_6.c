///Piele_Bogdan_312AB_7_6

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char vText[100];
    char vVoc[]="aeiou";;
    int vTestVocala[256]={0},incepeVocala=0;

    for (int iVoc=0;iVoc<5;++iVoc)
    {
        vTestVocala[vVoc[iVoc]]=1;
    }
    gets(vText); //  printf("%s\n",vText);
    int lgText=strlen(vText),iText=0,stanga=0;
    if ( vTestVocala [ vText[iText] ] )
    {
        incepeVocala=1;
    }

    iText=1;

    vText[lgText++]=' ';
    /// vreau sa faca testul din while (daca am gasit caracter spatiu)
    /// inca o data pentru ultimul caracter
    vText[lgText]='\0';

    while(iText<lgText)
    {
        if (vText[iText] == ' ')
        {
            if ( vTestVocala [ vText [ iText - 1 ] ] == 1 && incepeVocala == 1 )
            {
                //printf ("%c ",vText[iText-1]);
                vText[iText]='\0';
                printf("%s\n",vText+stanga);
            }

            incepeVocala=0;
            ++iText;

            if (vTestVocala [ vText[iText] ] == 1)
            {
                incepeVocala=1;
                stanga=iText;
            }
        }
        ++iText;
    }

    return 0;
}
