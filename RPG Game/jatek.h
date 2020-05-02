#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

typedef struct koordinatak
{
    int x;
    int y;
}koordinatak;


void magassag_eldontese(int szint,koordinatak* koordinatak);
void szelesseg_eldontese(int szint, koordinatak* koordinatak);
int palyaMemoriaFoglalasa(int **palya,koordinatak* koordinatak);
int isTop(int x,int y,int magassag,int szelesseg);
int isLeftWall(int x,int y,int magassag,int szelesseg);
int isRightWall(int x,int y,int magassag,int szelesseg);
int isBottom(int x,int y,int magassag,int szelesseg);
void rajzolElsoSzintPalya(int magassag,int szelesseg);
void rajzolMasodikSzintPalya(int magassag,int szelesseg);
void inicializalPalya(koordinatak* koordinatak,int **palya);

#endif // JATEK_H_INCLUDED
