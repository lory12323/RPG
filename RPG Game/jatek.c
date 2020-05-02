#include <stdio.h>
#include <stdlib.h>
#include "jatek.h"

void magassag_eldontese(int szint, koordinatak* koordinatak)
{
    int magassag;
    if (szint==1)
    {
        koordinatak->y=20;
        printf("%d",koordinatak->y);
    }
    if (szint==2)
    {
        koordinatak->y=40;
    }
    if (szint==3)
    {
        koordinatak->y=60;
    }
}

void szelesseg_eldontese(int szint,koordinatak* koordinatak)
{
    int szelesseg;
    if (szint==1)
    {
        koordinatak->x=40;
    }
    if (szint==2)
    {
        koordinatak->x=60;
    }
    if (szint==3)
    {
        koordinatak->x=80;
    }
}

int palyaMemoriaFoglalasa(int **palya,koordinatak* koordinatak)
{
    palya=(int**)malloc(koordinatak->x*sizeof(int*));
    for (int i=0;i<koordinatak->x;i++)
    {
        palya[i]=(int*)malloc(koordinatak->y*sizeof(int));
    }
    return palya;
}

int isTop(int x,int y,int magassag,int szelesseg)
{
    if ((x==0)&&(y>=0)&&(y<szelesseg-1))
        return 1;
        else return 0;
}/*
int isLeftWall(int x,int y,int magassag,int szelesseg)
{
    if ((y==0)&&(x>0)&&(x<magassag))
        return 1;
        else
            return 0;
}
int isRightWall(int x,int y,int magassag,int szelesseg)
{
    if ((y==szelesseg-1)&&(x>=0)&&(x<magassag))
        return 1;
        else return 0;
}
int isBottom(int x, int y, int magassag,int szelesseg)
{
    if ((x==magassag-1)&&(y>0)&&(y<szelesseg-1))
        return 1;
        else return 0;
}

void rajzolElsoSzintPalya(int magassag,int szelesseg)
{
    for (int i=0;i<magassag;i++)
    {
        for (int j=0;j<szelesseg;j++)
        {
            if (isTop(i,j,magassag,szelesseg)==1)
                printf("#");
            else if (isLeftWall(i,j,magassag,szelesseg)==1)
                printf("#");
            else if (isRightWall(i,j,magassag,szelesseg)==1)
            {
                printf("#");
                printf("\n");
            }
            else if (isBottom(i,j,magassag,szelesseg)==1)
                printf("#");
            else if ((i>0)&&(i<5)&&((j==2)||(j==13)||(j==23)||(j==25)))
                {
                    printf("#");
                }
            else if ((i==1)&&((j==4)||(j==11)))
            {
                printf("#");
            }
            else if ((i==2)&&(j>3)&&(j<12))
                printf("#");
            else if ((i==4)&&(j>2)&&(j<12))
                printf("#");
            else if ((i>4)&&(i<18)&&(j==11))
                printf("#");
            else if ((i==7)&&(j>12)&&(j<39))
                printf("#");
            else if ((i==5)&&(((j>12)&&(j<24))||(j>24)&&(j<39)))
                printf("#");
            else if ((j==13)&&(((i>7)&&(i<10))||((i>10)&&(i<16))))
                printf("#");
            else if ((i==15)&&(j>12)&&(j<39))
                printf("#");
            else if ((i==17)&&(((j>11)&&(j<24))||((j>24)&&(j<39))))
                printf("#");
            else if ((i==18)&&((j==23)||(j==25)))
                printf("#");
            else printf(" ");

        }
    }
}*/

/*void rajzolMasodikSzintPalya(int magassag,int szelesseg)
{
    for (int i=0;i<magassag;i++)
    {
        for (int j=0;j<szelesseg;j++)
        {
            if (isTop(i,j,magassag,szelesseg)==1)
                printf("#");
            else if (isLeftWall(i,j,magassag,szelesseg)==1)
                printf("#");
            else if (isRightWall(i,j,magassag,szelesseg)==1)
            {
                printf("#");
                printf("\n");
            }
            else if (isBottom(i,j,magassag,szelesseg)==1)
                printf("#");
            //else if ()
        }
    }
}*/

void inicializalPalya(koordinatak* koordinatak,int **palya)
{
    palya=palyaMemoriaFoglalasa(palya,koordinatak);

    for (int i=0;i<koordinatak->x;i++)
    {
        for (int j=0;i<koordinatak->y;j++)
        {
            if (isTop(i,j,koordinatak->y,koordinatak->x)==1)
                palya[i][j]=1;
        }
    }
}
