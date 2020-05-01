#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

struct koordinatak
{
    int x;
    int y;
};

typedef struct koordinatak koordinatak;

int magassag_eldontese(int szint);
int szelesseg_eldontese(int szint);
int isTop(int x,int y,int magassag,int szelesseg);
int isLeftWall(int x,int y,int magassag,int szelesseg);
int isRightWall(int x,int y,int magassag,int szelesseg);
int isBottom(int x,int y,int magassag,int szelesseg);
void rajzolElsoSzintPalya(int magassag,int szelesseg);
void rajzolMasodikSzintPalya(int magassag,int szelesseg);

#endif // JATEK_H_INCLUDED
