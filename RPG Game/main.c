#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "jatek.h"

int counter;
int i,j;
bool gameRunning=true;

int main()
{
    int **palya;
    int szint,c;
    szint=1;

    i=1;
    j=3;

    Koordinatak* koordinatak;
    koordinatak=koordinatak_letrehozasa();

    magassag_eldontese(szint,koordinatak);
    szelesseg_eldontese(szint,koordinatak);

    palya=inicializalPalya(koordinatak,palya);

    printf("A feladat az, hogy keresd meg a kijaratot a labirintusbol.\nCsak akkor tudsz tovabb lepni az akadalyokon, ha azokra jol valaszolsz.\nSok sikert !!\n\n!!Vigyazat a jatek CASE SENSITIVE\n\n[Press any key to start the game]");
    getch();

    system("cls");

    kirajzolPalya(koordinatak,palya);

    while(gameRunning)
    {
        c=0;
        counter=0;
        c=getch();

        if ((c==0)||(c==224)){
            switch((c=getch())){
            case 72:
                system("cls");

                if ((i==1)||(palya[i-1][j]=='#'))
                {
                    counter++;
                    printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                    break;
                }

                if ((i==3)&&(j==12))
                {
                    srand(time(0));
                    counter=kerdes();

                    if (counter!=0)
                        break;
                }

                if ((i==6)&&(j==24))
                {
                    srand(time(0));
                    counter=kerdes();

                    if (counter!=0)
                        break;
                }

                palya[i][j]=' ';
                i--;
                palya[i][j]='.';

                kirajzolPalya(koordinatak,palya);

                break;
            case 80:
                system("cls");

                if ((i==koordinatak->x-2)||(palya[i+1][j]=='#'))
                {
                    counter++;
                    printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                    break;
                }

                if ((i==3)&&(j==12))
                {
                    srand(time(0));
                    counter=kerdes();

                    if (counter!=0)
                        break;
                }

                if ((i==8)&&(j==12))
                {
                    srand(time(0));
                    counter=kerdes();

                    if (counter!=0)
                        break;
                }

                if ((i==16)&&(j==24))
                {
                    srand(time(0));
                    counter=kerdes();

                    if (counter!=0)
                        break;
                }

                if ((i==17)&&(j==24))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;

                    system("cls");
                    szint++;
                    printf("Gratulalok, tovabb jutottal a kovetkezo szintre\nKezdodjon a masodik szint\n[Press any key to continue]");
                    getch();
                    system("cls");
                    break;
                }

                palya[i][j]=' ';
                i++;
                palya[i][j]='.';

                kirajzolPalya(koordinatak,palya);

                break;
            case 75:
                system("cls");

                if ((j==1)||(palya[i][j-1]=='#'))
                {
                    counter++;
                    printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                    break;
                }

                palya[i][j]=' ';
                j--;
                palya[i][j]='.';

                kirajzolPalya(koordinatak,palya);

                break;
            case 77:
                system("cls");

                if ((i==10)&&(j==12))
                {
                    srand(time(0));
                    counter=kerdes();

                    if (counter!=0)
                        break;

                    szint++;
                    system("cls");
                    printf("Gratulalok, megkaptad a titkos atjaratot a kovetkezo szintre.\nKezdodjon a masodik szint.\n[Press any key to continue]\n");
                    getch();
                    system("cls");
                    break;
                }

                if ((j==koordinatak->y-2)||(palya[i][j+1]=='#'))
                {
                    counter++;
                    printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                    break;
                }

                if ((i==6)&&(j==17))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                if ((i==6)&&(j==30))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                if ((i==16)&&(j==13))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                palya[i][j]=' ';
                j++;
                palya[i][j]='.';

                kirajzolPalya(koordinatak,palya);

                break;
            default:
                printf("A nyilakkal kell mozogni\n");
                break;
            }
            if (counter!=0)
                gameRunning=false;
            if (szint!=1)
                break;
        }
    }

    if (gameRunning==false)
    {
        return 0;
    }

    gameRunning=true;
    szint=2;

    magassag_eldontese(szint,koordinatak);
    szelesseg_eldontese(szint,koordinatak);

    palya=letrehozPalyaMasodikSzint(koordinatak,palya);

    i=15;
    j=58;

    palya[i][j]='.';

    kirajzolPalya(koordinatak,palya);

    while (gameRunning)
    {
        c=0;
        counter=0;
        c=getch();

        if ((c==0)||(c==224)){
            switch((c=getch())){
            case 72:
                system("cls");

                if ((i==1)||(palya[i-1][j]=='#'))
                {
                    counter++;
                    printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                    break;
                }

                if ((i==13)&&((j==49)||(j==50)))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                if ((i==26)&&(j==25))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                palya[i][j]=' ';
                i--;
                palya[i][j]='.';

                kirajzolPalya(koordinatak,palya);

                break;
            case 80:
                system("cls");

                if ((i==koordinatak->x-2)||(palya[i+1][j]=='#'))
                {
                    counter++;
                    printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                    break;
                }

                if ((i==19)&&((j==49)||(j==50)))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                if ((i==26)&&(j==39))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                palya[i][j]=' ';
                i++;
                palya[i][j]='.';

                kirajzolPalya(koordinatak,palya);

                break;
            case 75:
                system("cls");

                if ((j==1)||(palya[i][j-1]=='#'))
                {
                    counter++;
                    printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                    break;
                }

                if ((i==10)&&(j==39))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                if ((i==6)&&(j==35))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                if ((i==12)&&(j==4))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                if ((i==18)&&(j==31))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                if ((i==16)&&(j==2))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;

                    szint++;
                    system("cls");
                    printf("Gratulalok, kijatszodtad a jatekot !");
                    break;
                }

                palya[i][j]=' ';
                j--;
                palya[i][j]='.';

                kirajzolPalya(koordinatak,palya);

                break;
            case 77:
                system("cls");

                if ((j==koordinatak->y-2)||(palya[i][j+1]=='#'))
                {
                    counter++;
                    printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                    break;
                }

                if ((i==34)&&(j==26))
                {
                    srand(time(0));
                    counter=kerdes();
                    if (counter!=0)
                        break;
                }

                palya[i][j]=' ';
                j++;
                palya[i][j]='.';

                kirajzolPalya(koordinatak,palya);

                break;
            default:
                printf("A nyilakkal kell mozogni\n");
                break;
            }
            if (counter!=0)
                gameRunning=false;
            if (szint!=2)
                break;
        }
    }

    return 0;
}
