#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Librerias/decoc.h"
#include "Librerias/Colorama.h"

#define HEIGHT 45
#define WIDTH 150
#define PANTHEIGHT 30
#define PANTWIDTH 125

void logo();
void dibujo(int tablero[200][200], int camara[2]);
void borrar(int tablero[200][200], int camara[2]);
void playerController(int player[2], int camara[2], int tablero[200][200]);
void camaraController(int player[2], int camara[2], int tablero[200][200]);
void preset(int x, int y, int tablero[200][200]);

int main()
{   
    int tablero[200][200];
    for (int i = 0; i < 200; i++){
        for (int j = 0; j < 200; j++){
            tablero[i][j] = 32;
        }
    }
    int camara[2] = {100,100};
    int player[2] = {11,11};

    setConsoleDim(WIDTH,HEIGHT);
    setConsoleColor('0','f');
    hidecursor();
    desactivarmax();

    recuadro(0,PANTHEIGHT,WIDTH-1,HEIGHT-PANTHEIGHT-1);
    recuadro(PANTWIDTH,0,WIDTH-PANTWIDTH-1,PANTHEIGHT);

    preset(70,100, tablero);
    preset(90,100, tablero);
    preset(110,100, tablero);
    dibujo(tablero, camara);

    while (1)
    {
        playerController(player, camara, tablero);
        camaraController(player, camara, tablero);

        gotoxy(0,HEIGHT-5); printf("Camara: %d, %d  ", camara[0], camara[1]);
    }

    return 0;
}

void dibujo(int tablero[200][200], int camara[2]){
    for (int i = 0; i < PANTHEIGHT; i++){
        for (int j = 0; j < PANTWIDTH; j++){
            if (tablero[i+camara[1]][j+camara[0]] != 32){
                gotoxy(j,i); printf("%c", tablero[i+camara[1]][j+camara[0]]);
            }
        }
    }
}

void borrar(int tablero[200][200], int camara[2]){
    for (int i = 0; i < PANTHEIGHT; i++){
        for (int j = 0; j < PANTWIDTH; j++){
            if (tablero[i+camara[1]][j+camara[0]] != 32){
                gotoxy(j,i); printf("%c", 32);
            }
        }
    }
}

void playerController(int player[2], int camara[2], int tablero[200][200]){
    int playerTableroUP = tablero[player[1]+camara[1]-1][player[0]+camara[0]];
    int playerTableroDOWN = tablero[player[1]+camara[1]+1][player[0]+camara[0]];
    int playerTableroLEFT = tablero[player[1]+camara[1]][player[0]+camara[0]-1];
    int playerTableroRIGHT = tablero[player[1]+camara[1]][player[0]+camara[0]+1];

    printf(Fore_BLUE);
    gotoxy(player[0], player[1]); printf("%c", 1);

    char tecla = getch();
    gotoxy(player[0], player[1]); printf("%c", 32);
    if (tecla == 'w' && playerTableroUP != 219){
        player[1] -= 1;
    }
    if (tecla == 's' && playerTableroDOWN != 219){
        player[1] += 1;
    }
    if (tecla == 'a' && playerTableroLEFT != 219){
        player[0] -= 1;
    }
    if (tecla == 'd' && playerTableroRIGHT != 219){
        player[0] += 1;
    }
    printf(Style_RESET_ALL);
}

void camaraController(int player[2], int camara[2], int tablero[200][200]){
    if (player[0] > PANTWIDTH - 10){
            borrar(tablero, camara);
            camara[0] += 1;
            dibujo(tablero, camara);
            player[0] = PANTWIDTH - 10;
    }
    if (player[0] < 10){
        borrar(tablero, camara);
        camara[0] -= 1;
        dibujo(tablero, camara);
        player[0] = 10;
    }
    if (player[1] > PANTHEIGHT - 5){
        borrar(tablero, camara);
        camara[1] += 1;
        dibujo(tablero, camara);
        player[1] = PANTHEIGHT - 5;
    }
    if (player[1] < 5){
        borrar(tablero, camara);
        camara[1] -= 1;
        dibujo(tablero, camara);
        player[1] = 5;
    }
}

void preset(int x, int y, int tablero[200][200]){
    int coords[16][2] = {
        {x, y},
        {x+20, y},
        {x+20, y+10},
        {x, y+10},
        {x, y}
    };
    poligono(coords, 5, 219, tablero);
    tablero[y+10][x+10] = 220;
}