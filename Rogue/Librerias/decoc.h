#ifndef _DECOC_H_
#include "decoc.c"

void setConsoleDim(int x, int y);
void setConsoleColor(char bg, char fg);
void gotoxy(int x, int y);
void line(int x1, int y1, int x2, int y2, int sprite, int tablero[200][200]);
void poligono(int  coords[16][2], int elemt, int sprite, int tablero[200][200]);
void recuadro(int x, int y, int w, int h);
void hidecursor();
void showcursor();
void desactivarmax();
#endif