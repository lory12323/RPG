#include <stdio.h>
#include <stdlib.h>
#include "jatek.h"

int main()
{
    int szint,szelesseg,magassag;
    szint=1;

    magassag=magassag_eldontese(szint);
    szelesseg=szelesseg_eldontese(szint);


    rajzolElsoSzintPalya(magassag,szelesseg);

    for (int i=0;i<magassag;i++)
    {
        for (int j=0;j<szelesseg;j++)
        {
            if ((j==9)&&(i==23))
                printf("_|_");
        }
    }

    return 0;
}
