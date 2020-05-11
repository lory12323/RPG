#include <stdio.h>
#include <stdlib.h>
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
        koordinatak->y=80;
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
