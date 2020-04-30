#include <stdio.h>
#include <stdlib.h>
#include "jatek.h"

int magassag_eldontese(int szint)
{
    int magassag;
    if (szint==1)
    {
        magassag=20;
    }
    if (szint==2)
    {
        magassag=40;
    }
    if (szint==3)
    {
        magassag=60;
    }
    return magassag;
}

int szelesseg_eldontese(int szint)
{
    int szelesseg;
    if (szint==1)
    {
        szelesseg=20;
    }
    if (szint==2)
    {
        szelesseg=40;
    }
    if (szint==3)
    {
        szelesseg=60;
    }
    return szelesseg;
}

int isTop(int x,int y,int magassag,int szelesseg)
{
    if ((x==0)&&(y>=0)&&(y<szelesseg-1))
        return 1;
        else return 0;
}
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

void rajzolPalya(int magassag,int szelesseg)
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
            else
                printf(" ");
        }
    }
}
