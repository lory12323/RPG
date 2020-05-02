#include <stdio.h>
#include <stdlib.h>
#include "jatek.h"

int main()
{
    int **palya;
    int szint,szelesseg,magassag;
    szint=1;

    koordinatak* koordinatak;

    magassag_eldontese(szint,koordinatak);
    szelesseg_eldontese(szint,koordinatak);

    inicializalPalya(koordinatak,palya);

    return 0;
}
