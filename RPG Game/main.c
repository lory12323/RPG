#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

        switch((c=getch())){
        case 'w':
            system("cls");

            if ((i==1)||(palya[i-1][j]=='#'))
            {
                counter++;
                printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                break;
            }

            if ((i==3)&&(j==12))
            {
                int szam;
                system("cls");

                printf("7-5+2= ");
                scanf("%d",&szam);
                if (szam!=4)
                {
                    system("cls");
                    printf("Sajnalom de nem folytathatja a jatekot\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            if ((i==6)&&(j==24))
            {
                char valasz[]="nem egymassal jatszodtak";
                char jatekos[50];
                char temp;
                int eredmeny;
                system("cls");

                printf("Ket ember sakkozik. Mar lejatszottak 5 jatszmat, es mind a ketten harmat nyertek. Hogyan lehetseges ez ?\n");

                scanf("%c",&temp);
                scanf("%[^\n]",jatekos);

                if ((strcmp(jatekos,valasz))!=0)
                {
                    system("cls");
                    printf("Rossz valasz\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            palya[i][j]=' ';
            i--;
            palya[i][j]='.';

            kirajzolPalya(koordinatak,palya);

            break;
        case 's':
            system("cls");

            if ((i==koordinatak->x-2)||(palya[i+1][j]=='#'))
            {
                counter++;
                printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                break;
            }

            if ((i==3)&&(j==12))
            {
                int szam;
                system("cls");

                printf("Van 10 hal egy zart akvariumban. 2 elsullyedt, 4 eluszott, 3 meghalt. Hany hal van most az akvariumban ?\n");
                scanf("%d",&szam); //10, mert egy sem hagyta el az akvariumot

                if (szam!=10)
                {
                    system("cls");
                    printf("Sajnalom de nem annyi hal van az akvariumban, gondold at jobban kovetkezore\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            if ((i==8)&&(j==12))
            {
                int eredmeny;
                system("cls");

                printf("1000-hez adj hozza 40-et. Most 1000-et. Aztan 30-at. Majd ismet 1000-et.\nMost 20-at. Ujra 1000-et, vegul 10-et.\nMennyi jott ki ?  (Nem szabad szamologepet hasznaljal)\n");
                scanf("%d",&eredmeny);

                if (eredmeny!=4100)
                {
                    system("cls");
                    printf("Szamolj ujra\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            if ((i==16)&&(j==24))
            {
                system("cls");

                int eredmeny;

                printf("3*2-1*0+2/2=");
                scanf("%d",&eredmeny);

                if (eredmeny!=7)
                {
                    system("cls");
                    printf("Szamolj ujra\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            if ((i==17)&&(j==24))
            {
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
        case 'a':
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
        case 'd':
            system("cls");

            if ((i==10)&&(j==12))
            {
                system("cls");
                char valasz[]="tegnapelott,tegnap,ma,holnap,holnaputan";
                char jatekos[50];
                char temp;

                printf("Sorold fel a het ot napjat ugy,hogy nem mondod ki a nevuket, sem a szamukat\n");

                scanf("%c",&temp);
                scanf("%[^\n]",jatekos);

                if ((strcmp(jatekos,valasz))!=0)
                {
                    system("cls");
                    printf("Vagy nem jo a valasz vagy nem jo sorrendbe irtad be oket\nProbald ki mas sorrendbe is");
                    counter++;
                    break;
                }
                szint++;
                system("cls");
                printf("Gratulalok, megkaptad a titkos atjaratot a kovetkezo szintre\nKezdodjon a masodik szint\n[Press any key to continue]\n");
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
                int szam;
                system("cls");

                printf ("7 szenarakas meg 5 szenarakas egyutt hany szenarakas ?  (szamban add meg)\n");
                scanf("%d",&szam);
                if (szam!=1)
                {
                    system("cls");
                    printf("Nem jo valasz, gondold at jobban\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            if ((i==6)&&(j==30))
            {
                system("cls");

                int szam;

                printf("Ha kilencszer egymas utan feldobsz egy penzermet\nes mind a kilencszer iras lesz, akkor hany szazalek az esely arra, hogy tizedikre fej lesz ?\n");
                scanf("%d",&szam);

                if (szam!=50)
                {
                    system("cls");
                    printf("Helytelen valasz\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            if ((i==16)&&(j==13))
            {
                system("cls");
                char valasz[]="Jani";
                char jatekos[50];
                char temp;

                printf("Jani anyukajanak negy gyereke van. Az elso Aprilis, a masodik Junius,\nA harmadik Junius. Hogy hivjak a negyediket ?\n");

                scanf("%c",&temp);
                scanf("%[^\n]",jatekos);

                if ((strcmp(jatekos,valasz))!=0)
                {
                    system("cls");
                    printf("Nem jo a valasz\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            palya[i][j]=' ';
            j++;
            palya[i][j]='.';

            kirajzolPalya(koordinatak,palya);

            break;
        default:
            printf("Csak a WASD-vel tudsz mozogni\n");
            break;
        }
        if (counter!=0)
            gameRunning=false;
        if (szint!=1)
            break;
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

        switch((c=getch())){
        case 'w':
            system("cls");

            if ((i==1)||(palya[i-1][j]=='#'))
            {
                counter++;
                printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                break;
            }

            if ((i==13)&&((j==49)||(j==50)))
            {
                system("cls");

                char valasz[]="semmi";
                char jatekos[20];

                printf("A gazdagnak erre van szuksege, a szegenynek csak ez van. Mi ez?\n");

                scanf("%[^\n]",jatekos);

                if ((strcmp(jatekos,valasz))!=0)
                {
                    system("cls");
                    printf("Rossz a valasz\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            palya[i][j]=' ';
            i--;
            palya[i][j]='.';

            kirajzolPalya(koordinatak,palya);

            break;
        case 's':
            system("cls");

            if ((i==koordinatak->x-2)||(palya[i+1][j]=='#'))
            {
                counter++;
                printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                break;
            }

            if ((i==19)&&((j==49)||(j==50)))
            {
                system("cls");
                char valasz[]="tukor";
                char jatekos[10];

                printf("Melyik kor lehet szogletes ?\n");
                scanf("%s",jatekos);

                if (strcmp(valasz,jatekos)!=0)
                {
                    system("cls");

                    printf("Sajnos rossz valaszt adtal :(\nGAME OVER");
                    counter++;
                    break;
                }
                system("cls");
            }

            palya[i][j]=' ';
            i++;
            palya[i][j]='.';

            kirajzolPalya(koordinatak,palya);

            break;
        case 'a':
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
        case 'd':
            system("cls");

            if ((j==koordinatak->y-2)||(palya[i][j+1]=='#'))
            {
                counter++;
                printf("GAME OVER\nNekimentel a falnak\nBetter luck next time :)");
                break;
            }

            palya[i][j]=' ';
            j++;
            palya[i][j]='.';

            kirajzolPalya(koordinatak,palya);

            break;
        default:
            printf("Csak a WASD-vel tudsz mozogni\n");
            break;
        }
        if (counter!=0)
            gameRunning=false;
        if (szint!=2)
            break;
        printf("%d %d",i,j);
    }

    return 0;
}
