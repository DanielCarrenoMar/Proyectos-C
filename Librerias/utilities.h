#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>

#define CLEAR "cls"

#else
#define CLEAR "clear"


#endif

// Duales
void borrarPantalla();
void gotoxy(int x, int y);

// Comunes
int pedirNum (char* mensaje);
int pedirNums (char* mensaje);
char* pedirCadena(char* mensaje);
void limpiarMatriz(int* matriz, int x, int y, int valor);
void imprimirMatriz(int* matriz, int x, int y);
void recuadro(int x, int y, int w, int h);

#include "utilities.c"
#endif