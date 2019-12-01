///Piele_Bogdan_312AB_7_10

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    char vText[100];
    char vVoc[]="aeiou";;
    int vTestVocala[256]={0};
    for (int iVoc=0;iVoc<5;++iVoc)
    {
        vTestVocala[vVoc[iVoc]]=1;
    }
    gets(vText); //  printf("%s\n",vText);
    int lgText=strlen(vText);

    for (int iText=0;iText<lgText;++iText)
    {
        if (vTestVocala[vText[iText]])
            vText[iText] = toupper(vText[iText]);
    }

    printf("%s",vText);

    return 0;
}
