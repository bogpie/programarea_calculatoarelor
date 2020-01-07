#include<stdio.h>


int main()
{

    char vcnp[15];
    scanf ("%s",vcnp+1);

    /// 00 01 02 03 04 05 06 07 08 09 10 11 12 13
    /// CT AN AN LN LN ZI ZI


    /// pas 1;
    int cif1=vcnp[1]-'0';

    if  ( (cif1<0 || cif1>6) && cif1!=9 )
    {
        printf("Prima cifra gresita\n");
        return 0;
    }

    ///pas 2
    int month = ( vcnp[3]-'0') * 10 + ( vcnp[4]-'0' );
    if (month < 1 && month > 12)
    {
        printf ("Luna incorecta\n");
        return 0;
    }
    int day = ( vcnp[5]-'0') * 10 + ( vcnp[6]-'0' );
    if (day < 1 && day > 31)
    {
        printf ("Zi incorecta\n");
        return 0;
    }

    ///pas 3
    char vtest[]=" 279146358279";
    int sum=0;

    for (int icar=1;icar<=12;++icar)
    {
        int ciftest=vtest[icar]-'0';
        int cifcnp=vcnp[icar]-'0';
        sum+=(ciftest*cifcnp);
    }

    ///pas 4
    sum%=11;

    ///pas 5
    int cifctrl=1;
    if (sum<10)
    {
        cifctrl=sum;
    }

    if (cifctrl != ( vcnp[13]-'0' ) )
    {
        printf("Cifra de control nu corespnde \n");
        return 0;
    }

    printf ("CNP VALID\n");

    return 0;

}
