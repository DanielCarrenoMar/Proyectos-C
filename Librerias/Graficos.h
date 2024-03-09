#ifndef Graficos_H
#define Graficos_H

void gotoxy(int x, int y);
void borrarPantalla();

#ifdef _WIN32

void setConsoleDim(int x, int y);
void setConsoleColor(char bg, char fg);
void hidecursor();
void showcursor();
void desactivarmax();

#endif

void line(int x1, int y1, int x2, int y2, char sprite);
void poligono(int  coords[16][2], int elemt, char sprite);
void recuadro(int x, int y, int w, int h);
void tabla(int x , int y, int filas, int columnas, int filasize, int columnasize);
void cuadrado(int x, int y, int w, int h, char sprite);

#include "Graficos.c"
#endif