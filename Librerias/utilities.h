#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32

#else

#endif

int pedirNum (char* mensaje);
char* pedirCadena(char* mensaje);
void limpiarMatriz(int* matriz, int x, int y, int valor);
void imprimirMatriz(int* matriz, int x, int y);

#include "utilities.c"
#endif