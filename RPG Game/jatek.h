#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

typedef struct Kordinatak
{
    int x;
    int y;
}Koordinatak;


Koordinatak* koordinatak_letrehozasa();
void magassag_eldontese(int szint,Koordinatak* koordinatak);
void szelesseg_eldontese(int szint, Koordinatak* koordinatak);
int palyaMemoriaFoglalasa(Koordinatak* koordinatak);
int isTop(int i,int j,int magassag,int szelesseg);
int isLeftWall(int i,int j,int magassag,int szelesseg);
int isRightWall(int i,int j,int magassag,int szelesseg);
int isBottom(int i,int j,int magassag,int szelesseg);
int inicializalPalya(Koordinatak* koordinatak,int **palya);
int kirajzolPalya(Koordinatak* koordinatak, int **palya);
int letrehozPalyaMasodikSzint(Koordinatak* koordinatak,int **palya);
int letrehozPalyaHarmadikSzint(Koordinatak* koordinatak,int **palya);
int kerdes();

#endif // JATEK_H_INCLUDED
