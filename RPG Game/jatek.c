#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jatek.h"

Koordinatak* koordinatak_letrehozasa()
{
    Koordinatak* koordinatak;
    koordinatak=(Koordinatak*)malloc(1*sizeof(Koordinatak));
    return koordinatak;
}

void magassag_eldontese(int szint, Koordinatak* koordinatak)
{
    if (szint==1)
    {
        koordinatak->x=20;
    }
    if (szint==2)
    {
        koordinatak->x=40;
    }
    if (szint==3)
    {
        koordinatak->x=60;
    }
}

void szelesseg_eldontese(int szint,Koordinatak* koordinatak)
{
    if (szint==1)
    {
        koordinatak->y=40;
    }
    if (szint==2)
    {
        koordinatak->y=60;
    }
    if (szint==3)
    {
        koordinatak->y=100;
    }
}

int palyaMemoriaFoglalasa(Koordinatak* koordinatak)
{
    int **palya;

    palya=(int**)malloc(koordinatak->x*sizeof(int*));
    for (int i=0;i<koordinatak->x;i++)
    {
        palya[i]=(int*)malloc(koordinatak->y*sizeof(int));
    }
    return palya;
}

int isTop(int i,int j,int magassag,int szelesseg)
{
    if ((i==0)&&(j>=0)&&(j<szelesseg-1))
        return 1;
        else return 0;
}
int isLeftWall(int i,int j,int magassag,int szelesseg)
{
    if ((j==0)&&(i>0)&&(i<magassag))
        return 1;
        else
            return 0;
}
int isRightWall(int i,int j,int magassag,int szelesseg)
{
    if ((j==szelesseg-1)&&(i>=0)&&(i<magassag))
        return 1;
        else return 0;
}
int isBottom(int i, int j, int magassag,int szelesseg)
{
    if ((i==magassag-1)&&(j>0)&&(j<szelesseg-1))
        return 1;
        else return 0;
}

