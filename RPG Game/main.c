#include <stdio.h>
#include <stdlib.h>
#include "jatek.h"

int main()
{
    int szint,szelesseg,magassag;
    szint=1;

    magassag=magassag_eldontese(szint);
    szelesseg=szelesseg_eldontese(szint);


    rajzolPalya(magassag,szelesseg);

    return 0;
}