int inicializalPalya(Koordinatak* koordinatak,int **palya)
{
    palya=palyaMemoriaFoglalasa(koordinatak);

    for (int i=0;i<koordinatak->x;i++)
    {
        for (int j=0;j<koordinatak->y;j++)
        {
            if (isTop(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isLeftWall(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isRightWall(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isBottom(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (((i>0)&&(i<5))&&(j==2))
                palya[i][j]='#';
            else if (((i>1)&&(i<5))&&((j==13)||(j==23)||(j==25)))
                palya[i][j]='#';
            else if ((i==1)&&((j==4)||(j==11)||(j==13)||(j==23)||(j==25)))
                palya[i][j]='#';
            else if ((i==2)&&(j>3)&&(j<12))
                palya[i][j]='#';
            else if ((i==4)&&(j>2)&&(j<12))
                palya[i][j]='#';
            else if ((i>4)&&(i<18)&&(j==11))
                palya[i][j]='#';
            else if ((i==7)&&(j>12)&&(j<39))
                palya[i][j]='#';
            else if ((i==5)&&(((j>12)&&(j<24))||(j>24)&&(j<39)))
                palya[i][j]='#';
            else if ((j==13)&&((i>7)&&(i<16)))
                palya[i][j]='#';
            else if ((i==15)&&(j>12)&&(j<39))
                palya[i][j]='#';
            else if ((i==17)&&(((j>11)&&(j<24))||((j>24)&&(j<39))))
                palya[i][j]='#';
            else if ((i==18)&&((j==23)||(j==25)))
                palya[i][j]='#';
            else if ((i==1)&&(j==3))
                palya[i][j]='.';
            else palya[i][j]=' ';
        }
    }
    return palya;
}

int kirajzolPalya(Koordinatak* koordinatak,int **palya)
{
    for (int i=0;i<koordinatak->x;i++)
    {
        for (int j=0;j<koordinatak->y;j++)
        {
            printf("%c",palya[i][j]);
        }
        printf("\n");
    }
}

int letrehozPalyaMasodikSzint(Koordinatak* koordinatak, int **palya)
{
    palya=palyaMemoriaFoglalasa(koordinatak);

    for (int i=0;i<koordinatak->x;i++)
    {
        for (int j=0;j<koordinatak->y;j++)
        {
            if (isTop(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isLeftWall(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isRightWall(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isBottom(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (((i>0)&&(i<5))&&((j==24)||(j==26)||(j==50)))
                palya[i][j]='#';
            else if ((j==47)&&((i==1)||(i==2)||(i==4)||(i==5)||(i==7)||(i==9)||(i==11)||(i==19)||(i==21)||(i==28)||(i==30)||(i==33)||(i==35)))
                palya[i][j]='#';
            else if ((i==5)&&(((j>17)&&(j<24))||((j>25)&&(j<37))||((j>38)&&(j<koordinatak->y-1))))
                palya[i][j]='#';
            else if ((i==2)&&((j>35)&&(j<47)))
                palya[i][j]='#';
            else if ((i==4)&&(((j>38)&&(j<51))||(j==36)))
                palya[i][j]='#';
            else if ((i==7)&&(((j>20)&&(j<37))||((j>38)&&(j<koordinatak->y-1))))
                palya[i][j]='#';
            else if ((i==9)&&(((j>27)&&(j<37))||((j>38)&&(j<52))))
                palya[i][j]='#';
            else if ((i==11)&&(((j>0)&&(j<19))||((j>29)&&(j<49))))
                palya[i][j]='#';
            else if ((i==13)&&((j>0)&&(j<22)))
                palya[i][j]='#';
            else if ((i==14)&&((j>50)&&(j<koordinatak->y-1)))
                palya[i][j]='#';
            else if ((i==15)&&((j>0)&&(j<12)))
                palya[i][j]='#';
            else if ((i==16)&&(((j>50)&&(j<koordinatak->y-1))||(j==11)))
                palya[i][j]='#';
            else if ((i==17)&&(((j>0)&&(j<10))||(j==11)||((j>29)&&(j<41))))
                palya[i][j]='#';
            else if ((i==18)&&((j==9)||((j>10)&&(j<21))))
                palya[i][j]='#';
            else if ((i==19)&&((j==9)||(j==20)||((j>30)&&(j<39))||((j>39)&&(j<49))))
                palya[i][j]='#';
            else if ((i==20)&&((j==9)||((j>9)&&(j<19))||((j>19)&&(j<29))||(j==31)))
                palya[i][j]='#';
            else if ((i==21)&&((j==18)||(j==31)||((j>39)&&(j<52))))
                palya[i][j]='#';
            else if ((i==22)&&(((j>17)&&(j<25))||((j>25)&&(j<32))))
                palya[i][j]='#';
            else if ((i==28)&&(((j>0)&&(j<25))||((j>25)&&(j<39))||((j>39)&&(j<koordinatak->y-1))))
                palya[i][j]='#';
            else if ((i==30)&&(((j>0)&&(j<15))||((j>15)&&(j<19))||((j>19)&&(j<koordinatak->y-1))))
                palya[i][j]='#';
            else if ((i==33)&&((j>19)&&(j<koordinatak->y-1)))
                palya[i][j]='#';
            else if ((i==35)&&(((j>17)&&(j<33))||((j>33)&&(j<koordinatak->y-1))))
                palya[i][j]='#';
            else if ((j==14)&&((i>30)&&(i<koordinatak->x-1)))
                palya[i][j]='#';
            else if ((j==16)&&((i>30)&&(i<koordinatak->x-1)))
                palya[i][j]='#';
            else if ((j==18)&&(((i>5)&&(i<11))||((i>30)&&(i<35))))
                palya[i][j]='#';
            else if ((j==20)&&((i>30)&&(i<33)))
                palya[i][j]='#';
            else if ((j==21)&&((i>7)&&(i<13)))
                palya[i][j]='#';
            else if ((j==24)&&((i>22)&&(i<28)))
                palya[i][j]='#';
            else if ((j==26)&&((i>22)&&(i<28)))
                palya[i][j]='#';
            else if ((j==28)&&((i>9)&&(i<20)))
                palya[i][j]='#';
            else if ((j==30)&&((i>11)&&(i<17)))
                palya[i][j]='#';
            else if ((j==32)&&((i>35)&&(i<koordinatak->x-1)))
                palya[i][j]='#';
            else if ((j==34)&&((i>35)&&(i<koordinatak->x-1)))
                palya[i][j]='#';
            else if ((j==36)&&((i==3)||(i==8)))
                palya[i][j]='#';
            else if ((j==38)&&((i>19)&&(i<28)))
                palya[i][j]='#';
            else if ((i==8)&&(j==39))
                palya[i][j]='#';
            else if ((j==40)&&((i==18)||((i>21)&&(i<28))))
                palya[i][j]='#';
            else if ((j==48)&&((i>11)&&(i<19)))
                palya[i][j]='#';
            else if ((j==51)&&(((i>9)&&(i<14))||((i>16)&&(i<21))))
                palya[i][j]='#';
            else palya[i][j]=' ';
        }
    }
    return palya;
}

int letrehozPalyaHarmadikSzint(Koordinatak* koordinatak, int **palya)
{
    palya=palyaMemoriaFoglalasa(koordinatak);

    for (int i=0;i<koordinatak->x;i++)
    {
        for (int j=0;j<koordinatak->y;j++)
        {
            if (isTop(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isLeftWall(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isRightWall(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (isBottom(i,j,koordinatak->x,koordinatak->y)==1)
                palya[i][j]='#';
            else if (((j==43)||(j==45))&&((i>46)&&(j<59)))
                palya[i][j]='#';
            else palya[i][j]=' ';
        }
    }
    return palya;
}

int kerdes()
{
    int szam,eredmeny,x,szamlalo;
    szamlalo=0;
    int random;
    char temp;
    char valasz;
    char jatekos[50];
    random=(rand()%(19-1+1)) + 1;
    switch(random){
    case 1:
        system("cls");

        printf("7-5+2= ");
        scanf("%d",&szam);
        if (szam!=4)
        {
            system("cls");
            printf("Sajnalom de nem folytathatja a jatekot\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");
        break;
    case 2:
        strcpy(&valasz,"nem egymassal jatszodtak");
        system("cls");

        printf("Ket ember sakkozik. Mar lejatszottak 5 jatszmat, es mind a ketten harmat nyertek. Hogyan lehetseges ez ?\n");

        scanf("%[^\n]",jatekos);

        if ((strcmp(jatekos,&valasz))!=0)
        {
            system("cls");
            printf("Rossz valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 3:
        system("cls");

        printf("Van 10 hal egy zart akvariumban. 2 elsullyedt, 4 eluszott, 3 meghalt. Hany hal van most az akvariumban ?\n");
        scanf("%d",&szam); //10, mert egy sem hagyta el az akvariumot

        if (szam!=10)
        {
            system("cls");
            printf("Sajnalom de nem annyi hal van az akvariumban, gondold at jobban kovetkezore\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 4:
        system("cls");

        printf("1000-hez adj hozza 40-et. Most 1000-et. Aztan 30-at. Majd ismet 1000-et.\nMost 20-at. Ujra 1000-et, vegul 10-et.\nMennyi jott ki ?  (Nem szabad szamologepet hasznaljal)\n");
        scanf("%d",&eredmeny);

        if (eredmeny!=4100)
        {
            system("cls");
            printf("Szamolj ujra\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 5:
        system("cls");

        printf("3*2-1*0+2/2=");
        scanf("%d",&eredmeny);

        if (eredmeny!=7)
        {
            system("cls");
            printf("Szamolj ujra\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 6:
        system("cls");
        strcpy(&valasz,"tegnapelott,tegnap,ma,holnap,holnaputan");

        printf("Sorold fel a het ot napjat ugy,hogy nem mondod ki a nevuket, sem a szamukat\n");

        scanf("%[^\n]",jatekos);

        printf("%s\n",&valasz);

        getch();

        printf("%s\n",jatekos);

        getch();

        x=strcmp(jatekos,&valasz);

        getch();

        szamlalo=0;

        if (x!=0)
        {
            system("cls");
            printf("Vagy nem jo a valasz vagy nem jo sorrendbe irtad be oket\nProbald ki mas sorrendbe is");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 7:
        system("cls");

        printf ("7 szenarakas meg 5 szenarakas egyutt hany szenarakas ?  (szamban add meg)\n");
        scanf("%d",&szam);
        if (szam!=1)
        {
            system("cls");
            printf("Nem jo valasz, gondold at jobban\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 8:
        system("cls");

        printf("Ha kilencszer egymas utan feldobsz egy penzermet\nes mind a kilencszer iras lesz, akkor hany szazalek az esely arra, hogy tizedikre fej lesz ?\n");
        scanf("%d",&szam);

        if (szam!=50)
        {
            system("cls");
            printf("Helytelen valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 9:
        system("cls");
        strcpy(&valasz,"Jani");

        printf("Jani anyukajanak negy gyereke van. Az elso Aprilis, a masodik Junius,\nA harmadik Julius. Hogy hivjak a negyediket ?\n");

        scanf("%s",jatekos);

        if ((strcmp(jatekos,&valasz))!=0)
        {
            system("cls");
            printf("Nem jo a valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 10:
        system("cls");

        strcpy(&valasz,"semmi");

        printf("A gazdagnak erre van szuksege, a szegenynek csak ez van. Mi ez?\n");

        scanf("%s",jatekos);

        if ((strcmp(jatekos,&valasz))!=0)
        {
            system("cls");
            printf("Rossz a valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 11:
        system("cls");
        strcpy(&valasz,"McDonalds");

        printf("Mi lesz a kacsa es a kecske keresztezodesebol ?\n");
        scanf("%s",&jatekos);

        if (strcmp(&valasz,jatekos)!=0)
        {
            system("cls");

            printf("Gondold at jobban\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 12:
        system("cls");
        strcpy(&valasz,"tukor");

        printf("Melyik kor lehet szogletes ?\n");
        scanf("%s",jatekos);

        if (strcmp(&valasz,jatekos)!=0)
        {
            system("cls");

            printf("Sajnos rossz valaszt adtal :(\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 13:
        system("cls");
        strcpy(&valasz,"feny");

        printf("Megtoltok egy egesz szobat, megis barmi befer tolem. Mi vagyok ?\n");
        scanf("%s",&jatekos);

        if (strcmp(&valasz,jatekos)!=0)
        {
            system("cls");

            printf("Helytelen valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 14:
        system("cls");

        printf("Ha egy futoversenyen megelozod a masodikat, hanyadik helyen vegzel ?\n");
        scanf("%d",&x);

        if (x!=2)
        {
            system("cls");

            printf("Sajnalom de nem jo a valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 15:
        system("cls");

        printf("Van nyolc ego gyertyad, amibol harmat eloltasz.\nHany gyertyad marad ?\n");

        scanf("%d",&x);

        if (x!=3)
        {
            system("cls");

            printf("Sajnalom, de helytelen a valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 16:
        system("cls");
        strcpy(&valasz,"nem");

        printf("Legalis-e Magyarorszagon, hogy egy ferfi az ozvegyenek a hugat vegye felesegul ?\n");
        scanf("%s",jatekos);

        if (strcmp(&valasz,jatekos)!=0)
        {
            system("cls");

            printf("Gondold at jobban\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 17:
        system("cls");

        printf("Oszd el a 30-at fellel, es az eredmenyhez adj hozza 10-et.\nMennyi jott ki ?\n");
        scanf("%d",&x);

        if (x!=70)
        {
            system("cls");
            printf("Nem jo a valasz\nGAME OVER");

            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 18:
        system("cls");
        strcpy(&valasz,"koporso");

        printf("Aki kesziti annak nem kell. Aki megveszi, az nem hasznalja.\nAki hasznalja, nem tud rola. Mi az ?\n");
        scanf("%s",jatekos);

        if (strcmp(&valasz,jatekos)!=0)
        {
            system("cls");

            printf("Nem jo a valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    case 19:
        system("cls");
        strcpy(&valasz,"nem");

        printf("Ha egy ejjeli or reggel hal meg, kaphat-e nyugdijat ?\n");
        scanf("%s",&jatekos);

        if (strcmp(&valasz,jatekos)!=0)
        {
            system("cls");

            printf("Sajnalom de nem jo a valasz\nGAME OVER");
            szamlalo++;
            break;
        }

        system("cls");

        break;
    default:
        break;
    }
    return szamlalo;
}
